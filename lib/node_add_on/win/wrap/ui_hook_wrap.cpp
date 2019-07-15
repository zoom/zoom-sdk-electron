#include "ui_hook_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IUIHooker* InitIUIHookerFunc(ZOOM_SDK_NAMESPACE::IUIHookerEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::IUIHooker* pObj(NULL);
	CSDKImpl::GetInst().RetrieveUIHooker(&pObj);
	if (pObj)
	{
		pObj->SetEvent(pEvent);
	}
	return pObj;
}
void UninitIUIHookerFunc(ZOOM_SDK_NAMESPACE::IUIHooker* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
		obj->Stop();
	}
}

//virtual SDKError MonitorWndMessage(unsigned int wndmsgid, bool bAdd = true) = 0;
IMPL_FUNC_2(IUIHooker, MonitorWndMessage, SDKError, unsigned int, wndmsgid, bool, bAdd, SDKERR_UNINITIALIZE)
//virtual SDKError MonitorWnd(const wchar_t* classname, bool bAdd = true) = 0;
IMPL_FUNC_2(IUIHooker, MonitorWnd, SDKError, const wchar_t*, classname, bool, bAdd, SDKERR_UNINITIALIZE)
//virtual SDKError Start() = 0;
IMPL_FUNC_0(IUIHooker, Start, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError Stop() = 0;
IMPL_FUNC_0(IUIHooker, Stop, SDKError, SDKERR_UNINITIALIZE)
END_ZOOM_SDK_NAMESPACE