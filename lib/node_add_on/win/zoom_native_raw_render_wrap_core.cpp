#include "../zoom_native_raw_render_wrap_core.h"
#include "../zoom_native_sdk_wrap_core.h"
extern ZNativeSDKWrap _g_native_wrap;
ZNativeRawRenderWrap::ZNativeRawRenderWrap()
{
	m_pNativeRender = NULL;
	m_recv_handle = 0xffffffff;
	m_rawDataType = ZNRAW_DATA_TYPE_VIDEO;
}
ZNativeRawRenderWrap::~ZNativeRawRenderWrap()
{
	m_pNativeRender = NULL;
	m_recv_handle = 0xffffffff;
	m_rawDataType = ZNRAW_DATA_TYPE_VIDEO;
}

ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* ZNativeRawRenderWrap::GetNativeRender()
{
	return m_pNativeRender;
}
void ZNativeRawRenderWrap::SetNativeRender(ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* nativeRender)
{
	m_pNativeRender = nativeRender;
}
void ZNativeRawRenderWrap::SetRecvHandle(unsigned long long recvHandle)
{
	m_recv_handle = recvHandle;
}
unsigned long long ZNativeRawRenderWrap::GetRecvHandle()
{
	return m_recv_handle;
}
void ZNativeRawRenderWrap::SetRawDataType(ZNZoomSDKRawDataType type)
{
	m_rawDataType = type;
}
ZNZoomSDKRawDataType ZNativeRawRenderWrap::GetRawDataType()
{
	return m_rawDataType;
}

////////////////

void ZNativeRawRenderWrap::onRawDataFrameReceived(YUVRawDataI420* data_)
{
	ZoomNodeRawDataHelperMgr::GetInst().onRawDataFrameReceived(data_, m_recv_handle, m_rawDataType);
}

void ZNativeRawRenderWrap::onRawDataStatusChanged(RawDataStatus status)
{
	ZoomNodeRawDataHelperMgr::GetInst().onRawDataStatusChanged((ZNRawDataStatus)status, m_recv_handle);
}
void ZNativeRawRenderWrap::onRendererBeDestroyed()
{
	_g_native_wrap.GetRawAPIWrap().HandleNativeRendererBeDestroyed(m_recv_handle);
}