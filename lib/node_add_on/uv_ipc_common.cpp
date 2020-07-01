 #include "uv_ipc_common.h"
#include <map>
void UVIPCLocker::Lock(bool write/* = true*/)
{
	write ? uv_rwlock_wrlock(&uv_rw_locker) : uv_rwlock_rdlock(&uv_rw_locker);
}
void UVIPCLocker::Unlock(bool write/* = true*/)
{
	write ? uv_rwlock_wrunlock(&uv_rw_locker) : uv_rwlock_rdunlock(&uv_rw_locker);
}

UVIPCLocker g_owner_locker;
std::map<void*, UVIPC* > g_owner_list;
//////////////////////////////////////////////////////////////////////////
UVIPCMessage::UVIPCMessage(const char* in_buf, int in_len, bool using_external_buffer_)
{
	buf = NULL;
	len = 0;
	using_external_buffer = using_external_buffer_;
	if (using_external_buffer)
	{
		buf = const_cast<char*>(in_buf);
		len = in_len;
	}
	else
	{
		if (in_len > 0)
		{
			//owner|buffer
			char* real_buf = (char*)malloc(in_len + UVIPC_MSG_HEADER_LEN);
			if (real_buf)
			{
				unsigned long long& owner_ = *(unsigned long long*)real_buf;
				owner_ = (unsigned long long)this;
				int& buf_len = *(int*)(real_buf + sizeof(unsigned long long));
				buf_len = in_len;
				buf = real_buf + UVIPC_MSG_HEADER_LEN;
				in_buf ? memcpy(buf, in_buf, in_len) : memset(buf, 0, in_len);
				len = in_len;
			}
		}
	}
	

	ref_count.Inc();
}

UVIPCMessage::~UVIPCMessage()
{
	if (buf && !using_external_buffer)
	{
		char* real_buf = buf - UVIPC_MSG_HEADER_LEN;
		free(real_buf);
	}
}

char* UVIPCMessage::GetRealBuf()
{
	if (buf && !using_external_buffer)
	{
		return buf - UVIPC_MSG_HEADER_LEN;
	}
	return NULL;
}
int UVIPCMessage::GetRealLen()
{
	if (buf && !using_external_buffer)
	{
		return len + UVIPC_MSG_HEADER_LEN;
	}
	return 0;
}

char* UVIPCMessage::GetBuf()
{
	return buf;
}
int UVIPCMessage::GetLen()
{
	return len;
}
//////////////////////////////////////////////////////////////////////////
UVIPC::UVIPC()
{
	buffered_ipc_msg = NULL;
	buffered_ipc_msg_offset = 0;
}

UVIPC::~UVIPC()
{
	Stop();
}
bool UVIPC::IsRunning(bool check_connection/* = false*/)
{
	if (check_connection)
	{
		if (uv_data.is_server_mode)
			return uv_data.ut.part_s.client ? true : false;
		else
			return uv_data.ut.part_c.connect ? true : false;
	}
	else
	{
		return uv_data.owner ? true : false;
	}
}

void uv_ipc_timer_cb(uv_timer_t* handle)
{
	UVIPC::UVIPCTimerData* timer_data = (UVIPC::UVIPCTimerData*)handle;
	if (timer_data && timer_data->owener)
		timer_data->owener->uv_cb_ipc_timer(handle);
}

bool UVIPC::Start(char* name_, bool is_server, uv_loop_t* loop_, UVIPCSink* sink_)
{
	bool succ = false;
	do 
	{
		if (IsRunning())
		{
			break;
		}
		
		if (NULL == name_ || NULL == loop_)
			break;

		succ = is_server ? StartWithServer(name_, is_server, loop_) : StartWithClient(name_, is_server, loop_);
		if (!succ)
			break;

		uv_data.uv_pipe_name = name_;
		uv_data.external_sink = sink_;
		uv_timer_init(loop_, &uv_timer_data.uv_timer_req);
		uv_timer_start(&uv_timer_data.uv_timer_req, uv_ipc_timer_cb, 100, 10);
		uv_timer_data.owener = this;
		uv_timer_data.owner_ipc_data = &uv_data;
	} while (false);
	return succ;
}

bool UVIPC::Stop()
{
	bool succ = false;
	do 
	{
		if (!IsRunning())
		{
			succ = true;
			break;
		}

		if (uv_data.is_server_mode)
		{
			if (uv_data.ut.part_s.client)
			{
				uv_read_stop((uv_stream_t*)uv_data.ut.part_s.client);
				uv_close((uv_handle_t*)uv_data.ut.part_s.client, NULL);
				free(uv_data.ut.part_s.client);
				uv_data.ut.part_s.client = NULL;
			}
			uv_close((uv_handle_t*)&uv_data.handle, NULL);
		}
		else
		{
			if (uv_data.ut.part_c.connect)
			{
				uv_read_stop((uv_stream_t*)uv_data.ut.part_c.connect->handle);
				uv_close((uv_handle_t*)uv_data.ut.part_c.connect->handle, NULL);
				free(uv_data.ut.part_c.connect);
				uv_data.ut.part_c.connect= NULL;
			}
		}
		uv_data.uv_pipe_name.clear();
		uv_data.is_server_mode = false;
		uv_data.uv_looper = NULL;
		uv_data.external_sink = NULL;
		uv_data.owner = NULL;
	} while (false);
	if (buffered_ipc_msg)
	{
		free(buffered_ipc_msg);
		buffered_ipc_msg = NULL;
	}
	buffered_ipc_msg_offset = 0;
	return succ;
}

void on_pipe_client_connection_cb(uv_stream_t* server,int status)
{
	UVIPC::UVIPCData* ipc_data = (UVIPC::UVIPCData*)server;
	if (NULL == ipc_data || NULL == ipc_data->owner)
		return;

	ipc_data->owner->uv_cb_client_connection_notify(server, status);
}

bool UVIPC::StartWithServer(char* name_, bool is_server, uv_loop_t* loop_)
{
	bool succ = false;
	do 
	{
		if (NULL == name_ || NULL == loop_ || !is_server)
			break;
		uv_fs_t req;
		uv_fs_unlink(loop_, &req, name_, NULL);
		uv_pipe_init(loop_, (uv_pipe_t*)&uv_data, 0);
		uv_data.owner = this;
		int ret=uv_pipe_bind((uv_pipe_t*)&uv_data, name_);
		if(ret)
		{
			break;
		}

		ret=uv_listen((uv_stream_t*)&uv_data, 128, on_pipe_client_connection_cb);
		if(ret)
		{
			break;
		}

		uv_data.is_server_mode = is_server;
		uv_data.uv_looper = loop_;
		succ = true;
	} while (false);
	return succ;
}

void on_server_connected_cb(uv_connect_t* req,int status)
{
	UVIPC::UVIPCData* ipc_data = (UVIPC::UVIPCData*)req->handle;
	if (ipc_data && ipc_data->owner)
		ipc_data->owner->uv_cb_server_connected_notify(req, status);
}

bool UVIPC::StartWithClient(char* name_, bool is_server, uv_loop_t* loop_)
{
	bool succ = false;
	do 
	{
		if (is_server || NULL == name_ 
			|| NULL == loop_ || NULL != uv_data.ut.part_c.connect)
			break;

		uv_data.owner = this;
		int ret = uv_pipe_init(loop_, (uv_pipe_t*)&uv_data, 0);
		uv_data.ut.part_c.connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));
		uv_pipe_connect(uv_data.ut.part_c.connect, (uv_pipe_t*)&uv_data, name_, on_server_connected_cb);

		uv_data.is_server_mode = is_server;
		uv_data.uv_looper = loop_;
		succ = true;
	} while (false);

	return succ;
}

void alloc_buffer_for_uv_pipe(uv_handle_t* handle,size_t suggested_size,uv_buf_t* buf)
{
	buf->base = (char*)malloc(suggested_size);
	buf->len = suggested_size;
}

void on_pipe_data_read_cb(uv_stream_t* client, ssize_t nread,const uv_buf_t* buf)
{
	UVIPC* owner_ = NULL;
	{
		g_owner_locker.Lock(false);
		std::map<void *, UVIPC *>::iterator iter_ = g_owner_list.find(client);
		if (g_owner_list.end() != iter_)
		{
			owner_ = iter_->second;
		}
		g_owner_locker.Unlock(false);
	}

	if (owner_)
		owner_->uv_cb_pipe_data_read(client, nread, buf);
}

void UVIPC::uv_cb_client_connection_notify(uv_stream_t* server, int status)
{
	if(status < 0 || NULL == uv_data.uv_looper
		|| NULL != uv_data.ut.part_s.client)
	{  
		return;
	}
	uv_data.ut.part_s.client = (uv_pipe_t*)malloc(sizeof(uv_pipe_t));
	if (NULL == uv_data.ut.part_s.client)
	{
		return;
	}
	
	uv_pipe_init(uv_data.uv_looper, uv_data.ut.part_s.client ,0);
	int ret=uv_accept(server, (uv_stream_t*)uv_data.ut.part_s.client);
	if(ret==0)
	{
		{
			g_owner_locker.Lock(true);
			g_owner_list.insert(std::make_pair((void*)uv_data.ut.part_s.client, this));
			g_owner_locker.Unlock(true);
		}
		if (uv_data.external_sink)
			uv_data.external_sink->onConnect();
		uv_read_start((uv_stream_t*)uv_data.ut.part_s.client, alloc_buffer_for_uv_pipe, on_pipe_data_read_cb);
	}
}

#define BUFFERED_MSG_MAX_LEN (10*1024*1024)
void UVIPC::uv_cb_pipe_data_read(uv_stream_t* client, ssize_t nread,const uv_buf_t* buf)
{
	if(nread<0)
	{
		if(nread!=UV_EOF)
		{    
		}

		if (uv_data.external_sink)
			uv_data.external_sink->onDisconnect();
		Stop();
	}
	else if(nread > 0 && uv_data.external_sink)
	{
		if (NULL == buffered_ipc_msg)
		{
			buffered_ipc_msg = (char*)malloc(BUFFERED_MSG_MAX_LEN);
			buffered_ipc_msg_offset = 0;
		}
		const char* p(NULL), *end(NULL);
		if (buffered_ipc_msg_offset == 0)
		{
			p = buf->base;
			end = p + nread;
		}
		else
		{
            ssize_t buffer_remain = BUFFERED_MSG_MAX_LEN - buffered_ipc_msg_offset;
			if (buffer_remain > nread)
			{
				memcpy(buffered_ipc_msg + buffered_ipc_msg_offset, buf->base, nread);
				buffered_ipc_msg_offset += nread;
				p = buffered_ipc_msg;
				end = p + buffered_ipc_msg_offset;
			}
			else
			{
				//fix me.
			}
		}
		
		while (p < end) {
            if (p + UVIPC_MSG_HEADER_LEN >= end)
                break;
			int msgLen = *(int*)(p+sizeof(unsigned long long));
			int dataLen = msgLen + UVIPC_MSG_HEADER_LEN;
			if (p + dataLen <= end)
			{
				char* real_buf = (char*)(p + UVIPC_MSG_HEADER_LEN);
				UVIPCMessage* msg = new UVIPCMessage(real_buf, msgLen);
				if (msg)
				{
					uv_data.external_sink->onMessageRecvNotification(msg);
					msg->Release();
				}
				p = p + dataLen;
			}
			else {
				// Last message is partial.
				break;
			}
		}
		memmove(buffered_ipc_msg, p, end - p);
		buffered_ipc_msg_offset = end - p;
	}

	if (buf && buf->base)
	{
		free(buf->base);
	}
}

void UVIPC::uv_cb_pipe_data_write(uv_write_t* req, int status)
{

}

void on_write_data_cb(uv_write_t* req,int status)
{
	if (status == 0) {
	}

	uv_buf_t* w_buf = (uv_buf_t*)req->data;
	if (w_buf)
	{
		unsigned long long* real_buf = (unsigned long long*)(w_buf->base);
		UVIPCMessage* msg = (UVIPCMessage*)*real_buf;
		msg->Release();
		free(w_buf);
	}
	free(req);

}

void UVIPC::uv_cb_server_connected_notify(uv_connect_t* req,int status)
{
	uv_write_t* wr = (uv_write_t*)malloc(sizeof(uv_write_t));
	do 
	{
		if (NULL == wr)
			break;
		{
			g_owner_locker.Lock(true);
			g_owner_list.insert(std::make_pair((void*)req->handle, this));
			g_owner_locker.Unlock(true);
		}
		if (uv_data.external_sink)
		{
			(0 == status) ? uv_data.external_sink->onConnect() : uv_data.external_sink->onDisconnect();
		}

		if (0 == status)
			uv_read_start((uv_stream_t*)req->handle, alloc_buffer_for_uv_pipe, on_pipe_data_read_cb);
		else
			Stop();
	} while (false);
}

bool UVIPC::SendMessage(const char* buf, int len)
{
	if (NULL == buf || len <= 0)
		return false;

	if (!IsRunning(true))
		return false;
	
	UVIPCMessage* msg = new UVIPCMessage(buf, len);
	outmsg_locker.Lock();
	outmsg_list.push_back(msg);
	outmsg_locker.Unlock();

	return true;
}

bool UVIPC::SendMessage(UVIPCMessage* msg)
{
	if (!IsRunning(true))
		return false;

	outmsg_locker.Lock();
	outmsg_list.push_back(msg);
	outmsg_locker.Unlock();

	return true;
}

void UVIPC::uv_cb_ipc_timer(uv_timer_t* handle)
{
	if (outmsg_list.size() <= 0
		|| (uv_data.is_server_mode && NULL == uv_data.ut.part_s.client)
		|| (!uv_data.is_server_mode && NULL == uv_data.ut.part_c.connect))
	{
		if (outmsg_list.size() <= 0 && uv_data.external_sink && IsRunning(true))
			uv_data.external_sink->onIdle();
		return;
	}

	std::list<UVIPCMessage* > tmp_outmsg_list;
	outmsg_locker.Lock();
	tmp_outmsg_list.swap(outmsg_list);
	outmsg_locker.Unlock();
	std::list<UVIPCMessage* >::iterator it_msg = tmp_outmsg_list.begin();
	while(tmp_outmsg_list.end() != it_msg)
	{
		UVIPCMessage* msg = *it_msg;
		if (msg)
		{
			uv_write_t* w_req = (uv_write_t*)malloc(sizeof(uv_write_t));
			uv_buf_t* w_buf = (uv_buf_t*)malloc(sizeof(uv_buf_t));

			w_buf->base = msg->GetRealBuf();
			w_buf->len = msg->GetRealLen();
			w_req->data = w_buf;
			int ret = uv_write(w_req, (uv_data.is_server_mode ? (uv_stream_t*)uv_data.ut.part_s.client : uv_data.ut.part_c.connect->handle),
				w_buf, 1, on_write_data_cb);
			it_msg = tmp_outmsg_list.erase(it_msg);
		}
	}
}
