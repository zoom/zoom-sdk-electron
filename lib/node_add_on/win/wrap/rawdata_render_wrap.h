#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomSDKRenderer* InitIZoomSDKRendererFunc(IZoomSDKRendererDelegate* pEvent);
void UninitIZoomSDKRendererFunc(IZoomSDKRenderer* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IZoomSDKRenderer, IZoomSDKRendererDelegate)
STAITC_CLASS(IZoomSDKRenderer)
INIT_UNINIT_WITHEVENT(IZoomSDKRenderer)

SDKError SetEvent(IZoomSDKRendererDelegate* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}


//virtual SDKError setRawDataResolution(ZoomSDKResolution resolution) = 0;
DEFINE_FUNC_1(setRawDataResolution, SDKError, ZoomSDKResolution, resolution)
//virtual SDKError subscribe(uint32_t userId, ZoomSDKRawDataType type) = 0;
DEFINE_FUNC_2(subscribe, SDKError, uint32_t, userId, ZoomSDKRawDataType, type)
//virtual SDKError unSubscribe() = 0;
DEFINE_FUNC_0(unSubscribe, SDKError)
//virtual ZoomSDKResolution getResolution() = 0;
DEFINE_FUNC_0(getResolution, ZoomSDKResolution)
//virtual ZoomSDKRawDataType getRawDataType() = 0;
DEFINE_FUNC_0(getRawDataType, ZoomSDKRawDataType)
//virtual uint32_t getUserId() = 0;
DEFINE_FUNC_0(getUserId, uint32_t)

//virtual void onRawDataFrameReceived(YUVRawDataI420* data)
CallBack_FUNC_1(onRawDataFrameReceived, YUVRawDataI420*, data)
//virtual void onRawDataStatusChanged(RawDataStatus status)
CallBack_FUNC_1(onRawDataStatusChanged, RawDataStatus, status)
CallBack_FUNC_0(onRendererBeDestroyed)
END_CLASS_DEFINE(IZoomSDKRenderer)
END_ZOOM_SDK_NAMESPACE