
#include "Header_include.h"
#include "sdk_native_error.h"
#include "../meeting_audio_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#import "meetingServiceDelegate.h"
ZMeetingAudioWrap &ZMeetingServiceWrap::GetMeetingAudioCtrl()
{
    return m_meeting_audio_ctrl;
}
ZMeetingAudioWrap::ZMeetingAudioWrap()
{
   m_pSink = 0;
}

ZMeetingAudioWrap::~ZMeetingAudioWrap()
{
    m_pSink = 0;
}

void ZMeetingAudioWrap::Init()
{

}
void ZMeetingAudioWrap::Uninit()
{
    
}

void ZMeetingAudioWrap::SetSink(ZNativeSDKMeetingAudioWrapSink *pSink)
{
    m_pSink= pSink;
}

ZNSDKError ZMeetingAudioWrap::MuteAudio(unsigned int userid, bool allowUnmuteBySelf)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret(ZoomSDKError_UnKnow);
        if (userid == 0) {
            ret = [action actionMeetingWithCmd:ActionMeetingCmd_MuteAll userID:userid onScreen:ScreenType_First];
        }else{
            ret = [action actionMeetingWithCmd:ActionMeetingCmd_MuteAudio userID:userid onScreen:ScreenType_First];
            if (allowUnmuteBySelf == true) {
                ret = [action actionMeetingWithCmd:ActionMeetingCmd_EnableUnmuteBySelf userID:userid onScreen:ScreenType_First];
            }else{
                ret = [action actionMeetingWithCmd:ActionMeetingCmd_DisableUnmuteBySelf userID:userid onScreen:ScreenType_First];
            }
        }
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZNSDKError ZMeetingAudioWrap::UnMuteAudio(unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret(ZoomSDKError_UnKnow);
        if (userid == 0) {
            ret = [action actionMeetingWithCmd:ActionMeetingCmd_UnmuteAll userID:userid onScreen:ScreenType_First];
        }else{
            ret = [action actionMeetingWithCmd:ActionMeetingCmd_UnMuteAudio userID:userid onScreen:ScreenType_First];
        }
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingAudioWrap::JoinVoip()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {
        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_JoinVoip userID:0 onScreen:ScreenType_First];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingAudioWrap::LeaveVoip()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *action = [service getMeetingActionController];
    if (action) {

        ZoomSDKError ret = [action actionMeetingWithCmd:ActionMeetingCmd_LeaveVoip userID:0 onScreen:ScreenType_First];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


//callback
void ZMeetingAudioWrap::onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList)
{
    if (m_pSink) {
        m_pSink->onUserAudioStatusChange(lstAudioStatusChange, strAudioStatusList);
    }
}

void ZMeetingAudioWrap::onUserActiveAudioChange(ZNList<unsigned int> lstActiveAudio)
{
    if (m_pSink) {
        m_pSink->onUserActiveAudioChange(lstActiveAudio);
    }
}
