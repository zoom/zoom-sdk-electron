

#include "../auth_service_wrap_core.h"
#include "Header_include.h"
#import "authServiceDelegate.h"
#import "sdk_native_error.h"
static nativeErrorTypeHelp error;
ZAuthServiceWrap::ZAuthServiceWrap()
{
    m_pSink = 0;
}

ZAuthServiceWrap::~ZAuthServiceWrap()
{
    m_pSink = 0;
    [[[ZoomSDK sharedSDK] getAuthService] setDelegate:nil];
}

void ZAuthServiceWrap::Init()
{
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK] getAuthService];
    if (auth) {
        [auth setDelegate:[authServiceDelegate share]];
    }
}

void ZAuthServiceWrap::Uninit()
{

}

void ZAuthServiceWrap::SetSink(ZNativeSDKAuthWrapSink *pSink)
{
    m_pSink = pSink;
}

ZNSDKError  ZAuthServiceWrap::AuthSDK(ZNAuthParam &authParam)
{
    NSString *key = [NSString stringWithCString:authParam.sdk_key.c_str() encoding:NSUTF8StringEncoding];
    NSString  *sercret = [NSString stringWithCString:authParam.sdk_secret.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK] getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth sdkAuth:key appSecret:sercret];
    nativeErrorTypeHelp error;
    return error.ZoomSDKErrorType(ret);
}

ZNSDKError ZAuthServiceWrap::AuthSDK(ZNAuthContext& authContext)
{
    NSString *jwtToken = [NSString stringWithCString:authContext.sdk_jwt_token.c_str() encoding:NSUTF8StringEncoding];
    if (!jwtToken || jwtToken.length == 0) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK] getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKAuthContext *context = [[ZoomSDKAuthContext alloc] init];
    context.jwtToken = jwtToken;
    ZoomSDKError ret = [auth sdkAuth:context];
    nativeErrorTypeHelp error;
    return error.ZoomSDKErrorType(ret);
}

ZNSDKError ZAuthServiceWrap::Login(ZNLoginParam &loginParam)
{
    NSString *userName = [NSString stringWithCString:loginParam.user_name.c_str() encoding:NSUTF8StringEncoding];
    NSString *pwd = [NSString stringWithCString:loginParam.psw.c_str() encoding:NSUTF8StringEncoding];
    bool isRem = loginParam.remember_me;
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK] getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth login:userName Password:pwd RememberMe:isRem];
    nativeErrorTypeHelp error;
    return error.ZoomSDKErrorType(ret);
}

ZNSDKError ZAuthServiceWrap::LoginWithSSOToken(ZNLoginParam &loginParam)
{
    NSString *sso = [NSString stringWithCString:loginParam.ssotoken.c_str() encoding:NSUTF8StringEncoding];
    bool isrem = loginParam.remember_me;
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK] getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth loginSSO:sso RememberMe:isrem];
    nativeErrorTypeHelp error;
    return error.ZoomSDKErrorType(ret);
}

ZNSDKError ZAuthServiceWrap::Logout()
{
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK] getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth logout];
    nativeErrorTypeHelp error;
    return error.ZoomSDKErrorType(ret);
}

ZNAuthResult ZAuthServiceWrap::GetAuthResult()
{
    return  [[authServiceDelegate share] getAuthResult];
}

ZNLOGINSTATUS ZAuthServiceWrap::GetLoginStatus()
{
    return [[authServiceDelegate share] getLoginStatus];
}

//callback
void ZAuthServiceWrap::onAuthenticationReturn(ZNAuthResult authResult)
{
    if (m_pSink) {
        m_pSink->onAuthenticationReturn(authResult);
    }
}

void ZAuthServiceWrap::onLoginRet(ZNLOGINSTATUS ret)
{
    if (m_pSink) {
        m_pSink->onLoginRet(ret);
    }
}

void ZAuthServiceWrap::onLogout()
{
    if (m_pSink) {
        m_pSink->onLogout();
    }
}


void ZAuthServiceWrap::onZoomIdentityExpired()
{
    if (m_pSink) {
        m_pSink->onZoomIdentityExpired();
    }
}

void ZAuthServiceWrap::onZoomAuthIdentityExpired()
{
    if (m_pSink) {
        m_pSink->onZoomAuthIdentityExpired();
    }
}


