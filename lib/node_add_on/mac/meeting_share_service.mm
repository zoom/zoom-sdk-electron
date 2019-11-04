
#include "Header_include.h"
#include "../meeting_share_wrap_core.h"
#include "sdk_native_error.h"
#include "../meeting_service_wrap_core.h"
ZMeetingShareWrap &ZMeetingServiceWrap::GetMeetingShareCtrl()
{
    return m_meeting_share_ctrl;
}

ZMeetingShareWrap::ZMeetingShareWrap()
{
    m_pSink = 0;
}

ZMeetingShareWrap::~ZMeetingShareWrap()
{
    m_pSink = 0;
}

void ZMeetingShareWrap::Init()
{
    
}

void ZMeetingShareWrap::Uninit()
{
    
}

void ZMeetingShareWrap::SetSink(ZNativeSDKMeetingShareWrapSink *pSink)
{
    m_pSink = pSink;
}

ZNSDKError ZMeetingShareWrap::StartAppShare(ZoomSTRING hShareApp)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString *ID = [NSString stringWithCString:hShareApp.c_str() encoding:NSUTF8StringEncoding];
    CGWindowID windowID = ID.intValue;
    ZoomSDKASController *as = [service getASController];
    if (as) {
        ZoomSDKError error = [as startAppShare:windowID];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingShareWrap::StartMonitorShare(ZoomSTRING monitorID)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString *ID = [NSString stringWithCString:monitorID.c_str() encoding:NSUTF8StringEncoding];
    CGDirectDisplayID  displayID = ID.intValue;
    ZoomSDKASController *as = [service getASController];
    if (as) {
        ZoomSDKError error = [as startMonitorShare:displayID];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingShareWrap::StopShare()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKASController *as = [service getASController];
    if (as) {
        ZoomSDKError error = [as stopShare];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

//callback
void ZMeetingShareWrap::onSharingStatus(ZNShareStatus status, unsigned int userId)
{
    if (m_pSink)
    {
        m_pSink->onSharingStatus(status, userId);
    }
}
