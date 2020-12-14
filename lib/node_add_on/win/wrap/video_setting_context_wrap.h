#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class ISettingServiceWrap;
IVideoSettingContext* InitIVideoSettingContextFunc(IVideoSettingContextEvent* pEvent, ISettingServiceWrap* pOwner);
void UninitIVideoSettingContextFunc(IVideoSettingContext* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IVideoSettingContext, IVideoSettingContextEvent)
NORMAL_CLASS(IVideoSettingContext)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IVideoSettingContext, ISettingServiceWrap)
virtual SDKError SetVideoDeviceEvent(IVideoSettingContextEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual IList<ICameraInfo* >* GetCameraList() = 0;
DEFINE_FUNC_0(GetCameraList, IList<ICameraInfo*>*)
//virtual SDKError SelectCamera(const wchar_t* deviceId) = 0;
DEFINE_FUNC_1(SelectCamera, SDKError, const wchar_t*, deviceId)
//virtual SDKError EnableVideoMirrorEffect(bool bEnable) = 0;
DEFINE_FUNC_1(EnableVideoMirrorEffect, SDKError, bool, bEnable)
//virtual bool IsVideoMirrorEffectEnabled() = 0;
DEFINE_FUNC_0(IsVideoMirrorEffectEnabled, bool)
//virtual SDKError EnableFaceBeautyEffect(bool bEnable) = 0;
DEFINE_FUNC_1(EnableFaceBeautyEffect, SDKError, bool, bEnable)
//virtual bool IsFaceBeautyEffectEnabled() = 0;
DEFINE_FUNC_0(IsFaceBeautyEffectEnabled, bool)
//virtual SDKError EnableHDVideo(bool bEnable) = 0;
DEFINE_FUNC_1(EnableHDVideo, SDKError, bool, bEnable)
//virtual bool IsHDVideoEnabled() = 0;
DEFINE_FUNC_0(IsHDVideoEnabled, bool)
//virtual SDKError EnableAlwaysShowNameOnVideo(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAlwaysShowNameOnVideo, SDKError, bool, bEnable)
//virtual bool IsAlwaysShowNameOnVideoEnabled() = 0;
DEFINE_FUNC_0(IsAlwaysShowNameOnVideoEnabled, bool)
//virtual SDKError EnableVideoPreviewDialog(bool bEnable) = 0;
DEFINE_FUNC_1(EnableVideoPreviewDialog, SDKError, bool, bEnable)
//virtual bool IsVideoPreviewDialogEnabled() = 0;
DEFINE_FUNC_0(IsVideoPreviewDialogEnabled, bool)
//virtual SDKError EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAutoTurnOffVideoWhenJoinMeeting, SDKError, bool, bEnable)
//virtual bool IsAutoTurnOffVideoWhenJoinMeetingEnabled() = 0;
DEFINE_FUNC_0(IsAutoTurnOffVideoWhenJoinMeetingEnabled, bool)
//virtual SDKError EnableAlwaysUse16v9(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAlwaysUse16v9, SDKError, bool, bEnable)
//virtual bool IsAlwaysUse16v9() = 0;
DEFINE_FUNC_0(IsAlwaysUse16v9, bool)
//virtual SDKError EnableSpotlightSelf(bool bEnable) = 0;
DEFINE_FUNC_1(EnableSpotlightSelf, SDKError, bool, bEnable)
//virtual bool IsSpotlightSelfEnabled() = 0;
DEFINE_FUNC_0(IsSpotlightSelfEnabled, bool)
//virtual SDKError EnableHardwareEncode(bool bEnable) = 0;
DEFINE_FUNC_2(EnableHardwareEncode, SDKError, bool, bEnable, VIDEO_HARDWARE_ENCODE_TYPE, encodeType)
//virtual bool IsHardwareEncodeEnabled() = 0;
DEFINE_FUNC_1(IsHardwareEncodeEnabled, bool, VIDEO_HARDWARE_ENCODE_TYPE, encodeType)
//virtual SDKError Enable49VideoesInGallaryView(bool bEnable) = 0;
DEFINE_FUNC_1(Enable49VideoesInGallaryView, SDKError, bool, bEnable)
//virtual bool Is49VideoesInGallaryViewEnabled() = 0;
DEFINE_FUNC_0(Is49VideoesInGallaryViewEnabled, bool)
//virtual SDKError EnableHideNoVideoUsersOnWallView(bool bEnable) = 0;
DEFINE_FUNC_1(EnableHideNoVideoUsersOnWallView, SDKError, bool, bEnable)
//virtual bool IsHideNoVideoUsersOnWallViewEnabled() = 0;
DEFINE_FUNC_0(IsHideNoVideoUsersOnWallViewEnabled, bool)
//virtual ITestVideoDeviceHelper* GetTestVideoDeviceHelper() = 0;
DEFINE_FUNC_0(GetTestVideoDeviceHelper, ITestVideoDeviceHelper*)

//virtual void onComputerCamDeviceChanged(IList<ICameraInfo*>* pNewCameraList) = 0;
CallBack_FUNC_1(onComputerCamDeviceChanged, IList<ICameraInfo*>*, pNewCameraList)
//virtual void onDefaultCamDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName) = 0;
CallBack_FUNC_2(onDefaultCamDeviceChanged, const wchar_t*, deviceId, const wchar_t*, deviceName)

END_CLASS_DEFINE(IVideoSettingContext)
END_ZOOM_SDK_NAMESPACE