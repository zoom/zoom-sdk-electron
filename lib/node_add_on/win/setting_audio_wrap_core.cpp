
#include "../setting_audio_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/audio_setting_context_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::ISettingServiceWrap& g_setting_service_wrap;

ZSettingAudioWrap::ZSettingAudioWrap()
{
	SDKEventWrapMgr::GetInst().m_audioSettingContextWrapEvent.SetOwner(this);
	m_pSink = NULL;
}
ZSettingAudioWrap::~ZSettingAudioWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_audioSettingContextWrapEvent.SetOwner(NULL);
}
void ZSettingAudioWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().Init_Wrap(&g_setting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().SetAudioDeviceEvent(&SDKEventWrapMgr::GetInst().m_audioSettingContextWrapEvent);
}
void ZSettingAudioWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().SetAudioDeviceEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().Uninit_Wrap();
}

ZNSDKError ZSettingAudioWrap::SelectMic(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().SelectMic(deviceId.c_str(), deviceName.c_str()));
}

ZNList<ZNMicInfo> ZSettingAudioWrap::GetMicList()
{
	ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IMicInfo* >* pMicLst(NULL);
	ZOOM_SDK_NAMESPACE::ISettingServiceWrap& settingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap();
	pMicLst = settingWrap.T_GetAudioSettings().GetMicList();
	ZNList<ZNMicInfo> zn_mic_list;
	if (pMicLst && pMicLst->GetCount() > 0)
	{
		int count = pMicLst->GetCount();
		for (int i = 0; i < count; i++)
		{
			ZOOM_SDK_NAMESPACE::IMicInfo* pMicInfo = pMicLst->GetItem(i);
			ZNMicInfo zn_mic_info;
			if (NULL == pMicInfo)
				continue;

			if (pMicInfo->GetDeviceName())
			{
				zn_mic_info.deviceName = pMicInfo->GetDeviceName();
			}
			if (pMicInfo->GetDeviceId())
			{
				zn_mic_info.deviceId = pMicInfo->GetDeviceId();
			}
			zn_mic_info.isSelectedDevice = pMicInfo->IsSelectedDevice();
			zn_mic_list.push_back(zn_mic_info);
		}
	}
	return zn_mic_list;
}
ZNSDKError ZSettingAudioWrap::SelectSpeaker(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().SelectSpeaker(deviceId.c_str(), deviceName.c_str()));
}
ZNList<ZNSpeakerInfo> ZSettingAudioWrap::GetSpeakerList()
{
	ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::ISpeakerInfo* >* pSpeakerLst(NULL);
	ZOOM_SDK_NAMESPACE::ISettingServiceWrap& settingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap();
	pSpeakerLst = settingWrap.T_GetAudioSettings().GetSpeakerList();
	ZNList<ZNSpeakerInfo> zn_speaker_list;
	if (pSpeakerLst && pSpeakerLst->GetCount() > 0)
	{
		int count = pSpeakerLst->GetCount();
		for (int i = 0; i < count; i++)
		{
			ZOOM_SDK_NAMESPACE::ISpeakerInfo* pSpeakerInfo = pSpeakerLst->GetItem(i);
			ZNSpeakerInfo zn_speaker_info;
			if (NULL == pSpeakerInfo)
				continue;

			if (pSpeakerInfo->GetDeviceName())
			{
				zn_speaker_info.deviceName = pSpeakerInfo->GetDeviceName();
			}
			if (pSpeakerInfo->GetDeviceId())
			{
				zn_speaker_info.deviceId = pSpeakerInfo->GetDeviceId();
			}
			zn_speaker_info.isSelectedDevice = pSpeakerInfo->IsSelectedDevice();
			zn_speaker_list.push_back(zn_speaker_info);
		}
	}
	return zn_speaker_list;
}
bool ZSettingAudioWrap::IsAutoJoinAudioEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsAutoJoinAudioEnabled();
}
bool ZSettingAudioWrap::IsAutoAdjustMicEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsAutoAdjustMicEnabled();
}
ZNSDKError ZSettingAudioWrap::EnableAutoJoinAudio(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableAutoJoinAudio(bEnable));
}
ZNSDKError ZSettingAudioWrap::EnableAutoAdjustMic(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableAutoAdjustMic(bEnable));
}
void ZSettingAudioWrap::SetSink(ZNativeSDKAudioSettingContextWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZSettingAudioWrap::EnableStereoAudio(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableStereoAudio(bEnable));
}
bool ZSettingAudioWrap::IsStereoAudioEnable()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsStereoAudioEnable();
}
ZNSDKError ZSettingAudioWrap::EnableMicOriginalInput(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableMicOriginalInput(bEnable));
}
bool ZSettingAudioWrap::IsMicOriginalInputEnable()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsMicOriginalInputEnable();
}
ZNSDKError ZSettingAudioWrap::EnableHoldSpaceKeyToSpeak(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableHoldSpaceKeyToSpeak(bEnable));
}
bool ZSettingAudioWrap::IsHoldSpaceKeyToSpeakEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsHoldSpaceKeyToSpeakEnabled();
}
ZNSDKError ZSettingAudioWrap::EnableAlwaysMuteMicWhenJoinVoip(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableAlwaysMuteMicWhenJoinVoip(bEnable));
}
bool ZSettingAudioWrap::IsAlwaysMuteMicWhenJoinVoipEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsAlwaysMuteMicWhenJoinVoipEnabled();
}
ZNSDKError ZSettingAudioWrap::EnableSuppressAudioNotify(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableSuppressAudioNotify(bEnable));
}
bool ZSettingAudioWrap::IsSuppressAudioNotifyEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsSuppressAudioNotifyEnabled();
}
ZNSDKError ZSettingAudioWrap::SetMicVol(float& value)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().SetMicVol(value));
}
ZNSDKError ZSettingAudioWrap::GetMicVol(float& value)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().GetMicVol(value));
}
ZNSDKError ZSettingAudioWrap::SetSpeakerVol(float& value)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().SetSpeakerVol(value));
}
ZNSDKError ZSettingAudioWrap::GetSpeakerVol(float& value)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().GetSpeakerVol(value));
}
ZNSDKError ZSettingAudioWrap::EnableEchoCancellation(bool bEnable)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().EnableEchoCancellation(bEnable));
}
bool ZSettingAudioWrap::IsEchoCancellationEnabled()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetSettingServiceWrap().T_GetAudioSettings().IsEchoCancellationEnabled();
}

void ZSettingAudioWrap::onComputerMicDeviceChanged(ZNList<ZNMicInfo> newMicList)
{
	if (m_pSink)
		m_pSink->onComputerMicDeviceChanged(newMicList);
}
void ZSettingAudioWrap::onComputerSpeakerDeviceChanged(ZNList<ZNSpeakerInfo> newSpeakerList)
{
	if (m_pSink)
		m_pSink->onComputerSpeakerDeviceChanged(newSpeakerList);
}
void ZSettingAudioWrap::onDefaultMicDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	if (m_pSink)
		m_pSink->onDefaultMicDeviceChanged(deviceId, deviceName);
}
void ZSettingAudioWrap::onDefaultSpeakerDeviceChanged(ZoomSTRING deviceId, ZoomSTRING deviceName)
{
	if (m_pSink)
		m_pSink->onDefaultSpeakerDeviceChanged(deviceId, deviceName);
}