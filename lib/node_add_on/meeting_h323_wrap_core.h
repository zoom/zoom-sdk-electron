#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class IZNativeSDKMeetingH323WrapSink
{
public:
	//
	virtual void onH323CalloutStatusNotify(ZNH323CalloutStatus status) = 0;
};
class ZMeetingH323Wrap
{
public:
	ZMeetingH323Wrap();
	virtual ~ZMeetingH323Wrap();
	void Init();
	void Uninit();
	void SetSink(IZNativeSDKMeetingH323WrapSink* pSink);

	ZNSDKError CallOutH323(ZoomSTRING deviceName, ZoomSTRING deviceIP, ZoomSTRING device164Num, ZNH323DeviceType deviceType);
	ZNSDKError CancelCallOutH323();
	ZNList<ZoomSTRING> GetH323Address();
	ZoomSTRING GetH323Password();
	ZNList<ZNH323DeviecInfo> GetCalloutH323DviceList();

	//callback
	void onH323CalloutStatusNotify(ZNH323CalloutStatus status);

private:
	IZNativeSDKMeetingH323WrapSink* m_pSink;

};
