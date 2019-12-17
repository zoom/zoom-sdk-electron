

#import "meetingServiceDelegate.h"
#include "../zoom_node_addon.h"
#include "sdk_native_error.h"
extern ZNativeSDKWrap _g_native_wrap;

@interface meetingServiceDelegate()
@property(nonatomic,retain)ZoomSDKRetrieveSMSVerificationCodeController *retriveController;
@property(nonatomic,retain)ZoomSDKVerifySMSVerificationCodeController *verifyCintroller;
@property(nonatomic,retain)ZoomSDKWebinarRegisterHelper *webinarRegisterHelper;
@property(nonatomic,retain)ZoomSDKJoinMeetingHelper *joinMeetingHelper;
@end

@implementation meetingServiceDelegate

+(meetingServiceDelegate *)share
{
    static meetingServiceDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        delegate = [[meetingServiceDelegate alloc]init];
    });
    return delegate;
}

#pragma mark meeting delegate
- (void)onMeetingStatusChange:(ZoomSDKMeetingStatus)state meetingError:(ZoomSDKMeetingError)error EndReason:(EndMeetingReason)reason
{
    nativeErrorTypeHelp help;
    ZNMeetingStatus status = help.ZNSDKMeetingStatus(state);
    int  result = 0;
    if (error == ZoomSDKMeetingError_None) {
        result = help.ZNSDKMeetingEndReason(reason);
    }else{
        result = help.ZNSDKMeetingFailCode(error);
    }
    _g_native_wrap.GetMeetingServiceWrap().onMeetingStatusChanged(status, result);
}

- (void)onFreeMeetingNeedToUpgrade:(FreeMeetingNeedUpgradeType)type giftUpgradeURL:(NSString *)giftURL
{
    nativeErrorTypeHelp help;
    ZNFreeMeetingNeedUpgradeType  ZN_type = help.ZoomSDKFreeMeetingNeedUpgradeType(type);
    NSString *url = nil;
    if (giftURL == nil) {
        url = @"";
    }else{
        url = giftURL;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingNeedToUpgrade(ZN_type, url.UTF8String);
}

- (void)onFreeMeetingUpgradeToGiftFreeTrialStop
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingUpgradeToGiftFreeTrialStop();
}

- (void)onFreeMeetingUpgradeToGiftFreeTrialStart
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingUpgradeToGiftFreeTrialStart();
}

- (void)onFreeMeetingUpgradedToProMeeting
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingConfigCtrl().onFreeMeetingUpgradeToProMeeting();
}

-(void)onSharingStatus:(ZoomSDKShareStatus)status User:(unsigned int)userID
{
    nativeErrorTypeHelp help;
    ZNShareStatus shareStatus = help.ZNSDKShareStatus(status);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().onSharingStatus(shareStatus, userID);
}

#pragma mark meeting ui delegate
- (void)onToolbarInviteButtonClick
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    ZoomSDKMeetingConfiguration *config = [service getMeetingConfiguration];
    bool  isInvite = false;
    if (service && config) {
        isInvite = [config disableToolbarInviteButtonClickOriginAction];
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onInviteBtnClicked(isInvite);
}

-(void)onToolbarShareButtonClick
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onStartShareBtnClicked();
}

-(void)onParticipantButtonClicked
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onParticipantListBtnClicked();
}

-(void)onCustomLiveButtonClicked
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onCustomLiveStreamMenuClicked();
}

-(void)onNeedShowLeaveMeetingWindow
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onEndMeetingBtnClicked();
}

-(void)onAudioButtonClicked:(unsigned int)userid audioSession:(ZoomSDKAudioActionInfo)info
{
    nativeErrorTypeHelp help;
    ZNAudioCallbackActionInfo Actioninfo = help.ZNSDKAudioCallbackAction(info);
    ZNAudioBtnClickedCallbackInfo callbackInfo;
    callbackInfo.userid_MuteUnmute = userid;
    callbackInfo.audio_clicked_action = Actioninfo;
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onAudioBtnClicked(callbackInfo);
}

-(void)onAudioSettingMenuButtonClicked
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingUICtrl().onAudioMenuBtnClicked();
}
#pragma mark meeting action controller
- (void)onVideoStatusChange:(BOOL)videoOn UserID:(unsigned int)userID
{
    ZNVideoStatus videoStatus = ZN_Video_OFF;
    if (videoOn == YES) {
        videoStatus = ZN_Video_ON;
    }else{
        videoStatus = ZN_Video_OFF;
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().onUserVideoStatusChange(userID, videoStatus);
}

-(void)onActiveVideoUserChanged:(unsigned int)userID
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().onActiveVideoUserChanged(userID);
}

-(void)onActiveSpeakerVideoUserChanged:(unsigned int)userID
{
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().onActiveSpeakerVideoUserChanged(userID);
}

-(void)onUserAudioStatusChange:(NSArray *)userAudioStatusArray
{
    if (!userAudioStatusArray || userAudioStatusArray.count == 0) {
        return;
    }
    ZNList<ZNUserAudioStatus> userAudioStatusList;
    nativeErrorTypeHelp help_typeChanage;
    ZNUserAudioStatus userAudioInfo;
    for (ZoomSDKUserAudioStauts *key in userAudioStatusArray) {
        unsigned int USERID = [key getUserID];
        ZoomSDKAudioStatus status = [key getStatus];
        ZNAudioStatus  znStatus = help_typeChanage.ZNSDKUserAudioStatus(status);
        userAudioInfo.audioStauts = znStatus;
        userAudioInfo.userId = USERID;
        userAudioStatusList.push_back(userAudioInfo);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().onUserAudioStatusChange(userAudioStatusList, "");
    
}

-(void)onActiveSpeakerChanged:(unsigned int)userID
{
    ZNList<unsigned int> list;
    list.push_back(userID);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().onUserActiveAudioChange(list);
}

-(void)onUserLeft:(NSArray *)array
{
    if (!array || array.count == 0) {
        return;
    }
    ZNList<unsigned int> list;
    for (NSNumber *num in array) {
        unsigned int userid = [num unsignedIntValue];
        list.push_back(userid);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onUserLeft(list, "");
}

-(void)onUserJoin:(NSArray *)array
{
    if (!array || array.count == 0) {
        return;
    }
    ZNList<unsigned int> list;
    for (NSNumber *num in array) {
        unsigned int userid = [num unsignedIntValue];
        list.push_back(userid);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onUserJoin(list, "");
}

-(void)onHostChange:(unsigned int)userID
{
 _g_native_wrap.GetMeetingServiceWrap().GetMeetingParticipantsCtrl().onHostChangeNotification(userID);
}


//h323
-(void)onCalloutStatusReceived:(H323CalloutStatus)calloutStatus
{
    nativeErrorTypeHelp help_typeChanage;
    ZNH323CalloutStatus status = help_typeChanage.ZoomSDKH323Status(calloutStatus);
    _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().onH323CalloutStatusNotify(status);
}

#pragma mark  sms
-(void)onNeedRealNameAuthMeetingWithSupportCountryList:(NSArray *)supportCountryList withPrivacyURL:(NSString *)privacyURL withRetrieveSMSVerificationCodeHandler:(ZoomSDKRetrieveSMSVerificationCodeController *)handler
{
    self.retriveController = handler;
    ZNList<ZNZoomRealNameAuthCountryInfo> infoList;
    for (ZoomSDKRealNameAuthCountryInfo *info in supportCountryList) {
        ZNZoomRealNameAuthCountryInfo countryInfo;
        countryInfo.countryCode = [info getCountryCode].UTF8String;
        countryInfo.countryID = [info getCountryID].UTF8String;
        countryInfo.countryName = [info getCountryName].UTF8String;
        infoList.push_back(countryInfo);
    }
    _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().onNeedRealNameAuthMeetingNotification(infoList, privacyURL.UTF8String);
}

-(void)onRetrieveSMSVerificationCodeResult:(ZoomSDKSMSVerificationCodeError)result withVerifySMSVerificationCodeHandle:(ZoomSDKVerifySMSVerificationCodeController *)handler
{
    self.verifyCintroller = handler;
    nativeErrorTypeHelp help;
    ZNSMSVerificationCodeErr ret = help.ZNSDKSMSVerificationCodeError(result);
    _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().onRetrieveSMSVerificationCodeResultNotification(ret);
}

-(void)onVerifySMSVerificationCodeResult:(ZoomSDKSMSVerificationCodeError)reuslt
{
    nativeErrorTypeHelp help;
    ZNSMSVerificationCodeErr ret = help.ZNSDKSMSVerificationCodeError(reuslt);
    _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().onVerifySMSVerificationCodeResultNotification(ret);
}

-(ZoomSDKVerifySMSVerificationCodeController *)getVerifyCintroller
{
    return  self.verifyCintroller;
}

-(ZoomSDKRetrieveSMSVerificationCodeController *)getRetriveController
{
    return self.retriveController;
}

-(BOOL)getResendRetriveController
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return NO;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return NO;
    }
    self.retriveController = [controller resendSMSVerificationCodeController];
    if (self.retriveController) {
        return YES;
    }
    return NO;
}

-(BOOL)getReVerifyCintroller
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return NO;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return NO;
    }
    self.verifyCintroller = [controller reVerifySMSVerificationCodeController];
    if (self.verifyCintroller) {
        return YES;
    }
    return NO;
}

-(ZoomSDKError)onWebinarNeedRegisterResponse:(ZoomSDKWebinarRegisterHelper *)webinarRegisterHelper
{
    self.webinarRegisterHelper = webinarRegisterHelper;
}

-(ZoomSDKWebinarRegisterHelper *)getWebinarRegisterHelper
{
    return self.webinarRegisterHelper;
}

-(void)onJoinMeetingResponse:(ZoomSDKJoinMeetingHelper *)joinMeetingHelper
{
    self.joinMeetingHelper = joinMeetingHelper;
}

-(ZoomSDKJoinMeetingHelper *)getJoinMeetingHelper
{
    return self.joinMeetingHelper;
}

-(void)cleanUp
{
    if (_verifyCintroller) {
        [_verifyCintroller release];
        _verifyCintroller = nil;
    }
    
    if (_retriveController) {
        [_retriveController release];
        _retriveController = nil;
    }
    if (_webinarRegisterHelper) {
        [_webinarRegisterHelper release];
        _webinarRegisterHelper = nil;
    }
    if (_joinMeetingHelper) {
        [_joinMeetingHelper release];
        _joinMeetingHelper = nil;
    }
}

-(void)dealloc
{
    [self cleanUp];
    [super dealloc];
}
@end
