
#include "../meeting_video_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_video_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingVideoWrap::ZMeetingVideoWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingVideoCtrlWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingVideoWrap::~ZMeetingVideoWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingVideoCtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingVideoWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingVideoCtrlWrapEvent);
}
void ZMeetingVideoWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().Uninit_Wrap();
}
void ZMeetingVideoWrap::SetSink(ZNativeSDKMeetingVideoWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingVideoWrap::MuteVideo(unsigned int userId)
{
	bool zn_is_myself = false;
	ZOOM_SDK_NAMESPACE::IUserInfo* userinfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().GetUserByUserID(userId);
	if (userinfo)
	{
		zn_is_myself = userinfo->IsMySelf();
	}
		
	if (userId != 0 && !zn_is_myself)
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().StopAttendeeVideo(userId));
	}
	else
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().MuteVideo());
	}
}
ZNSDKError ZMeetingVideoWrap::UnMuteVideo(unsigned int userId)
{
	bool zn_is_myself = false;
	ZOOM_SDK_NAMESPACE::IUserInfo* userinfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().GetUserByUserID(userId);
	if (userinfo)
	{
		zn_is_myself = userinfo->IsMySelf();
	}
	if (userId != 0 && !zn_is_myself)
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().AskAttendeeToStartVideo(userId));
	}
	else
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnmuteVideo());
	}
	
}
ZNSDKError ZMeetingVideoWrap::PinVideo(bool bPin, bool bFirstView, unsigned int userId)
{
	
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().PinVideo(bPin, bFirstView, userId));
}
ZNSDKError ZMeetingVideoWrap::SpotlightVideo(bool bSpotlight, unsigned int userId)
{
	
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SpotlightVideo(bSpotlight, userId));
}
ZNSDKError ZMeetingVideoWrap::HideOrShowNoVideoUserOnVideoWall(bool bHide)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().HideOrShowNoVideoUserOnVideoWall(bHide));
}


void ZMeetingVideoWrap::onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status)
{
	if (m_pSink)
	{
		m_pSink->onUserVideoStatusChange(userId, status);
	}
}
void ZMeetingVideoWrap::onActiveSpeakerVideoUserChanged(unsigned int userId)
{
	if (m_pSink)
	{
		m_pSink->onActiveSpeakerVideoUserChanged(userId);
	}
}
void ZMeetingVideoWrap::onActiveVideoUserChanged(unsigned int userId)
{
	if (m_pSink)
	{
		m_pSink->onActiveVideoUserChanged(userId);
	}
}