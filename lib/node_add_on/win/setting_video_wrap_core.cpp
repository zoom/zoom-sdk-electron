
#include "../setting_video_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/video_setting_context_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::ISettingServiceWrap& g_setting_service_wrap;

ZSettingVideoWrap::ZSettingVideoWrap()
{
	SDKEventWrapMgr::GetInst().m_videoSettingContextWrapEvent.SetOwner(this);
	m_pSink = NULL;
}
ZSettingVideoWrap::~ZSettingVideoWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_videoSettingContextWrapEvent.SetOwner(NULL);
}
void ZSettingVideoWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().Init_Wrap(&g_setting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().SetVideoDeviceEvent(&SDKEventWrapMgr::GetInst().m_videoSettingContextWrapEvent);
}
void ZSettingVideoWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().SetVideoDeviceEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().Uninit_Wrap();
}
ZNSDKError ZSettingVideoWrap::SelectCamera(ZoomSTRING deviceId)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().SelectCamera(deviceId.c_str()));
}
bool ZSettingVideoWrap::IsVideoMirrorEffectEnable()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsVideoMirrorEffectEnabled();
}
ZNList<ZNCameraInfo> ZSettingVideoWrap::GetCameraList()
{
	ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ICameraInfo* >* pCameraLst(NULL);
	ZOOM_SDK_NAMESPACE::ISettingServiceWrap& settingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap();
	pCameraLst = settingWrap.T_GetVideoSettings().GetCameraList();
	ZNList<ZNCameraInfo> zn_camera_list;
	if (pCameraLst && pCameraLst->GetCount() > 0)
	{
		int count = pCameraLst->GetCount();
		for (int i = 0; i < count; i++)
		{
			ZOOM_SDK_NAMESPACE::ICameraInfo* pCameraInfo = pCameraLst->GetItem(i);
			ZNCameraInfo zn_camera_info;
			if (NULL == pCameraInfo)
				continue;

			if (pCameraInfo->GetDeviceName())
			{
				zn_camera_info.deviceName = pCameraInfo->GetDeviceName();
			}
			if (pCameraInfo->GetDeviceId())
			{
				zn_camera_info.deviceId = pCameraInfo->GetDeviceId();
			}
			zn_camera_info.isSelectedDevice = pCameraInfo->IsSelectedDevice();
			zn_camera_list.push_back(zn_camera_info);
		}
	}
	return zn_camera_list;
}
ZNSDKError ZSettingVideoWrap::EnableVideoMirrorEffect(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableVideoMirrorEffect(bEnable));
}
ZNSDKError ZSettingVideoWrap::EnableFaceBeautyEffect(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableFaceBeautyEffect(bEnable));
}
bool ZSettingVideoWrap::IsFaceBeautyEffectEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsFaceBeautyEffectEnabled();
}

//////////////////////////////////////////////////////////////////////////////////////////////
void ZSettingVideoWrap::SetSink(ZNativeSDKVideoSettingContextWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZSettingVideoWrap::EnableHDVideo(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableHDVideo(bEnable));
}
bool ZSettingVideoWrap::IsHDVideoEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsHDVideoEnabled();
}
ZNSDKError ZSettingVideoWrap::EnableAlwaysShowNameOnVideo(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableAlwaysShowNameOnVideo(bEnable));
}
bool ZSettingVideoWrap::IsAlwaysShowNameOnVideoEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsAlwaysShowNameOnVideoEnabled();
}
ZNSDKError ZSettingVideoWrap::EnableAutoTurnOffVideoWhenJoinMeeting(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableAutoTurnOffVideoWhenJoinMeeting(bEnable));
}
bool ZSettingVideoWrap::IsAutoTurnOffVideoWhenJoinMeetingEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsAutoTurnOffVideoWhenJoinMeetingEnabled();
}
ZNSDKError ZSettingVideoWrap::EnableAlwaysUse16v9(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableAlwaysUse16v9(bEnable));
}
bool ZSettingVideoWrap::IsAlwaysUse16v9()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsAlwaysUse16v9();
}
ZNSDKError ZSettingVideoWrap::EnableSpotlightSelf(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableSpotlightSelf(bEnable));
}
bool ZSettingVideoWrap::IsSpotlightSelfEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsSpotlightSelfEnabled();
}
ZNSDKError ZSettingVideoWrap::EnableHardwareEncode(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableHardwareEncode(bEnable));
}
bool ZSettingVideoWrap::IsHardwareEncodeEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsHardwareEncodeEnabled();
}
ZNSDKError ZSettingVideoWrap::Enable49VideoesInGallaryView(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().Enable49VideoesInGallaryView(bEnable));
}
bool ZSettingVideoWrap::Is49VideoesInGallaryViewEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().Is49VideoesInGallaryViewEnabled();
}
ZNSDKError ZSettingVideoWrap::EnableHideNoVideoUsersOnWallView(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().EnableHideNoVideoUsersOnWallView(bEnable));
}
bool ZSettingVideoWrap::IsHideNoVideoUsersOnWallViewEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetVideoSettings().IsHideNoVideoUsersOnWallViewEnabled();
}
void ZSettingVideoWrap::onComputerCamDeviceChanged(ZNList<ZNCameraInfo> newCameraList)
{
	if (m_pSink)
	{
		m_pSink->onComputerCamDeviceChanged(newCameraList);
	}
}
void ZSettingVideoWrap::onDefaultCamDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	if (m_pSink)
	{
		m_pSink->onDefaultCamDeviceChanged(deviceId, deviceName);
	}
}