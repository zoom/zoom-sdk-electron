#include "directshare_helper_wrap.h"
#include "auth_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IDirectShareServiceHelper* InitIDirectShareServiceHelperFunc(IDirectShareServiceHelperEvent* pEvent, IAuthServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IDirectShareServiceHelper* pObj = pOwner->GetSDKObj()->GetDirectShareServiceHeler();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIDirectShareServiceHelperFunc(IDirectShareServiceHelper* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError CanStartDirectShare() = 0;
IMPL_FUNC_0(IDirectShareServiceHelper, CanStartDirectShare, SDKError, SDKERR_UNINITIALIZE)
//virtual bool	 IsDirectShareInProgress() = 0;
IMPL_FUNC_0(IDirectShareServiceHelper, IsDirectShareInProgress, bool, false)
//virtual SDKError StartDirectShare() = 0;
IMPL_FUNC_0(IDirectShareServiceHelper, StartDirectShare, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StopDirectShare() = 0;
IMPL_FUNC_0(IDirectShareServiceHelper, StopDirectShare, SDKError, SDKERR_UNINITIALIZE)


END_ZOOM_SDK_NAMESPACE