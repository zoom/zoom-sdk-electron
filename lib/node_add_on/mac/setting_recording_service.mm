
#include "../setting_recording_wrap_core.h"
#include "../meeting_service_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"
#import "settingServiceDelegate.h"
ZSettingRecordingWrap::ZSettingRecordingWrap()
{
    m_pSink = 0;
}

ZSettingRecordingWrap::~ZSettingRecordingWrap()
{
    m_pSink = 0;
    ZoomSDKSettingService* service = [[ZoomSDK sharedSDK] getSettingService];
    if (service) {
        ZoomSDKRecordSetting* recording = [service getRecordSetting];
        if (recording) {
            [recording setDelegate:nil];
        }
    }
}

void ZSettingRecordingWrap::SetSink(ZNativeSDKRecordingSettingContextWrapSink* pSink)
{
    ZoomSDKSettingService* service = [[ZoomSDK sharedSDK] getSettingService];
    if (service) {
        ZoomSDKRecordSetting* recording = [service getRecordSetting];
        if (recording) {
            [recording setDelegate:[settingServiceDelegate share]];
        }
    }
    m_pSink = pSink;
}
void ZSettingRecordingWrap::Init()
{
    
}

void ZSettingRecordingWrap::Uninit()
{

}

ZNSDKError ZSettingRecordingWrap::SetRecordingPath(ZoomSTRING szPath)
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *record = [service getRecordSetting];
    NSString *path = [NSString stringWithCString:szPath.c_str() encoding:NSUTF8StringEncoding];
    if (!path) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    if(service && record){
        ZoomSDKError ret = [record setRecordingPath:path];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZoomSTRING ZSettingRecordingWrap::GetRecordingPath()
{
    ZoomSDKSettingService *service = [[ZoomSDK sharedSDK] getSettingService];
    if (!service){
        return "";
    }
    ZoomSDKRecordSetting *record = [service getRecordSetting];
    if(record){
        NSString *path = [record getRecordingPath];
        if (!path) {
            return "";
        }
        return path.UTF8String;
    }
    return "";
}
bool ZSettingRecordingWrap::CanGetCloudRecordingStorageInfo()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording canGetCloudRecordingStorageInfo];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingRecordingWrap::GetCloudRecordingStorageInfo()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = CanGetCloudRecordingStorageInfo();
    if (enable == false) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError  ret = [recording getCloudRecordingStorageInfo];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

ZoomSTRING ZSettingRecordingWrap::GetRecordingManagementURL()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return "";
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return "";
    }
    NSString *url = [recording getRecordingManagementURL];
    if (url == nil) {
        return "";
    }
    return url.UTF8String;
}

ZNSDKError ZSettingRecordingWrap::CanGetRecordingManagementURL(bool& bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bEnable = [recording canGetRecordingManagementURL];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZSettingRecordingWrap::EnableSelectRecordFileLocationAfterMeeting(bool bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsSelectRecordFileLocationAfterMeetingEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [recording chooseRecordingPathWhenMeetingEnd:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingRecordingWrap::IsSelectRecordFileLocationAfterMeetingEnabled()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording isEnableChooseRecordingPathWhenMeetingEnd];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingRecordingWrap::EnableMultiAudioStreamRecord(bool bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsMultiAudioStreamRecordEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [recording recordAudioForEveryAttendeeIndividually:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingRecordingWrap::IsMultiAudioStreamRecordEnabled()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording isEnableRecordAudioForEveryAttendeeIndividually];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingRecordingWrap::EnableAddTimestampWatermark(bool bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    bool enable = IsAddTimestampWatermarkEnabled();
    if (enable == bEnable) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    ZoomSDKError ret = [recording addTimestampForRecording:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingRecordingWrap::IsAddTimestampWatermarkEnabled()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording isEnableAddTimestampForRecording];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingRecordingWrap::EnableOptimizeFor3rdPartyVideoEditor(bool bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [recording OptimizeFor3PartyVideoEditor:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingRecordingWrap::IsOptimizeFor3rdPartyVideoEditorEnabled()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording isEnableOptimizeFor3PartyVideoEditor];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingRecordingWrap::EnableShowVideoThumbnailWhenShare(bool bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [recording recordDuringScreenSharing:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingRecordingWrap::IsShowVideoThumbnailWhenShareEnabled()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording isEnableRecordDuringScreenSharing];
    return (enable == YES) ? true : false;
}

ZNSDKError ZSettingRecordingWrap::EnablePlaceVideoNextToShareInRecord(bool bEnable)
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [recording displayVideoNextToShareContentsInRecordingFile:bEnable];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

bool ZSettingRecordingWrap::IsPlaceVideoNextToShareInRecordEnabled()
{
    ZoomSDKSettingService *setting = [[ZoomSDK sharedSDK] getSettingService];
    if (!setting) {
        return false;
    }
    ZoomSDKRecordSetting *recording = [setting getRecordSetting];
    if (!recording) {
        return false;
    }
    BOOL enable = [recording isEnableDisplayVideoNextToShareContentsInRecordingFile];
    return (enable == YES) ? true : false;
}

//callback
void ZSettingRecordingWrap::onCloudRecordingStorageInfo(signed long long storage_total_size, signed long long storage_used_size, bool allow_exceed_storage)
{
    if (m_pSink) {
        m_pSink->onCloudRecordingStorageInfo(storage_total_size, storage_used_size, allow_exceed_storage);
    }
}
