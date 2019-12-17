
#include "../zoom_sdk_sms_helper_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_realname_auth_helper_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZSDKSMSHelperWrap::ZSDKSMSHelperWrap()
{
	SDKEventWrapMgr::GetInst().m_zoomRealNameAuthMeetingWrapEvent.SetOwner(this);
	m_pSink = NULL;
}
ZSDKSMSHelperWrap::~ZSDKSMSHelperWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_zoomRealNameAuthMeetingWrapEvent.SetOwner(NULL);
}
void ZSDKSMSHelperWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().SetEvent(&SDKEventWrapMgr::GetInst().m_zoomRealNameAuthMeetingWrapEvent);
}
void ZSDKSMSHelperWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().Uninit_Wrap();
}
void ZSDKSMSHelperWrap::SetSink(ZNativeSDKSMSHelperWrapSink* pSink)
{
	m_pSink = pSink;
}
bool ZSDKSMSHelperWrap::EnableZoomAuthRealNameMeetingUIShown(bool enable)
{
	bool b_ret = false;
	b_ret = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().EnableZoomAuthRealNameMeetingUIShown(enable);
	return b_ret;
}
bool ZSDKSMSHelperWrap::SetDefaultCellPhoneInfo(ZoomSTRING country_code, ZoomSTRING phone_number)
{
	bool b_ret = false;
	b_ret = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().SetDefaultCellPhoneInfo((const zTCHAR*)country_code.c_str(), (const zTCHAR*)phone_number.c_str());
	return b_ret;
}
bool ZSDKSMSHelperWrap::Retrieve(ZoomSTRING country_code, ZoomSTRING phone_number)
{
	bool b_ret = false;
	b_ret = ZoomRetrieveSMSVerificationCodeHandler::GetInst().Retrieve((const zTCHAR*)(country_code.c_str()), (const zTCHAR*)(phone_number.c_str()));
	return b_ret;
}
bool ZSDKSMSHelperWrap::Retrieve_CancelAndLeaveMeeting()
{
	bool b_ret = false;
	b_ret = ZoomRetrieveSMSVerificationCodeHandler::GetInst().CancelAndLeaveMeeting();
	return b_ret;
}
bool ZSDKSMSHelperWrap::GetResendSMSVerificationCodeHandler()
{
	bool b_ret = false;
	IZoomRetrieveSMSVerificationCodeHandler* handler = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().GetResendSMSVerificationCodeHandler();
	ZoomRetrieveSMSVerificationCodeHandler::GetInst().SetHandler(handler);
	if (handler)
	{
		b_ret = true;
	}
	return b_ret;
}
bool ZSDKSMSHelperWrap::Verify(ZoomSTRING country_code, ZoomSTRING phone_number, ZoomSTRING verification_code)
{
	bool b_ret = false;
	b_ret = ZoomVerifySMSVerificationCodeHandler::GetInst().Verify((const zTCHAR*)(country_code.c_str()), (const zTCHAR*)(phone_number.c_str()), (const zTCHAR*)(verification_code.c_str()));
	return b_ret;
}
bool ZSDKSMSHelperWrap::Verify_CancelAndLeaveMeeting()
{
	bool b_ret = false;
	b_ret = ZoomVerifySMSVerificationCodeHandler::GetInst().CancelAndLeaveMeeting();
	return b_ret;
}
bool ZSDKSMSHelperWrap::GetReVerifySMSVerificationCodeHandler()
{
	bool b_ret = false;
	IZoomVerifySMSVerificationCodeHandler* handler = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().GetReVerifySMSVerificationCodeHandler();
	ZoomVerifySMSVerificationCodeHandler::GetInst().SetHandler(handler);
	if (handler)
	{
		b_ret = true;
	}
	return b_ret;
}
ZNList<ZNZoomRealNameAuthCountryInfo> ZSDKSMSHelperWrap::GetSupportPhoneNumberCountryList()
{
	ZNList<ZNZoomRealNameAuthCountryInfo> SMSCountryInfo_list;
	IVector<IZoomRealNameAuthCountryInfo* >* lst_countryInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().GetSupportPhoneNumberCountryList();
	if (NULL == lst_countryInfo)
	{
		return SMSCountryInfo_list;
	}
	for (int i = 0; i < lst_countryInfo->GetCount(); ++i)
	{
		ZNZoomRealNameAuthCountryInfo countryInfo;
		IZoomRealNameAuthCountryInfo* temp_pCountryInfo = lst_countryInfo->GetItem(i);
		if (temp_pCountryInfo)
		{
			countryInfo.countryID = (const wchar_t*)temp_pCountryInfo->GetCountryID();
			countryInfo.countryName = (const wchar_t*)temp_pCountryInfo->GetCountryName();
			countryInfo.countryCode = (const wchar_t*)temp_pCountryInfo->GetCountryCode();
		}
		SMSCountryInfo_list.push_back(countryInfo);
	}
	return SMSCountryInfo_list;
}
void ZSDKSMSHelperWrap::onNeedRealNameAuthMeetingNotification(ZNList<ZNZoomRealNameAuthCountryInfo> support_country_list, ZoomSTRING privacy_url)
{
	if (m_pSink)
	{
		m_pSink->onNeedRealNameAuthMeetingNotification(support_country_list, privacy_url);
	}
}
void ZSDKSMSHelperWrap::onRetrieveSMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result)
{
	if (m_pSink)
	{
		m_pSink->onRetrieveSMSVerificationCodeResultNotification(result);
	}
}
void ZSDKSMSHelperWrap::onVerifySMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result)
{
	if (m_pSink)
	{
		m_pSink->onVerifySMSVerificationCodeResultNotification(result);
	}
}