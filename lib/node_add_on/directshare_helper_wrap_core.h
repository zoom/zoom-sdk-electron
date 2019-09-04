#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZDirectShareHelperWrap
{
public:
	ZDirectShareHelperWrap();
	virtual ~ZDirectShareHelperWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKDirectShareHelperWrapSink* pSink);

	ZNSDKError CanStartDirectShare();
	bool IsDirectShareInProgress();
	ZNSDKError StartDirectShare();
	ZNSDKError StopDirectShare();
	
	ZNSDKError TryWithMeetingNumber(unsigned long long meetingNumber);
	ZNSDKError TryWithPairingCode(ZoomSTRING pairingCode);
	ZNSDKError Cancel();
	

	//callback
	void OnDirectShareStatusUpdate(ZNDirectShareStatus status);
	
private:
	ZNativeSDKDirectShareHelperWrapSink* m_pSink;
	

};
