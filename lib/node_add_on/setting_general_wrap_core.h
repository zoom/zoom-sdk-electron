#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZSettingGeneralWrap
{
public:
	ZSettingGeneralWrap();
	virtual ~ZSettingGeneralWrap();
	void Init();
	void Uninit();

	ZNSDKError EnableDualScreenMode(bool bEnable);
	ZNSDKError TurnOffAeroModeInSharing(bool bEnable);
	ZNSDKError EnableAutoFitToWindowWhenViewSharing(bool bEnable);
	ZNSDKError EnableAutoFullScreenVideoWhenJoinMeeting(bool bEnable);
	ZNSDKError EnableSplitScreenMode(bool bEnable);
	bool IsDualScreenModeEnabled();
	bool IsAeroModeInSharingTurnOff();
	bool IsAutoFitToWindowWhenViewSharingEnabled();
	bool IsAutoFullScreenVideoWhenJoinMeetingEnabled();
	bool IsSplitScreenModeEnabled();

};
