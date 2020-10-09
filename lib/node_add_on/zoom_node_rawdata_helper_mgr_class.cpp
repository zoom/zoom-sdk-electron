
#include "zoom_node_rawdata_helper_mgr_class.h"

////////////////////////////////////////////////////////////////////////////////

void ZoomNodePipeServerMgr::onMessageRecvNotification(UVIPCMessage* msg)
{
	if (NULL == msg)
		return;
	if (sizeof(unsigned int) != msg->GetLen()
		|| NULL == msg->GetBuf())
		return;
	unsigned int* p_source_id = (unsigned int*)msg->GetBuf();
	std::lock_guard<std::mutex> lock_(_cached_raw_data_count_map_mutex);
	std::map<unsigned int, int>::iterator iter = _cached_raw_data_count_map.find(*p_source_id);
	if (_cached_raw_data_count_map.end() != iter)
		--iter->second;
}
ZoomNodePipeServerMgr _g_video_pipe_server;
ZoomNodePipeServerMgr _g_audio_pipe_server;
ZoomNodePipeServerMgr _g_share_pipe_server;

/////////////////////////////////////////////////////////////////////////////
#define max_cache_frame_ 10

void ZoomNodeRawDataHelperMgr::onRawDataFrameReceived(Node_VideoYUV_DEF* data_, unsigned long long recv_handle_, ZNZoomSDKRawDataType type_)
{
	if (ZNRAW_DATA_TYPE_VIDEO == type_)
	{
		if (_g_video_pipe_server._uv_ipc_server.HasClientConnected() && data_)
		{
			{
				std::lock_guard<std::mutex> lock_(_g_video_pipe_server._cached_raw_data_count_map_mutex);
#ifdef _WIN32
				std::map<unsigned int, int>::iterator iter = _g_video_pipe_server._cached_raw_data_count_map.find(data_->GetSourceID());
#else
                std::map<unsigned int, int>::iterator iter = _g_video_pipe_server._cached_raw_data_count_map.find(data_->source_id);
#endif
				if (_g_video_pipe_server._cached_raw_data_count_map.end() != iter)
				{
					if (iter->second > max_cache_frame_)
					{
						return;
					}
					else
					{
						++iter->second;
					}
				}
				else
				{
#ifdef _WIN32
                    _g_video_pipe_server._cached_raw_data_count_map.insert(std::make_pair(data_->GetSourceID(), 1));
#else
                    _g_video_pipe_server._cached_raw_data_count_map.insert(std::make_pair(data_->source_id, 1));
#endif
				}
			}
			UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, recv_handle_, TYPE_VIDEO);
			_g_video_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
		}
	}
	if (ZNRAW_DATA_TYPE_SHARE == type_)
	{
		if (_g_share_pipe_server._uv_ipc_server.HasClientConnected() && data_)
		{
			{
				std::lock_guard<std::mutex> lock_(_g_share_pipe_server._cached_raw_data_count_map_mutex);
#ifdef _WIN32
                std::map<unsigned int, int>::iterator iter = _g_share_pipe_server._cached_raw_data_count_map.find(data_->GetSourceID());
#else
                std::map<unsigned int, int>::iterator iter = _g_share_pipe_server._cached_raw_data_count_map.find(data_->source_id);

#endif
				if (_g_share_pipe_server._cached_raw_data_count_map.end() != iter)
				{
					if (iter->second > max_cache_frame_)
					{
						return;
					}
					else
					{
						++iter->second;
					}
				}
				else
				{
#ifdef _WIN32
					_g_share_pipe_server._cached_raw_data_count_map.insert(std::make_pair(data_->GetSourceID(), 1));
#else
                    _g_share_pipe_server._cached_raw_data_count_map.insert(std::make_pair(data_->source_id, 1));
#endif
				}
			}
			UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, recv_handle_, TYPE_SHARE);
			_g_share_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
		}
	}
}

void ZoomNodeRawDataHelperMgr::onRawDataStatusChanged(ZNRawDataStatus status, unsigned long long recv_handle_)
{
	if (ZoomNodeSinkHelper::GetInst().onRawDataStatusChanged.IsEmpty())
		return;

	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();

	v8::Local<v8::Integer> v8_rawdataStatus = v8::Integer::New(isolate, (int32_t)status);
	v8::Local<v8::Integer> v8_recv_handle = v8::Integer::New(isolate, (uint64_t)recv_handle_);
	int argc = 2;
	v8::Local<v8::Value> argv[2] = { v8_rawdataStatus, v8_recv_handle };
	auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onRawDataStatusChanged);

	fn->Call(context, global, argc, argv);
}

void ZoomNodeRawDataHelperMgr::onMixedAudioRawDataReceived(Node_AudioRawData_DEF* data_)
{
	if (_g_audio_pipe_server._uv_ipc_server.HasClientConnected() && data_)
	{
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, 0, TYPE_AUDIO);
		_g_audio_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
	}
}
void ZoomNodeRawDataHelperMgr::onOneWayAudioRawDataReceived(Node_AudioRawData_DEF* data_, uint32_t node_id)
{
	if (_g_audio_pipe_server._uv_ipc_server.HasClientConnected() && data_)
	{
		UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, node_id, TYPE_AUDIO);
		_g_audio_pipe_server._uv_ipc_server.SendMessage(rawdata_msg);
	}
}
void ZoomNodeRawDataHelperMgr::SetRawdataIntermediateMode(bool bEnableRawdataIntermediateMode)
{
	m_enableRawdataIntermediateMode = bEnableRawdataIntermediateMode;
}
bool ZoomNodeRawDataHelperMgr::GetRawdataIntermediateMode()
{
	return m_enableRawdataIntermediateMode;
}


