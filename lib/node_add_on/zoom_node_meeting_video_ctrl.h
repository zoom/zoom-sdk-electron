#ifndef _ZOOM_NODE_MEETING_VIDEO_CTRL_H_
#define _ZOOM_NODE_MEETING_VIDEO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingVideoCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingVideoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingVideoCtrlWrap >;
private:
	ZoomNodeMeetingVideoCtrlWrap();
	~ZoomNodeMeetingVideoCtrlWrap();
public:
	static void MuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnMuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void PinVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideOrShowNoVideoUserOnVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingVideoStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingVideoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingVideoCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "MuteVideo", ZoomNodeMeetingVideoCtrlWrap::MuteVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnMuteVideo", ZoomNodeMeetingVideoCtrlWrap::UnMuteVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PinVideo", ZoomNodeMeetingVideoCtrlWrap::PinVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SpotlightVideo", ZoomNodeMeetingVideoCtrlWrap::SpotlightVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideOrShowNoVideoUserOnVideoWall", ZoomNodeMeetingVideoCtrlWrap::HideOrShowNoVideoUserOnVideoWall);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingVideoStatusCB", ZoomNodeMeetingVideoCtrlWrap::SetMeetingVideoStatusCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingVideoCtrlWrap >() {
	return &ZoomNodeMeetingVideoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingVideoWrapSink : public IZNativeSDKMeetingVideoWrapSink
{
public:
	virtual void onUserVideoStatusChange(ZoomSTRING userId, ZNVideoStatus status)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange.IsEmpty())
		return;
		
		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(v8::String::NewFromUtf8(isolate, "userId"), v8::String::NewFromUtf8(isolate, zs2s(userId).c_str()));
		node->Set(v8::String::NewFromUtf8(isolate, "videoStatus"), v8::Integer::New(isolate, (int32_t)status));

		int argc = 1;
		v8::Local<v8::Value> argv[1] = { node };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange);

		fn->Call(context, global, argc, argv);


	}
};

static ZNativeSDKMeetingVideoWrapSink _g_node_meetingVideo_cb;


#endif
