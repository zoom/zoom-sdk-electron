#import "Header_include.h"
#include "../meeting_config_wrap_core.h"
#include "sdk_native_error.h"
#include "../meeting_service_wrap_core.h"
#import "meetingServiceDelegate.h"
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
    [[[[ZoomSDK sharedSDK] getMeetingService] getWebinarController] setDelegate:nil];
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
    [[[[ZoomSDK sharedSDK] getMeetingService] getWebinarController] setDelegate:[meetingServiceDelegate share]];
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

void ZMeetingConfigWrap::EnableLeaveMeetingOptionForHost(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            BOOL enable = (bEnable == true) ? YES : NO;
            config.hideLeaveMeetingWindow = enable;
        }
    }
}
void ZMeetingConfigWrap::EnableVideoButtonOnMeetingUI(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config  hideSDKButtons:bEnable ButtonType:ToolBarVideoButton];
            [config  hideSDKButtons:bEnable ButtonType:FitBarVideoButton];
        }
    }
}
void ZMeetingConfigWrap::EnableEnterAndExitFullScreenButtonOnMeetingUI(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            BOOL enable = (bEnable == true) ? YES : NO;
            [config hideSDKButtons:enable ButtonType:MainExitFullScreenButton] ;
        }
    }
}


void ZMeetingConfigWrap::RedirectClickShareBTNEvent(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableShareButtonClickOriginAction = bRedirect;
        }
    }
}

void ZMeetingConfigWrap::RedirectClickParticipantListBTNEvent(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableParticipantButtonClickOriginAction = bRedirect;
        }
    }
}

void ZMeetingConfigWrap::RedirectMeetingWarningMsg(ZNZoomRedirectWarningMsgOption redirectOption)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideMeetingStaticBadNetWorkWaring = redirectOption.bRedirectBadNetwork;
            config.hideMeetingStaticSystemBusyWaring = redirectOption.bRedirectWarnHighCPU;
        }
    }
}

void ZMeetingConfigWrap::EnableClaimHostFeature(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            BOOL enable = (bEnable == true) ? NO : YES;
            [config hideSDKButtons:enable ButtonType:ClaimHostButton];
        }
    }
}

void ZMeetingConfigWrap::RedirectFreeMeetingEndingReminderDlg(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableFreeUserOriginAction = bRedirect;
        }
    }
}
void ZMeetingConfigWrap::RedirectClickCustomLiveStreamMenuEvent(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableCustomLiveStreamAction = bRedirect;
        }
    }
}

void ZMeetingConfigWrap::HideUpgradeWarningMsgForFreeUserWhenSchedule(bool bHide)
{
    ZoomSDKPremeetingService *service = [[ZoomSDK sharedSDK]  getPremeetingService];
    if (service) {
        [service hideScheduleComponent:ScheduleComponent_UpgradeAccountTipForFreeUser hide:bHide];
    }
}
void ZMeetingConfigWrap::RedirectClickCCBTNEvent(bool bRedirect)
{}
void ZMeetingConfigWrap::EnableToolTipsShow(bool bEnable)
{}
void ZMeetingConfigWrap::EnableAirplayInstructionWindow(bool bEnable)
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
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            BOOL  isHide = (bShow == true) ? NO : YES;
            config.hideTelephoneInAudiowWindow = isHide;
        }
    }
}
void ZMeetingConfigWrap::SetShowCallMeTab(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            BOOL  isHide = (bShow == true) ? NO : YES;
            config.hideCallMeInAudioWindow = isHide;
        }
    }
}
void ZMeetingConfigWrap::SetAlwaysShowMeetingIDOnTitle(bool bAlwaysShow)
{}
void ZMeetingConfigWrap::DisableTopMostAttr4SettingDialog(bool bDisable)
{}
void ZMeetingConfigWrap::EnableGrabShareWithoutReminder(bool bEnable)
{}
void ZMeetingConfigWrap::EnableShowShareSwitchMultiToSingleConfirmDlg(bool bEnable)
{}
void ZMeetingConfigWrap::HideRecordItemOnMeetingUI(bool bHide)
{}
void ZMeetingConfigWrap::HideUpgradeFreeMeetingButton(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config  hideSDKButtons:bHide ButtonType:UpgradeButtonInFreeMeetingRemainTimeTooltip];
        }
    }
}
void ZMeetingConfigWrap::SetShowInviteDlgTabPage(ZNSDKInviteDlgTabPage tabPage, bool bShow)
{}
void ZMeetingConfigWrap::RedirectClickEndMeetingBTNEvent(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideLeaveMeetingWindow = bRedirect;
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
void ZMeetingConfigWrap::SetMaxDurationForOnlyHostInMeeting(int nDuration)
{
}
void ZMeetingConfigWrap::DisableRemoteCtrlCopyPasteFeature(bool bDisable)
{
}
void ZMeetingConfigWrap::EnableApproveRemoteControlDlg(bool bEnable)
{}
void ZMeetingConfigWrap::EnableDeclineRemoteControlResponseDlg(bool bEnable)
{}
void ZMeetingConfigWrap::EnableInputMeetingScreenNameDlg(bool bEnable)
{}
void ZMeetingConfigWrap::RedirectWebinarNeedRegister(bool bRedirect)
{}

void ZMeetingConfigWrap::EnableForceAutoStartMyVideoWhenJoinMeeting(bool bEnable)
{
    ZoomSDKPremeetingService *service = [[ZoomSDK sharedSDK]  getPremeetingService];
    if (service) {
        [service enableForceAutoStartMyVideoWhenJoinMeeting:bEnable];
    }
}
void ZMeetingConfigWrap::EnableForceAutoStopMyVideoWhenJoinMeeting(bool bEnable)
{
    ZoomSDKPremeetingService *service = [[ZoomSDK sharedSDK]  getPremeetingService];
    if (service) {
        [service enableForceAutoStopMyVideoWhenJoinMeeting:bEnable];
    }
}


void ZMeetingConfigWrap::DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bool bDisable)
{
    ZoomSDKPremeetingService *service = [[ZoomSDK sharedSDK]  getPremeetingService];
    if (service) {
        [service disableAutoShowSelectJoinAudioDlgWhenJoinMeeting:NO];
    }
}


void ZMeetingConfigWrap::DisableFreeMeetingRemainTimeNotify(bool bDisable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableFreeMeetingRemainTimeNotify = bDisable;
        }
    }
}


void ZMeetingConfigWrap::HideChatItemOnMeetingUI(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideChatItemInMeeting = bHide;
        }
    }
}

void ZMeetingConfigWrap::SetShowH323SubTabPage(ZNSDKH323TabPage tabPage, bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (!service) {
        return;
    }
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    if (!config) {
        return;
    }
    if (tabPage == SDK_INVITEDLG_H323_DIALIN) {
        config.hideInviteInMeetingH323CallInTab = bShow;
    }
    if (tabPage == SDK_INVITEDLG_H323_CALLOUT) {
        config.hideInviteInMeetingH323CallOutTab = bShow;
    }
}

void ZMeetingConfigWrap::HideSwitchCameraButton(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideSwitchCameraButton = bHide;
        }
    }
}
void ZMeetingConfigWrap::HideCopyUrlOnInviteWindow(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideCopyURLButtonWhenInviteOthers = bHide;
        }
    }
}
void ZMeetingConfigWrap::HideCopyInvitationOnInviteWindow(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideCopyInvitationButtonWhenInviteOthers = bHide;
        }
    }
}

//
void ZMeetingConfigWrap::HideKeypadButtonOnMeetingWindow(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideShowKeypadButton = bHide;
        }
    }
}
void ZMeetingConfigWrap::HideRemoteControlOnMeetingUI(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config hideSDKButtons:bHide ButtonType:FitBarRemoteControlButton];
        }
    }
}
void ZMeetingConfigWrap::HideQAOnMeetingUI(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config hideSDKButtons:bHide ButtonType:ToolBarQandAButton];
        }
    }
}
void ZMeetingConfigWrap::HidePollOnMeetingUI(bool bHide)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            [config hideSDKButtons:bHide ButtonType:ToolBarPollingButton];
        }
    }
}

void ZMeetingConfigWrap::EnableInputMeetingPasswordDlg(bool bEnable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableInputPasswordWindow = bEnable;
        }
    }
}

void ZMeetingConfigWrap::RedirectEndOtherMeeting(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableEndOtherMeetingAlert = bRedirect;
        }
    }
}

void ZMeetingConfigWrap::RedirectClickAudioBTNEvent(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableAudioButtonClickOriginAction = bRedirect;
        }
    }
}

void ZMeetingConfigWrap::RedirectClickAudioMenuBTNEvent(bool bRedirect)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.disableAudioSettingMenuButtonClickOriginAction = bRedirect;
        }
    }
}

void ZMeetingConfigWrap::EnableAudioButtonOnMeetingUI(bool bEnable)
{
    return;
}

void ZMeetingConfigWrap::DisableShowJoinMeetingWnd(bool bDisable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (service) {
        ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
        if (config) {
            config.hideLoadingWindow = bDisable;
        }
    }
}

void ZMeetingConfigWrap::SetShowVideoOptimizeChkbox(bool bShow)
{
    return;
}

ZNRequiredInfoType ZMeetingConfigWrap::GetRequiredInfoType()
{
    ZoomSDKJoinMeetingHelper *helper = [[meetingServiceDelegate share] getJoinMeetingHelper];
    if (helper) {
        JoinMeetingReqInfoType type = [helper getReqInfoType];
        nativeErrorTypeHelp help;
        return help.ZNSDKRequiredInfoType(type);
    }
    return ZNREQUIRED_INFO_TYPE_NONE;
}

bool ZMeetingConfigWrap::InputMeetingPasswordAndScreenName(ZoomSTRING meetingPassword, ZoomSTRING screenName)
{
    ZoomSDKJoinMeetingHelper *helper = [[meetingServiceDelegate share] getJoinMeetingHelper];
    if (helper) {
        if (!meetingPassword.empty()) {
            NSString *psdStr = [NSString stringWithCString:meetingPassword.c_str() encoding:NSUTF8StringEncoding];
            ZoomSDKError ret = [helper inputPassword:psdStr];
            return (ret == ZoomSDKError_Success) ? true : false;
        }
    }
    return false;
}

bool ZMeetingConfigWrap::InputMeetingIDAndScreenName(ZoomSTRING meetingID, ZoomSTRING screenName)
{
    return false;
}

bool ZMeetingConfigWrap::InputMeetingScreenName(ZoomSTRING screenName)
{
    return false;
}

void ZMeetingConfigWrap::MeetingPasswordAndScreenNameHandler_Cancel()
{
    ZoomSDKJoinMeetingHelper *helper = [[meetingServiceDelegate share] getJoinMeetingHelper];
    if (helper) {
        [helper cancel];
    }
}

ZNWebinarNeedRegisterType ZMeetingConfigWrap::GetWebinarNeedRegisterType()
{
    ZoomSDKWebinarRegisterHelper *helper = [[meetingServiceDelegate share] getWebinarRegisterHelper];
    if (!helper) {
        return ZNWebinarReg_NONE;
    }
    WebinarRegisterType type = [helper getWebinarRegisterType];
    nativeErrorTypeHelp help;
    return help.ZNSDKWebinarNeedRegisterType(type);
}

ZoomSTRING ZMeetingConfigWrap::GetWebinarRegisterUrl()
{
    ZoomSDKWebinarRegisterHelper *helper = [[meetingServiceDelegate share] getWebinarRegisterHelper];
    if (helper) {
        NSURL *url = [helper getWebinarRegisterURL];
        if (url) {
            NSString *urlStr = [url absoluteString];
            return urlStr.UTF8String;
        }
    }
    return "";
}

void ZMeetingConfigWrap::ReleaseRegisterWebinarByUrl()
{
    return;
}

ZNSDKError ZMeetingConfigWrap::InputWebinarRegisterEmailAndScreenName(ZoomSTRING email, ZoomSTRING screenName)
{
    ZoomSDKWebinarRegisterHelper *helper = [[meetingServiceDelegate share] getWebinarRegisterHelper];
    if (!helper) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString *emailStr = [NSString stringWithCString:email.c_str() encoding:NSUTF8StringEncoding];
    NSString *screenNameStr = [NSString stringWithCString:screenName.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKError ret = [helper inputEmail:emailStr screenName:screenNameStr];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

void ZMeetingConfigWrap::CancelRegisterWebinarByEmail()
{
    ZoomSDKWebinarRegisterHelper *helper = [[meetingServiceDelegate share] getWebinarRegisterHelper];
    if (helper) {
        [helper cancel];
    }
}

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
