#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel* InitIShareRawDataChannelFunc();
void UninitIShareRawDataChannelFunc(ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IShareRawDataChannel, ZOOM_RAWDATA_NAMESPACE::IShareRawDataReceiver)
STAITC_CLASS(IShareRawDataChannel)
INIT_UNINIT(IShareRawDataChannel)

SDKError SetEvent(ZOOM_RAWDATA_NAMESPACE::IShareRawDataReceiver* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual SDKRawDataError Start(RawDataMemoryMode mode, IShareRawDataReceiver* data_receiver) = 0;
DEFINE_FUNC_2(Start, SDKError, ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode&, mode, ZOOM_RAWDATA_NAMESPACE::IShareRawDataReceiver*, data_receiver)
//virtual SDKRawDataError Subscribe(unsigned int node_id, RawDataResolution size_, unsigned long long recver_handle) = 0;
DEFINE_FUNC_3(Subscribe, SDKError, unsigned int, node_id, ZOOM_RAWDATA_NAMESPACE::RawDataResolution, size_, unsigned long long, recver_handle)
//virtual SDKRawDataError UnSubscribe(unsigned int node_id, unsigned long long recver_handle) = 0;
DEFINE_FUNC_2(UnSubscribe, SDKError, unsigned int, node_id, unsigned long long, recver_handle)
//virtual SDKRawDataError Stop() = 0;
DEFINE_FUNC_0(Stop, SDKError)

//virtual void onShareRawDataReceived(YUVRawDataI420* data_, IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_2(onShareRawDataReceived, YUVRawDataI420*, data_, IVector<unsigned long long >*, recv_handle_list)
//virtual void onSubscribedShareUserDataOn(IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_1(onSubscribedShareUserDataOn, IVector<unsigned long long >*, recv_handle_list)
//virtual void onSubscribedShareUserDataOff(IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_1(onSubscribedShareUserDataOff, IVector<unsigned long long >*, recv_handle_list)
//virtual void onSubscribedShareUserLeft(IVector<unsigned long long >* recv_handle_list) = 0;
CallBack_FUNC_1(onSubscribedShareUserLeft, IVector<unsigned long long >*, recv_handle_list)

END_CLASS_DEFINE(ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel)
END_ZOOM_SDK_NAMESPACE