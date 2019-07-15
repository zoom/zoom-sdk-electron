#pragma once
#include "../common_include.h"

BEGIN_ZOOM_SDK_NAMESPACE

class IMeetingLiveStreamItemImpl : public IMeetingLiveStreamItem
{
public:
	IMeetingLiveStreamItemImpl(const wchar_t* liveStreamURL, const wchar_t* liveStreamURLDescription);
	virtual ~IMeetingLiveStreamItemImpl() {};

	virtual void SetLiveStreamURL(const wchar_t* liveStreamURL);
	virtual const wchar_t* GetLiveStreamURL();
	virtual void SetLiveStreamURLDescription(const wchar_t* liveStreamURLDescription);
	virtual const wchar_t* GetLiveStreamURLDescription();

private:
	std::wstring _liveStreamURL;
	std::wstring _liveStreamURLDescription;
};


class IMeetingServiceWrap;
IMeetingLiveStreamController* InitIMeetingLiveStreamControllerFunc(IMeetingLiveStreamCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingLiveStreamControllerFunc(IMeetingLiveStreamController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingLiveStreamController, IMeetingLiveStreamCtrlEvent)
NORMAL_CLASS(IMeetingLiveStreamController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingLiveStreamController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingLiveStreamCtrlEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
// virtual SDKError CanStartLiveStream() = 0;
DEFINE_FUNC_0(CanStartLiveStream, SDKError)
// virtual SDKError StartLiveStream(IMeetingLiveStreamItem* item_) = 0;
DEFINE_FUNC_1(StartLiveStream, SDKError, IMeetingLiveStreamItem*, item_)
// virtual SDKError StartLiveStreamWithSteamingURL(const wchar_t* streamingURL, const wchar_t* streamingKey, const wchar_t* broadcastURL) = 0;
DEFINE_FUNC_3(StartLiveStreamWithSteamingURL, SDKError, const wchar_t*, streamingURL, const wchar_t*, streamingKey, const wchar_t*, broadcastURL)
// virtual SDKError StopLiveStream() = 0;
DEFINE_FUNC_0(StopLiveStream, SDKError)
// virtual IList<IMeetingLiveStreamItem* >* GetSupportLiveStreamURL() = 0;
DEFINE_FUNC_0(GetSupportLiveStreamURL, IList<IMeetingLiveStreamItem*>*)
// virtual LiveStreamStatus GetCurrentLiveStreamStatus() = 0;
DEFINE_FUNC_0(GetCurrentLiveStreamStatus, LiveStreamStatus)

// virtual void onLiveStreamStatusChange(LiveStreamStatus status) = 0;
CallBack_FUNC_1(onLiveStreamStatusChange, LiveStreamStatus, status)

END_CLASS_DEFINE(IMeetingLiveStreamController)
END_ZOOM_SDK_NAMESPACE
