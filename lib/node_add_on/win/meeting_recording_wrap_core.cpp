
#include "../meeting_recording_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_recording_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingRecordingWrap::ZMeetingRecordingWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingRecordingCtrlWrapEvent.SetOwner(this);
	m_pSink = NULL;
}
ZMeetingRecordingWrap::~ZMeetingRecordingWrap()
{
	Uninit();
	m_pSink = NULL;
	SDKEventWrapMgr::GetInst().m_meetingRecordingCtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingRecordingWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingRecordingCtrlWrapEvent);
}
void ZMeetingRecordingWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().Uninit_Wrap();
}
void ZMeetingRecordingWrap::SetSink(ZNativeSDKMeetingRecordingWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingRecordingWrap::StartRecording(time_t& startTimestamp, ZoomSTRING recPath)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().StartRecording(startTimestamp, (wchar_t*)(recPath.c_str())));
}
ZNSDKError ZMeetingRecordingWrap::StopRecording(time_t& stopTimestamp)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().StopRecording(stopTimestamp));
}
ZNSDKError ZMeetingRecordingWrap::CanStartRecording(bool cloud_recording, unsigned int userid)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().CanStartRecording(cloud_recording, userid));
}
ZNSDKError ZMeetingRecordingWrap::CanAllowDisAllowLocalRecording()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().CanAllowDisAllowLocalRecording());
}
ZNSDKError ZMeetingRecordingWrap::StartCloudRecording()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().StartCloudRecording());
}
ZNSDKError ZMeetingRecordingWrap::StopCloudRecording()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().StopCloudRecording());
}
ZNSDKError ZMeetingRecordingWrap::IsSupportLocalRecording(unsigned int userid)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().IsSupportLocalRecording(userid));
}
ZNSDKError ZMeetingRecordingWrap::AllowLocalRecording(unsigned int userid)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().AllowLocalRecording(userid));
}
ZNSDKError ZMeetingRecordingWrap::DisAllowLocalRecording(unsigned int userid)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().DisAllowLocalRecording(userid));
}
ZNSDKError ZMeetingRecordingWrap::RequestCustomizedLocalRecordingSource()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingRecordingController().RequestCustomizedLocalRecordingSource());
}
void ZMeetingRecordingWrap::onRecording2MP4Done(bool bsuccess, int iResult, ZoomSTRING szPath)
{
	if (m_pSink)
	{
		m_pSink->onRecording2MP4Done(bsuccess, iResult, szPath);
	}
}
void ZMeetingRecordingWrap::onRecording2MP4Processing(int iPercentage)
{
	if (m_pSink)
	{
		m_pSink->onRecording2MP4Processing(iPercentage);
	}
}
void ZMeetingRecordingWrap::onRecordingStatus(ZNRecordingStatus status)
{
	if (m_pSink)
	{
		m_pSink->onRecordingStatus(status);
	}
}
void ZMeetingRecordingWrap::onCloudRecordingStatus(ZNRecordingStatus status)
{
	if (m_pSink)
	{
		m_pSink->onCloudRecordingStatus(status);
	}
}

void ZMeetingRecordingWrap::onRecordPriviligeChanged(bool bCanRec)
{
	if (m_pSink)
	{
		m_pSink->onRecordPriviligeChanged(bCanRec);
	}
}
void ZMeetingRecordingWrap::onCustomizedLocalRecordingSourceNotification()
{
	if (m_pSink)
	{
		m_pSink->onCustomizedLocalRecordingSourceNotification();
	}
}