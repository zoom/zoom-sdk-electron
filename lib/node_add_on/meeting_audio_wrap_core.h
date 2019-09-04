#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingAudioWrap
{
public:
	ZMeetingAudioWrap();
	virtual ~ZMeetingAudioWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingAudioWrapSink* pSink);

	ZNSDKError MuteAudio(unsigned int userid, bool allowUnmuteBySelf);
	ZNSDKError UnMuteAudio(unsigned int userid);
	ZNSDKError JoinVoip();
	ZNSDKError LeaveVoip();

	//callback
	void onUserAudioStatusChange(ZNList<ZNUserAudioStatus> lstAudioStatusChange, ZoomSTRING strAudioStatusList);
	void onUserActiveAudioChange(ZNList<unsigned int > lstActiveAudio);

private:
	ZNativeSDKMeetingAudioWrapSink* m_pSink;

};
