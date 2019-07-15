#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class ZMeetingShareWrap
{
public:
	ZMeetingShareWrap();
	virtual ~ZMeetingShareWrap();
	void Init();
	void Uninit();

	ZNSDKError StartAppShare(ZoomSTRING hShareApp);
	ZNSDKError StartMonitorShare(ZoomSTRING monitorID);
	ZNSDKError StopShare();
};
