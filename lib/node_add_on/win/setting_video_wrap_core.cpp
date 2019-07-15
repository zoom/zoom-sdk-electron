
#include "../setting_video_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/video_setting_context_wrap.h"
#include "zoom_native_to_wrap.h"



ZSettingVideoWrap::ZSettingVideoWrap()
{

}
ZSettingVideoWrap::~ZSettingVideoWrap()
{
	Uninit();
}
void ZSettingVideoWrap::Init()
{

}
void ZSettingVideoWrap::Uninit()
{

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
			zn_camera_list.add(zn_camera_info);
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