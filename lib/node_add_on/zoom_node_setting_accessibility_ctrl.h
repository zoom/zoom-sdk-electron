#ifndef _ZOOM_NODE_SETTING_ACCESSIBILITY_CTRL_H_
#define _ZOOM_NODE_SETTING_ACCESSIBILITY_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingAccessibilityCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingAccessibilityCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingAccessibilityCtrlWrap >;
private:
	ZoomNodeSettingAccessibilityCtrlWrap();
	~ZoomNodeSettingAccessibilityCtrlWrap();
public:
	static void EnableAlwaysShowMeetingControls(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAlwaysShowMeetingControlsEnable(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingAccessibilityCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingAccessibilityCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAlwaysShowMeetingControls", ZoomNodeSettingAccessibilityCtrlWrap::EnableAlwaysShowMeetingControls);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAlwaysShowMeetingControlsEnable", ZoomNodeSettingAccessibilityCtrlWrap::IsAlwaysShowMeetingControlsEnable);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingAccessibilityCtrlWrap >() {
	return &ZoomNodeSettingAccessibilityCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
