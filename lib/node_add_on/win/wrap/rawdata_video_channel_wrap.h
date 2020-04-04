#pragma once
#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel* InitIVideoRawDataChannelFunc();
void UninitIVideoRawDataChannelFunc(ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IVideoRawDataChannel, ZOOM_RAWDATA_NAMESPACE::IVideoRawDataReceiver)
STAITC_CLASS(IVideoRawDataChannel)
INIT_UNINIT(IVideoRawDataChannel)

SDKError SetEvent(ZOOM_RAWDATA_NAMESPACE::IVideoRawDataReceiver* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual SDKRawDataError Start(RawDataMemoryMode mode, IVideoRawDataReceiver* data_receiver) = 0;
DEFINE_FUNC_2(Start, SDKError, ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode&, mode, ZOOM_RAWDATA_NAMESPACE::IVideoRawDataReceiver*, data_receiver)
//virtual SDKRawDataError Subscribe(unsigned int node_id, RawDataResolution size_, unsigned long long recver_handle) = 0;
DEFINE_FUNC_3(Subscribe, SDKError, unsigned int, node_id, ZOOM_RAWDATA_NAMESPACE::RawDataResolution, size_, unsigned long long, recver_handle)
//virtual SDKRawDataError UnSubscribe(unsigned int node_id, unsigned long long recver_handle) = 0;
DEFINE_FUNC_2(UnSubscribe, SDKError, unsigned int, node_id, unsigned long long, recver_handle)
//virtual SDKRawDataError Stop() = 0;
DEFINE_FUNC_0(Stop, SDKError)

//virtual SDKRawDataError GetLocalDeviceStatus(void* device, LocalVideoDeviceStatus& status) = 0;
DEFINE_FUNC_2(GetLocalDeviceStatus, SDKError, void*, device, ZOOM_RAWDATA_NAMESPACE::LocalVideoDeviceStatus&, status)
//virtual SDKRawDataError RotateLocalDevice(void* device, LocalVideoDeviceRotation& rotation_flag) = 0;
DEFINE_FUNC_2(RotateLocalDevice, SDKError, void*, device, ZOOM_RAWDATA_NAMESPACE::LocalVideoDeviceRotation&, rotation_flag)

//virtual void onDeviceRunning(void* device) = 0;
CallBack_FUNC_1(onDeviceRunning, void*, device);
//virtual void onDeviceStop(void* device) = 0;
CallBack_FUNC_1(onDeviceStop, void*, device);
//virtual void onVideoRawDataReceived(YUVRawDataI420* data_, IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_2(onVideoRawDataReceived, YUVRawDataI420*, data_, IVector<unsigned long long >*, recv_handle_list)
//virtual void onSubscribedVideoUserDataOn(IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_1(onSubscribedVideoUserDataOn, IVector<unsigned long long >*, recv_handle_list)
//virtual void onSubscribedVideoUserDataOff(IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_1(onSubscribedVideoUserDataOff, IVector<unsigned long long >*, recv_handle_list)
//virtual void onSubscribedVideoUserLeft(IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_1(onSubscribedVideoUserLeft, IVector<unsigned long long >*, recv_handle_list)

// virtual void onPreProcessRawData(YUVProcessDataI420* data_, IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_2(onPreProcessRawData, ZOOM_RAWDATA_NAMESPACE::YUVProcessDataI420*, data_, IVector<unsigned long long >*, recv_handle_list)

END_CLASS_DEFINE(ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel)
END_ZOOM_SDK_NAMESPACE