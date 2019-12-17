
#include "../setting_recording_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::ISettingServiceWrap& g_setting_service_wrap;


ZSettingRecordingWrap::ZSettingRecordingWrap()
{
	SDKEventWrapMgr::GetInst().m_recordingSettingContextWrapEvent.SetOwner(this);
	m_pSink = NULL;
}
ZSettingRecordingWrap::~ZSettingRecordingWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_recordingSettingContextWrapEvent.SetOwner(NULL);
}
void ZSettingRecordingWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().Init_Wrap(&g_setting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().SetRecordingSettingEvent(&SDKEventWrapMgr::GetInst().m_recordingSettingContextWrapEvent);
}
void ZSettingRecordingWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().SetRecordingSettingEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().Uninit_Wrap();
}
ZNSDKError ZSettingRecordingWrap::SetRecordingPath(ZoomSTRING szPath)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().SetRecordingPath(szPath.c_str()));
}
ZoomSTRING ZSettingRecordingWrap::GetRecordingPath()
{
	ZoomSTRING zn_szPath;
	const wchar_t* sdk_path = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().GetRecordingPath();
	if (sdk_path)
	{
		zn_szPath = sdk_path;
	}
	return zn_szPath;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ZSettingRecordingWrap::SetSink(ZNativeSDKRecordingSettingContextWrapSink* pSink)
{
	m_pSink = pSink;
}
bool ZSettingRecordingWrap::CanGetCloudRecordingStorageInfo()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().CanGetCloudRecordingStorageInfo();
}
ZNSDKError ZSettingRecordingWrap::GetCloudRecordingStorageInfo()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().GetCloudRecordingStorageInfo());
}
ZoomSTRING ZSettingRecordingWrap::GetRecordingManagementURL()
{
	ZoomSTRING zn_url;
	const wchar_t* sdk_url = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().GetRecordingManagementURL();
	if (sdk_url)
	{
		zn_url = sdk_url;
	}
	return zn_url;
}
ZNSDKError ZSettingRecordingWrap::CanGetRecordingManagementURL(bool& bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().CanGetRecordingManagementURL(bEnable));
}
ZNSDKError ZSettingRecordingWrap::EnableSelectRecordFileLocationAfterMeeting(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().EnableSelectRecordFileLocationAfterMeeting(bEnable));
}
bool ZSettingRecordingWrap::IsSelectRecordFileLocationAfterMeetingEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().IsSelectRecordFileLocationAfterMeetingEnabled();
}
ZNSDKError ZSettingRecordingWrap::EnableMultiAudioStreamRecord(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().EnableMultiAudioStreamRecord(bEnable));
}
bool ZSettingRecordingWrap::IsMultiAudioStreamRecordEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().IsMultiAudioStreamRecordEnabled();
}
ZNSDKError ZSettingRecordingWrap::EnableAddTimestampWatermark(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().EnableAddTimestampWatermark(bEnable));
}
bool ZSettingRecordingWrap::IsAddTimestampWatermarkEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().IsAddTimestampWatermarkEnabled();
}
ZNSDKError ZSettingRecordingWrap::EnableOptimizeFor3rdPartyVideoEditor(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().EnableOptimizeFor3rdPartyVideoEditor(bEnable));
}
bool ZSettingRecordingWrap::IsOptimizeFor3rdPartyVideoEditorEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().IsOptimizeFor3rdPartyVideoEditorEnabled();
}
ZNSDKError ZSettingRecordingWrap::EnableShowVideoThumbnailWhenShare(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().EnableShowVideoThumbnailWhenShare(bEnable));
}
bool ZSettingRecordingWrap::IsShowVideoThumbnailWhenShareEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().IsShowVideoThumbnailWhenShareEnabled();
}
ZNSDKError ZSettingRecordingWrap::EnablePlaceVideoNextToShareInRecord(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().EnablePlaceVideoNextToShareInRecord(bEnable));
}
bool ZSettingRecordingWrap::IsPlaceVideoNextToShareInRecordEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetRecordingSettings().IsPlaceVideoNextToShareInRecordEnabled();
}
void ZSettingRecordingWrap::onCloudRecordingStorageInfo(signed long long storage_total_size, signed long long storage_used_size, bool allow_exceed_storage)
{
	if (m_pSink)
		m_pSink->onCloudRecordingStorageInfo(storage_total_size, storage_used_size, allow_exceed_storage);
}