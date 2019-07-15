
#include "../setting_recording_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"
extern nativeErrorTypeHelp  Help_type;

ZSettingRecordingWrap::ZSettingRecordingWrap(){
    
}

ZSettingRecordingWrap::~ZSettingRecordingWrap(){
    
}

void ZSettingRecordingWrap::Init(){
    
}

void ZSettingRecordingWrap::Uninit(){
    
}


ZNSDKError ZSettingRecordingWrap::SetRecordingPath(ZoomSTRING szPath){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKRecordSetting *record = [service getRecordSetting];
    NSString *path = [NSString stringWithCString:szPath.c_str() encoding:NSUTF8StringEncoding];
    if (!path) {
        
        return ZNSDKERR_INVALID_PARAMETER;
    }
    if(service && record){
        
        ZoomSDKError ret = [record setRecordingPath:path];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZoomSTRING ZSettingRecordingWrap::GetRecordingPath(){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKRecordSetting *record = [service getRecordSetting];
    if(service && record){
        NSString *path = [record getRecordingPath];
        return path.UTF8String;
    }
    return "";
    
}
