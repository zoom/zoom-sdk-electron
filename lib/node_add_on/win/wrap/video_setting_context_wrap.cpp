#include "video_setting_context_wrap.h"
#include "setting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IVideoSettingContext* InitIVideoSettingContextFunc(IVideoSettingContextEvent* pEvent, ISettingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IVideoSettingContext* pObj = pOwner->GetSDKObj()->GetVideoSettings();
		if (pObj)
		{
			pObj->SetVideoDeviceEvent(pEvent);
		}

		return pObj;
	}

	return NULL;
}

void UninitIVideoSettingContextFunc(IVideoSettingContext* pObj)
{
	if (pObj)
	{
		pObj->SetVideoDeviceEvent(NULL);
	}
}

//virtual IList<ICameraInfo* >* GetCameraList() = 0;
IMPL_FUNC_0(IVideoSettingContext, GetCameraList, IList<ICameraInfo*>*, NULL)
//virtual SDKError SelectCamera(const wchar_t* deviceId) = 0;
IMPL_FUNC_1(IVideoSettingContext, SelectCamera, SDKError, const wchar_t*, deviceId, SDKERR_UNINITIALIZE)
//virtual SDKError EnableVideoMirrorEffect(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableVideoMirrorEffect, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsVideoMirrorEffectEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsVideoMirrorEffectEnabled, bool, false)
//virtual SDKError EnableFaceBeautyEffect(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableFaceBeautyEffect, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsFaceBeautyEffectEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsFaceBeautyEffectEnabled, bool, false)
//virtual SDKError EnableHDVideo(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableHDVideo, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsHDVideoEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsHDVideoEnabled, bool, false)
//virtual SDKError EnableAlwaysShowNameOnVideo(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableAlwaysShowNameOnVideo, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsAlwaysShowNameOnVideoEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsAlwaysShowNameOnVideoEnabled, bool, false)
//virtual SDKError EnableVideoPreviewDialog(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableVideoPreviewDialog, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsVideoPreviewDialogEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsVideoPreviewDialogEnabled, bool, false)
//virtual SDKError EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableAutoTurnOffVideoWhenJoinMeeting, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsAutoTurnOffVideoWhenJoinMeetingEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsAutoTurnOffVideoWhenJoinMeetingEnabled, bool, false)
//virtual SDKError EnableAlwaysUse16v9(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableAlwaysUse16v9, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsAlwaysUse16v9() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsAlwaysUse16v9, bool, false)
//virtual SDKError EnableSpotlightSelf(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableSpotlightSelf, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsSpotlightSelfEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsSpotlightSelfEnabled, bool, false)
//virtual SDKError EnableHardwareEncode(bool bEnable) = 0;
IMPL_FUNC_2(IVideoSettingContext, EnableHardwareEncode, SDKError, bool, bEnable, VIDEO_HARDWARE_ENCODE_TYPE, encodeType, SDKERR_UNINITIALIZE)
//virtual bool IsHardwareEncodeEnabled() = 0;
IMPL_FUNC_1(IVideoSettingContext, IsHardwareEncodeEnabled, bool, VIDEO_HARDWARE_ENCODE_TYPE, encodeType, false)
//virtual SDKError Enable49VideoesInGallaryView(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, Enable49VideoesInGallaryView, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool Is49VideoesInGallaryViewEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, Is49VideoesInGallaryViewEnabled, bool, false)
//virtual SDKError EnableHideNoVideoUsersOnWallView(bool bEnable) = 0;
IMPL_FUNC_1(IVideoSettingContext, EnableHideNoVideoUsersOnWallView, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual bool IsHideNoVideoUsersOnWallViewEnabled() = 0;
IMPL_FUNC_0(IVideoSettingContext, IsHideNoVideoUsersOnWallViewEnabled, bool, false)
//virtual ITestVideoDeviceHelper* GetTestVideoDeviceHelper() = 0;
IMPL_FUNC_0(IVideoSettingContext, GetTestVideoDeviceHelper, ITestVideoDeviceHelper*, NULL)

END_ZOOM_SDK_NAMESPACE