#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class IZNativeSDKMeetingVideoWrapSink
{
public:
	//
	virtual void onUserVideoStatusChange(ZoomSTRING userId, ZNVideoStatus status) = 0;
};
class ZMeetingVideoWrap
{
public:
	ZMeetingVideoWrap();
	virtual ~ZMeetingVideoWrap();
	void Init();
	void Uninit();
	void SetSink(IZNativeSDKMeetingVideoWrapSink* pSink);

	ZNSDKError MuteVideo();
	ZNSDKError UnMuteVideo();
	ZNSDKError PinVideo(bool bPin, bool bFirstView, ZoomSTRING userId);
	ZNSDKError SpotlightVideo(bool bSpotlight, ZoomSTRING userId);
	ZNSDKError HideOrShowNoVideoUserOnVideoWall(bool bHide);

	//callback
	void onUserVideoStatusChange(ZoomSTRING userId, ZNVideoStatus status);

private:
	IZNativeSDKMeetingVideoWrapSink* m_pSink;

};
