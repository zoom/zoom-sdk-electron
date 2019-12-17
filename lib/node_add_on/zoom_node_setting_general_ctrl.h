#ifndef _ZOOM_NODE_SETTING_GENERAL_CTRL_H_
#define _ZOOM_NODE_SETTING_GENERAL_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingGeneralCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingGeneralCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingGeneralCtrlWrap >;
private:
	ZoomNodeSettingGeneralCtrlWrap();
	~ZoomNodeSettingGeneralCtrlWrap();
public:
	/// \brief Enable or disable dual screen mode.
	/// \param 1. bEnable(bool) TRUE indicates to set to enable the dual screen mode.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableDualScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable the aero mode when sharing the screen.
	/// \param 1. bTurnoff(bool) TRUE indicates to turn off the aero mode when sharing the screen.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks The function can only be called in windows 7 environment.
	static void TurnOffAeroModeInSharing(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable to auto-fit the ZOOM window when viewing the shared content.
	/// \param 1. bEnable(bool) TRUE indicates to resize automatically.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableAutoFitToWindowWhenViewSharing(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable to enter the full screen video mode automatically when join meeting. 
	/// \param 1. bEnable(bool) TRUE indicates to enter the full screen video mode.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableAutoFullScreenVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable to use the split screen mode, which enables the attendees to view the lectures or the gallery.
	/// \param 1. bEnable(bool) TRUE indicates to enter the split screen mode.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableSplitScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if the dual screen mode is supported.
	/// \return TRUE indicates to enable the dual screen mode.
	static void IsDualScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if the aero mode is turned off when sharing the screen.
	/// \return TRUE indicates to turn off the mode. 
	static void IsAeroModeInSharingTurnOff(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if it is able to auto-fit the ZOOM window when viewing the shared content.
	/// \return TRUE indicates to resize automatically.
	static void IsAutoFitToWindowWhenViewSharingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if it is able to enter the full screen video mode automatically when join meeting.
	/// \return TRUE indicates to enter the full screen video mode.
	static void IsAutoFullScreenVideoWhenJoinMeetingEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Determine if the split screen mode is enabled.
	/// \return TRUE indicates enabled. FALSE not.
	static void IsSplitScreenModeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static void EnableAutoFullScreenVideoWhenViewShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAutoFullScreenVideoWhenViewShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableDisplayReminderWindowWhenExit(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsDisplayReminderWindowWhenExitEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableShowMyMeetingElapseTime(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsShowMyMeetingElapseTimeEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void IsCurrentOSSupportAccelerateGPUWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableAccelerateGPUWhenShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAccelerateGPUWhenShareEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableRemoteControlAllApplications(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsRemoteControlAllApplicationsEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingGeneralCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingGeneralCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDualScreenMode", ZoomNodeSettingGeneralCtrlWrap::EnableDualScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "TurnOffAeroModeInSharing", ZoomNodeSettingGeneralCtrlWrap::TurnOffAeroModeInSharing);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFitToWindowWhenViewSharing", ZoomNodeSettingGeneralCtrlWrap::EnableAutoFitToWindowWhenViewSharing);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFullScreenVideoWhenJoinMeeting", ZoomNodeSettingGeneralCtrlWrap::EnableAutoFullScreenVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSplitScreenMode", ZoomNodeSettingGeneralCtrlWrap::EnableSplitScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDualScreenModeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsDualScreenModeEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAeroModeInSharingTurnOff", ZoomNodeSettingGeneralCtrlWrap::IsAeroModeInSharingTurnOff);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFitToWindowWhenViewSharingEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAutoFitToWindowWhenViewSharingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFullScreenVideoWhenJoinMeetingEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSplitScreenModeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsSplitScreenModeEnabled);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoFullScreenVideoWhenViewShare", ZoomNodeSettingGeneralCtrlWrap::EnableAutoFullScreenVideoWhenViewShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoFullScreenVideoWhenViewShareEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAutoFullScreenVideoWhenViewShareEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDisplayReminderWindowWhenExit", ZoomNodeSettingGeneralCtrlWrap::EnableDisplayReminderWindowWhenExit);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsDisplayReminderWindowWhenExitEnabled", ZoomNodeSettingGeneralCtrlWrap::IsDisplayReminderWindowWhenExitEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShowMyMeetingElapseTime", ZoomNodeSettingGeneralCtrlWrap::EnableShowMyMeetingElapseTime);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsShowMyMeetingElapseTimeEnabled", ZoomNodeSettingGeneralCtrlWrap::IsShowMyMeetingElapseTimeEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "IsCurrentOSSupportAccelerateGPUWhenShare", ZoomNodeSettingGeneralCtrlWrap::IsCurrentOSSupportAccelerateGPUWhenShare);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAccelerateGPUWhenShare", ZoomNodeSettingGeneralCtrlWrap::EnableAccelerateGPUWhenShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAccelerateGPUWhenShareEnabled", ZoomNodeSettingGeneralCtrlWrap::IsAccelerateGPUWhenShareEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableRemoteControlAllApplications", ZoomNodeSettingGeneralCtrlWrap::EnableRemoteControlAllApplications);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsRemoteControlAllApplicationsEnabled", ZoomNodeSettingGeneralCtrlWrap::IsRemoteControlAllApplicationsEnabled);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingGeneralCtrlWrap >() {
	return &ZoomNodeSettingGeneralCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif
