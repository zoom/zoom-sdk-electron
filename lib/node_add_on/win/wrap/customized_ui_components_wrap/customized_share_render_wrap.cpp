#include "../sdk_wrap.h"
#include "customized_share_render_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE

ICustomizedShareRenderWrap::~ICustomizedShareRenderWrap()
{
	UnInit();
}

// This wrapper doesn't follow the standard pattern. It's expected to be created by the customized UI manager.
// So the manager will create the ICustomizedShareRender interface and call this method to set the underlying SDK object
void ICustomizedShareRenderWrap::Init(ICustomizedShareRender* pObj)
{
	if (m_obj)
	{
		UnInit();
	}
	
	m_obj = pObj;
	if( m_obj )
	{
		m_obj->SetEvent(this);
	}
}

void ICustomizedShareRenderWrap::UnInit()
{
	if (m_obj)
	{
		m_obj->SetEvent(NULL);
		m_obj = NULL;
	}
}

IMPL_FUNC_1(ICustomizedShareRender, SetEvent, SDKError, ICustomizedShareRenderEvent*, pEvent, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedShareRender, Show, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedShareRender, Hide, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedShareRender, SetUserID, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedShareRender, GetUserID, unsigned int, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedShareRender, Resize, SDKError, RECT, rc, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedShareRender, SetViewMode, SDKError, CustomizedViewShareMode, mode, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedShareRender, GetOwnerWnd, HWND, NULL)
IMPL_FUNC_0(ICustomizedShareRender, HandleWindowsMoveMsg, SDKError, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE