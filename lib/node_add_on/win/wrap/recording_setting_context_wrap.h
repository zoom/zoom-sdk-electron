#pragma once
#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class ISettingServiceWrap;
IRecordingSettingContext* InitIRecordingSettingContextFunc(IRecordingSettingContextEvent* pEvent, ISettingServiceWrap* pOwner);
void UninitIRecordingSettingContextFunc(IRecordingSettingContext* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IRecordingSettingContext, IRecordingSettingContextEvent)
NORMAL_CLASS(IRecordingSettingContext)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IRecordingSettingContext, ISettingServiceWrap)
virtual SDKError SetRecordingSettingEvent(IRecordingSettingContextEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual SDKError SetRecordingPath(const wchar_t* szPath) = 0;
DEFINE_FUNC_1(SetRecordingPath, SDKError, const wchar_t*, szPath)
//virtual const wchar_t* GetRecordingPath() = 0;
DEFINE_FUNC_0(GetRecordingPath, const wchar_t*)
//virtual bool CanGetCloudRecordingStorageInfo() = 0;
DEFINE_FUNC_0(CanGetCloudRecordingStorageInfo, bool)
//virtual SDKError GetCloudRecordingStorageInfo() = 0;
DEFINE_FUNC_0(GetCloudRecordingStorageInfo, SDKError)
//virtual const wchar_t* GetRecordingManagementURL() = 0;
DEFINE_FUNC_0(GetRecordingManagementURL, const wchar_t*)
//virtual SDKError CanGetRecordingManagementURL(bool& bEnable) = 0;
DEFINE_FUNC_1(CanGetRecordingManagementURL, SDKError, bool&, bEnable)
//virtual SDKError EnableSelectRecordFileLocationAfterMeeting(bool bEnable) = 0;
DEFINE_FUNC_1(EnableSelectRecordFileLocationAfterMeeting, SDKError, bool, bEnable)
//virtual bool IsSelectRecordFileLocationAfterMeetingEnabled() = 0;
DEFINE_FUNC_0(IsSelectRecordFileLocationAfterMeetingEnabled, bool)
//virtual SDKError EnableMultiAudioStreamRecord(bool bEnable) = 0;
DEFINE_FUNC_1(EnableMultiAudioStreamRecord, SDKError, bool, bEnable)
//virtual bool IsMultiAudioStreamRecordEnabled() = 0;
DEFINE_FUNC_0(IsMultiAudioStreamRecordEnabled, bool)
//virtual SDKError EnableAddTimestampWatermark(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAddTimestampWatermark, SDKError, bool, bEnable)
//virtual bool IsAddTimestampWatermarkEnabled() = 0;
DEFINE_FUNC_0(IsAddTimestampWatermarkEnabled, bool)
//virtual SDKError EnableOptimizeFor3rdPartyVideoEditor(bool bEnable) = 0;
DEFINE_FUNC_1(EnableOptimizeFor3rdPartyVideoEditor, SDKError, bool, bEnable)
//virtual bool IsOptimizeFor3rdPartyVideoEditorEnabled() = 0;
DEFINE_FUNC_0(IsOptimizeFor3rdPartyVideoEditorEnabled, bool)
//virtual SDKError EnableShowVideoThumbnailWhenShare(bool bEnable) = 0;
DEFINE_FUNC_1(EnableShowVideoThumbnailWhenShare, SDKError, bool, bEnable)
//virtual bool IsShowVideoThumbnailWhenShareEnabled() = 0;
DEFINE_FUNC_0(IsShowVideoThumbnailWhenShareEnabled, bool)
//virtual SDKError EnablePlaceVideoNextToShareInRecord(bool bEnable) = 0;
DEFINE_FUNC_1(EnablePlaceVideoNextToShareInRecord, SDKError, bool, bEnable)
//virtual bool IsPlaceVideoNextToShareInRecordEnabled() = 0;
DEFINE_FUNC_0(IsPlaceVideoNextToShareInRecordEnabled, bool)

//virtual void onCloudRecordingStorageInfo(INT64 storage_total_size, INT64 storage_used_size) = 0;
CallBack_FUNC_3(onCloudRecordingStorageInfo, INT64, storage_total_size, INT64, storage_used_size, bool, allow_exceed_storage)

END_CLASS_DEFINE(IRecordingSettingContext)
END_ZOOM_SDK_NAMESPACE
