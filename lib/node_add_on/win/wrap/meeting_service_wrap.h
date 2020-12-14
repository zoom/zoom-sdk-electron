#pragma once
#include "common_include.h"
#include "meeting_service_components_wrap/meeting_configuration_wrap.h"
#include "meeting_service_components_wrap/meeting_ui_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_annotation_wrap.h"
#include "meeting_service_components_wrap/meeting_video_wrap.h"
#include "meeting_service_components_wrap/meeting_remote_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_sharing_wrap.h"
#include "meeting_service_components_wrap/meeting_audio_wrap.h"
#include "meeting_service_components_wrap/meeting_recording_wrap.h"
#include "meeting_service_components_wrap/meeting_chat_wrap.h"
#include "meeting_service_components_wrap/meeting_waiting_room_wrap.h"
#include "meeting_service_components_wrap/meeting_h323_helper_wrap.h"
#include "meeting_service_components_wrap/meeting_phone_helper_wrap.h"
#include "meeting_service_components_wrap/meeting_breakout_rooms_wrap.h"
#include "meeting_service_components_wrap/meeting_participants_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_live_stream_wrap.h"
#include "meeting_service_components_wrap/meeting_webinar_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_closedcaption_ctrl_wrap.h"
#include "meeting_service_components_wrap/meeting_realname_auth_helper_wrap.h"
#include "meeting_service_components_wrap/meeting_interpretation_ctrl_wrap.h"

BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IMeetingService* InitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingServiceEvent* pEvent);
void UninitIMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IMeetingService* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingService, IMeetingServiceEvent)
STAITC_CLASS(IMeetingService)
INIT_UNINIT_WITHEVENT(IMeetingService)
virtual SDKError SetEvent(IMeetingServiceEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError Join(JoinParam& joinParam) = 0;
DEFINE_FUNC_1(Join, SDKError, JoinParam&, joinParam)
//virtual SDKError Start(StartParam& startParam) = 0;
DEFINE_FUNC_1(Start, SDKError, StartParam&, startParam)
//virtual SDKError Leave(LeaveMeetingCmd leaveCmd) = 0;
DEFINE_FUNC_1(Leave, SDKError, LeaveMeetingCmd, leaveCmd)
//virtual MeetingStatus GetMeetingStatus() = 0;
DEFINE_FUNC_0(GetMeetingStatus, MeetingStatus)
//virtual SDKError LockMeeting() = 0;
DEFINE_FUNC_0(LockMeeting, SDKError)
//virtual SDKError UnlockMeeting() = 0;
DEFINE_FUNC_0(UnlockMeeting, SDKError)
//virtual bool IsMeetingLocked() = 0;
DEFINE_FUNC_0(IsMeetingLocked, bool)
//virtual IMeetingInfo* GetMeetingInfo() = 0;
DEFINE_FUNC_0(GetMeetingInfo, IMeetingInfo*)
//virtual ConnectionQuality GetMeetingConnQuality() = 0;
DEFINE_FUNC_0(GetSharingConnQuality, ConnectionQuality)
//virtual ConnectionQuality GetVideoConnQuality() = 0;
DEFINE_FUNC_0(GetVideoConnQuality, ConnectionQuality)
//virtual ConnectionQuality GetAudioConnQuality() = 0;
DEFINE_FUNC_0(GetAudioConnQuality, ConnectionQuality)
//virtual SDKError HandleZoomWebUriProtocolAction(const wchar_t* protocol_action) = 0;
DEFINE_FUNC_1(HandleZoomWebUriProtocolAction, SDKError, const wchar_t*, protocol_action)
//virtual ConnectionQuality GetSharingConnQuality(bool bSending = true) = 0;
DEFINE_FUNC_1(GetSharingConnQuality, ConnectionQuality, bool, bSending)
//virtual ConnectionQuality GetVideoConnQuality(bool bSending = true) = 0;
DEFINE_FUNC_1(GetVideoConnQuality, ConnectionQuality, bool, bSending)
//virtual ConnectionQuality GetAudioConnQuality(bool bSending = true) = 0;
DEFINE_FUNC_1(GetAudioConnQuality, ConnectionQuality, bool, bSending)

#if (defined UserInterfaceClass)
private:
DEFINE_FUNC_0(GetMeetingConfiguration, IMeetingConfiguration*)
DEFINE_FUNC_0(GetUIController, IMeetingUIController*)
DEFINE_FUNC_0(GetAnnotationController, IAnnotationController*)
DEFINE_FUNC_0(GetMeetingVideoController, IMeetingVideoController*)
DEFINE_FUNC_0(GetMeetingRemoteController, IMeetingRemoteController*)
DEFINE_FUNC_0(GetMeetingShareController, IMeetingShareController*)
DEFINE_FUNC_0(GetMeetingAudioController, IMeetingAudioController*)
DEFINE_FUNC_0(GetMeetingRecordingController, IMeetingRecordingController*)
DEFINE_FUNC_0(GetMeetingChatController, IMeetingChatController*)
DEFINE_FUNC_0(GetMeetingWaitingRoomController, IMeetingWaitingRoomController*)
DEFINE_FUNC_0(GetH323Helper, IMeetingH323Helper*)
DEFINE_FUNC_0(GetMeetingPhoneHelper, IMeetingPhoneHelper*)
DEFINE_FUNC_0(GetMeetingBreakoutRoomsController, IMeetingBreakoutRoomsController*)
DEFINE_FUNC_0(GetMeetingParticipantsController, IMeetingParticipantsController*)
DEFINE_FUNC_0(GetMeetingLiveStreamController, IMeetingLiveStreamController*)
DEFINE_FUNC_0(GetMeetingWebinarController, IMeetingWebinarController*)
DEFINE_FUNC_0(GetMeetingClosedCaptionController, IClosedCaptionController*)
DEFINE_FUNC_0(GetMeetingRealNameAuthController IZoomRealNameAuthMeetingHelper*)
public:
#define T_GetMeetingConfiguration _GetMeetingConfiguration
#define T_GetUIController _GetUIController
#define T_GetAnnotationController _GetAnnotationController
#define T_GetMeetingVideoController _GetMeetingVideoController
#define T_GetMeetingRemoteController _GetMeetingRemoteController
#define T_GetMeetingShareController _GetMeetingShareController
#define T_GetMeetingAudioController _GetMeetingAudioController
#define T_GetMeetingRecordingController _GetMeetingRecordingController
#define T_GetMeetingChatController _GetMeetingChatController
#define T_GetMeetingWaitingRoomController _GetMeetingWaitingRoomController
#define T_GetH323Helper _GetH323Helper
#define T_GetMeetingPhoneHelper _GetMeetingPhoneHelper
#define T_GetMeetingBreakoutRoomsController _GetMeetingBreakoutRoomsController
#define T_GetMeetingParticipantsController _GetMeetingParticipantsController
#define T_GetMeetingLiveStreamController _GetMeetingLiveStreamController
#define T_GetMeetingWebinarController _GetMeetingWebinarController
#define T_GetMeetingClosedCaptionController _GetMeetingClosedCaptionController
#define T_GetMeetingRealNameAuthController _GetMeetingRealNameAuthController
#define T_GetMeetingQAController _GetMeetingQAController
#define T_GetMeetingBOController _GetMeetingBOController
#define T_GetMeetingInterpretationController _GetMeetingInterpretationController
#else
#define T_GetMeetingConfiguration GetMeetingConfiguration
#define T_GetUIController GetUIController
#define T_GetAnnotationController GetAnnotationController
#define T_GetMeetingVideoController GetMeetingVideoController
#define T_GetMeetingRemoteController GetMeetingRemoteController
#define T_GetMeetingShareController GetMeetingShareController
#define T_GetMeetingAudioController GetMeetingAudioController
#define T_GetMeetingRecordingController GetMeetingRecordingController
#define T_GetMeetingChatController GetMeetingChatController
#define T_GetMeetingWaitingRoomController GetMeetingWaitingRoomController
#define T_GetH323Helper GetH323Helper
#define T_GetMeetingPhoneHelper GetMeetingPhoneHelper
#define T_GetMeetingBreakoutRoomsController GetMeetingBreakoutRoomsController
#define T_GetMeetingParticipantsController GetMeetingParticipantsController
#define T_GetMeetingLiveStreamController GetMeetingLiveStreamController
#define T_GetMeetingWebinarController GetMeetingWebinarController
#define T_GetMeetingClosedCaptionController GetMeetingClosedCaptionController
#define T_GetMeetingRealNameAuthController GetMeetingRealNameAuthController
#define T_GetMeetingQAController GetMeetingQAController
#define T_GetMeetingBOController GetMeetingBOController
#define T_GetMeetingInterpretationController GetMeetingInterpretationController

#endif
DEFINE_FUNC_AND_MEMBER(T_GetMeetingConfiguration, IMeetingConfigurationWrap)
DEFINE_FUNC_AND_MEMBER(T_GetUIController, IMeetingUIControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetAnnotationController, IAnnotationControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingVideoController, IMeetingVideoControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingRemoteController, IMeetingRemoteControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingShareController, IMeetingShareControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingAudioController, IMeetingAudioControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingRecordingController, IMeetingRecordingControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingChatController, IMeetingChatControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingWaitingRoomController, IMeetingWaitingRoomControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetH323Helper, IMeetingH323HelperWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingPhoneHelper, IMeetingPhoneHelperWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingBreakoutRoomsController, IMeetingBreakoutRoomsControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingParticipantsController, IMeetingParticipantsControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingLiveStreamController, IMeetingLiveStreamControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingWebinarController, IMeetingWebinarControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingClosedCaptionController, IClosedCaptionControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingRealNameAuthController, IZoomRealNameAuthMeetingHelperWrap)
//DEFINE_FUNC_AND_MEMBER(T_GetMeetingQAController, IMeetingQAControllerWrap)
//DEFINE_FUNC_AND_MEMBER(T_GetMeetingBOController, IMeetingBOControllerWrap)
DEFINE_FUNC_AND_MEMBER(T_GetMeetingInterpretationController, IMeetingInterpretationControllerWrap)

//need wrap it in next release.todo
/*
virtual IMeetingLiveStreamController* GetMeetingLiveStreamController()
{
	if (m_obj)
		return m_obj->GetMeetingLiveStreamController();
	return NULL;
}

virtual IMeetingWebinarController* GetMeetingWebinarController()
{
	if (m_obj)
		return m_obj->GetMeetingWebinarController();
	return NULL;
}
virtual IClosedCaptionController* GetMeetingClosedCaptionController()
{
	if (m_obj)
		return m_obj->GetMeetingClosedCaptionController();
	return NULL;
}
*/

//need wrap it in next release.todo

//virtual void onMeetingStatusChanged(MeetingStatus status, int iResult = 0) = 0;
CallBack_FUNC_2(onMeetingStatusChanged, MeetingStatus, status, int, iResult)

//virtual void onMeetingSecureKeyNotification(const char* key, int len, IMeetingExternalSecureKeyHandler* pHandler) = 0;
CallBack_FUNC_3(onMeetingSecureKeyNotification, const char*, key, int, len, IMeetingExternalSecureKeyHandler*, pHandler)

/// \brief Meeting statistics warning notification callback
/// \param type The type of meeting statistics warning.
//virtual void onMeetingStatisticsWarningNotification(StatisticsWarningType type) = 0;
CallBack_FUNC_1(onMeetingStatisticsWarningNotification, StatisticsWarningType, type)
//virtual void onMeetingParameterNotification(const MeetingParameter* meeting_param) = 0;
CallBack_FUNC_1(onMeetingParameterNotification, const MeetingParameter*, meeting_param)

END_CLASS_DEFINE(IMeetingService)
END_ZOOM_SDK_NAMESPACE