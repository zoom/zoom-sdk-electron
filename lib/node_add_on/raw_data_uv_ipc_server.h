#ifndef _raw_data_uv_ipc_server_h_
#define _raw_data_uv_ipc_server_h_
#include "uv_ipc_common.h"
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////////
class RawDataUVIPCServer : public UVIPCSink
{
public:
	RawDataUVIPCServer();
	virtual ~RawDataUVIPCServer();
	bool StartPipeServer(char* pipe_name, UVIPCSink* sink);
	bool StopPipeServer();


	virtual void onMessageRecvNotification(UVIPCMessage* msg);
	virtual void onConnect();
	virtual void onDisconnect();
	virtual void onIdle();
	bool SendMessage(const char* buf, int len);
	bool SendMessage(UVIPCMessage* msg);

	bool HasClientConnected() { return _work_param._rawdata_pipe_server.IsRunning(true); }
	struct WorkThreadParam
	{
		UVIPC _rawdata_pipe_server;
		uv_async_t async;
		std::string pipe_name;
		uv_loop_t* _rawdata_pipe_server_loop;
		UVIPCSink* _sink;
		bool _running;
		int action;
		WorkThreadParam()
		{
			pipe_name.clear();
			_rawdata_pipe_server_loop = NULL;
			_running = false;
			_sink = NULL;
			action = 0;
		}
	};
private:
	int  _client_connected_count;
	WorkThreadParam _work_param;
};
#endif