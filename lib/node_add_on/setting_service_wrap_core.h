#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "setting_video_wrap_core.h"
#include "setting_audio_wrap_core.h"
#include "setting_general_wrap_core.h"
#include "setting_recording_wrap_core.h"
#include "setting_ui_strategy_wrap_core.h"

#include "setting_statistic_wrap_core.h"
#include "setting_accessibility_wrap_core.h"

class ZSettingServiceWrap
{
public:
	ZSettingServiceWrap();
	virtual ~ZSettingServiceWrap();
	void Init();
	void Uninit();

	ZNSDKError ShowSettingDlg(ZNShowSettingDlgParam param);
	ZNSDKError HideSettingDlg();

	ZSettingVideoWrap& GetSettingVideoCtrl();
	ZSettingAudioWrap& GetSettingAudioCtrl();
	ZSettingGeneralWrap& GetSettingGeneralCtrl();
	ZSettingRecordingWrap& GetSettingRecordingCtrl();
	ZSettingUIStrategyWrap& GetSettingStrategyCtrl();

	ZSettingStatisticWrap& GetSettingStatisticCtrl();
	ZSettingAccessibilityWrap& GetSettingAccessibilityCtrl();
	
private:
	ZSettingVideoWrap m_setting_video_ctrl;
	ZSettingAudioWrap m_setting_audio_ctrl;
	ZSettingGeneralWrap m_setting_general_ctrl;
	ZSettingRecordingWrap m_setting_recording_ctrl;
	ZSettingUIStrategyWrap m_setting_ui_strategy_ctrl;

	ZSettingStatisticWrap m_setting_statistic_ctrl;
	ZSettingAccessibilityWrap m_setting_accessibility_ctrl;
};
