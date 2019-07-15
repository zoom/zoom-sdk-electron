#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingVideoControllerWrap;
ICameraController* InitICameraControllerFunc(ICameraControllerEvent* pEvent, IMeetingVideoControllerWrap* pOwner);
void UninitICameraControllerFunc(ICameraController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(ICameraController, ICameraControllerEvent)
NORMAL_CLASS(ICameraController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(ICameraController, IMeetingVideoControllerWrap)
virtual SDKError SetEvent(ICameraControllerEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual bool	 IsValid() = 0;
DEFINE_FUNC_0(IsValid, bool)
//virtual SDKError BeginTurnLeft() = 0;
DEFINE_FUNC_0(BeginTurnLeft, SDKError)
//virtual SDKError ContinueTurnLeft() = 0;
DEFINE_FUNC_0(ContinueTurnLeft, SDKError)
//virtual SDKError EndTurnLeft() = 0;
DEFINE_FUNC_0(EndTurnLeft, SDKError)

//virtual SDKError BeginTurnRight() = 0;
DEFINE_FUNC_0(BeginTurnRight, SDKError)
//virtual SDKError ContinueTurnRight() = 0;
DEFINE_FUNC_0(ContinueTurnRight, SDKError)
//virtual SDKError EndTurnRight() = 0;
DEFINE_FUNC_0(EndTurnRight, SDKError)

//virtual SDKError BeginTurnUp() = 0;
DEFINE_FUNC_0(BeginTurnUp, SDKError)
//virtual SDKError ContinueTurnUp() = 0;
DEFINE_FUNC_0(ContinueTurnUp, SDKError)
//virtual SDKError EndTurnUp() = 0;
DEFINE_FUNC_0(EndTurnUp, SDKError)

//virtual SDKError BeginTurnDown() = 0;
DEFINE_FUNC_0(BeginTurnDown, SDKError)
//virtual SDKError ContinueTurnDown() = 0;
DEFINE_FUNC_0(ContinueTurnDown, SDKError)
//virtual SDKError EndTurnDown() = 0;
DEFINE_FUNC_0(EndTurnDown, SDKError)

//virtual SDKError BeginZoomIn() = 0;
DEFINE_FUNC_0(BeginZoomIn, SDKError)
//virtual SDKError ContinueZoomIn() = 0;
DEFINE_FUNC_0(ContinueZoomIn, SDKError)
//virtual SDKError EndZoomIn() = 0;
DEFINE_FUNC_0(EndZoomIn, SDKError)

//virtual SDKError BeginZoomOut() = 0;
DEFINE_FUNC_0(BeginZoomOut, SDKError)
//virtual SDKError ContinueZoomOut() = 0;
DEFINE_FUNC_0(ContinueZoomOut, SDKError)
//virtual SDKError EndZoomOut() = 0;
DEFINE_FUNC_0(EndZoomOut, SDKError)

//virtual SDKError CanControlCamera(bool& bCan) = 0;
DEFINE_FUNC_1(CanControlCamera, SDKError, bool&, bCan)

//virtual void onControllerStatusChanged(bool valid) = 0;
CallBack_FUNC_1(onControllerStatusChanged, bool, valid)

END_CLASS_DEFINE(ICameraController)
END_ZOOM_SDK_NAMESPACE
