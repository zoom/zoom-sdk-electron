#ifndef _ZOOM_NODE_SETTING_RECORDING_CTRL_H_
#define _ZOOM_NODE_SETTING_RECORDING_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;

class ZOOM_NODE_HIDE ZoomNodeSettingRecordingCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingRecordingCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingRecordingCtrlWrap >;
private:
	ZoomNodeSettingRecordingCtrlWrap();
	~ZoomNodeSettingRecordingCtrlWrap();
public:
	/// \brief Set the path to save the recording file.
	/// \param 1. szPath(string) Specify the path to save the recording file.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the path to save the recording file.
	/// \return The path to save the recording file.
	static void GetRecordingPath(const v8::FunctionCallbackInfo<v8::Value>& args);

	///////////////////////////////////////////////////////////////////////////////////////////////////////
	static void SetonCloudRecordingStorageInfoCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanGetCloudRecordingStorageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetCloudRecordingStorageInfo(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void GetRecordingManagementURL(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CanGetRecordingManagementURL(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableSelectRecordFileLocationAfterMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsSelectRecordFileLocationAfterMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableMultiAudioStreamRecord(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsMultiAudioStreamRecordEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableAddTimestampWatermark(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAddTimestampWatermarkEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableOptimizeFor3rdPartyVideoEditor(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsOptimizeFor3rdPartyVideoEditorEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableShowVideoThumbnailWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsShowVideoThumbnailWhenShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnablePlaceVideoNextToShareInRecord(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsPlaceVideoNextToShareInRecordEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingRecordingCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingRecordingCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetRecordingPath", ZoomNodeSettingRecordingCtrlWrap::SetRecordingPath);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRecordingPath", ZoomNodeSettingRecordingCtrlWrap::GetRecordingPath);
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonCloudRecordingStorageInfoCB", ZoomNodeSettingRecordingCtrlWrap::SetonCloudRecordingStorageInfoCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanGetCloudRecordingStorageInfo", ZoomNodeSettingRecordingCtrlWrap::CanGetCloudRecordingStorageInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCloudRecordingStorageInfo", ZoomNodeSettingRecordingCtrlWrap::GetCloudRecordingStorageInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRecordingManagementURL", ZoomNodeSettingRecordingCtrlWrap::GetRecordingManagementURL);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CanGetRecordingManagementURL", ZoomNodeSettingRecordingCtrlWrap::CanGetRecordingManagementURL);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSelectRecordFileLocationAfterMeeting", ZoomNodeSettingRecordingCtrlWrap::EnableSelectRecordFileLocationAfterMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSelectRecordFileLocationAfterMeetingEnabled", ZoomNodeSettingRecordingCtrlWrap::IsSelectRecordFileLocationAfterMeetingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMultiAudioStreamRecord", ZoomNodeSettingRecordingCtrlWrap::EnableMultiAudioStreamRecord);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMultiAudioStreamRecordEnabled", ZoomNodeSettingRecordingCtrlWrap::IsMultiAudioStreamRecordEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAddTimestampWatermark", ZoomNodeSettingRecordingCtrlWrap::EnableAddTimestampWatermark);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAddTimestampWatermarkEnabled", ZoomNodeSettingRecordingCtrlWrap::IsAddTimestampWatermarkEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableOptimizeFor3rdPartyVideoEditor", ZoomNodeSettingRecordingCtrlWrap::EnableOptimizeFor3rdPartyVideoEditor);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsOptimizeFor3rdPartyVideoEditorEnabled", ZoomNodeSettingRecordingCtrlWrap::IsOptimizeFor3rdPartyVideoEditorEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShowVideoThumbnailWhenShare", ZoomNodeSettingRecordingCtrlWrap::EnableShowVideoThumbnailWhenShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsShowVideoThumbnailWhenShareEnabled", ZoomNodeSettingRecordingCtrlWrap::IsShowVideoThumbnailWhenShareEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnablePlaceVideoNextToShareInRecord", ZoomNodeSettingRecordingCtrlWrap::EnablePlaceVideoNextToShareInRecord);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsPlaceVideoNextToShareInRecordEnabled", ZoomNodeSettingRecordingCtrlWrap::IsPlaceVideoNextToShareInRecordEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingRecordingCtrlWrap >() {
	return &ZoomNodeSettingRecordingCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#endif
