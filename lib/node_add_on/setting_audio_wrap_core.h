#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

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
	////////////////////////////////////////////////////////////////////////////////
	void SetSink(ZNativeSDKAudioSettingContextWrapSink* pSink);
	ZNSDKError EnableStereoAudio(bool bEnable);
	bool IsStereoAudioEnable();
	ZNSDKError EnableMicOriginalInput(bool bEnable);
	bool IsMicOriginalInputEnable();
	ZNSDKError EnableHoldSpaceKeyToSpeak(bool bEnable);
	bool IsHoldSpaceKeyToSpeakEnabled();
	ZNSDKError EnableAlwaysMuteMicWhenJoinVoip(bool bEnable);
	bool IsAlwaysMuteMicWhenJoinVoipEnabled();
	ZNSDKError EnableSuppressAudioNotify(bool bEnable);
	bool IsSuppressAudioNotifyEnabled();
	ZNSDKError SetMicVol(float& value);
	ZNSDKError GetMicVol(float& value);
	ZNSDKError SetSpeakerVol(float& value);
	ZNSDKError GetSpeakerVol(float& value);
	ZNSDKError EnableEchoCancellation(bool bEnable);
	bool IsEchoCancellationEnabled();


	//callback
	void onComputerMicDeviceChanged(ZNList<ZNMicInfo> newMicList);
	void onComputerSpeakerDeviceChanged(ZNList<ZNSpeakerInfo> newSpeakerList);
	void onDefaultMicDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName);
	void onDefaultSpeakerDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName);

private:
	ZNativeSDKAudioSettingContextWrapSink* m_pSink;
};
