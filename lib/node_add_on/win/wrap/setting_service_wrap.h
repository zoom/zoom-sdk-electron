#pragma once
#include "common_include.h"
#include "video_setting_context_wrap.h"
#include "audio_setting_context_wrap.h"
#include "recording_setting_context_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ISettingService* InitISettingServiceFunc();
void UninitISettingServiceFunc(ZOOM_SDK_NAMESPACE::ISettingService* obj);

BEGIN_CLASS_DEFINE(ISettingService)
STAITC_CLASS(ISettingService)
INIT_UNINIT(ISettingService)


//virtual SDKError ShowSettingDlg(ShowSettingDlgParam& param) = 0;
DEFINE_FUNC_1(ShowSettingDlg, SDKError, ShowSettingDlgParam&, param)
//virtual SDKError HideSettingDlg() = 0;
DEFINE_FUNC_0(HideSettingDlg, SDKError)
//virtual IGeneralSettingContext* GetGeneralSettings() = 0;
DEFINE_FUNC_0(GetGeneralSettings, IGeneralSettingContext*)
//virtual IStatisticSettingContext* GetStatisticSettings() = 0;
DEFINE_FUNC_0(GetStatisticSettings, IStatisticSettingContext*)
//virtual ISettingUIStrategy* GetSettingUIStrategy() = 0;
DEFINE_FUNC_0(GetSettingUIStrategy, ISettingUIStrategy*)
//virtual IAccessibilitySettingContext* GetAccessibilitySettings() = 0;
DEFINE_FUNC_0(GetAccessibilitySettings, IAccessibilitySettingContext*)

#if (defined UserInterfaceClass)
private:
//virtual IAudioSettingContext* GetAudioSettings() = 0;
DEFINE_FUNC_0(GetAudioSettings, IAudioSettingContext*)
//virtual IVideoSettingContext* GetVideoSettings() = 0;
DEFINE_FUNC_0(GetVideoSettings, IVideoSettingContext*)
//virtual IRecordingSettingContext* GetRecordingSettings() = 0;
DEFINE_FUNC_0(GetRecordingSettings, IRecordingSettingContext*)
public:
#define T_GetAudioSettings _GetAudioSettings
#define T_GetVideoSettings _GetVideoSettings
#define T_GetRecordingSettings _GetRecordingSettings
#else
#define T_GetAudioSettings GetAudioSettings
#define T_GetVideoSettings GetVideoSettings
#define T_GetRecordingSettings GetRecordingSettings
#endif
DEFINE_FUNC_AND_MEMBER(T_GetAudioSettings, IAudioSettingContextWrap)
DEFINE_FUNC_AND_MEMBER(T_GetVideoSettings, IVideoSettingContextWrap)
DEFINE_FUNC_AND_MEMBER(T_GetRecordingSettings, IRecordingSettingContextWrap)

END_CLASS_DEFINE(ISettingService)
END_ZOOM_SDK_NAMESPACE