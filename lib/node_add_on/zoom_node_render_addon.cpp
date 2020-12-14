
#include "zoom_node_render_addon.h"
#include "zoom_v8_to_c.h"

#include "uv_ipc_common.h"
#include "raw_data_format.h"
#include <iostream>
#include <string>

static void CreateRenderNodeObject(const v8::FunctionCallbackInfo<v8::Value>& args) {

	RenderAddonData* data =
		reinterpret_cast<RenderAddonData*>(args.Data().As<v8::External>()->Value());
	data->zoomNodeWrapInstance = ZoomNodeRenderWrap::GetNewInstance(args);
	args.GetReturnValue().Set(data->zoomNodeWrapInstance);
}


NODE_MODULE_INIT(/* exports, module, context */) {
	v8::Isolate* isolate = context->GetIsolate();

	ZoomNodeRenderWrap::Init(exports->GetIsolate());
	ZoomNodeVideoRawDataLibuvClientWrap::Init(exports->GetIsolate());
	ZoomNodeShareRawDataLibuvClientWrap::Init(exports->GetIsolate());
	ZoomNodeAudioRawDataLibuvClientWrap::Init(exports->GetIsolate());

	RenderAddonData* data = new RenderAddonData(isolate);

	v8::Local<v8::External> external = v8::External::New(isolate, data);

	exports->Set(context,
		v8::String::NewFromUtf8(isolate, "exports", v8::NewStringType::kNormal)
		.ToLocalChecked(),
		v8::FunctionTemplate::New(isolate, CreateRenderNodeObject, external)
		->GetFunction(context).ToLocalChecked()).FromJust();
}

v8::Persistent<v8::Function> ZoomNodeRenderWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeVideoRawDataLibuvClientWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeShareRawDataLibuvClientWrap::constructor;
v8::Persistent<v8::Function> ZoomNodeAudioRawDataLibuvClientWrap::constructor;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void ZoomNodeRenderWrap::GetVideoLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeVideoRawDataLibuvClientWrap::NewInstance(args);
}
void ZoomNodeRenderWrap::GetShareLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeShareRawDataLibuvClientWrap::NewInstance(args);
}
void ZoomNodeRenderWrap::GetAudioLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args) {
	ZoomNodeAudioRawDataLibuvClientWrap::NewInstance(args);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > g_cb_onRenderVideoRawDataReceived;
v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > g_cb_onRenderShareRawDataReceived;
v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > g_cb_onMixedAudioRawDataReceived;
v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > g_cb_onOneWayAudioRawDataReceived;

void SendPingPongMsg(int type, unsigned int source_id);
void RunVideoFormatDataCB(char* msg_buf, int type)
{
	if ((TYPE_VIDEO != type && TYPE_SHARE != type) || NULL == msg_buf)
	{
		return;
	}
	if (TYPE_VIDEO == type && g_cb_onRenderVideoRawDataReceived.IsEmpty())
	{
		return;
	}
	if (TYPE_SHARE == type && g_cb_onRenderShareRawDataReceived.IsEmpty())
	{
		return;
	}

	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();

	VideoRawDataHeader& header = *(VideoRawDataHeader*)msg_buf;
	char format_[200] = { 0 };
	//type islimit width height rotation yoffset uoffset voffset
	sprintf(format_, "%s;%d;%d;%d;%d;%llu;%llu;%llu", "yuvi420", header.isLimitedI420,
		header.width, header.height, header.rotation, header.y_offset, header.u_offset, header.v_offset);
	v8::Local<v8::Value> data_format = v8::String::NewFromUtf8(isolate, format_, v8::NewStringType::kInternalized).ToLocalChecked();

	char* data_buf_ptr = msg_buf + sizeof(VideoRawDataHeader);

	v8::Local<v8::Integer > uint64_recv_handle = v8::Integer::New(isolate, (uint64_t)header.recvHandle);

	auto array_data_buf = v8::ArrayBuffer::New(isolate, data_buf_ptr, header.dataBufferLen, v8::ArrayBufferCreationMode::kExternalized);
	v8::Local<v8::Uint8Array> uint8_array_data_buf = v8::Uint8Array::New(array_data_buf, 0, header.dataBufferLen);

	int argc = 3;
	v8::Local<v8::Value> argv[3] = { data_format, uint64_recv_handle, uint8_array_data_buf };
	switch (type)
	{
	case TYPE_VIDEO:
	{
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onRenderVideoRawDataReceived);
		fn->Call(context, global, argc, argv);
		SendPingPongMsg(TYPE_VIDEO, header.source_id);
	}
	break;
	case TYPE_SHARE:
	{
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onRenderShareRawDataReceived);
		fn->Call(context, global, argc, argv);
		SendPingPongMsg(TYPE_SHARE, header.source_id);
	}
	break;
	default:
		break;
	}
}

void RunAudioFormatDataCB(char* msg_buf)
{
	if ((g_cb_onMixedAudioRawDataReceived.IsEmpty() && g_cb_onOneWayAudioRawDataReceived.IsEmpty())
		|| NULL == msg_buf)
	{
		return;
	}
	auto isolate = v8::Isolate::GetCurrent();
	v8::HandleScope scope(isolate);
	auto context = isolate->GetCurrentContext();
	auto global = context->Global();
	AudioRawDataHeader& header = *(AudioRawDataHeader*)msg_buf;
	if (0 == header.node_id && g_cb_onMixedAudioRawDataReceived.IsEmpty())
		return;
	if (0 != header.node_id && g_cb_onOneWayAudioRawDataReceived.IsEmpty())
		return;
	char format_[200] = { 0 };
	//type buffer_len sample_rate channel_num 
	sprintf(format_, "%s;%d;%d;%d;", "AudioRawData", header.dataBufferLen, header.sampleRate, header.channelNum);
	v8::Local<v8::Value> data_format = v8::String::NewFromUtf8(isolate, format_, v8::NewStringType::kInternalized).ToLocalChecked();

	//node id
	v8::Local<v8::Value> nodeidname = v8::String::NewFromUtf8(isolate, "node_id", v8::NewStringType::kInternalized).ToLocalChecked();
	v8::Local<v8::Integer> nodeid = v8::Integer::New(isolate, (int32_t)header.node_id);

	//buffer
	char* audio_data_buf_ptr = msg_buf + sizeof(AudioRawDataHeader);
	auto array_data_buf = v8::ArrayBuffer::New(isolate, audio_data_buf_ptr, header.dataBufferLen, v8::ArrayBufferCreationMode::kExternalized);
	v8::Local<v8::Uint8Array> uint8_array_data_buf = v8::Uint8Array::New(array_data_buf, 0, header.dataBufferLen);
	if (0 == header.node_id)
	{
		int argc = 2;
		v8::Local<v8::Value> argv[2] = { uint8_array_data_buf, data_format };
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onMixedAudioRawDataReceived);
		fn->Call(context, global, argc, argv);
	}
	else
	{
		int argc = 3;
		v8::Local<v8::Value> argv[3] = { uint8_array_data_buf, data_format, nodeid };
		auto fn = v8::Local<v8::Function>::New(isolate, g_cb_onOneWayAudioRawDataReceived);
		fn->Call(context, global, argc, argv);
	}
}
class UVIPCClientSink : public UVIPCSink
{
public:
	friend class ZoomNodeVideoRawDataLibuvClientWrap;
	UVIPCClientSink()
	{
		
	}
	~UVIPCClientSink()
	{
		
	}
	virtual void onMessageRecvNotification(UVIPCMessage* msg)
	{
		char* msg_buf = msg->GetBuf();
		if (NULL == msg_buf)
			return;

		RawDataCommonHeader common_header;
		memcpy(&common_header, msg_buf, sizeof(RawDataCommonHeader));
		switch (common_header.type)
		{
		case TYPE_VIDEO:
		case TYPE_SHARE:
			RunVideoFormatDataCB(msg_buf, common_header.type);
			break;
		case TYPE_AUDIO:
			RunAudioFormatDataCB(msg_buf);
			break;
		default:
			break;
		}
	}
	virtual void onConnect()
	{
	}
	virtual void onDisconnect()
	{
	}
	virtual void onIdle()
	{
		
	}

public:
	uv_loop_t* _uv_loop;
	UVIPC _uv_ipc_client;
};
UVIPCClientSink g_ipcSinkClientVideo;
UVIPCClientSink g_ipcSinkClientShare;
UVIPCClientSink g_ipcSinkClientAudio;

void SendPingPongMsg(int type, unsigned int source_id)
{
	switch (type)
	{
	case TYPE_VIDEO:
	{
		UVIPCMessage* msg = new UVIPCMessage((const char*)&source_id, sizeof(unsigned int));
		g_ipcSinkClientVideo._uv_ipc_client.SendMessage(msg);
	}
	break;
	case TYPE_SHARE:
	{
		UVIPCMessage* msg = new UVIPCMessage((const char*)&source_id, sizeof(unsigned int));
		g_ipcSinkClientShare._uv_ipc_client.SendMessage(msg);
	}
	break;
	default:
		break;
	}
}
void ZoomNodeVideoRawDataLibuvClientWrap::SetRenderVideoRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			g_cb_onRenderVideoRawDataReceived.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		g_cb_onRenderVideoRawDataReceived = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeVideoRawDataLibuvClientWrap::StartVideoClient(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;

	g_ipcSinkClientVideo._uv_loop = uv_default_loop();

	err = g_ipcSinkClientVideo._uv_ipc_client.Start(VIDEO_PIPE_NAME, false, g_ipcSinkClientVideo._uv_loop, &g_ipcSinkClientVideo);
	
	uv_run(g_ipcSinkClientVideo._uv_loop, UV_RUN_NOWAIT);

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeVideoRawDataLibuvClientWrap::StopVideoClient(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = g_ipcSinkClientVideo._uv_ipc_client.Stop();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeShareRawDataLibuvClientWrap::SetRenderShareRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			g_cb_onRenderShareRawDataReceived.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		g_cb_onRenderShareRawDataReceived = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeShareRawDataLibuvClientWrap::StartShareClient(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    bool err = false;
    
    g_ipcSinkClientShare._uv_loop = uv_default_loop();

    err = g_ipcSinkClientShare._uv_ipc_client.Start(SHARE_PIPE_NAME, false, g_ipcSinkClientShare._uv_loop, &g_ipcSinkClientShare);
    uv_run(g_ipcSinkClientShare._uv_loop, UV_RUN_NOWAIT);
    
    v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
    args.GetReturnValue().Set(bret);
}
void ZoomNodeShareRawDataLibuvClientWrap::StopShareClient(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = g_ipcSinkClientShare._uv_ipc_client.Stop();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeAudioRawDataLibuvClientWrap::SetRenderAudioRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 2) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		bool wrongArguments = false;
		if (args[0]->IsNull())
		{
			g_cb_onMixedAudioRawDataReceived.Empty();
		}
		else
		{
			if (!args[0]->IsFunction())
				wrongArguments = true;
			else
			{
				v8::Local<v8::Function> cbfunc_mix = v8::Local<v8::Function>::Cast(args[0]);
				v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb_mix(isolate, cbfunc_mix);
				g_cb_onMixedAudioRawDataReceived = cb_mix;
			}
		}
		if (args[1]->IsNull())
		{
			g_cb_onOneWayAudioRawDataReceived.Empty();
		}
		else
		{
			if (!args[1]->IsFunction())
				wrongArguments = true;
			else
			{
				v8::Local<v8::Function> cbfunc_oneway = v8::Local<v8::Function>::Cast(args[1]);
				v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb_oneway(isolate, cbfunc_oneway);
				g_cb_onOneWayAudioRawDataReceived = cb_oneway;
			}
		}
		if (wrongArguments)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeAudioRawDataLibuvClientWrap::StartAudioClient(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;

	g_ipcSinkClientAudio._uv_loop = uv_default_loop();

	err = g_ipcSinkClientAudio._uv_ipc_client.Start(AUDIO_PIPE_NAME, false, g_ipcSinkClientAudio._uv_loop, &g_ipcSinkClientAudio);
	uv_run(g_ipcSinkClientAudio._uv_loop, UV_RUN_NOWAIT);

	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeAudioRawDataLibuvClientWrap::StopAudioClient(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	err = g_ipcSinkClientAudio._uv_ipc_client.Stop();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
