#pragma once
#include "rawdata_share_channel_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel* InitIShareRawDataChannelFunc()
{
	ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel* pObj(NULL);
	CSDKImpl::GetInst().RetrieveShareRawDataChannel(&pObj);
	return pObj;
}

void UninitIShareRawDataChannelFunc(ZOOM_RAWDATA_NAMESPACE::IShareRawDataChannel* obj)
{

}

SDKError IShareRawDataChannelWrap::Start(ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode& mode, ZOOM_RAWDATA_NAMESPACE::IShareRawDataReceiver* data_receiver)
{
	SetEvent(data_receiver);
	if (m_obj)
		return error_Internal_map(m_obj->Start(mode, data_receiver));
	return SDKERR_UNINITIALIZE;
}

SDKError IShareRawDataChannelWrap::Stop()
{
	SetEvent(NULL);
	if (m_obj)
		return error_Internal_map(m_obj->Stop());
	return SDKERR_UNINITIALIZE;
}

SDKError IShareRawDataChannelWrap::Subscribe(unsigned int node_id, ZOOM_RAWDATA_NAMESPACE::RawDataResolution size_, unsigned long long recver_handle)
{
	if (m_obj)
		return error_Internal_map(m_obj->Subscribe(node_id, size_, recver_handle));
	return SDKERR_UNINITIALIZE;
}

ZOOM_SDK_NAMESPACE::SDKError IShareRawDataChannelWrap::UnSubscribe(unsigned int node_id, unsigned long long recver_handle)
{
	if (m_obj)
		return error_Internal_map(m_obj->UnSubscribe(node_id, recver_handle));
	return SDKERR_UNINITIALIZE;
}

END_ZOOM_SDK_NAMESPACE