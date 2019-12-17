#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZSettingAccessibilityWrap
{
public:
	ZSettingAccessibilityWrap();
	virtual ~ZSettingAccessibilityWrap();
	void Init();
	void Uninit();

	ZNSDKError EnableAlwaysShowMeetingControls(bool bEnable);
	ZNSDKError IsAlwaysShowMeetingControlsEnable(bool& bEnable);

};
