#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE

class IAnnotationControllerWrap;
BEGIN_CLASS_DEFINE_WITHCALLBACK(ICustomizedAnnotationController, ICustomizedAnnotationControllerEvent)
NORMAL_CLASS(ICustomizedAnnotationController)
~ICustomizedAnnotationControllerWrap();
void Init(ICustomizedAnnotationController* pObj);
void UnInit();

//virtual SDKError CreateAnnoObj(ICustomizedShareRender* view_share_render, ICustomizedAnnotationObj** pp_obj) = 0;
DEFINE_FUNC_2(CreateAnnoObj, SDKError, ICustomizedShareRender*, view_share_render, ICustomizedAnnotationObj**, pp_obj)
//virtual SDKError DestroyAnnoObj(ICustomizedAnnotationObj* anno_obj) = 0;
DEFINE_FUNC_1(DestroyAnnoObj, SDKError, ICustomizedAnnotationObj*, anno_obj)

//virtual void onCustomizedAnnotationObjDestroyed(ICustomizedAnnotationObj* obj_) = 0;
CallBack_FUNC_1(onCustomizedAnnotationObjDestroyed, ICustomizedAnnotationObj*, obj)
//virtual void onSharingShareAnnotationStatusChanged(ICustomizedShareRender* share_render_, CustomizedShareAnnotationStatus status_) = 0;
CallBack_FUNC_2(onSharingShareAnnotationStatusChanged, ICustomizedShareRender*, share_render, CustomizedShareAnnotationStatus, status)

END_CLASS_DEFINE(ICustomizedAnnotationController)
END_ZOOM_SDK_NAMESPACE