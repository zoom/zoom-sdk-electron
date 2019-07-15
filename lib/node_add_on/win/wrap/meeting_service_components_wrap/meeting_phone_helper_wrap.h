#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingPhoneHelper* InitIMeetingPhoneHelperFunc(IMeetingPhoneHelperEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingPhoneHelperFunc(IMeetingPhoneHelper* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingPhoneHelper, IMeetingPhoneHelperEvent)
NORMAL_CLASS(IMeetingPhoneHelper)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingPhoneHelper, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingPhoneHelperEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual bool IsSupportPhoneFeature() = 0;
DEFINE_FUNC_0(IsSupportPhoneFeature, bool)
//virtual IList<IMeetingPhoneSupportCountryInfo* >* GetSupportCountryInfo() = 0;
DEFINE_FUNC_0(GetSupportCountryInfo, IList<IMeetingPhoneSupportCountryInfo* >*)
//virtual SDKError InviteCallOutUser(const wchar_t* countryCode, const wchar_t* phoneNumber, const wchar_t* name) = 0;
DEFINE_FUNC_3(InviteCallOutUser, SDKError, const wchar_t*, countryCode, const wchar_t*, phoneNumber, const wchar_t*, name)
//virtual SDKError CancelCallOut() = 0;
DEFINE_FUNC_0(CancelCallOut, SDKError)
//virtual PhoneStatus GetInviteCalloutUserStatus() = 0;
DEFINE_FUNC_0(GetInviteCalloutUserStatus, PhoneStatus)
//virtual SDKError CallMe(const wchar_t* countryCode, const wchar_t* phoneNumber) = 0;
DEFINE_FUNC_2(CallMe, SDKError, const wchar_t*, countryCode, const wchar_t*, phoneNumber)
//virtual SDKError Hangup() = 0;
DEFINE_FUNC_0(Hangup, SDKError)
//virtual PhoneStatus GetCallMeStatus() = 0;
DEFINE_FUNC_0(GetCallMeStatus, PhoneStatus)
//virtual IList<IMeetingCallInPhoneNumberInfo*>* GetCurrentMeetingCallinNumber() = 0;
DEFINE_FUNC_0(GetCurrentMeetingCallinNumber, IList<IMeetingCallInPhoneNumberInfo*>*)
//virtual unsigned int GetCurrentMeetingCallinParticipantID() = 0;
DEFINE_FUNC_0(GetCurrentMeetingCallinParticipantID, unsigned int)

//virtual void onInviteCallOutUserStatus(PhoneStatus status, PhoneFailedReason reason) = 0;
CallBack_FUNC_2(onInviteCallOutUserStatus, PhoneStatus, status, PhoneFailedReason, reason)
//virtual void onCallMeStatus(PhoneStatus status, PhoneFailedReason reason) = 0;
CallBack_FUNC_2(onCallMeStatus, PhoneStatus, status, PhoneFailedReason, reason)
END_CLASS_DEFINE(IMeetingPhoneHelper)
END_ZOOM_SDK_NAMESPACE