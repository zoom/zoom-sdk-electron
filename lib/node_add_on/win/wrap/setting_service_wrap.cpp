#pragma once
#include "setting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ISettingService* InitISettingServiceFunc()
{
	ZOOM_SDK_NAMESPACE::ISettingService* pObj(NULL);
	CSDKImpl::GetInst().CreateSettingService(&pObj);
	return pObj;
}

void UninitISettingServiceFunc(ZOOM_SDK_NAMESPACE::ISettingService* obj)
{
	CSDKImpl::GetInst().DestroySettingService(obj);
}

//virtual SDKError ShowSettingDlg(ShowSettingDlgParam& param) = 0;
IMPL_FUNC_1(ISettingService, ShowSettingDlg, SDKError, ShowSettingDlgParam&, param, SDKERR_UNINITIALIZE)
//virtual SDKError HideSettingDlg() = 0;
IMPL_FUNC_0(ISettingService, HideSettingDlg, SDKError, SDKERR_UNINITIALIZE)
//virtual IGeneralSettingContext* GetGeneralSettings() = 0;
IMPL_FUNC_0(ISettingService, GetGeneralSettings, IGeneralSettingContext*, NULL)
//virtual IStatisticSettingContext* GetStatisticSettings() = 0;
IMPL_FUNC_0(ISettingService, GetStatisticSettings, IStatisticSettingContext*, NULL)
//virtual IAccessibilitySettingContext* GetAccessibilitySettings() = 0;
IMPL_FUNC_0(ISettingService, GetAccessibilitySettings, IAccessibilitySettingContext*, NULL)

#if (defined UserInterfaceClass)
//virtual IVideoSettingContext* GetVideoSettings() = 0;
IMPL_FUNC_0(ISettingService, GetVideoSettings, IVideoSettingContext*, NULL)
//virtual IAudioSettingContext* GetAudioSettings() = 0;
IMPL_FUNC_0(ISettingService, GetAudioSettings, IAudioSettingContext*, NULL)
//virtual IRecordingSettingContext* GetRecordingSettings() = 0;
IMPL_FUNC_0(ISettingService, GetRecordingSettings, IRecordingSettingContext*, NULL)

#endif
IMPL_FUNC_AND_MEMBER(ISettingService, T_GetAudioSettings, IAudioSettingContextWrap)
IMPL_FUNC_AND_MEMBER(ISettingService, T_GetVideoSettings, IVideoSettingContextWrap)
IMPL_FUNC_AND_MEMBER(ISettingService, T_GetRecordingSettings, IRecordingSettingContextWrap)
IMPL_FUNC_0(ISettingService, GetSettingUIStrategy, ISettingUIStrategy*, NULL)
END_ZOOM_SDK_NAMESPACE
