#import "Header_include.h"
#include "../meeting_config_wrap_core.h"
#include "sdk_native_error.h"
#include "../meeting_service_wrap_core.h"

extern nativeErrorTypeHelp  Help_type;

ZMeetingConfigWrap &ZMeetingServiceWrap::GetMeetingConfigCtrl(){
    
    return m_meeting_config_ctrl;
}


ZMeetingConfigWrap::ZMeetingConfigWrap(){
    m_pSink = 0;
}

ZMeetingConfigWrap::~ZMeetingConfigWrap(){
    m_pSink = 0;
    
}


void ZMeetingConfigWrap::Init(){
    
}


void ZMeetingConfigWrap::Uninit(){
    
}

void ZMeetingConfigWrap::SetSink(ZNativeSDKMeetingConfigWrapFreemeetingSink *pSink){
    
    m_pSink = pSink;
}


ZNSDKError ZMeetingConfigWrap::EnableInviteButtonOnMeetingUI(bool bEnable){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enable = bEnable;
    if (service && config) {
        config.disableToolbarInviteButtonClickOriginAction = (enable == YES) ? NO : YES;
    }
    return ZNSDKERR_SUCCESS;
}


void ZMeetingConfigWrap::SetFloatVideoPos(ZNWndPosition position){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    NSString *X = [NSString stringWithCString:position.z_left.c_str() encoding:NSUTF8StringEncoding];
    NSString *Y = [NSString stringWithCString:position.z_top.c_str() encoding:NSUTF8StringEncoding];
    if (service && config) {
        
        config.floatVideoPoint = NSMakePoint(X.floatValue, Y.floatValue);
    }
    
}

void ZMeetingConfigWrap::SetBottomFloatToolbarWndVisibility(bool bShow){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enable = bShow;
    if (service && config) {
        config.mainToolBarVisible = (enable == YES) ? YES : NO;
    }
//    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
//    if (service && controller) {
//        [controller showMeetingComponent:MeetingComponent_MainToolBar window:nil show:bShow InPanel:YES frame:NSZeroRect];
//    }
}

void ZMeetingConfigWrap::SetSharingToolbarVisibility(bool bShow){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enable = bShow;
    if (service && config) {
        config.shareToolBarVisible = (enable == YES) ? YES : NO;
    }
    
}

void ZMeetingConfigWrap::SetMeetingUIPos(ZNWndPosition position){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    NSString *L = [NSString stringWithCString:position.z_left.c_str() encoding:NSUTF8StringEncoding];
    NSString *T = [NSString stringWithCString:position.z_top.c_str() encoding:NSUTF8StringEncoding];
    if (service && config) {
        config.mainVideoPoint = NSMakePoint(L.floatValue, T.floatValue);
    }
    
}

void ZMeetingConfigWrap::SetMeetingIDForMeetingUITitle(unsigned long long meetingNumber){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    if (!service) {
        return;
    }
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    if (service && config && meetingNumber) {
        config.newMeetingID = (unsigned int)meetingNumber;
    }
    
}

void ZMeetingConfigWrap::SetDirectShareMonitorID(ZoomSTRING monitorID){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    if (service && config) {
        NSString *ID = [NSString stringWithCString:monitorID.c_str() encoding:NSUTF8StringEncoding];
        config.monitorID = ID.intValue;
    }
    
}

void ZMeetingConfigWrap::DisableWaitingForHostDialog(bool bDisable){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bDisable;
    if (service && config) {
        config.jbhWindowVisible = (enbale == YES) ? NO : YES;
    }
    
}

void ZMeetingConfigWrap::HideMeetingInfoFromMeetingUITitle(bool bHide){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bHide;
    if (service && config) {
        config.hideMainWindowMeetingInfo = (enbale == YES) ? YES : NO;
    }
    
}

void ZMeetingConfigWrap::DisablePopupMeetingWrongPSWDlg(bool bDisable){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bDisable;
    if (service && config) {
        config.disablePopupWrongPasswordWindow = (enbale == YES) ? YES : NO;
    }
    
}

void ZMeetingConfigWrap::EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable){
   
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bEnable;
    if (service && config) {
        config.disableEndOtherMeetingAlert = (enbale == YES) ? NO : YES;
    }
    
}

void ZMeetingConfigWrap::EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bEnable;
    if (service && config) {
        config.disableDoubleClickToFullScreen = (enbale ==  YES)? NO : YES;
    }
    
}

void ZMeetingConfigWrap::SetFloatVideoWndVisibility(bool bShow){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool enbale = bShow;
    if (service && config) {
        config.hideThumbnailVideoWindow = (enbale ==  YES)? NO : YES;
    }
    
}

void ZMeetingConfigWrap::PrePopulateWebinarRegistrationInfo(ZoomSTRING email, ZoomSTRING userName){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    NSString *Email = [NSString stringWithCString:email.c_str() encoding:NSUTF8StringEncoding];
    NSString *username = [NSString stringWithCString:userName.c_str() encoding:NSUTF8StringEncoding];
    
    if (service && config) {
        if (Email != nil && username != nil) {
            [config prefillWebinarUserName:username Email:Email];
        }
    }
}

ZNFreeMeetingEndingReminderType ZMeetingConfigWrap::GetReminderType(){
   
//    ZoomSDKUpgradeAccountHelper *pre = [[ZoomSDKUpgradeAccountHelper alloc]init];
//    SDKReminderType ret = [pre  getReminderType];
//    return Help_type.ZoomSDKFreeMeetingEndReminderType(ret);
    
    return ZN_FreeMeetingEndingReminder_NONE;
}

ZNSDKError ZMeetingConfigWrap::UpgradeMeeting(){
    
    ZoomSDKUpgradeAccountHelper *pre = [[[ZoomSDKUpgradeAccountHelper alloc]init] autorelease];
    ZoomSDKError ret = [pre  upgradeAccount];
    return Help_type.ZoomSDKErrorType(ret);
    
}

ZNSDKError ZMeetingConfigWrap::UpgradeAccount(){
    
    ZoomSDKUpgradeAccountHelper *pre = [[[ZoomSDKUpgradeAccountHelper alloc]init] autorelease];
    ZoomSDKError ret = [pre  upgradeAccountFreeTrial];
    return Help_type.ZoomSDKErrorType(ret);
    
}

ZNSDKError ZMeetingConfigWrap::CancelUpdate(){
    
    return ZNSDKERR_NO_IMPL;
}

//callback
void  ZMeetingConfigWrap::onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url){
    
    if (m_pSink) {
        m_pSink->onFreeMeetingNeedToUpgrade(type, gift_url);
    }
    
}
void  ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStart(){
    
    if (m_pSink) {
        m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStart();
    }
    
}

void  ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStop(){
    
    if (m_pSink) {
        m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStop();
    }
    
}


void  ZMeetingConfigWrap::onFreeMeetingUpgradeToProMeeting(){
    
    if (m_pSink) {
        m_pSink->onFreeMeetingUpgradeToProMeeting();
    }
    
}
