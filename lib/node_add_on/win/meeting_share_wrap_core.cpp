
#include "../meeting_share_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_sharing_wrap.h"
#include "zoom_native_to_wrap.h"


extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
class ZMeetingShareCtrlWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingShareCtrlEvent
{
public:
	void SetOwner(ZMeetingShareWrap* obj) { owner_ = obj; }
	virtual void onSharingStatus(ZOOM_SDK_NAMESPACE::SharingStatus status, unsigned int userId)
	{
		if (owner_) {
			
				owner_->onSharingStatus(Map2WrapDefine(status), userId);
			}
		
	}
	virtual void onLockShareStatus(bool bLocked)
	{

	}
	virtual void onShareContentNotification(ZOOM_SDK_NAMESPACE::ShareInfo& shareInfo)
	{

	}
	virtual void onMultiShareSwitchToSingleShareNeedConfirm(ZOOM_SDK_NAMESPACE::IShareSwitchMultiToSingleConfirmHandler* handler_)
	{

	}
private:
	ZMeetingShareWrap* owner_;
};

static ZMeetingShareCtrlWrapEvent g_meeting_share_ctrl_event;

ZMeetingShareWrap::ZMeetingShareWrap()
{
	g_meeting_share_ctrl_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingShareWrap::~ZMeetingShareWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_share_ctrl_event.SetOwner(NULL);
}
void ZMeetingShareWrap::Init()
{
	

	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().SetEvent(&g_meeting_share_ctrl_event);
}
void ZMeetingShareWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().Uninit_Wrap();
}
ZNSDKError ZMeetingShareWrap::StartAppShare(ZoomSTRING hShareApp)
{
	if (!hShareApp.empty())
	{
		HWND sdk_share_app;
		swscanf_s(hShareApp.c_str(), L"%x", &sdk_share_app);
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().StartAppShare(sdk_share_app));
	}
	else
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().StartAppShare(NULL));
	}
	
}
ZNSDKError ZMeetingShareWrap::StartMonitorShare(ZoomSTRING monitorID)
{
	if (!monitorID.empty())
	{
		const wchar_t* sdk_monitorID = monitorID.c_str();
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().StartMonitorShare(sdk_monitorID));
	}

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().StartMonitorShare(NULL));
	
}
ZNSDKError ZMeetingShareWrap::StopShare()
{
	ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingShareController().StopShare();
	return Map2WrapDefine(err);
}
void ZMeetingShareWrap::onSharingStatus(ZNShareStatus status, unsigned int userId)
{
	if (m_pSink)
	{
		m_pSink->onSharingStatus(status, userId);
	}
	
}
void ZMeetingShareWrap::SetSink(ZNativeSDKMeetingShareWrapSink* pSink)
{
	m_pSink = pSink;
}