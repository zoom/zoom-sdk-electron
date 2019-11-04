#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::INetworkConnectionHelper* InitINetworkConnectionHelperFunc(INetworkConnectionHandler* pEvent);
void UninitINetworkConnectionHelperFunc(INetworkConnectionHelper* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(INetworkConnectionHelper, INetworkConnectionHandler)
STAITC_CLASS(INetworkConnectionHelper)
INIT_UNINIT_WITHEVENT(INetworkConnectionHelper)
virtual SDKError RegisterNetworkConnectionHandler(INetworkConnectionHandler* pNetworkHandler)
{
	external_cb = pNetworkHandler;
	if (NULL == m_obj)
		InitINetworkConnectionHelperFunc(this);
	return SDKERR_SUCCESS;
}

virtual SDKError UnRegisterNetworkConnectionHandler()
{
	external_cb = NULL;
	return SDKERR_SUCCESS;
}

//virtual SDKError ConfigureProxy(ProxySettings& proxy_setting) = 0;
DEFINE_FUNC_1(ConfigureProxy, SDKError, ProxySettings&, proxy_setting)
//virtual void onProxyDetectComplete() = 0;
CallBack_FUNC_0(onProxyDetectComplete)
//virtual void onProxySettingNotification(IProxySettingHandler* handler) = 0;
CallBack_FUNC_1(onProxySettingNotification, IProxySettingHandler*, handler)
//virtual void onSSLCertVerifyNotification(ISSLCertVerificationHandler* handler) = 0;
CallBack_FUNC_1(onSSLCertVerifyNotification, ISSLCertVerificationHandler*, handler)
END_CLASS_DEFINE(INetworkConnectionHelper)
END_ZOOM_SDK_NAMESPACE