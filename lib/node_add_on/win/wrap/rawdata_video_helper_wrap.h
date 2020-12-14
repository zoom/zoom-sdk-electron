#pragma once
#pragma once
#include "common_include.h"
#include "rawdata_renderer_callback_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomSDKVideoSourceHelper* InitIZoomSDKVideoSourceHelperFunc(ISDKRendererCallbackWrap* pEvent);
void UninitIZoomSDKVideoSourceHelperFunc(IZoomSDKVideoSourceHelper* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IZoomSDKVideoSourceHelper, ISDKRendererCallbackWrap)
STAITC_CLASS(IZoomSDKVideoSourceHelper)
INIT_UNINIT_WITHEVENT(IZoomSDKVideoSourceHelper)

//virtual SDKError setPreProcessor(IZoomSDKPreProcessor* processor) = 0;
DEFINE_FUNC_1(setPreProcessor, SDKError, IZoomSDKPreProcessor*, processor)
//virtual SDKError setExternalVideoSource(IZoomSDKVideoSource* source) = 0;
DEFINE_FUNC_1(setExternalVideoSource, SDKError, IZoomSDKVideoSource*, processor)

//IZoomSDKVideoSender.onPreProcessRawData(YUVProcessDataI420* rawData)
CallBack_FUNC_1(onPreProcessRawData, YUVProcessDataI420*, rawData);

//IZoomSDKVideoSource callbacks
//virtual	void onInitialize(IZoomSDKVideoSender* sender, IList<VideoSourceCapability >* support_cap_list, VideoSourceCapability& suggest_cap) = 0;
CallBack_FUNC_3(onInitialize, IZoomSDKVideoSender*, sender, IList<VideoSourceCapability >*, support_cap_list, VideoSourceCapability&, suggest_cap);
//virtual void onPropertyChange(IList<VideoSourceCapability >* support_cap_list, VideoSourceCapability suggest_cap) = 0;
CallBack_FUNC_2(onPropertyChange, IList<VideoSourceCapability >*, support_cap_list, VideoSourceCapability, suggest_cap)
//virtual void onStartSend() = 0;
CallBack_FUNC_0(onStartSend);
//virtual void onStopSend() = 0;
CallBack_FUNC_0(onStopSend);
//virtual void onUninitialized() = 0;
CallBack_FUNC_0(onUninitialized);

END_CLASS_DEFINE(IZoomSDKVideoSourceHelper)
END_ZOOM_SDK_NAMESPACE