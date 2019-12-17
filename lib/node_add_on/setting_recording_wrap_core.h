#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"
class ZSettingRecordingWrap
{
public:
	ZSettingRecordingWrap();
	virtual ~ZSettingRecordingWrap();
	void Init();
	void Uninit();

	ZNSDKError SetRecordingPath(ZoomSTRING szPath);
	ZoomSTRING GetRecordingPath();
	///////////////////////////////////////////////////////////////////////////////
	void SetSink(ZNativeSDKRecordingSettingContextWrapSink* pSink);
	bool CanGetCloudRecordingStorageInfo();
	ZNSDKError GetCloudRecordingStorageInfo();
	ZoomSTRING GetRecordingManagementURL();
	ZNSDKError CanGetRecordingManagementURL(bool& bEnable);
	ZNSDKError EnableSelectRecordFileLocationAfterMeeting(bool bEnable);
	bool IsSelectRecordFileLocationAfterMeetingEnabled();
	ZNSDKError EnableMultiAudioStreamRecord(bool bEnable);
	bool IsMultiAudioStreamRecordEnabled();
	ZNSDKError EnableAddTimestampWatermark(bool bEnable);
	bool IsAddTimestampWatermarkEnabled();
	ZNSDKError EnableOptimizeFor3rdPartyVideoEditor(bool bEnable);
	bool IsOptimizeFor3rdPartyVideoEditorEnabled();
	ZNSDKError EnableShowVideoThumbnailWhenShare(bool bEnable);
	bool IsShowVideoThumbnailWhenShareEnabled();
	ZNSDKError EnablePlaceVideoNextToShareInRecord(bool bEnable);
	bool IsPlaceVideoNextToShareInRecordEnabled();

	//callback
	void onCloudRecordingStorageInfo(signed long long storage_total_size, signed long long storage_used_size, bool allow_exceed_storage);

private:
	ZNativeSDKRecordingSettingContextWrapSink* m_pSink;
};
