#pragma once
#include "../common_include.h"

BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* InitICustomizedUIMgrFunc(ZOOM_SDK_NAMESPACE::ICustomizedUIMgrEvent* pEvent);
void UninitICustomizedUIMgrFunc(ZOOM_SDK_NAMESPACE::ICustomizedUIMgr* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(ICustomizedUIMgr, ICustomizedUIMgrEvent)
STAITC_CLASS(ICustomizedUIMgr)
INIT_UNINIT_WITHEVENT(ICustomizedUIMgr)

//virtual SDKError HasLicense() = 0;
DEFINE_FUNC_0(HasLicense, SDKError)
//virtual SDKError SetEvent(ICustomizedUIMgrEvent* pEvent) = 0;
DEFINE_FUNC_1(SetEvent, SDKError, ICustomizedUIMgrEvent*, pEvent)
//virtual SDKError CreateVideoContainer(ICustomizedVideoContainer** ppContainer, HWND hParentWnd, RECT rc) = 0;
DEFINE_FUNC_3(CreateVideoContainer, SDKError, ICustomizedVideoContainer**, ppContainer, HWND, hParentWnd, RECT, rc)
//virtual SDKError DestroyVideoContainer(ICustomizedVideoContainer* pContainer) = 0;
DEFINE_FUNC_1(DestroyVideoContainer, SDKError, ICustomizedVideoContainer*, pContainer)
//virtual SDKError DestroyAllVideoContainer() = 0;
DEFINE_FUNC_0(DestroyAllVideoContainer, SDKError)
//virtual SDKError CreateShareRender(ICustomizedShareRender** ppRender, HWND hParentWnd, RECT rc) = 0;
DEFINE_FUNC_3(CreateShareRender, SDKError, ICustomizedShareRender**, ppRender, HWND, hParentWnd, RECT, rc)
//virtual SDKError DestroyShareRender(ICustomizedShareRender* pRender) = 0;
DEFINE_FUNC_1(DestroyShareRender, SDKError, ICustomizedShareRender*, pRender)
//virtual SDKError DestroyAllShareRender() = 0;
DEFINE_FUNC_0(DestroyAllShareRender, SDKError)

//virtual void onVideoContainerDestroyed(ICustomizedVideoContainer* pContainer) = 0;
CallBack_FUNC_1(onVideoContainerDestroyed, ICustomizedVideoContainer*, pContainer)
//virtual void onShareRenderDestroyed(ICustomizedShareRender* pRender) = 0;
CallBack_FUNC_1(onShareRenderDestroyed, ICustomizedShareRender*, pRender)

END_CLASS_DEFINE(ICustomizedUIMgr)
END_ZOOM_SDK_NAMESPACE
