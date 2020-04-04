#pragma once
#include "../common_include.h"
#include "../customized_ui_components_wrap/customized_annotation_wrap.h"

BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IAnnotationController* InitIAnnotationControllerFunc(IMeetingAnnotationSupportEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIAnnotationControllerFunc(IAnnotationController* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IAnnotationController, IMeetingAnnotationSupportEvent)
NORMAL_CLASS(IAnnotationController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IAnnotationController, IMeetingServiceWrap)

virtual SDKError SetEvent(IMeetingAnnotationSupportEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

private:
	ICustomizedAnnotationControllerWrap  m_customizeAnnoCtrl;
public:

//virtual ICustomizedAnnotationController* GetCustomizedAnnotationController(ICustomizedShareRender* pShareRender = NULL) = 0;
ICustomizedAnnotationControllerWrap& IAnnotationControllerWrap::GetCustomizedAnnotationController(ICustomizedShareRender* pShareRender = NULL)
{
	if (m_obj)
	{
		ZOOM_SDK_NAMESPACE::ICustomizedAnnotationController* pCustomizeAnnotationController = m_obj->GetCustomizedAnnotationController(pShareRender);
		if (pCustomizeAnnotationController)
		{
			m_customizeAnnoCtrl.Init(pCustomizeAnnotationController);
		}
	}
	return m_customizeAnnoCtrl;
}

//virtual bool IsAnnoataionDisable() = 0;
DEFINE_FUNC_0(IsAnnoataionDisable, bool)
//virtual SDKError StartAnnotation(SDKViewType viewtype, int left, int top) = 0;
DEFINE_FUNC_3(StartAnnotation, SDKError, SDKViewType, viewtype, int, left, int, top)
//virtual SDKError StopAnnotation(SDKViewType viewtype) = 0;
DEFINE_FUNC_1(StopAnnotation, SDKError, SDKViewType, viewtype)
//virtual SDKError SetTool(SDKViewType viewtype, AnnotationToolType type) = 0;
DEFINE_FUNC_2(SetTool, SDKError, SDKViewType, viewtype, AnnotationToolType, type)
//virtual SDKError Clear(SDKViewType viewtype, AnnotationClearType type) = 0;
DEFINE_FUNC_2(Clear, SDKError, SDKViewType, viewtype, AnnotationClearType, type)
//virtual SDKError SetColor(SDKViewType viewtype, unsigned long color) = 0;
DEFINE_FUNC_2(SetColor, SDKError, SDKViewType, viewtype, unsigned long, color)
//virtual SDKError SetLineWidth(SDKViewType viewtype, long lineWidth) = 0;
DEFINE_FUNC_2(SetLineWidth, SDKError, SDKViewType, viewtype, long, lineWidth)
//virtual SDKError Undo(SDKViewType viewtype) = 0;
DEFINE_FUNC_1(Undo, SDKError, SDKViewType, viewtype)
//virtual SDKError Redo(SDKViewType viewtype) = 0;
DEFINE_FUNC_1(Redo, SDKError, SDKViewType, viewtype)
//virtual SDKError DisableViewerAnnotation(SDKViewType viewtype, bool bDisable) = 0;
DEFINE_FUNC_2(DisableViewerAnnotation, SDKError, SDKViewType, viewtype, bool, bDisable)
//virtual SDKError IsViewerAnnotationDisabled(SDKViewType viewtype, bool& bDisabled) = 0;
DEFINE_FUNC_2(IsViewerAnnotationDisabled, SDKError, SDKViewType, viewtype, bool&, bDisable)
//virtual SDKError CanDisableViewerAnnotation(SDKViewType viewtype, bool& bCan) = 0;
DEFINE_FUNC_2(CanDisableViewerAnnotation, SDKError, SDKViewType, viewtype, bool&, bCan)
//virtual SDKError CanDoAnnotation(SDKViewType viewtype, bool& bCan) = 0;
DEFINE_FUNC_2(CanDoAnnotation, SDKError, SDKViewType, viewtype, bool&, bCan)

//virtual void onSupportAnnotationStatus(unsigned int userid, bool bSupportAnnotation) = 0;
CallBack_FUNC_2(onSupportAnnotationStatus, unsigned int, userid, bool, bSupportAnnotation)

END_CLASS_DEFINE(IAnnotationController)
END_ZOOM_SDK_NAMESPACE