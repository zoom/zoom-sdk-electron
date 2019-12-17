#include "zoom_node_setting_video_ctrl.h"

ZoomNodeSettingVideoCtrlWrap::ZoomNodeSettingVideoCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_videoSettingContextWrapSink);
}

ZoomNodeSettingVideoCtrlWrap::~ZoomNodeSettingVideoCtrlWrap()
{
	_g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SetSink(NULL);
}
void ZoomNodeSettingVideoCtrlWrap::SelectVideoCamera(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZoomSTRING zn_deviceId;
	zoom_v8toc(args[0].As<v8::String>(), zn_deviceId);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().SelectCamera(zn_deviceId);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsMirrorEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsVideoMirrorEffectEnable();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNList<ZNCameraInfo> zn_cameraInfoLst = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().GetCameraList();

	v8::HandleScope scope(isolate);
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_cameraInfoLst.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "deviceId", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_cameraInfoLst[i].deviceId).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "deviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_cameraInfoLst[i].deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(isolate->GetCurrentContext(), v8::String::NewFromUtf8(isolate, "isSelected", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_cameraInfoLst[i].isSelectedDevice));
		nodes->Set(isolate->GetCurrentContext(), i, node);
	}

	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSettingVideoCtrlWrap::EnableVideoMirrorEffect(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableVideoMirrorEffect(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableFaceBeautyEffect(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableFaceBeautyEffect(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsFaceBeautyEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsFaceBeautyEffectEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZoomNodeSettingVideoCtrlWrap::SetComputerCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onComputerCamDeviceChanged.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onComputerCamDeviceChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::SetDefaultCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onDefaultCamDeviceChanged.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onDefaultCamDeviceChanged = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableHDVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableHDVideo(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsHDVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsHDVideoEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableAlwaysShowNameOnVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableAlwaysShowNameOnVideo(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsAlwaysShowNameOnVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsAlwaysShowNameOnVideoEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableAutoTurnOffVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableAutoTurnOffVideoWhenJoinMeeting(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsAutoTurnOffVideoWhenJoinMeetingEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableAlwaysUse16v9(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableAlwaysUse16v9(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsAlwaysUse16v9(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsAlwaysUse16v9();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableSpotlightSelf(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableSpotlightSelf(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsSpotlightSelfEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsSpotlightSelfEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableHardwareEncode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableHardwareEncode(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsHardwareEncodeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsHardwareEncodeEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::Enable49VideoesInGallaryView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().Enable49VideoesInGallaryView(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::Is49VideoesInGallaryViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().Is49VideoesInGallaryViewEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::EnableHideNoVideoUsersOnWallView(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().EnableHideNoVideoUsersOnWallView(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingVideoCtrlWrap::IsHideNoVideoUsersOnWallViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool isEnabled = _g_native_wrap.GetSettingServiceWrap().GetSettingVideoCtrl().IsHideNoVideoUsersOnWallViewEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, isEnabled);
	args.GetReturnValue().Set(bret);
}

