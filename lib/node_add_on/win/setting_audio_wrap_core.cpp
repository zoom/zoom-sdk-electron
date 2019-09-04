
#include "../setting_audio_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/audio_setting_context_wrap.h"
#include "zoom_native_to_wrap.h"

ZSettingAudioWrap::ZSettingAudioWrap()
{

}
ZSettingAudioWrap::~ZSettingAudioWrap()
{
	Uninit();
}
void ZSettingAudioWrap::Init()
{

}
void ZSettingAudioWrap::Uninit()
{

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