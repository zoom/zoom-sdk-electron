#include "meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IMeetingService* InitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingServiceEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::IMeetingService* pObj(NULL);
	CSDKImpl::GetInst().CreateMeetingService(&pObj);
	if (pObj)
	{
		pObj->SetEvent(pEvent);
	}
	return pObj;
}
void UninitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingService* obj)
{
	CSDKImpl::GetInst().DestroyMeetingService(obj);
}

//virtual SDKError HandleZoomWebUriProtocolAction(const wchar_t* protocol_action) = 0;
IMPL_FUNC_1(IMeetingService, HandleZoomWebUriProtocolAction, SDKError, const wchar_t*, protocol_action, SDKERR_UNINITIALIZE)
//virtual ConnectionQuality GetSharingConnQuality(bool bSending = true) = 0;
IMPL_FUNC_1(IMeetingService, GetSharingConnQuality, ConnectionQuality, bool, bSending, Conn_Quality_Unknow)
//virtual ConnectionQuality GetVideoConnQuality(bool bSending = true) = 0;
IMPL_FUNC_1(IMeetingService, GetVideoConnQuality, ConnectionQuality, bool, bSending, Conn_Quality_Unknow)
//virtual ConnectionQuality GetAudioConnQuality(bool bSending = true) = 0;
IMPL_FUNC_1(IMeetingService, GetAudioConnQuality, ConnectionQuality, bool, bSending, Conn_Quality_Unknow)

IMPL_FUNC_1(IMeetingService, Join, SDKError, JoinParam&, joinParam, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IMeetingService, Start, SDKError, StartParam&, startParam, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IMeetingService, Leave, SDKError, LeaveMeetingCmd, leaveCmd, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(IMeetingService, GetMeetingStatus, MeetingStatus, MEETING_STATUS_IDLE);
IMPL_FUNC_0(IMeetingService, LockMeeting, SDKError, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(IMeetingService, UnlockMeeting, SDKError, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(IMeetingService, IsMeetingLocked, bool, false);
IMPL_FUNC_0(IMeetingService, GetMeetingInfo, IMeetingInfo*, NULL);
IMPL_FUNC_0(IMeetingService, GetSharingConnQuality, ConnectionQuality, Conn_Quality_Unknow);
IMPL_FUNC_0(IMeetingService, GetVideoConnQuality, ConnectionQuality, Conn_Quality_Unknow);
IMPL_FUNC_0(IMeetingService, GetAudioConnQuality, ConnectionQuality, Conn_Quality_Unknow);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingConfiguration, IMeetingConfigurationWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetUIController, IMeetingUIControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetAnnotationController, IAnnotationControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingVideoController, IMeetingVideoControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingRemoteController, IMeetingRemoteControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingShareController, IMeetingShareControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingAudioController, IMeetingAudioControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingRecordingController, IMeetingRecordingControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingChatController, IMeetingChatControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingWaitingRoomController, IMeetingWaitingRoomControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetH323Helper, IMeetingH323HelperWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingPhoneHelper, IMeetingPhoneHelperWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingBreakoutRoomsController, IMeetingBreakoutRoomsControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingParticipantsController, IMeetingParticipantsControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingLiveStreamController, IMeetingLiveStreamControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingWebinarController, IMeetingWebinarControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingClosedCaptionController, IClosedCaptionControllerWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingRealNameAuthController, IZoomRealNameAuthMeetingHelperWrap);
IMPL_FUNC_AND_MEMBER(IMeetingService, T_GetMeetingInterpretationController, IMeetingInterpretationControllerWrap);
#if (defined UserInterfaceClass)
IMPL_FUNC_0(IMeetingService, GetMeetingConfiguration, IMeetingConfiguration*, NULL)
IMPL_FUNC_0(IMeetingService, GetUIController, IMeetingUIController*, NULL)
IMPL_FUNC_0(IMeetingService, GetAnnotationController, IAnnotationController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingVideoController, IMeetingVideoController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingRemoteController, IMeetingRemoteController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingShareController, IMeetingShareController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingAudioController, IMeetingAudioController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingRecordingController, IMeetingRecordingController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingChatController, IMeetingChatController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingWaitingRoomController, IMeetingWaitingRoomController*, NULL)
IMPL_FUNC_0(IMeetingService, GetH323Helper, IMeetingH323Helper*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingPhoneHelper, IMeetingPhoneHelper*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingBreakoutRoomsController, IMeetingBreakoutRoomsController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingParticipantsController, IMeetingParticipantsController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingLiveStreamController, IMeetingLiveStreamController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingWebinarController, IMeetingWebinarController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingClosedCaptionController, IClosedCaptionController*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingRealNameAuthController, IZoomRealNameAuthMeetingHelper*, NULL)
IMPL_FUNC_0(IMeetingService, GetMeetingInterpretationController, IMeetingInterpretationControllerWrap*, NULL)
#endif
END_ZOOM_SDK_NAMESPACE