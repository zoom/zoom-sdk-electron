
#include "Header_include.h"
#include "../meeting_share_wrap_core.h"
#include "sdk_native_error.h"
#include "../meeting_service_wrap_core.h"

extern nativeErrorTypeHelp  Help_type;


ZMeetingShareWrap &ZMeetingServiceWrap::GetMeetingShareCtrl(){
    
    return m_meeting_share_ctrl;
}

ZMeetingShareWrap::ZMeetingShareWrap(){
    
}

ZMeetingShareWrap::~ZMeetingShareWrap(){
    
}

void ZMeetingShareWrap::Init(){
    
}

void ZMeetingShareWrap::Uninit(){
    
}

ZNSDKError ZMeetingShareWrap::StartAppShare(ZoomSTRING hShareApp){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *as = [service getASController];
    NSString *ID = [NSString stringWithCString:hShareApp.c_str() encoding:NSUTF8StringEncoding];
    CGWindowID windowID = ID.intValue;
    if (service && as) {
        ZoomSDKError error = [as startAppShare:windowID];
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}

ZNSDKError ZMeetingShareWrap::StartMonitorShare(ZoomSTRING monitorID){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *as = [service getASController];
    NSString *ID = [NSString stringWithCString:monitorID.c_str() encoding:NSUTF8StringEncoding];
    CGDirectDisplayID  displayID = ID.intValue;
    if (service && as) {
        ZoomSDKError error = [as startMonitorShare:displayID];
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}

ZNSDKError ZMeetingShareWrap::StopShare(){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *as = [service getASController];
    if (service && as) {
        ZoomSDKError error = [as stopShare];
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}


