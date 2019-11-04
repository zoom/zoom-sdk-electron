
#include "../zoom_native_sdk_wrap_core.h"
#include "../auth_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
ZNSDKError ZNativeSDKWrap::InitSDK(ZNInitParam &initParam)
{
    //set language
    nativeErrorTypeHelp help;
    NSString *lanStr = help.ZNSDKLanaguageChanage(initParam.langid);
    NSArray *language = [[ZoomSDK sharedSDK] getLanguageArray];
    if (language != nil && [language  containsObject:lanStr])
    {
        [[ZoomSDK sharedSDK] setPreferLanguage:lanStr];
    }
    [[ZoomSDK sharedSDK] enableDefaultLog:initParam.enable_log fileSize:5];
    ZoomSDKLocale local = help.ZNSDKAPPLocalType(initParam.locale);
    [[ZoomSDK sharedSDK] setAppLocale:local];
    [[ZoomSDK sharedSDK] initSDK:NO];
    NSString *domain = [NSString stringWithCString:initParam.domain.c_str() encoding:NSUTF8StringEncoding];  
    if (!domain)
    {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    [[ZoomSDK sharedSDK] setZoomDomain:domain];
    _z_auth_service_wrap.Init();
    _z_meeting_service_wrap.Init();
    _z_setting_service_wrap.Init();
    _z_premeeting_service_wrap.Init();
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZNativeSDKWrap::CleanUPSDK()
{
    return ZNSDKERR_SUCCESS;
}

ZoomSTRING ZNativeSDKWrap::GetVersion()
{
    NSString *versionNum = [[ZoomSDK sharedSDK] getSDKVersionNumber];
    if (!versionNum) {
        return "";
    }
    return versionNum.UTF8String;
}

ZAuthServiceWrap &ZNativeSDKWrap::GetAuthServiceWrap()
{
    return _z_auth_service_wrap;
}

ZMeetingServiceWrap &ZNativeSDKWrap::GetMeetingServiceWrap()
{
    return _z_meeting_service_wrap;
}


ZSettingServiceWrap &ZNativeSDKWrap::GetSettingServiceWrap()
{
    return _z_setting_service_wrap;
}

ZCustomizedResourceWrap &ZNativeSDKWrap::GetCustomizedResourceWrap()
{
    return _z_customized_resource_wrap;
}

ZPremeetingServiceWrap &ZNativeSDKWrap::GetPremeetingServiecWrap()
{
    return _z_premeeting_service_wrap;
}

ZDirectShareHelperWrap &ZAuthServiceWrap::GetDirectShareHelper()
{
    return m_direct_share_helper;
}

ZNativeSDKWrap::ZNativeSDKWrap()
{
    
}

ZNativeSDKWrap::~ZNativeSDKWrap()
{
    _z_auth_service_wrap.Uninit();
    _z_meeting_service_wrap.Uninit();
    _z_premeeting_service_wrap.Uninit();
    _z_setting_service_wrap.Uninit();
}

