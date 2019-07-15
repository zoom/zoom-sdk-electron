#ifndef _ZOOM_NODE_SETTING_GENERAL_CTRL_H_
#define _ZOOM_NODE_SETTING_GENERAL_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingGeneralCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingGeneralCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingGeneralCtrlWrap >;
private:
	ZoomNodeSettingGeneralCtrlWrap();
	~ZoomNodeSettingGeneralCtrlWrap();
public:
	static void EnableDualScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void TurnOffAeroModeInSharing(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAutoFitToWindowWhenViewSharing(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAutoFullScreenVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsDualScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAeroModeInSharingTurnOff(const v8::FunctionCallbackInfo<v8::Value>& args); //win7
	static void IsAutoFitToWindowWhenViewSharingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAutoFullScreenVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsSplitScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingGeneralCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingGeneralCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDualScreenMode", ZoomNodeSettingGeneralCtrlWrap::EnableDualScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOffAeroModeInSharing", ZoomNodeSettingGeneralCtrlWrap::TurnOffAeroModeInSharing);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFitToWindowWhenViewSharing", ZoomNodeSettingGeneralCtrlWrap::EnableAutoFitToWindowWhenViewSharing);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFullScreenVideoWhenJoinMeeting", ZoomNodeSettingGeneralCtrlWrap::EnableAutoFullScreenVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSplitScreenMode", ZoomNodeSettingGeneralCtrlWrap::EnableSplitScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDualScreenModeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsDualScreenModeEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAeroModeInSharingTurnOff", ZoomNodeSettingGeneralCtrlWrap::IsAeroModeInSharingTurnOff);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFitToWindowWhenViewSharingEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAutoFitToWindowWhenViewSharingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFullScreenVideoWhenJoinMeetingEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSplitScreenModeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsSplitScreenModeEnabled);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingGeneralCtrlWrap >() {
	return &ZoomNodeSettingGeneralCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
