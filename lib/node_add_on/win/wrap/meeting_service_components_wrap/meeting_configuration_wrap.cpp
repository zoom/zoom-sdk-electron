#include "meeting_configuration_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingConfiguration* InitIMeetingConfigurationFunc(IMeetingConfigurationEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingConfiguration* pObj = pOwner->GetSDKObj()->GetMeetingConfiguration();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}
void UninitIMeetingConfigurationFunc(IMeetingConfiguration* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

IMPL_FUNC_NORET_0(IMeetingConfiguration, Reset, void)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetFloatVideoPos, void, WndPosition, pos)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetSharingToolbarVisibility, void, bool, bShow)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetBottomFloatToolbarWndVisibility, void, bool, bShow)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetDirectShareMonitorID, void, const wchar_t*, monitorID)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetMeetingUIPos, void, WndPosition, pos)
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisableWaitingForHostDialog, void, bool, bDisable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisablePopupMeetingWrongPSWDlg, void, bool, bDisable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAutoEndOtherMeetingWhenStartMeeting, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAutoAdjustSpeakerVolumeWhenJoinAudio, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAutoAdjustMicVolumeWhenJoinAudio, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableApproveRemoteControlDlg, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableDeclineRemoteControlResponseDlg, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableLeaveMeetingOptionForHost, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableInviteButtonOnMeetingUI, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableVideoButtonOnMeetingUI, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAudioButtonOnMeetingUI, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableInputMeetingPasswordDlg, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableEnterAndExitFullScreenButtonOnMeetingUI, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableLButtonDBClick4SwitchFullScreenMode, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,SetFloatVideoWndVisibility, void, bool, bShow)
IMPL_FUNC_NORET_2(IMeetingConfiguration,PrePopulateWebinarRegistrationInfo, void, const wchar_t*, email, const wchar_t*, username)
IMPL_FUNC_NORET_1(IMeetingConfiguration,RedirectClickShareBTNEvent, void, bool, bRedirect)
IMPL_FUNC_NORET_1(IMeetingConfiguration,RedirectClickEndMeetingBTNEvent, void, bool, bRedirect)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableToolTipsShow, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableAirplayInstructionWindow, void, bool, bEnable)
IMPL_FUNC_NORET_1(IMeetingConfiguration,EnableClaimHostFeature, void, bool, bEnable)

IMPL_FUNC_NORET_1(IMeetingConfiguration, HideSwitchCameraButton, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideCopyUrlOnInviteWindow, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideCopyInvitationOnInviteWindow, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideKeypadButtonOnMeetingWindow, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideRemoteControlOnMeetingUI, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideQAOnMeetingUI, void, bool, bHide)
IMPL_FUNC_NORET_1(IMeetingConfiguration, HidePollOnMeetingUI, void, bool, bHide)

//virtual void HideReactionsOnMeetingUI(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideReactionsOnMeetingUI, void, bool, bHide)
//virtual void HideMeetingInfoOnMeetingUI(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideMeetingInfoOnMeetingUI, void, bool, bHide)
//virtual void HideShareButtonOnMeetingUI(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideShareButtonOnMeetingUI, void, bool, bHide)
//virtual void DisablePanelistMenuItem(PanelistMenuItemOption menuOption) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, DisablePanelistMenuItem, void, PanelistMenuItemOption, menuOption)
//virtual void DisableAttendeeMenuItem(AttendeeMenuItemOption menuOption) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, DisableAttendeeMenuItem, void, AttendeeMenuItemOption, menuOption)

//virtual void ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset) = 0;
IMPL_FUNC_NORET_3(IMeetingConfiguration,ConfigDSCP, void, int, dscpAudio, int, dscpVideo, bool, bReset)
//virtual void RedirectClickParticipantListBTNEvent(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration,RedirectClickParticipantListBTNEvent, void, bool, bRedirect)
//virtual void DisableRemoteCtrlCopyPasteFeature(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisableRemoteCtrlCopyPasteFeature, void, bool, bDisable)
//virtual void DisableSplitScreenModeUIElements(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration,DisableSplitScreenModeUIElements, void, bool, bDisable)
//virtual void EnableAutoHideJoinAudioDialog(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableAutoHideJoinAudioDialog, void, bool, bEnable)
//virtual void EnableHideFullPhoneNumber4PureCallinUser(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableHideFullPhoneNumber4PureCallinUser, void, bool, bEnable)

//virtual void EnableLengthLimitationOfMeetingNumber(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableLengthLimitationOfMeetingNumber, void, bool, bEnable)
//virtual void EnableShareIOSDevice(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableShareIOSDevice, void, bool, bEnable)

//virtual void EnableShareWhiteBoard(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableShareWhiteBoard, void, bool, bEnable)
//virtual void AlwaysShowIconOnTaskBar(bool bAlwaysShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, AlwaysShowIconOnTaskBar, void, bool, bAlwaysShow)
//virtual void RedirectFreeMeetingEndingReminderDlg(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectFreeMeetingEndingReminderDlg, void, bool, bRedirect)
//virtual void SetShowAudioUseComputerSoundChkbox(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowAudioUseComputerSoundChkbox, void, bool, bShow)
//virtual void SetShowVideoOptimizeChkbox(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowVideoOptimizeChkbox, void, bool, bShow)
//virtual void SetShowCallInTab(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowCallInTab, void, bool, bShow)
//virtual void SetShowCallMeTab(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetShowCallMeTab, void, bool, bShow)
//virtual void ForceDisableMultiShare(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, ForceDisableMultiShare, void, bool, bDisable)
//virtual void RedirectClickCustomLiveStreamMenuEvent(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectClickCustomLiveStreamMenuEvent, void, bool, bRedirect)
//virtual void RedirectClickAudioBTNEvent(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectClickAudioBTNEvent, void, bool, bRedirect)
//virtual void RedirectClickAudioMenuBTNEvent(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectClickAudioMenuBTNEvent, void, bool, bRedirect)
//virtual void RedirectClickCCBTNEvent(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectClickCCBTNEvent, void, bool, bRedirect)
//virtual SDKError SetUICustomizedString(SDKCustomizedStringType customizedType, const wchar_t* customizedString) = 0;
IMPL_FUNC_2(IMeetingConfiguration, SetUICustomizedString, SDKError, SDKCustomizedStringType, customizedType, const wchar_t*, customizedString, SDKERR_UNINITIALIZE)
//virtual SDKError DisableTopMostAttr4SettingDialog(bool bDisable) = 0;
IMPL_FUNC_1(IMeetingConfiguration, DisableTopMostAttr4SettingDialog, SDKError, bool, bDisable, SDKERR_UNINITIALIZE)
//virtual SDKError EnableGrabShareWithoutReminder(bool bEnable) = 0;
IMPL_FUNC_1(IMeetingConfiguration, EnableGrabShareWithoutReminder, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual void EnableShowShareSwitchMultiToSingleConfirmDlg(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableShowShareSwitchMultiToSingleConfirmDlg, void, bool, bEnable)
//virtual void DisableFreeMeetingRemainTimeNotify(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, DisableFreeMeetingRemainTimeNotify, void, bool, bDisable)
//virtual void HideChatItemOnMeetingUI(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideChatItemOnMeetingUI, void, bool, bHide)
//virtual void HideRecordItemOnMeetingUI(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideRecordItemOnMeetingUI, void, bool, bHide)
//virtual void HideUpgradeFreeMeetingButton(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideUpgradeFreeMeetingButton, void, bool, bHide)
//virtual void SetShowInviteDlgTabPage(SDKInviteDlgTabPage tabPage, bool bShow) = 0;
IMPL_FUNC_NORET_2(IMeetingConfiguration, SetShowInviteDlgTabPage, void, SDKInviteDlgTabPage, tabPage, bool, bShow)
//virtual void SetShowH323SubTabPage(SDKH323TabPage tabPage, bool bShow) = 0;
IMPL_FUNC_NORET_2(IMeetingConfiguration, SetShowH323SubTabPage, void, SDKH323TabPage, tabPage, bool, bShow)
//virtual void RedirectMeetingWarningMsg(RedirectWarningMsgOption redirectOption) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectMeetingWarningMsg, void, RedirectWarningMsgOption, redirectOption)
//virtual void HideUpgradeWarningMsgForFreeUserWhenSchedule(bool bHide) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, HideUpgradeWarningMsgForFreeUserWhenSchedule, void, bool, bHide)
//virtual void EnableLocalRecordingConvertProgressBarDialog(bool bShow) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableLocalRecordingConvertProgressBarDialog, void, bool, bShow)

//virtual void EnableInputMeetingScreenNameDlg(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableInputMeetingScreenNameDlg, void, bool, bEnable)
//virtual void RedirectWebinarNeedRegister(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectWebinarNeedRegister, void, bool, bRedirect)
//virtual void RedirectEndOtherMeeting(bool bRedirect) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, RedirectEndOtherMeeting, void, bool, bRedirect)
//virtual void EnableForceAutoStartMyVideoWhenJoinMeeting(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableForceAutoStartMyVideoWhenJoinMeeting, void, bool, bEnable)
//virtual void EnableForceAutoStopMyVideoWhenJoinMeeting(bool bEnable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, EnableForceAutoStopMyVideoWhenJoinMeeting, void, bool, bEnable)
//virtual void DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting, void, bool, bDisable)
//virtual void DisableShowJoinMeetingWnd(bool bDisable) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, DisableShowJoinMeetingWnd, void, bool, bDisable)
//virtual void SetMaxDurationForOnlyHostInMeeting(int nDuration) = 0;
IMPL_FUNC_NORET_1(IMeetingConfiguration, SetMaxDurationForOnlyHostInMeeting, void, int, nDuration)

END_ZOOM_SDK_NAMESPACE