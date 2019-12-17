#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "directshare_helper_wrap_core.h"
#include "zoom_sinks_wrap_class.h"

class ZAuthServiceWrap
{
public:
	ZAuthServiceWrap();
	virtual ~ZAuthServiceWrap();
	void Init();
	void Uninit();
	//
	void SetSink(ZNativeSDKAuthWrapSink* pSink);
	ZNSDKError AuthSDK(ZNAuthParam& authParam);
	ZNSDKError AuthSDK(ZNAuthContext& authContext);
	ZNSDKError Login(ZNLoginParam& loginParam);
	ZNSDKError LoginWithSSOToken(ZNLoginParam& loginParam);
	ZNSDKError Logout();
	ZNAuthResult GetAuthResult();
	ZNLOGINSTATUS GetLoginStatus();

	ZDirectShareHelperWrap& GetDirectShareHelper();

	void onAuthenticationReturn(ZNAuthResult authResult);
	void onLoginRet(ZNLOGINSTATUS ret);
	void onLogout();
	void onZoomIdentityExpired();
	void onZoomAuthIdentityExpired();
	
private:
	ZNativeSDKAuthWrapSink* m_pSink;
	ZDirectShareHelperWrap m_direct_share_helper;
};
