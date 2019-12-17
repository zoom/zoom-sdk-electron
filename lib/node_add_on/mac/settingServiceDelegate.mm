

#import "settingServiceDelegate.h"
#include "../zoom_node_addon.h"
#include "sdk_native_error.h"
extern ZNativeSDKWrap _g_native_wrap;
@implementation settingServiceDelegate

+(settingServiceDelegate *)share
{
    static settingServiceDelegate *delegate = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        delegate = [[settingServiceDelegate alloc]init];
    });
    return delegate;
}

-(void)onSelectedCameraChanged:(NSString *)deviceID
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return;
    }
    ZoomSDKVideoSetting *video = [setting getVideoSetting];
    if (!video) {
        return;
    }
    NSArray *arr = [video getCameraList];
    if (!arr) {
        return;
    }
    ZNList<ZNCameraInfo> list;
    for (SDKDeviceInfo *info in arr) {
        NSString *str = [info getDeviceName];
        NSString *ID = [info getDeviceID];
        bool isSelected = [info  isSelectedDevice];
        ZNCameraInfo cameraInfo;
        if (str) {
            cameraInfo.deviceName = str.UTF8String;
        }else{
            cameraInfo.deviceName = "";
        }
        if (ID) {
            cameraInfo.deviceId = ID.UTF8String;
        }else{
            cameraInfo.deviceId = "";
        }
        cameraInfo.isSelectedDevice = isSelected;
        list.push_back(cameraInfo);
    }
}

-(void)onSelectedSpeakerDeviceChanged
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return;
    }
    ZoomSDKAudioSetting *audio = [setting getAudioSetting];
    if (!audio) {
        return;
    }
    NSArray *arr = [audio getAudioDeviceList:NO];
    if (!arr) {
        return;
    }
    ZNList<ZNSpeakerInfo> list;
    for (SDKDeviceInfo *info in arr) {
        NSString *str = [info getDeviceName];
        NSString *ID = [info getDeviceID];
        bool isSelected = [info  isSelectedDevice];
        ZNSpeakerInfo speakinfo;
        if (str) {
            speakinfo.deviceName = str.UTF8String;
        }else{
            speakinfo.deviceName = "";
        }
        if (ID) {
            speakinfo.deviceId = ID.UTF8String;
        }else{
            speakinfo.deviceId = "";
        }
        
        speakinfo.isSelectedDevice = isSelected;
        list.push_back(speakinfo);
    }
    _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().onComputerSpeakerDeviceChanged(list);
}

-(void)onSelectedMicDeviceChanged
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return;
    }
    ZoomSDKAudioSetting *audio = [setting getAudioSetting];
    if (!audio) {
        return;
    }
    NSArray *arr = [audio getAudioDeviceList:YES];
    if (!arr) {
        return;
    }
    ZNList<ZNMicInfo> list;
    for (SDKDeviceInfo *info in arr) {
        NSString *str = [info getDeviceName];
        NSString *ID = [info getDeviceID];
        bool isSelected = [info  isSelectedDevice];
        ZNMicInfo micinfo;
        if (str) {
            micinfo.deviceName = str.UTF8String;
        }else{
            micinfo.deviceName = "";
        }
        if (ID) {
            micinfo.deviceId = ID.UTF8String;
        }else{
            micinfo.deviceId = "";
        }
        
        micinfo.isSelectedDevice = isSelected;
        list.push_back(micinfo);
    }
    _g_native_wrap.GetSettingServiceWrap().GetSettingAudioCtrl().onComputerMicDeviceChanged(list);
}

-(void)onNotifyCloudRecordingStorageInfo:(long long)totalSize usedSize:(long long)usedSize isAllowExceedStorage:(BOOL)allowExceedStorage
{
    _g_native_wrap.GetSettingServiceWrap().GetSettingRecordingCtrl().onCloudRecordingStorageInfo(totalSize, usedSize, allowExceedStorage);
}

@end
