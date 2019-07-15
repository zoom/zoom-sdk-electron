#pragma once
#include "zoom_native_sdk_wrap_core_def.h"

class IZNativeSDKMeetingAudioWrapSink
{
public:
	//
	virtual void onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList) = 0;
};
class ZMeetingAudioWrap
{
public:
	ZMeetingAudioWrap();
	virtual ~ZMeetingAudioWrap();
	void Init();
	void Uninit();
	void SetSink(IZNativeSDKMeetingAudioWrapSink* pSink);

	ZNSDKError MuteAudio(ZoomSTRING userid, bool allowUnmuteBySelf);
	ZNSDKError UnMuteAudio(ZoomSTRING userid);
	ZNSDKError JoinVoip();
	ZNSDKError LeaveVoip();

	//callback
	void onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList);

private:
	IZNativeSDKMeetingAudioWrapSink* m_pSink;

};
