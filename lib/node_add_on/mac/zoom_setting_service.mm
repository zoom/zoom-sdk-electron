#include "../meeting_service_wrap_core.h"
#include "../setting_service_wrap_core.h"
#import "Header_include.h"
#include "sdk_native_error.h"
extern nativeErrorTypeHelp  Help_type;
ZSettingServiceWrap::ZSettingServiceWrap(){
    
}

ZSettingServiceWrap::~ZSettingServiceWrap(){
    
}

ZSettingVideoWrap &ZSettingServiceWrap::GetSettingVideoCtrl(){
    
    return m_setting_video_ctrl;
}
ZSettingAudioWrap &ZSettingServiceWrap::GetSettingAudioCtrl(){
    
    return m_setting_audio_ctrl;
}

ZSettingGeneralWrap &ZSettingServiceWrap::GetSettingGeneralCtrl(){
    
    return m_setting_general_ctrl;
}

ZSettingRecordingWrap &ZSettingServiceWrap::GetSettingRecordingCtrl(){
    
    return m_setting_recording_ctrl;
}


void ZSettingServiceWrap::Init(){
    
}

void ZSettingServiceWrap::Uninit(){
    
}


ZNSDKError ZSettingServiceWrap::ShowSettingDlg(ZNShowSettingDlgParam param){
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (controller) {
        ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Setting window:nil show:YES InPanel:YES frame:NSZeroRect];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return  ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingServiceWrap::HideSettingDlg(){
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (controller) {
        ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Setting window:nil show:NO InPanel:NO frame:NSZeroRect];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return  ZNSDKERR_SERVICE_FAILED;
}


