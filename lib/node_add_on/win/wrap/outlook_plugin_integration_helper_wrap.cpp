#include "outlook_plugin_integration_helper_wrap.h"
#include "auth_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IOutlookPluginIntegrationHelper* InitIOutlookPluginIntegrationHelperFunc(IOutlookPluginIntegrationHelperEvent* pEvent, IAuthServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IOutlookPluginIntegrationHelper* pObj = pOwner->GetSDKObj()->GetOutlookPluginHeler();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIOutlookPluginIntegrationHelperFunc(IOutlookPluginIntegrationHelper* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError Start(const wchar_t* ipc_channel_name = NULL) = 0;
IMPL_FUNC_1(IOutlookPluginIntegrationHelper, Start, SDKError, const wchar_t*, ipc_channel_name, SDKERR_UNINITIALIZE)
//virtual SDKError Stop() = 0;
IMPL_FUNC_0(IOutlookPluginIntegrationHelper, Stop, SDKError, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE