#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZMeetingAnnotationWrap
{
public:
	ZMeetingAnnotationWrap();
	virtual ~ZMeetingAnnotationWrap();
	void Init();
	void Uninit();

	bool IsAnnoataionDisable();
	ZNSDKError StartAnnotation(ZNSDKViewType type, ZoomSTRING left, ZoomSTRING top);
	ZNSDKError StopAnnotation(ZNSDKViewType type);
	ZNSDKError SetTool(ZNSDKViewType viewType, ZNAnnotationToolType toolType);
	ZNSDKError Clear(ZNSDKViewType viewType, ZNAnnotationClearType toolType);
	ZNSDKError SetColor(ZNSDKViewType viewType, ZoomSTRING color);
	ZNSDKError SetLineWidth(ZNSDKViewType viewType, ZoomSTRING lineWidth);
	ZNSDKError Undo(ZNSDKViewType viewType);
	ZNSDKError Redo(ZNSDKViewType viewType);

};
