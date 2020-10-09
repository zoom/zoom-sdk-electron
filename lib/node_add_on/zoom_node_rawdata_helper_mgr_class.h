#ifndef _zoom_node_rawdata_helper_mgr_class_h_
#define _zoom_node_rawdata_helper_mgr_class_h_

#include <mutex>
#include <thread>
#include <map>
#include <iostream>
#include <string>
#include "raw_data_uv_ipc_server.h"
#include "raw_data_format.h"
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"



class ZoomNodePipeServerMgr : public UVIPCSink
{
public:
	ZoomNodePipeServerMgr() { libuv_option = false; }
	~ZoomNodePipeServerMgr() { libuv_option = false; }

	virtual void onConnect() 
	{
		
	}
	virtual void onDisconnect() 
	{
		
	}
	virtual void onMessageRecvNotification(UVIPCMessage* msg);
	virtual void onIdle() {}

public:
	RawDataUVIPCServer _uv_ipc_server;
	std::mutex _cached_raw_data_count_map_mutex;
	std::map<unsigned int, int > _cached_raw_data_count_map;
	bool libuv_option;
};

////////////////////////////////////////////////////////////////////////////////
class ZoomNodeRawDataHelperMgr
{
public:
	static ZoomNodeRawDataHelperMgr& GetInst()
	{
		static ZoomNodeRawDataHelperMgr inst;
		return inst;
	}
#if (defined _WIN32)
#define Node_VideoYUV_DEF YUVRawDataI420
#else
#define Node_VideoYUV_DEF ZoomNodeYUVRawdataI420
#endif
	void onRawDataFrameReceived(Node_VideoYUV_DEF* data_, unsigned long long recv_handle_, ZNZoomSDKRawDataType type_);
	void onRawDataStatusChanged(ZNRawDataStatus status, unsigned long long recv_handle_);

#if (defined _WIN32)
#define Node_AudioRawData_DEF AudioRawData
#else
#define Node_AudioRawData_DEF ZoomNodeAudioRawdata
#endif
	void onMixedAudioRawDataReceived(Node_AudioRawData_DEF* data_);
	void onOneWayAudioRawDataReceived(Node_AudioRawData_DEF* data_, uint32_t node_id);

	void SetRawdataIntermediateMode(bool bEnableRawdataIntermediateMode);
	bool GetRawdataIntermediateMode();

	~ZoomNodeRawDataHelperMgr()
	{
	}

private:
	ZoomNodeRawDataHelperMgr() { m_enableRawdataIntermediateMode = true; }
	bool m_enableRawdataIntermediateMode;
};
#endif // !_zoom_instant_node_rawdata_helper_mgr_class_h_
