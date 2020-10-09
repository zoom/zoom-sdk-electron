#include "../sdk_wrap.h"
#include "customized_annotation_obj_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE

ICustomizedAnnotationObjWrap::~ICustomizedAnnotationObjWrap()
{
	UnInit();
}

// This wrapper doesn't follow the standard pattern. It's expected to be created by the customized annotation controller.
// So the controller will create the ICustomizedAnnotationObj interface and call this method to set the underlying SDK object
void ICustomizedAnnotationObjWrap::Init(ICustomizedAnnotationObj* pObj)
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

void ICustomizedAnnotationObjWrap::UnInit()
{
	if (m_obj)
	{
		m_obj->SetEvent(NULL);
		m_obj = NULL;
	}
}

IMPL_FUNC_1(ICustomizedAnnotationObj, SetEvent, SDKError, ICustomizedAnnotationObjEvent*, pEvent, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, CanClear, SDKError, AnnotationClearType, type, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, Clear, SDKError, AnnotationClearType, type, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, SetTool, SDKError, AnnotationToolType, type, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, SetColor, SDKError, unsigned long, color, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, SetLineWidth, SDKError, long, lineWidth, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, GetCurColor, SDKError, unsigned long&, color, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, GetCurLineWidth, SDKError, long&, lineWidth, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(ICustomizedAnnotationObj, GetCurTool, SDKError, AnnotationToolType&, type, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedAnnotationObj, Undo, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedAnnotationObj, Redo, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(ICustomizedAnnotationObj, CanSaveSnapshot, SDKError, SDKERR_UNINITIALIZE)
IMPL_FUNC_2(ICustomizedAnnotationObj, SaveSnapshot, SDKError, const wchar_t*, path, SDKAnnoSaveType, nType, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE