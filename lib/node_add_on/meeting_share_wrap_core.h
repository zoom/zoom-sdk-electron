#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingShareWrap
{
public:
	ZMeetingShareWrap();
	virtual ~ZMeetingShareWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingShareWrapSink* pSink);

	void onSharingStatus(ZNShareStatus status, unsigned int userId);

	ZNSDKError StartAppShare(ZoomSTRING hShareApp);
	ZNSDKError StartMonitorShare(ZoomSTRING monitorID);
	ZNSDKError StopShare();
private:
	ZNativeSDKMeetingShareWrapSink* m_pSink;
};
