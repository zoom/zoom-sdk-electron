

#include "../auth_service_wrap_core.h"
#include "Header_include.h"
#import "authServiceDelegate.h"
static nativeErrorTypeHelp error;
ZAuthServiceWrap::ZAuthServiceWrap(){
  

}

ZAuthServiceWrap::~ZAuthServiceWrap(){

    [[[ZoomSDK sharedSDK]getAuthService]setDelegate:NULL];
   
}

void ZAuthServiceWrap::Init(){

    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK]getAuthService];
    if (auth) {
        
        [auth setDelegate:[authServiceDelegate share]];
    }
    
}

void ZAuthServiceWrap::Uninit(){
    [[[ZoomSDK sharedSDK]getAuthService]setDelegate:nil];
}

void ZAuthServiceWrap::SetSink(IZNativeSDKAuthWrapSink *pSink){
    

    m_pSink = pSink;
}

ZNSDKError  ZAuthServiceWrap::AuthSDK(ZNAuthParam &authParam){
    
    NSString *key = [NSString stringWithCString:authParam.sdk_key.c_str() encoding:NSUTF8StringEncoding];
    NSString  *sercret = [NSString stringWithCString:authParam.sdk_secret.c_str() encoding:NSUTF8StringEncoding];
    
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK]getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth sdkAuth:key appSecret:sercret];
    
    return error.ZoomSDKErrorType(ret);
}

ZNSDKError ZAuthServiceWrap::Login(ZNLoginParam &loginParam){
    
    NSString *userName = [NSString stringWithCString:loginParam.user_name.c_str() encoding:NSUTF8StringEncoding];
    NSString *pwd = [NSString stringWithCString:loginParam.psw.c_str() encoding:NSUTF8StringEncoding];
    bool isRem = loginParam.remember_me;
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK]getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth login:userName Password:pwd RememberMe:isRem];
    return error.ZoomSDKErrorType(ret);
    
}

ZNSDKError ZAuthServiceWrap::LoginWithSSOToken(ZNLoginParam &loginParam){
    
    NSString *sso = [NSString stringWithCString:loginParam.ssotoken.c_str() encoding:NSUTF8StringEncoding];
    bool isrem = loginParam.remember_me;
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK]getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth loginSSO:sso RememberMe:isrem];
    return error.ZoomSDKErrorType(ret);
}

ZNSDKError ZAuthServiceWrap::Logout(){
    
    ZoomSDKAuthService *auth = [[ZoomSDK sharedSDK]getAuthService];
    if (!auth) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [auth logout];
    return error.ZoomSDKErrorType(ret);
}

ZNAuthResult ZAuthServiceWrap::GetAuthResult(){
    
    return  [[authServiceDelegate share]getAuthResult];
}
ZNLOGINSTATUS ZAuthServiceWrap::GetLoginStatus(){
    
    return [[authServiceDelegate share]getLoginStatus];
}


//callback
void ZAuthServiceWrap::onAuthenticationReturn(ZNAuthResult authResult){
    
    if (m_pSink) {
        m_pSink->onAuthenticationReturn(authResult);
    }
}

void ZAuthServiceWrap::onLoginRet(ZNLOGINSTATUS ret){
    
    if (m_pSink) {
        m_pSink->onLoginRet(ret);
    }
}

void ZAuthServiceWrap::onLogout(){
    
    if (m_pSink) {
        m_pSink->onLogout();
    }
}


void ZAuthServiceWrap::onZoomIdentityExpired(){
    
    if (m_pSink) {
        m_pSink->onZoomIdentityExpired()
        ;
    }
}




