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
#include "rawdata_audio_helper_wrap.h"
#include "rawdata_render_wrap.h"
#include "rawdata_video_helper_wrap.h"

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

	IZoomSDKVideoSourceHelperWrap& GetRawdataVideoSourceHelperWrap();
	IZoomSDKAudioRawDataHelperWrap& GetAudioRawdataHelperWrap();

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

class CSDKRendererWrap
{
public:
	static CSDKRendererWrap& GetInst();
	IZoomSDKRendererWrap& GetRendererWrap();
private:
	CSDKRendererWrap();
};

END_ZOOM_SDK_NAMESPACE