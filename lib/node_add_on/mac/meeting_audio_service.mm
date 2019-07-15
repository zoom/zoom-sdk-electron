
#include "Header_include.h"
#include "sdk_native_error.h"
#include "../meeting_audio_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#import "meetingServiceDelegate.h"
extern nativeErrorTypeHelp  Help_type;
ZMeetingAudioWrap &ZMeetingServiceWrap::GetMeetingAudioCtrl(){
    return m_meeting_audio_ctrl;
}
ZMeetingAudioWrap::ZMeetingAudioWrap(){
   m_pSink = 0;

}

ZMeetingAudioWrap::~ZMeetingAudioWrap(){
    
 
    m_pSink = 0;
}

void ZMeetingAudioWrap::Init(){
    

}
void ZMeetingAudioWrap::Uninit(){
    
}

void ZMeetingAudioWrap::SetSink(IZNativeSDKMeetingAudioWrapSink *pSink){
 
    m_pSink= pSink;
}

ZNSDKError ZMeetingAudioWrap::MuteAudio(ZoomSTRING userid, bool allowUnmuteBySelf){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        NSString *ID = [NSString stringWithCString:userid.c_str() encoding:NSUTF8StringEncoding];
        if (ID == nil) {
            return ZNSDKERR_INVALID_PARAMETER;
        }
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_MuteAudio userID:ID.intValue onScreen:ScreenType_First];
        
        if (ret == ZoomSDKError_Success) {
            if (allowUnmuteBySelf == true) {
                ret = [action actionMeetingWithCmd:ActionMeetingCmd_EnableUnmuteBySelf userID:ID.intValue onScreen:ScreenType_First];
            }else{
                ret = [action actionMeetingWithCmd:ActionMeetingCmd_DisableUnmuteBySelf userID:ID.intValue onScreen:ScreenType_First];
            }
            
        }
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZNSDKError ZMeetingAudioWrap::UnMuteAudio(ZoomSTRING userid){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        NSString *ID = [NSString stringWithCString:userid.c_str() encoding:NSUTF8StringEncoding];
        if (ID == nil) {
            return ZNSDKERR_INVALID_PARAMETER;
        }
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_UnMuteAudio userID:ID.intValue onScreen:ScreenType_First];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingAudioWrap::JoinVoip(){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_JoinVoip userID:0 onScreen:ScreenType_First];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingAudioWrap::LeaveVoip(){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (service && action) {

        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_LeaveVoip userID:0 onScreen:ScreenType_First];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


//callback
void ZMeetingAudioWrap::onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList){
    
    if (m_pSink) {
        
        m_pSink->onUserAudioStatusChange(lstAudioStatusChange, strAudioStatusList);
    }
}
