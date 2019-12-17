#include "../setting_audio_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"
#import "settingServiceDelegate.h"
ZSettingAudioWrap::ZSettingAudioWrap()
{
    m_pSink = 0;
}

ZSettingAudioWrap::~ZSettingAudioWrap()
{
    ZoomSDKSettingService* service = [[ZoomSDK sharedSDK] getSettingService];
    if (service) {
        ZoomSDKAudioSetting* audio = [service getAudioSetting];
        if (audio) {
            [audio setDelegate:nil];
        }
    }
    m_pSink = 0;
}

void ZSettingAudioWrap::Init()
{
    
}

void ZSettingAudioWrap::Uninit()
{
    
}

void ZSettingAudioWrap::SetSink(ZNativeSDKAudioSettingContextWrapSink* pSink)
{
    ZoomSDKSettingService* service = [[ZoomSDK sharedSDK] getSettingService];
    if (service) {
        ZoomSDKAudioSetting* audio = [service getAudioSetting];
        if (audio) {
            [audio setDelegate:[settingServiceDelegate share]];
        }
    }
    m_pSink = pSink;
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

ZNSDKError ZSettingAudioWrap::EnableStereoAudio(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [audio enableStero:bEnable];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZSettingAudioWrap::IsStereoAudioEnable()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    BOOL enable = [audio isEnableStereoOn];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingAudioWrap::EnableMicOriginalInput(bool bEnable)
{
//    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
//    if (!service){
//        return ZNSDKERR_SERVICE_FAILED;
//    }
//    ZoomSDKAudioSetting *audio = [service getAudioSetting];
//    if(!audio){
//        return ZNSDKERR_SERVICE_FAILED;
//    }
//    ZoomSDKError ret = [audio enableUseOriginalSound:bEnable];
//    nativeErrorTypeHelp  Help_type;
//    return Help_type.ZoomSDKErrorType(ret);
    
    //    NS_DEPRECATED_MAC(4.1, 4.3);
    return ZNSDKERR_NO_IMPL;
}

bool ZSettingAudioWrap::IsMicOriginalInputEnable()
{
//    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
//    if (!service){
//        return ZNSDKERR_SERVICE_FAILED;
//    }
//    ZoomSDKAudioSetting *audio = [service getAudioSetting];
//    if(!audio){
//        return ZNSDKERR_SERVICE_FAILED;
//    }
//    BOOL enable = [audio isUseOriginalSoundOn];
//    return (enable == YES) ? true : false;
    
    //NS_DEPRECATED_MAC(4.1, 4.3);
    return ZNSDKERR_NO_IMPL;
}

ZNSDKError ZSettingAudioWrap::EnableHoldSpaceKeyToSpeak(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [audio enablePushToTalk:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingAudioWrap::IsHoldSpaceKeyToSpeakEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    BOOL enable = [audio isTemporarilyUnmuteOn];
    return (enable == YES) ? true : NO;
}

ZNSDKError ZSettingAudioWrap::EnableAlwaysMuteMicWhenJoinVoip(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [audio enableMuteMicJoinVoip:bEnable];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZSettingAudioWrap::IsAlwaysMuteMicWhenJoinVoipEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    BOOL enable = [audio isMuteMicWhenJoinMeetingOn];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingAudioWrap::EnableSuppressAudioNotify(bool bEnable)
{}

bool ZSettingAudioWrap::IsSuppressAudioNotifyEnabled()
{}

ZNSDKError ZSettingAudioWrap::SetMicVol(float& value)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [audio setAudioDeviceVolume:YES Volume:value];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZSettingAudioWrap::GetMicVol(float& value)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    value = [audio getAudioDeviceVolume:YES];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZSettingAudioWrap::SetSpeakerVol(float& value)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [audio setAudioDeviceVolume:NO Volume:value];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZSettingAudioWrap::GetSpeakerVol(float& value)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    value = [audio getAudioDeviceVolume:NO];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZSettingAudioWrap::EnableEchoCancellation(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [audio enableEchoCancellation:bEnable];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

bool ZSettingAudioWrap::IsEchoCancellationEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAudioSetting *audio = [service getAudioSetting];
    if(!audio){
        return ZNSDKERR_SERVICE_FAILED;
    }
    BOOL enable = [audio isEchoCancellationOn];
    return (enable == YES) ? true : false;
}
//callback
void ZSettingAudioWrap::onComputerMicDeviceChanged(ZNList<ZNMicInfo> newMicList)
{
    if (m_pSink) {
        m_pSink->onComputerMicDeviceChanged(newMicList);
    }
}
void ZSettingAudioWrap::onComputerSpeakerDeviceChanged(ZNList<ZNSpeakerInfo> newSpeakerList)
{
    if (m_pSink) {
        m_pSink->onComputerSpeakerDeviceChanged(newSpeakerList);
    }
}
void ZSettingAudioWrap::onDefaultMicDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
    return;
}
void ZSettingAudioWrap::onDefaultSpeakerDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
    return;
}
