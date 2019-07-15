
#include "../meeting_annotation_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_annotation_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
ZMeetingAnnotationWrap::ZMeetingAnnotationWrap()
{
	
}
ZMeetingAnnotationWrap::~ZMeetingAnnotationWrap()
{
	Uninit();
}
void ZMeetingAnnotationWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().Init_Wrap(&g_meeting_service_wrap);
}
void ZMeetingAnnotationWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().Uninit_Wrap();
}
bool ZMeetingAnnotationWrap::IsAnnoataionDisable()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().IsAnnoataionDisable();
}
ZNSDKError ZMeetingAnnotationWrap::StartAnnotation(ZNSDKViewType type, ZoomSTRING left, ZoomSTRING top)
{
	ZOOM_SDK_NAMESPACE::SDKViewType viewtype = Map2SDKDefine(type);
	int sdk_left = _wtoi(left.c_str());
	int sdk_top = _wtoi(top.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().StartAnnotation(viewtype, sdk_left, sdk_top));
}
ZNSDKError ZMeetingAnnotationWrap::StopAnnotation(ZNSDKViewType type)
{
	ZOOM_SDK_NAMESPACE::SDKViewType viewtype = Map2SDKDefine(type);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().StopAnnotation(viewtype));
}
ZNSDKError ZMeetingAnnotationWrap::SetTool(ZNSDKViewType viewType, ZNAnnotationToolType toolType)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_viewtype = Map2SDKDefine(viewType);
	ZOOM_SDK_NAMESPACE::AnnotationToolType sdk_toolType = Map2SDKDefine(toolType);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().SetTool(sdk_viewtype, sdk_toolType));
}
ZNSDKError ZMeetingAnnotationWrap::Clear(ZNSDKViewType viewType, ZNAnnotationClearType clearType)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_viewtype = Map2SDKDefine(viewType);
	ZOOM_SDK_NAMESPACE::AnnotationClearType sdk_clearType = Map2SDKDefine(clearType);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().Clear(sdk_viewtype, sdk_clearType));
}
ZNSDKError ZMeetingAnnotationWrap::SetColor(ZNSDKViewType viewType, ZoomSTRING color)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_viewtype = Map2SDKDefine(viewType);
	unsigned long sdk_color =(unsigned long)_wtol(color.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().SetColor(sdk_viewtype, sdk_color));
}
ZNSDKError ZMeetingAnnotationWrap::SetLineWidth(ZNSDKViewType viewType, ZoomSTRING lineWidth)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_viewtype = Map2SDKDefine(viewType);
	long sdk_line_width = _wtol(lineWidth.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().SetLineWidth(sdk_viewtype, sdk_line_width));
}
ZNSDKError ZMeetingAnnotationWrap::Undo(ZNSDKViewType viewType)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_viewtype = Map2SDKDefine(viewType);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().Undo(sdk_viewtype));
}
ZNSDKError ZMeetingAnnotationWrap::Redo(ZNSDKViewType viewType)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_viewtype = Map2SDKDefine(viewType);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().Redo(sdk_viewtype));
}