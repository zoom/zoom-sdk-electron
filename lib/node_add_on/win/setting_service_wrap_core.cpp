
#include "../setting_service_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"

ZOOM_SDK_NAMESPACE::ISettingServiceWrap& g_setting_service_wrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap();
ZSettingServiceWrap::ZSettingServiceWrap()
{
	
}
ZSettingServiceWrap::~ZSettingServiceWrap()
{
	Uninit();
}
void ZSettingServiceWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().Init_Wrap();
	m_setting_audio_ctrl.Init();
	m_setting_video_ctrl.Init();
	m_setting_recording_ctrl.Init();
}
void ZSettingServiceWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().Uninit_Wrap();
}
ZSettingVideoWrap& ZSettingServiceWrap::GetSettingVideoCtrl()
{
	return m_setting_video_ctrl;
}
ZSettingAudioWrap& ZSettingServiceWrap::GetSettingAudioCtrl()
{
	return m_setting_audio_ctrl;
}
ZSettingGeneralWrap& ZSettingServiceWrap::GetSettingGeneralCtrl()
{
	return m_setting_general_ctrl;
}
ZSettingRecordingWrap& ZSettingServiceWrap::GetSettingRecordingCtrl()
{
	return m_setting_recording_ctrl;
}
ZSettingUIStrategyWrap& ZSettingServiceWrap::GetSettingStrategyCtrl()
{
	return m_setting_ui_strategy_ctrl;
}
///////////////////////////////////////////////////////////////////////////////////////
ZSettingStatisticWrap& ZSettingServiceWrap::GetSettingStatisticCtrl()
{
	return m_setting_statistic_ctrl;
}
ZSettingAccessibilityWrap& ZSettingServiceWrap::GetSettingAccessibilityCtrl()
{
	return m_setting_accessibility_ctrl;
}
////////////////////////////////////////////////////////////////////////////////////
ZNSDKError ZSettingServiceWrap::ShowSettingDlg(ZNShowSettingDlgParam param)
{
	ZOOM_SDK_NAMESPACE::ShowSettingDlgParam sdk_param;
	swscanf_s(param.hParent.c_str(), L"%x", (unsigned int*)&sdk_param.hParent);
	sdk_param.left = _wtoi(param.left.c_str());
	sdk_param.top = _wtoi(param.top.c_str());
	swscanf_s(param.hSettingWnd.c_str(), L"%x", (unsigned int*)&sdk_param.hSettingWnd);
	sdk_param.bShow = param.bShow;
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().ShowSettingDlg(sdk_param));
}
ZNSDKError ZSettingServiceWrap::HideSettingDlg()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().HideSettingDlg());
}
