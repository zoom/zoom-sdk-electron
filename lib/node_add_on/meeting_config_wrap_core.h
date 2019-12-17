#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"


class ZMeetingConfigWrap
{
public:
	ZMeetingConfigWrap();
	virtual ~ZMeetingConfigWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingConfigWrapFreemeetingSink* pSink);

	ZNSDKError EnableInviteButtonOnMeetingUI(bool bEnable);
	void SetFloatVideoPos(ZNWndPosition position);
	void SetBottomFloatToolbarWndVisibility(bool bShow);
	void SetSharingToolbarVisibility(bool bShow);
	void SetDirectShareMonitorID(ZoomSTRING monitorID);
	void SetMeetingUIPos(ZNWndPosition position);
	void DisableWaitingForHostDialog(bool bDisable);
	void HideMeetingInfoFromMeetingUITitle(bool bHide);
	void SetMeetingIDForMeetingUITitle(unsigned long long meetingNumber);
	void DisablePopupMeetingWrongPSWDlg(bool bDisable);
	void EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable);
	void EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable);
	void SetFloatVideoWndVisibility(bool bShow);
	void PrePopulateWebinarRegistrationInfo(ZoomSTRING email, ZoomSTRING userName);

	void Reset();
	void EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bool bEnable);
	void EnableAutoAdjustMicVolumeWhenJoinAudio(bool bEnable);
	void ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset);
	
	void EnableHideFullPhoneNumber4PureCallinUser(bool bHide);
	void EnableLengthLimitationOfMeetingNumber(bool bEnable);
	void EnableShareIOSDevice(bool bEnable);
	void EnableShareWhiteBoard(bool bEnable);
	void ForceDisableMultiShare(bool bDisable);
	void SetMaxDurationForOnlyHostInMeeting(int nDuration);
	void EnableLocalRecordingConvertProgressBarDialog(bool bShow);

	void EnableApproveRemoteControlDlg(bool bEnable);
	void EnableDeclineRemoteControlResponseDlg(bool bEnable);
	void EnableLeaveMeetingOptionForHost(bool bEnable);
	void EnableVideoButtonOnMeetingUI(bool bEnable);
	void EnableAudioButtonOnMeetingUI(bool bEnable);
	void EnableEnterAndExitFullScreenButtonOnMeetingUI(bool bEnable);
	void RedirectClickShareBTNEvent(bool bRedirect);
	void RedirectClickEndMeetingBTNEvent(bool bRedirect);
	void RedirectFreeMeetingEndingReminderDlg(bool bRedirect);
	void RedirectClickCustomLiveStreamMenuEvent(bool bRedirect);
	void RedirectClickParticipantListBTNEvent(bool bRedirect);
	void RedirectClickCCBTNEvent(bool bRedirect);
	void RedirectClickAudioBTNEvent(bool bRedirect);
	void RedirectClickAudioMenuBTNEvent(bool bRedirect);
	void RedirectMeetingWarningMsg(ZNZoomRedirectWarningMsgOption redirectOption);
	void EnableToolTipsShow(bool bEnable);
	void EnableAirplayInstructionWindow(bool bEnable);
	void EnableClaimHostFeature(bool bEnable);
	void EnableAutoHideJoinAudioDialog(bool bEnable);
	void AlwaysShowIconOnTaskBar(bool bAlwaysShow);
	void DisableSplitScreenModeUIElements(bool bDisable);
	void SetShowAudioUseComputerSoundChkbox(bool bShow);
	void SetShowCallInTab(bool bShow);
	void SetShowCallMeTab(bool bShow);
	void SetAlwaysShowMeetingIDOnTitle(bool bAlwaysShow);
	void DisableTopMostAttr4SettingDialog(bool bDisable);
	void EnableGrabShareWithoutReminder(bool bEnable);
	void EnableShowShareSwitchMultiToSingleConfirmDlg(bool bEnable);
	void DisableFreeMeetingRemainTimeNotify(bool bDisable);
	void HideChatItemOnMeetingUI(bool bHide);
	void HideRecordItemOnMeetingUI(bool bHide);
	void HideUpgradeFreeMeetingButton(bool bHide);
	void SetShowInviteDlgTabPage(ZNSDKInviteDlgTabPage tabPage, bool bShow);
	void SetShowH323SubTabPage(ZNSDKH323TabPage tabPage, bool bShow);
	void HideUpgradeWarningMsgForFreeUserWhenSchedule(bool bHide);
	void HideSwitchCameraButton(bool bHide);
	void HideCopyUrlOnInviteWindow(bool bHide);
	void HideCopyInvitationOnInviteWindow(bool bHide);
	void HideKeypadButtonOnMeetingWindow(bool bHide);
	void HideRemoteControlOnMeetingUI(bool bHide);
	void HideQAOnMeetingUI(bool bHide);
	void HidePollOnMeetingUI(bool bHide);
	void EnableInputMeetingPasswordDlg(bool bEnable);
	void EnableInputMeetingScreenNameDlg(bool bEnable);
	void RedirectWebinarNeedRegister(bool bRedirect);
	void RedirectEndOtherMeeting(bool bRedirect);
	void EnableForceAutoStartMyVideoWhenJoinMeeting(bool bEnable);
	void EnableForceAutoStopMyVideoWhenJoinMeeting(bool bEnable);
	void DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bool bDisable);
	void DisableShowJoinMeetingWnd(bool bDisable);
	void DisableRemoteCtrlCopyPasteFeature(bool bDisable);

	void SetShowVideoOptimizeChkbox(bool bShow);
	ZNRequiredInfoType GetRequiredInfoType();
	bool InputMeetingPasswordAndScreenName(ZoomSTRING meetingPassword, ZoomSTRING screenName);
	bool InputMeetingIDAndScreenName(ZoomSTRING meetingID, ZoomSTRING screenName);
	bool InputMeetingScreenName(ZoomSTRING screenName);
	void MeetingPasswordAndScreenNameHandler_Cancel();// not a good name
	ZNWebinarNeedRegisterType GetWebinarNeedRegisterType();
	ZoomSTRING GetWebinarRegisterUrl();
	void ReleaseRegisterWebinarByUrl();//not a good name
	ZNSDKError InputWebinarRegisterEmailAndScreenName(ZoomSTRING email, ZoomSTRING screenName);
	void CancelRegisterWebinarByEmail();

	ZNFreeMeetingEndingReminderType GetReminderType();
	ZNSDKError UpgradeMeeting();
	ZNSDKError UpgradeAccount();
	ZNSDKError CancelUpdate();

	//callback
	void onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url);
	void onFreeMeetingUpgradeToGiftFreeTrialStart();
	void onFreeMeetingUpgradeToGiftFreeTrialStop();
	void onFreeMeetingUpgradeToProMeeting();

	void onInputMeetingPasswordAndScreenNameNotification();
	void onAirPlayInstructionWndNotification(bool bShow, ZoomSTRING airhostName);
	void onWebinarNeedRegisterNotification();
	void onEndOtherMeetingToJoinMeetingNotification();
	void onFreeMeetingRemainTime(unsigned int leftTime);
	void onFreeMeetingRemainTimeStopCountDown();

private:
	ZNativeSDKMeetingConfigWrapFreemeetingSink* m_pSink;
};
