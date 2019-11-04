#ifndef _zoom_native_sdk_wrap_core_h_
#define _zoom_native_sdk_wrap_core_h_
#include "zoom_native_sdk_wrap_core_def.h"
#include "auth_service_wrap_core.h"
#include "meeting_service_wrap_core.h"
#include "setting_service_wrap_core.h"
#include "premeeting_service_wrap_core.h"
#include "customized_resource_wrap_core.h"

class ZOOM_HIDE_SYMBOL ZNativeSDKWrap
{
public:
	ZNativeSDKWrap();
	virtual ~ZNativeSDKWrap();
	ZNSDKError InitSDK(ZNInitParam& initParam);
	ZNSDKError CleanUPSDK();
	ZoomSTRING GetVersion();
	ZAuthServiceWrap& GetAuthServiceWrap();
	ZMeetingServiceWrap& GetMeetingServiceWrap();
	ZSettingServiceWrap& GetSettingServiceWrap();
	ZPremeetingServiceWrap& GetPremeetingServiecWrap();
	ZCustomizedResourceWrap& GetCustomizedResourceWrap();
private:
	ZAuthServiceWrap _z_auth_service_wrap;
	ZMeetingServiceWrap _z_meeting_service_wrap;
	ZSettingServiceWrap _z_setting_service_wrap;
	ZPremeetingServiceWrap _z_premeeting_service_wrap;
	ZCustomizedResourceWrap _z_customized_resource_wrap;
};
#endif