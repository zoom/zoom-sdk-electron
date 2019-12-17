
#include "../meeting_service_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_ui_ctrl_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"

ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();

ZMeetingServiceWrap::ZMeetingServiceWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingServiceWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingServiceWrap::~ZMeetingServiceWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingServiceWrapEvent.SetOwner(NULL);
}
void ZMeetingServiceWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Init_Wrap();
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingServiceWrapEvent);
}
void ZMeetingServiceWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().Uninit_Wrap();
}
void ZMeetingServiceWrap::SetSink(ZNativeSDKMeetingWrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingServiceWrap::Start(ZNStartParam startParam)
{
	ZOOM_SDK_NAMESPACE::StartParam param;
	param.userType = Map2SDKDefine(startParam.userType);
	param.param.normaluserStart.meetingNumber = startParam.meetingNumber;
	swscanf_s(startParam.hDirectShareAppWnd.c_str(), L"%x", (unsigned int*)&param.param.normaluserStart.hDirectShareAppWnd);
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
	param.param.withoutloginStart.meetingNumber = startParam.meetingNumber;
	if (!startParam.sdkVanityID.empty())
	{
		param.param.withoutloginStart.vanityID = startParam.sdkVanityID.c_str();
	}
	//param.param.withoutloginStart.hDirectShareAppWnd = (HWND)_wtoi64(startParam.hDirectShareAppWnd.c_str());
	swscanf_s(startParam.hDirectShareAppWnd.c_str(), L"%x", (unsigned int*)&param.param.withoutloginStart.hDirectShareAppWnd);
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
	param.param.normaluserJoin.meetingNumber = joinParam.meetingNumber; 
	swscanf_s(joinParam.hDirectShareAppWnd.c_str(), L"%x", (unsigned int*)&param.param.normaluserJoin.hDirectShareAppWnd);
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
	param.param.withoutloginuserJoin.meetingNumber = joinParam.meetingNumber;
	if (!joinParam.vanityID.empty())
	{
		param.param.withoutloginuserJoin.vanityID = joinParam.vanityID.c_str();
	}
	param.param.withoutloginuserJoin.userName = joinParam.username.c_str();
	param.param.withoutloginuserJoin.psw = joinParam.psw.c_str();
	swscanf_s(joinParam.hDirectShareAppWnd.c_str(), L"%x", (unsigned int*)&param.param.withoutloginuserJoin.hDirectShareAppWnd);
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
ZNSDKError ZMeetingServiceWrap::HandleZoomWebUriProtocolAction(ZoomSTRING protocol_action)
{
	if (protocol_action.empty())
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().HandleZoomWebUriProtocolAction(NULL));
	}
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().HandleZoomWebUriProtocolAction(protocol_action.c_str()));
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
ZSDKSMSHelperWrap& ZMeetingServiceWrap::GetSDKSMSHelper()
{
	return m_sdk_sms_helper;
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
	ZoomSTRING meetingTopic;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		meetingTopic = pMeetingInfo->GetMeetingTopic();
	}
	
	return meetingTopic;
}
ZNMeetingType ZMeetingInfoWrap::GetMeetingType()
{
	ZNMeetingType zn_type = ZNMEETING_TYPE_NONE;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		zn_type = Map2WrapDefine(pMeetingInfo->GetMeetingType());
	}
	return zn_type;
}
unsigned long long ZMeetingInfoWrap::GetMeetingNumber()
{
	UINT64 meetingNumber;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		meetingNumber = pMeetingInfo->GetMeetingNumber();
	}
	return meetingNumber;
}
ZoomSTRING ZMeetingInfoWrap::GetMeetingID()
{
	ZoomSTRING meetingID;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		meetingID = pMeetingInfo->GetMeetingID();
	}
	
	return meetingID;
}
ZoomSTRING ZMeetingInfoWrap::GetInviteEmailTeamplate()
{
	ZoomSTRING inviteEmailTeamplate;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		inviteEmailTeamplate = pMeetingInfo->GetInviteEmailTeamplate();
	}
	
	return inviteEmailTeamplate;
}
ZoomSTRING ZMeetingInfoWrap::GetInviteEmailTitle()
{
	ZoomSTRING inviteEmailTitle;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		inviteEmailTitle = pMeetingInfo->GetInviteEmailTitle();
	}
	
	return inviteEmailTitle;
}
ZoomSTRING ZMeetingInfoWrap::GetJoinMeetingUrl()
{
	ZoomSTRING joinMeetingUrl;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		joinMeetingUrl = pMeetingInfo->GetJoinMeetingUrl();
	}
	
	return joinMeetingUrl;
}
ZoomSTRING ZMeetingInfoWrap::GetMeetingHostTag()
{
	ZoomSTRING meetingHostTag;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		meetingHostTag = pMeetingInfo->GetMeetingHostTag();
	}
	
	return meetingHostTag;
}
bool ZMeetingInfoWrap::CheckingIsInternalMeeting()
{
	bool bDisable;
	ZOOM_SDK_NAMESPACE::IMeetingInfo* pMeetingInfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().GetMeetingInfo();
	if (pMeetingInfo)
	{
		bDisable = pMeetingInfo->IsInternalMeeting();
	}
	
	return bDisable;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ZMeetingUICtrlWrap::ZMeetingUICtrlWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingUICtrlWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingUICtrlWrap::~ZMeetingUICtrlWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingUICtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingUICtrlWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingUICtrlWrapEvent);
}
void ZMeetingUICtrlWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().Uninit_Wrap();
}
void ZMeetingUICtrlWrap::SetSink(ZNativeSDKMeetingUICtrlWrapSink* pSink)
{
	m_pSink = pSink;
}

void ZMeetingUICtrlWrap::onInviteBtnClicked(bool& bHandled)
{
	if (m_pSink)
		m_pSink->onInviteBtnClicked(bHandled);
}
void ZMeetingUICtrlWrap::onStartShareBtnClicked()
{
	if (m_pSink)
		m_pSink->onStartShareBtnClicked();
}
void ZMeetingUICtrlWrap::onEndMeetingBtnClicked()
{
	if (m_pSink)
		m_pSink->onEndMeetingBtnClicked();
}
void ZMeetingUICtrlWrap::onParticipantListBtnClicked()
{
	if (m_pSink)
		m_pSink->onParticipantListBtnClicked();
}
void ZMeetingUICtrlWrap::onCustomLiveStreamMenuClicked()
{
	if (m_pSink)
		m_pSink->onCustomLiveStreamMenuClicked();
}
void ZMeetingUICtrlWrap::onZoomInviteDialogFailed()
{
	if (m_pSink)
		m_pSink->onZoomInviteDialogFailed();
}
void ZMeetingUICtrlWrap::onCCBTNClicked()
{
	if (m_pSink)
		m_pSink->onCCBTNClicked();
}
void ZMeetingUICtrlWrap::onAudioBtnClicked(ZNAudioBtnClickedCallbackInfo info)
{
	if (m_pSink)
		m_pSink->onAudioBtnClicked(info);
}
void ZMeetingUICtrlWrap::onAudioMenuBtnClicked()
{
	if (m_pSink)
		m_pSink->onAudioMenuBtnClicked();
}

ZNSDKError ZMeetingUICtrlWrap::ShowChatDlg(ZNShowChatDlgParam showChatDlgParam)
{
	ZOOM_SDK_NAMESPACE::ShowChatDlgParam param;
	swscanf_s(showChatDlgParam.hParent.c_str(), L"%x", (unsigned int*)&param.hParent);
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

ZNSDKError ZMeetingUICtrlWrap::BackToMeeting()
{
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().BackToMeeting());
	return err;
}
ZNSDKError ZMeetingUICtrlWrap::GetMeetingUIWnd(ZoomSTRING& hFirstView, ZoomSTRING& hSecondView)
{
	HWND sdk_hFirstView;
	HWND sdk_hSecondView;
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().GetMeetingUIWnd(sdk_hFirstView, sdk_hSecondView));
	wchar_t temp_1[1024];
	wchar_t temp_2[1024];
	int radix = 16;
	_i64tow((long long)sdk_hFirstView, temp_1, radix);
	_i64tow((long long)sdk_hSecondView, temp_2, radix);
	hFirstView = temp_1;
	hSecondView = temp_2;
	return err;
}
ZNSDKError ZMeetingUICtrlWrap::SwitchMinimizeUIMode4FristScreenMeetingUIWnd(ZNSDKMinimizeUIMode mode)
{
	ZOOM_SDK_NAMESPACE::SDKMinimizeUIMode sdk_mode = Map2SDKDefine(mode);
	ZOOM_SDK_NAMESPACE::SDKError sdk_err = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwitchMinimizeUIMode4FristScreenMeetingUIWnd(sdk_mode);
	ZNSDKError err = Map2WrapDefine(sdk_err);
	//ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwitchMinimizeUIMode4FristScreenMeetingUIWnd(sdk_mode));
	return err;
}
bool ZMeetingUICtrlWrap::IsMinimizeModeOfFristScreenMeetingUIWnd(ZNSDKMinimizeUIMode &mode)
{
	ZOOM_SDK_NAMESPACE::SDKMinimizeUIMode sdk_mode = Map2SDKDefine(mode);
	bool b_isMinimizMode = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().IsMinimizeModeOfFristScreenMeetingUIWnd(sdk_mode);
	switch (sdk_mode)
	{
	case ZOOMSDK::MinimizeUIMode_NONE:
		mode = ZN_MinimizeUIMode_NONE;
		break;
	case ZOOMSDK::MinimizeUIMode_SHARE:
		mode = ZN_MinimizeUIMode_SHARE;
		break;
	case ZOOMSDK::MinimizeUIMode_VIDEO:
		mode = ZN_MinimizeUIMode_VIDEO;
		break;
	case ZOOMSDK::MinimizeUIMode_ACTIVESPEAKER:
		mode = ZN_MinimizeUIMode_ACTIVESPEAKER;
		break;
	default:
		break;
	}
	return b_isMinimizMode;
}
ZNSDKError ZMeetingUICtrlWrap::SwapToShowShareViewOrVideo(bool bToDisplayShare)
{
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().SwapToShowShareViewOrVideo(bToDisplayShare));
	return err;
}
ZNSDKError ZMeetingUICtrlWrap::IsDisplayingShareViewOrVideo(bool& bIsShare)
{
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().IsDisplayingShareViewOrVideo(bIsShare));
	return err;
}
ZNSDKError ZMeetingUICtrlWrap::CanSwapToShowShareViewOrVideo(bool& bCan)
{
	ZNSDKError err = Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetUIController().CanSwapToShowShareViewOrVideo(bCan));
	return err;
}