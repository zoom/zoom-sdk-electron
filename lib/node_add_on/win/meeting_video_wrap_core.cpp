
#include "../meeting_video_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_video_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
class ZMeetingVideoCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingVideoCtrlEvent
{
public:
	void SetOwner(ZMeetingVideoWrap* obj) { owner_ = obj; }
	virtual void onUserVideoStatusChange(unsigned int userId, ZOOM_SDK_NAMESPACE::VideoStatus status)
	{
		if (owner_) {
			UINT64 userid = userId;
			wchar_t temp[1024];
			int radix = 10;
			_ui64tow(userid, temp, radix);
			ZoomSTRING zn_userid = temp;
			owner_->onUserVideoStatusChange(zn_userid, Map2WrapDefine(status));
		}
	}
	virtual void onSpotlightVideoChangeNotification(bool bSpotlight, unsigned int userid)
	{
		//
	}
	virtual void onHostRequestStartVideo(ZOOM_SDK_NAMESPACE::IRequestStartVideoHandler* handler_)
	{

	}
	virtual void onActiveSpeakerVideoUserChanged(unsigned int userid)
	{

	}
	virtual void onActiveVideoUserChanged(unsigned int userid)
	{

	}
private:
	ZMeetingVideoWrap* owner_;
};

static ZMeetingVideoCtrlWrapEvent g_meeting_video_ctrl_event;


ZMeetingVideoWrap::ZMeetingVideoWrap()
{
	g_meeting_video_ctrl_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingVideoWrap::~ZMeetingVideoWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_video_ctrl_event.SetOwner(NULL);
}
void ZMeetingVideoWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetEvent(&g_meeting_video_ctrl_event);
}
void ZMeetingVideoWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().Uninit_Wrap();
}
void ZMeetingVideoWrap::SetSink(IZNativeSDKMeetingVideoWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingVideoWrap::MuteVideo()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().MuteVideo());
}
ZNSDKError ZMeetingVideoWrap::UnMuteVideo()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().UnmuteVideo());
}
ZNSDKError ZMeetingVideoWrap::PinVideo(bool bPin, bool bFirstView, ZoomSTRING userId)
{
	unsigned int sdk_userid = (unsigned int)_wtoi(userId.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().PinVideo(bPin, bFirstView, sdk_userid));
}
ZNSDKError ZMeetingVideoWrap::SpotlightVideo(bool bSpotlight, ZoomSTRING userId)
{
	unsigned int sdk_userid = (unsigned int)_wtoi(userId.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().SpotlightVideo(bSpotlight, sdk_userid));
}
ZNSDKError ZMeetingVideoWrap::HideOrShowNoVideoUserOnVideoWall(bool bHide)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingVideoController().HideOrShowNoVideoUserOnVideoWall(bHide));
}


void ZMeetingVideoWrap::onUserVideoStatusChange(ZoomSTRING userId, ZNVideoStatus status)
{
	m_pSink->onUserVideoStatusChange(userId, status);
}