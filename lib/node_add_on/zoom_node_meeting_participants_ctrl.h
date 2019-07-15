#ifndef _ZOOM_NODE_MEETING_PARTICIPANTS_CTRL_H_
#define _ZOOM_NODE_MEETING_PARTICIPANTS_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingParticipantsCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingParticipantsCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingParticipantsCtrlWrap >;
private:
	ZoomNodeMeetingParticipantsCtrlWrap();
	~ZoomNodeMeetingParticipantsCtrlWrap();
public:
	static void SetMeetingUserJoinCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingUserLeftCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetMeetingHostChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingParticipantsCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingParticipantsCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUserJoinCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserJoinCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUserLeftCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingUserLeftCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingHostChangeCB", ZoomNodeMeetingParticipantsCtrlWrap::SetMeetingHostChangeCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingParticipantsCtrlWrap >() {
	return &ZoomNodeMeetingParticipantsCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZNativeSDKMeetingParticipantsWrapSink : public IZNativeSDKMeetingParticipantsWrapSink
{
public:
	virtual void onUserJoin(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserJoin.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();
		
		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (int i = 0; i < lstUserID.getLength(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::String::NewFromUtf8(isolate, zs2s(lstUserID.get(i)).c_str()));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserJoin);

		fn->Call(context, global, argc, argv);
	}
	virtual void onUserLeft(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList)
	{
		if (ZoomNodeSinkHelper::GetInst().onUserLeft.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::Array> nodes = v8::Array::New(isolate);
		for (int i = 0; i < lstUserID.getLength(); ++i) {
			v8::HandleScope scope(isolate);
			v8::Local<v8::Object> node = v8::Object::New(isolate);
			node->Set(v8::String::NewFromUtf8(isolate, "userid"), v8::String::NewFromUtf8(isolate, zs2s(lstUserID.get(i)).c_str()));
			nodes->Set(i, node);
		}
		//
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { nodes };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onUserLeft);

		fn->Call(context, global, argc, argv);
	}
	virtual void onHostChangeNotification(ZoomSTRING userId)
	{
		if (ZoomNodeSinkHelper::GetInst().onHostChangeNotification.IsEmpty())
			return;

		auto isolate = v8::Isolate::GetCurrent();
		v8::HandleScope scope(isolate);
		auto context = isolate->GetCurrentContext();
		auto global = context->Global();

		v8::Local<v8::String> v8_userid = v8::String::NewFromUtf8(isolate, zs2s(userId).c_str());
		int argc = 1;
		v8::Local<v8::Value> argv[1] = { v8_userid };
		auto fn = v8::Local<v8::Function>::New(isolate, ZoomNodeSinkHelper::GetInst().onHostChangeNotification);

		fn->Call(context, global, argc, argv);
	}
};

static ZNativeSDKMeetingParticipantsWrapSink _g_node_meetingParticipants_cb;





#endif
