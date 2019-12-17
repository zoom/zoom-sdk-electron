#include "zoom_node_meeting_config_ctrl.h"


ZoomNodeMeetingConfigCtrlWrap::ZoomNodeMeetingConfigCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingConfigWrapFreeMeetingSink);
}

ZoomNodeMeetingConfigCtrlWrap::~ZoomNodeMeetingConfigCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetSink(NULL);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableInviteButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableInviteButtonOnMeetingUI(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoPos(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
#if (defined _WIN32)
	if (args.Length() < 4) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
#else
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
#endif
	

	ZNWndPosition zn_position;
	zoom_v8toc(args[0].As<v8::String>(), zn_position.z_left);
	zoom_v8toc(args[1].As<v8::String>(), zn_position.z_top);
#if (defined _WIN32)
	zoom_v8toc(args[2].As<v8::String>(), zn_position.z_hSelfWnd);
	zoom_v8toc(args[3].As<v8::String>(), zn_position.z_hParent);
#endif
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetFloatVideoPos(zn_position);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetBottomFloatToolbarWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetBottomFloatToolbarWndVisibility(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetSharingToolbarVisibility(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetSharingToolbarVisibility(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetDirectShareMonitorID(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_monitorID;
	zoom_v8toc(args[0].As<v8::String>(), zn_monitorID);
	
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetDirectShareMonitorID(zn_monitorID);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetMeetingUIPos(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
#if (defined _WIN32)
	if (args.Length() < 4) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
#else
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
#endif

	ZNWndPosition zn_position;
	zoom_v8toc(args[0].As<v8::String>(), zn_position.z_left);
	zoom_v8toc(args[1].As<v8::String>(), zn_position.z_top);
#if (defined _WIN32)
	zoom_v8toc(args[2].As<v8::String>(), zn_position.z_hSelfWnd);
	zoom_v8toc(args[3].As<v8::String>(), zn_position.z_hParent);
#endif
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetMeetingUIPos(zn_position);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::DisableWaitingForHostDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableWaitingForHostDialog(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::HideMeetingInfoFromMeetingUITitle(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideMeetingInfoFromMeetingUITitle(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetMeetingIDForMeetingUITitle(const v8::FunctionCallbackInfo<v8::Value>& args)
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

	unsigned long long  zn_meetingNumber;
	zn_meetingNumber = (unsigned long long)args[0]->NumberValue();
	
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetMeetingIDForMeetingUITitle(zn_meetingNumber);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::DisablePopupMeetingWrongPSWDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisablePopupMeetingWrongPSWDlg(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAutoEndOtherMeetingWhenStartMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoEndOtherMeetingWhenStartMeeting(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableLButtonDBClick4SwitchFullScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLButtonDBClick4SwitchFullScreenMode(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetFloatVideoWndVisibility(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::PrePopulateWebinarRegistrationInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_email;
	zoom_v8toc(args[0].As<v8::String>(), zn_email);
	ZoomSTRING zn_userName;
	zoom_v8toc(args[1].As<v8::String>(), zn_userName);

	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().PrePopulateWebinarRegistrationInfo(zn_email,zn_userName);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::Reset(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().Reset();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAutoAdjustSpeakerVolumeWhenJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoAdjustSpeakerVolumeWhenJoinAudio(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAutoAdjustMicVolumeWhenJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoAdjustMicVolumeWhenJoinAudio(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::ConfigDSCP(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsNumber() ||
		!args[2]->IsBoolean()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	int zn_dscpAudio = (int)args[0].As<v8::Integer>()->Value();
	int zn_dscpVideo = (int)args[1].As<v8::Integer>()->Value();
	bool zn_bReset = false;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bReset);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().ConfigDSCP(zn_dscpAudio, zn_dscpVideo, zn_bReset);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableHideFullPhoneNumber4PureCallinUser(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = false;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableHideFullPhoneNumber4PureCallinUser(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableLengthLimitationOfMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = false;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
#if (defined _WIN32)
	ZNSDKError err = ZNSDKERR_SUCCESS;
#else
	ZNSDKError err = ZNSDKERR_NO_IMPL;
#endif 
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLengthLimitationOfMeetingNumber(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableShareIOSDevice(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = false;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
#if (defined _WIN32)
	ZNSDKError err = ZNSDKERR_SUCCESS;
#else
	ZNSDKError err = ZNSDKERR_NO_IMPL;
#endif 
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableShareIOSDevice(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableShareWhiteBoard(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
#if (defined _WIN32)
	ZNSDKError err = ZNSDKERR_SUCCESS;
#else
	ZNSDKError err = ZNSDKERR_NO_IMPL;
#endif 
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableShareWhiteBoard(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::ForceDisableMultiShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = false;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().ForceDisableMultiShare(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableLocalRecordingConvertProgressBarDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLocalRecordingConvertProgressBarDialog(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetMaxDurationForOnlyHostInMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
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

	int zn_nDuration = (int)args[0].As<v8::Integer>()->Value();
#if (defined _WIN32)
	ZNSDKError err = ZNSDKERR_SUCCESS;
#else
	ZNSDKError err = ZNSDKERR_NO_IMPL;
#endif 
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetMaxDurationForOnlyHostInMeeting(zn_nDuration);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::GetReminderType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNFreeMeetingEndingReminderType zn_type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetReminderType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)zn_type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::UpgradeMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().UpgradeMeeting();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::UpgradeAccount(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().UpgradeAccount();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::CancelUpdate(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().CancelUpdate();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingNeedToUpgradeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStartCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStopCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToProMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


void ZoomNodeMeetingConfigCtrlWrap::EnableApproveRemoteControlDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	
	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableApproveRemoteControlDlg(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableDeclineRemoteControlResponseDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableDeclineRemoteControlResponseDlg(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableLeaveMeetingOptionForHost(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableLeaveMeetingOptionForHost(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableVideoButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableVideoButtonOnMeetingUI(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableAudioButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAudioButtonOnMeetingUI(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableEnterAndExitFullScreenButtonOnMeetingUI(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickShareBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickShareBTNEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickEndMeetingBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickEndMeetingBTNEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectFreeMeetingEndingReminderDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectFreeMeetingEndingReminderDlg(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickCustomLiveStreamMenuEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickCustomLiveStreamMenuEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickParticipantListBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickParticipantListBTNEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectClickCCBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickCCBTNEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickAudioBTNEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioMenuBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectClickAudioMenuBTNEvent(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectMeetingWarningMsg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean() || !args[1]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNZoomRedirectWarningMsgOption zn_RedirectOption;
	bool zn_bRedirect = false; 
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);	
	zn_RedirectOption.bRedirectBadNetwork = zn_bRedirect;
	zoom_v8toc(args[1].As<v8::Boolean>(), zn_bRedirect);
	zn_RedirectOption.bRedirectWarnHighCPU = zn_bRedirect;
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectMeetingWarningMsg(zn_RedirectOption);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableToolTipsShow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableToolTipsShow(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableAirplayInstructionWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAirplayInstructionWindow(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableClaimHostFeature(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableClaimHostFeature(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableAutoHideJoinAudioDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableAutoHideJoinAudioDialog(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::AlwaysShowIconOnTaskBar(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bAlwaysShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bAlwaysShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().AlwaysShowIconOnTaskBar(zn_bAlwaysShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableSplitScreenModeUIElements(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableSplitScreenModeUIElements(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowAudioUseComputerSoundChkbox(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowAudioUseComputerSoundChkbox(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowCallInTab(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowCallInTab(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowCallMeTab(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowCallMeTab(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetAlwaysShowMeetingIDOnTitle(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bAlwaysShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bAlwaysShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetAlwaysShowMeetingIDOnTitle(zn_bAlwaysShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableTopMostAttr4SettingDialog(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableTopMostAttr4SettingDialog(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableGrabShareWithoutReminder(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableGrabShareWithoutReminder(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableShowShareSwitchMultiToSingleConfirmDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableShowShareSwitchMultiToSingleConfirmDlg(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableFreeMeetingRemainTimeNotify(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableFreeMeetingRemainTimeNotify(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideChatItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideChatItemOnMeetingUI(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideRecordItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideRecordItemOnMeetingUI(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideUpgradeFreeMeetingButton(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideUpgradeFreeMeetingButton(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowInviteDlgTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() || !args[1]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNSDKInviteDlgTabPage  zn_TabPage;
	zn_TabPage = (ZNSDKInviteDlgTabPage)(unsigned int)args[0]->NumberValue();
	bool zn_bShow = true;
	zoom_v8toc(args[1].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowInviteDlgTabPage(zn_TabPage, zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::SetShowH323SubTabPage(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() || !args[1]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZNSDKH323TabPage  zn_TabPage;
	zn_TabPage = (ZNSDKH323TabPage)(unsigned int)args[0]->NumberValue();
	bool zn_bShow = true;
	zoom_v8toc(args[1].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowH323SubTabPage(zn_TabPage, zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideUpgradeWarningMsgForFreeUserWhenSchedule(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideUpgradeWarningMsgForFreeUserWhenSchedule(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideSwitchCameraButton(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideSwitchCameraButton(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideCopyUrlOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideCopyUrlOnInviteWindow(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideCopyInvitationOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideCopyInvitationOnInviteWindow(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideKeypadButtonOnMeetingWindow(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideKeypadButtonOnMeetingWindow(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideRemoteControlOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideRemoteControlOnMeetingUI(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HideQAOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HideQAOnMeetingUI(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::HidePollOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bHide = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bHide);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().HidePollOnMeetingUI(zn_bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingPasswordDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableInputMeetingPasswordDlg(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingScreenNameDlg(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableInputMeetingScreenNameDlg(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectWebinarNeedRegister(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectWebinarNeedRegister(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::RedirectEndOtherMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bRedirect = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bRedirect);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().RedirectEndOtherMeeting(zn_bRedirect);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStartMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableForceAutoStartMyVideoWhenJoinMeeting(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStopMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bEnable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bEnable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().EnableForceAutoStopMyVideoWhenJoinMeeting(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableShowJoinMeetingWnd(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableShowJoinMeetingWnd(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

void ZoomNodeMeetingConfigCtrlWrap::DisableRemoteCtrlCopyPasteFeature(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bDisable = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bDisable);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().DisableRemoteCtrlCopyPasteFeature(zn_bDisable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetShowVideoOptimizeChkbox(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_bShow = true;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_bShow);
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().SetShowVideoOptimizeChkbox(zn_bShow);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::GetRequiredInfoType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNRequiredInfoType zn_type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetRequiredInfoType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)zn_type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputMeetingPasswordAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_meetingPassword;
	zoom_v8toc(args[0].As<v8::String>(), zn_meetingPassword);
	ZoomSTRING zn_screenName;
	zoom_v8toc(args[1].As<v8::String>(), zn_screenName);

	bool err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputMeetingPasswordAndScreenName(zn_meetingPassword, zn_screenName);
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputMeetingIDAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_meetingID;
	zoom_v8toc(args[0].As<v8::String>(), zn_meetingID);
	ZoomSTRING zn_screenName;
	zoom_v8toc(args[1].As<v8::String>(), zn_screenName);

	bool err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputMeetingIDAndScreenName(zn_meetingID, zn_screenName);
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputMeetingScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_screenName;
	zoom_v8toc(args[0].As<v8::String>(), zn_screenName);


	bool err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputMeetingScreenName(zn_screenName);
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::MeetingPasswordAndScreenNameHandler_Cancel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().MeetingPasswordAndScreenNameHandler_Cancel();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::GetWebinarNeedRegisterType(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNWebinarNeedRegisterType zn_type = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetWebinarNeedRegisterType();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)zn_type);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::GetWebinarRegisterUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING webinarRegisterUrl = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().GetWebinarRegisterUrl();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(webinarRegisterUrl).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::ReleaseRegisterWebinarByUrl(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().ReleaseRegisterWebinarByUrl();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::InputWebinarRegisterEmailAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_email;
	zoom_v8toc(args[0].As<v8::String>(), zn_email);
	ZoomSTRING zn_screenName;
	zoom_v8toc(args[1].As<v8::String>(), zn_screenName);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().InputWebinarRegisterEmailAndScreenName(zn_email, zn_screenName);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::CancelRegisterWebinarByEmail(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().CancelRegisterWebinarByEmail();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetInputMeetingPasswordAndScreenNameNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onInputMeetingPasswordAndScreenNameNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onInputMeetingPasswordAndScreenNameNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetAirPlayInstructionWndNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onAirPlayInstructionWndNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onAirPlayInstructionWndNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonWebinarNeedRegisterNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onWebinarNeedRegisterNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onWebinarNeedRegisterNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonEndOtherMeetingToJoinMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onEndOtherMeetingToJoinMeetingNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onEndOtherMeetingToJoinMeetingNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTime.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTime = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeStopCountDownCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTimeStopCountDown.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingRemainTimeStopCountDown = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}


