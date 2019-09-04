#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingVideoWrap
{
public:
	ZMeetingVideoWrap();
	virtual ~ZMeetingVideoWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingVideoWrapSink* pSink);

	ZNSDKError MuteVideo(unsigned int userId);
	ZNSDKError UnMuteVideo(unsigned int userId);
	ZNSDKError PinVideo(bool bPin, bool bFirstView, unsigned int userId);
	ZNSDKError SpotlightVideo(bool bSpotlight, unsigned int userId);
	ZNSDKError HideOrShowNoVideoUserOnVideoWall(bool bHide);

	//callback
	void onUserVideoStatusChange(unsigned int userId, ZNVideoStatus status);
	void onActiveSpeakerVideoUserChanged(unsigned int userid);
	void onActiveVideoUserChanged(unsigned int userid);

private:
	ZNativeSDKMeetingVideoWrapSink* m_pSink;

};
