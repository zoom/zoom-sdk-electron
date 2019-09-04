#include "zoom_raw_data_wrap.h"
#include "zoom_node_audio_raw_data.h"
#include "run_task_to_main_thread.h"

class AudioRawDataHelper : public IAudioRawDataReceiver
{
public:
	friend class ZoomNodeAudioRawDataWrap;
	AudioRawDataHelper()
	{
		_channel = NULL;
	}
	~AudioRawDataHelper()
	{
		if (_channel)
			_channel->Stop();
		_channel = NULL;
	}

	virtual void onMixedAudioRawDataReceived(AudioRawData* data_)
	{
		if (data_ && data_->CanAddRef())
		{
			data_->AddRef();

			class MixedAudioRawDataTask: public IMainThreadTask
			{
			public:
				friend class AudioRawDataHelper;
				explicit MixedAudioRawDataTask(AudioRawDataHelper* helper, AudioRawData* data)
				{
					helper_ = helper;
					data_ = data;
				}
				virtual ~MixedAudioRawDataTask() {}
				virtual void Run()
				{
					if (helper_)
					{
						helper_->onMixedAudioRawDataReceived_MainThread(data_);
					}
					if (data_)
					{
						data_->Release();
					}
					delete this;
				}
			private:
				AudioRawDataHelper* helper_;
				AudioRawData* data_;
			};
			if (!PostTaskToMainThread(new MixedAudioRawDataTask(this, data_)))
				data_->Release();

		}
	}
	virtual void onMixedAudioRawDataReceived_MainThread(AudioRawData* data_)
	{
		if (_onMixedAudioRawDataReceived.IsEmpty()
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

		//2. data format
		char format_[200] = { 0 };
		//type buffer_len sample_rate channel_num 
		sprintf(format_, "%s;%d;%d;%d;", "AudioRawData", data_->GetBufferLen(), data_->GetSampleRate(), data_->GetChannelNum());
		v8::Local<v8::Value> data_format = v8::String::NewFromUtf8(isolate, format_, v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 2;
		v8::Local<v8::Value> argv[2] = { uint8_array_data_buf, data_format };
		auto fn = v8::Local<v8::Function>::New(isolate, _onMixedAudioRawDataReceived);

		fn->Call(context, global, argc, argv);
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, unsigned int node_id_)
	{
		
		if (data_ && data_->CanAddRef())
		{
			data_->AddRef();

			class OneWayAudioRawDataTask : public IMainThreadTask
			{
			public:
				friend class AudioRawDataHelper;
				explicit OneWayAudioRawDataTask(AudioRawDataHelper* helper, AudioRawData* data, unsigned int node_id)
				{
					helper_ = helper;
					data_ = data;
					nodeID_ = node_id;
				}
				virtual ~OneWayAudioRawDataTask() {}
				virtual void Run()
				{
					if (helper_)
					{
						helper_->onOneWayAudioRawDataReceived_MainThread(data_, nodeID_);
					}
					if (data_)
					{
						data_->Release();
					}
					delete this;
				}
			private:
				AudioRawDataHelper* helper_;
				AudioRawData* data_;
				unsigned int nodeID_;
			};
			if (!PostTaskToMainThread(new OneWayAudioRawDataTask(this, data_, node_id_)))
				data_->Release();

		}
	}
	virtual void onOneWayAudioRawDataReceived_MainThread(AudioRawData* data_, unsigned int node_id)
	{
		if (_onOneWayAudioRawDataReceived.IsEmpty()
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

		//2 node_id
		v8::Local<v8::Value> nodeidname = v8::String::NewFromUtf8(isolate, "node_id", v8::NewStringType::kInternalized).ToLocalChecked();
		v8::Local<v8::Integer> nodeid = v8::Integer::New(isolate, (int32_t)node_id);

		//3.data format
		char format_[200] = { 0 };
		//type buffer_len sample_rate channel_num 
		sprintf(format_, "%s;%d;%d;%d;", "AudioRawData", data_->GetBufferLen(), data_->GetSampleRate(), data_->GetChannelNum());
		v8::Local<v8::Value> data_format = v8::String::NewFromUtf8(isolate, format_, v8::NewStringType::kInternalized).ToLocalChecked();

		int argc = 3;
		v8::Local<v8::Value> argv[3] = { uint8_array_data_buf, data_format, nodeid };
		auto fn = v8::Local<v8::Function>::New(isolate, _onOneWayAudioRawDataReceived);

		fn->Call(context, global, argc, argv);
	}


private:
	IAudioRawDataChannel*  _channel;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > _onMixedAudioRawDataReceived;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > _onOneWayAudioRawDataReceived;
};
AudioRawDataHelper g_audio_rawdata;

ZoomNodeAudioRawDataWrap::ZoomNodeAudioRawDataWrap()
{

}

ZoomNodeAudioRawDataWrap::~ZoomNodeAudioRawDataWrap()
{

}

void ZoomNodeAudioRawDataWrap::SetRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		|| !args[1]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc_mix = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb_mix(isolate, cbfunc_mix);
	g_audio_rawdata._onMixedAudioRawDataReceived = cb_mix;

	v8::Local<v8::Function> cbfunc_oneway = v8::Local<v8::Function>::Cast(args[1]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb_oneway(isolate, cbfunc_oneway);
	g_audio_rawdata._onOneWayAudioRawDataReceived = cb_oneway;

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)SDKRawDataError_SUCCESS);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAudioRawDataWrap::Start(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}
	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	if (NULL == g_audio_rawdata._channel)
		Node_RetrieveAudioRawDataChannel(&g_audio_rawdata._channel);
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	if (g_audio_rawdata._channel)
		err = g_audio_rawdata._channel->Start(RawDataMemoryMode_Heap, &g_audio_rawdata);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeAudioRawDataWrap::Stop(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (NULL == g_audio_rawdata._channel)
		Node_RetrieveAudioRawDataChannel(&g_audio_rawdata._channel);
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	if (g_audio_rawdata._channel)
		err = g_audio_rawdata._channel->Stop();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


