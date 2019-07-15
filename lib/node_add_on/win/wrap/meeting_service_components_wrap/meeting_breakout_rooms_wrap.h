#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingBreakoutRoomsController* InitIMeetingBreakoutRoomsControllerFunc(IMeetingBreakoutRoomsEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingBreakoutRoomsControllerFunc(IMeetingBreakoutRoomsController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingBreakoutRoomsController, IMeetingBreakoutRoomsEvent)
NORMAL_CLASS(IMeetingBreakoutRoomsController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingBreakoutRoomsController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingBreakoutRoomsEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError JoinBreakoutRoom(const wchar_t* stBID) = 0;
DEFINE_FUNC_1(JoinBreakoutRoom, SDKError, const wchar_t*, stBID)
//virtual SDKError LeaveBreakoutRoom() = 0;
DEFINE_FUNC_0(LeaveBreakoutRoom, SDKError)
//virtual IList<IBreakoutRoomsInfo* >* GetBreakoutRoomsInfoList() = 0;
DEFINE_FUNC_0(GetBreakoutRoomsInfoList, IList<IBreakoutRoomsInfo* >*)

//virtual void OnBreakoutRoomsStartedNotification(const wchar_t* stBID) = 0;
CallBack_FUNC_1(OnBreakoutRoomsStartedNotification, const wchar_t*, stBID)
END_CLASS_DEFINE(IMeetingBreakoutRoomsController)
END_ZOOM_SDK_NAMESPACE