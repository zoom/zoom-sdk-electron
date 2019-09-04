#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZPremeetingServiceWrap
{
public:
	ZPremeetingServiceWrap();
	virtual ~ZPremeetingServiceWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKPreMeetingWrapSink* pSink);

	ZNSDKError ScheduleMeeting(ZNWndPosition wndParam);
	ZNSDKError ScheduleMeeting();
	ZNSDKError EditMeeting(unsigned long long meetingUniqueID);
	ZNSDKError EditMeeting(ZNWndPosition wndParam, unsigned long long meetingUniqueID);
	ZNSDKError ListMeeting();
	ZNSDKError DeleteMeeting(unsigned long long meetingUniqueID);

	

	//callback
	void onScheduleOrEditMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID);
	void onListMeeting(ZNPremeetingAPIResult result, ZNList<unsigned long long> lst_meeting_list);
	void onDeleteMeeting(ZNPremeetingAPIResult result);
	
private:
	ZNativeSDKPreMeetingWrapSink* m_pSink;
	

};
