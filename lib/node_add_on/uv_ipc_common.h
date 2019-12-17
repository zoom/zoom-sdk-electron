#ifndef uv_ipc_common_h
#define uv_ipc_common_h
#include "uv.h"
#include <string>
#include <list>
class UVIPCLocker
{
public:
	UVIPCLocker()
	{
		uv_rwlock_init(&uv_rw_locker);
	}
	virtual ~UVIPCLocker()
	{
		uv_rwlock_destroy(&uv_rw_locker);
	}

	void Lock(bool write = true);
	void Unlock(bool write = true);
private:
	uv_rwlock_t uv_rw_locker;
};

#ifdef _WIN32
#include <windows.h>
typedef LONG                                 UVAtmInt;
#   define uv_atomic_inc                    ::InterlockedIncrement
#   define uv_atomic_dec                    ::InterlockedDecrement
#else//now only support win and mac

#include <libkern/OSAtomic.h>
typedef int32_t                         UVAtmInt;
#   define uv_atomic_inc                    OSAtomicIncrement32
#   define uv_atomic_dec                    OSAtomicDecrement32
#endif

class UVCAtomicInt
{
private:
	UVAtmInt m_nVal;
public:
	UVCAtomicInt (long n = 0) : m_nVal (n) {}
	UVAtmInt Inc () { return uv_atomic_inc (&m_nVal); }
	UVAtmInt Dec () { return uv_atomic_dec (&m_nVal); }
	long Get () const { return m_nVal; }
};

#define UVIPC_MSG_HEADER_LEN (sizeof(unsigned long long)+sizeof(int))
class UVIPCMessage
{
public:
	explicit UVIPCMessage(const char* in_buf, int in_len, bool using_external_buffer_ = false);
	char* GetBuf();
	int GetLen();
	char* GetRealBuf();
	int GetRealLen();
	virtual bool AddRef()
	{
		if (ref_count.Get() > 0)
		{
			ref_count.Inc();
			return true;
		}
		return false;
	}
	virtual int Release()
	{
		if (ref_count.Get() <= 0)
			return 0;

		int ref_ = ref_count.Dec();
		if (ref_ == 0)
		{
			delete this;
		}
		return ref_;
	}
protected:
	virtual ~UVIPCMessage();
private:
	char* buf;
	int len;
	UVCAtomicInt ref_count;
	bool using_external_buffer;
};

#if (defined _WIN32)
class RUNTIMECOUNTER
{
public:
	RUNTIMECOUNTER(){
		time=0;    
	}
	virtual ~RUNTIMECOUNTER(){}

	void start()
	{
		QueryPerformanceFrequency(&nFreq);  
		QueryPerformanceCounter(&nBeginTime);
	}
	int end()
	{
		QueryPerformanceCounter(&nEndTime);
		time=(double)(nEndTime.QuadPart-nBeginTime.QuadPart)/(double)nFreq.QuadPart;
		return (int)time*1000;
	}


private:
	double time;  
	LARGE_INTEGER nFreq;  
	LARGE_INTEGER nBeginTime;  
	LARGE_INTEGER nEndTime;  
};
#endif


class UVIPCSink
{
public:
	virtual void onConnect() = 0;
	virtual void onDisconnect() = 0;
	virtual void onMessageRecvNotification(UVIPCMessage* msg) = 0;
	virtual void onIdle() = 0;
};
class UVIPC
{
public:
	friend void on_pipe_client_connection_cb(uv_stream_t* server,int status);
	friend void on_pipe_data_read_cb(uv_stream_t* client,ssize_t nread,const uv_buf_t* buf);
	friend void on_server_connected_cb(uv_connect_t* req,int status);
	friend void on_write_data_cb(uv_write_t* req,int status);
	friend void uv_ipc_timer_cb(uv_timer_t* handle);
	UVIPC();
	virtual ~UVIPC();
	bool Start(char* name_, bool is_server, uv_loop_t* loop_, UVIPCSink* sink_);
	bool Stop();
	bool IsRunning(bool check_connection = false);

	bool SendMessage(const char* buf, int len);
	bool SendMessage(UVIPCMessage* msg);

private:
	typedef struct _UVIPCData
	{
		uv_pipe_t handle;
		UVIPC* owner;
		std::string uv_pipe_name;
		bool is_server_mode;
		uv_loop_t* uv_looper;
		UVIPCSink* external_sink;
		
		typedef struct _ServerPart  
		{
			uv_pipe_t* client;
		}ServerPart;
		typedef struct _ClientPart
		{
			uv_connect_t* connect;
		}ClientPart;
		union PART
		{
			ClientPart part_c;
			ServerPart part_s;
		}ut;
		_UVIPCData()
		{
			owner = NULL;
			is_server_mode = false;
			uv_looper = NULL;
			external_sink = NULL;
			memset(&ut, 0, sizeof(ut));
		}
	}UVIPCData;
	typedef struct _UVIPCTimerData
	{
		uv_timer_t uv_timer_req;
		UVIPC* owener;
		UVIPCData* owner_ipc_data;
		_UVIPCTimerData()
		{
			owener = NULL;
		}
	}UVIPCTimerData;
	bool StartWithServer(char* name_, bool is_server, uv_loop_t* loop_);
	void uv_cb_client_connection_notify(uv_stream_t* server, int status);


	bool StartWithClient(char* name_, bool is_server, uv_loop_t* loop_);
	void uv_cb_server_connected_notify(uv_connect_t* req,int status);

	void uv_cb_pipe_data_write(uv_write_t* req,int status);
	void uv_cb_pipe_data_read(uv_stream_t* client,ssize_t nread,const uv_buf_t* buf);
	void uv_cb_ipc_timer(uv_timer_t* handle);
	UVIPCData uv_data;
	UVIPCTimerData uv_timer_data;

	UVIPCLocker outmsg_locker;
	std::list<UVIPCMessage* > outmsg_list;
	char* buffered_ipc_msg;
	int buffered_ipc_msg_offset;
};
#endif
