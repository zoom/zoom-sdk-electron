#include "zoom_node_rawdata_api_ctrl.h"
#include "zoom_node_rawdata_helper_mgr_class.h"

extern ZoomNodePipeServerMgr _g_video_pipe_server;
extern ZoomNodePipeServerMgr _g_share_pipe_server;
extern ZoomNodePipeServerMgr _g_audio_pipe_server;

ZoomNodeRawApiCtrlWrap::ZoomNodeRawApiCtrlWrap()
{
	
}

ZoomNodeRawApiCtrlWrap::~ZoomNodeRawApiCtrlWrap()
{

}
void ZoomNodeRawApiCtrlWrap::HasRawDataLicense(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bHas = _g_native_wrap.GetRawAPIWrap().HasRawDataLicense();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bHas);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::InitAudioRawDataHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().InitAudioRawDataHelper();

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::GetRawdataVideoSourceHelper(const v8::FunctionCallbackInfo<v8::Value>& args)
{

}
void ZoomNodeRawApiCtrlWrap::CreateRenderer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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

	unsigned long long zn_recv_handle = (unsigned long long)args[0]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().CreateRenderer(zn_recv_handle);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::DestroyRenderer(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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
	//
	unsigned long long zn_recv_handle = (unsigned long long)args[0]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().DestroyRenderer(zn_recv_handle);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber() ||
		!args[2]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	uint32_t zn_userid = (uint32_t)args[0]->NumberValue(context).FromJust();
	ZNZoomSDKRawDataType zn_rawdataType = (ZNZoomSDKRawDataType)args[1]->NumberValue(context).FromJust();
	unsigned long long zn_recv_handle = (unsigned long long)args[2]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().Subscribe(zn_userid, zn_rawdataType, zn_recv_handle);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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

	unsigned long long zn_recv_handle = (unsigned long long)args[0]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().UnSubscribe(zn_recv_handle);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::SetRawDataResolution(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNZoomSDKResolution zn_resolution = (ZNZoomSDKResolution)args[0]->NumberValue(context).FromJust();
	unsigned long long zn_recv_handle = (unsigned long long)args[1]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().SetRawDataResolution(zn_resolution, zn_recv_handle);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::GetResolution(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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
	ZNZoomSDKResolution zn_resolution = ZNZoomSDKResolution_NoUse;
	unsigned long long zn_recv_handle = (unsigned long long)args[0]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().GetResolution(zn_resolution, zn_recv_handle);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "resolution", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_resolution));

	args.GetReturnValue().Set(node);
}
void ZoomNodeRawApiCtrlWrap::GetRawDataType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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
	ZNZoomSDKRawDataType zn_rawdataType = ZNRAW_DATA_TYPE_VIDEO;
	unsigned long long zn_recv_handle = (unsigned long long)args[0]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().GetRawDataType(zn_rawdataType, zn_recv_handle);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "rawdataType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)zn_rawdataType));

	args.GetReturnValue().Set(node);
}
void ZoomNodeRawApiCtrlWrap::GetUserId(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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
	uint32_t zn_userid = 0;
	unsigned long long zn_recv_handle = (unsigned long long)args[0]->NumberValue(context).FromJust();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().GetUserId(zn_userid, zn_recv_handle);

	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "userid", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, zn_userid));

	args.GetReturnValue().Set(node);
}
void ZoomNodeRawApiCtrlWrap::SetonRawDataStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())
	{
		ZoomNodeSinkHelper::GetInst().onRawDataStatusChanged.Empty();
		return;
	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onRawDataStatusChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeRawApiCtrlWrap::SubscribeAudioRawdata(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().SubscribeAudioRawdata();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::UnSubscribeAudioRawdata(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetRawAPIWrap().UnSubscribeAudioRawdata();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeRawApiCtrlWrap::StartPipeServe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	bool bsucc_video_pipe = false;
	bsucc_video_pipe = _g_video_pipe_server._uv_ipc_server.StartPipeServer(VIDEO_PIPE_NAME, &_g_video_pipe_server);
	bool bsucc_share_pipe = false;
	bsucc_share_pipe = _g_share_pipe_server._uv_ipc_server.StartPipeServer(SHARE_PIPE_NAME, &_g_share_pipe_server);
	bool bsucc_audio_pipe = false;
	bsucc_audio_pipe = _g_audio_pipe_server._uv_ipc_server.StartPipeServer(AUDIO_PIPE_NAME, &_g_audio_pipe_server);
	if (!bsucc_video_pipe || !bsucc_share_pipe || !bsucc_audio_pipe)
	{
		err = ZNSDKERR_INTELNAL_ERROR;
	}
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeRawApiCtrlWrap::StopPipeServe(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	bool bsucc_video_pipe = false;
	bsucc_video_pipe = _g_video_pipe_server._uv_ipc_server.StopPipeServer();
	bool bsucc_share_pipe = false;
	bsucc_share_pipe = _g_share_pipe_server._uv_ipc_server.StopPipeServer();
	bool bsucc_audio_pipe = false;
	bsucc_audio_pipe = _g_audio_pipe_server._uv_ipc_server.StopPipeServer();
	if (!bsucc_video_pipe || !bsucc_share_pipe || !bsucc_audio_pipe)
	{
		err = ZNSDKERR_INTELNAL_ERROR;
	}
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}