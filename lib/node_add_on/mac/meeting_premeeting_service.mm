

#include "../premeeting_service_wrap_core.h"
#include "../directshare_helper_wrap_core.h"
#import "Header_include.h"
#import "authServiceDelegate.h"
ZPremeetingServiceWrap::~ZPremeetingServiceWrap()
{
     [[[ZoomSDK sharedSDK] getPremeetingService]setDelegate:nil];
    m_pSink = 0;
}

ZPremeetingServiceWrap::ZPremeetingServiceWrap()
{
    m_pSink = 0;
}

void ZPremeetingServiceWrap::Init()
{

}

void ZPremeetingServiceWrap::Uninit()
{
    
}

void ZPremeetingServiceWrap::SetSink(ZNativeSDKPreMeetingWrapSink *pSink)
{
    [[[ZoomSDK sharedSDK] getPremeetingService] setDelegate:[authServiceDelegate share]];
    m_pSink = pSink;
}

ZNSDKError ZPremeetingServiceWrap::ScheduleMeeting(ZNWndPosition wndParam)
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSWindow* scheduleWindow = [[[NSWindow alloc] init] autorelease];
    ZoomSDKError ret = [pre showScheduleEditMeetingWindow:YES Window:&scheduleWindow MeetingID:0];
    NSString *X = [NSString stringWithCString:wndParam.z_left.c_str() encoding:NSUTF8StringEncoding];
    NSString *Y = [NSString stringWithCString:wndParam.z_top.c_str() encoding:NSUTF8StringEncoding];
    NSString *W = [NSString stringWithCString:wndParam.z_width.c_str() encoding:NSUTF8StringEncoding];
    NSString *H = [NSString stringWithCString:wndParam.z_height.c_str() encoding:NSUTF8StringEncoding];
    [scheduleWindow  setFrame:NSMakeRect(X.integerValue, Y.integerValue, W.integerValue, H.integerValue) display:YES];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZPremeetingServiceWrap::ScheduleMeeting()
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSWindow* scheduleWindow = [[[NSWindow alloc] init] autorelease];
    ZoomSDKError ret = [pre showScheduleEditMeetingWindow:YES Window:&scheduleWindow MeetingID:0];
    if (ret == ZoomSDKError_Success) {
        [scheduleWindow center];
    }
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZPremeetingServiceWrap::EditMeeting(unsigned long long meetingUniqueID)
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    if (meetingUniqueID == 0) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    NSWindow* scheduleWindow = [[[NSWindow alloc] init] autorelease];
    ZoomSDKError ret = [pre showScheduleEditMeetingWindow:YES Window:&scheduleWindow MeetingID:meetingUniqueID];
    if (ret == ZoomSDKError_Success) {
        [scheduleWindow center];
    }
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZPremeetingServiceWrap::EditMeeting(ZNWndPosition wndParam, unsigned long long meetingUniqueID)
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    if (meetingUniqueID == 0) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    NSWindow* scheduleWindow = [[[NSWindow alloc] init] autorelease];
    ZoomSDKError ret = [pre showScheduleEditMeetingWindow:YES Window:&scheduleWindow MeetingID:meetingUniqueID];
    if (ret == ZoomSDKError_Success) {
        NSString *X = [NSString stringWithCString:wndParam.z_left.c_str() encoding:NSUTF8StringEncoding];
        NSString *Y = [NSString stringWithCString:wndParam.z_top.c_str() encoding:NSUTF8StringEncoding];
        NSString *W = [NSString stringWithCString:wndParam.z_width.c_str() encoding:NSUTF8StringEncoding];
        NSString *H = [NSString stringWithCString:wndParam.z_height.c_str() encoding:NSUTF8StringEncoding];
        [scheduleWindow  setFrame:NSMakeRect(X.integerValue, Y.integerValue, W.integerValue, H.integerValue) display:YES];
    }
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZPremeetingServiceWrap::ListMeeting()
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [pre listMeeting];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZPremeetingServiceWrap::DeleteMeeting(unsigned long long meetingUniqueID)
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    if (!meetingUniqueID ) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [pre deleteMeeting:meetingUniqueID];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

#pragma mark  DirectShare
ZDirectShareHelperWrap::ZDirectShareHelperWrap()
{
    m_pSink = 0;
}
ZDirectShareHelperWrap::~ZDirectShareHelperWrap()
{
    [[[[ZoomSDK sharedSDK] getPremeetingService] getDirectShareHelper] setDelegate:nil];
    m_pSink = 0;
}

void ZDirectShareHelperWrap::Init()
{
    
}

void ZDirectShareHelperWrap::Uninit()
{
    
}

void ZDirectShareHelperWrap::SetSink(ZNativeSDKDirectShareHelperWrapSink *pSink)
{

    [[[[ZoomSDK sharedSDK] getPremeetingService] getDirectShareHelper] setDelegate:[authServiceDelegate share]];
    m_pSink = pSink;
}

ZNSDKError ZDirectShareHelperWrap::CanStartDirectShare()
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKDirectShareHelper *handle = [pre getDirectShareHelper];
    if (!handle) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [handle canDirectShare];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZDirectShareHelperWrap::StartDirectShare()
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZNSDKError  error = CanStartDirectShare();
    if (error != ZNSDKERR_SUCCESS) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKDirectShareHelper *handle = [pre getDirectShareHelper];
    if (!handle) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [handle startDirectShare];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZDirectShareHelperWrap::StopDirectShare()
{
    ZoomSDKPremeetingService *pre = [[ZoomSDK sharedSDK] getPremeetingService];
    if (!pre) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKDirectShareHelper *handle = [pre getDirectShareHelper];
    if (!handle) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [handle stopDirectShare];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZDirectShareHelperWrap::IsDirectShareInProgress()
{
    DirectShareStatus status = [[authServiceDelegate share] getDirectShare];
    if (status == DirectShareStatus_InProgress) {
        return YES;
    }
    return NO;
}

ZNSDKError ZDirectShareHelperWrap::TryWithMeetingNumber(unsigned long long meetingNumber)
{
    DirectShareStatus status = [[authServiceDelegate share] getDirectShare];
    if (status == DirectShareStatus_WrongMeetingIDOrSharingKey || status == DirectShareStatus_NeedMeetingIDOrSharingKey) {

        ZoomSDKDirectShareHandler *handle = [[authServiceDelegate share] getDirectShareHandler];
        if (meetingNumber && handle != nil) {
            NSNumber *num = [NSNumber numberWithUnsignedLong:meetingNumber];
            NSString *number = [num stringValue];
            if (number != nil) {
                ZoomSDKError ret = [handle inputMeetingNumber:number];
                nativeErrorTypeHelp  Help_type;
                return Help_type.ZoomSDKErrorType(ret);
            }
        }
        return ZNSDKERR_INVALID_PARAMETER;
    }
    return ZNSDKERR_WRONG_USEAGE;
}

ZNSDKError ZDirectShareHelperWrap::TryWithPairingCode(ZoomSTRING pairingCode)
{
    DirectShareStatus status = [[authServiceDelegate share] getDirectShare];
    if (status == DirectShareStatus_WrongMeetingIDOrSharingKey || status == DirectShareStatus_NeedMeetingIDOrSharingKey) {
        
        ZoomSDKDirectShareHandler *handle = [[authServiceDelegate share] getDirectShareHandler];
        if (pairingCode.length() > 0 && handle != nil) {
            NSString *number = [NSString stringWithCString:pairingCode.c_str() encoding:NSUTF8StringEncoding];
            ZoomSDKError ret = [handle inputSharingKey:number];
            nativeErrorTypeHelp  Help_type;
            return Help_type.ZoomSDKErrorType(ret);
        }
        return ZNSDKERR_INVALID_PARAMETER;
    }
    return ZNSDKERR_WRONG_USEAGE;
    
}

ZNSDKError ZDirectShareHelperWrap::Cancel()
{
    ZoomSDKDirectShareHandler *handle = [[authServiceDelegate share] getDirectShareHandler];
    if (handle  == nil) {
        return  ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [handle cancel];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
    
}
//callback
void ZPremeetingServiceWrap::onScheduleOrEditMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID)
{
    if (m_pSink) {
        m_pSink->onScheduleOrEditMeeting(result, meetingUniqueID);
    }
}

void ZPremeetingServiceWrap::onListMeeting(ZNPremeetingAPIResult result, std::vector<unsigned long long> lst_meeting_list)
{
    if (m_pSink) {
        m_pSink->onListMeeting(result, lst_meeting_list);
    }
}

void ZPremeetingServiceWrap::onDeleteMeeting(ZNPremeetingAPIResult result)
{
    if (m_pSink) {
        m_pSink->onDeleteMeeting(result);
    }
}


void ZDirectShareHelperWrap::OnDirectShareStatusUpdate(ZNDirectShareStatus status)
{
    if (m_pSink) {
        m_pSink->OnDirectShareStatusUpdate(status);
    }
}
