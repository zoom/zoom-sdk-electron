#include "raw_data_uv_ipc_server.h"
#ifdef _WIN32
#else
#include <unistd.h>
#endif
RawDataUVIPCServer::RawDataUVIPCServer()
{
	_client_connected_count = 0;
}
RawDataUVIPCServer::~RawDataUVIPCServer()
{
}
void work_thread_sync_proc(uv_async_t *handle) {
	if (handle && handle->data)
	{
		RawDataUVIPCServer::WorkThreadParam* p_work = (RawDataUVIPCServer::WorkThreadParam*)handle->data;
		if (0xccdd == p_work->action)
		{
			p_work->action = 0;
			uv_stop(p_work->_rawdata_pipe_server_loop);
		}
	}
}
void work_thread_proc(void *param)
{
	if (NULL == param)
		return;

	RawDataUVIPCServer::WorkThreadParam* p_work = (RawDataUVIPCServer::WorkThreadParam*)param;
	p_work->_rawdata_pipe_server_loop = new uv_loop_t;
	if (p_work->_rawdata_pipe_server_loop)
	{
		uv_loop_init(p_work->_rawdata_pipe_server_loop);
		uv_async_init(p_work->_rawdata_pipe_server_loop, &p_work->async, work_thread_sync_proc);
		p_work->_rawdata_pipe_server.Start(const_cast<char*>(p_work->pipe_name.c_str()),
			true, p_work->_rawdata_pipe_server_loop, p_work->_sink);

		p_work->_running = true;
		uv_run(p_work->_rawdata_pipe_server_loop, UV_RUN_DEFAULT);
		p_work->_rawdata_pipe_server.Stop();
		uv_close((uv_handle_t*)&p_work->async, NULL);

		uv_loop_close(p_work->_rawdata_pipe_server_loop);
		p_work->_running = false;
	}

	if (p_work->_rawdata_pipe_server_loop)
	{
		delete p_work->_rawdata_pipe_server_loop;
		p_work->_rawdata_pipe_server_loop = NULL;
	}
}

static void z_sleep(unsigned int millisecond) {
#ifdef _WIN32
	::Sleep(millisecond);
#else
    usleep(millisecond * 1000);
#endif
}

bool RawDataUVIPCServer::StartPipeServer(char* pipe_name, UVIPCSink* sink)
{
	if (NULL == pipe_name)
		return false;

	if (_work_param._running)
		return false;

	_work_param.pipe_name = pipe_name;
	_work_param._sink = sink;
	uv_thread_t work_thread;
	uv_thread_create(&work_thread, work_thread_proc, &_work_param);
	while (!_work_param._running)
	{
		z_sleep(100);
	}

	return true;
}
bool RawDataUVIPCServer::StopPipeServer()
{
	if (_work_param._running && 0xccdd != _work_param.action)
	{
		_work_param.action = 0xccdd;
		_work_param.async.data = (void*)&_work_param;
		uv_async_send(&_work_param.async);
	}
	return true;
}

bool RawDataUVIPCServer::SendMessage(const char* buf, int len)
{
	if (_work_param._running )
	{
		return _work_param._rawdata_pipe_server.SendMessage(buf, len);
	}

	return false;
}
bool RawDataUVIPCServer::SendMessage(UVIPCMessage* msg)
{
	if (_work_param._running)
	{
		return _work_param._rawdata_pipe_server.SendMessage(msg);
	}

	return false;
}

void RawDataUVIPCServer::onMessageRecvNotification(UVIPCMessage* msg)
{
	if (_work_param._sink)
		_work_param._sink->onMessageRecvNotification(msg);
}
void RawDataUVIPCServer::onConnect()
{
	++_client_connected_count;
	if (_work_param._sink)
		_work_param._sink->onConnect();
}
void RawDataUVIPCServer::onDisconnect()
{
	--_client_connected_count;
	if (_work_param._sink)
		_work_param._sink->onConnect();
}
void RawDataUVIPCServer::onIdle()
{
	if (_work_param._sink)
		_work_param._sink->onIdle();
}
