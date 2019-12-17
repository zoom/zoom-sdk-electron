#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "meeting_annotation_wrap_core.h"
#include "meeting_audio_wrap_core.h"
#include "meeting_video_wrap_core.h"
#include "meeting_participants_wrap_core.h"
#include "meeting_share_wrap_core.h"
#include "meeting_h323_wrap_core.h"
#include "meeting_config_wrap_core.h"
#include "zoom_sdk_sms_helper_wrap_core.h"
#include "zoom_sinks_wrap_class.h"

class ZMeetingInfoWrap
{
public:
	ZMeetingInfoWrap(){}
	virtual ~ZMeetingInfoWrap(){}

	ZoomSTRING GetMeetingTopic();
	ZNMeetingType GetMeetingType();
	unsigned long long GetMeetingNumber();
	ZoomSTRING GetMeetingID();
	ZoomSTRING GetInviteEmailTeamplate();
	ZoomSTRING GetInviteEmailTitle();
	ZoomSTRING GetJoinMeetingUrl();
	ZoomSTRING GetMeetingHostTag();
	bool CheckingIsInternalMeeting();

};
class ZMeetingUICtrlWrap
{
public:
	ZMeetingUICtrlWrap();
	virtual ~ZMeetingUICtrlWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingUICtrlWrapSink* pSink);

	ZNSDKError ShowChatDlg(ZNShowChatDlgParam showChatDlgParam);
	ZNSDKError HideChatDlg();
	ZNSDKError EnterFullScreen(bool bFirstView, bool bSecView);
	ZNSDKError ExitFullScreen(bool bFirstView, bool bSecView);
	ZNSDKError SwitchToVideoWall();
	ZNSDKError SwtichToAcitveSpeaker();
	ZNSDKError MoveFloatVideoWnd(ZoomSTRING left, ZoomSTRING top);
	ZNSDKError ShowSharingToolbar(bool bShow);
	ZNSDKError SwitchFloatVideoToActiveSpkMod();
	ZNSDKError ChangeFloatoActiveSpkVideoSize(ZNSDKFloatVideoType type);
	ZNSDKError SwitchFloatVideoToGalleryMod();
	ZNSDKError ShowParticipantsListWnd(bool bShow);
	ZNSDKError ShowBottomFloatToolbarWnd(bool bShow);
	ZNSDKError ShowJoinAudioDlg();
	ZNSDKError HideJoinAudioDlg();
	ZNSDKError GetWallViewPageInfo(ZNVideoWallPageInfoParam& param);
	ZNSDKError ShowPreOrNextPageVideo(bool bPageUP);
	ZNSDKError ShowSharingFrameWindows(bool bShow);
	ZNSDKError GetCurrentSplitScreenModeInfo(ZNSplitScreenInfo& info);
	ZNSDKError SwitchSplitScreenMode(bool bSplit);

	ZNSDKError BackToMeeting();
	ZNSDKError GetMeetingUIWnd(ZoomSTRING& hFirstView, ZoomSTRING& hSecondView);
	ZNSDKError SwitchMinimizeUIMode4FristScreenMeetingUIWnd(ZNSDKMinimizeUIMode mode);
	bool  IsMinimizeModeOfFristScreenMeetingUIWnd(ZNSDKMinimizeUIMode& mode);
	ZNSDKError SwapToShowShareViewOrVideo(bool bToDisplayShare);
	ZNSDKError IsDisplayingShareViewOrVideo(bool& bIsShare);
	ZNSDKError CanSwapToShowShareViewOrVideo(bool& bCan);

	//callback
	void onInviteBtnClicked(bool& bHandled);

	void onStartShareBtnClicked();
	void onEndMeetingBtnClicked();
	void onParticipantListBtnClicked();
	void onCustomLiveStreamMenuClicked();
	void onZoomInviteDialogFailed();
	void onCCBTNClicked();
	void onAudioBtnClicked(ZNAudioBtnClickedCallbackInfo info);
	void onAudioMenuBtnClicked();
private:
	ZNativeSDKMeetingUICtrlWrapSink* m_pSink;
};
class ZMeetingServiceWrap
{
public:
	ZMeetingServiceWrap();
	virtual ~ZMeetingServiceWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingWrapSink* pSink);
	
	ZNSDKError Start(ZNStartParam startParam);
	ZNSDKError Start_WithoutLogin(ZNStartParam startParam);
	ZNSDKError Join(ZNJoinParam joinParam);
	ZNSDKError Join_WithoutLogin(ZNJoinParam joinParam);
	ZNSDKError Leave(ZNLeaveMeetingCmd cmd);
	ZNSDKError Lock();
	ZNSDKError Unlock();
	ZNSDKError HandleZoomWebUriProtocolAction(ZoomSTRING protocol_action);

	ZMeetingInfoWrap& GetMeetingInfo();
	ZMeetingUICtrlWrap& GetMeetingUICtrl();
	ZMeetingAnnotationWrap& GetMeetingAnnotation();
	ZMeetingAudioWrap& GetMeetingAudioCtrl();
	ZMeetingVideoWrap& GetMeetingVideoCtrl();
    ZMeetingParticipantsWrap& GetMeetingParticipantsCtrl();
	ZMeetingShareWrap& GetMeetingShareCtrl();
	ZMeetingH323Wrap& GetMeetingH323Ctrl();
	ZMeetingConfigWrap& GetMeetingConfigCtrl();
	ZSDKSMSHelperWrap& GetSDKSMSHelper();

	ZNConnectionQuality GetSharingConnQuality();
	ZNConnectionQuality GetVideoConnQuality();
	ZNConnectionQuality GetAudioConnQuality();

	//callback
	void onMeetingStatusChanged(ZNMeetingStatus meetingStatus, int iResult);
private:
	ZNativeSDKMeetingWrapSink* m_pSink;
	ZMeetingInfoWrap m_meeting_info;
	ZMeetingUICtrlWrap m_meeting_ui_ctrl;
	ZMeetingAnnotationWrap m_meeting_annotation;
	ZMeetingAudioWrap m_meeting_audio_ctrl;
	ZMeetingVideoWrap m_meeting_video_ctrl;
	ZMeetingParticipantsWrap m_meeting_participants_ctrl;
	ZMeetingShareWrap m_meeting_share_ctrl;
	ZMeetingH323Wrap m_meeting_h323_ctrl;
	ZMeetingConfigWrap m_meeting_config_ctrl;
	ZSDKSMSHelperWrap m_sdk_sms_helper;
};
