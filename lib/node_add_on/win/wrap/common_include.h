#pragma once
#ifdef _NEED_STDAFX_
#include "StdAfx.h"
#endif
#include <windows.h>
#if (defined JS_WRAP)
#include "../h/zoom_sdk.h"
#include "../h/meeting_service_interface.h"
#include "../h/auth_service_interface.h"
#include "../h/setting_service_interface.h"
#include "../h/premeeting_service_interface.h"
#include "../h/calender_service_interface.h"
#include "../h/direct_share_helper_interface.h"
#include "../h/outlook_plugin_integration_helper_interface.h"
#include "../h/customized_resource_helper_interface.h"
#include "../h/customized_ui/customized_annotation.h"
#include "../h/customized_ui/customized_local_recording.h"
#include "../h/customized_ui/customized_share_render.h"
#include "../h/customized_ui/customized_ui_mgr.h"
#include "../h/customized_ui/customized_video_container.h"
#include "../h/customized_ui/zoom_customized_ui.h"
#include "../h/meeting_service_components/meeting_annotation_interface.h"
#include "../h/meeting_service_components/meeting_audio_interface.h"
#include "../h/meeting_service_components/meeting_breakout_rooms_interface.h"
#include "../h/meeting_service_components/meeting_chat_interface.h"
#include "../h/meeting_service_components/meeting_configuration_interface.h"
#include "../h/meeting_service_components/meeting_h323_helper_interface.h"
#include "../h/meeting_service_components/meeting_live_stream_interface.h"
#include "../h/meeting_service_components/meeting_participants_ctrl_interface.h"
#include "../h/meeting_service_components/meeting_phone_helper_interface.h"
#include "../h/meeting_service_components/meeting_recording_interface.h"
#include "../h/meeting_service_components/meeting_remote_ctrl_interface.h"
#include "../h/meeting_service_components/meeting_sharing_interface.h"
#include "../h/meeting_service_components/meeting_ui_ctrl_interface.h"
#include "../h/meeting_service_components/meeting_video_interface.h"
#include "../h/meeting_service_components/meeting_waiting_room_interface.h"
#include "../h/meeting_service_components/meeting_webinar_interface.h"
#include "../h/meeting_service_components/meeting_closedcaption_interface.h"
#include "../h/meeting_service_components/meeting_interpretation_interface.h"
#include "../h/zoom_sdk_ext.h"
#include "../h/zoom_sdk_util_define.h"
#include "../h/network_connection_handler_interface.h"
#include "../h/embedded_browser_interface.h"
#include "../h/ui_hook_interface.h"
#include "../h/zoom_sdk_platform.h"

#include "../h/rawdata/zoom_rawdata_api.h"
#include "../h/rawdata/rawdata_video_source_helper_interface.h"
#include "../h/rawdata/rawdata_renderer_interface.h"
#include "../h/rawdata/rawdata_audio_helper_interface.h"
#include "../h/zoom_sdk_raw_data_def.h"
#include "../h/zoom_sdk_sms_helper_interface.h"
#elif (defined CSHARP_WRAP) || (defined INTEL_UNITE)
#include "../h/zoom_sdk.h"
#include "../h/meeting_service_interface.h"
#include "../h/auth_service_interface.h"
#include "../h/setting_service_interface.h"
#include "../h/premeeting_service_interface.h"
#include "../h/calender_service_interface.h"
#include "../h/direct_share_helper_interface.h"
#include "../h/outlook_plugin_integration_helper_interface.h"
#include "../h/customized_resource_helper_interface.h"
#include "../h/customized_ui/customized_annotation.h"
#include "../h/customized_ui/customized_local_recording.h"
#include "../h/customized_ui/customized_share_render.h"
#include "../h/customized_ui/customized_ui_mgr.h"
#include "../h/customized_ui/customized_video_container.h"
#include "../h/customized_ui/zoom_customized_ui.h"
#include "../h/meeting_service_components/meeting_annotation_interface.h"
#include "../h/meeting_service_components/meeting_audio_interface.h"
#include "../h/meeting_service_components/meeting_breakout_rooms_interface.h"
#include "../h/meeting_service_components/meeting_chat_interface.h"
#include "../h/meeting_service_components/meeting_configuration_interface.h"
#include "../h/meeting_service_components/meeting_h323_helper_interface.h"
#include "../h/meeting_service_components/meeting_live_stream_interface.h"
#include "../h/meeting_service_components/meeting_participants_ctrl_interface.h"
#include "../h/meeting_service_components/meeting_phone_helper_interface.h"
#include "../h/meeting_service_components/meeting_recording_interface.h"
#include "../h/meeting_service_components/meeting_remote_ctrl_interface.h"
#include "../h/meeting_service_components/meeting_sharing_interface.h"
#include "../h/meeting_service_components/meeting_ui_ctrl_interface.h"
#include "../h/meeting_service_components/meeting_video_interface.h"
#include "../h/meeting_service_components/meeting_waiting_room_interface.h"
#include "../h/meeting_service_components/meeting_webinar_interface.h"
#include "../h/meeting_service_components/meeting_closedcaption_interface.h"
#include "../h/meeting_service_components/meeting_interpretation_interface.h"
#include "../h/zoom_sdk_ext.h"
#include "../h/zoom_sdk_util_define.h"
#include "../h/network_connection_handler_interface.h"
#include "../h/embedded_browser_interface.h"
#include "../h/ui_hook_interface.h"
#include "../h/zoom_sdk_platform.h"

#include "../h/rawdata/zoom_rawdata_api.h"
#include "../h/rawdata/rawdata_video_source_helper_interface.h"
#include "../h/rawdata/rawdata_renderer_interface.h"
#include "../h/rawdata/rawdata_audio_helper_interface.h"
#include "../h/zoom_sdk_raw_data_def.h"
#include "../h/zoom_sdk_sms_helper_interface.h"
#else
#include "../../zoom_sdk/include/zoom_sdk.h"
#include "../../zoom_sdk/include/meeting_service_interface.h"
#include "../../zoom_sdk/include/auth_service_interface.h"
#include "../../zoom_sdk/include/setting_service_interface.h"
#include "../../zoom_sdk/include/premeeting_service_interface.h"
#include "../../zoom_sdk/include/calender_service_interface.h"
#include "../../zoom_sdk/include/direct_share_helper_interface.h"
#include "../../zoom_sdk/include/outlook_plugin_integration_helper_interface.h"
#include "../../zoom_sdk/include/customized_resource_helper_interface.h"
#include "../../zoom_sdk/include/customized_ui/customized_annotation.h"
#include "../../zoom_sdk/include/customized_ui/customized_local_recording.h"
#include "../../zoom_sdk/include/customized_ui/customized_share_render.h"
#include "../../zoom_sdk/include/customized_ui/customized_ui_mgr.h"
#include "../../zoom_sdk/include/customized_ui/customized_video_container.h"
#include "../../zoom_sdk/include/customized_ui/zoom_customized_ui.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_annotation_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_audio_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_breakout_rooms_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_chat_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_configuration_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_h323_helper_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_live_stream_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_participants_ctrl_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_phone_helper_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_recording_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_remote_ctrl_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_sharing_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_ui_ctrl_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_video_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_waiting_room_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_webinar_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_closedcaption_interface.h"
#include "../../zoom_sdk/include/meeting_service_components/meeting_interpretation_interface.h"
#include "../../zoom_sdk/include/zoom_sdk_ext.h"
#include "../../zoom_sdk/include/zoom_sdk_util_define.h"
#include "../../zoom_sdk/include/network_connection_handler_interface.h"
#include "../../zoom_sdk/include/embedded_browser_interface.h"
#include "../../zoom_sdk/include/ui_hook_interface.h"
#include "../../../../zoom_sdk/zoom_sdk_rawdata_helper/zoom_sdk_platform.h"

#include "../../zoom_sdk/include/rawdata/zoom_rawdata_api.h"
#include "../../zoom_sdk/include/rawdata/rawdata_video_source_helper_interface.h"
#include "../../zoom_sdk/include/rawdata/rawdata_renderer_interface.h"
#include "../../zoom_sdk/include/rawdata/rawdata_audio_helper_interface.h"
#include "../../zoom_sdk/include/zoom_sdk_raw_data_def.h"
#include "../h/zoom_sdk_sms_helper_interface.h"
#endif
#include <string>
#include <functional>
#include "macro_define.h"
inline void myOutputDebugString(const char* format, ...)
{
	//return;
	va_list args;
	va_start(args, format);
	char szData[2048] = { 0 };
	vsnprintf(szData, 2048, format, args);

	OutputDebugStringA(szData);
	va_end(args);
}
inline void myOutputDebugStringW(const wchar_t* format, ...)
{
	//return;
	va_list args;
	va_start(args, format);
	wchar_t szData[2048] = { 0 };
	_vsnwprintf_s(szData, 2048, _TRUNCATE, format, args);

	OutputDebugStringW(szData);
	va_end(args);
}

_inline std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), slength, 0, 0);
	std::wstring r(len, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, s.c_str(), slength, &r[0], len);
	return r;
}

_inline std::string ws2s(const std::wstring& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), slength, 0, 0, 0, 0);
	std::string r(len, '\0');
	WideCharToMultiByte(CP_UTF8, 0, s.c_str(), slength, &r[0], len, 0, 0);
	return r;
}

#include "sdk_loader.h"