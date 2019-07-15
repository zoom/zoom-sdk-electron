#include "recording_setting_context_wrap.h"
#include "setting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IRecordingSettingContext* InitIRecordingSettingContextFunc(IRecordingSettingContextEvent* pEvent, ISettingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IRecordingSettingContext* pObj = pOwner->GetSDKObj()->GetRecordingSettings();
		if (pObj)
		{
			pObj->SetRecordingSettingEvent(pEvent);
		}

		return pObj;
	}

	return NULL;
}

void UninitIRecordingSettingContextFunc(IRecordingSettingContext* pObj)
{
	if (pObj)
	{
		pObj->SetRecordingSettingEvent(NULL);
	}
}

//virtual SDKError SetRecordingPath(const wchar_t* szPath) = 0;
IMPL_FUNC_1(IRecordingSettingContext, SetRecordingPath, SDKError, const wchar_t*, szPath, SDKERR_UNINITIALIZE)
//virtual const wchar_t* GetRecordingPath() = 0;
IMPL_FUNC_0(IRecordingSettingContext, GetRecordingPath, const wchar_t*, NULL)
//virtual bool CanGetCloudRecordingStorageInfo() = 0;
IMPL_FUNC_0(IRecordingSettingContext, CanGetCloudRecordingStorageInfo, bool, false)
//virtual SDKError GetCloudRecordingStorageInfo() = 0;
IMPL_FUNC_0(IRecordingSettingContext, GetCloudRecordingStorageInfo, SDKError, SDKERR_UNINITIALIZE)
//virtual const wchar_t* GetRecordingManagementURL() = 0;
IMPL_FUNC_0(IRecordingSettingContext, GetRecordingManagementURL, const wchar_t*, NULL)
//virtual SDKError CanGetRecordingManagementURL(bool& bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, CanGetRecordingManagementURL, SDKError, bool&, bEnable, SDKERR_UNINITIALIZE)
//virtual SDKError EnableSelectRecordFileLocationAfterMeeting(bool bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, EnableSelectRecordFileLocationAfterMeeting, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsSelectRecordFileLocationAfterMeetingEnabled() = 0;
IMPL_FUNC_0(IRecordingSettingContext, IsSelectRecordFileLocationAfterMeetingEnabled, bool, false)
//virtual SDKError EnableMultiAudioStreamRecord(bool bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, EnableMultiAudioStreamRecord, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsMultiAudioStreamRecordEnabled() = 0;
IMPL_FUNC_0(IRecordingSettingContext, IsMultiAudioStreamRecordEnabled, bool, false)
//virtual SDKError EnableAddTimestampWatermark(bool bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, EnableAddTimestampWatermark, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsAddTimestampWatermarkEnabled() = 0;
IMPL_FUNC_0(IRecordingSettingContext, IsAddTimestampWatermarkEnabled, bool, false)
//virtual SDKError EnableOptimizeFor3rdPartyVideoEditor(bool bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, EnableOptimizeFor3rdPartyVideoEditor, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsOptimizeFor3rdPartyVideoEditorEnabled() = 0;
IMPL_FUNC_0(IRecordingSettingContext, IsOptimizeFor3rdPartyVideoEditorEnabled, bool, false)
//virtual SDKError EnableShowVideoThumbnailWhenShare(bool bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, EnableShowVideoThumbnailWhenShare, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsShowVideoThumbnailWhenShareEnabled() = 0;
IMPL_FUNC_0(IRecordingSettingContext, IsShowVideoThumbnailWhenShareEnabled, bool, false)
//virtual SDKError EnablePlaceVideoNextToShareInRecord(bool bEnable) = 0;
IMPL_FUNC_1(IRecordingSettingContext, EnablePlaceVideoNextToShareInRecord, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsPlaceVideoNextToShareInRecordEnabled() = 0;
IMPL_FUNC_0(IRecordingSettingContext, IsPlaceVideoNextToShareInRecordEnabled, bool, false)

END_ZOOM_SDK_NAMESPACE
