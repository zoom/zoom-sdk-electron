#include "../auth_service_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"
class ZAuthServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IAuthServiceEvent
{
public:
	void SetOwner(ZAuthServiceWrap* obj) { owner_ = obj; }
	virtual void onAuthenticationReturn(ZOOM_SDK_NAMESPACE::AuthResult ret){
		if (owner_) {
			owner_->onAuthenticationReturn(Map2WrapDefine(ret));
		}
	}
	virtual void onLoginRet(ZOOM_SDK_NAMESPACE::LOGINSTATUS ret, ZOOM_SDK_NAMESPACE::IAccountInfo* pAccountInfo){
		if (owner_) {
			owner_->onLoginRet(Map2WrapDefine(ret));
		}
	}
	virtual void onLogout(){
		if (owner_) {
			owner_->onLogout();
		}
	}
	virtual void onZoomIdentityExpired() {
		if (owner_) {
			owner_->onZoomIdentityExpired();
		}
	}
private:
	ZAuthServiceWrap* owner_;
};

static ZAuthServiceWrapEvent g_auth_event;
ZAuthServiceWrap::ZAuthServiceWrap()
{
	g_auth_event.SetOwner(this);
	m_pSink = 0;
}
ZAuthServiceWrap::~ZAuthServiceWrap()
{
	Uninit();
	m_pSink = 0;
	g_auth_event.SetOwner(NULL);
}
void ZAuthServiceWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Init_Wrap();
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().SetEvent(&g_auth_event);
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
void ZAuthServiceWrap::SetSink(IZNativeSDKAuthWrapSink* pSink)
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
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().Login(param));
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
ZNAuthResult ZAuthServiceWrap::GetAuthResult()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetAuthResult());
}
ZNLOGINSTATUS ZAuthServiceWrap::GetLoginStatus()
{
	return  Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().GetLoginStatus());
}