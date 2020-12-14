const { ZoomMeetingUIViewType, ZoomMeetingUIFloatVideoType, ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
var ZoomMeetingUICtrl = (function () {
  var instance;
   /**
   * mode: Zoom SDK Meeting UI Controller Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingUICtrl}
   */
  function init(opts) {
    let clientOpts = opts || {};
    let _addon = clientOpts.addon.GetMeetingUICtrl() || null;	
    let _onInvitebuttonclickedcb = clientOpts.onInvitebuttonclickedcb || null;
    let _onStartShareBtnClicked = clientOpts.onStartShareBtnClicked || null;
    let _onEndMeetingBtnClicked = clientOpts.onEndMeetingBtnClicked || null;
    let _onParticipantListBtnClicked = clientOpts.onParticipantListBtnClicked || null;
    let _onCustomLiveStreamMenuClicked = clientOpts.onCustomLiveStreamMenuClicked || null;
    let _onZoomInviteDialogFailed = clientOpts.onZoomInviteDialogFailed || null;
    let _onCCBTNClicked = clientOpts.onCCBTNClicked || null;
    let _onAudioBtnClicked = clientOpts.onAudioBtnClicked || null;
    let _onAudioMenuBtnClicked = clientOpts.onAudioMenuBtnClicked || null;

    function onInviteBtnClicked(result) {
      if(_onInvitebuttonclickedcb){
        var handleObj = new Object();
        handleObj.bHandled = false;
        _onInvitebuttonclickedcb(handleObj);
        return handleObj.bHandled;
      }
    }

    function onStartShareBtnClicked() {
      if (_onStartShareBtnClicked) {
        _onStartShareBtnClicked()
      }
    }

    function onEndMeetingBtnClicked() {
      if (_onEndMeetingBtnClicked) {
        _onEndMeetingBtnClicked()
      }
    }

    function onParticipantListBtnClicked() {
      if (_onParticipantListBtnClicked) {
        _onParticipantListBtnClicked()
      }
    }

    function onCustomLiveStreamMenuClicked() {
      if (_onCustomLiveStreamMenuClicked) {
        _onCustomLiveStreamMenuClicked()
      }
    }

    function onZoomInviteDialogFailed() {
      if (_onZoomInviteDialogFailed) {
        _onZoomInviteDialogFailed()
      }
    }

    function onCCBTNClicked() {
      if (_onCCBTNClicked) {
        _onCCBTNClicked()
      }
    }

    function onAudioBtnClicked(info) {
      if (_onAudioBtnClicked) {
        _onAudioBtnClicked(info)
      }
    }

    function onAudioMenuBtnClicked() {
      if (_onAudioMenuBtnClicked) {
        _onAudioMenuBtnClicked()
      }
    }

    if (_addon) {
      _addon.SetInviteButtonClickedCB(onInviteBtnClicked);
      _addon.SetonStartShareBtnClickedCB(onStartShareBtnClicked);
      _addon.SetonEndMeetingBtnClickedCB(onEndMeetingBtnClicked);
      _addon.SetonParticipantListBtnClickedCB(onParticipantListBtnClicked);
      _addon.SetonCustomLiveStreamMenuClickedCB(onCustomLiveStreamMenuClicked);
      _addon.SetonZoomInviteDialogFailedCB(onZoomInviteDialogFailed);
      _addon.SetonCCBTNClickedCB(onCCBTNClicked);
      _addon.SetonAudioBTNClickedCB(onAudioBtnClicked);
      _addon.SetonAudioMenuBTNClickedCB(onAudioMenuBtnClicked);
    }

    return {
      // Public methods and variables
      /**
      * mode: Set Invite Button Clicked CB
      * @param {Function} onInviteBtnClicked
      * @return {Boolean}
      */
      MeetingUI_SetInviteButtonClickedCB: function (onInviteBtnClicked) {
        if (_addon && onInviteBtnClicked && onInviteBtnClicked instanceof Function) {
          _onInviteBtnClicked = onInviteBtnClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on Start Share Btn Clicked CB
      * @param {Function} onStartShareBtnClicked
      * @return {Boolean}
      */
      MeetingUI_SetonStartShareBtnClickedCB: function (onStartShareBtnClicked) {
        if (_addon && onStartShareBtnClicked && onStartShareBtnClicked instanceof Function) {
          _onStartShareBtnClicked = onStartShareBtnClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on End Meeting Btn Clicked CB
      * @param {Function} onEndMeetingBtnClicked
      * @return {Boolean}
      */
      MeetingUI_SetonEndMeetingBtnClickedCB: function (onEndMeetingBtnClicked) {
        if (_addon && onEndMeetingBtnClicked && onEndMeetingBtnClicked instanceof Function) {
          _onEndMeetingBtnClicked = onEndMeetingBtnClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on Participant List Btn Clicked CB
      * @param {Function} onParticipantListBtnClicked
      * @return {Boolean}
      */
      MeetingUI_SetonParticipantListBtnClickedCB: function (onParticipantListBtnClicked) {
        if (_addon && onParticipantListBtnClicked && onParticipantListBtnClicked instanceof Function) {
          _onParticipantListBtnClicked = onParticipantListBtnClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on Custom Live Stream Menu Clicked CB
      * @param {Function} onCustomLiveStreamMenuClicked
      * @return {ZoomSDKError}
      */
      MeetingUI_SetonCustomLiveStreamMenuClickedCB: function (onCustomLiveStreamMenuClicked) {
        if (_addon && onCustomLiveStreamMenuClicked && onCustomLiveStreamMenuClicked instanceof Function) {
          _onCustomLiveStreamMenuClicked = onCustomLiveStreamMenuClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on Zoom Invite Dialog Failed CB
      * @param {Function} onZoomInviteDialogFailed
      * @return {Boolean}
      */
      MeetingUI_SetonZoomInviteDialogFailedCB: function (onZoomInviteDialogFailed) {
        if (_addon && onZoomInviteDialogFailed && onZoomInviteDialogFailed instanceof Function) {
          _onZoomInviteDialogFailed = onZoomInviteDialogFailed;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on CCBTN Clicked CB
      * @param {Function} onCCBTNClicked
      * @return {Boolean}
      */
      MeetingUI_SetonCCBTNClickedCB: function (onCCBTNClicked) {
        if (_addon && onCCBTNClicked && onCCBTNClicked instanceof Function) {
          _onCCBTNClicked = onCCBTNClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on Audio BTN Clicked CB
      * @param {Function} onAudioBtnClicked
      * @return {Boolean}
      */
      MeetingUI_SetonAudioBTNClickedCB: function (onAudioBtnClicked) {
        if (_addon && onCCBTNClicked && onCCBTNClicked instanceof Function) {
          _onAudioBtnClicked = onAudioBtnClicked;
          return true;
        }
        return false;
      },
      /**
      * mode: Set on Audio BTN Clicked CB
      * @param {Function} onAudioMenuBtnClicked
      * @return {Boolean}
      */
      MeetingUI_SetonAudioMenuBTNClickedCB: function (onAudioMenuBtnClicked) {
        if (_addon && onAudioMenuBtnClicked && onAudioMenuBtnClicked instanceof Function) {
          _onAudioMenuBtnClicked = onAudioMenuBtnClicked;
          return true;
        }
        return false;
      },
      /** 
      * mode: Show inmeeting chat window
      * @param {String} hParent parent window handle (require hexadecimal)
      * @param {String} left chat window left pos
      * @param {String} top chat window top pos
      * @param {String} right chat window right pos
      * @param {String} bottom chat window bottom pos
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowChatDlg: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let hParent = clientOpts.hParent || '0';
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          let right = clientOpts.right || '0';
          let bottom = clientOpts.bottom || '0';
          try {
            let ShowChatDlgParams = new messages.ShowChatDlgParams();
            ShowChatDlgParams.setHparent(hParent);
            ShowChatDlgParams.setRectleft(left);
            ShowChatDlgParams.setRecttop(top);
            ShowChatDlgParams.setRectright(right);
            ShowChatDlgParams.setRectbottom(bottom);
            let bytes = ShowChatDlgParams.serializeBinary();
            return _addon.ShowChatDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Hide inmeeting chat window
      * @return {ZoomSDKError}
      */
      MeetingUI_HideChatDlg: function () {
        if (_addon){
          return _addon.HideChatDlg();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enter full screen mode
      * @param {String} viewtype: view type of the meeting ui, define at ZoomMeetingUIViewType
      * @return {ZoomSDKError}
      */
      MeetingUI_EnterFullScreen: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let bFirstView = (ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR == viewtype) ? true : false;
          let bSecView = (ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR == viewtype) ? false : true;
          try {
            let EnterFullScreenParams = new messages.EnterFullScreenParams();
            EnterFullScreenParams.setBfirstview(bFirstView);
            EnterFullScreenParams.setBsecview(bSecView);
            let bytes = EnterFullScreenParams.serializeBinary();
            return _addon.EnterFullScreen(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Exit full screen mode
      * @param {String} viewtype: view type of the meeting ui, define at ZoomMeetingUIViewType
      * @return {ZoomSDKError}
      */
      MeetingUI_ExitFullScreen: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let bFirstView = (ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR == viewtype) ? true : false;
          let bSecView = (ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR == viewtype) ? false : true;
          try {
            let ExitFullScreenParams = new messages.ExitFullScreenParams();
            ExitFullScreenParams.setBfirstview(bFirstView);
            ExitFullScreenParams.setBsecview(bSecView);
            let bytes = ExitFullScreenParams.serializeBinary();
            return _addon.ExitFullScreen(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Switch to video wall mode
      * @return {ZoomSDKError}
      */
      MeetingUI_SwitchToVideoWall: function () {
        if (_addon) {
          return _addon.SwitchToVideoWall();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Switch to active speaker mode
      * @return {ZoomSDKError}
      */
      MeetingUI_SwtichToAcitveSpeaker: function () {
        if (_addon){
          return _addon.SwtichToAcitveSpeaker();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Move float video window
      * @param {String} left chat window left pos
      * @param {String} top chat window top pos
      * @return {ZoomSDKError}
      */
      MeetingUI_MoveFloatVideoWnd : function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let left = clientOpts.left || 0;
          let top = clientOpts.top || 0;
          try {
            let MoveFloatVideoWndParams = new messages.MoveFloatVideoWndParams();
            MoveFloatVideoWndParams.setLeft(left);
            MoveFloatVideoWndParams.setTop(top);
            let bytes = MoveFloatVideoWndParams.serializeBinary();
            return _addon.MoveFloatVideoWnd(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Show or hide the toolbar of sharing
      * @param {Boolean} show: show or not
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowSharingToolbar : function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let show = clientOpts.show;
          try {
            let ShowSharingToolbarParams = new messages.ShowSharingToolbarParams();
            ShowSharingToolbarParams.setBshow(show);
            let bytes = ShowSharingToolbarParams.serializeBinary();
            return _addon.ShowSharingToolbar(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Switch float video to active speaker mode
      * @return {ZoomSDKError}
      */
      MeetingUI_SwitchFloatVideoToActiveSpkMod: function () {
        if (_addon){
          return _addon.SwitchFloatVideoToActiveSpkMod();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;       
      },
      /** 
      * mode: Switch float video to gallery mode
      * @return {ZoomSDKError}
      */
      MeetingUI_SwitchFloatVideoToGalleryMod: function() {
        if (_addon){
          return _addon.SwitchFloatVideoToGalleryMod();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Change float active speaker window type and size
      * @param {String} floatvideotype the type of float active speaker window, define at ZoomMeetingUIFloatVideoType
      * @return {ZoomSDKError}
      */
      MeetingUI_ChangeFloatoActiveSpkVideoSize: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let floatvideotype = clientOpts.floatvideotype || ZoomMeetingUIFloatVideoType.FLOATVIDEO_Small;
          try {
            let ChangeFloatoActiveSpkVideoSizeParams = new messages.ChangeFloatoActiveSpkVideoSizeParams();
            ChangeFloatoActiveSpkVideoSizeParams.setFloatvideotype(floatvideotype);
            let bytes = ChangeFloatoActiveSpkVideoSizeParams.serializeBinary();
            return _addon.ChangeFloatoActiveSpkVideoSize(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Show or hide the window of participants list
      * @param {String} show show or not
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowParticipantsListWnd: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let show = clientOpts.show;
          try {
            let ShowParticipantsListWndParams = new messages.ShowParticipantsListWndParams();
            ShowParticipantsListWndParams.setBshow(show);
            let bytes = ShowParticipantsListWndParams.serializeBinary();
            return _addon.ShowParticipantsListWnd(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Show or hide the window of bottom float tool bar
      * @param {String} show show or not
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowBottomFloatToolbarWnd: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let show = clientOpts.show;
          try {
            let ShowBottomFloatToolbarWndParams = new messages.ShowBottomFloatToolbarWndParams();
            ShowBottomFloatToolbarWndParams.setBshow(show);
            let bytes = ShowBottomFloatToolbarWndParams.serializeBinary();
            return _addon.ShowBottomFloatToolbarWnd(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Show join audio dialog
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowJoinAudioDlg: function() {
        if (_addon) {
          return _addon.ShowJoinAudioDlg();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE; 
      },
      /**
      * mode: Hide join audio dialog
      * @return {ZoomSDKError}
      */
      MeetingUI_HideJoinAudioDlg: function() {
        if (_addon){
          return _addon.HideJoinAudioDlg();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Wall View Page Info
      * @return {ZoomSDKError}
      */
      MeetingUI_GetWallViewPageInfo: function() {
        if (_addon) {
          return _addon.GetWallViewPageInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Show Pre Or Next Page Video
      * @param {Boolean} show: show or not
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowPreOrNextPageVideo: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let show = clientOpts.show;
          try {
            let ShowPreOrNextPageVideoParams = new messages.ShowPreOrNextPageVideoParams();
            ShowPreOrNextPageVideoParams.setBpageup(show);
            let bytes = ShowPreOrNextPageVideoParams.serializeBinary();
            return _addon.ShowPreOrNextPageVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Show Sharing Frame Windows
      * @param {Boolean} show: show or not
      * @return {ZoomSDKError}
      */
      MeetingUI_ShowSharingFrameWindows: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let show = clientOpts.show;
          try {
            let ShowSharingFrameWindowsParams = new messages.ShowSharingFrameWindowsParams();
            ShowSharingFrameWindowsParams.setBshow(show);
            let bytes = ShowSharingFrameWindowsParams.serializeBinary();
            return _addon.ShowSharingFrameWindows(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Current Split ScreenMode Info
      * @return {ZoomSDKError}
      */
      MeetingUI_GetCurrentSplitScreenModeInfo: function() {
        if (_addon) {
          return _addon.GetCurrentSplitScreenModeInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Switch Split Screen Mode
      * @param {Boolean} isSwitch: switch or not
      * @return {ZoomSDKError}
      */
      MeetingUI_SwitchSplitScreenMode: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let isSwitch = clientOpts.isSwitch;
          try {
            let SwitchSplitScreenModeParams = new messages.SwitchSplitScreenModeParams();
            SwitchSplitScreenModeParams.setBsplit(isSwitch);
            let bytes = SwitchSplitScreenModeParams.serializeBinary();
            return _addon.SwitchSplitScreenMode(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Active the principal window of meeting and place it on top
      * @return {ZoomSDKError}
      */
      MeetingUI_BackToMeeting: function() {
        if (_addon) {
          return _addon.BackToMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Get the window handle of the meeting user interface. This interface is only valid on Windows
        * @return {ZoomSDKError} If the function succeeds, "hFirstView" the window handle(hex) of the meeting user interface displayed by the first view,
        * and "hSecondView" the window handle(hex) of the meeting user interface displayed by the second view
        */
      MeetingUI_GetMeetingUIWnd: function() {
        if (_addon) {
          return _addon.GetMeetingUIWnd();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Change the display mode of the minimized meeting window for the first view
        * @param {Number} mode mode(number) Specifies the minimized mode. For more details, see ZNSDKMinimizeUIMode
        * @return {ZoomSDKError}
        */
      MeetingUI_SwitchMinimizeUIMode4FristScreenMeetingUIWnd: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let mode = clientOpts.mode;
          try {
            let SwitchMinimizeUIMode4FirstScreenMeetingUIWndParams = new messages.SwitchMinimizeUIMode4FirstScreenMeetingUIWndParams();
            SwitchMinimizeUIMode4FirstScreenMeetingUIWndParams.setMinimizeuimode(mode);
            let bytes = SwitchMinimizeUIMode4FirstScreenMeetingUIWndParams.serializeBinary();
            return _addon.SwitchMinimizeUIMode4FristScreenMeetingUIWnd(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Determines the minimize state of the first view
        * @return {ZoomSDKError} If the function succeeds, the return value is a object which includes "bIsMinimizMode", TRUE indicates the minimize state, FALSE not
        */
      MeetingUI_IsMinimizeModeOfFristScreenMeetingUIWnd: function() {
        if (_addon) {
          return _addon.IsMinimizeModeOfFristScreenMeetingUIWnd();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: when someone else shares, and meeting window is not full screen. you can call the api to switch video & share display postion
        * @param {Boolean} mode 0 means to display share, otherwise video
        * @return {ZoomSDKError}
        */
      MeetingUI_SwapToShowShareViewOrVideo: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bToDisplayShare = clientOpts.bToDisplayShare;
          try {
            let SwapToShowShareViewOrVideoParams = new messages.SwapToShowShareViewOrVideoParams();
            SwapToShowShareViewOrVideoParams.setBtodisplayshare(bToDisplayShare);
            let bytes = SwapToShowShareViewOrVideoParams.serializeBinary();
            return _addon.SwapToShowShareViewOrVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Determine if the meeting is displaying the sharing screen now
        * @return {ZoomSDKError} 0 means is showing sharing screen, otherwise means is showing video
        */
      MeetingUI_IsDisplayingShareViewOrVideo: function() {
        if (_addon) {
          return _addon.IsDisplayingShareViewOrVideo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Determine if the user can swap to show sharing screen or video now
        * @return {ZoomSDKError} 0 means Can, otherwise not
        */
      MeetingUI_CanSwapToShowShareViewOrVideo: function() {
        if (_addon) {
          return _addon.CanSwapToShowShareViewOrVideo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Service Module
     * @return {ZoomMeetingUICtrl}
    */
    getInstance: function(opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomMeetingUICtrl: ZoomMeetingUICtrl
}
