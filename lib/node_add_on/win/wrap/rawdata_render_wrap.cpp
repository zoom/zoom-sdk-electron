#pragma once
#include "rawdata_render_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomSDKRenderer* InitIZoomSDKRendererFunc(IZoomSDKRendererDelegate* pEvent)
{
	IZoomSDKRenderer* pObj(NULL);
	CSDKImpl::GetInst().createRenderer(&pObj, pEvent);
	return pObj;
}

void UninitIZoomSDKRendererFunc(IZoomSDKRenderer* obj)
{
	if (obj)
		CSDKImpl::GetInst().destroyRenderer(obj);
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
	return ZoomSDKResolution_NoUse;
}
ZoomSDKRawDataType IZoomSDKRendererWrap::getRawDataType()
{
	if (m_obj)
		return m_obj->getRawDataType();
	return RAW_DATA_TYPE_VIDEO;
}
uint32_t IZoomSDKRendererWrap::getUserId()
{
	if (m_obj)
		return m_obj->getUserId();
	return 0xFFFF;
}

END_ZOOM_SDK_NAMESPACE