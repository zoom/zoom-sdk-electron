#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingRecordingWrap
{
public:
	ZMeetingRecordingWrap();
	virtual ~ZMeetingRecordingWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingRecordingWrapSink* pSink);

	ZNSDKError StartRecording(time_t& startTimestamp, ZoomSTRING recPath);
	ZNSDKError StopRecording(time_t& stopTimestamp);
	ZNSDKError CanStartRecording(bool cloud_recording, unsigned int userid);
	ZNSDKError CanAllowDisAllowLocalRecording();
	ZNSDKError StartCloudRecording();
	ZNSDKError StopCloudRecording();
	ZNSDKError IsSupportLocalRecording(unsigned int userid);
	ZNSDKError AllowLocalRecording(unsigned int userid);
	ZNSDKError DisAllowLocalRecording(unsigned int userid);
	ZNSDKError RequestCustomizedLocalRecordingSource();
	
	//callback
	void onRecording2MP4Done(bool bsuccess, int iResult, ZoomSTRING szPath);
	void onRecording2MP4Processing(int iPercentage);
	void onRecordingStatus(ZNRecordingStatus status);
	void onCloudRecordingStatus(ZNRecordingStatus status);
	void onRecordPriviligeChanged(bool bCanRec);
	void onCustomizedLocalRecordingSourceNotification();
private:
	ZNativeSDKMeetingRecordingWrapSink* m_pSink;

};
