#pragma once
#include "rawdata_video_channel_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel* InitIVideoRawDataChannelFunc()
{
	ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel* pObj(NULL);
	CSDKImpl::GetInst().RetrieveVideoRawDataChannel(&pObj);
	return pObj;
}

void UninitIVideoRawDataChannelFunc(ZOOM_RAWDATA_NAMESPACE::IVideoRawDataChannel* obj)
{

}

SDKError IVideoRawDataChannelWrap::Start(ZOOM_RAWDATA_NAMESPACE::RawDataMemoryMode& mode, ZOOM_RAWDATA_NAMESPACE::IVideoRawDataReceiver* data_receiver)
{
	SetEvent(data_receiver);
	if (m_obj)
		return error_Internal_map(m_obj->Start(mode, data_receiver));
	return SDKERR_UNINITIALIZE;
}

SDKError IVideoRawDataChannelWrap::Stop()
{
	SetEvent(NULL);
	if (m_obj)
		return error_Internal_map(m_obj->Stop());
	return SDKERR_UNINITIALIZE;

}

SDKError IVideoRawDataChannelWrap::Subscribe(unsigned int node_id, ZOOM_RAWDATA_NAMESPACE::RawDataResolution size_, unsigned long long recver_handle)
{
	if (m_obj)
		return error_Internal_map(m_obj->Subscribe(node_id, size_, recver_handle));
	return SDKERR_UNINITIALIZE;
}

SDKError IVideoRawDataChannelWrap::UnSubscribe(unsigned int node_id, unsigned long long recver_handle)
{
	if (m_obj)
		return error_Internal_map(m_obj->UnSubscribe(node_id, recver_handle));
	return SDKERR_UNINITIALIZE;
}

SDKError IVideoRawDataChannelWrap::GetLocalDeviceStatus(void* device, ZOOM_RAWDATA_NAMESPACE::LocalVideoDeviceStatus& status)
{
	if (m_obj)
		return error_Internal_map(m_obj->GetLocalDeviceStatus(device, status));
	return SDKERR_UNINITIALIZE;
}

SDKError IVideoRawDataChannelWrap::RotateLocalDevice(void* device, ZOOM_RAWDATA_NAMESPACE::LocalVideoDeviceRotation& rotation_flag)
{
	if (m_obj)
		return error_Internal_map(m_obj->RotateLocalDevice(device, rotation_flag));
	return SDKERR_UNINITIALIZE;
}

END_ZOOM_SDK_NAMESPACE