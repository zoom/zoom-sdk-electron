
#include "../directshare_helper_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/directshare_helper_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"

extern ZOOM_SDK_NAMESPACE::IAuthServiceWrap& g_auth_service_wrap;

ZDirectShareHelperWrap::ZDirectShareHelperWrap()
{
	SDKEventWrapMgr::GetInst().m_directShareHelperWrapEvent.SetOwner(this);
	m_pSink = NULL;
	
}
ZDirectShareHelperWrap::~ZDirectShareHelperWrap()
{
	Uninit();
	m_pSink = NULL;
	
	SDKEventWrapMgr::GetInst().m_directShareHelperWrapEvent.SetOwner(NULL);
}
void ZDirectShareHelperWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().Init_Wrap(&g_auth_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().SetEvent(&SDKEventWrapMgr::GetInst().m_directShareHelperWrapEvent);
}
void ZDirectShareHelperWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAuthServiceWrap().T_GetDirectShareServiceHeler().Uninit_Wrap();
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

