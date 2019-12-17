
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
	int sdk_color = _wtoi(color.c_str());
	unsigned long nColorValue;

	switch (sdk_color)
	{
	case 1:
		//yellow
		nColorValue = RGB(255, 255, 0);
		break;
	case 2:
		//orange
		nColorValue = RGB(255, 102, 0);
		break;
	case 3:
		//red
		nColorValue = RGB(255, 0, 0);
		break;
	case 4:
		nColorValue = RGB(96, 57, 19);
		break;
	case 5:
		nColorValue = RGB(246, 150, 121);
		break;
	case 6:
		nColorValue = RGB(236, 0, 140);
		break;
	case 7:
		nColorValue = RGB(146, 39, 143);
		break;
	case 8:
		nColorValue = RGB(0, 0, 0);
		break;
	case 9:
		nColorValue = RGB(0, 165, 255);
		break;
	case 10:
		nColorValue = RGB(0, 0, 255);
		break;
	case 11:
		nColorValue = RGB(0, 33, 87);
		break;
	case 12:
		nColorValue = RGB(149, 149, 149);
		break;
	case 13:
		nColorValue = RGB(137, 204, 0);
		break;
	case 14:
		nColorValue = RGB(0, 255, 0);
		break;
	case 15:
		nColorValue = RGB(0, 114, 54);
		break;
	case 16:
		nColorValue = RGB(255, 255, 255);
		break;
	}
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetAnnotationController().SetColor(sdk_viewtype, nColorValue));
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