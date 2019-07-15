#include "../setting_audio_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"

extern nativeErrorTypeHelp  Help_type;
ZSettingAudioWrap::ZSettingAudioWrap(){
    
}
ZSettingAudioWrap::~ZSettingAudioWrap(){
    
}


void ZSettingAudioWrap::Init(){
    
}


void ZSettingAudioWrap::Uninit(){
    
}

ZNSDKError ZSettingAudioWrap::SelectMic(ZoomSTRING deviceId, ZoomSTRING deviceName){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    NSString  *ID = [NSString stringWithCString:deviceId.c_str() encoding:NSUTF8StringEncoding];
    NSString  *name = [NSString stringWithCString:deviceName.c_str() encoding:NSUTF8StringEncoding];
    if (!ID || !name) {
        
        return ZNSDKERR_INVALID_PARAMETER;
    }
    if(service && audio){
        ZoomSDKError ret = [audio selectAudioDevice:YES DeviceID:ID DeviceName:name];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZNList<ZNMicInfo> ZSettingAudioWrap::GetMicList(){
   
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    ZNList<ZNMicInfo> list;
    if(service && audio){
        NSArray *micList = [audio getAudioDeviceList:YES];
        ZNMicInfo  micInfo;
        if (!micList || micList.count == 0) {
            return list;
        }
        for (SDKDeviceInfo *info in micList) {
            NSString *DeviceID = [info getDeviceID];
            NSString *DeviceName = [info getDeviceName];
            bool  isSelected = [info isSelectedDevice];
            micInfo.deviceId = DeviceID.UTF8String;
            micInfo.deviceName = DeviceName.UTF8String;
            micInfo.isSelectedDevice = isSelected;
            list.add(micInfo);
        }
        
        return list;
    }
    return list;
    
}

ZNSDKError ZSettingAudioWrap::SelectSpeaker(ZoomSTRING deviceId, ZoomSTRING deviceName){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    NSString  *ID = [NSString stringWithCString:deviceId.c_str() encoding:NSUTF8StringEncoding];
    NSString  *name = [NSString stringWithCString:deviceName.c_str() encoding:NSUTF8StringEncoding];
    if (!ID || !name) {
        
        return ZNSDKERR_INVALID_PARAMETER;
    }
    if(service && audio){
        ZoomSDKError ret = [audio selectAudioDevice:NO DeviceID:ID DeviceName:name];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}

ZNList<ZNSpeakerInfo> ZSettingAudioWrap::GetSpeakerList(){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    ZNList<ZNSpeakerInfo> list;
    if(service && audio){
        NSArray *speakList = [audio getAudioDeviceList:NO];
        ZNSpeakerInfo  speakInfo;
        if (!speakList || speakList.count == 0) {
            return list;
        }
        for (SDKDeviceInfo *info in speakList) {
            NSString *DeviceID = [info getDeviceID];
            NSString *DeviceName = [info getDeviceName];
            bool  isSelected = [info isSelectedDevice];
            speakInfo.deviceId = DeviceID.UTF8String;
            speakInfo.deviceName = DeviceName.UTF8String;
            speakInfo.isSelectedDevice = isSelected;
            list.add(speakInfo);
        }
        
        return list;
    }
    return list;
}

bool ZSettingAudioWrap::IsAutoJoinAudioEnabled(){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(service && audio){
        
        return [audio isJoinAudoWhenJoinMeetingOn];
    }
    return false;
}

bool ZSettingAudioWrap::IsAutoAdjustMicEnabled(){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(service && audio){
        
        return [audio isAutoAdjustMicOn];
    }
    return  false;
}

ZNSDKError ZSettingAudioWrap::EnableAutoJoinAudio(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    bool isJoin = this->IsAutoJoinAudioEnabled();
    if (isJoin == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    if(service && audio){
        
        ZoomSDKError ret = [audio enableAutoJoinVoip:bEnable];
        return Help_type.ZoomSDKErrorType(ret);
 
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingAudioWrap::EnableAutoAdjustMic(bool bEnable){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK]getSettingService];
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    bool isJoin = this->IsAutoAdjustMicEnabled();
    if (isJoin == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    if(service && audio){
        
        ZoomSDKError ret = [audio enableAutoAdjustMic:bEnable];
        return Help_type.ZoomSDKErrorType(ret);
        
    }
    return ZNSDKERR_SERVICE_FAILED;
}
