#pragma once
#include "rawdata_share_channel_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_RAWDATA_NAMESPACE::IZoomSDKRenderer* InitIZoomSDKRendererFunc(IZoomSDKRendererDelegate* pEvent)
{
	ZOOM_RAWDATA_NAMESPACE::IZoomSDKRenderer* pObj(NULL);
	CSDKImpl::GetInst().createRenderer(&pObj, pEvent);
	return pObj;
}

void UninitIZoomSDKRendererFunc(ZOOM_RAWDATA_NAMESPACE::IZoomSDKRenderer* obj)
{
	if (obj)
		CSDKImpl::GetInst().destroyRenderer();
}
SDKError IZoomSDKRendererWrap::setRawDataResolution(ZoomSDKResolution resolution)
{
	if (m_obj)
		return m_obj->setRawDataResolution(resolution);
	return SDKERR_UNINITIALIZE;
}

SDKError IZoomSDKRendererWrap::subscribe(uint32_t userId, ZoomSDKRawDataType type)
{
	if (m_obj)
		return m_obj->subscribe(userId, type);
	return SDKERR_UNINITIALIZE;
}
SDKError IZoomSDKRendererWrap::unSubscribe()
{
	if (m_obj)
		return m_obj->unSubscribe();
	return SDKERR_UNINITIALIZE;
}
ZoomSDKResolution IZoomSDKRendererWrap::getResolution()
{
	if (m_obj)
		return m_obj->getResolution();
	return SDKERR_UNINITIALIZE;
}
ZoomSDKRawDataType IZoomSDKRendererWrap::getRawDataType()
{
	if (m_obj)
		return m_obj->getRawDataType();
	return SDKERR_UNINITIALIZE;
}
uint32_t IZoomSDKRendererWrap::getUserId()
{
	if (m_obj)
		return m_obj->getUserId();
	return SDKERR_UNINITIALIZE;
}

END_ZOOM_SDK_NAMESPACE