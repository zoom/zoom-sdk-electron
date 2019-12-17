
#include "../meeting_config_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_configuration_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZMeetingConfigWrap::ZMeetingConfigWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingConfigCtrlWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingConfigWrap::~ZMeetingConfigWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingConfigCtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingConfigWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingConfigCtrlWrapEvent);
	
}
void ZMeetingConfigWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().Uninit_Wrap();
}
void ZMeetingConfigWrap::SetSink(ZNativeSDKMeetingConfigWrapFreemeetingSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingConfigWrap::EnableInviteButtonOnMeetingUI(bool bEnable)
{
	ZNSDKError zn_err = ZNSDKERR_SUCCESS;
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableInviteButtonOnMeetingUI(bEnable);
	return zn_err;
}
void ZMeetingConfigWrap::SetFloatVideoPos(ZNWndPosition position)
{
	ZOOM_SDK_NAMESPACE::WndPosition sdk_pos;
	sdk_pos.left = _wtoi(position.z_left.c_str());
	sdk_pos.top = _wtoi(position.z_top.c_str());
	swscanf_s(position.z_hParent.c_str(), L"%x", (unsigned int*)&sdk_pos.hParent);
	swscanf_s(position.z_hSelfWnd.c_str(), L"%x", (unsigned int*)&sdk_pos.hSelfWnd);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetFloatVideoPos(sdk_pos);
}
void ZMeetingConfigWrap::SetBottomFloatToolbarWndVisibility(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetBottomFloatToolbarWndVisibility(bShow);
}
void ZMeetingConfigWrap::SetSharingToolbarVisibility(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetSharingToolbarVisibility(bShow);
}
void ZMeetingConfigWrap::SetDirectShareMonitorID(ZoomSTRING monitorID)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetDirectShareMonitorID(monitorID.c_str());
}
void ZMeetingConfigWrap::SetMeetingUIPos(ZNWndPosition position)
{
	ZOOM_SDK_NAMESPACE::WndPosition sdk_pos;
	sdk_pos.left = _wtoi(position.z_left.c_str());
	sdk_pos.top = _wtoi(position.z_top.c_str());
	swscanf_s(position.z_hParent.c_str(), L"%x", (unsigned int*)&sdk_pos.hParent);
	swscanf_s(position.z_hSelfWnd.c_str(), L"%x", (unsigned int*)&sdk_pos.hSelfWnd);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetMeetingUIPos(sdk_pos);
}
void ZMeetingConfigWrap::DisableWaitingForHostDialog(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableWaitingForHostDialog(bDisable);
}
void ZMeetingConfigWrap::HideMeetingInfoFromMeetingUITitle(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideMeetingInfoFromMeetingUITitle(bHide);
}
void ZMeetingConfigWrap::SetMeetingIDForMeetingUITitle(unsigned long long meetingNumber)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetMeetingIDForMeetingUITitle(meetingNumber);
}
void ZMeetingConfigWrap::DisablePopupMeetingWrongPSWDlg(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisablePopupMeetingWrongPSWDlg(bDisable);
}
void ZMeetingConfigWrap::EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAutoEndOtherMeetingWhenStartMeeting(bEnable);
}
void ZMeetingConfigWrap::EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableLButtonDBClick4SwitchFullScreenMode(bEnable);
}
void ZMeetingConfigWrap::SetFloatVideoWndVisibility(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetFloatVideoWndVisibility(bShow);
}
void ZMeetingConfigWrap::PrePopulateWebinarRegistrationInfo(ZoomSTRING email, ZoomSTRING userName)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().PrePopulateWebinarRegistrationInfo(email.c_str(), userName.c_str());
}

void ZMeetingConfigWrap::Reset()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().Reset();
}
void ZMeetingConfigWrap::EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bEnable);
}
void ZMeetingConfigWrap::EnableAutoAdjustMicVolumeWhenJoinAudio(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAutoAdjustMicVolumeWhenJoinAudio(bEnable);
}
void ZMeetingConfigWrap::ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset)
{
	bool sdk_bReset = true;
	if (bReset)
		sdk_bReset = false;
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().ConfigDSCP(dscpAudio, dscpVideo, sdk_bReset);
}

void ZMeetingConfigWrap::EnableHideFullPhoneNumber4PureCallinUser(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableHideFullPhoneNumber4PureCallinUser(bHide);
}
void ZMeetingConfigWrap::EnableLengthLimitationOfMeetingNumber(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableLengthLimitationOfMeetingNumber(bEnable);
}
void ZMeetingConfigWrap::EnableShareIOSDevice(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableShareIOSDevice(bEnable);
}
void ZMeetingConfigWrap::EnableShareWhiteBoard(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableShareWhiteBoard(bEnable);
}
void ZMeetingConfigWrap::ForceDisableMultiShare(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().ForceDisableMultiShare(bDisable);
}
void ZMeetingConfigWrap::SetMaxDurationForOnlyHostInMeeting(int nDuration)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetMaxDurationForOnlyHostInMeeting(nDuration);
}
void ZMeetingConfigWrap::EnableLocalRecordingConvertProgressBarDialog(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableLocalRecordingConvertProgressBarDialog(bShow);
}


void ZMeetingConfigWrap::EnableApproveRemoteControlDlg(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableApproveRemoteControlDlg(bEnable);
}
void ZMeetingConfigWrap:: EnableDeclineRemoteControlResponseDlg(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableDeclineRemoteControlResponseDlg(bEnable);
}
void ZMeetingConfigWrap:: EnableLeaveMeetingOptionForHost(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableLeaveMeetingOptionForHost(bEnable);
}
void ZMeetingConfigWrap:: EnableVideoButtonOnMeetingUI(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableVideoButtonOnMeetingUI(bEnable);
}
void ZMeetingConfigWrap::EnableAudioButtonOnMeetingUI(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAudioButtonOnMeetingUI(bEnable);
}
void ZMeetingConfigWrap:: EnableEnterAndExitFullScreenButtonOnMeetingUI(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableEnterAndExitFullScreenButtonOnMeetingUI(bEnable);
}
void ZMeetingConfigWrap:: RedirectClickShareBTNEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickShareBTNEvent(bRedirect);
}
void ZMeetingConfigWrap:: RedirectClickEndMeetingBTNEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickEndMeetingBTNEvent(bRedirect);
}
void ZMeetingConfigWrap:: RedirectFreeMeetingEndingReminderDlg(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectFreeMeetingEndingReminderDlg(bRedirect);
}
void ZMeetingConfigWrap:: RedirectClickCustomLiveStreamMenuEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickCustomLiveStreamMenuEvent(bRedirect);
}
void ZMeetingConfigWrap:: RedirectClickParticipantListBTNEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickParticipantListBTNEvent(bRedirect);
}
void ZMeetingConfigWrap:: RedirectClickCCBTNEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickCCBTNEvent(bRedirect);
}
void ZMeetingConfigWrap::RedirectClickAudioBTNEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickAudioBTNEvent(bRedirect);
}
void ZMeetingConfigWrap::RedirectClickAudioMenuBTNEvent(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectClickAudioMenuBTNEvent(bRedirect);
}
void ZMeetingConfigWrap:: RedirectMeetingWarningMsg(ZNZoomRedirectWarningMsgOption redirectOption)
{
	ZOOM_SDK_NAMESPACE::RedirectWarningMsgOption msgOption;
	msgOption.bRedirectBadNetwork = redirectOption.bRedirectBadNetwork;
	msgOption.bRedirectWarnHighCPU = redirectOption.bRedirectWarnHighCPU;
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectMeetingWarningMsg(msgOption);
}
void ZMeetingConfigWrap:: EnableToolTipsShow(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableToolTipsShow(bEnable);
}
void ZMeetingConfigWrap:: EnableAirplayInstructionWindow(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAirplayInstructionWindow(bEnable);
}
void ZMeetingConfigWrap:: EnableClaimHostFeature(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableClaimHostFeature(bEnable);
}
void ZMeetingConfigWrap:: EnableAutoHideJoinAudioDialog(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAutoHideJoinAudioDialog(bEnable);
}
void ZMeetingConfigWrap:: AlwaysShowIconOnTaskBar(bool bAlwaysShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().AlwaysShowIconOnTaskBar(bAlwaysShow);
}
void ZMeetingConfigWrap:: DisableSplitScreenModeUIElements(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableSplitScreenModeUIElements(bDisable);
}
void ZMeetingConfigWrap:: SetShowAudioUseComputerSoundChkbox(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetShowAudioUseComputerSoundChkbox(bShow);
}
void ZMeetingConfigWrap:: SetShowCallInTab(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetShowCallInTab(bShow);
}
void ZMeetingConfigWrap:: SetShowCallMeTab(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetShowCallMeTab(bShow);
}
void ZMeetingConfigWrap:: SetAlwaysShowMeetingIDOnTitle(bool bAlwaysShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetAlwaysShowMeetingIDOnTitle(bAlwaysShow);
}
void ZMeetingConfigWrap:: DisableTopMostAttr4SettingDialog(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableTopMostAttr4SettingDialog(bDisable);
}
void ZMeetingConfigWrap:: EnableGrabShareWithoutReminder(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableGrabShareWithoutReminder(bEnable);
}
void ZMeetingConfigWrap:: EnableShowShareSwitchMultiToSingleConfirmDlg(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableShowShareSwitchMultiToSingleConfirmDlg(bEnable);
}
void ZMeetingConfigWrap:: DisableFreeMeetingRemainTimeNotify(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableFreeMeetingRemainTimeNotify(bDisable);
}
void ZMeetingConfigWrap:: HideChatItemOnMeetingUI(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideChatItemOnMeetingUI(bHide);
}
void ZMeetingConfigWrap:: HideRecordItemOnMeetingUI(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideRecordItemOnMeetingUI(bHide);
}
void ZMeetingConfigWrap:: HideUpgradeFreeMeetingButton(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideUpgradeFreeMeetingButton(bHide);
}
void ZMeetingConfigWrap:: SetShowInviteDlgTabPage(ZNSDKInviteDlgTabPage tabPage, bool bShow)
{
	ZOOM_SDK_NAMESPACE::SDKInviteDlgTabPage tab_page;
	switch (tabPage)
	{
		case SDK_INVITEDLG_TAB_EMAILCONTACT:
			tab_page = ZOOM_SDK_NAMESPACE::SDK_INVITEDLG_TAB_EMAILCONTACT;
			break;
		case SDK_INVITEDLG_TAB_PHONECONTACT:
			tab_page = ZOOM_SDK_NAMESPACE::SDK_INVITEDLG_TAB_PHONECONTACT;
			break;
		case SDK_INVITEDLG_TAB_ROOMSYSTEM:
			tab_page = ZOOM_SDK_NAMESPACE::SDK_INVITEDLG_TAB_ROOMSYSTEM;
			break;
		default:
				break;
	}
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetShowInviteDlgTabPage(tab_page, bShow);
}
void ZMeetingConfigWrap:: SetShowH323SubTabPage(ZNSDKH323TabPage tabPage, bool bShow)
{
	ZOOM_SDK_NAMESPACE::SDKH323TabPage tab_page;
	switch (tabPage)
	{
	case SDK_INVITEDLG_H323_DIALIN:
		tab_page = ZOOM_SDK_NAMESPACE::SDK_INVITEDLG_H323_DIALIN;
		break;
	case SDK_INVITEDLG_H323_CALLOUT:
		tab_page = ZOOM_SDK_NAMESPACE::SDK_INVITEDLG_H323_CALLOUT;
		break;
	default:
		break;
	}
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetShowH323SubTabPage(tab_page, bShow);
}
void ZMeetingConfigWrap:: HideUpgradeWarningMsgForFreeUserWhenSchedule(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideUpgradeWarningMsgForFreeUserWhenSchedule(bHide);
}
void ZMeetingConfigWrap:: HideSwitchCameraButton(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideSwitchCameraButton(bHide);
}
void ZMeetingConfigWrap:: HideCopyUrlOnInviteWindow(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideCopyUrlOnInviteWindow(bHide);
}
void ZMeetingConfigWrap:: HideCopyInvitationOnInviteWindow(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideCopyInvitationOnInviteWindow(bHide);
}
void ZMeetingConfigWrap:: HideKeypadButtonOnMeetingWindow(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideKeypadButtonOnMeetingWindow(bHide);
}
void ZMeetingConfigWrap:: HideRemoteControlOnMeetingUI(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideRemoteControlOnMeetingUI(bHide);
}
void ZMeetingConfigWrap:: HideQAOnMeetingUI(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideQAOnMeetingUI(bHide);
}
void ZMeetingConfigWrap:: HidePollOnMeetingUI(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HidePollOnMeetingUI(bHide);
}
void ZMeetingConfigWrap:: EnableInputMeetingPasswordDlg(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableInputMeetingPasswordDlg(bEnable);
}
void ZMeetingConfigWrap:: EnableInputMeetingScreenNameDlg(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableInputMeetingScreenNameDlg(bEnable);
}
void ZMeetingConfigWrap:: RedirectWebinarNeedRegister(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectWebinarNeedRegister(bRedirect);
}
void ZMeetingConfigWrap:: RedirectEndOtherMeeting(bool bRedirect)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().RedirectEndOtherMeeting(bRedirect);
}
void ZMeetingConfigWrap:: EnableForceAutoStartMyVideoWhenJoinMeeting(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableForceAutoStartMyVideoWhenJoinMeeting(bEnable);
}
void ZMeetingConfigWrap:: EnableForceAutoStopMyVideoWhenJoinMeeting(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableForceAutoStopMyVideoWhenJoinMeeting(bEnable);
}
void ZMeetingConfigWrap:: DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bDisable);
}
void ZMeetingConfigWrap::DisableShowJoinMeetingWnd(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableShowJoinMeetingWnd(bDisable);
}
void ZMeetingConfigWrap:: DisableRemoteCtrlCopyPasteFeature(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableRemoteCtrlCopyPasteFeature(bDisable);
}


ZNFreeMeetingEndingReminderType ZMeetingConfigWrap::GetReminderType()
{
	return  FreeMeetingReminderHandler::GetInst().GetType();
}
ZNSDKError ZMeetingConfigWrap::UpgradeMeeting()
{
	return  Map2WrapDefine(FreeMeetingReminderHandler::GetInst().UpgradeMeeting());
}
ZNSDKError ZMeetingConfigWrap::UpgradeAccount()
{
	return  Map2WrapDefine(FreeMeetingReminderHandler::GetInst().UpgradeAccount());
}
ZNSDKError ZMeetingConfigWrap::CancelUpdate()
{
	return  Map2WrapDefine(FreeMeetingReminderHandler::GetInst().Cancel());
}

void ZMeetingConfigWrap::onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url)
{
	if (m_pSink)
		m_pSink->onFreeMeetingNeedToUpgrade(type, gift_url);
}
void ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStart()
{
	if (m_pSink)
		m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStart();
}
void ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStop()
{
	if (m_pSink)
		m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStop();
}
void ZMeetingConfigWrap::onFreeMeetingUpgradeToProMeeting()
{
	if (m_pSink)
		m_pSink->onFreeMeetingUpgradeToProMeeting();
}

void ZMeetingConfigWrap::SetShowVideoOptimizeChkbox(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetShowVideoOptimizeChkbox(bShow);
}
ZNRequiredInfoType ZMeetingConfigWrap::GetRequiredInfoType()
{
	return ZMeetingPasswordAndScreenNameHandler::GetInst().GetRequiredInfoType();
}
bool ZMeetingConfigWrap::InputMeetingPasswordAndScreenName(ZoomSTRING meetingPassword, ZoomSTRING screenName)
{
	return ZMeetingPasswordAndScreenNameHandler::GetInst().InputMeetingPasswordAndScreenName(meetingPassword, screenName);
}
bool ZMeetingConfigWrap::InputMeetingIDAndScreenName(ZoomSTRING meetingID, ZoomSTRING screenName)
{
	return ZMeetingPasswordAndScreenNameHandler::GetInst().InputMeetingIDAndScreenName(meetingID, screenName);
}
bool ZMeetingConfigWrap::InputMeetingScreenName(ZoomSTRING screenName)
{
	return ZMeetingPasswordAndScreenNameHandler::GetInst().InputMeetingScreenName(screenName);
}
void ZMeetingConfigWrap::MeetingPasswordAndScreenNameHandler_Cancel()
{
	return ZMeetingPasswordAndScreenNameHandler::GetInst().Cancel();
}
void ZMeetingConfigWrap::onInputMeetingPasswordAndScreenNameNotification()
{
	if (m_pSink)
		m_pSink->onInputMeetingPasswordAndScreenNameNotification();
}
void ZMeetingConfigWrap::onAirPlayInstructionWndNotification(bool bShow, ZoomSTRING airhostName)
{
	if (m_pSink)
		m_pSink->onAirPlayInstructionWndNotification(bShow, airhostName);
}
void ZMeetingConfigWrap::onWebinarNeedRegisterNotification()
{
	if (m_pSink)
		m_pSink->onWebinarNeedRegisterNotification();
}
void ZMeetingConfigWrap::onEndOtherMeetingToJoinMeetingNotification()
{
	if (m_pSink)
		m_pSink->onEndOtherMeetingToJoinMeetingNotification();
}
void ZMeetingConfigWrap::onFreeMeetingRemainTime(unsigned int leftTime)
{
	if (m_pSink)
		m_pSink->onFreeMeetingRemainTime(leftTime);
}
void ZMeetingConfigWrap::onFreeMeetingRemainTimeStopCountDown()
{
	if (m_pSink)
		m_pSink->onFreeMeetingRemainTimeStopCountDown();
}

ZNWebinarNeedRegisterType ZMeetingConfigWrap::GetWebinarNeedRegisterType()
{
	return ZWebinarNeedRegisterHandler::GetInst().GetWebinarNeedRegisterType();
}
ZoomSTRING ZMeetingConfigWrap::GetWebinarRegisterUrl()
{
	return ZWebinarNeedRegisterHandler::GetInst().GetWebinarRegisterUrl();
}
void ZMeetingConfigWrap::ReleaseRegisterWebinarByUrl()
{
	ZWebinarNeedRegisterHandler::GetInst().Release();
}
ZNSDKError ZMeetingConfigWrap::InputWebinarRegisterEmailAndScreenName(ZoomSTRING email, ZoomSTRING screenName)
{
	return ZWebinarNeedRegisterHandler::GetInst().InputWebinarRegisterEmailAndScreenName(email, screenName);
}
void ZMeetingConfigWrap::CancelRegisterWebinarByEmail()
{
	ZWebinarNeedRegisterHandler::GetInst().Cancel();
}