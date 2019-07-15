#include "meeting_audio_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingAudioController* InitIMeetingAudioControllerFunc(IMeetingAudioCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingAudioController* pObj = pOwner->GetSDKObj()->GetMeetingAudioController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingAudioControllerFunc(IMeetingAudioController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError JoinVoip() = 0;
IMPL_FUNC_0(IMeetingAudioController, JoinVoip, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError LeaveVoip() = 0;
IMPL_FUNC_0(IMeetingAudioController, LeaveVoip, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError MuteAudio(unsigned int userid, bool allowUnmuteBySelf = true) = 0;
IMPL_FUNC_2(IMeetingAudioController, MuteAudio, SDKError, unsigned int, userid, bool, allowUnmuteBySelf, SDKERR_UNINITIALIZE)
//virtual SDKError UnMuteAudio(unsigned int userid) = 0;
IMPL_FUNC_1(IMeetingAudioController, UnMuteAudio, SDKError, unsigned int, userid, SDKERR_UNINITIALIZE)
//virtual bool CanUnMuteBySelf() = 0;
IMPL_FUNC_0(IMeetingAudioController, CanUnMuteBySelf, bool, false)
//virtual SDKError EnableMuteOnEntry(bool bEnable) = 0;
IMPL_FUNC_1(IMeetingAudioController, EnableMuteOnEntry, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
//virtual SDKError EnablePlayChimeWhenEnterOrExit(bool bEnable) = 0;
IMPL_FUNC_1(IMeetingAudioController, EnablePlayChimeWhenEnterOrExit, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE