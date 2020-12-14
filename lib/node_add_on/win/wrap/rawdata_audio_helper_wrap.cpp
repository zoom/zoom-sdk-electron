#pragma once
#include "rawdata_audio_helper_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomSDKAudioRawDataHelper* InitIZoomSDKAudioRawDataHelperFunc(IZoomSDKAudioRawDataDelegate* pEvent)
{
	IZoomSDKAudioRawDataHelper* pObj(NULL);
	pObj = CSDKImpl::GetInst().GetAudioRawdataHelper();
	if (pObj)
	{
		SetEvent(pEvent);
	}
	return pObj;
}

void UninitIZoomSDKAudioRawDataHelperFunc(IZoomSDKAudioRawDataHelper* obj)
{
	
}

//virtual SDKError subscribe(IZoomSDKAudioRawDataDelegate* pDelegate) = 0;
SDKError IZoomSDKAudioRawDataHelperWrap::subscribe(IZoomSDKAudioRawDataDelegate* pDelegate)
{
	SetEvent(pDelegate);
	if (m_obj)
		return m_obj->subscribe(pDelegate);
	return SDKERR_UNINITIALIZE;
}

//virtual SDKError unSubscribe() = 0;
SDKError IZoomSDKAudioRawDataHelperWrap::unSubscribe()
{
	SetEvent(NULL);
	if (m_obj)
		return m_obj->unSubscribe();
	return SDKERR_UNINITIALIZE;

}
END_ZOOM_SDK_NAMESPACE