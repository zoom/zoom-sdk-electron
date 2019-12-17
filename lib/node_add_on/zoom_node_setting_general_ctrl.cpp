#include "zoom_node_setting_general_ctrl.h"


ZoomNodeSettingGeneralCtrlWrap::ZoomNodeSettingGeneralCtrlWrap()
{

}

ZoomNodeSettingGeneralCtrlWrap::~ZoomNodeSettingGeneralCtrlWrap()
{

}
void ZoomNodeSettingGeneralCtrlWrap::EnableDualScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableDualScreenMode(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::TurnOffAeroModeInSharing(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().TurnOffAeroModeInSharing(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableAutoFitToWindowWhenViewSharing(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableAutoFitToWindowWhenViewSharing(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableAutoFullScreenVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableAutoFullScreenVideoWhenJoinMeeting(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableSplitScreenMode(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsDualScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsDualScreenModeEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsAeroModeInSharingTurnOff(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsAeroModeInSharingTurnOff();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsAutoFitToWindowWhenViewSharingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsAutoFitToWindowWhenViewSharingEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsAutoFullScreenVideoWhenJoinMeetingEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsSplitScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bDisable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsSplitScreenModeEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bDisable);
	args.GetReturnValue().Set(bret);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZoomNodeSettingGeneralCtrlWrap::EnableAutoFullScreenVideoWhenViewShare(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableAutoFullScreenVideoWhenViewShare(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsAutoFullScreenVideoWhenViewShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsAutoFullScreenVideoWhenViewShareEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableDisplayReminderWindowWhenExit(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableDisplayReminderWindowWhenExit(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsDisplayReminderWindowWhenExitEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsDisplayReminderWindowWhenExitEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableShowMyMeetingElapseTime(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableShowMyMeetingElapseTime(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsShowMyMeetingElapseTimeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsShowMyMeetingElapseTimeEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsCurrentOSSupportAccelerateGPUWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsCurrentOSSupportAccelerateGPUWhenShare();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnable);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableAccelerateGPUWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableAccelerateGPUWhenShare(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsAccelerateGPUWhenShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
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

	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsAccelerateGPUWhenShareEnabled(zn_bEnable);
	v8::HandleScope scope(isolate);
	v8::Local<v8::Object> node = v8::Object::New(isolate);
	node->Set(context, v8::String::NewFromUtf8(isolate, "err", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)err));
	node->Set(context, v8::String::NewFromUtf8(isolate, "bEnable", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Boolean::New(isolate, zn_bEnable));

	args.GetReturnValue().Set(node);
}
void ZoomNodeSettingGeneralCtrlWrap::EnableRemoteControlAllApplications(const v8::FunctionCallbackInfo<v8::Value>& args)
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


	ZNSDKError err = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().EnableRemoteControlAllApplications(zn_bEnable);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSettingGeneralCtrlWrap::IsRemoteControlAllApplicationsEnabled(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bEnable = _g_native_wrap.GetSettingServiceWrap().GetSettingGeneralCtrl().IsRemoteControlAllApplicationsEnabled();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bEnable);
	args.GetReturnValue().Set(bret);
}
