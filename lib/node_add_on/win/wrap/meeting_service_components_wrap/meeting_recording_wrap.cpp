#include "meeting_recording_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingRecordingController* InitIMeetingRecordingControllerFunc(IMeetingRecordingCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingRecordingController* pObj = pOwner->GetSDKObj()->GetMeetingRecordingController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingRecordingControllerFunc(IMeetingRecordingController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError StartRecording(time_t& startTimestamp, wchar_t* recPath) = 0;
IMPL_FUNC_2(IMeetingRecordingController, StartRecording, SDKError, time_t&, startTimestamp, wchar_t*, recPath, SDKERR_UNINITIALIZE)
//virtual SDKError StopRecording(time_t& stopTimestamp) = 0;
IMPL_FUNC_1(IMeetingRecordingController, StopRecording, SDKError, time_t&, stopTimestamp, SDKERR_UNINITIALIZE)
//virtual SDKError CanStartRecording(bool cloud_recording, unsigned int userid) = 0;
IMPL_FUNC_2(IMeetingRecordingController, CanStartRecording, SDKError, bool, cloud_recording, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError CanAllowDisAllowLocalRecording() = 0;
IMPL_FUNC_0(IMeetingRecordingController, CanAllowDisAllowLocalRecording, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StartCloudRecording() = 0;
IMPL_FUNC_0(IMeetingRecordingController, StartCloudRecording, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError StopCloudRecording() = 0;
IMPL_FUNC_0(IMeetingRecordingController, StopCloudRecording, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError IsSupportLocalRecording(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingRecordingController, IsSupportLocalRecording, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError AllowLocalRecording(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingRecordingController, AllowLocalRecording, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError DisAllowLocalRecording(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingRecordingController, DisAllowLocalRecording, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual SDKError RequestCustomizedLocalRecordingSource() = 0;
IMPL_FUNC_0(IMeetingRecordingController, RequestCustomizedLocalRecordingSource, SDKError, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE