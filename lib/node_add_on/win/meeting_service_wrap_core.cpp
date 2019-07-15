
#include "../meeting_service_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_ui_ctrl_wrap.h"
#include "zoom_native_to_wrap.h"


ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
class ZMeetingServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingServiceEvent
{
public:
	void SetOwner(ZMeetingServiceWrap* obj) { owner_ = obj; }
	virtual void onMeetingStatusChanged(ZOOM_SDK_NAMESPACE::MeetingStatus status, int iResult)
	{
		if (owner_) {
			owner_->onMeetingStatusChanged(Map2WrapDefine(status), iResult);
		}
	}
	virtual void onMeetingStatisticsWarningNotification(ZOOM_SDK_NAMESPACE::StatisticsWarningType type)
	{

	}
	virtual void onMeetingSecureKeyNotification(const char* key, int len, ZOOM_SDK_NAMESPACE::IMeetingExternalSecureKeyHandler* pHandler)
	{

	}
	virtual void onMeetingParameterNotification(const ZOOM_SDK_NAMESPACE::MeetingParameter* pMeetingParam)
	{

	}
private:
	ZMeetingServiceWrap* owner_;
};

static ZMeetingServiceWrapEvent g_meeting_event;
ZMeetingServiceWrap::ZMeetingServiceWrap()
{
	g_meeting_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingServiceWrap::~ZMeetingServiceWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_event.SetOwner(NULL);
}
void ZMeetingServiceWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Init_Wrap();
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().SetEvent(&g_meeting_event);
	m_meeting_ui_ctrl.Init();
	m_meeting_annotation.Init();
	m_meeting_audio_ctrl.Init();
	m_meeting_video_ctrl.Init();
	m_meeting_participants_ctrl.Init();
	m_meeting_share_ctrl.Init();
	m_meeting_h323_ctrl.Init();
	m_meeting_config_ctrl.Init();
	
}
void ZMeetingServiceWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Uninit_Wrap();
}
void ZMeetingServiceWrap::SetSink(IZNativeSDKMeetingWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingServiceWrap::Start(ZNStartParam startParam)
{
	ZOOM_SDK_NAMESPACE::StartParam param;
	param.userType = Map2SDKDefine(startParam.userType);
	param.param.normaluserStart.meetingNumber = _wtoi64(startParam.meetingNumber.c_str());
	swscanf_s(startParam.hDirectShareAppWnd.c_str(), L"%x", &param.param.normaluserStart.hDirectShareAppWnd);
	param.param.normaluserStart.participantId = startParam.participantId.c_str();
	param.param.normaluserStart.isVideoOff = startParam.isVideoOff;
	param.param.normaluserStart.isAudioOff = startParam.isAudioOff;
	param.param.normaluserStart.isDirectShareDesktop = startParam.isDirectShareDesktop;
	m_meeting_config_ctrl.SetSharingToolbarVisibility(true);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Start(param));
}
ZNSDKError ZMeetingServiceWrap::Start_WithoutLogin(ZNStartParam startParam)
{
	ZOOM_SDK_NAMESPACE::StartParam param;
	param.userType = Map2SDKDefine(startParam.userType);
	param.param.withoutloginStart.userID = startParam.userId.c_str();
	param.param.withoutloginStart.userToken = startParam.userToken.c_str();
	param.param.withoutloginStart.userZAK = startParam.userZAK.c_str();
	param.param.withoutloginStart.userName = startParam.username.c_str();
	param.param.withoutloginStart.zoomuserType = Map2SDKDefine(startParam.zoomUserType);
	param.param.withoutloginStart.meetingNumber = _wtoi64(startParam.meetingNumber.c_str());
	if (!startParam.sdkVanityID.empty())
	{
		param.param.withoutloginStart.vanityID = startParam.sdkVanityID.c_str();
	}
	//param.param.withoutloginStart.hDirectShareAppWnd = (HWND)_wtoi64(startParam.hDirectShareAppWnd.c_str());
	swscanf_s(startParam.hDirectShareAppWnd.c_str(), L"%x", &param.param.withoutloginStart.hDirectShareAppWnd);
	param.param.withoutloginStart.participantId = startParam.participantId.c_str();
	param.param.withoutloginStart.isVideoOff = startParam.isVideoOff;
	param.param.withoutloginStart.isAudioOff = startParam.isAudioOff;
	param.param.withoutloginStart.isDirectShareDesktop = startParam.isDirectShareDesktop;
	m_meeting_config_ctrl.SetSharingToolbarVisibility(true);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Start(param));
}
ZNSDKError ZMeetingServiceWrap::Join(ZNJoinParam joinParam)
{
	ZOOM_SDK_NAMESPACE::JoinParam param;
	param.userType = Map2SDKDefine(joinParam.userType);
	param.param.normaluserJoin.meetingNumber = _wtoi64(joinParam.meetingNumber.c_str());
	swscanf_s(joinParam.hDirectShareAppWnd.c_str(), L"%x", &param.param.normaluserJoin.hDirectShareAppWnd);
	param.param.normaluserJoin.participantId = joinParam.participantId.c_str();
	param.param.normaluserJoin.isVideoOff = joinParam.isVideoOff;
	param.param.normaluserJoin.isAudioOff = joinParam.isAudioOff;
	param.param.normaluserJoin.isDirectShareDesktop = joinParam.isDirectShareDesktop;
	if (!joinParam.vanityID.empty())
	{
		param.param.normaluserJoin.vanityID = joinParam.vanityID.c_str();
	}
	param.param.normaluserJoin.userName = joinParam.username.c_str();
	param.param.normaluserJoin.psw = joinParam.psw.c_str();
	param.param.normaluserJoin.webinarToken = joinParam.webinarToken.c_str();
	m_meeting_config_ctrl.SetSharingToolbarVisibility(true);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Join(param));
}
ZNSDKError ZMeetingServiceWrap::Join_WithoutLogin(ZNJoinParam joinParam)
{
	ZOOM_SDK_NAMESPACE::JoinParam param;
	param.userType = Map2SDKDefine(joinParam.userType);
	param.param.withoutloginuserJoin.meetingNumber = _wtoi64(joinParam.meetingNumber.c_str());
	if (!joinParam.vanityID.empty())
	{
		param.param.withoutloginuserJoin.vanityID = joinParam.vanityID.c_str();
	}
	param.param.withoutloginuserJoin.userName = joinParam.username.c_str();
	param.param.withoutloginuserJoin.psw = joinParam.psw.c_str();
	swscanf_s(joinParam.hDirectShareAppWnd.c_str(), L"%x", &param.param.withoutloginuserJoin.hDirectShareAppWnd);
	param.param.withoutloginuserJoin.toke4enfrocelogin = joinParam.token4EnforceLogin.c_str();
	param.param.withoutloginuserJoin.participantId = joinParam.participantId.c_str();
	param.param.withoutloginuserJoin.webinarToken = joinParam.webinarToken.c_str();
	param.param.withoutloginuserJoin.isVideoOff = joinParam.isVideoOff;
	param.param.withoutloginuserJoin.isAudioOff = joinParam.isAudioOff;
	param.param.withoutloginuserJoin.isDirectShareDesktop = joinParam.isDirectShareDesktop;
	m_meeting_config_ctrl.SetSharingToolbarVisibility(true);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Join(param));
}
void ZMeetingServiceWrap::onMeetingStatusChanged(ZNMeetingStatus meetingStatus, int iResult)
{
	if (m_pSink)
		m_pSink->onMeetingStatusChanged(meetingStatus, iResult);
}
ZNSDKError ZMeetingServiceWrap::Leave(ZNLeaveMeetingCmd cmd)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Leave(Map2SDKDefine(cmd)));
}
ZNSDKError ZMeetingServiceWrap::Lock()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().LockMeeting());
}
ZNSDKError ZMeetingServiceWrap::Unlock()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().UnlockMeeting());
}

ZMeetingInfoWrap& ZMeetingServiceWrap::GetMeetingInfo()
{
	return m_meeting_info;
}
ZMeetingUICtrlWrap& ZMeetingServiceWrap::GetMeetingUICtrl()
{
	return m_meeting_ui_ctrl;
}
ZMeetingAnnotationWrap& ZMeetingServiceWrap::GetMeetingAnnotation()
{
	return m_meeting_annotation;
}
ZMeetingAudioWrap& ZMeetingServiceWrap::GetMeetingAudioCtrl()
{
	return m_meeting_audio_ctrl;
}
ZMeetingVideoWrap& ZMeetingServiceWrap::GetMeetingVideoCtrl()
{
	return m_meeting_video_ctrl;
}
ZMeetingParticipantsWrap& ZMeetingServiceWrap::GetMeetingParticipantsCtrl()
{
	return m_meeting_participants_ctrl;
}
ZMeetingShareWrap& ZMeetingServiceWrap::GetMeetingShareCtrl()
{
	return m_meeting_share_ctrl;
}
ZMeetingH323Wrap& ZMeetingServiceWrap::GetMeetingH323Ctrl()
{
	return m_meeting_h323_ctrl;
}
ZMeetingConfigWrap& ZMeetingServiceWrap::GetMeetingConfigCtrl()
{
	return m_meeting_config_ctrl;
}
ZNConnectionQuality ZMeetingServiceWrap::GetSharingConnQuality()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetSharingConnQuality());
}
ZNConnectionQuality ZMeetingServiceWrap::GetVideoConnQuality()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetVideoConnQuality());
}
ZNConnectionQuality ZMeetingServiceWrap::GetAudioConnQuality()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetAudioConnQuality());
}
////////////////////////////////////////////////////////////////////////////////////////////////
ZoomSTRING ZMeetingInfoWrap::GetMeetingTopic()
{
	ZoomSTRING meetingTopic = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetMeetingTopic();
	return meetingTopic;
}
ZNMeetingType ZMeetingInfoWrap::GetMeetingType()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetMeetingType());
}
ZoomSTRING ZMeetingInfoWrap::GetMeetingNumber()
{
	UINT64 num = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetMeetingNumber();
	wchar_t temp[1024];
	int radix = 10;
	_ui64tow(num, temp, radix);
	ZoomSTRING meetingNumber = temp;
	return meetingNumber;
}
ZoomSTRING ZMeetingInfoWrap::GetMeetingID()
{
	ZoomSTRING meetingID = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetMeetingID();
	return meetingID;
}
ZoomSTRING ZMeetingInfoWrap::GetInviteEmailTeamplate()
{
	ZoomSTRING inviteEmailTeamplate = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetInviteEmailTeamplate();
	return inviteEmailTeamplate;
}
ZoomSTRING ZMeetingInfoWrap::GetInviteEmailTitle()
{
	ZoomSTRING inviteEmailTitle = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetInviteEmailTitle();
	return inviteEmailTitle;
}
ZoomSTRING ZMeetingInfoWrap::GetJoinMeetingUrl()
{
	ZoomSTRING joinMeetingUrl = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetJoinMeetingUrl();
	return joinMeetingUrl;
}
ZoomSTRING ZMeetingInfoWrap::GetMeetingHostTag()
{
	ZoomSTRING meetingHostTag = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->GetMeetingHostTag();
	return meetingHostTag;
}
bool ZMeetingInfoWrap::CheckingIsInternalMeeting()
{
	bool bDisable = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo()->IsInternalMeeting();
	return bDisable;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ZMeetingUIControllerWrapEvent : public ZOOM_SDK_NAMESPACE::IMeetingUIControllerEvent
{
public:
	void SetOwner(ZMeetingUICtrlWrap* obj) { owner_ = obj; }
	virtual void onInviteBtnClicked(bool& bHandled)
	{
		if (owner_) {
			owner_->onInviteBtnClicked(bHandled);
		}
	}
	virtual void onStartShareBtnClicked() {}
	virtual void onEndMeetingBtnClicked() {}
	virtual void onParticipantListBtnClicked() {}
	virtual void onCustomLiveStreamMenuClicked() {}
	virtual void onZoomInviteDialogFailed() {}
	virtual void onCCBTNClicked() {}


private:
	ZMeetingUICtrlWrap* owner_;
};
static ZMeetingUIControllerWrapEvent g_meeting_ui_controller_event;

ZMeetingUICtrlWrap::ZMeetingUICtrlWrap()
{
	g_meeting_ui_controller_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingUICtrlWrap::~ZMeetingUICtrlWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_ui_controller_event.SetOwner(NULL);
}
void ZMeetingUICtrlWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SetEvent(&g_meeting_ui_controller_event);
}
void ZMeetingUICtrlWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().Uninit_Wrap();
}
void ZMeetingUICtrlWrap::SetSink(IZNativeSDKMeetingUICtrlWrapSink* pSink)
{
	m_pSink = pSink;
}
void ZMeetingUICtrlWrap::onInviteBtnClicked(bool& bHandled)
{
	if (m_pSink)
		m_pSink->onInviteBtnClicked(bHandled);
}
ZNSDKError ZMeetingUICtrlWrap::ShowChatDlg(ZNShowChatDlgParam showChatDlgParam)
{
	ZOOM_SDK_NAMESPACE::ShowChatDlgParam param;
	swscanf_s(showChatDlgParam.hParent.c_str(), L"x%", &param.hParent);
	param.rect.top = _wtoi64(showChatDlgParam.rect_top.c_str());
	param.rect.bottom = _wtoi64(showChatDlgParam.rect_bottom.c_str());
	param.rect.left = _wtoi64(showChatDlgParam.rect_left.c_str());
	param.rect.right = _wtoi64(showChatDlgParam.rect_right.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowChatDlg(param));
}
ZNSDKError ZMeetingUICtrlWrap::HideChatDlg()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().HideChatDlg());
}
ZNSDKError ZMeetingUICtrlWrap::EnterFullScreen(bool bFirstView, bool bSecView)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().EnterFullScreen(bFirstView, bSecView));
}
ZNSDKError ZMeetingUICtrlWrap::ExitFullScreen(bool bFirstView, bool bSecView)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ExitFullScreen(bFirstView, bSecView));
}
ZNSDKError ZMeetingUICtrlWrap::SwitchToVideoWall()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwitchToVideoWall());
}
ZNSDKError ZMeetingUICtrlWrap::SwtichToAcitveSpeaker()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwtichToAcitveSpeaker());
}
ZNSDKError ZMeetingUICtrlWrap::MoveFloatVideoWnd(ZoomSTRING left, ZoomSTRING top)
{
	int n_left = _wtoi(left.c_str());
	int n_top = _wtoi(top.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().MoveFloatVideoWnd(n_left, n_top));
}
ZNSDKError ZMeetingUICtrlWrap::ShowSharingToolbar(bool bShow)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowSharingToolbar(bShow));
}
ZNSDKError ZMeetingUICtrlWrap::SwitchFloatVideoToActiveSpkMod()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwitchFloatVideoToActiveSpkMod());
}
ZNSDKError ZMeetingUICtrlWrap::ChangeFloatoActiveSpkVideoSize(ZNSDKFloatVideoType type)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ChangeFloatoActiveSpkVideoSize(Map2SDKDefine(type)));
}
ZNSDKError ZMeetingUICtrlWrap::SwitchFloatVideoToGalleryMod()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwitchFloatVideoToGalleryMod());
}
ZNSDKError ZMeetingUICtrlWrap::ShowParticipantsListWnd(bool bShow)
{
	HWND hPlistWnd(NULL);
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowParticipantsListWnd(bShow, hPlistWnd));
}
ZNSDKError ZMeetingUICtrlWrap::ShowBottomFloatToolbarWnd(bool bShow)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowBottomFloatToolbarWnd(bShow));
}
ZNSDKError ZMeetingUICtrlWrap::ShowJoinAudioDlg()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowJoinAudioDlg());
}
ZNSDKError ZMeetingUICtrlWrap::HideJoinAudioDlg()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().HideJoinAudioDlg());
}
ZNSDKError ZMeetingUICtrlWrap::GetWallViewPageInfo(ZNVideoWallPageInfoParam& param)
{
	ZOOM_SDK_NAMESPACE::VideoWallPageInfoParam sdk_param;
	sdk_param.nCurrentPage = _wtoi(param.currentPage.c_str());
	sdk_param.nTotalPages = _wtoi(param.totalPages.c_str());
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().GetWallViewPageInfo(sdk_param));
	wchar_t temp_current[1024];
	int radix = 10;
	_itow(sdk_param.nCurrentPage, temp_current, radix);
	param.currentPage = temp_current;
	wchar_t temp_total[1024];
	_itow(sdk_param.nTotalPages, temp_total, radix);
	param.totalPages = temp_total;
	return err;
}
ZNSDKError ZMeetingUICtrlWrap::ShowPreOrNextPageVideo(bool bPageUP)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowPreOrNextPageVideo(bPageUP));
}
ZNSDKError ZMeetingUICtrlWrap::ShowSharingFrameWindows(bool bShow)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().ShowSharingFrameWindows(bShow));
}
ZNSDKError ZMeetingUICtrlWrap::GetCurrentSplitScreenModeInfo(ZNSplitScreenInfo& info)
{
	ZOOM_SDK_NAMESPACE::SplitScreenInfo param;
	param.bInSplitScreenMode = info.bZNInSplitScreenMode;
	param.bSupportSplitScreen = info.bZNSupportSplitScreen;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().GetCurrentSplitScreenModeInfo(param));
	info.bZNInSplitScreenMode = param.bInSplitScreenMode;
	info.bZNSupportSplitScreen = param.bSupportSplitScreen;
	return err;
}
ZNSDKError ZMeetingUICtrlWrap::SwitchSplitScreenMode(bool bSplit)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwitchSplitScreenMode(bSplit));
}