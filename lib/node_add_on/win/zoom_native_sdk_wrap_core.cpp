#include "../zoom_native_sdk_wrap_core.h"
//
#include "wrap/sdk_wrap.cpp"
#include "wrap/auth_service_wrap.cpp"
#include "wrap/meeting_service_wrap.cpp"
#include "wrap/setting_service_wrap.cpp"
#include "wrap/premeeting_service_wrap.cpp"
#include "wrap/network_connection_handler_wrap.cpp"
#include "wrap/calender_service_wrap.cpp"
#include "wrap/sdk_loader.cpp"
#include "wrap/ui_hook_wrap.cpp"
#include "wrap/embedded_browser_wrap.cpp"
#include "wrap/customized_resource_helper_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_annotation_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_audio_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_breakout_rooms_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_chat_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_configuration_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_h323_helper_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_participants_ctrl_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_phone_helper_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_recording_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_remote_ctrl_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_sharing_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_ui_ctrl_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_video_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_waiting_room_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_realname_auth_helper_wrap.cpp"
//
#include "wrap/video_setting_context_wrap.cpp"
#include "wrap/audio_setting_context_wrap.cpp"
#include "wrap/recording_setting_context_wrap.cpp"
#include "wrap/camera_controller_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_live_stream_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_webinar_ctrl_wrap.cpp"
#include "wrap/meeting_service_components_wrap/meeting_closedcaption_ctrl_wrap.cpp"
#include "wrap/customized_ui_components_wrap/customized_ui_mgr_wrap.cpp"



#include "wrap/directshare_helper_wrap.cpp"
#include "wrap/outlook_plugin_integration_helper_wrap.cpp"
#include "zoom_native_to_wrap.h"
#include "../resource.h"


std::string wsTOs(const ZoomSTRING& s)
{

	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), slength, 0, 0, 0, 0);
	std::string r(len, '\0');
	WideCharToMultiByte(CP_UTF8, 0, s.c_str(), slength, &r[0], len, 0, 0);
	return r;
}

void DummyFunc()
{
	int i = i / 0;
	printf("%d", i);
}
ZNSDKError ZNativeSDKWrap::InitSDK(ZNInitParam& initParam)
{
	ZOOM_SDK_NAMESPACE::InitParam param;
	param.emLanguageID = Map2SDKDefine(initParam.langid);
	param.strWebDomain = initParam.domain.c_str();
	param.enableLogByDefault = initParam.enable_log;
	param.strSupportUrl = initParam.strSupportUrl.c_str();
	param.obConfigOpts.customizedLang.langName = wsTOs(initParam.obConfigOpts.customizedLang.langName).c_str();
	param.obConfigOpts.customizedLang.langInfo = wsTOs(initParam.obConfigOpts.customizedLang.langInfo).c_str();
	param.locale = Map2SDKDefine(initParam.locale);

	HMODULE hRes = NULL;
	param.uiWindowIconSmallID = IDI_SDK_ICON;
	param.uiWindowIconBigID = IDI_SDK_BIG_ICON;
	GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)DummyFunc, &hRes);
	param.hResInstance = hRes;
	FreeLibrary(hRes);


	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().InitSDK(
		initParam.path.size() > 0 ? initParam.path.c_str() : NULL, param));
	if (ZNSDKERR_SUCCESS == err)
	{
		_z_auth_service_wrap.Init();
	}
	return err;
}
ZNSDKError ZNativeSDKWrap::CleanUPSDK()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().CleanUPSDK();
	return ZNSDKERR_SUCCESS;
}
ZoomSTRING ZNativeSDKWrap::GetVersion()
{

	ZoomSTRING zn_version;
	zn_version = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetVersion();
	return zn_version;
}
ZNativeSDKWrap::ZNativeSDKWrap()
{
}
ZNativeSDKWrap::~ZNativeSDKWrap()
{
}
ZAuthServiceWrap& ZNativeSDKWrap::GetAuthServiceWrap()
{
	return _z_auth_service_wrap;
}
ZMeetingServiceWrap& ZNativeSDKWrap::GetMeetingServiceWrap()
{
	return _z_meeting_service_wrap;
}
ZSettingServiceWrap& ZNativeSDKWrap::GetSettingServiceWrap()
{
	return _z_setting_service_wrap;
}
ZPremeetingServiceWrap& ZNativeSDKWrap::GetPremeetingServiecWrap()
{
	return _z_premeeting_service_wrap;
}
ZCustomizedResourceWrap& ZNativeSDKWrap::GetCustomizedResourceWrap()
{
	return _z_customized_resource_wrap;
}
