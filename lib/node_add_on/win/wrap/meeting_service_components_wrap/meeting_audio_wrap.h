#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingAudioController* InitIMeetingAudioControllerFunc(IMeetingAudioCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingAudioControllerFunc(IMeetingAudioController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingAudioController, IMeetingAudioCtrlEvent)
NORMAL_CLASS(IMeetingAudioController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingAudioController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingAudioCtrlEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError JoinVoip() = 0;
DEFINE_FUNC_0(JoinVoip, SDKError)
//virtual SDKError LeaveVoip() = 0;
DEFINE_FUNC_0(LeaveVoip, SDKError)
//virtual SDKError MuteAudio(unsigned int userid, bool allowUnmuteBySelf = true) = 0;
DEFINE_FUNC_2(MuteAudio, SDKError, unsigned int, userid, bool, allowUnmuteBySelf)
//virtual SDKError UnMuteAudio(unsigned int userid) = 0;
DEFINE_FUNC_1(UnMuteAudio, SDKError, unsigned int, userid)
//virtual bool CanUnMuteBySelf() = 0;
DEFINE_FUNC_0(CanUnMuteBySelf, bool)
//virtual SDKError EnableMuteOnEntry(bool bEnable) = 0;
DEFINE_FUNC_1(EnableMuteOnEntry, SDKError, bool, bEnable)
//virtual SDKError EnablePlayChimeWhenEnterOrExit(bool bEnable) = 0;
DEFINE_FUNC_1(EnablePlayChimeWhenEnterOrExit, SDKError, bool, bEnable)

//virtual void onUserAudioStatusChange(IList<IUserAudioStatus* >* lstAudioStatusChange, const wchar_t* strAudioStatusList = NULL) = 0;
CallBack_FUNC_2(onUserAudioStatusChange, IList<IUserAudioStatus* >*, lstAudioStatusChange, const wchar_t*, strAudioStatusList)
//virtual void onUserActiveAudioChange(unsigned int userId) = 0;
CallBack_FUNC_1(onUserActiveAudioChange, IList<unsigned int>*, plstActiveAudio)
//virtual void onHostRequestStartAudio(IRequestStartAudioHandler* handler_) = 0;
CallBack_FUNC_1(onHostRequestStartAudio, IRequestStartAudioHandler*, handler_)

END_CLASS_DEFINE(IMeetingAudioController)
END_ZOOM_SDK_NAMESPACE