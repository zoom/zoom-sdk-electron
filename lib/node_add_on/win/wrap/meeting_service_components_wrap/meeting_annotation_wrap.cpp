#include "meeting_annotation_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IAnnotationController* InitIAnnotationControllerFunc(IMeetingAnnotationSupportEvent* pEvent, ZOOM_SDK_NAMESPACE::IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IAnnotationController* pObj = pOwner->GetSDKObj()->GetAnnotationController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIAnnotationControllerFunc(ZOOM_SDK_NAMESPACE::IAnnotationController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}

}

//virtual ICustomizedAnnotationController* GetCustomizedAnnotationController(ICustomizedShareRender* pShareRender = NULL) = 0;
//IMPL_FUNC_0(IAnnotationController, GetCustomizedAnnotationController, ICustomizedAnnotationController*, NULL)

//virtual bool IsAnnoataionDisable() = 0;
IMPL_FUNC_0(IAnnotationController, IsAnnoataionDisable, bool, false)
//virtual SDKError StartAnnotation(SDKViewType viewtype, int left, int top) = 0;
IMPL_FUNC_3(IAnnotationController, StartAnnotation, SDKError, SDKViewType, viewtype, int, left, int, top, SDKERR_UNINITIALIZE)
//virtual SDKError StopAnnotation(SDKViewType viewtype) = 0;
IMPL_FUNC_1(IAnnotationController, StopAnnotation, SDKError, SDKViewType, viewtype, SDKERR_UNINITIALIZE)
//virtual SDKError SetTool(SDKViewType viewtype, AnnotationToolType type) = 0;
IMPL_FUNC_2(IAnnotationController, SetTool, SDKError, SDKViewType, viewtype, AnnotationToolType, type, SDKERR_UNINITIALIZE)
//virtual SDKError Clear(SDKViewType viewtype, AnnotationClearType type) = 0;
IMPL_FUNC_2(IAnnotationController, Clear, SDKError, SDKViewType, viewtype, AnnotationClearType, type, SDKERR_UNINITIALIZE)
//virtual SDKError SetColor(SDKViewType viewtype, unsigned long color) = 0;
IMPL_FUNC_2(IAnnotationController, SetColor, SDKError, SDKViewType, viewtype, unsigned long, color, SDKERR_UNINITIALIZE)
//virtual SDKError SetLineWidth(SDKViewType viewtype, long lineWidth) = 0;
IMPL_FUNC_2(IAnnotationController, SetLineWidth, SDKError, SDKViewType, viewtype, long, lineWidth, SDKERR_UNINITIALIZE)
//virtual SDKError Undo(SDKViewType viewtype) = 0;
IMPL_FUNC_1(IAnnotationController, Undo, SDKError, SDKViewType, viewtype, SDKERR_UNINITIALIZE)
//virtual SDKError Redo(SDKViewType viewtype) = 0;
IMPL_FUNC_1(IAnnotationController, Redo, SDKError, SDKViewType, viewtype, SDKERR_UNINITIALIZE)
//virtual SDKError DisableViewerAnnotation(SDKViewType viewtype, bool bDisable) = 0;
IMPL_FUNC_2(IAnnotationController, DisableViewerAnnotation, SDKError, SDKViewType, viewtype, bool, bDisable, SDKERR_UNINITIALIZE)
//virtual SDKError IsViewerAnnotationDisabled(SDKViewType viewtype, bool& bDisabled) = 0;
IMPL_FUNC_2(IAnnotationController, IsViewerAnnotationDisabled, SDKError, SDKViewType, viewtype, bool&, bDisable, SDKERR_UNINITIALIZE)
//virtual SDKError CanDisableViewerAnnotation(SDKViewType viewtype, bool& bCan) = 0;
IMPL_FUNC_2(IAnnotationController, CanDisableViewerAnnotation, SDKError, SDKViewType, viewtype, bool&, bCan, SDKERR_UNINITIALIZE)
//virtual SDKError CanDoAnnotation(SDKViewType viewtype, bool& bCan) = 0;
IMPL_FUNC_2(IAnnotationController, CanDoAnnotation, SDKError, SDKViewType, viewtype, bool&, bCan, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE