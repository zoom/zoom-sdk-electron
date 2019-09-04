#pragma once
#include "rawdata_audio_channel_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel* InitIAudioRawDataChannelFunc()
{
	ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel* pObj(NULL);
	CSDKImpl::GetInst().RetrieveAudioRawDataChannel(&pObj);
	return pObj;
}

void UninitIAudioRawDataChannelFunc(ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel* obj)
{
	
}

//virtual SDKRawDataError Start(RawDataMemoryMode mode, IAudioRawDataReceiver* data_receiver) = 0;
SDKError IAudioRawDataChannelWrap::Start(ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode& mode, ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver* data_receiver)
{
	SetEvent(data_receiver);
	if (m_obj)
		return error_Internal_map(m_obj->Start(mode, data_receiver));
	return SDKERR_UNINITIALIZE;
}

//virtual SDKRawDataError Stop() = 0;
SDKError IAudioRawDataChannelWrap::Stop()
{
	SetEvent(NULL);
	if (m_obj)
		return error_Internal_map(m_obj->Stop());
	return SDKERR_UNINITIALIZE;

}
END_ZOOM_SDK_NAMESPACE