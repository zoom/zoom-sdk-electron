#include "meeting_h323_helper_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingH323Helper* InitIMeetingH323HelperFunc(IMeetingH323HelperEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingH323Helper* pObj = pOwner->GetSDKObj()->GetH323Helper();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingH323HelperFunc(IMeetingH323Helper* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual IList<const wchar_t* >* GetH323Address() = 0;
IMPL_FUNC_0(IMeetingH323Helper, GetH323Address, IList<const wchar_t* >*, NULL)
//virtual const wchar_t* GetH323Password() = 0;
IMPL_FUNC_0(IMeetingH323Helper, GetH323Password, const wchar_t*, NULL)
//virtual SDKError SendMeetingParingCode(UINT64 meetingNum, wchar_t* paringCode) = 0;
IMPL_FUNC_2(IMeetingH323Helper, SendMeetingParingCode, SDKError, UINT64, meetingNum, wchar_t*, paringCode, SDKERR_UNINITIALIZE)
//virtual IList<IH323Device* >* GetCalloutH323DviceList() = 0;
IMPL_FUNC_0(IMeetingH323Helper, GetCalloutH323DviceList, IList<IH323Device* >*, NULL)
//virtual SDKError CallOutH323(H323Device& deviceInfo) = 0;
IMPL_FUNC_1(IMeetingH323Helper, CallOutH323, SDKError, IH323Device*, deviceInfo, SDKERR_UNINITIALIZE)
//virtual SDKError CanPairingMeeting(UINT64 meetingNum) = 0;
IMPL_FUNC_1(IMeetingH323Helper, CanPairingMeeting, SDKError, UINT64, meetingNum, SDKERR_UNINITIALIZE)
//virtual SDKError CancelCallOutH323() = 0;
IMPL_FUNC_0(IMeetingH323Helper, CancelCallOutH323, SDKError, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE