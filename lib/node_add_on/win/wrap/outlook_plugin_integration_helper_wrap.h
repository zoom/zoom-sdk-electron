#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IAuthServiceWrap;
IOutlookPluginIntegrationHelper* InitIOutlookPluginIntegrationHelperFunc(IOutlookPluginIntegrationHelperEvent* pEvent, IAuthServiceWrap* pOwner);
void UninitIOutlookPluginIntegrationHelperFunc(IOutlookPluginIntegrationHelper* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IOutlookPluginIntegrationHelper, IOutlookPluginIntegrationHelperEvent)
NORMAL_CLASS(IOutlookPluginIntegrationHelper)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IOutlookPluginIntegrationHelper, IAuthServiceWrap)
virtual SDKError SetEvent(IOutlookPluginIntegrationHelperEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual SDKError Start(const wchar_t* ipc_channel_name = NULL) = 0;
DEFINE_FUNC_1(Start, SDKError, const wchar_t*, ipc_channel_name = NULL)
//virtual SDKError Stop() = 0;
DEFINE_FUNC_0(Stop, SDKError)

//virtual void onOutlookPluginNeedLoginRequestNotification() = 0;
CallBack_FUNC_0(onOutlookPluginNeedLoginRequestNotification)
//virtual void onOutlookPluginScheduleMeetingRequestNotification() = 0;
CallBack_FUNC_0(onOutlookPluginScheduleMeetingRequestNotification)
//virtual void onOutlookPluginDefaultMeetingTopicRequestNotification(const wchar_t* pScheduleForEmail, wchar_t** ppDefaultMeetingTopic) = 0;
CallBack_FUNC_2(onOutlookPluginDefaultMeetingTopicRequestNotification, const wchar_t*, pScheduleForEmail, wchar_t**, ppDefaultMeetingTopic)

END_CLASS_DEFINE(IOutlookPluginIntegrationHelper)
END_ZOOM_SDK_NAMESPACE