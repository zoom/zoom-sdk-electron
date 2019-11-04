#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZSettingUIStrategyWrap
{
public:
	ZSettingUIStrategyWrap();
	virtual ~ZSettingUIStrategyWrap();
	void Init();
	void Uninit();

	void DisableAdvancedFeatures4GeneralSetting(bool bDisable);
	void DisableAccountSettingTabPage(bool bDisable);
	void ConfSettingDialogShownTabPage(unsigned long showOption);
};
