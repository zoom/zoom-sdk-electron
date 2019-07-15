#include "meeting_live_stream_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE

IMeetingLiveStreamItemImpl::IMeetingLiveStreamItemImpl(const wchar_t* liveStreamURL, const wchar_t* liveStreamURLDescription)
{
	_liveStreamURL = liveStreamURL;
	_liveStreamURLDescription = liveStreamURLDescription;
}

void IMeetingLiveStreamItemImpl::SetLiveStreamURL(const wchar_t* liveStreamURL)
{
	_liveStreamURL = liveStreamURL;
}

const wchar_t* IMeetingLiveStreamItemImpl::GetLiveStreamURL()
{
	return _liveStreamURL.c_str();
}

void IMeetingLiveStreamItemImpl::SetLiveStreamURLDescription(const wchar_t* liveStreamURLDescription)
{
	_liveStreamURLDescription = liveStreamURLDescription;
}

const wchar_t* IMeetingLiveStreamItemImpl::GetLiveStreamURLDescription()
{
	return _liveStreamURLDescription.c_str();
}

IMeetingLiveStreamController* InitIMeetingLiveStreamControllerFunc(IMeetingLiveStreamCtrlEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingLiveStreamController* pObj = pOwner->GetSDKObj()->GetMeetingLiveStreamController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingLiveStreamControllerFunc(IMeetingLiveStreamController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

// virtual SDKError CanStartLiveStream() = 0;
IMPL_FUNC_0(IMeetingLiveStreamController, CanStartLiveStream, SDKError, SDKERR_UNINITIALIZE)
// virtual SDKError StartLiveStream(IMeetingLiveStreamItem* item_) = 0;
IMPL_FUNC_1(IMeetingLiveStreamController, StartLiveStream, SDKError, IMeetingLiveStreamItem*, item_, SDKERR_UNINITIALIZE)
// virtual SDKError StartLiveStreamWithSteamingURL(const wchar_t* streamingURL, const wchar_t* streamingKey, const wchar_t* broadcastURL) = 0;
IMPL_FUNC_3(IMeetingLiveStreamController, StartLiveStreamWithSteamingURL, SDKError, const wchar_t*, streamingURL, const wchar_t*, streamingKey, const wchar_t*, broadcastURL, SDKERR_UNINITIALIZE)
// virtual SDKError StopLiveStream() = 0;
IMPL_FUNC_0(IMeetingLiveStreamController, StopLiveStream, SDKError, SDKERR_UNINITIALIZE)
// virtual IList<IMeetingLiveStreamItem* >* GetSupportLiveStreamURL() = 0;
IMPL_FUNC_0(IMeetingLiveStreamController, GetSupportLiveStreamURL, IList<IMeetingLiveStreamItem*>*, NULL)
// virtual LiveStreamStatus GetCurrentLiveStreamStatus() = 0;
IMPL_FUNC_0(IMeetingLiveStreamController, GetCurrentLiveStreamStatus, LiveStreamStatus, LiveStreamStatus_None)

END_ZOOM_SDK_NAMESPACE
