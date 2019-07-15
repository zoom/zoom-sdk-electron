#include "../sdk_wrap.h"
#include "customized_video_container_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE

ICustomizedVideoContainerWrap::~ICustomizedVideoContainerWrap()
{
	UnInit();
}

// This wrapper doesn't follow the standard pattern. It's expected to be created by the customized UI manager.
// So the manager will create the ICustomizedVideoContainer interface and call this method to set the underlying SDK object
void ICustomizedVideoContainerWrap::Init(ICustomizedVideoContainer* pObj)
{
	if (pObj)
	{
		if (m_obj) 
		{
			UnInit();
		}

		m_obj = pObj;
		if (m_obj)
		{
			m_obj->SetEvent(this);
		}
	}
}

void ICustomizedVideoContainerWrap::UnInit()
{
	if (m_obj)
	{
		m_obj->SetEvent(NULL);
		m_obj = NULL;
	}
}

IMPL_FUNC_1(ICustomizedVideoContainer, SetEvent, SDKError, ICustomizedVideoContainerEvent*, pEvent, SDKERR_UNINITIALIZE)
IMPL_FUNC_2(ICustomizedVideoContainer, CreateVideoElement, SDKError, IVideoRenderElement**, ppElement, VideoRenderElementType, type_, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(ICustomizedVideoContainer, DestroyVideoElement, SDKError, IVideoRenderElement*, ppElement, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(ICustomizedVideoContainer, DestroyAllVideoElement, SDKError, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(ICustomizedVideoContainer, Show, SDKError, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(ICustomizedVideoContainer, Hide, SDKError, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(ICustomizedVideoContainer, Resize, SDKError, RECT, rc, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(ICustomizedVideoContainer, GetVideoElementList, IList<IVideoRenderElement* >*, NULL);

END_ZOOM_SDK_NAMESPACE