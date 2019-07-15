#ifndef _ZOOM_NODE_MEETING_SHARE_CTRL_H_
#define _ZOOM_NODE_MEETING_SHARE_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingShareCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingShareCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingShareCtrlWrap >;
private:
	ZoomNodeMeetingShareCtrlWrap();
	~ZoomNodeMeetingShareCtrlWrap();
public:
	static void StartAppShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartMonitorShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingShareCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingShareCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAppShare", ZoomNodeMeetingShareCtrlWrap::StartAppShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartMonitorShare", ZoomNodeMeetingShareCtrlWrap::StartMonitorShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopShare", ZoomNodeMeetingShareCtrlWrap::StopShare);
	
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingShareCtrlWrap >() {
	return &ZoomNodeMeetingShareCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





#endif
