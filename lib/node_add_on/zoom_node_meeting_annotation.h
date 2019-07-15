#ifndef _ZOOM_NODE_MEETING_ANNOTATION_H_
#define _ZOOM_NODE_MEETING_ANNOTATION_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingAnnotationWrap :
	public ZoomWrapObject<ZoomNodeMeetingAnnotationWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingAnnotationWrap >;
private:
	ZoomNodeMeetingAnnotationWrap() {};
	~ZoomNodeMeetingAnnotationWrap() {};
public:
	static void IsAnnoataionDisable(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopAnnotation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetTool(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Clear(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetColor(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetLineWidth(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Undo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Redo(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingAnnotationWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingAnnotationWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAnnoataionDisable", ZoomNodeMeetingAnnotationWrap::IsAnnoataionDisable);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartAnnotation", ZoomNodeMeetingAnnotationWrap::StartAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopAnnotation", ZoomNodeMeetingAnnotationWrap::StopAnnotation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetTool", ZoomNodeMeetingAnnotationWrap::SetTool);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Clear", ZoomNodeMeetingAnnotationWrap::Clear);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetColor", ZoomNodeMeetingAnnotationWrap::SetColor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetLineWidth", ZoomNodeMeetingAnnotationWrap::SetLineWidth);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Undo", ZoomNodeMeetingAnnotationWrap::Undo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Redo", ZoomNodeMeetingAnnotationWrap::Redo);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingAnnotationWrap >() {
	return &ZoomNodeMeetingAnnotationWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
