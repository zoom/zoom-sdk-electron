#include "../auth_service_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
#include "../zoom_native_sdk_wrap_core.h"

ZOOM_SDK_NAMESPACE::IAuthServiceWrap& g_auth_service_wrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap();

ZAuthServiceWrap::ZAuthServiceWrap()
{
	SDKEventWrapMgr::GetInst().m_authServiceWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZAuthServiceWrap::~ZAuthServiceWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_authServiceWrapEvent.SetOwner(NULL);
}
void ZAuthServiceWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Init_Wrap();
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SetEvent(&SDKEventWrapMgr::GetInst().m_authServiceWrapEvent);
}
void ZAuthServiceWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Uninit_Wrap();
}
ZNSDKError ZAuthServiceWrap::AuthSDK(ZNAuthParam& authParam)
{
	ZOOM_SDK_NAMESPACE::AuthParam param;
	param.appKey = authParam.sdk_key.c_str();
	param.appSecret = authParam.sdk_secret.c_str();
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SDKAuth(param));
	return err;
}
ZNSDKError ZAuthServiceWrap::AuthSDK(ZNAuthContext& authContext)
{
	ZOOM_SDK_NAMESPACE::AuthContext context;
	if (!authContext.sdk_jwt_token.empty())
	{
		context.jwt_token = authContext.sdk_jwt_token.c_str();
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SDKAuth(context));
	}
	return ZNSDKERR_INVALID_PARAMETER;
}
void ZAuthServiceWrap::SetSink(ZNativeSDKAuthWrapSink* pSink)
{
	m_pSink = pSink;
}
void ZAuthServiceWrap::onAuthenticationReturn(ZNAuthResult authResult)
{
	if (m_pSink){
		m_pSink->onAuthenticationReturn(authResult);
	}
}
ZNSDKError ZAuthServiceWrap::Login(ZNLoginParam& loginParam)
{
	ZOOM_SDK_NAMESPACE::LoginParam param;
	param.loginType = ZOOM_SDK_NAMESPACE::LoginType_Email;
	param.ut.emailLogin.userName = loginParam.user_name.c_str();
	param.ut.emailLogin.password = loginParam.psw.c_str();
	param.ut.emailLogin.bRememberMe = loginParam.remember_me;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Login(param));
	return err;
}
void ZAuthServiceWrap::onLoginRet(ZNLOGINSTATUS ret)
{
	if (m_pSink)
	{
		m_pSink->onLoginRet(ret);
	}
}
ZNSDKError ZAuthServiceWrap::LoginWithSSOToken(ZNLoginParam& loginParam)
{
	ZOOM_SDK_NAMESPACE::LoginParam param;
	param.loginType = ZOOM_SDK_NAMESPACE::LoginType_SSO;
	param.ut.ssoLogin.ssoToken = loginParam.ssotoken.c_str();
	param.ut.ssoLogin.bRememberMe = loginParam.remember_me;
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Login(param));
}
ZNSDKError ZAuthServiceWrap::Logout()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().LogOut());
}
void ZAuthServiceWrap::onLogout()
{
	if (m_pSink)
	{
		m_pSink->onLogout();
	}
}
void ZAuthServiceWrap::onZoomIdentityExpired()
{
	if (m_pSink)
	{
		m_pSink->onZoomIdentityExpired();
	}
}
void ZAuthServiceWrap::onZoomAuthIdentityExpired()
{
	if (m_pSink)
	{
		m_pSink->onZoomAuthIdentityExpired();
	}
}
ZNAuthResult ZAuthServiceWrap::GetAuthResult()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetAuthResult());
}
ZNLOGINSTATUS ZAuthServiceWrap::GetLoginStatus()
{
	return  Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetLoginStatus());
}
ZDirectShareHelperWrap& ZAuthServiceWrap::GetDirectShareHelper()
{
	return m_direct_share_helper;
}