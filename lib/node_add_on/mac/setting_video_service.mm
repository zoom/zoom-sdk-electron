#include "../setting_video_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#import "Header_include.h"
#include "sdk_native_error.h"
extern nativeErrorTypeHelp  Help_type;
ZSettingVideoWrap::ZSettingVideoWrap(){
    
}

ZSettingVideoWrap::~ZSettingVideoWrap(){
    
}

void ZSettingVideoWrap::Init(){
    
}

void ZSettingVideoWrap::Uninit(){
    
}

ZNSDKError  ZSettingVideoWrap::SelectCamera(ZoomSTRING deviceId){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    NSString *ID = [NSString stringWithCString:deviceId.c_str() encoding:NSUTF8StringEncoding];
    if (ID == nil) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    
    if(video){
        ZoomSDKError ret = [video selectCamera:ID];
        return Help_type.ZoomSDKErrorType(ret);
    }
    
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<ZNCameraInfo> ZSettingVideoWrap::GetCameraList(){
    
    ZNList<ZNCameraInfo> list;
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    if (!service){
        return list;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    
    if(video){
        NSArray *cameraList = [video getCameraList];
        ZNCameraInfo  cameraInfo;
        if (!cameraList || cameraList.count == 0) {
            return list;
        }
        for (SDKDeviceInfo *info in cameraList) {
            NSString *DeviceID = [info getDeviceID];
            NSString *DeviceName = [info getDeviceName];
            bool  isSelected = [info isSelectedDevice];
            cameraInfo.deviceId = DeviceID.UTF8String;
            cameraInfo.deviceName = DeviceName.UTF8String;
            cameraInfo.isSelectedDevice = isSelected;
            list.push_back(cameraInfo);
        }
        
        return list;
    }
    return list;
}

ZNSDKError  ZSettingVideoWrap::EnableVideoMirrorEffect(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    bool isEnable = this->IsVideoMirrorEffectEnable();
    if (isEnable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    if(video){
        ZoomSDKError ret = [video enableMirrorEffect:bEnable];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingVideoWrap::EnableFaceBeautyEffect(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    bool isEnable = this->IsFaceBeautyEffectEnabled();
    if (isEnable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    if(video){
        ZoomSDKError ret = [video enableBeautyFace:bEnable];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}

bool ZSettingVideoWrap::IsVideoMirrorEffectEnable(){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        
        return [video isMirrorEffectEnabled];
    }
    return false;
    
}


bool ZSettingVideoWrap::IsFaceBeautyEffectEnabled(){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        
        return [video isBeautyFaceEnabled];
    }
    return false;
}
