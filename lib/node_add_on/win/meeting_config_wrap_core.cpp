
#include "../meeting_config_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_configuration_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
class ZMeetingConfigCtrlWrapFreeMeetingEvent : public ZOOM_SDK_NAMESPACE::IMeetingConfigurationEvent
{
public:
	void SetOwner(ZMeetingConfigWrap* obj) { owner_ = obj; }
	virtual void onFreeMeetingRemainTime(unsigned int leftTime)
	{
	}
	virtual void onFreeMeetingRemainTimeStopCountDown()
	{
	}
	virtual void onFreeMeetingEndingReminderNotification(ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler* handler_)
	{
	}
	virtual void onFreeMeetingNeedToUpgrade(ZOOM_SDK_NAMESPACE::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType type_, const wchar_t* gift_url)
	{
		if (owner_) {
			ZoomSTRING zn_gift_url = gift_url;
			owner_->onFreeMeetingNeedToUpgrade(Map2WrapDefine(type_), zn_gift_url);
		}
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStart()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToGiftFreeTrialStart();
		}
	}
	virtual void onFreeMeetingUpgradeToGiftFreeTrialStop()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToGiftFreeTrialStop();
		}
	}
	virtual void onFreeMeetingUpgradeToProMeeting()
	{
		if (owner_) {
			owner_->onFreeMeetingUpgradeToProMeeting();
		}
	}
	virtual void onInputMeetingPasswordAndScreenNameNotification(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler* pHandler)
	{

	}
	virtual void onAirPlayInstructionWndNotification(bool bShow, const wchar_t* airhostName)
	{

	}
	virtual void onWebinarNeedRegisterNotification(ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler* handler_)
	{

	}
	virtual void onEndOtherMeetingToJoinMeetingNotification(ZOOM_SDK_NAMESPACE::IEndOtherMeetingToJoinMeetingHandler* handler_)
	{

	}
private:
	ZMeetingConfigWrap* owner_;
};

static ZMeetingConfigCtrlWrapFreeMeetingEvent g_meeting_config_ctrl_event;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class FreeMeetingReminderHandler
{
public:
	static FreeMeetingReminderHandler& GetInst()
	{
		static FreeMeetingReminderHandler inst;
		return inst;
	}
	ZNFreeMeetingEndingReminderType GetType()
	{
		ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminderType winDefinedType = ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_NONE;
		int nMapToMACDefinedType = 5;
		if (m_pHandler)
			winDefinedType = m_pHandler->GetType();
		return Map2WrapDefine(winDefinedType);
	}

	ZOOM_SDK_NAMESPACE::SDKError UpgradeMeeting()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->UpgradeMeeting();
		m_pHandler = NULL;
		return err;
	}

	ZOOM_SDK_NAMESPACE::SDKError UpgradeAccount()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->UpgradeAccount();
		m_pHandler = NULL;
		return err;
	}

	ZOOM_SDK_NAMESPACE::SDKError Cancel()
	{
		ZOOM_SDK_NAMESPACE::SDKError err = ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE;
		if (m_pHandler)
			err = m_pHandler->Cancel();
		m_pHandler = NULL;
		return err;
	}
private:
	FreeMeetingReminderHandler() {}
	ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler* m_pHandler;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ZMeetingConfigWrap::ZMeetingConfigWrap()
{
	g_meeting_config_ctrl_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingConfigWrap::~ZMeetingConfigWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_config_ctrl_event.SetOwner(NULL);
}
void ZMeetingConfigWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetEvent(&g_meeting_config_ctrl_event);
	
}
void ZMeetingConfigWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().Uninit_Wrap();
}
void ZMeetingConfigWrap::SetSink(IZNativeSDKMeetingConfigWrapFreeMeetingSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingConfigWrap::EnableInviteButtonOnMeetingUI(bool bEnable)
{
	ZNSDKError zn_err = ZNSDKERR_SUCCESS;
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableInviteButtonOnMeetingUI(bEnable);
	return zn_err;
}
void ZMeetingConfigWrap::SetFloatVideoPos(ZNWndPosition position)
{
	ZOOM_SDK_NAMESPACE::WndPosition sdk_pos;
	swscanf_s(position.z_hParent.c_str(), L"%x", &sdk_pos.hParent);
	swscanf_s(position.z_hSelfWnd.c_str(), L"%x", &sdk_pos.hSelfWnd);
	sdk_pos.left = _wtoi(position.z_left.c_str());
	sdk_pos.top = _wtoi(position.z_top.c_str());
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetFloatVideoPos(sdk_pos);
}
void ZMeetingConfigWrap::SetBottomFloatToolbarWndVisibility(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetBottomFloatToolbarWndVisibility(bShow);
}
void ZMeetingConfigWrap::SetSharingToolbarVisibility(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetSharingToolbarVisibility(bShow);
}
void ZMeetingConfigWrap::SetDirectShareMonitorID(ZoomSTRING monitorID)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetDirectShareMonitorID(monitorID.c_str());
}
void ZMeetingConfigWrap::SetMeetingUIPos(ZNWndPosition position)
{
	ZOOM_SDK_NAMESPACE::WndPosition sdk_pos;
	swscanf_s(position.z_hParent.c_str(), L"%x", &sdk_pos.hParent);
	swscanf_s(position.z_hSelfWnd.c_str(), L"%x", &sdk_pos.hSelfWnd);
	sdk_pos.left = _wtoi(position.z_left.c_str());
	sdk_pos.top = _wtoi(position.z_top.c_str());
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetMeetingUIPos(sdk_pos);
}
void ZMeetingConfigWrap::DisableWaitingForHostDialog(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisableWaitingForHostDialog(bDisable);
}
void ZMeetingConfigWrap::HideMeetingInfoFromMeetingUITitle(bool bHide)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().HideMeetingInfoFromMeetingUITitle(bHide);
}
void ZMeetingConfigWrap::SetMeetingIDForMeetingUITitle(ZoomSTRING meetingNumber)
{
	UINT64	sdk_meetingNumber = _wtoi64(meetingNumber.c_str());
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetMeetingIDForMeetingUITitle(sdk_meetingNumber);
}
void ZMeetingConfigWrap::DisablePopupMeetingWrongPSWDlg(bool bDisable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().DisablePopupMeetingWrongPSWDlg(bDisable);
}
void ZMeetingConfigWrap::EnableAutoEndOtherMeetingWhenStartMeeting(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableAutoEndOtherMeetingWhenStartMeeting(bEnable);
}
void ZMeetingConfigWrap::EnableLButtonDBClick4SwitchFullScreenMode(bool bEnable)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().EnableLButtonDBClick4SwitchFullScreenMode(bEnable);
}
void ZMeetingConfigWrap::SetFloatVideoWndVisibility(bool bShow)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().SetFloatVideoWndVisibility(bShow);
}
void ZMeetingConfigWrap::PrePopulateWebinarRegistrationInfo(ZoomSTRING email, ZoomSTRING userName)
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingConfiguration().PrePopulateWebinarRegistrationInfo(email.c_str(), userName.c_str());
}
ZNFreeMeetingEndingReminderType ZMeetingConfigWrap::GetReminderType()
{
	return  FreeMeetingReminderHandler::GetInst().GetType();
}
ZNSDKError ZMeetingConfigWrap::UpgradeMeeting()
{
	return  Map2WrapDefine(FreeMeetingReminderHandler::GetInst().UpgradeMeeting());
}
ZNSDKError ZMeetingConfigWrap::UpgradeAccount()
{
	return  Map2WrapDefine(FreeMeetingReminderHandler::GetInst().UpgradeAccount());
}
ZNSDKError ZMeetingConfigWrap::CancelUpdate()
{
	return  Map2WrapDefine(FreeMeetingReminderHandler::GetInst().Cancel());
}

void ZMeetingConfigWrap::onFreeMeetingNeedToUpgrade(ZNFreeMeetingNeedUpgradeType type, ZoomSTRING gift_url)
{
	if (m_pSink)
		m_pSink->onFreeMeetingNeedToUpgrade(type, gift_url);
}
void ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStart()
{
	if (m_pSink)
		m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStart();
}
void ZMeetingConfigWrap::onFreeMeetingUpgradeToGiftFreeTrialStop()
{
	if (m_pSink)
		m_pSink->onFreeMeetingUpgradeToGiftFreeTrialStop();
}
void ZMeetingConfigWrap::onFreeMeetingUpgradeToProMeeting()
{
	if (m_pSink)
		m_pSink->onFreeMeetingUpgradeToProMeeting();
}