#ifndef _ZOOM_NODE_MEETING_AUDIO_CTRL_H_
#define _ZOOM_NODE_MEETING_AUDIO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingAudioCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingAudioCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingAudioCtrlWrap >;
private:
	ZoomNodeMeetingAudioCtrlWrap();
	~ZoomNodeMeetingAudioCtrlWrap();
public:
	static void MuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void UnMuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void JoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void LeaveVoip(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingAudioStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingAudioCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingAudioCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "MuteAudio", ZoomNodeMeetingAudioCtrlWrap::MuteAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UnMuteAudio", ZoomNodeMeetingAudioCtrlWrap::UnMuteAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "JoinVoip", ZoomNodeMeetingAudioCtrlWrap::JoinVoip);
	NODE_SET_PROTOTYPE_METHOD(tpl, "LeaveVoip", ZoomNodeMeetingAudioCtrlWrap::LeaveVoip);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingAudioStatusCB", ZoomNodeMeetingAudioCtrlWrap::SetMeetingAudioStatusCB);

}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingAudioCtrlWrap >() {
	return &ZoomNodeMeetingAudioCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingAudioWrapSink : public IZNativeSDKMeetingAudioWrapSink
{
public:
	virtual void onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		
		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (int i = 0; i < lstAudioStatusChange.getLength(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::String::NewFromUtf8(isolate, zs2s(lstAudioStatusChange.get(i).userId).c_str()));
			node->Set(v8::String::NewFromUtf8(isolate, "audioStauts"), v8::Integer::New(isolate, (int32_t)lstAudioStatusChange.get(i).audioStauts));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange);

		fn->Call(context, global, argc, argv);
	}
};

static ZNativeSDKMeetingAudioWrapSink _g_node_meetingAudio_cb;



#endif
