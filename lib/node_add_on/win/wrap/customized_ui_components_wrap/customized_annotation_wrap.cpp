#include "customized_annotation_wrap.h"
#include "../meeting_service_components_wrap/meeting_annotation_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ICustomizedAnnotationController* InitICustomizedAnnotationControllerFunc(ICustomizedAnnotationControllerEvent* pEvent, IAnnotationControllerWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationController* pObj = pOwner->GetSDKObj()->GetCustomizedAnnotationController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingParticipantsControllerFunc(ICustomizedAnnotationController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError CreateAnnoObj(ICustomizedShareRender* view_share_render, ICustomizedAnnotationObj** pp_obj) = 0;
IMPL_FUNC_2(ICustomizedAnnotationController, CreateAnnoObj, SDKError, ICustomizedShareRender*, view_share_render, ICustomizedAnnotationObj**, pp_obj, SDKERR_UNINITIALIZE)
//virtual SDKError DestroyAnnoObj(ICustomizedAnnotationObj* anno_obj) = 0;
IMPL_FUNC_1(ICustomizedAnnotationController, DestroyAnnoObj, SDKError, ICustomizedAnnotationObj*, anno_obj, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE