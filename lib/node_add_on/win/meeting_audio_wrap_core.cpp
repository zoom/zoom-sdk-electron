
#include "../meeting_audio_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_audio_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingAudioWrap::ZMeetingAudioWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingAudioCtrlWrapEvent.SetOwner(this);
	m_pSink = 0;
	
}
ZMeetingAudioWrap::~ZMeetingAudioWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingAudioCtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingAudioWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingAudioCtrlWrapEvent);
}
void ZMeetingAudioWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().Uninit_Wrap();
}
void ZMeetingAudioWrap::SetSink(ZNativeSDKMeetingAudioWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingAudioWrap::MuteAudio(unsigned int userid, bool allowUnmuteBySelf)
{
	
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().MuteAudio(userid, allowUnmuteBySelf));
	return err;
}
ZNSDKError ZMeetingAudioWrap::UnMuteAudio(unsigned int userid)
{
	
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().UnMuteAudio(userid));
}
ZNSDKError ZMeetingAudioWrap::JoinVoip()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().JoinVoip());
}
ZNSDKError ZMeetingAudioWrap::LeaveVoip()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().LeaveVoip());
}
void ZMeetingAudioWrap::onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList)
{
	if (m_pSink)
		m_pSink->onUserAudioStatusChange(lstAudioStatusChange, strAudioStatusList);
}
void ZMeetingAudioWrap::onUserActiveAudioChange(ZNList<unsigned int > lstActiveAudio)
{
	if (m_pSink)
		m_pSink->onUserActiveAudioChange(lstActiveAudio);
}