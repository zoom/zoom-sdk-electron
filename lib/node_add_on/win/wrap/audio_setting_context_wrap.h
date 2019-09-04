#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class ISettingServiceWrap;
IAudioSettingContext* InitIAudioSettingContextFunc(IAudioSettingContextEvent* pEvent, ISettingServiceWrap* pOwner);
void UninitIAudioSettingContextFunc(IAudioSettingContext* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IAudioSettingContext, IAudioSettingContextEvent)
NORMAL_CLASS(IAudioSettingContext)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IAudioSettingContext, ISettingServiceWrap)
virtual SDKError SetAudioDeviceEvent(IAudioSettingContextEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual IList<IMicInfo* >* GetMicList() = 0;
DEFINE_FUNC_0(GetMicList, IList<IMicInfo*>*)
//virtual SDKError SelectMic(const wchar_t* deviceId, const wchar_t* deviceName) = 0;
DEFINE_FUNC_2(SelectMic, SDKError, const wchar_t*, deviceId, const wchar_t*, deviceName)
//virtual IList<ISpeakerInfo* >* GetSpeakerList() = 0;
DEFINE_FUNC_0(GetSpeakerList, IList<ISpeakerInfo* >*)
//virtual SDKError SelectSpeaker(const wchar_t* deviceId, const wchar_t* deviceName) = 0;
DEFINE_FUNC_2(SelectSpeaker, SDKError, const wchar_t*, deviceId, const wchar_t*, deviceName)
//virtual SDKError EnableAutoJoinAudio(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAutoJoinAudio, SDKError, bool, bEnable)
//virtual bool IsAutoJoinAudioEnabled() = 0;
DEFINE_FUNC_0(IsAutoJoinAudioEnabled, bool)
//virtual SDKError EnableAutoAdjustMic(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAutoAdjustMic, SDKError, bool, bEnable)
//virtual bool IsAutoAdjustMicEnabled() = 0;
DEFINE_FUNC_0(IsAutoAdjustMicEnabled, bool)
//virtual SDKError EnableStereoAudio(bool bEnable) = 0;
DEFINE_FUNC_1(EnableStereoAudio, SDKError, bool, bEnable)
//virtual bool IsStereoAudioEnable() = 0;
DEFINE_FUNC_0(IsStereoAudioEnable, bool)
//virtual SDKError EnableMicOriginalInput(bool bEnable) = 0;
DEFINE_FUNC_1(EnableMicOriginalInput, SDKError, bool, bEnable)
//virtual bool IsMicOriginalInputEnable() = 0;
DEFINE_FUNC_0(IsMicOriginalInputEnable, bool)
//virtual SDKError EnableHoldSpaceKeyToSpeak(bool bEnable) = 0;
DEFINE_FUNC_1(EnableHoldSpaceKeyToSpeak, SDKError, bool, bEnable)
//virtual bool IsHoldSpaceKeyToSpeakEnabled() = 0;
DEFINE_FUNC_0(IsHoldSpaceKeyToSpeakEnabled, bool)
//virtual SDKError EnableAlwaysMuteMicWhenJoinVoip(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAlwaysMuteMicWhenJoinVoip, SDKError, bool, bEnable)
//virtual bool IsAlwaysMuteMicWhenJoinVoipEnabled() = 0;
DEFINE_FUNC_0(IsAlwaysMuteMicWhenJoinVoipEnabled, bool)
//virtual SDKError EnableSuppressAudioNotify(bool bEnable) = 0;
DEFINE_FUNC_1(EnableSuppressAudioNotify, SDKError, bool, bEnable)
//virtual bool IsSuppressAudioNotifyEnabled() = 0;
DEFINE_FUNC_0(IsSuppressAudioNotifyEnabled, bool)
//virtual ITestAudioDeviceHelper* GetTestAudioDeviceHelper() = 0;
DEFINE_FUNC_0(GetTestAudioDeviceHelper, ITestAudioDeviceHelper*)

//virtual SDKError SetMicVol(FLOAT& value) = 0;
DEFINE_FUNC_1(SetMicVol, SDKError, FLOAT&, value)
//virtual SDKError GetMicVol(FLOAT& value) = 0;
DEFINE_FUNC_1(GetMicVol, SDKError, FLOAT&, value)
//virtual SDKError SetSpeakerVol(FLOAT& value) = 0;
DEFINE_FUNC_1(SetSpeakerVol, SDKError, FLOAT&, value)
//virtual SDKError GetSpeakerVol(FLOAT& value) = 0;
DEFINE_FUNC_1(GetSpeakerVol, SDKError, FLOAT&, value)

//virtual SDKError EnableEchoCancellation(bool bEnable) = 0;
DEFINE_FUNC_1(EnableEchoCancellation, SDKError, bool, bEnable)
//virtual bool IsEchoCancellationEnabled() = 0;
DEFINE_FUNC_0(IsEchoCancellationEnabled, bool)

//virtual void onComputerMicDeviceChanged(IList<IMicInfo*>* pNewMicList) = 0;
CallBack_FUNC_1(onComputerMicDeviceChanged, IList<IMicInfo*>*, pNewMicList)
//virtual void onComputerSpeakerDeviceChanged(IList<ISpeakerInfo*>* pNewSpeakerList) = 0;
CallBack_FUNC_1(onComputerSpeakerDeviceChanged, IList<ISpeakerInfo*>*, pNewSpeakerList)
//virtual void onDefaultMicDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName) = 0;
CallBack_FUNC_2(onDefaultMicDeviceChanged, const wchar_t*, deviceId, const wchar_t*, deviceName)
//virtual void onDefaultSpeakerDeviceChanged(const wchar_t* deviceId, const wchar_t* deviceName) = 0;
CallBack_FUNC_2(onDefaultSpeakerDeviceChanged, const wchar_t*, deviceId, const wchar_t*, deviceName)

END_CLASS_DEFINE(IAudioSettingContext)
END_ZOOM_SDK_NAMESPACE
