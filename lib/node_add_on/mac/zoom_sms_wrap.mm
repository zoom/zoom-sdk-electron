
#include "../zoom_sdk_sms_helper_wrap_core.h"
#import "Header_include.h"
#import "meetingServiceDelegate.h"
#include "../meeting_service_wrap_core.h"


ZSDKSMSHelperWrap& ZMeetingServiceWrap::GetSDKSMSHelper()
{
    return m_sdk_sms_helper;
}


ZSDKSMSHelperWrap::ZSDKSMSHelperWrap()
{
    
}

ZSDKSMSHelperWrap::~ZSDKSMSHelperWrap()
{
    
}

void ZSDKSMSHelperWrap::Init()
{
    
}

void ZSDKSMSHelperWrap::Uninit()
{
    
}

void ZSDKSMSHelperWrap::SetSink(ZNativeSDKSMSHelperWrapSink *pSink)
{
    m_pSink = pSink;
}

bool ZSDKSMSHelperWrap::EnableZoomAuthRealNameMeetingUIShown(bool enable)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return false;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return false;
    }
    ZoomSDKError ret = [controller enableZoomAuthRealNameMeetingUIShown:enable];
    if (ret == ZoomSDKError_Success) {
        return true;
    }
    return false;
}

bool ZSDKSMSHelperWrap::GetResendSMSVerificationCodeHandler()
{
    meetingServiceDelegate *service = [meetingServiceDelegate share];
    if (!service) {
        return false;
    }
    return [service getResendRetriveController];
}

bool ZSDKSMSHelperWrap::Retrieve(ZoomSTRING country_code, ZoomSTRING phone_number)
{
    ZoomSDKRetrieveSMSVerificationCodeController *controller = [[meetingServiceDelegate share] getRetriveController];
    if (!controller) {
        return false;
    }
    NSString *countryCode = [NSString stringWithCString:country_code.c_str() encoding:NSUTF8StringEncoding];
    NSString *phoneNum = [NSString stringWithCString:phone_number.c_str() encoding:NSUTF8StringEncoding];
    if (country_code.length() > 0 && phoneNum.length > 0) {
        ZoomSDKError ret = [controller retriveWithCountryCode:countryCode PhoneNum:phoneNum];
        if (ret == ZoomSDKError_Success) {
            return true;
        }
        return false;
    }
    return false;
}

bool ZSDKSMSHelperWrap::Retrieve_CancelAndLeaveMeeting()
{
    ZoomSDKRetrieveSMSVerificationCodeController *controller = [[meetingServiceDelegate share] getRetriveController];
    if (!controller) {
        return false;
    }
    ZoomSDKError ret =[controller cancelAndLeaveMeeting];
    if (ret == ZoomSDKError_Success) {
        return true;
    }
    return false;
}

bool ZSDKSMSHelperWrap::GetReVerifySMSVerificationCodeHandler()
{
    meetingServiceDelegate *service = [meetingServiceDelegate share];
    if (!service) {
        return false;
    }
    return [service getReVerifyCintroller];
}

bool ZSDKSMSHelperWrap::Verify(ZoomSTRING country_code, ZoomSTRING phone_number, ZoomSTRING verification_code)
{
    ZoomSDKVerifySMSVerificationCodeController *controller = [[meetingServiceDelegate share] getVerifyCintroller];
    if (!controller) {
        return false;
    }
    NSString *countryCode = [NSString stringWithCString:country_code.c_str() encoding:NSUTF8StringEncoding];
    NSString *phoneNum = [NSString stringWithCString:phone_number.c_str() encoding:NSUTF8StringEncoding];
    NSString *code = [NSString stringWithCString:verification_code.c_str() encoding:NSUTF8StringEncoding];
    if (country_code.length() > 0 && phoneNum.length > 0 && code.length > 0) {
        ZoomSDKError ret = [controller verifyWithCountryCode:countryCode withPhoneNumber:phoneNum withCode:code];
        if (ret == ZoomSDKError_Success) {
            return true;
        }
        return false;
    }
    return false;
}

bool ZSDKSMSHelperWrap::Verify_CancelAndLeaveMeeting()
{
    ZoomSDKVerifySMSVerificationCodeController *controller = [[meetingServiceDelegate share] getVerifyCintroller];
    if (!controller) {
        return false;
    }
    ZoomSDKError ret = [controller cancelAndLeaveMeeting];
    if (ret == ZoomSDKError_Success) {
        return true;
    }
    return false;
}

ZNList<ZNZoomRealNameAuthCountryInfo> ZSDKSMSHelperWrap::GetSupportPhoneNumberCountryList()
{
    ZNList<ZNZoomRealNameAuthCountryInfo> infoList;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return infoList;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return infoList;
    }
    NSArray *arr = [controller getSupportPhoneNumberCountryList];
    for (ZoomSDKRealNameAuthCountryInfo *info in arr) {
        ZNZoomRealNameAuthCountryInfo countryInfo;
        countryInfo.countryCode = [info getCountryCode].UTF8String;
        countryInfo.countryID = [info getCountryID].UTF8String;
        countryInfo.countryName = [info getCountryName].UTF8String;
        infoList.push_back(countryInfo);
    }
    return infoList;
}

bool ZSDKSMSHelperWrap::SetDefaultCellPhoneInfo(ZoomSTRING country_code, ZoomSTRING phone_number)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return false;
    }
    ZoomSDKRealNameAuthenticationController *controller = [service getRealNameController];
    if (!controller) {
        return false;
    }
    if (country_code.length() == 0 || phone_number.length() == 0) {
        return false;
    }
    NSString *countryCode = [NSString stringWithCString:country_code.c_str() encoding:NSUTF8StringEncoding];
    NSString *phone = [NSString stringWithCString:phone_number.c_str() encoding:NSUTF8StringEncoding];
    if (countryCode.length > 0 && phone.length > 0) {
        ZoomSDKError ret = [controller setDefaultCellPhoneInfo:countryCode phoneNumber:phone];
        return ret == ZoomSDKError_Success ? true : false;
    }
    return false;
}

void ZSDKSMSHelperWrap::onNeedRealNameAuthMeetingNotification(ZNList<ZNZoomRealNameAuthCountryInfo> support_country_list, ZoomSTRING privacy_url)
{
    if (m_pSink) {
        m_pSink -> onNeedRealNameAuthMeetingNotification(support_country_list, privacy_url);
    }
}

void ZSDKSMSHelperWrap::onRetrieveSMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result)
{
    if (m_pSink) {
        m_pSink -> onRetrieveSMSVerificationCodeResultNotification(result);
    }
}

void ZSDKSMSHelperWrap::onVerifySMSVerificationCodeResultNotification(ZNSMSVerificationCodeErr result)
{
    if (m_pSink) {
        m_pSink -> onRetrieveSMSVerificationCodeResultNotification(result);
    }
}
