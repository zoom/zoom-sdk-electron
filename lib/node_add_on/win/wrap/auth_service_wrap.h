#pragma once
#include "common_include.h"
#include "outlook_plugin_integration_helper_wrap.h"
#include "directshare_helper_wrap.h"
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

//virtual SDKError SDKAuth(AuthContext& authContext) = 0;
DEFINE_FUNC_1(SDKAuth, SDKError, AuthContext&, authContext)

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
#if (defined UserInterfaceClass)
private:
	//virtual IOutlookPluginIntegrationHelper* GetOutlookPluginHeler() = 0;
	DEFINE_FUNC_0(GetOutlookPluginHeler, IOutlookPluginIntegrationHelper*)
	//virtual IDirectShareServiceHelper* GetDirectShareServiceHeler() = 0;
	DEFINE_FUNC_0(GetDirectShareServiceHeler, IDirectShareServiceHelper*)
public:
#define T_GetOutlookPluginHeler _GetOutlookPluginHeler
#define T_GetDirectShareServiceHeler _GetDirectShareServiceHeler
#else
#define T_GetOutlookPluginHeler GetOutlookPluginHeler
#define T_GetDirectShareServiceHeler GetDirectShareServiceHeler
#endif

//virtual IOutlookPluginIntegrationHelper* GetOutlookPluginHeler() = 0;
DEFINE_FUNC_AND_MEMBER(T_GetOutlookPluginHeler, IOutlookPluginIntegrationHelperWrap)
//virtual IDirectShareServiceHelper* GetDirectShareServiceHeler() = 0;
DEFINE_FUNC_AND_MEMBER(T_GetDirectShareServiceHeler, IDirectShareServiceHelperWrap)

//virtual void onAuthenticationReturn(AuthResult ret)
CallBack_FUNC_1(onAuthenticationReturn, AuthResult,ret)
//virtual void onLoginRet(LOGINSTATUS ret, IAccountInfo* pAccountInfo) = 0;
CallBack_FUNC_2(onLoginRet, LOGINSTATUS, ret, IAccountInfo*,pAccountInfo)
//virtual void onLogout() = 0;
CallBack_FUNC_0(onLogout)
//virtual void onZoomIdentityExpired() = 0;
CallBack_FUNC_0(onZoomIdentityExpired)
//virtual void onZoomAuthIdentityExpired() = 0;
CallBack_FUNC_0(onZoomAuthIdentityExpired)

END_CLASS_DEFINE(IAuthService)
END_ZOOM_SDK_NAMESPACE