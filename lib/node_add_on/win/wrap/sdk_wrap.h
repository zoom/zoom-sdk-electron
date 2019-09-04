#pragma once
#include "auth_service_wrap.h"
#include "meeting_service_wrap.h"
#include "calender_service_wrap.h"
#include "premeeting_service_wrap.h"
#include "setting_service_wrap.h"
#include "network_connection_handler_wrap.h"
#include "ui_hook_wrap.h"
#include "embedded_browser_wrap.h"
#include "customized_ui_components_wrap/customized_ui_mgr_wrap.h"
#include "customized_resource_helper_wrap.h"
#include "rawdata_audio_channel_wrap.h"
#include "rawdata_share_channel_wrap.h"
#include "rawdata_video_channel_wrap.h"

BEGIN_ZOOM_SDK_NAMESPACE
class CSDKWrap
{
public:
	static CSDKWrap& GetInst();
	SDKError InitSDK(const wchar_t* sdkpath, InitParam& initParam);
	SDKError CleanUPSDK();
	const wchar_t* GetVersion();
	INetworkConnectionHelperWrap& GetNetworkConnectionHelperWrap();
	IAuthServiceWrap& GetAuthServiceWrap();
	IMeetingServiceWrap& GetMeetingServiceWrap();
	ICalenderServiceWrap& GetCalenderServiceWrap();
	IPreMeetingServiceWrap& GetPreMeetingServiceWrap();
	ISettingServiceWrap& GetSettingServiceWrap();
private:
	CSDKWrap();
};

class CSDKExtWrap
{
public:
	static CSDKExtWrap& GetInst();
	IUIHookerWrap& GetUIHookerWrap();
	IEmbeddedBrowserWrap* CreateEmbeddedBrowserWrap(HWND hwnd);
	void DestroyEmbeddedBrowserWrap(IEmbeddedBrowserWrap* pObj);
	ICustomizedResourceHelperWrap& GetCustomizedResourceHelperWrap();

	IAudioRawDataChannelWrap& GetAudioRawDataChannelWrap();
	IVideoRawDataChannelWrap& GetVideoRawDataChannelWrap();
	IShareRawDataChannelWrap& GetShareRawDataChannelWrap();
private:
	CSDKExtWrap();
};

class CSDKCustomizedUIWrap
{
public:
	static CSDKCustomizedUIWrap& GetInst();
	ICustomizedUIMgrWrap& GetCustomizedUIMgrWrap();
private:
	CSDKCustomizedUIWrap();
};
END_ZOOM_SDK_NAMESPACE