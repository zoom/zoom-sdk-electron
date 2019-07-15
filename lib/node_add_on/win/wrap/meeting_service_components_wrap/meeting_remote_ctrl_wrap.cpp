#include "meeting_remote_ctrl_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingRemoteController* InitIMeetingRemoteControllerFunc(IMeetingRemoteCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingRemoteController* pObj = pOwner->GetSDKObj()->GetMeetingRemoteController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingRemoteControllerFunc(IMeetingRemoteController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}
//virtual SDKError CanRequestControl(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, CanRequestControl, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError IsHaveRemoteControlRight(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, IsHaveRemoteControlRight, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError IsInRemoteControllingStatus(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, IsInRemoteControllingStatus, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError EnterRemoteControllingStatus(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, EnterRemoteControllingStatus, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError LeaveRemoteControllingStatus(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, LeaveRemoteControllingStatus, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError RequestRemoteControl(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, RequestRemoteControl, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError GiveupRemoteControl(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, GiveupRemoteControl, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError GiveRemoteControlTo(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, GiveRemoteControlTo, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError DeclineRemoteControlRequest(unsigned int userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, DeclineRemoteControlRequest, SDKError, unsigned int, userId, SDKERR_UNINITIALIZE)
//virtual SDKError RevokeRemoteControl() = 0;
IMPL_FUNC_0(IMeetingRemoteController, RevokeRemoteControl, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError GetCurrentRemoteController(unsigned int& userId) = 0;
IMPL_FUNC_1(IMeetingRemoteController, GetCurrentRemoteController, SDKError, unsigned int&, userId, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE