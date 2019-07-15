#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingChatController* InitIMeetingChatControllerFunc(IMeetingChatCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingChatControllerFunc(IMeetingChatController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingChatController, IMeetingChatCtrlEvent)
NORMAL_CLASS(IMeetingChatController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingChatController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingChatCtrlEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError SendChatTo(unsigned int receiver, wchar_t* content) = 0;
DEFINE_FUNC_2(SendChatTo, SDKError, unsigned int, receiver, wchar_t*, content)
//virtual SDKError SendChat4WebinarMeeting(SendChatItem4Webinar& chatIteam) = 0;
DEFINE_FUNC_1(SendChat4WebinarMeeting, SDKError, SendChatItem4Webinar&, chatIteam)
//virtual const ChatStatus* GetChatStatus() = 0;
DEFINE_FUNC_0(GetChatStatus, const ChatStatus*)

//virtual void onChatMsgNotifcation(IChatMsgInfo* chatMsg, const wchar_t* content = NULL) = 0;
CallBack_FUNC_2(onChatMsgNotifcation, IChatMsgInfo*, chatMsg, const wchar_t*, content)
//virtual void onChatStautsChangedNotification(ChatStatus* status_) = 0;
CallBack_FUNC_1(onChatStautsChangedNotification, ChatStatus*, status_)
END_CLASS_DEFINE(IMeetingChatController)
END_ZOOM_SDK_NAMESPACE