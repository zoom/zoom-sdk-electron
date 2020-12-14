#pragma once
#include "rawdata_video_helper_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomSDKVideoSourceHelper* InitIZoomSDKVideoSourceHelperFunc(ISDKRendererCallbackWrap* pEvent)
{
	IZoomSDKVideoSourceHelper* pObj(NULL);
	pObj = CSDKImpl::GetInst().GetRawdataVideoSourceHelper();
	return pObj;
}

void UninitIZoomSDKVideoSourceHelperFunc(IZoomSDKVideoSourceHelper* obj)
{
}

SDKError IZoomSDKVideoSourceHelperWrap::setPreProcessor(IZoomSDKPreProcessor* processor)
{
	if (m_obj)
	{
		if (external_cb)
			external_cb->SetPreProcessorCB(processor);
		return m_obj->setPreProcessor(processor);
	}
	return SDKERR_UNINITIALIZE;
}

SDKError IZoomSDKVideoSourceHelperWrap::setExternalVideoSource(IZoomSDKVideoSource* processor)
{
	if (m_obj)
	{
		if (external_cb)
			external_cb->SetVideoSourceCB(processor);

		return m_obj->setExternalVideoSource(processor);
	}
	return SDKERR_UNINITIALIZE;

}

END_ZOOM_SDK_NAMESPACE