#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE

BEGIN_CLASS_DEFINE_WITHCALLBACK(IEmbeddedBrowser, IEmbeddedBrowserEvent)
NORMAL_CLASS(IEmbeddedBrowser)
void Init(HWND hwnd);
void Uninit();
virtual SDKError SetEvent(IEmbeddedBrowserEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError Navigate(const char* url) = 0;
DEFINE_FUNC_1(Navigate, SDKError, const char*, url)
//virtual SDKError Resize() = 0;
DEFINE_FUNC_0(Resize, SDKError)
//virtual const char* GetURL() = 0;
DEFINE_FUNC_0(GetURL, const char*)
//virtual const char* GetTitle() = 0;
DEFINE_FUNC_0(GetTitle, const char*)
//virtual SDKError GoBack() = 0;
DEFINE_FUNC_0(GoBack, SDKError)
//virtual SDKError GoForward() = 0;
DEFINE_FUNC_0(GoForward, SDKError)
//virtual SDKError DoRefresh() = 0;
DEFINE_FUNC_0(DoRefresh, SDKError)
//virtual SDKError DoStop() = 0;
DEFINE_FUNC_0(DoStop, SDKError)

//virtual void NotifyBeforeNavigate(const char* url) = 0;
CallBack_FUNC_1(NotifyBeforeNavigate, const char*, url)
//virtual void NotifyDocumentComplete(const char* url) = 0;
CallBack_FUNC_1(NotifyDocumentComplete, const char*, url)
//virtual void NotifyNavigateError(const char* url, NavigateError err, int component_err) = 0;
CallBack_FUNC_3(NotifyNavigateError, const char*, url, NavigateError, err, int, component_err)
END_CLASS_DEFINE(IEmbeddedBrowser)
END_ZOOM_SDK_NAMESPACE