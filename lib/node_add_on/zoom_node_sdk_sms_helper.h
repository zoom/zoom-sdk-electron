#ifndef _ZOOM_NODE_SDK_SMS_HELPER_H_
#define _ZOOM_NODE_SDK_SMS_HELPER_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeSDKSMSHelperWrap :
	public ZoomWrapObject<ZoomNodeSDKSMSHelperWrap >
{
	friend class ZoomWrapObject<ZoomNodeSDKSMSHelperWrap >;
private:
	ZoomNodeSDKSMSHelperWrap();
	~ZoomNodeSDKSMSHelperWrap();
public:
	static void EnableZoomAuthRealNameMeetingUIShown(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetDefaultCellPhoneInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetResendSMSVerificationCodeHandler(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Retrieve(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Retrieve_CancelAndLeaveMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetReVerifySMSVerificationCodeHandler(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Verify(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Verify_CancelAndLeaveMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSupportPhoneNumberCountryList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetNeedRealNameAuthMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetRetrieveSMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetVerifySMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSDKSMSHelperWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSDKSMSHelperWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableZoomAuthRealNameMeetingUIShown", ZoomNodeSDKSMSHelperWrap::EnableZoomAuthRealNameMeetingUIShown);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetResendSMSVerificationCodeHandler", ZoomNodeSDKSMSHelperWrap::GetResendSMSVerificationCodeHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Retrieve", ZoomNodeSDKSMSHelperWrap::Retrieve);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Retrieve_CancelAndLeaveMeeting", ZoomNodeSDKSMSHelperWrap::Retrieve_CancelAndLeaveMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetReVerifySMSVerificationCodeHandler", ZoomNodeSDKSMSHelperWrap::GetReVerifySMSVerificationCodeHandler);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Verify", ZoomNodeSDKSMSHelperWrap::Verify);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Verify_CancelAndLeaveMeeting", ZoomNodeSDKSMSHelperWrap::Verify_CancelAndLeaveMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSupportPhoneNumberCountryList", ZoomNodeSDKSMSHelperWrap::GetSupportPhoneNumberCountryList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetNeedRealNameAuthMeetingNotificationCB", ZoomNodeSDKSMSHelperWrap::SetNeedRealNameAuthMeetingNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRetrieveSMSVerificationCodeResultNotificationCB", ZoomNodeSDKSMSHelperWrap::SetRetrieveSMSVerificationCodeResultNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetVerifySMSVerificationCodeResultNotificationCB", ZoomNodeSDKSMSHelperWrap::SetVerifySMSVerificationCodeResultNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultCellPhoneInfo", ZoomNodeSDKSMSHelperWrap::SetDefaultCellPhoneInfo);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSDKSMSHelperWrap >() {
	return &ZoomNodeSDKSMSHelperWrap::constructor;
}

#endif
