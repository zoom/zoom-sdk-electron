#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZSettingStatisticWrap
{
public:
	ZSettingStatisticWrap();
	virtual ~ZSettingStatisticWrap();
	void Init();
	void Uninit();

	ZNSDKError QueryOverallStatisticInfo(ZNOverallStatisticInfo& info_);
	ZNSDKError QueryAudioStatisticInfo(ZNAudioSessionStatisticInfo& info_);
	ZNSDKError QueryVideoStatisticInfo(ZNASVSessionStatisticInfo& info_);
	ZNSDKError QueryShareStatisticInfo(ZNASVSessionStatisticInfo& info_);
};
