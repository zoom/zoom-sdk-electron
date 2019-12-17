#ifndef _ZOOM_NODE_SETTING_STATISTIC_CTRL_H_
#define _ZOOM_NODE_SETTING_STATISTIC_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingStatisticCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingStatisticCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingStatisticCtrlWrap >;
private:
	ZoomNodeSettingStatisticCtrlWrap();
	~ZoomNodeSettingStatisticCtrlWrap();
public:
	static void QueryOverallStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void QueryAudioStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void QueryVideoStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void QueryShareStatisticInfo(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingStatisticCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingStatisticCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "QueryOverallStatisticInfo", ZoomNodeSettingStatisticCtrlWrap::QueryOverallStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "QueryAudioStatisticInfo", ZoomNodeSettingStatisticCtrlWrap::QueryAudioStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "QueryVideoStatisticInfo", ZoomNodeSettingStatisticCtrlWrap::QueryVideoStatisticInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "QueryShareStatisticInfo", ZoomNodeSettingStatisticCtrlWrap::QueryShareStatisticInfo);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingStatisticCtrlWrap >() {
	return &ZoomNodeSettingStatisticCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
