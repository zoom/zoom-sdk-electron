#ifndef _ZOOM_NODE_MEETING_RECORDING_CTRL_H_
#define _ZOOM_NODE_MEETING_RECORDING_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeMeetingRecordingCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingRecordingCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingRecordingCtrlWrap >;
private:
	ZoomNodeMeetingRecordingCtrlWrap();
	~ZoomNodeMeetingRecordingCtrlWrap();
public:
	
	static void StartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanStartRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanAllowDisAllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StartCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void StopCloudRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsSupportLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void AllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisAllowLocalRecording(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RequestCustomizedLocalRecordingSource(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SetonRecording2MP4DoneCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonRecording2MP4ProcessingCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonRecordingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonCloudRecordingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonRecordPriviligeChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonCustomizedLocalRecordingSourceNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);


	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingRecordingCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingRecordingCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartRecording", ZoomNodeMeetingRecordingCtrlWrap::StartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopRecording", ZoomNodeMeetingRecordingCtrlWrap::StopRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanStartRecording", ZoomNodeMeetingRecordingCtrlWrap::CanStartRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanAllowDisAllowLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::CanAllowDisAllowLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StartCloudRecording", ZoomNodeMeetingRecordingCtrlWrap::StartCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "StopCloudRecording", ZoomNodeMeetingRecordingCtrlWrap::StopCloudRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSupportLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::IsSupportLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AllowLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::AllowLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisAllowLocalRecording", ZoomNodeMeetingRecordingCtrlWrap::DisAllowLocalRecording);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RequestCustomizedLocalRecordingSource", ZoomNodeMeetingRecordingCtrlWrap::RequestCustomizedLocalRecordingSource);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecording2MP4DoneCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecording2MP4DoneCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecording2MP4ProcessingCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecording2MP4ProcessingCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecordingStatusCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecordingStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCloudRecordingStatusCB", ZoomNodeMeetingRecordingCtrlWrap::SetonCloudRecordingStatusCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonRecordPriviligeChangedCB", ZoomNodeMeetingRecordingCtrlWrap::SetonRecordPriviligeChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCustomizedLocalRecordingSourceNotificationCB", ZoomNodeMeetingRecordingCtrlWrap::SetonCustomizedLocalRecordingSourceNotificationCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingRecordingCtrlWrap >() {
	return &ZoomNodeMeetingRecordingCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
