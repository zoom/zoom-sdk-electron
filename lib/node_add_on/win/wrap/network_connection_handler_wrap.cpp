#include "network_connection_handler_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::INetworkConnectionHelper* InitINetworkConnectionHelperFunc(INetworkConnectionHandler* pEvent)
{
	ZOOM_SDK_NAMESPACE::INetworkConnectionHelper* pObj(NULL);
	CSDKImpl::GetInst().CreateNetworkConnectionHelper(&pObj);
	if (pObj)
	{
		pObj->RegisterNetworkConnectionHandler(pEvent);
	}

	return pObj;
}

void UninitINetworkConnectionHelperFunc(INetworkConnectionHelper* obj)
{
	if (obj)
	{
		obj->UnRegisterNetworkConnectionHandler();
		CSDKImpl::GetInst().DestroyNetworkConnectionHelper(obj);
	}
}
//virtual SDKError ConfigureProxy(ProxySettings& proxy_setting) = 0;
IMPL_FUNC_1(INetworkConnectionHelper, ConfigureProxy, SDKError, ProxySettings&, proxy_setting, SDKERR_UNINITIALIZE)
END_ZOOM_SDK_NAMESPACE