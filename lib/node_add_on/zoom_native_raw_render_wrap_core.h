#ifndef _zoom_native_raw_render_wrap_core_h_
#define _zoom_native_raw_render_wrap_core_h_
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_node_rawdata_helper_mgr_class.h"
#include "win/wrap/sdk_wrap.h"
#include "win/wrap/sdk_loader.h"
#include "win/zoom_native_to_wrap.h"

class ZOOM_HIDE_SYMBOL ZNativeRawRenderWrap :  public ZOOM_SDK_NAMESPACE::IZoomSDKRendererDelegate
{
public:
	ZNativeRawRenderWrap();
	virtual ~ZNativeRawRenderWrap();

	ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* GetNativeRender();
	void SetNativeRender(ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* nativeRender_);
	void SetRecvHandle(unsigned long long recvHandle);
	unsigned long long GetRecvHandle();
	void SetRawDataType(ZNZoomSDKRawDataType type);
	ZNZoomSDKRawDataType GetRawDataType();
	
	virtual void onRawDataFrameReceived(YUVRawDataI420* data);
	virtual void onRawDataStatusChanged(RawDataStatus status);
	virtual void onRendererBeDestroyed();

private:
	ZOOM_SDK_NAMESPACE::IZoomSDKRenderer* m_pNativeRender;
	unsigned long long m_recv_handle;
	ZNZoomSDKRawDataType m_rawDataType;
};
#endif