
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
					UINT64 userid = pAudioStatus->GetUserId();
					wchar_t temp[1024];
					int radix = 10;
					_ui64tow(userid, temp, radix);
					userAudioStatus.userId = temp;
					userAudioStatus.audioStauts = Map2WrapDefine(pAudioStatus->GetStatus());
					audio_status_list.add(userAudioStatus);
				}
				owner_->onUserAudioStatusChange(audio_status_list, zn_strAudioStatusList);
			}
		}
	}
	virtual void onUserActiveAudioChange(ZOOM_SDK_NAMESPACE::IList<unsigned int >* plstActiveAudio)
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
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().SetEvent(&g_meeting_audio_ctrl_event);
}
void ZMeetingAudioWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().Uninit_Wrap();
}
void ZMeetingAudioWrap::SetSink(IZNativeSDKMeetingAudioWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingAudioWrap::MuteAudio(ZoomSTRING userid, bool allowUnmuteBySelf)
{
	unsigned int sdk_userid = (unsigned int)_wtoi(userid.c_str());
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().MuteAudio(sdk_userid, allowUnmuteBySelf));
	return err;
}
ZNSDKError ZMeetingAudioWrap::UnMuteAudio(ZoomSTRING userid)
{
	unsigned int sdk_userid = (unsigned int)_wtoi(userid.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingAudioController().UnMuteAudio(sdk_userid));
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