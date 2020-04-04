#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel* InitIAudioRawDataChannelFunc();
void UninitIAudioRawDataChannelFunc(ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IAudioRawDataChannel, ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver)
STAITC_CLASS(IAudioRawDataChannel)
INIT_UNINIT(IAudioRawDataChannel)

SDKError SetEvent(ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKRawDataError Start(RawDataMode mode, IAudioRawDataReceiver* data_receiver) = 0;
DEFINE_FUNC_2(Start, SDKError, ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode&, mode, ZOOM_RAWDATA_NAMESPACE::IAudioRawDataReceiver*, data_receiver)
//virtual SDKRawDataError Stop() = 0;
DEFINE_FUNC_0(Stop, SDKError)


//virtual void onMixedAudioRawDataReceived(AudioRawData* data_) = 0;
CallBack_FUNC_1(onMixedAudioRawDataReceived, AudioRawData*, data_)
//virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, unsigned int node_id) = 0;
CallBack_FUNC_2(onOneWayAudioRawDataReceived, AudioRawData*, data_, unsigned int, node_id)


END_CLASS_DEFINE(ZOOM_RAWDATA_NAMESPACE::IAudioRawDataChannel)
END_ZOOM_SDK_NAMESPACE