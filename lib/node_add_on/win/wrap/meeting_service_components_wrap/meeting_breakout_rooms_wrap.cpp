#include "meeting_breakout_rooms_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingBreakoutRoomsController* InitIMeetingBreakoutRoomsControllerFunc(IMeetingBreakoutRoomsEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingBreakoutRoomsController* pObj = pOwner->GetSDKObj()->GetMeetingBreakoutRoomsController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingBreakoutRoomsControllerFunc(IMeetingBreakoutRoomsController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError JoinBreakoutRoom(const wchar_t* stBID) = 0;
IMPL_FUNC_1(IMeetingBreakoutRoomsController, JoinBreakoutRoom, SDKError, const wchar_t*, stBID, SDKERR_UNINITIALIZE)
//virtual SDKError LeaveBreakoutRoom() = 0;
IMPL_FUNC_0(IMeetingBreakoutRoomsController, LeaveBreakoutRoom, SDKError, SDKERR_UNINITIALIZE)
//virtual IList<IBreakoutRoomsInfo* >* GetBreakoutRoomsInfoList() = 0;
IMPL_FUNC_0(IMeetingBreakoutRoomsController, GetBreakoutRoomsInfoList, IList<IBreakoutRoomsInfo* >*, NULL)

END_ZOOM_SDK_NAMESPACE