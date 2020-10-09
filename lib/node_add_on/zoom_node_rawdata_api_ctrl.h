#ifndef _ZOOM_NODE_RAW_API_CTRL_H_
#define _ZOOM_NODE_RAW_API_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeRawApiCtrlWrap :
	public ZoomWrapObject<ZoomNodeRawApiCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeRawApiCtrlWrap >;
private:
	ZoomNodeRawApiCtrlWrap();
	~ZoomNodeRawApiCtrlWrap();
public:
	
	static void HasRawDataLicense(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void InitAudioRawDataHelper(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static void GetRawdataVideoSourceHelper(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void CreateRenderer(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void DestroyRenderer(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void Subscribe(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void UnSubscribe(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SetRawDataResolution(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetResolution(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetRawDataType(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetUserId(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SetonRawDataStatusChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SubscribeAudioRawdata(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void UnSubscribeAudioRawdata(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void StartPipeServe(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void StopPipeServe(const v8::FunctionCallbackInfo<v8::Value>& args);

	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeRawApiCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeRawApiCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "HasRawDataLicense", ZoomNodeRawApiCtrlWrap::HasRawDataLicense);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InitAudioRawDataHelper", ZoomNodeRawApiCtrlWrap::InitAudioRawDataHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRawdataVideoSourceHelper", ZoomNodeRawApiCtrlWrap::GetRawdataVideoSourceHelper);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CreateRenderer", ZoomNodeRawApiCtrlWrap::CreateRenderer);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DestroyRenderer", ZoomNodeRawApiCtrlWrap::DestroyRenderer);

	NODE_SET_PROTOTYPE_METHOD(tpl, "Subscribe", ZoomNodeRawApiCtrlWrap::Subscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribe", ZoomNodeRawApiCtrlWrap::UnSubscribe);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRawDataResolution", ZoomNodeRawApiCtrlWrap::SetRawDataResolution);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetResolution", ZoomNodeRawApiCtrlWrap::GetResolution);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRawDataType", ZoomNodeRawApiCtrlWrap::GetRawDataType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetUserId", ZoomNodeRawApiCtrlWrap::GetUserId);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRawDataStatusChangedCB", ZoomNodeRawApiCtrlWrap::SetonRawDataStatusChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SubscribeAudioRawdata", ZoomNodeRawApiCtrlWrap::SubscribeAudioRawdata);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnSubscribeAudioRawdata", ZoomNodeRawApiCtrlWrap::UnSubscribeAudioRawdata);

	NODE_SET_PROTOTYPE_METHOD(tpl, "StartPipeServe", ZoomNodeRawApiCtrlWrap::StartPipeServe);

	NODE_SET_PROTOTYPE_METHOD(tpl, "StopPipeServe", ZoomNodeRawApiCtrlWrap::StopPipeServe);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeRawApiCtrlWrap >() {
	return &ZoomNodeRawApiCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





#endif
