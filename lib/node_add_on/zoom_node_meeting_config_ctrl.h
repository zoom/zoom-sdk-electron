#ifndef _ZOOM_NODE_MEETING_CONFIG_CTRL_H_
#define _ZOOM_NODE_MEETING_CONFIG_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeMeetingConfigCtrlWrap :
	public ZoomWrapObject<ZoomNodeMeetingConfigCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeMeetingConfigCtrlWrap >;
private:
	ZoomNodeMeetingConfigCtrlWrap();
	~ZoomNodeMeetingConfigCtrlWrap();
public:
	/// \brief Set the visibility of the INVITE button in the toolbar during the meeting. Default value: TRUE.
	/// \param 1. bEnable(bool) TRUE indicates to display the button. Otherwise not.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableInviteButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the position of the floating video window when sharing. 	/// \param 1. For Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	///For Mac: height(string) Specifies the height of the window.
	/// \param 2. hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
	///For Mac: width(string) Specifies the width of the window.
	/// \param 3. left(string) Specifies the X-axis coordinate of the top-left corner of the window
	/// \param 4. top(string) Specifies the Y-axis coordinate of the top-left of the window.	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks The value shall be set before the sharing begins. If you set the value during the process of share, the function will not be valid until the next share.
	static void SetFloatVideoPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the toolbar at the bottom of the meeting window.
	/// \param 1. bShow(bool) TRUE means to enable the feature to display always the toolbar at the bottom. Otherwise not. 
	static void SetBottomFloatToolbarWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the sharing toolbar. Default value: TRUE. 
	/// \param 1. bShow(bool) TRUE means to enable the display sharing toolbar. Otherwise not.
	/// \remarks This function works only before the meeting or the sharing starts. 
	static void SetSharingToolbarVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the shared device ID when sharing directly.
	/// \param 1. monitorID(string) Specify the device ID to be shared. 
	static void SetDirectShareMonitorID(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the position of the primary view meeting window.
	/// \param 1. For Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	///For Mac: height(string) Specifies the height of the window.
	/// \param 2. hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
	///For Mac: width(string) Specifies the width of the window.
	/// \param 3. left(string) Specifies the X-axis coordinate of the top-left corner of the window
	/// \param 4. top(string) Specifies the Y-axis coordinate of the top-left of the window.
	static void SetMeetingUIPos(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the dialog box of waiting for the host after joining the meeting. Only invalidate when the host is not in the meeting.
	/// \param 1. bDisable(bool) TRUE indicates to hide the dialog box. FALSE not.
	static void DisableWaitingForHostDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the meeting ID in the title-bar.
	/// \param 1. bHide(bool) FALSE means to display the content. Otherwise not.
	static void HideMeetingInfoFromMeetingUITitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the meeting ID in the title-bar of the meeting window. 
	/// \param 1. meetingNumber(number) Specify the meeting ID in the title-bar of the meeting window.
	static void SetMeetingIDForMeetingUITitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the dialog box if the password is wrong when join the meeting.
	/// \param 1. bDisable(bool) TRUE indicates to hide the dialog box of wrong password.
	/// \remarks If it is disabled to display the dialog box of wrong password, the system will directly exit the state of trying to join the meeting.
	static void DisablePopupMeetingWrongPSWDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to end automatically another ongoing meeting when joining a new meeting. 
	/// \param 1. bEnable(bool) TRUE indicates to end the other ongoing meetings. FALSE not.
	static void EnableAutoEndOtherMeetingWhenStartMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to switch between the full screen mode and normal mode by double-click. 
	/// \param 1. bEnable(bool) TRUE indicates to switch. FALSE not.
	static void EnableLButtonDBClick4SwitchFullScreenMode(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the floating video window when sharing in the meeting. 
	/// \param 1. bShow(bool) TRUE indicates to display the floating video window. FALSE not.
	static void SetFloatVideoWndVisibility(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Pre-set email and username information before joining the webinar.
	/// \param 1. email(string) Configure the default email.
	/// \param 2. username(string) Configure default username.
	static void PrePopulateWebinarRegistrationInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the reminder type of ending free meeting.
	/// \return If the function succeeds, the return value is a value of \link ZNFreeMeetingEndingReminderType \endlink enum.
	static void GetReminderType(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Upgrade the meeting if the notification is the ZN_FreeMeetingEndingReminder_Can_UpgradeMeeting_ToPro_Once.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks The SDK will destroy this object instance after calling this function.
	static void UpgradeMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Upgrade the account if the notification is the ZN_FreeMeetingEndingReminder_Can_UpgradeAccount.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks The SDK will destroy this object instance after calling this function.
	static void UpgradeAccount(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Ignore the current notification.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	/// \remarks The SDK will destroy this object instance after calling this function.
	static void CancelUpdate(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the callback of upgrading the free meeting.
	/// \param 1. callback(function)  The callback of upgrading the free meeting, onFreeMeetingNeedToUpgrade.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetFreeMeetingNeedToUpgradeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the callback function of starting to upgrade the free meeting by the gift link.
	/// \param 1. callback(function)  The callback of starting to upgrade the free meeting by the gift link, onFreeMeetingUpgradeToGiftFreeTrialStart.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetFreeMeetingUpgradeToGiftFreeTrialStartCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the callback of ending upgrade the free meeting by the gift link.
	/// \param 1. callback(function)  The callback of ending upgrade the free meeting by the gift link, onFreeMeetingUpgradeToGiftFreeTrialStop.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetFreeMeetingUpgradeToGiftFreeTrialStopCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the callback of free meting upgrades successfully.
	/// \param 1. callback(function)  The callback of free meting upgrades successfully, onFreeMeetingUpgradeToProMeeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SetFreeMeetingUpgradeToProMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingConfigCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingConfigCtrlWrap"));
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInviteButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableInviteButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFloatVideoPos", ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetBottomFloatToolbarWndVisibility", ZoomNodeMeetingConfigCtrlWrap::SetBottomFloatToolbarWndVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSharingToolbarVisibility", ZoomNodeMeetingConfigCtrlWrap::SetSharingToolbarVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDirectShareMonitorID", ZoomNodeMeetingConfigCtrlWrap::SetDirectShareMonitorID);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingUIPos", ZoomNodeMeetingConfigCtrlWrap::SetMeetingUIPos);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableWaitingForHostDialog", ZoomNodeMeetingConfigCtrlWrap::DisableWaitingForHostDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideMeetingInfoFromMeetingUITitle", ZoomNodeMeetingConfigCtrlWrap::HideMeetingInfoFromMeetingUITitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMeetingIDForMeetingUITitle", ZoomNodeMeetingConfigCtrlWrap::SetMeetingIDForMeetingUITitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisablePopupMeetingWrongPSWDlg", ZoomNodeMeetingConfigCtrlWrap::DisablePopupMeetingWrongPSWDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoEndOtherMeetingWhenStartMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableAutoEndOtherMeetingWhenStartMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLButtonDBClick4SwitchFullScreenMode", ZoomNodeMeetingConfigCtrlWrap::EnableLButtonDBClick4SwitchFullScreenMode);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFloatVideoWndVisibility", ZoomNodeMeetingConfigCtrlWrap::SetFloatVideoWndVisibility);
	NODE_SET_PROTOTYPE_METHOD(tpl, "PrePopulateWebinarRegistrationInfo", ZoomNodeMeetingConfigCtrlWrap::PrePopulateWebinarRegistrationInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetReminderType", ZoomNodeMeetingConfigCtrlWrap::GetReminderType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpgradeMeeting", ZoomNodeMeetingConfigCtrlWrap::UpgradeMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpgradeAccount", ZoomNodeMeetingConfigCtrlWrap::UpgradeAccount);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelUpdate", ZoomNodeMeetingConfigCtrlWrap::CancelUpdate);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingNeedToUpgradeCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingNeedToUpgradeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStartCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStartCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStopCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStopCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToProMeetingCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToProMeetingCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingConfigCtrlWrap >() {
	return &ZoomNodeMeetingConfigCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
