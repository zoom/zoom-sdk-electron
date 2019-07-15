#include "meeting_chat_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingChatController* InitIMeetingChatControllerFunc(IMeetingChatCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingChatController* pObj = pOwner->GetSDKObj()->GetMeetingChatController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingChatControllerFunc(IMeetingChatController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError SendChatTo(unsigned int receiver, wchar_t* content) = 0;
IMPL_FUNC_2(IMeetingChatController, SendChatTo, SDKError, unsigned int, receiver, wchar_t*, content, SDKERR_UNINITIALIZE)
//virtual SDKError SendChat4WebinarMeeting(SendChatItem4Webinar& chatIteam) = 0;
IMPL_FUNC_1(IMeetingChatController, SendChat4WebinarMeeting, SDKError, SendChatItem4Webinar&, chatIteam, SDKERR_UNINITIALIZE)
//virtual const ChatStatus* GetChatStatus() = 0;
IMPL_FUNC_0(IMeetingChatController, GetChatStatus, const ChatStatus*, NULL)
END_ZOOM_SDK_NAMESPACE