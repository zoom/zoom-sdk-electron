#include "../setting_general_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"
extern nativeErrorTypeHelp  Help_type;

ZSettingGeneralWrap::ZSettingGeneralWrap(){
    
}

ZSettingGeneralWrap::~ZSettingGeneralWrap(){
    
}


void ZSettingGeneralWrap::Init(){
    
}

void ZSettingGeneralWrap::Uninit(){
    
}

ZNSDKError ZSettingGeneralWrap::EnableDualScreenMode(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKGeneralSetting *general = [service getGeneralSetting];
    if(service && general){
        
        ZoomSDKError ret =[general enableMeetingSetting:bEnable SettingCmd:MeetingSettingCmd_DualScreenMode];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingGeneralWrap::TurnOffAeroModeInSharing(bool bEnable){
    
    return ZNSDKERR_NO_IMPL;
    
}

ZNSDKError ZSettingGeneralWrap::EnableAutoFitToWindowWhenViewSharing(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKGeneralSetting *general = [service getGeneralSetting];
    if(service && general){
        
        ZoomSDKError ret =[general enableMeetingSetting:bEnable SettingCmd:MeetingSettingCmd_AutoFitToWindowWhenViewShare];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingGeneralWrap::EnableAutoFullScreenVideoWhenJoinMeeting(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKGeneralSetting *general = [service getGeneralSetting];
    if(service && general){
        
        ZoomSDKError ret =[general enableMeetingSetting:bEnable SettingCmd:MeetingSettingCmd_AutoFullScreenWhenJoinMeeting];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}
ZNSDKError ZSettingGeneralWrap::EnableSplitScreenMode(bool bEnable){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *general = [service getASController];
    if(service && general){
        
        ZoomSDKError ret =[general switchSplitScreenMode:bEnable];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}

bool ZSettingGeneralWrap::IsDualScreenModeEnabled(){
    
    return false;
}

bool ZSettingGeneralWrap::IsAeroModeInSharingTurnOff(){
    return false;
}

bool ZSettingGeneralWrap::IsAutoFitToWindowWhenViewSharingEnabled(){
    return false;
}
bool ZSettingGeneralWrap::IsAutoFullScreenVideoWhenJoinMeetingEnabled(){
    return false;
}
bool ZSettingGeneralWrap::IsSplitScreenModeEnabled(){
    return false;
}
