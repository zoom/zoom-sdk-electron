#include "zoom_raw_data_wrap.h"
#include "zoom_node_video_raw_data.h"
#include "run_task_to_main_thread.h"
#include <iostream>
#include <string>
#include "raw_data_uv_ipc_server.h"
#include "raw_data_format.h"

class VideoRawDataHelper : public IVideoRawDataReceiver, public UVIPCSink
{
public:
	friend class ZoomNodeVideoRawDataWrap;
	VideoRawDataHelper()
	{
		_channel = NULL;
		_libuv_option = false;
	}
	~VideoRawDataHelper()
	{
		if (_channel)
			_channel->Stop();
		_channel = NULL;
		_libuv_option = false;
	}

	virtual void onDeviceRunning(void* device) {}
	virtual void onDeviceStop(void* device) {}

	virtual void onConnect() {}
	virtual void onDisconnect() {}
	virtual void onMessageRecvNotification(UVIPCMessage* msg)
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
	virtual void onIdle() {}
#define max_cache_frame 10
	virtual void onVideoRawDataReceived(YUVRawDataI420* data_, IVector<unsigned long long >* recv_handle_list)
	{
		if (_libuv_option)
		{
			if (_uv_ipc_server.HasClientConnected() && data_)
			{
				{
					std::lock_guard<std::mutex> lock_(_cached_raw_data_count_map_mutex);
					std::map<unsigned int, int>::iterator iter = _cached_raw_data_count_map.find(data_->GetSourceID());
					if (_cached_raw_data_count_map.end() != iter)
					{
						if (iter->second > max_cache_frame)
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
						_cached_raw_data_count_map.insert(std::make_pair(data_->GetSourceID(), 1));
					}	
				}
				UVIPCMessage* rawdata_msg = MakeUVIPCMsg(data_, recv_handle_list, TYPE_VIDEO);
				_uv_ipc_server.SendMessage(rawdata_msg);
			}
		}
		else
		{
			if (data_ && data_->CanAddRef())
			{
				data_->AddRef();

				{
					std::lock_guard<std::mutex> lock_(_cached_raw_data_mutex);
					std::map<unsigned int, IMainThreadTask* >::iterator iter_ = _cached_raw_data.find(data_->GetSourceID());
					if (_cached_raw_data.end() != iter_ && iter_->second)
					{
						IVector<unsigned long long >* recv_handle_list_tmp = NULL;
						if (recv_handle_list && recv_handle_list->GetCount() > 0)
						{
							CZNodeSetImpl<unsigned long long >* znSet = new CZNodeSetImpl<unsigned long long >;
							if (znSet)
							{
								int count = recv_handle_list->GetCount();
								for (int index = 0; index < count; index++)
								{
									znSet->m_List.insert(recv_handle_list->GetItem(index));
								}
								recv_handle_list_tmp = znSet;
							}
						}

						iter_->second->UpdateData(data_, recv_handle_list_tmp);
						return;
					}
				}

				class VideoRawDataTask : public IMainThreadTask
				{
				public:
					friend class VideoRawDataHelper;
					explicit VideoRawDataTask(VideoRawDataHelper* helper, YUVRawDataI420* data, IVector<unsigned long long >* recv_handle_list)
					{
						helper_ = helper;
						data_ = data;
						recv_handle_list_ = recv_handle_list;
						if (helper_ && data_)
						{
							std::lock_guard<std::mutex> lock_(helper_->_cached_raw_data_mutex);
							helper_->_cached_raw_data.insert(std::make_pair(data_->GetSourceID(), this));
						}
					}
					virtual ~VideoRawDataTask() {}
					virtual void Run()
					{
						if (helper_ && data_)
						{
							std::lock_guard<std::mutex> lock_(helper_->_cached_raw_data_mutex);
							helper_->_cached_raw_data.erase(data_->GetSourceID());
						}
						if (helper_)
							helper_->onVideoRawDataReceived_MainThread(data_, recv_handle_list_);
						if (data_)
							data_->Release();
						if (recv_handle_list_)
							delete recv_handle_list_;

						delete this;
					}

					virtual void UpdateData(void* data_new, void* recv_handle_list_new)
					{
						{
							if (data_)
								data_->Release();
							if (recv_handle_list_)
								delete recv_handle_list_;

							data_ = (YUVRawDataI420*)data_new;
							recv_handle_list_ = (IVector<unsigned long long >*)recv_handle_list_new;
						}
					}

				private:
					VideoRawDataHelper* helper_;
					YUVRawDataI420* data_;
					IVector<unsigned long long >* recv_handle_list_;
				};

				IVector<unsigned long long >* recv_handle_list_tmp = NULL;
				if (recv_handle_list && recv_handle_list->GetCount() > 0)
				{
					CZNodeSetImpl<unsigned long long >* znSet = new CZNodeSetImpl<unsigned long long >;
					if (znSet)
					{
						int count = recv_handle_list->GetCount();
						for (int index = 0; index < count; index++)
						{
							znSet->m_List.insert(recv_handle_list->GetItem(index));
						}
						recv_handle_list_tmp = znSet;
					}
				}
				if (!PostTaskToMainThread(new VideoRawDataTask(this, data_, recv_handle_list_tmp)))
					data_->Release();
			}
		}
	}

	virtual void onVideoRawDataReceived_MainThread(YUVRawDataI420* data_, IVector<unsigned long long >* recv_handle_list)
	{
		if (_onVideoRawDataReceived.IsEmpty() 
			|| NULL == data_)
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		//1.data buffer
		auto array_data_buf = v8::ArrayBuffer::New(isolate, data_->GetBuffer(), data_->GetBufferLen(), v8::ArrayBufferCreationMode::kExternalized);
		v8::Local<v8::Uint8Array> uint8_array_data_buf = v8::Uint8Array::New(array_data_buf, 0, data_->GetBufferLen());

		//2.data format
		char format_[200] = { 0 };
		//type islimit width height yoffset uoffset voffset
		sprintf(format_, "%s;%d;%d;%d;%d;%llu;%llu;%llu", "yuvi420", data_->IsLimitedI420() ? 1 : 0,
			data_->GetStreamWidth(), data_->GetStreamHeight(), data_->GetRotation(),
			(unsigned long long)data_->GetYBuffer() - (unsigned long long)data_->GetBuffer(),
			(unsigned long long)data_->GetUBuffer() - (unsigned long long)data_->GetBuffer(),
			(unsigned long long)data_->GetVBuffer() - (unsigned long long)data_->GetBuffer()
		);
		v8::Local<v8::Value> data_format = v8::String::NewFromUtf8(isolate, format_, v8::NewStringType::kInternalized).ToLocalChecked();

		//3.recv_handle_list
		v8::Local<v8::BigUint64Array> ull_array_recv_handle;
		if (recv_handle_list)
		{
			auto array_recv_handle = v8::ArrayBuffer::New(isolate, recv_handle_list->GetCount()*sizeof(unsigned long long));
			for (int index = 0; index < recv_handle_list->GetCount(); ++index) {
				unsigned long long* buf_ull = (unsigned long long*)array_recv_handle->GetContents().Data();
				buf_ull[index] = recv_handle_list->GetItem(index);
			}
			ull_array_recv_handle = v8::BigUint64Array::New(array_recv_handle, 0, recv_handle_list->GetCount());
		}
		
		int argc = 3;
		v8::Local<v8::Value> argv[3] = { uint8_array_data_buf, data_format, ull_array_recv_handle };
		auto fn = v8::Local<v8::Function>::New(isolate, _onVideoRawDataReceived);

		fn->Call(context, global, argc, argv);
	}

	virtual void onSubscribedVideoUserDataOn(IVector<unsigned long long >* recv_handle_list)
	{
		if (_onSubscribedVideoUserDataOn.IsEmpty())
		{
			return;
		}
			
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::BigUint64Array> ull_array_recv_handle;
		if (recv_handle_list)
		{
			auto array_recv_handle = v8::ArrayBuffer::New(isolate, recv_handle_list->GetCount() * sizeof(unsigned long long));
			for (int index = 0; index < recv_handle_list->GetCount(); ++index) {
				unsigned long long* buf_ull = (unsigned long long*)array_recv_handle->GetContents().Data();
				buf_ull[index] = recv_handle_list->GetItem(index);
			}
			ull_array_recv_handle = v8::BigUint64Array::New(array_recv_handle, 0, recv_handle_list->GetCount());
		}
		int argc = 1;
		v8::Local<v8::Value> argv[1] = {ull_array_recv_handle };
		auto fn = v8::Local<v8::Function>::New(isolate, _onSubscribedVideoUserDataOn);
		fn->Call(context, global, argc, argv);
	}

	virtual void onSubscribedVideoUserDataOff(IVector<unsigned long long >* recv_handle_list)
	{
		if (_onSubscribedVideoUserDataOff.IsEmpty())
		{
			return;
		}
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::BigUint64Array> ull_array_recv_handle;
		if (recv_handle_list)
		{
			auto array_recv_handle = v8::ArrayBuffer::New(isolate, recv_handle_list->GetCount() * sizeof(unsigned long long));
			for (int index = 0; index < recv_handle_list->GetCount(); ++index) {
				unsigned long long* buf_ull = (unsigned long long*)array_recv_handle->GetContents().Data();
				buf_ull[index] = recv_handle_list->GetItem(index);
			}
			ull_array_recv_handle = v8::BigUint64Array::New(array_recv_handle, 0, recv_handle_list->GetCount());
		}
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { ull_array_recv_handle };
		auto fn = v8::Local<v8::Function>::New(isolate, _onSubscribedVideoUserDataOff);
		fn->Call(context, global, argc, argv);
	}

	virtual void onSubscribedVideoUserLeft(IVector<unsigned long long >* recv_handle_list)
	{
		if (_onSubscribedVideoUserLeft.IsEmpty())
		{
			return;
		}
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		v8::Local<v8::BigUint64Array> ull_array_recv_handle;
		if (recv_handle_list)
		{
			auto array_recv_handle = v8::ArrayBuffer::New(isolate, recv_handle_list->GetCount() * sizeof(unsigned long long));
			for (int index = 0; index < recv_handle_list->GetCount(); ++index) {
				unsigned long long* buf_ull = (unsigned long long*)array_recv_handle->GetContents().Data();
				buf_ull[index] = recv_handle_list->GetItem(index);
			}
			ull_array_recv_handle = v8::BigUint64Array::New(array_recv_handle, 0, recv_handle_list->GetCount());
		}
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { ull_array_recv_handle };
		auto fn = v8::Local<v8::Function>::New(isolate, _onSubscribedVideoUserLeft);
		fn->Call(context, global, argc, argv);
	}

private:
	IVideoRawDataChannel*  _channel;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > _onVideoRawDataReceived;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > _onSubscribedVideoUserDataOn;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > _onSubscribedVideoUserDataOff;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > _onSubscribedVideoUserLeft;
	std::mutex _cached_raw_data_mutex;
	std::map<unsigned int, IMainThreadTask* > _cached_raw_data;
	bool _libuv_option;
	RawDataUVIPCServer _uv_ipc_server;
	std::mutex _cached_raw_data_count_map_mutex;
	std::map<unsigned int, int > _cached_raw_data_count_map;
};
VideoRawDataHelper g_video_rawdata;

ZoomNodeVideoRawDataWrap::ZoomNodeVideoRawDataWrap()
{

}

ZoomNodeVideoRawDataWrap::~ZoomNodeVideoRawDataWrap()
{

}

void ZoomNodeVideoRawDataWrap::SetRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		g_video_rawdata._onVideoRawDataReceived.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	g_video_rawdata._onVideoRawDataReceived = cb;

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_SUCCESS);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::SetRawDataVideoUserDataOnCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		g_video_rawdata._onSubscribedVideoUserDataOn.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	g_video_rawdata._onSubscribedVideoUserDataOn = cb;

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_SUCCESS);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::SetRawDataVideoUserDataOffCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		g_video_rawdata._onSubscribedVideoUserDataOff.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	g_video_rawdata._onSubscribedVideoUserDataOff = cb;

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_SUCCESS);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::SetRawDataVideoUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{

	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		g_video_rawdata._onSubscribedVideoUserLeft.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	g_video_rawdata._onSubscribedVideoUserLeft = cb;

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_SUCCESS);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::Start(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (NULL == g_video_rawdata._channel)
		Node_RetrieveVideoRawDataChannel(&g_video_rawdata._channel);
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	if (g_video_rawdata._channel)
	{
		if (g_video_rawdata._libuv_option)
			g_video_rawdata._channel->EnableIntermediateRawDataCB(true);
		err = g_video_rawdata._channel->Start(RawDataMemoryMode_Heap, &g_video_rawdata);
	}
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber() ||
		!args[2]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	if (g_video_rawdata._channel)
	{
		err = g_video_rawdata._channel->Subscribe(args[0].As<v8::Integer >()->Value(),
			(RawDataResolution)args[1].As<v8::Integer >()->Value(), args[2].As<v8::Integer >()->Value());
	}
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	if (g_video_rawdata._channel)
	{
		err = g_video_rawdata._channel->UnSubscribe(args[0].As<v8::Integer >()->Value(),
			args[1].As<v8::Integer >()->Value());
	}
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::GetLocalDeviceStatus(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_WRONGUSAGE);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::RotateLocalDevice(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_WRONGUSAGE);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataWrap::Stop(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (NULL == g_video_rawdata._channel)
		Node_RetrieveVideoRawDataChannel(&g_video_rawdata._channel);
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	if (g_video_rawdata._channel)
		err = g_video_rawdata._channel->Stop();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeVideoRawDataWrap::StartPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	if (!g_video_rawdata._libuv_option)
	{
		err = g_video_rawdata._uv_ipc_server.StartPipeServer(VIDEO_PIPE_NAME, &g_video_rawdata);
		g_video_rawdata._libuv_option = true;
	}
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);

}
void ZoomNodeVideoRawDataWrap::StopPipeServer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	if (g_video_rawdata._libuv_option)
	{
		g_video_rawdata._libuv_option = false;
		err = g_video_rawdata._uv_ipc_server.StopPipeServer();
	}
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}


