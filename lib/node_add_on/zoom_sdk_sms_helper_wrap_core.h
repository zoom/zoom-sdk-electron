#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZSDKSMSHelperWrap
{
public:
	ZSDKSMSHelperWrap();
	virtual ~ZSDKSMSHelperWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKSMSHelperWrapSink* pSink);

	bool EnableZoomAuthRealNameMeetingUIShown(bool enable);
	bool SetDefaultCellPhoneInfo(ZoomSTRING country_code, ZoomSTRING phone_number);
	bool GetResendSMSVerificationCodeHandler();
	bool Retrieve(ZoomSTRING country_code, ZoomSTRING phone_number);
	bool Retrieve_CancelAndLeaveMeeting();

	bool GetReVerifySMSVerificationCodeHandler();
	bool Verify(ZoomSTRING country_code, ZoomSTRING phone_number, ZoomSTRING verification_code);
	bool Verify_CancelAndLeaveMeeting();

	ZNList<ZNZoomRealNameAuthCountryInfo> GetSupportPhoneNumberCountryList();

	////callback
	void onNeedRealNameAuthMeetingNotification(ZNList<ZNZoomRealNameAuthCountryInfo> support_country_list, ZoomSTRING privacy_url);
	void onRetrieveSMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result);
	void onVerifySMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result);
private:
	ZNativeSDKSMSHelperWrapSink* m_pSink;
	

};
