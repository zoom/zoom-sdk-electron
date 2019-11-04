
#include "../zoom_sdk_sms_helper_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_realname_auth_helper_wrap.h"
#include "zoom_native_to_wrap.h"

class ZoomRetrieveSMSVerificationCodeHandler
{
public:
	static ZoomRetrieveSMSVerificationCodeHandler& GetInst()
	{
		static ZoomRetrieveSMSVerificationCodeHandler inst;
		return inst;
	}
	void SetHandler(IZoomRetrieveSMSVerificationCodeHandler* handler)
	{
		m_pHandler = handler;
	}
	bool Retrieve(const zTCHAR* country_code, const zTCHAR* phone_number)
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->Retrieve(country_code, phone_number);
		}
		m_pHandler = NULL;
		return b_ret;
	}
	bool CancelAndLeaveMeeting()
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->CancelAndLeaveMeeting();
		}
		m_pHandler = NULL;
		return b_ret;
	}
private:
	ZoomRetrieveSMSVerificationCodeHandler() :m_pHandler(NULL) {}
	IZoomRetrieveSMSVerificationCodeHandler* m_pHandler;
};
class ZoomVerifySMSVerificationCodeHandler
{
public:
	static ZoomVerifySMSVerificationCodeHandler& GetInst()
	{
		static ZoomVerifySMSVerificationCodeHandler inst;
		return inst;
	}
	void SetHandler(IZoomVerifySMSVerificationCodeHandler* handler)
	{
		m_pHandler = handler;
	}
	bool Verify(const zTCHAR* country_code, const zTCHAR* phone_number, const zTCHAR* verification_code)
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->Verify(country_code, phone_number, verification_code);
		}
		m_pHandler = NULL;
		return b_ret;
	}
	bool CancelAndLeaveMeeting()
	{
		bool b_ret = false;
		if (m_pHandler)
		{
			b_ret = m_pHandler->CancelAndLeaveMeeting();
		}
		m_pHandler = NULL;
		return b_ret;
	}
private:
	ZoomVerifySMSVerificationCodeHandler() :m_pHandler(NULL) {}
	IZoomVerifySMSVerificationCodeHandler* m_pHandler;
};

class ZZoomRealNameAuthMeetingWrapEvent : public IZoomRealNameAuthMeetingEvent
{
public:
	void SetOwner(ZSDKSMSHelperWrap* obj) { owner_ = obj; }
	virtual void onNeedRealNameAuthMeetingNotification(IVector<IZoomRealNameAuthCountryInfo* >* support_country_list, const zTCHAR* privacy_url, IZoomRetrieveSMSVerificationCodeHandler* handler)
	{
		if (owner_ && support_country_list && handler)
		{
			ZoomRetrieveSMSVerificationCodeHandler::GetInst().SetHandler(handler);
			ZNList<ZNZoomRealNameAuthCountryInfo> SMSCountryInfo_list;
			for (int i = 0; i < support_country_list->GetCount(); ++i)
			{
				ZNZoomRealNameAuthCountryInfo countryInfo;
				IZoomRealNameAuthCountryInfo* temp_pCountryInfo = support_country_list->GetItem(i);
				if (temp_pCountryInfo)
				{
					countryInfo.countryID = (const wchar_t*)temp_pCountryInfo->GetCountryID();
					countryInfo.countryName = (const wchar_t*)temp_pCountryInfo->GetCountryName();
					countryInfo.countryCode = (const wchar_t*)temp_pCountryInfo->GetCountryCode();
				}
				SMSCountryInfo_list.push_back(countryInfo);
			}
			ZoomSTRING zn_privacy_url;
			zn_privacy_url = (const wchar_t*)privacy_url;
			owner_->onNeedRealNameAuthMeetingNotification(SMSCountryInfo_list, zn_privacy_url);
		}
	}
	virtual void onRetrieveSMSVerificationCodeResultNotification(SMSVerificationCodeErr result, IZoomVerifySMSVerificationCodeHandler* handler)
	{
		if (owner_)
		{
			if (SMSVerificationCodeErr_Success == result)
			{
				ZoomVerifySMSVerificationCodeHandler::GetInst().SetHandler(handler);
			}
			owner_->onRetrieveSMSVerificationCodeResultNotification(Map2WrapDefine(result));
		}
	}
	virtual void onVerifySMSVerificationCodeResultNotification(SMSVerificationCodeErr result)
	{
		if (owner_)
		{
			owner_->onRetrieveSMSVerificationCodeResultNotification(Map2WrapDefine(result));
		}
	}
private:
	ZSDKSMSHelperWrap* owner_;
};

static ZZoomRealNameAuthMeetingWrapEvent g_zoom_real_name_auth_meeting_event;

ZSDKSMSHelperWrap::ZSDKSMSHelperWrap()
{
	g_zoom_real_name_auth_meeting_event.SetOwner(this);
	m_pSink = NULL;
}
ZSDKSMSHelperWrap::~ZSDKSMSHelperWrap()
{
	Uninit();
	m_pSink = NULL;
	g_zoom_real_name_auth_meeting_event.SetOwner(NULL);
}
void ZSDKSMSHelperWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRealNameAuthController().SetEvent(&g_zoom_real_name_auth_meeting_event);
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