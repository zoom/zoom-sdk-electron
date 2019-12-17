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
	/// \brief Set the position of the floating video window when sharing. 
	/// \param 1. left(string) Specifies the X-axis coordinate of the top-left corner of the window
	/// \param 2. top(string) Specifies the Y-axis coordinate of the top-left of the window.	/// \param 3. Just for Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	/// \param 4. Just for Windows: hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
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
	/// \param 1. left(string) Specifies the X-axis coordinate of the top-left corner of the window
	/// \param 2. top(string) Specifies the Y-axis coordinate of the top-left of the window.
	/// \param 3. Just for Windows: hSelfWnd(string) Specifies the window handle of the window itself.
	/// \param 4. Just for Windows: hParent(string) Specifies the window handle of the parent window. If the string is empty, the position coordinate is the monitor coordinate.
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

	/// \brief Reset the meeting configuration and back to the default state.
	static void Reset(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to auto-adjust the volume of the speaker when joining the meeting. 
	/// \param 1.bEnable(bool) TRUE indicates to auto-adjust the volume of the speaker. FALSE not.
	/// \remarks If it is TRUE, the SDK will adjust the speaker volume automatically. It will unmute if the speaker was muted.
	static void EnableAutoAdjustSpeakerVolumeWhenJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to auto-adjust the volume of the mic when joining the meeting. 
	/// \param 1.bEnable(bool) TRUE indicates to auto-adjust the volume of the mic. FALSE not.
	/// \remarks If it is TRUE, the SDK will adjust the mic volume automatically. It will unmute if the mic was muted.
	static void EnableAutoAdjustMicVolumeWhenJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Configure DSCP(Differential services code point) values.  
	/// \param 1.dscpAudio(number) Configure DSCP value for audio.
	/// \param 2.dscpVideo(number) Configure DSCP value for video.
	/// \param 3.bReset(bool) Reset DSCP values. This param is just used for Windows. For Mac, you can pass TRUE or FALSE as you like.
	/// \remarks This interface satisfies some users who have other requirements. It is not recommended to configure it. Contact the support engineer for more details. 
	static void ConfigDSCP(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to display the full phone number for the user who joins the meeting with phone. Default: FALSE.
	/// \param 1.bHide(bool) TRUE indicates to hide the partial phone number. FALSE not. 
	/// \remarks If it is false, some figures of the number will be replaced by asterisk(*).
	static void EnableHideFullPhoneNumber4PureCallinUser(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to limit the length of meeting ID. Default: FALSE.
	/// \param 1.bEnable(bool) TRUE indicates to limit the length of meeting ID. FALSE not.
	/// \remarks If it is enabled, the length of the meeting ID depends on the ID type. The ID shall be more than nine(9) figures or five(5) letters.
	static void EnableLengthLimitationOfMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to share IOS device. Default: FALSE.
	/// \param 1.bEnable(bool) TRUE indicates to enable to share. FALSE not.
	static void EnableShareIOSDevice(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set if it is able to share white board. Default: TRUE.
	/// \param 1.bEnable(bool) TRUE indicates to enable to share on the white board. FALSE not.
	static void EnableShareWhiteBoard(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set whether to forbid multi-share. Default: FALSE.
	/// \param 1.bDisable(bool) TRUE indicates to forbid multi-share. FALSE not.
	static void ForceDisableMultiShare(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the maximum duration of the meeting when there is no attendee in the meeting. Default: 24*60.
	/// \param 1.nDuration(number) Specify the maximum duration in minutes.
	static void SetMaxDurationForOnlyHostInMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Set the visibility of the local recording convert progress bar dialog. Default: TRUE. 
	/// \param bShow TRUE indicates to show the dialog box. FALSE not.
	static void EnableLocalRecordingConvertProgressBarDialog(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableApproveRemoteControlDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableDeclineRemoteControlResponseDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableLeaveMeetingOptionForHost(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableVideoButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAudioButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableEnterAndExitFullScreenButtonOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickShareBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickEndMeetingBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectFreeMeetingEndingReminderDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickCustomLiveStreamMenuEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickParticipantListBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickCCBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickAudioBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectClickAudioMenuBTNEvent(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectMeetingWarningMsg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableToolTipsShow(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAirplayInstructionWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableClaimHostFeature(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableAutoHideJoinAudioDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void AlwaysShowIconOnTaskBar(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableSplitScreenModeUIElements(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetShowAudioUseComputerSoundChkbox(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetShowCallInTab(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetShowCallMeTab(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetAlwaysShowMeetingIDOnTitle(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableTopMostAttr4SettingDialog(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableGrabShareWithoutReminder(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableShowShareSwitchMultiToSingleConfirmDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableFreeMeetingRemainTimeNotify(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideChatItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideRecordItemOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideUpgradeFreeMeetingButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetShowInviteDlgTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetShowH323SubTabPage(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideUpgradeWarningMsgForFreeUserWhenSchedule(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideSwitchCameraButton(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideCopyUrlOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideCopyInvitationOnInviteWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideKeypadButtonOnMeetingWindow(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideRemoteControlOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HideQAOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void HidePollOnMeetingUI(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableInputMeetingPasswordDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableInputMeetingScreenNameDlg(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectWebinarNeedRegister(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void RedirectEndOtherMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableForceAutoStartMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void EnableForceAutoStopMyVideoWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableShowJoinMeetingWnd(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void DisableRemoteCtrlCopyPasteFeature(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SetShowVideoOptimizeChkbox(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetRequiredInfoType(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void InputMeetingPasswordAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void InputMeetingIDAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void InputMeetingScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void MeetingPasswordAndScreenNameHandler_Cancel(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetWebinarNeedRegisterType(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetWebinarRegisterUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void ReleaseRegisterWebinarByUrl(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void InputWebinarRegisterEmailAndScreenName(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void CancelRegisterWebinarByEmail(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetInputMeetingPasswordAndScreenNameNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetAirPlayInstructionWndNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonWebinarNeedRegisterNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonEndOtherMeetingToJoinMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonFreeMeetingRemainTimeCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetonFreeMeetingRemainTimeStopCountDownCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	//
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeMeetingConfigCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeMeetingConfigCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
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

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableApproveRemoteControlDlg", ZoomNodeMeetingConfigCtrlWrap::EnableApproveRemoteControlDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableDeclineRemoteControlResponseDlg", ZoomNodeMeetingConfigCtrlWrap::EnableDeclineRemoteControlResponseDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLeaveMeetingOptionForHost", ZoomNodeMeetingConfigCtrlWrap::EnableLeaveMeetingOptionForHost);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableVideoButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableVideoButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAudioButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableAudioButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableEnterAndExitFullScreenButtonOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickShareBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickShareBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickEndMeetingBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickEndMeetingBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectFreeMeetingEndingReminderDlg", ZoomNodeMeetingConfigCtrlWrap::RedirectFreeMeetingEndingReminderDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickCustomLiveStreamMenuEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickCustomLiveStreamMenuEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickParticipantListBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickParticipantListBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickCCBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickCCBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickAudioBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectClickAudioMenuBTNEvent", ZoomNodeMeetingConfigCtrlWrap::RedirectClickAudioMenuBTNEvent);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectMeetingWarningMsg", ZoomNodeMeetingConfigCtrlWrap::RedirectMeetingWarningMsg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableToolTipsShow", ZoomNodeMeetingConfigCtrlWrap::EnableToolTipsShow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAirplayInstructionWindow", ZoomNodeMeetingConfigCtrlWrap::EnableAirplayInstructionWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableClaimHostFeature", ZoomNodeMeetingConfigCtrlWrap::EnableClaimHostFeature);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoHideJoinAudioDialog", ZoomNodeMeetingConfigCtrlWrap::EnableAutoHideJoinAudioDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "AlwaysShowIconOnTaskBar", ZoomNodeMeetingConfigCtrlWrap::AlwaysShowIconOnTaskBar);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableSplitScreenModeUIElements", ZoomNodeMeetingConfigCtrlWrap::DisableSplitScreenModeUIElements);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowAudioUseComputerSoundChkbox", ZoomNodeMeetingConfigCtrlWrap::SetShowAudioUseComputerSoundChkbox);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowCallInTab", ZoomNodeMeetingConfigCtrlWrap::SetShowCallInTab);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowCallMeTab", ZoomNodeMeetingConfigCtrlWrap::SetShowCallMeTab);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetAlwaysShowMeetingIDOnTitle", ZoomNodeMeetingConfigCtrlWrap::SetAlwaysShowMeetingIDOnTitle);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableTopMostAttr4SettingDialog", ZoomNodeMeetingConfigCtrlWrap::DisableTopMostAttr4SettingDialog);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableGrabShareWithoutReminder", ZoomNodeMeetingConfigCtrlWrap::EnableGrabShareWithoutReminder);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShowShareSwitchMultiToSingleConfirmDlg", ZoomNodeMeetingConfigCtrlWrap::EnableShowShareSwitchMultiToSingleConfirmDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableFreeMeetingRemainTimeNotify", ZoomNodeMeetingConfigCtrlWrap::DisableFreeMeetingRemainTimeNotify);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideChatItemOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideChatItemOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideRecordItemOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideRecordItemOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideUpgradeFreeMeetingButton", ZoomNodeMeetingConfigCtrlWrap::HideUpgradeFreeMeetingButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowInviteDlgTabPage", ZoomNodeMeetingConfigCtrlWrap::SetShowInviteDlgTabPage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowH323SubTabPage", ZoomNodeMeetingConfigCtrlWrap::SetShowH323SubTabPage);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideUpgradeWarningMsgForFreeUserWhenSchedule", ZoomNodeMeetingConfigCtrlWrap::HideUpgradeWarningMsgForFreeUserWhenSchedule);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideSwitchCameraButton", ZoomNodeMeetingConfigCtrlWrap::HideSwitchCameraButton);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCopyUrlOnInviteWindow", ZoomNodeMeetingConfigCtrlWrap::HideCopyUrlOnInviteWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideCopyInvitationOnInviteWindow", ZoomNodeMeetingConfigCtrlWrap::HideCopyInvitationOnInviteWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideKeypadButtonOnMeetingWindow", ZoomNodeMeetingConfigCtrlWrap::HideKeypadButtonOnMeetingWindow);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideRemoteControlOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideRemoteControlOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HideQAOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HideQAOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "HidePollOnMeetingUI", ZoomNodeMeetingConfigCtrlWrap::HidePollOnMeetingUI);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInputMeetingPasswordDlg", ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingPasswordDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableInputMeetingScreenNameDlg", ZoomNodeMeetingConfigCtrlWrap::EnableInputMeetingScreenNameDlg);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectWebinarNeedRegister", ZoomNodeMeetingConfigCtrlWrap::RedirectWebinarNeedRegister);
	NODE_SET_PROTOTYPE_METHOD(tpl, "RedirectEndOtherMeeting", ZoomNodeMeetingConfigCtrlWrap::RedirectEndOtherMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableForceAutoStartMyVideoWhenJoinMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStartMyVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableForceAutoStopMyVideoWhenJoinMeeting", ZoomNodeMeetingConfigCtrlWrap::EnableForceAutoStopMyVideoWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting", ZoomNodeMeetingConfigCtrlWrap::DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableShowJoinMeetingWnd", ZoomNodeMeetingConfigCtrlWrap::DisableShowJoinMeetingWnd);
	NODE_SET_PROTOTYPE_METHOD(tpl, "DisableRemoteCtrlCopyPasteFeature", ZoomNodeMeetingConfigCtrlWrap::DisableRemoteCtrlCopyPasteFeature);

	NODE_SET_PROTOTYPE_METHOD(tpl, "PrePopulateWebinarRegistrationInfo", ZoomNodeMeetingConfigCtrlWrap::PrePopulateWebinarRegistrationInfo);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetReminderType", ZoomNodeMeetingConfigCtrlWrap::GetReminderType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpgradeMeeting", ZoomNodeMeetingConfigCtrlWrap::UpgradeMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "UpgradeAccount", ZoomNodeMeetingConfigCtrlWrap::UpgradeAccount);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelUpdate", ZoomNodeMeetingConfigCtrlWrap::CancelUpdate);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingNeedToUpgradeCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingNeedToUpgradeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStartCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStartCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToGiftFreeTrialStopCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToGiftFreeTrialStopCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetFreeMeetingUpgradeToProMeetingCB", ZoomNodeMeetingConfigCtrlWrap::SetFreeMeetingUpgradeToProMeetingCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "Reset", ZoomNodeMeetingConfigCtrlWrap::Reset);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoAdjustSpeakerVolumeWhenJoinAudio", ZoomNodeMeetingConfigCtrlWrap::EnableAutoAdjustSpeakerVolumeWhenJoinAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoAdjustMicVolumeWhenJoinAudio", ZoomNodeMeetingConfigCtrlWrap::EnableAutoAdjustMicVolumeWhenJoinAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ConfigDSCP", ZoomNodeMeetingConfigCtrlWrap::ConfigDSCP);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHideFullPhoneNumber4PureCallinUser", ZoomNodeMeetingConfigCtrlWrap::EnableHideFullPhoneNumber4PureCallinUser);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLengthLimitationOfMeetingNumber", ZoomNodeMeetingConfigCtrlWrap::EnableLengthLimitationOfMeetingNumber);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShareIOSDevice", ZoomNodeMeetingConfigCtrlWrap::EnableShareIOSDevice);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableShareWhiteBoard", ZoomNodeMeetingConfigCtrlWrap::EnableShareWhiteBoard);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ForceDisableMultiShare", ZoomNodeMeetingConfigCtrlWrap::ForceDisableMultiShare);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMaxDurationForOnlyHostInMeeting", ZoomNodeMeetingConfigCtrlWrap::SetMaxDurationForOnlyHostInMeeting);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableLocalRecordingConvertProgressBarDialog", ZoomNodeMeetingConfigCtrlWrap::EnableLocalRecordingConvertProgressBarDialog);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetShowVideoOptimizeChkbox", ZoomNodeMeetingConfigCtrlWrap::SetShowVideoOptimizeChkbox);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetRequiredInfoType", ZoomNodeMeetingConfigCtrlWrap::GetRequiredInfoType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputMeetingPasswordAndScreenName", ZoomNodeMeetingConfigCtrlWrap::InputMeetingPasswordAndScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputMeetingIDAndScreenName", ZoomNodeMeetingConfigCtrlWrap::InputMeetingIDAndScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputMeetingScreenName", ZoomNodeMeetingConfigCtrlWrap::InputMeetingScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "MeetingPasswordAndScreenNameHandler_Cancel", ZoomNodeMeetingConfigCtrlWrap::MeetingPasswordAndScreenNameHandler_Cancel);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWebinarNeedRegisterType", ZoomNodeMeetingConfigCtrlWrap::GetWebinarNeedRegisterType);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetWebinarRegisterUrl", ZoomNodeMeetingConfigCtrlWrap::GetWebinarRegisterUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "ReleaseRegisterWebinarByUrl", ZoomNodeMeetingConfigCtrlWrap::ReleaseRegisterWebinarByUrl);
	NODE_SET_PROTOTYPE_METHOD(tpl, "InputWebinarRegisterEmailAndScreenName", ZoomNodeMeetingConfigCtrlWrap::InputWebinarRegisterEmailAndScreenName);
	NODE_SET_PROTOTYPE_METHOD(tpl, "CancelRegisterWebinarByEmail", ZoomNodeMeetingConfigCtrlWrap::CancelRegisterWebinarByEmail);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetInputMeetingPasswordAndScreenNameNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetInputMeetingPasswordAndScreenNameNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetAirPlayInstructionWndNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetAirPlayInstructionWndNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonWebinarNeedRegisterNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetonWebinarNeedRegisterNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonEndOtherMeetingToJoinMeetingNotificationCB", ZoomNodeMeetingConfigCtrlWrap::SetonEndOtherMeetingToJoinMeetingNotificationCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonFreeMeetingRemainTimeCB", ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetonFreeMeetingRemainTimeStopCountDownCB", ZoomNodeMeetingConfigCtrlWrap::SetonFreeMeetingRemainTimeStopCountDownCB);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeMeetingConfigCtrlWrap >() {
	return &ZoomNodeMeetingConfigCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
