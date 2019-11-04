#import "Header_include.h"
#include "../meeting_config_wrap_core.h"
#include "sdk_native_error.h"
#include "../meeting_service_wrap_core.h"
ZMeetingConfigWrap &ZMeetingServiceWrap::GetMeetingConfigCtrl()
{
    return m_meeting_config_ctrl;
}

ZMeetingConfigWrap::ZMeetingConfigWrap()
{
    m_pSink = 0;
}

ZMeetingConfigWrap::~ZMeetingConfigWrap()
{
    m_pSink = 0;
}


void ZMeetingConfigWrap::Init()
{
    
}

void ZMeetingConfigWrap::Uninit()
{
    
}

void ZMeetingConfigWrap::SetSink(ZNativeSDKMeetingConfigWrapFreemeetingSink *pSink)
{
    m_pSink = pSink;
}


ZNSDKError ZMeetingConfigWrap::EnableInviteButtonOnMeetingUI(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enable = bEnable;
    if (service && config) {
        config.disableToolbarInviteButtonClickOriginAction = (enable == YES) ? NO : YES;
        if (bEnable == NO) {
            [config hideSDKButtons:YES ButtonType:ToolBarInviteButton];
        }
    }
    return ZNSDKERR_SUCCESS;
}


void ZMeetingConfigWrap::SetFloatVideoPos(ZNWndPosition position)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    NSString *X = [NSString stringWithCString:position.z_left.c_str() encoding:NSUTF8StringEncoding];
    NSString *Y = [NSString stringWithCString:position.z_top.c_str() encoding:NSUTF8StringEncoding];
    if (service && config) {
        config.floatVideoPoint = NSMakePoint(X.floatValue, Y.floatValue);
    }
}

void ZMeetingConfigWrap::SetBottomFloatToolbarWndVisibility(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enable = bShow;
    if (service && config) {
        config.mainToolBarVisible = (enable == YES) ? YES : NO;
    }
}

void ZMeetingConfigWrap::SetSharingToolbarVisibility(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enable = bShow;
    if (service && config) {
        config.shareToolBarVisible = (enable == YES) ? YES : NO;
    }
}

void ZMeetingConfigWrap::SetMeetingUIPos(ZNWndPosition position)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    NSString *L = [NSString stringWithCString:position.z_left.c_str() encoding:NSUTF8StringEncoding];
    NSString *T = [NSString stringWithCString:position.z_top.c_str() encoding:NSUTF8StringEncoding];
    if (service && config) {
        config.mainVideoPoint = NSMakePoint(L.floatValue, T.floatValue);
    }
}

void ZMeetingConfigWrap::SetMeetingIDForMeetingUITitle(unsigned long long meetingNumber)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return;
    }
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    if (service && config && meetingNumber) {
        config.newMeetingID = (unsigned int)meetingNumber;
    }
}

void ZMeetingConfigWrap::SetDirectShareMonitorID(ZoomSTRING monitorID)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    if (service && config) {
        NSString *ID = [NSString stringWithCString:monitorID.c_str() encoding:NSUTF8StringEncoding];
        config.monitorID = ID.intValue;
    }
}

void ZMeetingConfigWrap::DisableWaitingForHostDialog(bool bDisable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bDisable;
    if (service && config) {
        config.jbhWindowVisible = (enbale == YES) ? NO : YES;
    }
}

void ZMeetingConfigWrap::HideMeetingInfoFromMeetingUITitle(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bHide;
    if (service && config) {
        config.hideMainWindowMeetingInfo = (enbale == YES) ? YES : NO;
    }
}

void ZMeetingConfigWrap::DisablePopupMeetingWrongPSWDlg(bool bDisable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bDisable;
    if (service && config) {
        config.disablePopupWrongPasswordWindow = (enbale == YES) ? YES : NO;
    }
}

void ZMeetingConfigWrap::EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bEnable;
    if (service && config) {
        config.disableEndOtherMeetingAlert = (enbale == YES) ? NO : YES;
    }
}

void ZMeetingConfigWrap::EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bEnable;
    if (service && config) {
        config.disableDoubleClickToFullScreen = (enbale ==  YES)? NO : YES;
    }
}

void ZMeetingConfigWrap::SetFloatVideoWndVisibility(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bShow;
    if (service && config) {
        config.hideThumbnailVideoWindow = (enbale ==  YES)? NO : YES;
    }
}

void ZMeetingConfigWrap::PrePopulateWebinarRegistrationInfo(ZoomSTRING email, ZoomSTRING userName)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    NSString *Email = [NSString stringWithCString:email.c_str() encoding:NSUTF8StringEncoding];
    NSString *username = [NSString stringWithCString:userName.c_str() encoding:NSUTF8StringEncoding];
    if (service && config) {
        if (Email != nil && username != nil) {
            [config prefillWebinarUserName:username Email:Email];
        }
    }
}

ZNFreeMeetingEndingReminderType ZMeetingConfigWrap::GetReminderType()
{
    return ZN_FreeMeetingEndingReminder_NONE;
}

ZNSDKError ZMeetingConfigWrap::UpgradeMeeting()
{
    ZoomSDKUpgradeAccountHelper *pre = [[[ZoomSDKUpgradeAccountHelper alloc] init] autorelease];
    ZoomSDKError ret = [pre  upgradeAccount];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingConfigWrap::UpgradeAccount()
{
    ZoomSDKUpgradeAccountHelper *pre = [[[ZoomSDKUpgradeAccountHelper alloc] init] autorelease];
    ZoomSDKError ret = [pre  upgradeAccountFreeTrial];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingConfigWrap::CancelUpdate()
{
    return ZNSDKERR_NO_IMPL;
}


void ZMeetingConfigWrap::Reset()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config reset];
        }
    }
}

void ZMeetingConfigWrap::EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.autoAdjustSpeakerVolumeWhenJoinAudio = bEnable;
        }
    }
}

void ZMeetingConfigWrap::EnableAutoAdjustMicVolumeWhenJoinAudio(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.autoAdjustMicVolumeWhenJoinAudio = bEnable;
        }
    }
}

void ZMeetingConfigWrap::ConfigDSCP(int dscpAudio, int dscpVideo, bool bReset)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config modifyVideoDSCP:dscpVideo AudioDSCP:dscpAudio];
        }
    }
}


void ZMeetingConfigWrap::EnableHideFullPhoneNumber4PureCallinUser(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideFullPhoneNumber4PureCallinUser = bHide;
        }
    }
}

void ZMeetingConfigWrap::EnableLengthLimitationOfMeetingNumber(bool bEnable)
{
    
}

void ZMeetingConfigWrap::EnableShareIOSDevice(bool bEnable)
{
    
}

void ZMeetingConfigWrap::EnableShareWhiteBoard(bool bEnable)
{

}

void ZMeetingConfigWrap::ForceDisableMultiShare(bool bDisable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.forceDisableMultiShare = bDisable;
        }
    }
}

void ZMeetingConfigWrap::SetMaxDurationForOnlyHostInMeeting(int nDuration)
{

}

void ZMeetingConfigWrap::EnableLocalRecordingConvertProgressBarDialog(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableOpenRecordFileWhenMeetingEnd = (bShow ==  YES)? NO : YES ;
        }
    }
}

void ZMeetingConfigWrap::EnableApproveRemoteControlDlg(bool bEnable)
{
    
}
void ZMeetingConfigWrap::EnableDeclineRemoteControlResponseDlg(bool bEnable)
{
    
}
void ZMeetingConfigWrap::EnableLeaveMeetingOptionForHost(bool bEnable)
{
    
}
void ZMeetingConfigWrap::EnableVideoButtonOnMeetingUI(bool bEnable)
{
    
}
void ZMeetingConfigWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI(bool bEnable)
{
    
}
void ZMeetingConfigWrap::RedirectClickShareBTNEvent(bool bRedirect)
{
    
}
void ZMeetingConfigWrap::RedirectClickEndMeetingBTNEvent(bool bRedirect)
{
    
}
void ZMeetingConfigWrap::RedirectFreeMeetingEndingReminderDlg(bool bRedirect)
{
    
}
void ZMeetingConfigWrap::RedirectClickCustomLiveStreamMenuEvent(bool bRedirect)
{}
void ZMeetingConfigWrap::RedirectClickParticipantListBTNEvent(bool bRedirect)
{}
void ZMeetingConfigWrap::RedirectClickCCBTNEvent(bool bRedirect)
{}
void ZMeetingConfigWrap::RedirectMeetingWarningMsg(ZNZoomRedirectWarningMsgOption redirectOption)
{}
void ZMeetingConfigWrap::EnableToolTipsShow(bool bEnable)
{}
void ZMeetingConfigWrap::EnableAirplayInstructionWindow(bool bEnable)
{}
void ZMeetingConfigWrap::EnableClaimHostFeature(bool bEnable)
{}
void ZMeetingConfigWrap::EnableAutoHideJoinAudioDialog(bool bEnable)
{}
void ZMeetingConfigWrap::AlwaysShowIconOnTaskBar(bool bAlwaysShow)
{}
void ZMeetingConfigWrap::DisableSplitScreenModeUIElements(bool bDisable)
{}
void ZMeetingConfigWrap::SetShowAudioUseComputerSoundChkbox(bool bShow)
{}
void ZMeetingConfigWrap::SetShowCallInTab(bool bShow)
{}
void ZMeetingConfigWrap::SetShowCallMeTab(bool bShow)
{}
void ZMeetingConfigWrap::SetAlwaysShowMeetingIDOnTitle(bool bAlwaysShow)
{}
void ZMeetingConfigWrap::DisableTopMostAttr4SettingDialog(bool bDisable)
{}
void ZMeetingConfigWrap::EnableGrabShareWithoutReminder(bool bEnable)
{}
void ZMeetingConfigWrap::EnableShowShareSwitchMultiToSingleConfirmDlg(bool bEnable)
{}
void ZMeetingConfigWrap::DisableFreeMeetingRemainTimeNotify(bool bDisable)
{}
void ZMeetingConfigWrap::HideChatItemOnMeetingUI(bool bHide)
{}
void ZMeetingConfigWrap::HideRecordItemOnMeetingUI(bool bHide)
{}
void ZMeetingConfigWrap::HideUpgradeFreeMeetingButton(bool bHide)
{}
void ZMeetingConfigWrap::SetShowInviteDlgTabPage(ZNSDKInviteDlgTabPage tabPage, bool bShow)
{}
void ZMeetingConfigWrap::SetShowH323SubTabPage(ZNSDKH323TabPage tabPage, bool bShow)
{}
void ZMeetingConfigWrap::HideUpgradeWarningMsgForFreeUserWhenSchedule(bool bHide)
{}
void ZMeetingConfigWrap::HideSwitchCameraButton(bool bHide)
{}
void ZMeetingConfigWrap::HideCopyUrlOnInviteWindow(bool bHide)
{}
void ZMeetingConfigWrap::HideCopyInvitationOnInviteWindow(bool bHide)
{}
void ZMeetingConfigWrap::HideKeypadButtonOnMeetingWindow(bool bHide)
{}
void ZMeetingConfigWrap::HideRemoteControlOnMeetingUI(bool bHide)
{}
void ZMeetingConfigWrap::HideQAOnMeetingUI(bool bHide)
{}
void ZMeetingConfigWrap::HidePollOnMeetingUI(bool bHide)
{}
void ZMeetingConfigWrap::EnableInputMeetingPasswordDlg(bool bEnable)
{}
void ZMeetingConfigWrap::EnableInputMeetingScreenNameDlg(bool bEnable)
{}
void ZMeetingConfigWrap::RedirectWebinarNeedRegister(bool bRedirect)
{}
void ZMeetingConfigWrap::RedirectEndOtherMeeting(bool bRedirect)
{}
void ZMeetingConfigWrap::EnableForceAutoStartMyVideoWhenJoinMeeting(bool bEnable)
{}
void ZMeetingConfigWrap::EnableForceAutoStopMyVideoWhenJoinMeeting(bool bEnable)
{}
void ZMeetingConfigWrap::DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bool bDisable)
{}
void ZMeetingConfigWrap::DisableRemoteCtrlCopyPasteFeature(bool bDisable)
{}

//ZNFreeMeetingEndingReminderType ZMeetingConfigWrap::GetReminderType()
//{
//    return ZN_FreeMeetingEndingReminder_NONE;
//}
//ZNSDKError ZMeetingConfigWrap::UpgradeMeeting()
//{
//    return ZNSDKERR_NO_IMPL;
//}
//ZNSDKError ZMeetingConfigWrap::UpgradeAccount()
//{
//    return ZNSDKERR_NO_IMPL;
//}
//ZNSDKError ZMeetingConfigWrap::CancelUpdate()
//{
//    return ZNSDKERR_NO_IMPL;
//}
//callback
void  ZMeetingConfigWrap::onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url)
{
    if (m_pSink) {
        m_pSink->onFreeMeetingNeedToUpgrade(type, gift_url);
    }
    
}
void  ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStart()
{
    if (m_pSink) {
        m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStart();
    }
}

void  ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStop()
{
    if (m_pSink) {
        m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStop();
    }
    
}


void  ZMeetingConfigWrap::onFreeMeetingUpgradeToProMeeting()
{
    if (m_pSink) {
        m_pSink->onFreeMeetingUpgradeToProMeeting();
    }
    
}
