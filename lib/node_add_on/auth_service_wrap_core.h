#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
class IZNativeSDKAuthWrapSink
{
public:
	virtual void onAuthenticationReturn(ZNAuthResult authResult) = 0;
	virtual void onLoginRet(ZNLOGINSTATUS ret) = 0;
	virtual void onLogout() = 0;
	virtual void onZoomIdentityExpired() = 0;
};
class ZAuthServiceWrap
{
public:
	ZAuthServiceWrap();
	virtual ~ZAuthServiceWrap();
	void Init();
	void Uninit();
	//
	void SetSink(IZNativeSDKAuthWrapSink* pSink);
	ZNSDKError AuthSDK(ZNAuthParam& authParam);
	ZNSDKError Login(ZNLoginParam& loginParam);
	ZNSDKError LoginWithSSOToken(ZNLoginParam& loginParam);
	ZNSDKError Logout();
	ZNAuthResult GetAuthResult();
	ZNLOGINSTATUS GetLoginStatus();
	void onAuthenticationReturn(ZNAuthResult authResult);
	void onLoginRet(ZNLOGINSTATUS ret);
	void onLogout();
	void onZoomIdentityExpired();

	
private:
	IZNativeSDKAuthWrapSink* m_pSink;
};
