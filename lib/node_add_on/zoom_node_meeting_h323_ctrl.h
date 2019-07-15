#ifndef _ZOOM_NODE_MEETING_H323_CTRL_H_
#define _ZOOM_NODE_MEETING_H323_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingH323CtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingH323CtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingH323CtrlWrap >;
private:
	ZoomNodeMeetingH323CtrlWrap();
	~ZoomNodeMeetingH323CtrlWrap();
public:
	static void CallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CancelCallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetH323Address(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetH323Password(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCalloutH323DviceList(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetH323CallOutStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingH323CtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingH323CtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "CallOutH323", ZoomNodeMeetingH323CtrlWrap::CallOutH323);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelCallOutH323", ZoomNodeMeetingH323CtrlWrap::CancelCallOutH323);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetH323Address", ZoomNodeMeetingH323CtrlWrap::GetH323Address);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetH323Password", ZoomNodeMeetingH323CtrlWrap::GetH323Password);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCalloutH323DviceList", ZoomNodeMeetingH323CtrlWrap::GetCalloutH323DviceList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetH323CallOutStatusCB", ZoomNodeMeetingH323CtrlWrap::SetH323CallOutStatusCB);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingH323CtrlWrap >() {
	return &ZoomNodeMeetingH323CtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingH323WrapSink : public IZNativeSDKMeetingH323WrapSink
{
public:
	virtual void onH323CalloutStatusNotify(ZNH323CalloutStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify.IsEmpty())
		return;
		
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Integer> v8_h323CalloutStatus = v8::Integer::New(isolate, (int32_t)status);
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_h323CalloutStatus };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify);

		fn->Call(context, global, argc, argv);
	}
};

static ZNativeSDKMeetingH323WrapSink _g_node_meetingH323_cb;



#endif
