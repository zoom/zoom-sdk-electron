#ifndef _ZOOM_NODE_RENDER_ADDON_H_
#define _ZOOM_NODE_RENDER_ADDON_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_singleton_wrap_class.h"



class ZOOM_NODE_HIDE ZoomNodeRenderWrap : public ZoomWrapObject<ZoomNodeRenderWrap >
{
	friend class ZoomWrapObject<ZoomNodeRenderWrap >;
private:
	ZoomNodeRenderWrap() {}
	~ZoomNodeRenderWrap() {}

public:
	
	static void GetVideoLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetShareLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetAudioLibuvClientObj(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeRenderWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeRenderWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype

	NODE_SET_PROTOTYPE_METHOD(tpl, "GetVideoLibuvClientObj", ZoomNodeRenderWrap::GetVideoLibuvClientObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetShareLibuvClientObj", ZoomNodeRenderWrap::GetShareLibuvClientObj);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetAudioLibuvClientObj", ZoomNodeRenderWrap::GetAudioLibuvClientObj);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeRenderWrap >() {
	return &ZoomNodeRenderWrap::constructor;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeVideoRawDataLibuvClientWrap :
	public ZoomWrapObject<ZoomNodeVideoRawDataLibuvClientWrap >
{
	//
	friend class ZoomWrapObject<ZoomNodeVideoRawDataLibuvClientWrap >;
private:
	ZoomNodeVideoRawDataLibuvClientWrap() {};
	~ZoomNodeVideoRawDataLibuvClientWrap() {};
public:
	static void SetRenderVideoRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartVideoClient(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopVideoClient(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeVideoRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeVideoRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRenderVideoRawDataCB", ZoomNodeVideoRawDataLibuvClientWrap::SetRenderVideoRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartVideoClient", ZoomNodeVideoRawDataLibuvClientWrap::StartVideoClient);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopVideoClient", ZoomNodeVideoRawDataLibuvClientWrap::StopVideoClient);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeVideoRawDataLibuvClientWrap >() {
	return &ZoomNodeVideoRawDataLibuvClientWrap::constructor;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeShareRawDataLibuvClientWrap :
	public ZoomWrapObject<ZoomNodeShareRawDataLibuvClientWrap >
{
	//
	friend class ZoomWrapObject<ZoomNodeShareRawDataLibuvClientWrap >;
private:
	ZoomNodeShareRawDataLibuvClientWrap() {};
	~ZoomNodeShareRawDataLibuvClientWrap() {};
public:
	static void SetRenderShareRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartShareClient(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopShareClient(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeShareRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeShareRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRenderShareRawDataCB", ZoomNodeShareRawDataLibuvClientWrap::SetRenderShareRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartShareClient", ZoomNodeShareRawDataLibuvClientWrap::StartShareClient);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopShareClient", ZoomNodeShareRawDataLibuvClientWrap::StopShareClient);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeShareRawDataLibuvClientWrap >() {
	return &ZoomNodeShareRawDataLibuvClientWrap::constructor;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZOOM_NODE_HIDE ZoomNodeAudioRawDataLibuvClientWrap :
	public ZoomWrapObject<ZoomNodeAudioRawDataLibuvClientWrap >
{
	//
	friend class ZoomWrapObject<ZoomNodeAudioRawDataLibuvClientWrap >;
private:
	ZoomNodeAudioRawDataLibuvClientWrap() {};
	~ZoomNodeAudioRawDataLibuvClientWrap() {};
public:
	static void SetRenderAudioRawDataCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartAudioClient(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopAudioClient(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};

template<>
static void InitClassAttribute<ZoomNodeAudioRawDataLibuvClientWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeAudioRawDataLibuvClientWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRenderAudioRawDataCB", ZoomNodeAudioRawDataLibuvClientWrap::SetRenderAudioRawDataCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAudioClient", ZoomNodeAudioRawDataLibuvClientWrap::StartAudioClient);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAudioClient", ZoomNodeAudioRawDataLibuvClientWrap::StopAudioClient);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeAudioRawDataLibuvClientWrap >() {
	return &ZoomNodeAudioRawDataLibuvClientWrap::constructor;
}
#endif
