#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingRecordingController* InitIMeetingRecordingControllerFunc(IMeetingRecordingCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingRecordingControllerFunc(IMeetingRecordingController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingRecordingController, IMeetingRecordingCtrlEvent)
NORMAL_CLASS(IMeetingRecordingController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingRecordingController, IMeetingServiceWrap)

virtual SDKError SetEvent(IMeetingRecordingCtrlEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError StartRecording(time_t& startTimestamp, wchar_t* recPath) = 0;
DEFINE_FUNC_2(StartRecording, SDKError, time_t&, startTimestamp, wchar_t*, recPath)
//virtual SDKError StopRecording(time_t& stopTimestamp) = 0;
DEFINE_FUNC_1(StopRecording, SDKError, time_t&, stopTimestamp)

//virtual SDKError CanStartRecording(bool cloud_recording, unsigned int userid) = 0;
DEFINE_FUNC_2(CanStartRecording, SDKError, bool, cloud_recording, unsigned int, userid)
//virtual SDKError CanAllowDisAllowLocalRecording() = 0;
DEFINE_FUNC_0(CanAllowDisAllowLocalRecording, SDKError)
//virtual SDKError StartCloudRecording() = 0;
DEFINE_FUNC_0(StartCloudRecording, SDKError)
//virtual SDKError StopCloudRecording() = 0;
DEFINE_FUNC_0(StopCloudRecording, SDKError)
//virtual SDKError IsSupportLocalRecording(unsigned int userid) = 0;
DEFINE_FUNC_1(IsSupportLocalRecording, SDKError, unsigned int, userid)
//virtual SDKError AllowLocalRecording(unsigned int userid) = 0;
DEFINE_FUNC_1(AllowLocalRecording, SDKError, unsigned int, userid)
//virtual SDKError DisAllowLocalRecording(unsigned int userid) = 0;
DEFINE_FUNC_1(DisAllowLocalRecording, SDKError, unsigned int, userid)
//virtual SDKError RequestCustomizedLocalRecordingSource() = 0;
DEFINE_FUNC_0(RequestCustomizedLocalRecordingSource, SDKError)

//virtual void onRecording2MP4Done(bool bsuccess, int iResult, const wchar_t* szPath) = 0;
CallBack_FUNC_3(onRecording2MP4Done, bool, bsuccess, int, iResult, const wchar_t*, szPath)
//virtual void onRecording2MP4Processing(int iPercentage) = 0;
CallBack_FUNC_1(onRecording2MP4Processing, int, iPercentage)
//virtual void onRecordingStatus(RecordingStatus status) = 0;
CallBack_FUNC_1(onRecordingStatus, RecordingStatus, status)
//virtual void onCloudRecordingStatus(RecordingStatus status) = 0;
CallBack_FUNC_1(onCloudRecordingStatus, RecordingStatus, status)
//virtual void onRecordPriviligeChanged(bool bCanRec) = 0;
CallBack_FUNC_1(onRecordPriviligeChanged, bool, bCanRec)
//virtual void onCustomizedLocalRecordingSourceNotification(ICustomizedLocalRecordingLayoutHelper* layout_helper) = 0;
CallBack_FUNC_1(onCustomizedLocalRecordingSourceNotification, ICustomizedLocalRecordingLayoutHelper*, layout_helper)
END_CLASS_DEFINE(IMeetingRecordingController)
END_ZOOM_SDK_NAMESPACE