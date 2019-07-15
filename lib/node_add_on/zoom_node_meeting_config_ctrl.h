#ifndef _ZOOM_NODE_MEETING_CONFIG_CTRL_H_
#define _ZOOM_NODE_MEETING_CONFIG_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingConfigCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingConfigCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingConfigCtrlWrap >;
private:
	ZoomNodeMeetingConfigCtrlWrap();
	~ZoomNodeMeetingConfigCtrlWrap();
public:
	static void EnableInviteButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetFloatVideoPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetBottomFloatToolbarWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetSharingToolbarVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetDirectShareMonitorID(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingUIPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableWaitingForHostDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideMeetingInfoFromMeetingUITitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingIDForMeetingUITitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisablePopupMeetingWrongPSWDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAutoEndOtherMeetingWhenStartMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableLButtonDBClick4SwitchFullScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetFloatVideoWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void PrePopulateWebinarRegistrationInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetReminderType(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UpgradeMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UpgradeAccount(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CancelUpdate(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SetFreeMeetingNeedToUpgradeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetFreeMeetingUpgradeToGiftFreeTrialStartCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetFreeMeetingUpgradeToGiftFreeTrialStopCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetFreeMeetingUpgradeToProMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingConfigCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingConfigCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInviteButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableInviteButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFloatVideoPos", ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetBottomFloatToolbarWndVisibility", ZoomNodeMeetingConfigCtrlWrap::SetBottomFloatToolbarWndVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSharingToolbarVisibility", ZoomNodeMeetingConfigCtrlWrap::SetSharingToolbarVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDirectShareMonitorID", ZoomNodeMeetingConfigCtrlWrap::SetDirectShareMonitorID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUIPos", ZoomNodeMeetingConfigCtrlWrap::SetMeetingUIPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableWaitingForHostDialog", ZoomNodeMeetingConfigCtrlWrap::DisableWaitingForHostDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideMeetingInfoFromMeetingUITitle", ZoomNodeMeetingConfigCtrlWrap::HideMeetingInfoFromMeetingUITitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingIDForMeetingUITitle", ZoomNodeMeetingConfigCtrlWrap::SetMeetingIDForMeetingUITitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisablePopupMeetingWrongPSWDlg", ZoomNodeMeetingConfigCtrlWrap::DisablePopupMeetingWrongPSWDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoEndOtherMeetingWhenStartMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableAutoEndOtherMeetingWhenStartMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLButtonDBClick4SwitchFullScreenMode", ZoomNodeMeetingConfigCtrlWrap::EnableLButtonDBClick4SwitchFullScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFloatVideoWndVisibility", ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoWndVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PrePopulateWebinarRegistrationInfo", ZoomNodeMeetingConfigCtrlWrap::PrePopulateWebinarRegistrationInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetReminderType", ZoomNodeMeetingConfigCtrlWrap::GetReminderType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpgradeMeeting", ZoomNodeMeetingConfigCtrlWrap::UpgradeMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpgradeAccount", ZoomNodeMeetingConfigCtrlWrap::UpgradeAccount);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelUpdate", ZoomNodeMeetingConfigCtrlWrap::CancelUpdate);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingNeedToUpgradeCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingNeedToUpgradeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStartCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStartCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStopCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStopCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToProMeetingCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToProMeetingCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingConfigCtrlWrap >() {
	return &ZoomNodeMeetingConfigCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZNativeSDKMeetingConfigWrapFreemeetingSink : public IZNativeSDKMeetingConfigWrapFreeMeetingSink
{
public:
	virtual void onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url)
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "giftUrl"), v8::String::NewFromUtf8(isolate, zs2s(gift_url).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "freeMeetingNeedUpgradeType"), v8::Integer::New(isolate, (int32_t)type));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingNeedToUpgrade);

		fn->Call(context, global, argc, argv);
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStart()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		int32_t temp = 0;
		v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)temp);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStart);

		fn->Call(context, global, argc, argv);
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStop()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		int32_t temp = 0;
		v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)temp);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToGiftFreeTrialStop);

		fn->Call(context, global, argc, argv);
	}
	virtual void onFreeMeetingUpgradeToProMeeting()
	{
		if (ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		int32_t temp = 0;
		v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)temp);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { bret };

		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onFreeMeetingUpgradeToProMeeting);

		fn->Call(context, global, argc, argv);
	}
};

static ZNativeSDKMeetingConfigWrapFreemeetingSink _g_node_meetingConfig_freeMeeting_cb;



#endif
