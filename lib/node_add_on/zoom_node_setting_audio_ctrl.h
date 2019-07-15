#ifndef _ZOOM_NODE_SETTING_AUDIO_CTRL_H_
#define _ZOOM_NODE_SETTING_AUDIO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingAudioCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingAudioCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingAudioCtrlWrap >;
private:
	ZoomNodeSettingAudioCtrlWrap();
	~ZoomNodeSettingAudioCtrlWrap();
public:
	static void SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMicList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSpeakerList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAutoJoinAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAutoAdjustMicEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAutoJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAutoAdjustMic(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingAudioCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingAudioCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectMic", ZoomNodeSettingAudioCtrlWrap::SelectMic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMicList", ZoomNodeSettingAudioCtrlWrap::GetMicList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectSpeaker", ZoomNodeSettingAudioCtrlWrap::SelectSpeaker);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpeakerList", ZoomNodeSettingAudioCtrlWrap::GetSpeakerList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoJoinAudioEnabled", ZoomNodeSettingAudioCtrlWrap::IsAutoJoinAudioEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoAdjustMicEnabled", ZoomNodeSettingAudioCtrlWrap::IsAutoAdjustMicEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoJoinAudio", ZoomNodeSettingAudioCtrlWrap::EnableAutoJoinAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoAdjustMic", ZoomNodeSettingAudioCtrlWrap::EnableAutoAdjustMic);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingAudioCtrlWrap >() {
	return &ZoomNodeSettingAudioCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
