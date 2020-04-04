#include "customized_annotation_wrap.h"
#include "../meeting_service_components_wrap/meeting_annotation_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ICustomizedAnnotationControllerWrap::~ICustomizedAnnotationControllerWrap()
{
	UnInit();
}
void ICustomizedAnnotationControllerWrap::Init(ICustomizedAnnotationController* pObj)
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

void ICustomizedAnnotationControllerWrap::UnInit()
{
	if (m_obj)
	{
		m_obj->SetEvent(NULL);
		m_obj = NULL;
	}
}

//virtual SDKError CreateAnnoObj(ICustomizedShareRender* view_share_render, ICustomizedAnnotationObj** pp_obj) = 0;
IMPL_FUNC_2(ICustomizedAnnotationController, CreateAnnoObj, SDKError, ICustomizedShareRender*, view_share_render, ICustomizedAnnotationObj**, pp_obj, SDKERR_UNINITIALIZE)
//virtual SDKError DestroyAnnoObj(ICustomizedAnnotationObj* anno_obj) = 0;
IMPL_FUNC_1(ICustomizedAnnotationController, DestroyAnnoObj, SDKError, ICustomizedAnnotationObj*, anno_obj, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE