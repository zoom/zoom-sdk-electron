#ifndef _ZOOM_NODE_SETTING_VIDEO_CTRL_H_
#define _ZOOM_NODE_SETTING_VIDEO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingVideoCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingVideoCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingVideoCtrlWrap >;
private:
	ZoomNodeSettingVideoCtrlWrap();
	~ZoomNodeSettingVideoCtrlWrap();
public:
	/// \brief Select camera device.
	/// \param 1. deviceId(string) Specify a device to be selected.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SelectVideoCamera(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get camera device list.
	/// \return If the function succeeds, the return value is a camera device list.
	///Otherwise failed, returns an empty array.
	static void GetCameraList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable video mirror effect.
	/// \param 1. bEnable(bool) TRUE indicates to enable the video mirror effect.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableVideoMirrorEffect(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable the video facial beauty effect.
	/// \param 1. bEnable(bool) TRUE indicates to enable the video facial beauty effect.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableFaceBeautyEffect(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the flag to enable/disable the video mirror effect.
	/// \return Enabled(TRUE) or disabled(FALSE).
	static void IsMirrorEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the flag to enable/disable the video facial beauty effect.
	/// \return Enabled(TRUE) or disabled(FALSE).
	static void IsFaceBeautyEffectEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	static void SetComputerCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetDefaultCamDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableHDVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsHDVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableAlwaysShowNameOnVideo(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAlwaysShowNameOnVideoEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableAutoTurnOffVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAutoTurnOffVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableAlwaysUse16v9(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAlwaysUse16v9(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableSpotlightSelf(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsSpotlightSelfEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableHardwareEncode(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsHardwareEncodeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void Enable49VideoesInGallaryView(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void Is49VideoesInGallaryViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableHideNoVideoUsersOnWallView(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsHideNoVideoUsersOnWallViewEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingVideoCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingVideoCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectVideoCamera", ZoomNodeSettingVideoCtrlWrap::SelectVideoCamera);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetCameraList", ZoomNodeSettingVideoCtrlWrap::GetCameraList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableVideoMirrorEffect", ZoomNodeSettingVideoCtrlWrap::EnableVideoMirrorEffect);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableFaceBeautyEffect", ZoomNodeSettingVideoCtrlWrap::EnableFaceBeautyEffect);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMirrorEffectEnabled", ZoomNodeSettingVideoCtrlWrap::IsMirrorEffectEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsFaceBeautyEffectEnabled", ZoomNodeSettingVideoCtrlWrap::IsFaceBeautyEffectEnabled);

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetComputerCamDeviceChangedCB", ZoomNodeSettingVideoCtrlWrap::SetComputerCamDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultCamDeviceChangedCB", ZoomNodeSettingVideoCtrlWrap::SetDefaultCamDeviceChangedCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHDVideo", ZoomNodeSettingVideoCtrlWrap::EnableHDVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHDVideoEnabled", ZoomNodeSettingVideoCtrlWrap::IsHDVideoEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAlwaysShowNameOnVideo", ZoomNodeSettingVideoCtrlWrap::EnableAlwaysShowNameOnVideo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAlwaysShowNameOnVideoEnabled", ZoomNodeSettingVideoCtrlWrap::IsAlwaysShowNameOnVideoEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoTurnOffVideoWhenJoinMeeting", ZoomNodeSettingVideoCtrlWrap::EnableAutoTurnOffVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoTurnOffVideoWhenJoinMeetingEnabled", ZoomNodeSettingVideoCtrlWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAlwaysUse16v9", ZoomNodeSettingVideoCtrlWrap::EnableAlwaysUse16v9);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAlwaysUse16v9", ZoomNodeSettingVideoCtrlWrap::IsAlwaysUse16v9);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSpotlightSelf", ZoomNodeSettingVideoCtrlWrap::EnableSpotlightSelf);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSpotlightSelfEnabled", ZoomNodeSettingVideoCtrlWrap::IsSpotlightSelfEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHardwareEncode", ZoomNodeSettingVideoCtrlWrap::EnableHardwareEncode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHardwareEncodeEnabled", ZoomNodeSettingVideoCtrlWrap::IsHardwareEncodeEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "Enable49VideoesInGallaryView", ZoomNodeSettingVideoCtrlWrap::Enable49VideoesInGallaryView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "Is49VideoesInGallaryViewEnabled", ZoomNodeSettingVideoCtrlWrap::Is49VideoesInGallaryViewEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHideNoVideoUsersOnWallView", ZoomNodeSettingVideoCtrlWrap::EnableHideNoVideoUsersOnWallView);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHideNoVideoUsersOnWallViewEnabled", ZoomNodeSettingVideoCtrlWrap::IsHideNoVideoUsersOnWallViewEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingVideoCtrlWrap >() {
	return &ZoomNodeSettingVideoCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
