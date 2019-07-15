#include "camera_controller_wrap.h"
#include "./meeting_service_components_wrap/meeting_video_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ICameraController* InitICameraControllerFunc(ICameraControllerEvent* pEvent, IMeetingVideoControllerWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::ICameraController* pObj = pOwner->GetSDKObj()->GetMyCameraController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitICameraControllerFunc(ICameraController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual bool	 IsValid() = 0;
IMPL_FUNC_0(ICameraController, IsValid, bool, false)

//virtual SDKError BeginTurnLeft() = 0;
IMPL_FUNC_0(ICameraController, BeginTurnLeft, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ContinueTurnLeft() = 0;
IMPL_FUNC_0(ICameraController, ContinueTurnLeft, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EndTurnLeft() = 0;
IMPL_FUNC_0(ICameraController, EndTurnLeft, SDKError, SDKERR_UNINITIALIZE)

//virtual SDKError BeginTurnRight() = 0;
IMPL_FUNC_0(ICameraController, BeginTurnRight, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ContinueTurnRight() = 0;
IMPL_FUNC_0(ICameraController, ContinueTurnRight, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EndTurnRight() = 0;
IMPL_FUNC_0(ICameraController, EndTurnRight, SDKError, SDKERR_UNINITIALIZE)

//virtual SDKError BeginTurnUp() = 0;
IMPL_FUNC_0(ICameraController, BeginTurnUp, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ContinueTurnUp() = 0;
IMPL_FUNC_0(ICameraController, ContinueTurnUp, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EndTurnUp() = 0;
IMPL_FUNC_0(ICameraController, EndTurnUp, SDKError, SDKERR_UNINITIALIZE)

//virtual SDKError BeginTurnDown() = 0;
IMPL_FUNC_0(ICameraController, BeginTurnDown, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ContinueTurnDown() = 0;
IMPL_FUNC_0(ICameraController, ContinueTurnDown, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EndTurnDown() = 0;
IMPL_FUNC_0(ICameraController, EndTurnDown, SDKError, SDKERR_UNINITIALIZE)

//virtual SDKError BeginZoomIn() = 0;
IMPL_FUNC_0(ICameraController, BeginZoomIn, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ContinueZoomIn() = 0;
IMPL_FUNC_0(ICameraController, ContinueZoomIn, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EndZoomIn() = 0;
IMPL_FUNC_0(ICameraController, EndZoomIn, SDKError, SDKERR_UNINITIALIZE)

//virtual SDKError BeginZoomOut() = 0;
IMPL_FUNC_0(ICameraController, BeginZoomOut, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ContinueZoomOut() = 0;
IMPL_FUNC_0(ICameraController, ContinueZoomOut, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EndZoomOut() = 0;
IMPL_FUNC_0(ICameraController, EndZoomOut, SDKError, SDKERR_UNINITIALIZE)

//virtual SDKError CanControlCamera(bool& bCan) = 0;
IMPL_FUNC_1(ICameraController, CanControlCamera, SDKError, bool&, bCan, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE