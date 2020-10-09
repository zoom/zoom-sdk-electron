#include "meeting_webinar_ctrl_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingWebinarController* InitIMeetingWebinarControllerFunc(IMeetingWebinarCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingWebinarController* pObj = pOwner->GetSDKObj()->GetMeetingWebinarController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingWebinarControllerFunc(IMeetingWebinarController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError PromptAttendee2Panelist(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWebinarController, PromptAttendee2Panelist, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError DepromptPanelist2Attendee(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWebinarController, DepromptPanelist2Attendee, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError IsSupportAttendeeTalk() = 0;
IMPL_FUNC_0(IMeetingWebinarController, IsSupportAttendeeTalk, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError AllowAttendeeTalk(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWebinarController, AllowAttendeeTalk, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError DisallowAttendeeTalk(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingWebinarController, DisallowAttendeeTalk, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError AllowPanelistStartVideo() = 0;
IMPL_FUNC_0(IMeetingWebinarController, AllowPanelistStartVideo, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError DisallowPanelistStartVideo() = 0;
IMPL_FUNC_0(IMeetingWebinarController, DisallowPanelistStartVideo, SDKError, SDKERR_UNINITIALIZE)
//virtual WebinarMeetingStatus* GetWebinarMeetingStatus() = 0;
IMPL_FUNC_0(IMeetingWebinarController, GetWebinarMeetingStatus, WebinarMeetingStatus*, NULL)

END_ZOOM_SDK_NAMESPACE