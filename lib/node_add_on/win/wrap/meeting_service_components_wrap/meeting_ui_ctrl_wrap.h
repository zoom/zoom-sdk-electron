#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingUIController* InitIMeetingUIControllerFunc(IMeetingUIControllerEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingUIControllerFunc(IMeetingUIController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingUIController, IMeetingUIControllerEvent)
NORMAL_CLASS(IMeetingUIController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingUIController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingUIControllerEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError ShowChatDlg(ShowChatDlgParam& param) = 0;
DEFINE_FUNC_1(ShowChatDlg, SDKError, ShowChatDlgParam&, param)
//virtual SDKError HideChatDlg() = 0;
DEFINE_FUNC_0(HideChatDlg, SDKError)
//virtual SDKError EnterFullScreen(bool firstView, bool secondView) = 0;
DEFINE_FUNC_2(EnterFullScreen, SDKError, bool, firstView, bool, secondView)
//virtual SDKError ExitFullScreen(bool firstView, bool secondView) = 0;
DEFINE_FUNC_2(ExitFullScreen, SDKError, bool, firstView, bool, secondView)
//virtual SDKError SwitchToVideoWall() = 0;
DEFINE_FUNC_0(SwitchToVideoWall, SDKError)
//virtual SDKError SwtichToAcitveSpeaker() = 0;
DEFINE_FUNC_0(SwtichToAcitveSpeaker, SDKError)
//virtual SDKError MoveFloatVideoWnd(int left, int top) = 0;
DEFINE_FUNC_2(MoveFloatVideoWnd, SDKError, int, left, int, top)
//virtual SDKError ShowSharingToolbar(bool bShow) = 0;
DEFINE_FUNC_1(ShowSharingToolbar, SDKError, bool, bShow)
//virtual SDKError SwitchFloatVideoToActiveSpkMod() = 0;
DEFINE_FUNC_0(SwitchFloatVideoToActiveSpkMod, SDKError)
//virtual SDKError ChangeFloatoActiveSpkVideoSize(SDKFloatVideoType type) = 0;
DEFINE_FUNC_1(ChangeFloatoActiveSpkVideoSize, SDKError, SDKFloatVideoType, type)
//virtual SDKError SwitchFloatVideoToGalleryMod() = 0;
DEFINE_FUNC_0(SwitchFloatVideoToGalleryMod, SDKError)
//virtual SDKError ShowParticipantsListWnd(bool bShow, HWND& hParticipantsListWnd) = 0;
DEFINE_FUNC_2(ShowParticipantsListWnd, SDKError, bool, bShow, HWND&, hParticipantsListWnd)
//virtual SDKError ShowBottomFloatToolbarWnd(bool bShow) = 0;
DEFINE_FUNC_1(ShowBottomFloatToolbarWnd, SDKError, bool, bShow)
//virtual SDKError GetMeetingUIWnd(HWND& hFirstView, HWND& hSecondView) = 0;
DEFINE_FUNC_2(GetMeetingUIWnd, SDKError, HWND&, hFirstView, HWND&, hSecondView)
//virtual SDKError ShowJoinAudioDlg() = 0;
DEFINE_FUNC_0(ShowJoinAudioDlg, SDKError)
//virtual SDKError HideJoinAudioDlg() = 0;
DEFINE_FUNC_0(HideJoinAudioDlg, SDKError)
//virtual SDKError BackToMeeting() = 0;
DEFINE_FUNC_0(BackToMeeting, SDKError)
//virtual SDKError GetWallViewPageInfo(VideoWallPageInfoParam& videoWallPageInfoParam) = 0;
DEFINE_FUNC_1(GetWallViewPageInfo, SDKError, VideoWallPageInfoParam&, videoWallPageInfoParam)
//virtual SDKError ShowPreOrNextPageVideo(bool bPageUp) = 0;
DEFINE_FUNC_1(ShowPreOrNextPageVideo, SDKError, bool, bPageUp)
//virtual SDKError ShowSharingFrameWindows(bool bShow) = 0;
DEFINE_FUNC_1(ShowSharingFrameWindows, SDKError, bool, bShow)
//virtual bool IsMinimizeModeOfFristScreenMeetingUIWnd(SDKMinimizeUIMode& mode) = 0;
DEFINE_FUNC_1(IsMinimizeModeOfFristScreenMeetingUIWnd, bool, SDKMinimizeUIMode&, mode)
//virtual SDKError SwitchMinimizeUIMode4FristScreenMeetingUIWnd(SDKMinimizeUIMode mode) = 0;
DEFINE_FUNC_1(SwitchMinimizeUIMode4FristScreenMeetingUIWnd, SDKError, SDKMinimizeUIMode, mode)
//virtual SDKError GetCurrentSplitScreenModeInfo(SplitScreenInfo& info) = 0;
DEFINE_FUNC_1(GetCurrentSplitScreenModeInfo, SDKError, SplitScreenInfo&, info)
//virtual SDKError SwitchSplitScreenMode(bool bSplit) = 0;
DEFINE_FUNC_1(SwitchSplitScreenMode, SDKError, bool, bSplit)
//virtual SDKError SwapToShowShareViewOrVideo(bool bToDisplayShare) = 0;
DEFINE_FUNC_1(SwapToShowShareViewOrVideo, SDKError, bool, bToDisplayShare)
//virtual SDKError IsDisplayingShareViewOrVideo(bool& bIsShare) = 0;
DEFINE_FUNC_1(IsDisplayingShareViewOrVideo, SDKError, bool&, bIsShare)
//virtual SDKError CanSwapToShowShareViewOrVideo(bool& bCan) = 0;
DEFINE_FUNC_1(CanSwapToShowShareViewOrVideo, SDKError, bool&, bCan)

//virtual void onInviteBtnClicked(bool& bHandled) = 0;
CallBack_FUNC_1(onInviteBtnClicked, bool&, bHandled)
//virtual void onStartShareBtnClicked() = 0;
CallBack_FUNC_0(onStartShareBtnClicked)
//virtual void onEndMeetingBtnClicked() = 0;
CallBack_FUNC_0(onEndMeetingBtnClicked)
//virtual void onParticipantListBtnClicked() = 0;
CallBack_FUNC_0(onParticipantListBtnClicked)
//virtual void onCustomLiveStreamMenuClicked() = 0;
CallBack_FUNC_0(onCustomLiveStreamMenuClicked)
//virtual void onZoomInviteDialogFailed() = 0;
CallBack_FUNC_0(onZoomInviteDialogFailed)
//virtual void onCCBTNClicked() = 0;
CallBack_FUNC_0(onCCBTNClicked)
//virtual void onAudioBtnClicked(AudioBtnClickedCallbackInfo info) = 0;
CallBack_FUNC_1(onAudioBtnClicked, AudioBtnClickedCallbackInfo, info)
//virtual void onAudioMenuBtnClicked() = 0;
CallBack_FUNC_0(onAudioMenuBtnClicked)
//virtual void onBreakoutRoomBtnClicked() = 0;
CallBack_FUNC_0(onBreakoutRoomBtnClicked)
END_CLASS_DEFINE(IMeetingUIController)
END_ZOOM_SDK_NAMESPACE