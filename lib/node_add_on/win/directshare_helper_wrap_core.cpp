
#include "../directshare_helper_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/directshare_helper_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IAuthServiceWrap& g_auth_service_wrap;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZDirectShareViaMeetingIDOrPairingCodeHandler
{
public:
	static ZDirectShareViaMeetingIDOrPairingCodeHandler& GetInst()
	{
		static ZDirectShareViaMeetingIDOrPairingCodeHandler inst;
		return inst;
	}
	void SetHandler(ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler *handler)
	{
		m_pHandler = handler;
	}

	ZNSDKError TryWithMeetingNumber(unsigned long long meetingNumber)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->TryWithMeetingNumber(meetingNumber);
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError TryWithPairingCode(ZoomSTRING paringCode)
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->TryWithPairingCode(paringCode.c_str());
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}

	ZNSDKError Cancel()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->Cancel();
		m_pHandler = NULL;
		return Map2WrapDefine(err);
	}
private:
	ZDirectShareViaMeetingIDOrPairingCodeHandler():m_pHandler(NULL){}
	ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler* m_pHandler;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ZDirectShareHelperWrapEvent : public ZOOM_SDK_NAMESPACE::IDirectShareServiceHelperEvent
{
public:
	void SetOwner(ZDirectShareHelperWrap* obj) { owner_ = obj;}
	virtual void OnDirectShareStatusUpdate(ZOOM_SDK_NAMESPACE::DirectShareStatus status, ZOOM_SDK_NAMESPACE::IDirectShareViaMeetingIDOrPairingCodeHandler* handler)
	{
		
		if (owner_) {
			
			if ((status == ZOOM_SDK_NAMESPACE::DirectShare_Need_MeetingID_Or_PairingCode) || (status == ZOOM_SDK_NAMESPACE::DirectShare_WrongMeetingID_Or_SharingKey) )
			{
				ZDirectShareViaMeetingIDOrPairingCodeHandler::GetInst().SetHandler(handler);
			}
			owner_->OnDirectShareStatusUpdate(Map2WrapDefine(status));
		}
	}
private:
	ZDirectShareHelperWrap* owner_;
};

static ZDirectShareHelperWrapEvent g_direct_share_helper_event;



ZDirectShareHelperWrap::ZDirectShareHelperWrap()
{
	g_direct_share_helper_event.SetOwner(this);
	m_pSink = NULL;
	
}
ZDirectShareHelperWrap::~ZDirectShareHelperWrap()
{
	Uninit();
	m_pSink = NULL;
	
	g_direct_share_helper_event.SetOwner(NULL);
}
void ZDirectShareHelperWrap::Init()
{
	
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().SetEvent(&g_direct_share_helper_event);
}
void ZDirectShareHelperWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().SetEvent(NULL);
	
}
void ZDirectShareHelperWrap::SetSink(ZNativeSDKDirectShareHelperWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZDirectShareHelperWrap::CanStartDirectShare()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().CanStartDirectShare());
}
bool ZDirectShareHelperWrap::IsDirectShareInProgress()
{
	return ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().IsDirectShareInProgress();
}
ZNSDKError ZDirectShareHelperWrap::StartDirectShare()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().StartDirectShare());
}
ZNSDKError ZDirectShareHelperWrap::StopDirectShare()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().StopDirectShare());
}
void ZDirectShareHelperWrap::OnDirectShareStatusUpdate(ZNDirectShareStatus status)
{
	if (m_pSink)
		m_pSink->OnDirectShareStatusUpdate(status);
}

ZNSDKError ZDirectShareHelperWrap::TryWithMeetingNumber(unsigned long long meetingNumber)
{
	return ZDirectShareViaMeetingIDOrPairingCodeHandler::GetInst().TryWithMeetingNumber(meetingNumber);
}
ZNSDKError ZDirectShareHelperWrap::TryWithPairingCode(ZoomSTRING pairingCode)
{
	return ZDirectShareViaMeetingIDOrPairingCodeHandler::GetInst().TryWithPairingCode(pairingCode);
}
ZNSDKError ZDirectShareHelperWrap::Cancel()
{
	return ZDirectShareViaMeetingIDOrPairingCodeHandler::GetInst().Cancel();
}

