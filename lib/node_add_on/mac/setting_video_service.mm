#include "../setting_video_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#import "Header_include.h"
#include "sdk_native_error.h"
#import "settingServiceDelegate.h"
ZSettingVideoWrap::ZSettingVideoWrap()
{
    m_pSink = 0;
}

ZSettingVideoWrap::~ZSettingVideoWrap()
{
    ZoomSDKSettingService* service = [[ZoomSDK sharedSDK] getSettingService];
    if (service) {
        ZoomSDKVideoSetting* Video = [service getVideoSetting];
        if (Video) {
            ZoomSDKSettingTestVideoDeviceHelper *help = [Video getSettingVideoTestHelper];
            if (help) {
                 [help setDelegate:nil];
            }
        }
    }
    m_pSink = 0;
}

void ZSettingVideoWrap::Init()
{
    
}

void ZSettingVideoWrap::Uninit()
{
    
}

void ZSettingVideoWrap::SetSink(ZNativeSDKVideoSettingContextWrapSink* pSink)
{
    ZoomSDKSettingService* service = [[ZoomSDK sharedSDK] getSettingService];
    if (service) {
        ZoomSDKVideoSetting* Video = [service getVideoSetting];
        if (Video) {
            ZoomSDKSettingTestVideoDeviceHelper *help = [Video getSettingVideoTestHelper];
            if (help) {
                [help setDelegate:[settingServiceDelegate share]];
            }
        }
    }
    m_pSink = pSink;
}

ZNSDKError  ZSettingVideoWrap::SelectCamera(ZoomSTRING deviceId)
{
    NSString *ID = [NSString stringWithCString:deviceId.c_str() encoding:NSUTF8StringEncoding];
    if (ID == nil) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        ZoomSDKError ret = [video selectCamera:ID];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<ZNCameraInfo> ZSettingVideoWrap::GetCameraList()
{
    ZNList<ZNCameraInfo> list;
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
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

ZNSDKError  ZSettingVideoWrap::EnableVideoMirrorEffect(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    bool isEnable = IsVideoMirrorEffectEnable();
    if (isEnable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    if(video){
        ZoomSDKError ret = [video enableMirrorEffect:bEnable];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZSettingVideoWrap::EnableFaceBeautyEffect(bool bEnable)
{
    bool isEnable = IsFaceBeautyEffectEnabled();
    if (isEnable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        ZoomSDKError ret = [video enableBeautyFace:bEnable];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

bool ZSettingVideoWrap::IsVideoMirrorEffectEnable()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return NO;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL ret = [video isMirrorEffectEnabled];
        return (ret == YES) ?  true : false;
    }
    return false;
}

bool ZSettingVideoWrap::IsFaceBeautyEffectEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return NO;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL ret = [video isBeautyFaceEnabled];
        return (ret == YES) ?  true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableHDVideo(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsHDVideoEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [video enableCatchHDVideo:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingVideoWrap::IsHDVideoEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isCatchHDVideoOn];
        return (enable == YES) ? true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableAlwaysShowNameOnVideo(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsAlwaysShowNameOnVideoEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [video displayUserNameOnVideo:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingVideoWrap::IsAlwaysShowNameOnVideoEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isdisplayUserNameOnVideoOn];
        return (enable == YES) ? true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsAutoTurnOffVideoWhenJoinMeetingEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [video disableVideoJoinMeeting:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingVideoWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isMuteMyVideoWhenJoinMeetingOn];
        return (enable == YES) ? true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableAlwaysUse16v9(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsAlwaysUse16v9();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [video  onVideoCaptureOriginalSizeOr16To9:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingVideoWrap::IsAlwaysUse16v9()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isCatchHDVideoOn];
        return (enable == YES) ? true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableSpotlightSelf(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsSpotlightSelfEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [video onSpotlightMyVideoWhenISpeaker:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingVideoWrap::IsSpotlightSelfEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isSpotlightMyVideoOn];
        return (enable == YES) ? true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableHardwareEncode(bool bEnable)
{
    return ZNSDKERR_NO_IMPL;
}
bool ZSettingVideoWrap::IsHardwareEncodeEnabled()
{
    return false;
}
ZNSDKError ZSettingVideoWrap::Enable49VideoesInGallaryView(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = Is49VideoesInGallaryViewEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [video onDisplayUpTo49InWallView:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}


bool ZSettingVideoWrap::Is49VideoesInGallaryViewEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isCanDisplayUpTo49InWallView];
        return (enable == YES) ? true : false;
    }
    return false;
}

ZNSDKError ZSettingVideoWrap::EnableHideNoVideoUsersOnWallView(bool bEnable)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if (!video) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool zenable = IsHideNoVideoUsersOnWallViewEnabled();
    if (zenable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    BOOL enable = (bEnable == true) ? true : false;
    ZoomSDKError ret = [video hideNoVideoUser:enable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingVideoWrap::IsHideNoVideoUsersOnWallViewEnabled()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return false;
    }
    ZoomSDKVideoSetting *video = [service getVideoSetting];
    if(video){
        BOOL enable = [video isHideNoVideoUser];
        return (enable == YES) ? true : false;
    }
    return false;
}

void ZSettingVideoWrap::onComputerCamDeviceChanged(ZNList<ZNCameraInfo> newCameraList)
{
    if (m_pSink) {
        m_pSink->onComputerCamDeviceChanged(newCameraList);
    }
}
void ZSettingVideoWrap::onDefaultCamDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
    return;
}
