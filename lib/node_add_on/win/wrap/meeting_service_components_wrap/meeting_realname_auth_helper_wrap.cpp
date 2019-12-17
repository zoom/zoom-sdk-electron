#pragma once
#include "meeting_realname_auth_helper_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IZoomRealNameAuthMeetingHelper* InitIZoomRealNameAuthMeetingHelperFunc(IZoomRealNameAuthMeetingEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		IZoomRealNameAuthMeetingHelper* pObj = pOwner->GetSDKObj()->GetMeetingRealNameAuthController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}
	return NULL;
}

void UninitIZoomRealNameAuthMeetingHelperFunc(IZoomRealNameAuthMeetingHelper* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual bool EnableZoomAuthRealNameMeetingUIShown(bool enable) = 0;
bool IZoomRealNameAuthMeetingHelperWrap::EnableZoomAuthRealNameMeetingUIShown(bool enable)
{
	if (m_obj)
		return m_obj->EnableZoomAuthRealNameMeetingUIShown(enable);
	return false;
}

//virtual IZoomRetrieveSMSVerificationCodeHandler* GetResendSMSVerificationCodeHandler() = 0;
IZoomRetrieveSMSVerificationCodeHandler* IZoomRealNameAuthMeetingHelperWrap::GetResendSMSVerificationCodeHandler()
{
	if (m_obj)
		return m_obj->GetResendSMSVerificationCodeHandler();
	return NULL;

}

//virtual IZoomVerifySMSVerificationCodeHandler* GetReVerifySMSVerificationCodeHandler() = 0;
IZoomVerifySMSVerificationCodeHandler* IZoomRealNameAuthMeetingHelperWrap::GetReVerifySMSVerificationCodeHandler()
{
	if (m_obj)
		return m_obj->GetReVerifySMSVerificationCodeHandler();
	return NULL;

}

//virtual IVector<IZoomRealNameAuthCountryInfo* >* GetSupportPhoneNumberCountryList() = 0;
IVector<IZoomRealNameAuthCountryInfo* >* IZoomRealNameAuthMeetingHelperWrap::GetSupportPhoneNumberCountryList()
{
	if (m_obj)
		return m_obj->GetSupportPhoneNumberCountryList();
	return NULL;
}
//virtual bool SetDefaultCellPhoneInfo(const zTCHAR* country_code, const zTCHAR* phone_number) = 0;
bool IZoomRealNameAuthMeetingHelperWrap::SetDefaultCellPhoneInfo(const zTCHAR* country_code, const zTCHAR* phone_number)
{
	if (m_obj)
		return m_obj->SetDefaultCellPhoneInfo(country_code, phone_number);
	return false;
}

END_ZOOM_SDK_NAMESPACE