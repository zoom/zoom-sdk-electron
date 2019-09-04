
#include "../meeting_audio_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_audio_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
class ZMeetingAudioCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingAudioCtrlEvent
{
public:
	void SetOwner(ZMeetingAudioWrap* obj) { owner_ = obj; }
	virtual void onUserAudioStatusChange(ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IUserAudioStatus* >* lstAudioStatusChange, const wchar_t* strAudioStatusList)
	{
		if (owner_) {
			if (NULL == strAudioStatusList && lstAudioStatusChange && lstAudioStatusChange->GetCount() > 0)
			{
				//
				ZNList<ZNUserAudioStatus> audio_status_list;
				ZoomSTRING zn_strAudioStatusList = L"";
				for (int i = 0; i < lstAudioStatusChange->GetCount(); ++i)
				{
					ZOOM_SDK_NAMESPACE::IUserAudioStatus* pAudioStatus = lstAudioStatusChange->GetItem(i);
					ZNUserAudioStatus userAudioStatus;
					if (pAudioStatus)
					{
						userAudioStatus.userId = pAudioStatus->GetUserId();
						userAudioStatus.audioStauts = Map2WrapDefine(pAudioStatus->GetStatus());
					}
					
					audio_status_list.push_back(userAudioStatus);
				}
				owner_->onUserAudioStatusChange(audio_status_list, zn_strAudioStatusList);
			}
		}
	}
	virtual void onUserActiveAudioChange(ZOOM_SDK_NAMESPACE::IList<unsigned int >* plstActiveAudio)
	{
		if (owner_) {
			if (plstActiveAudio && plstActiveAudio->GetCount() > 0)
			{
				//
				ZNList<unsigned int> active_audio_list;
				for (int i = 0; i < plstActiveAudio->GetCount(); ++i)
				{
					unsigned int userid = plstActiveAudio->GetItem(i);
					active_audio_list.push_back(userid);
				}
				owner_->onUserActiveAudioChange(active_audio_list);
			}
		}
	}
	virtual void onHostRequestStartAudio(ZOOM_SDK_NAMESPACE::IRequestStartAudioHandler* handler_)
	{

	}
private:
	ZMeetingAudioWrap* owner_;
};

static ZMeetingAudioCtrlWrapEvent g_meeting_audio_ctrl_event;


ZMeetingAudioWrap::ZMeetingAudioWrap()
{
	g_meeting_audio_ctrl_event.SetOwner(this);
	m_pSink = 0;
	
}
ZMeetingAudioWrap::~ZMeetingAudioWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_audio_ctrl_event.SetOwner(NULL);
}
void ZMeetingAudioWrap::Init()
{
	
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().SetEvent(&g_meeting_audio_ctrl_event);
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