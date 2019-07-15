

#include "../meeting_video_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
#import "meetingServiceDelegate.h"
extern nativeErrorTypeHelp  Help_type;

ZMeetingVideoWrap  &ZMeetingServiceWrap::GetMeetingVideoCtrl(){
    return m_meeting_video_ctrl;
}

ZMeetingVideoWrap::ZMeetingVideoWrap(){
    m_pSink = 0;
    
}

ZMeetingVideoWrap::~ZMeetingVideoWrap(){

    m_pSink = 0;
}

void ZMeetingVideoWrap::Init(){
    
    
    
}

void ZMeetingVideoWrap::Uninit(){
    
}

void ZMeetingVideoWrap::SetSink(IZNativeSDKMeetingVideoWrapSink *pSink){
    
    m_pSink = pSink;
}

ZNSDKError ZMeetingVideoWrap::MuteVideo(){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_MuteVideo userID:0 onScreen:ScreenType_First];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::UnMuteVideo(){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_UnMuteVideo userID:0 onScreen:ScreenType_First];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::PinVideo(bool bPin, bool bFirstView, ZoomSTRING userId){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        NSString *ID = [NSString stringWithCString:userId.c_str() encoding:NSUTF8StringEncoding];
        if (ID == nil) {
            return ZNSDKERR_INVALID_PARAMETER;
        }
        ZoomSDKError ret(ZoomSDKError_UnKnow);
        if (bFirstView) {
            ret = [action actionMeetingWithCmd:ActionMeetingCmd_PinVideo userID:ID.intValue onScreen:ScreenType_First];
        }else{
            ret = [action actionMeetingWithCmd:ActionMeetingCmd_PinVideo userID:ID.intValue onScreen:ScreenType_Second];
        }
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::SpotlightVideo(bool bSpotlight, ZoomSTRING userId){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        NSString *ID = [NSString stringWithCString:userId.c_str() encoding:NSUTF8StringEncoding];
        if (ID == nil) {
            return ZNSDKERR_INVALID_PARAMETER;
        }
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_SpotlightVideo userID:ID.intValue onScreen:ScreenType_First];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingVideoWrap::HideOrShowNoVideoUserOnVideoWall(bool bHide){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingUIController *action = [service getMeetingUIController];
    if (service && action) {
        ZoomSDKError ret = [action hideOrShowNoVideoUserOnVideoWall:bHide];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}




//callback
void ZMeetingVideoWrap::onUserVideoStatusChange(ZoomSTRING userId, ZNVideoStatus status){
    
    if (m_pSink) {
        m_pSink->onUserVideoStatusChange(userId, status);
    }
    
}
