#ifndef _zoom_native_raw_api_wrap_core_h_
#define _zoom_native_raw_api_wrap_core_h_
#include "zoom_native_sdk_wrap_core_def.h"
#ifdef _WIN32
#include "zoom_native_raw_render_wrap_core.h"
#include "zoom_native_audio_rawdata_wrap_core.h"
#else
#include "./mac/Header_include.h"
#import <Foundation/Foundation.h>
#endif

#include <map>
class ZOOM_HIDE_SYMBOL ZNativeRawAPIWrap
{
public:
	ZNativeRawAPIWrap();
	virtual ~ZNativeRawAPIWrap();
	bool HasRawDataLicense();
	ZNSDKError InitAudioRawDataHelper();
	void GetRawdataVideoSourceHelper();
	ZNSDKError CreateRenderer(unsigned long long recv_handle);
	ZNSDKError DestroyRenderer(unsigned long long recv_handle);
	ZNSDKError Subscribe(uint32_t userId, ZNZoomSDKRawDataType type, unsigned long long recv_handle);
	ZNSDKError UnSubscribe(unsigned long long recv_handle);
	ZNSDKError SetRawDataResolution(ZNZoomSDKResolution resolution, unsigned long long recv_handle);
	ZNSDKError GetResolution(ZNZoomSDKResolution& resolution, unsigned long long recv_handle);
	ZNSDKError GetRawDataType(ZNZoomSDKRawDataType& type, unsigned long long recv_handle);
	ZNSDKError GetUserId(uint32_t& user_id, unsigned long long recv_handle);

	ZNSDKError SubscribeAudioRawdata();
	ZNSDKError UnSubscribeAudioRawdata();

	void HandleNativeRendererBeDestroyed(unsigned long long recv_handle);

private:
#ifdef _WIN32
	std::map<unsigned long long, ZNativeRawRenderWrap* > m_rawdatarender_map;
	ZNativeAudioRawDataWrap m_audiorawdatawrap;
#else
    NSMutableDictionary *renderDic;
    ZoomSDKAudioRawDataHelper *audioRawDataWrap;
#endif
};
#endif
