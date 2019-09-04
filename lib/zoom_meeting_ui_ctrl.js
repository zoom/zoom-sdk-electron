const { ZoomMeetingUIViewType, ZoomMeetingUIFloatVideoType, ZoomSDKError } = require('./settings.js');

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

    function onInviteBtnClicked(result) {
      console.log('onInviteBtnClicked', result);
    }

    if (_addon) {
      _addon.SetInviteButtonClickedCB(onInviteBtnClicked);
    }

    return {
      // Public methods and variables
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
          return _addon.ShowChatDlg(hParent, left, top, right, bottom);
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
          return _addon.EnterFullScreen(bFirstView, bSecView);
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
          return _addon.ExitFullScreen(bFirstView, bSecView);
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
          return _addon.MoveFloatVideoWnd(left, top);
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
          return _addon.ShowSharingToolbar(show);
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
          return _addon.ChangeFloatoActiveSpkVideoSize(floatvideotype);
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
          return _addon.ShowParticipantsListWnd(show);
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
          return _addon.ShowBottomFloatToolbarWnd(show);
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
      * @param {String} currentPage
      * @param {String} totalPages
      * @return {ZoomSDKError}
      */
      MeetingUI_GetWallViewPageInfo: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let currentPage = clientOpts.currentPage;
          let totalPages = clientOpts.totalPages;
          return _addon.GetWallViewPageInfo(currentPage, totalPages);
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
          return _addon.ShowPreOrNextPageVideo(show);
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
          return _addon.ShowSharingFrameWindows(show);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Current Split ScreenMode Info
      * @param {Boolean} bZNSupportSplitScreen
      * @param {Boolean} bZNInSplitScreenMode
      * @return {ZoomSDKError}
      */
      MeetingUI_GetCurrentSplitScreenModeInfo: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bZNSupportSplitScreen = clientOpts.bZNSupportSplitScreen;
          let bZNInSplitScreenMode = clientOpts.bZNInSplitScreenMode;
          return _addon.GetCurrentSplitScreenModeInfo(bZNSupportSplitScreen, bZNInSplitScreenMode);
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
          return _addon.SwitchSplitScreenMode(isSwitch);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Back To Meeting
        * @return {ZoomSDKError}
        */
      MeetingUI_BackToMeeting: function() {
        if (_addon) {
          return _addon.BackToMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Get Meeting UIWnd
        * @return {ZoomSDKError}
        */
      MeetingUI_GetMeetingUIWnd: function() {
        if (_addon) {
          return _addon.GetMeetingUIWnd();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Switch Minimize UIMode4 Frist Screen MeetingUIWnd
        * @param {Number} mode
        * @return {ZoomSDKError}
        */
      MeetingUI_SwitchMinimizeUIMode4FristScreenMeetingUIWnd: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let mode = clientOpts.mode;
          return _addon.SwitchMinimizeUIMode4FristScreenMeetingUIWnd(Number(mode));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Is Minimize Mode Of Frist ScreenMeetingUIWnd
        * @return {ZoomSDKError}
        */
      MeetingUI_IsMinimizeModeOfFristScreenMeetingUIWnd: function() {
        if (_addon) {
          return _addon.IsMinimizeModeOfFristScreenMeetingUIWnd();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Swap To Show Share View Or Video
        * @param {Boolean} mode
        * @return {ZoomSDKError}
        */
      MeetingUI_SwapToShowShareViewOrVideo: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bToDisplayShare = clientOpts.bToDisplayShare;
          return _addon.SwapToShowShareViewOrVideo(bToDisplayShare);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Is Displaying Share View Or Video
        * @return {ZoomSDKError}
        */
      MeetingUI_IsDisplayingShareViewOrVideo: function() {
        if (_addon) {
          return _addon.IsDisplayingShareViewOrVideo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Can Swap To Show Share View Or Video
        * @return {ZoomSDKError}
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
