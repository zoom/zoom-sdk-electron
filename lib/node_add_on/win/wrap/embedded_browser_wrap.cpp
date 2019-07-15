#include "embedded_browser_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
void IEmbeddedBrowserWrap::Init(HWND hwnd)
{
	CSDKImpl::GetInst().CreateEmbeddedBrowser(&m_obj, hwnd);
	if (m_obj)
	{
		m_obj->SetEvent(this);
	}
}
void IEmbeddedBrowserWrap::Uninit()
{
	if (m_obj)
	{
		m_obj->SetEvent(false);
		CSDKImpl::GetInst().DestroyEmbeddedBrowser(m_obj);
		m_obj = NULL;
	}
}

IMPL_FUNC_1(IEmbeddedBrowser, Navigate, SDKError, const char*, url, SDKERR_UNINITIALIZE)
//virtual SDKError Resize() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, Resize, SDKError, SDKERR_UNINITIALIZE)
//virtual const char* GetURL() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, GetURL, const char*, NULL)
//virtual const char* GetTitle() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, GetTitle, const char*, NULL)
//virtual SDKError GoBack() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, GoBack, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError GoForward() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, GoForward, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError DoRefresh() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, DoRefresh, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError DoStop() = 0;
IMPL_FUNC_0(IEmbeddedBrowser, DoStop, SDKError, SDKERR_UNINITIALIZE)
END_ZOOM_SDK_NAMESPACE