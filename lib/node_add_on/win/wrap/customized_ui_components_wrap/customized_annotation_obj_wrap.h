#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE

BEGIN_CLASS_DEFINE_WITHCALLBACK(ICustomizedAnnotationObj, ICustomizedAnnotationObjEvent)
NORMAL_CLASS(ICustomizedAnnotationObj)
~ICustomizedAnnotationObjWrap();
void Init(ICustomizedAnnotationObj* pObj);
void UnInit();
//virtual SDKError SetEvent(ICustomizedAnnotationObjEvent* event_) = 0;
DEFINE_FUNC_1(SetEvent, SDKError, ICustomizedAnnotationObjEvent*, pEvent)
//virtual SDKError CanClear(AnnotationClearType type) = 0;
DEFINE_FUNC_1(CanClear, SDKError, AnnotationClearType, type)
//virtual SDKError Clear(AnnotationClearType type) = 0;
DEFINE_FUNC_1(Clear, SDKError, AnnotationClearType, type)
//virtual SDKError SetTool(AnnotationToolType type) = 0;
DEFINE_FUNC_1(SetTool, SDKError, AnnotationToolType, type)
//virtual SDKError SetColor(unsigned long color) = 0;
DEFINE_FUNC_1(SetColor, SDKError, unsigned long, color)
//virtual SDKError SetLineWidth(long lineWidth) = 0;
DEFINE_FUNC_1(SetLineWidth, SDKError, long, lineWidth)
//virtual SDKError GetCurColor(unsigned long& color) = 0;
DEFINE_FUNC_1(GetCurColor, SDKError, unsigned long&, color)
//virtual SDKError GetCurLineWidth(long& lineWidth) = 0;
DEFINE_FUNC_1(GetCurLineWidth, SDKError, long&, lineWidth)
//virtual SDKError GetCurTool(AnnotationToolType& type) = 0;
DEFINE_FUNC_1(GetCurTool, SDKError, AnnotationToolType&, type)
//virtual SDKError Undo() = 0;
DEFINE_FUNC_0(Undo, SDKError);
//virtual SDKError Redo() = 0;
DEFINE_FUNC_0(Redo, SDKError);
//virtual SDKError CanSaveSnapshot() = 0;
DEFINE_FUNC_0(CanSaveSnapshot, SDKError);
//virtual SDKError SaveSnapshot(const wchar_t* path, SDKAnnoSaveType nType) = 0;
DEFINE_FUNC_2(SaveSnapshot, SDKError, const wchar_t*, path, SDKAnnoSaveType, nType);

//virtual void onAnnotationObjToolChange(AnnotationToolType type_);
CallBack_FUNC_1(onAnnotationObjToolChange, AnnotationToolType, type_)

END_CLASS_DEFINE(ICustomizedAnnotationObj)
END_ZOOM_SDK_NAMESPACE