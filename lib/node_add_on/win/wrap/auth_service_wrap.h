#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IAuthService* InitIAuthServiceFunc(ZOOM_SDK_NAMESPACE::IAuthServiceEvent* pEvent);
void UninitIAuthServiceFunc(ZOOM_SDK_NAMESPACE::IAuthService* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IAuthService, IAuthServiceEvent)
STAITC_CLASS(IAuthService)
INIT_UNINIT_WITHEVENT(IAuthService)
//virtual SDKError SetEvent(IAuthServiceEvent* pEvent) = 0;
//DEFINE_FUNC_1(SetEvent, SDKError, IAuthServiceEvent*, pEvent)
virtual SDKError SetEvent(IAuthServiceEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError SDKAuth(AuthParam& authParam) = 0;
DEFINE_FUNC_1(SDKAuth, SDKError, AuthParam&, authParam)

//virtual AuthResult GetAuthResult() = 0;
DEFINE_FUNC_0(GetAuthResult, AuthResult)

//virtual const wchar_t* GetSDKIdentity() = 0;
DEFINE_FUNC_0(GetSDKIdentity, const wchar_t*)

//virtual SDKError Login(LoginParam& param) = 0;
DEFINE_FUNC_1(Login, SDKError, LoginParam&, param)

//virtual SDKError LogOut() = 0;
DEFINE_FUNC_0(LogOut, SDKError)

//virtual IAccountInfo* GetAccountInfo() = 0;
DEFINE_FUNC_0(GetAccountInfo, IAccountInfo*)

//virtual LOGINSTATUS GetLoginStatus() = 0;
DEFINE_FUNC_0(GetLoginStatus, LOGINSTATUS)
//virtual IOutlookPluginIntegrationHelper* GetOutlookPluginHeler() = 0;
DEFINE_FUNC_0(GetOutlookPluginHeler, IOutlookPluginIntegrationHelper*)
//virtual IDirectShareServiceHelper* GetDirectShareServiceHeler() = 0;
DEFINE_FUNC_0(GetDirectShareServiceHeler, IDirectShareServiceHelper*)

//virtual void onAuthenticationReturn(AuthResult ret)
CallBack_FUNC_1(onAuthenticationReturn, AuthResult,ret)
//virtual void onLoginRet(LOGINSTATUS ret, IAccountInfo* pAccountInfo) = 0;
CallBack_FUNC_2(onLoginRet, LOGINSTATUS, ret, IAccountInfo*,pAccountInfo)
//virtual void onLogout() = 0;
CallBack_FUNC_0(onLogout)
//virtual void onZoomIdentityExpired() = 0;
CallBack_FUNC_0(onZoomIdentityExpired)

END_CLASS_DEFINE(IAuthService)
END_ZOOM_SDK_NAMESPACE