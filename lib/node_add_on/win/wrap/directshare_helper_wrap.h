#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IAuthServiceWrap;
IDirectShareServiceHelper* InitIDirectShareServiceHelperFunc(IDirectShareServiceHelperEvent* pEvent, IAuthServiceWrap* pOwner);
void UninitIDirectShareServiceHelperFunc(IDirectShareServiceHelper* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IDirectShareServiceHelper, IDirectShareServiceHelperEvent)
NORMAL_CLASS(IDirectShareServiceHelper)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IDirectShareServiceHelper, IAuthServiceWrap)
virtual SDKError SetEvent(IDirectShareServiceHelperEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual SDKError CanStartDirectShare() = 0;
DEFINE_FUNC_0(CanStartDirectShare, SDKError)
//virtual bool	 IsDirectShareInProgress() = 0;
DEFINE_FUNC_0(IsDirectShareInProgress, bool)
//virtual SDKError StartDirectShare() = 0;
DEFINE_FUNC_0(StartDirectShare, SDKError)
//virtual SDKError StopDirectShare() = 0;
DEFINE_FUNC_0(StopDirectShare, SDKError)

//virtual void OnDirectShareStatusUpdate(DirectShareStatus status, IDirectShareViaMeetingIDOrPairingCodeHandler* handler) = 0;
CallBack_FUNC_2(OnDirectShareStatusUpdate, DirectShareStatus, status, IDirectShareViaMeetingIDOrPairingCodeHandler*, handler)

END_CLASS_DEFINE(IDirectShareServiceHelper)
END_ZOOM_SDK_NAMESPACE