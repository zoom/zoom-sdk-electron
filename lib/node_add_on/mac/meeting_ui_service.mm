

#include "../meeting_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
#import "meetingServiceDelegate.h"
ZMeetingUICtrlWrap &ZMeetingServiceWrap::GetMeetingUICtrl()
{
    return m_meeting_ui_ctrl;
}

ZMeetingUICtrlWrap::ZMeetingUICtrlWrap()
{
    m_pSink = 0;
}

ZMeetingUICtrlWrap::~ZMeetingUICtrlWrap()
{
    m_pSink = 0;
}

void ZMeetingUICtrlWrap::Init()
{
    
}
void ZMeetingUICtrlWrap::Uninit()
{
    
}
void ZMeetingUICtrlWrap::SetSink(ZNativeSDKMeetingUICtrlWrapSink *pSink)
{
    m_pSink = pSink;
}

ZNSDKError ZMeetingUICtrlWrap::ShowChatDlg(ZNShowChatDlgParam showChatDlgParam)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString *L = [NSString stringWithCString:showChatDlgParam.rect_left.c_str() encoding:NSUTF8StringEncoding];
    NSString *T = [NSString stringWithCString:showChatDlgParam.rect_top.c_str() encoding:NSUTF8StringEncoding];
    NSString *R = [NSString stringWithCString:showChatDlgParam.rect_right.c_str() encoding:NSUTF8StringEncoding];
    NSString *B = [NSString stringWithCString:showChatDlgParam.rect_bottom.c_str() encoding:NSUTF8StringEncoding];
    NSRect  rect = NSMakeRect(L.floatValue, T.floatValue, R.floatValue, B.floatValue);
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Chat window:nil show:YES InPanel:YES frame:rect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::HideChatDlg()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Chat window:nil show:NO InPanel:NO frame:NSZeroRect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::EnterFullScreen(bool bFirstView, bool bSecView)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError  ret = [controller enterFullScreen:YES firstMonitor:bFirstView DualMonitor:bSecView];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}


ZNSDKError ZMeetingUICtrlWrap::ExitFullScreen(bool bFirstView, bool bSecView)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError  ret = [controller enterFullScreen:NO firstMonitor:bFirstView DualMonitor:bSecView];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::SwitchToVideoWall()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError  ret = [controller switchToVideoWallView];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::SwtichToAcitveSpeaker()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError  ret = [controller switchToActiveSpeakerView];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::MoveFloatVideoWnd(ZoomSTRING left, ZoomSTRING top)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }

    NSString *L = [NSString stringWithCString:left.c_str() encoding:NSUTF8StringEncoding];
    NSString *T = [NSString stringWithCString:top.c_str() encoding:NSUTF8StringEncoding];
    NSRect  rect = NSMakeRect(L.floatValue, T.floatValue, 0, 0);
    ZoomSDKError  ret = [controller showMeetingComponent:MeetingComponent_ThumbnailVideo window:nil show:YES InPanel:NO frame:rect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ShowSharingToolbar(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError  ret = [controller showMeetingComponent:MeetingComponent_MainShareToolBar window:nil show:bShow InPanel:bShow frame:NSZeroRect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::SwitchFloatVideoToActiveSpkMod()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller switchFloatVideoToActiveSpeakerMode];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ChangeFloatoActiveSpkVideoSize(ZNSDKFloatVideoType type)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller) {
         return ZNSDKERR_SERVICE_FAILED;
    }
    if (type == ZN_FLOATVIDEO_List || type == ZN_FLOATVIDEO_Small)
        return ZNSDKERR_NO_IMPL;
    if (type == ZN_FLOATVIDEO_Large){
        ZoomSDKError ret = [controller minimizeShareFloatVideoWindow:NO];
        return Help_type.ZoomSDKErrorType(ret);
    }
    if (type == ZN_FLOATVIDEO_Small){
        ZoomSDKError ret = [controller minimizeShareFloatVideoWindow:YES];
        return Help_type.ZoomSDKErrorType(ret);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingUICtrlWrap::SwitchFloatVideoToGalleryMod()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller switchFloatVideoToGalleryMode];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ShowParticipantsListWnd(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Participants window:nil show:bShow InPanel:YES frame:NSZeroRect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ShowBottomFloatToolbarWnd(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_MainToolBar window:nil show:bShow InPanel:NO frame:NSZeroRect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ShowJoinAudioDlg()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSRect rect = NSMakeRect(300, 300, 0, 0);
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Audio window:nil show:YES InPanel:NO frame:rect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::HideJoinAudioDlg()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_Audio window:nil show:NO InPanel:NO frame:NSZeroRect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::GetWallViewPageInfo(ZNVideoWallPageInfoParam &param)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString *currentPage = [NSString stringWithCString:param.currentPage.c_str() encoding:NSUTF8StringEncoding];
    NSString *totalPage = [NSString stringWithCString:param.totalPages.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKError ret = [controller getWallViewPageInfo:(int*)(intptr_t)currentPage.intValue TotalPageNum:(int *)(intptr_t)totalPage.intValue];
    param.currentPage = currentPage.UTF8String;
    param.totalPages  = currentPage.UTF8String;
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ShowPreOrNextPageVideo(bool bPageUP)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller showPreOrNextPageWallView:bPageUP];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::ShowSharingFrameWindows(bool bShow)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller showMeetingComponent:MeetingComponent_ShareOptionWindow window:nil show:bShow InPanel:NO frame:NSZeroRect];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::BackToMeeting()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller backToMeeting];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::GetMeetingUIWnd(ZoomSTRING &hFirstView, ZoomSTRING &hSecondView)
{
    return ZNSDKERR_NO_IMPL;
}

ZNSDKError ZMeetingUICtrlWrap::SwitchMinimizeUIMode4FristScreenMeetingUIWnd(ZNSDKMinimizeUIMode mode)
{
    return ZNSDKERR_NO_IMPL;
}

bool  ZMeetingUICtrlWrap::IsMinimizeModeOfFristScreenMeetingUIWnd(ZNSDKMinimizeUIMode& mode)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingUIController *controller = [service getMeetingUIController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    return [controller isInMiniVideoMode];
}

ZNSDKError ZMeetingUICtrlWrap::SwapToShowShareViewOrVideo(bool bToDisplayShare)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *controller = [service getMeetingActionController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [controller swapToShowShareViewOrVideo:bToDisplayShare];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingUICtrlWrap::IsDisplayingShareViewOrVideo(bool& bIsShare)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *controller = [service getMeetingActionController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    bIsShare = [controller isDisplayingShareViewOrVideo];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZMeetingUICtrlWrap::CanSwapToShowShareViewOrVideo(bool& bCan)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]  getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *controller = [service getMeetingActionController];
    if (!controller){
        return ZNSDKERR_SERVICE_FAILED;
    }
    bCan = [controller canSwapToShowShareViewOrVideo];
    return ZNSDKERR_SUCCESS;
    
}

//callback
void ZMeetingUICtrlWrap::onInviteBtnClicked(bool &bHandled)
{
    if (m_pSink) {
        m_pSink->onInviteBtnClicked(bHandled);
    }
}

void ZMeetingUICtrlWrap::onStartShareBtnClicked()
{
    if (m_pSink) {
        m_pSink->onStartShareBtnClicked();
    }
}

void ZMeetingUICtrlWrap::onEndMeetingBtnClicked()
{
    if (m_pSink) {
        m_pSink->onEndMeetingBtnClicked();
    }
}

void ZMeetingUICtrlWrap::onParticipantListBtnClicked()
{
    if (m_pSink) {
        m_pSink->onParticipantListBtnClicked();
    }
}

void ZMeetingUICtrlWrap::onCustomLiveStreamMenuClicked()
{
    if (m_pSink) {
        m_pSink->onCustomLiveStreamMenuClicked();
    }
}
void ZMeetingUICtrlWrap::onZoomInviteDialogFailed()
{
    if (m_pSink) {
        m_pSink->onZoomInviteDialogFailed();
    }
}

void ZMeetingUICtrlWrap::onAudioBtnClicked(ZNAudioBtnClickedCallbackInfo info)
{
    if (m_pSink) {
        m_pSink->onAudioBtnClicked(info);
    }
}

void ZMeetingUICtrlWrap::onAudioMenuBtnClicked()
{
    if (m_pSink) {
        m_pSink->onAudioMenuBtnClicked();
    }
}

void ZMeetingUICtrlWrap::onCCBTNClicked()
{
    return;
}
