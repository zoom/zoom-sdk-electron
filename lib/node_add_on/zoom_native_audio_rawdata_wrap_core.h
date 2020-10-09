#ifndef _zoom_native_audio_rawdata_wrap_core_h_
#define _zoom_native_audio_rawdata_wrap_core_h_
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_node_rawdata_helper_mgr_class.h"
#include "win/wrap/sdk_wrap.h"
#include "win/wrap/sdk_loader.h"
#include "win/zoom_native_to_wrap.h"

class ZOOM_HIDE_SYMBOL ZNativeAudioRawDataWrap :  public ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataDelegate
{
public:
	ZNativeAudioRawDataWrap();
	virtual ~ZNativeAudioRawDataWrap();

	ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* GetNativeHelper();
	void SetNativeHelper(ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* nativeHelper_);

	ZNSDKError SubScribe();
	ZNSDKError UnSubScribe();
	
	virtual void onMixedAudioRawDataReceived(AudioRawData* data_);
	virtual void onOneWayAudioRawDataReceived(AudioRawData* data_, uint32_t node_id);

private:
	ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelper* m_pNativeAudioRawDataHelper;
};
#endif