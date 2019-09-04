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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	if (args.Length() < 4) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZNWndPosition zn_position;
#if (defined _WIN32)
    zoom_v8toc(args[0].As<v8::String>(), zn_position.z_hSelfWnd);
    zoom_v8toc(args[1].As<v8::String>(), zn_position.z_hParent);
#else
    zoom_v8toc(args[0].As<v8::String>(), zn_position.z_height);
    zoom_v8toc(args[1].As<v8::String>(), zn_position.z_width);
#endif
	zoom_v8toc(args[2].As<v8::String>(), zn_position.z_left);
	zoom_v8toc(args[3].As<v8::String>(), zn_position.z_top);

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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
	if (args.Length() < 4) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString() ||
		!args[3]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZNWndPosition zn_position;
#if (defined _WIN32)
    zoom_v8toc(args[0].As<v8::String>(), zn_position.z_hSelfWnd);
    zoom_v8toc(args[1].As<v8::String>(), zn_position.z_hParent);
#else
    zoom_v8toc(args[0].As<v8::String>(), zn_position.z_height);
    zoom_v8toc(args[1].As<v8::String>(), zn_position.z_width);
#endif
	zoom_v8toc(args[2].As<v8::String>(), zn_position.z_left);
	zoom_v8toc(args[3].As<v8::String>(), zn_position.z_top);

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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsNumber())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
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
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}



