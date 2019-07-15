#include "meeting_phone_helper_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingPhoneHelper* InitIMeetingPhoneHelperFunc(IMeetingPhoneHelperEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingPhoneHelper* pObj = pOwner->GetSDKObj()->GetMeetingPhoneHelper();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingPhoneHelperFunc(IMeetingPhoneHelper* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual bool IsSupportPhoneFeature() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, IsSupportPhoneFeature, bool, false)
//virtual IList<IMeetingPhoneSupportCountryInfo* >* GetSupportCountryInfo() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, GetSupportCountryInfo, IList<IMeetingPhoneSupportCountryInfo* >*, NULL)
//virtual SDKError InviteCallOutUser(const wchar_t* countryCode, const wchar_t* phoneNumber, const wchar_t* name) = 0;
IMPL_FUNC_3(IMeetingPhoneHelper, InviteCallOutUser, SDKError, const wchar_t*, countryCode, const wchar_t*, phoneNumber, const wchar_t*, name, SDKERR_UNINITIALIZE)
//virtual SDKError CancelCallOut() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, CancelCallOut, SDKError, SDKERR_UNINITIALIZE)
//virtual PhoneStatus GetInviteCalloutUserStatus() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, GetInviteCalloutUserStatus, PhoneStatus, PhoneStatus_None)
//virtual SDKError CallMe(const wchar_t* countryCode, const wchar_t* phoneNumber) = 0;
IMPL_FUNC_2(IMeetingPhoneHelper, CallMe, SDKError, const wchar_t*, countryCode, const wchar_t*, phoneNumber, SDKERR_UNINITIALIZE)
//virtual SDKError Hangup() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, Hangup, SDKError, SDKERR_UNINITIALIZE)
//virtual PhoneStatus GetCallMeStatus() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, GetCallMeStatus, PhoneStatus, PhoneStatus_None)
//virtual IList<IMeetingCallInPhoneNumberInfo*>* GetCurrentMeetingCallinNumber() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, GetCurrentMeetingCallinNumber, IList<IMeetingCallInPhoneNumberInfo*>*, NULL)
//virtual unsigned int GetCurrentMeetingCallinParticipantID() = 0;
IMPL_FUNC_0(IMeetingPhoneHelper, GetCurrentMeetingCallinParticipantID, unsigned int, 0)

END_ZOOM_SDK_NAMESPACE