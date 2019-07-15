#include "meeting_ui_ctrl_wrap.h"
#include "../meeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
IMeetingUIController* InitIMeetingUIControllerFunc(IMeetingUIControllerEvent* pEvent, IMeetingServiceWrap* pOwner)
{
	if (pOwner && pOwner->GetSDKObj())
	{
		ZOOM_SDK_NAMESPACE::IMeetingUIController* pObj = pOwner->GetSDKObj()->GetUIController();
		if (pObj)
		{
			pObj->SetEvent(pEvent);
		}
		return pObj;
	}

	return NULL;
}

void UninitIMeetingUIControllerFunc(IMeetingUIController* obj)
{
	if (obj)
	{
		obj->SetEvent(NULL);
	}
}

//virtual SDKError ShowChatDlg(ShowChatDlgParam& param) = 0;
IMPL_FUNC_1(IMeetingUIController, ShowChatDlg, SDKError, ShowChatDlgParam&, param, SDKERR_UNINITIALIZE)
//virtual SDKError HideChatDlg() = 0;
IMPL_FUNC_0(IMeetingUIController, HideChatDlg, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError EnterFullScreen(bool firstView, bool secondView) = 0;
IMPL_FUNC_2(IMeetingUIController, EnterFullScreen, SDKError, bool, firstView, bool, secondView, SDKERR_UNINITIALIZE)
//virtual SDKError ExitFullScreen(bool firstView, bool secondView) = 0;
IMPL_FUNC_2(IMeetingUIController, ExitFullScreen, SDKError, bool, firstView, bool, secondView, SDKERR_UNINITIALIZE)
//virtual SDKError SwitchToVideoWall() = 0;
IMPL_FUNC_0(IMeetingUIController, SwitchToVideoWall, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError SwtichToAcitveSpeaker() = 0;
IMPL_FUNC_0(IMeetingUIController, SwtichToAcitveSpeaker, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError MoveFloatVideoWnd(int left, int top) = 0;
IMPL_FUNC_2(IMeetingUIController, MoveFloatVideoWnd, SDKError, int, left, int, top, SDKERR_UNINITIALIZE)
//virtual SDKError ShowSharingToolbar(bool bShow) = 0;
IMPL_FUNC_1(IMeetingUIController, ShowSharingToolbar, SDKError, bool, bShow, SDKERR_UNINITIALIZE)
//virtual SDKError SwitchFloatVideoToActiveSpkMod() = 0;
IMPL_FUNC_0(IMeetingUIController, SwitchFloatVideoToActiveSpkMod, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ChangeFloatoActiveSpkVideoSize(SDKFloatVideoType type) = 0;
IMPL_FUNC_1(IMeetingUIController, ChangeFloatoActiveSpkVideoSize, SDKError, SDKFloatVideoType, type, SDKERR_UNINITIALIZE)
//virtual SDKError SwitchFloatVideoToGalleryMod() = 0;
IMPL_FUNC_0(IMeetingUIController, SwitchFloatVideoToGalleryMod, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError ShowParticipantsListWnd(bool bShow, HWND& hParticipantsListWnd) = 0;
IMPL_FUNC_2(IMeetingUIController, ShowParticipantsListWnd, SDKError, bool, bShow, HWND&, hParticipantsListWnd, SDKERR_UNINITIALIZE)
//virtual SDKError ShowBottomFloatToolbarWnd(bool bShow) = 0;
IMPL_FUNC_1(IMeetingUIController, ShowBottomFloatToolbarWnd, SDKError, bool, bShow, SDKERR_UNINITIALIZE)
//virtual SDKError GetMeetingUIWnd(HWND& hFirstView, HWND& hSecondView) = 0;
IMPL_FUNC_2(IMeetingUIController, GetMeetingUIWnd, SDKError, HWND&, hFirstView, HWND&, hSecondView, SDKERR_UNINITIALIZE)
//virtual SDKError ShowJoinAudioDlg() = 0;
IMPL_FUNC_0(IMeetingUIController, ShowJoinAudioDlg, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError HideJoinAudioDlg() = 0;
IMPL_FUNC_0(IMeetingUIController, HideJoinAudioDlg, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError BackToMeeting() = 0;
IMPL_FUNC_0(IMeetingUIController, BackToMeeting, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError GetWallViewPageInfo(VideoWallPageInfoParam& videoWallPageInfoParam) = 0;
IMPL_FUNC_1(IMeetingUIController, GetWallViewPageInfo, SDKError, VideoWallPageInfoParam&, videoWallPageInfoParam, SDKERR_UNINITIALIZE)
//virtual SDKError ShowPreOrNextPageVideo(bool bPageUp) = 0;
IMPL_FUNC_1(IMeetingUIController, ShowPreOrNextPageVideo, SDKError, bool, bPageUp, SDKERR_UNINITIALIZE)
//virtual SDKError ShowSharingFrameWindows(bool bShow) = 0;
IMPL_FUNC_1(IMeetingUIController, ShowSharingFrameWindows, SDKError, bool, bShow, SDKERR_UNINITIALIZE)
//virtual bool IsMinimizeModeOfFristScreenMeetingUIWnd(SDKMinimizeUIMode& mode) = 0;
IMPL_FUNC_1(IMeetingUIController, IsMinimizeModeOfFristScreenMeetingUIWnd, bool, SDKMinimizeUIMode&, mode, false)
//virtual SDKError SwitchMinimizeUIMode4FristScreenMeetingUIWnd(SDKMinimizeUIMode mode) = 0;
IMPL_FUNC_1(IMeetingUIController, SwitchMinimizeUIMode4FristScreenMeetingUIWnd, SDKError, SDKMinimizeUIMode, mode, SDKERR_UNINITIALIZE)

IMPL_FUNC_1(IMeetingUIController, GetCurrentSplitScreenModeInfo, SDKError, SplitScreenInfo&, info, SDKERR_UNINITIALIZE)
//virtual SDKError SwitchSplitScreenMode(bool bSplit) = 0;
IMPL_FUNC_1(IMeetingUIController, SwitchSplitScreenMode, SDKError, bool, bSplit, SDKERR_UNINITIALIZE)

//virtual SDKError SwapToShowShareViewOrVideo(bool bToDisplayShare) = 0;
IMPL_FUNC_1(IMeetingUIController, SwapToShowShareViewOrVideo, SDKError, bool, bToDisplayShare, SDKERR_UNINITIALIZE)
//virtual SDKError IsDisplayingShareViewOrVideo(bool& bIsShare) = 0;
IMPL_FUNC_1(IMeetingUIController, IsDisplayingShareViewOrVideo, SDKError, bool&, bIsShare, SDKERR_UNINITIALIZE)
//virtual SDKError CanSwapToShowShareViewOrVideo(bool& bCan) = 0;
IMPL_FUNC_1(IMeetingUIController, CanSwapToShowShareViewOrVideo, SDKError, bool&, bCan, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE