#pragma once
#include "zoom_native_sdk_wrap_core_def.h"


class ZSettingAudioWrap
{
public:
	ZSettingAudioWrap();
	virtual ~ZSettingAudioWrap();
	void Init();
	void Uninit();

	ZNSDKError SelectMic(ZoomSTRING deviceId, ZoomSTRING deviceName);
	ZNList<ZNMicInfo> GetMicList();
	ZNSDKError SelectSpeaker(ZoomSTRING deviceId, ZoomSTRING deviceName);
	ZNList<ZNSpeakerInfo> GetSpeakerList();
	bool IsAutoJoinAudioEnabled();
	bool IsAutoAdjustMicEnabled();
	ZNSDKError EnableAutoJoinAudio(bool bEnable);
	ZNSDKError EnableAutoAdjustMic(bool bEnable);

};
