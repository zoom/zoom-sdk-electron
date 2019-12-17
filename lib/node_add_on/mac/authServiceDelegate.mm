
#import "authServiceDelegate.h"
#include "../zoom_node_addon.h"
#include "../auth_service_wrap_core.h"
extern  ZNativeSDKWrap _g_native_wrap;
@implementation authServiceDelegate

+(authServiceDelegate *)share
{
    static authServiceDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        delegate = [[authServiceDelegate alloc] init];
    });
    return delegate;
}

- (void)onZoomSDKAuthReturn:(ZoomSDKAuthError)returnValue
{
    nativeErrorTypeHelp native_help;
    ZNAuthResult result = native_help.ZoomSDKAuthErrorTpye(returnValue);
    self.authResult = result;
    _g_native_wrap.GetAuthServiceWrap().onAuthenticationReturn(result);
}

- (void)onZoomSDKLogin:(ZoomSDKLoginStatus)loginStatus failReason:(NSString *)reason
{
    nativeErrorTypeHelp native_login_help;
    ZNLOGINSTATUS result = native_login_help.ZoomSDKLoginStatusType(loginStatus);
    self.loginStatus = result;
    _g_native_wrap.GetAuthServiceWrap().onLoginRet(result);
}

-(void)onZoomSDKLogout
{
    _g_native_wrap.GetAuthServiceWrap().onLogout();
}

-(void)onZoomIdentityExpired
{
    _g_native_wrap.GetAuthServiceWrap().onZoomIdentityExpired();
}

-(ZNAuthResult)getAuthResult
{
    return self.authResult;
}

-(ZNLOGINSTATUS)getLoginStatus
{
    return self.loginStatus;
}

-(void)onZoomAuthIdentityExpired
{
    _g_native_wrap.GetAuthServiceWrap().onZoomAuthIdentityExpired();
}
#pragma mark PremeetingServic
-(void)onListMeeting:(ZoomSDKPremeetingError)error MeetingList:(NSArray *)meetingList
{
    nativeErrorTypeHelp help;
    ZNPremeetingAPIResult result = help.ZNSDKPreMeetingError(error);
    ZNList<unsigned long long> list;
    if (meetingList.count == 0) {
        return;
    }
    for (ZoomSDKMeetingItem *item in meetingList) {
        long long meetingID = [item  getMeetingUniqueID];
        list.push_back(meetingID);
    }
    _g_native_wrap.GetPremeetingServiecWrap().onListMeeting(result, list);
}

-(void)onScheduleOrEditMeeting:(ZoomSDKPremeetingError)error MeetingUniqueID:(long long)meetingUniqueID
{
    nativeErrorTypeHelp help;
    ZNPremeetingAPIResult result = help.ZNSDKPreMeetingError(error);
    _g_native_wrap.GetPremeetingServiecWrap().onScheduleOrEditMeeting(result, meetingUniqueID);
}

-(void)onDeleteMeeting:(ZoomSDKPremeetingError)error
{
    nativeErrorTypeHelp help;
    ZNPremeetingAPIResult result = help.ZNSDKPreMeetingError(error);
    _g_native_wrap.GetPremeetingServiecWrap().onDeleteMeeting(result);
}

#pragma direct share
-(void)onDirectShareStatusReceived:(DirectShareStatus)status DirectShareReceived:(ZoomSDKDirectShareHandler *)handler
{
    nativeErrorTypeHelp help;
    ZNDirectShareStatus  ZNStatus = help.ZNSDKDirectShareStatus(status);
    self.directStatus = status;
    self.DirectShareHandler = handler;
    _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().OnDirectShareStatusUpdate(ZNStatus);
}

-(DirectShareStatus)getDirectShare
{
    return self.directStatus;
}

-(ZoomSDKDirectShareHandler *)getDirectShareHandler
{
    return self.DirectShareHandler;
}

@end
