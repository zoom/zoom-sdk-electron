#ifndef _ZOOM_NODE_SETTING_VIDEO_CTRL_H_
#define _ZOOM_NODE_SETTING_VIDEO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingVideoCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingVideoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingVideoCtrlWrap >;
private:
	ZoomNodeSettingVideoCtrlWrap();
	~ZoomNodeSettingVideoCtrlWrap();
public:
	static void SelectVideoCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableVideoMirrorEffect(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableFaceBeautyEffect(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsMirrorEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsFaceBeautyEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingVideoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingVideoCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectVideoCamera", ZoomNodeSettingVideoCtrlWrap::SelectVideoCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCameraList", ZoomNodeSettingVideoCtrlWrap::GetCameraList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableVideoMirrorEffect", ZoomNodeSettingVideoCtrlWrap::EnableVideoMirrorEffect);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableFaceBeautyEffect", ZoomNodeSettingVideoCtrlWrap::EnableFaceBeautyEffect);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMirrorEffectEnabled", ZoomNodeSettingVideoCtrlWrap::IsMirrorEffectEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsFaceBeautyEffectEnabled", ZoomNodeSettingVideoCtrlWrap::IsFaceBeautyEffectEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingVideoCtrlWrap >() {
	return &ZoomNodeSettingVideoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
