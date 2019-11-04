#include "../setting_audio_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"
ZSettingAudioWrap::ZSettingAudioWrap()
{
    
}

ZSettingAudioWrap::~ZSettingAudioWrap()
{
    
}

void ZSettingAudioWrap::Init()
{
    
}

void ZSettingAudioWrap::Uninit()
{
    
}

ZNSDKError ZSettingAudioWrap::SelectMic(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
    NSString  *ID = [NSString stringWithCString:deviceId.c_str() encoding:NSUTF8StringEncoding];
    NSString  *name = [NSString stringWithCString:deviceName.c_str() encoding:NSUTF8StringEncoding];
    if (!ID || !name) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(audio){
        ZoomSDKError ret = [audio selectAudioDevice:YES DeviceID:ID DeviceName:name];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZNList<ZNMicInfo> ZSettingAudioWrap::GetMicList()
{
    ZNList<ZNMicInfo> list;
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return list;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
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
            list.push_back(micInfo);
        }
        return list;
    }
    return list;
}

ZNSDKError ZSettingAudioWrap::SelectSpeaker(ZoomSTRING deviceId, ZoomSTRING deviceName){
    
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString  *ID = [NSString stringWithCString:deviceId.c_str() encoding:NSUTF8StringEncoding];
    NSString  *name = [NSString stringWithCString:deviceName.c_str() encoding:NSUTF8StringEncoding];
    if (!ID || !name) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(service && audio){
        ZoomSDKError ret = [audio selectAudioDevice:NO DeviceID:ID DeviceName:name];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
    
}

ZNList<ZNSpeakerInfo> ZSettingAudioWrap::GetSpeakerList()
{
    ZNList<ZNSpeakerInfo> list;
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return list;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
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
            list.push_back(speakInfo);
        }
        
        return list;
    }
    return list;
}

bool ZSettingAudioWrap::IsAutoJoinAudioEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(audio){
        return [audio isJoinAudoWhenJoinMeetingOn];
    }
    return false;
}

bool ZSettingAudioWrap::IsAutoAdjustMicEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(audio){
        return [audio isAutoAdjustMicOn];
    }
    return  false;
}

ZNSDKError ZSettingAudioWrap::EnableAutoJoinAudio(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service)
    {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool isJoin = IsAutoJoinAudioEnabled();
    if (isJoin == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(audio)
    {
        ZoomSDKError ret = [audio enableAutoJoinVoip:bEnable];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingAudioWrap::EnableAutoAdjustMic(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool isJoin = IsAutoAdjustMicEnabled();
    if (isJoin == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(audio){
        ZoomSDKError ret = [audio enableAutoAdjustMic:bEnable];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}
