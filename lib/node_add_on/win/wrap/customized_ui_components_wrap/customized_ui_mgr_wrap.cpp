#include "customized_ui_mgr_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* InitICustomizedUIMgrFunc(ICustomizedUIMgrEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* pObj(NULL);
	CSDKImpl::GetInst().CreateCustomizedUIMgr(&pObj);
	if (pObj)
	{
		pObj->SetEvent(pEvent);
	}
	return pObj;
}
void UninitICustomizedUIMgrFunc(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* obj)
{
	CSDKImpl::GetInst().DestroyCustomizedUIMgr(obj);
}

IMPL_FUNC_0(ICustomizedUIMgr, HasLicense, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedUIMgr, SetEvent, SDKError, ICustomizedUIMgrEvent*, pEvent, SDKERR_UNINITIALIZE)
IMPL_FUNC_3(ICustomizedUIMgr, CreateVideoContainer, SDKError, ICustomizedVideoContainer**, ppContainer, HWND, hParentWnd, RECT, rc, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedUIMgr, DestroyVideoContainer, SDKError, ICustomizedVideoContainer*, pContainer, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedUIMgr, DestroyAllVideoContainer, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_3(ICustomizedUIMgr, CreateShareRender, SDKError, ICustomizedShareRender**, ppRender, HWND, hParentWnd, RECT, rc, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedUIMgr, DestroyShareRender, SDKError, ICustomizedShareRender*, pRender, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedUIMgr, DestroyAllShareRender, SDKError, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE
