const { ZoomSDKError } = require('./settings.js');

var ZoomMeetingConfiguration = (function () {
  var instance;
   /**
   * mode: Zoom SDK Meeting configuration module Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingConfiguration}
   */
  function init(opts) {
    var clientOpts = opts || {};
    // Private methods and variables
    var _addon = clientOpts.addon.GetMeetingConfigCtrl() || null;   

    function onFreeMeetingNeedToUpgrade(result) {
      console.log('onFreeMeetingNeedToUpgrade', result);
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStart(result) {
      console.log('onFreeMeetingUpgradeToGiftFreeTrialStart', result);
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStop(result) {
      console.log('onFreeMeetingUpgradeToGiftFreeTrialStop', result);
    }

    function onFreeMeetingUpgradeToProMeeting(result) {
      console.log('onFreeMeetingUpgradeToProMeeting', result);
    }

    if (_addon) {
      _addon.SetFreeMeetingNeedToUpgradeCB(onFreeMeetingNeedToUpgrade);
      _addon.SetFreeMeetingUpgradeToGiftFreeTrialStartCB(onFreeMeetingUpgradeToGiftFreeTrialStart);
      _addon.SetFreeMeetingUpgradeToGiftFreeTrialStopCB(onFreeMeetingUpgradeToGiftFreeTrialStop);
      _addon.SetFreeMeetingUpgradeToProMeetingCB(onFreeMeetingUpgradeToProMeeting);
    }

    return {
    // Public methods and variables
    /** 
      * mode: Set the visibility of Invite button in te toolbar
      * @param {Boolean} bEnable show or not
      * @return {ZoomSDKError}
      */
      MeetingConfig_EnableInviteButtonOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableInviteButtonOnMeetingUI(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },	
      /** 
      * mode: Set Float VideoPos
      * @param {String} hSelfWnd SelfWnd (require hexadecimal)
      * @param {String} hParent parent window handle (require hexadecimal)
      * @param {String} left Float Video left pos
      * @param {String} top Float Video pos
      * @return {ZoomSDKError}
      */
      MeetingConfig_SetFloatVideoPos: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          return _addon.SetFloatVideoPos(hSelfWnd, hParent, left, top);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Set visibility of the meeting bottom float toolbar 
      * @param {Boolean} bShow show or not
      * @return {ZoomSDKError}
      */
      MeetingConfig_SetBottomFloatToolbarWndVisibility: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bShow = clientOpts.bShow;
          return _addon.SetBottomFloatToolbarWndVisibility(bShow);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Set Sharing Toolbar Visibility 
      * @param {Boolean} bShow show or not
      * @return {ZoomSDKError}
      */
      MeetingConfig_SetSharingToolbarVisibility: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bShow = clientOpts.bShow;
          return _addon.SetSharingToolbarVisibility(bShow);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Set Direct Share MonitorID:
      * @param {String} monitorID
      * @return {ZoomSDKError}
      */
      MeetingConfig_SetDirectShareMonitorID: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let monitorID = clientOpts.monitorID;
          return _addon.SetDirectShareMonitorID(monitorID);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Meeting UI Pos
       * @param {String} hSelfWnd (require hexadecimal)
       * @param {String} hParent (require hexadecimal)
       * @param {String} left Float Video left pos
       * @param {String} top Float Video pos
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetMeetingUIPos: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          return _addon.SetMeetingUIPos(hSelfWnd, hParent, left, top);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Disable Waiting For Host Dialog
      * @param {Boolean} bDisable disable or enable 
      * @return {ZoomSDKError}
      */
      MeetingConfig_DisableWaitingForHostDialog: function (opts) {
        if (_addon) {
          let clientOpts = opts || {}
          let bDisable = clientOpts.bDisable
          return _addon.DisableWaitingForHostDialog(bDisable)
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** 
      * mode: Hide Meeting Info From Meeting UI Title
      * @param {Boolean} bHide Hide or not
      * @return {ZoomSDKError}
      */
      MeetingConfig_HideMeetingInfoFromMeetingUITitle: function (opts) {
        if (_addon) {
          let clientOpts = opts || {}
          let bHide = clientOpts.bHide
          return _addon.HideMeetingInfoFromMeetingUITitle(bHide)
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** 
      * mode: Set Meeting ID For Meeting UI Title
      * @param {Number} meetingNumber
      * @return {ZoomSDKError}
      */
      MeetingConfig_SetMeetingIDForMeetingUITitle: function (opts) {
        if (_addon) {
          let clientOpts = opts || {}
          let meetingNumber = clientOpts.meetingNumber
          return _addon.SetMeetingIDForMeetingUITitle(Number(meetingNumber));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** 
      * mode: Disable Popup Meeting Wrong PSW Dlg
      * @param {Boolean} bDisable disable or enable 
      * @return {ZoomSDKError}
      */
      MeetingConfig_DisablePopupMeetingWrongPSWDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          return _addon.DisablePopupMeetingWrongPSWDlg(bDisable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Auto End Other Meeting When Start Meeting
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      MeetingConfig_EnableAutoEndOtherMeetingWhenStartMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAutoEndOtherMeetingWhenStartMeeting(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Button DB Click Switch Full Screen Mode
       * @param {Boolean} bEnable Enable or not
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableLButtonDBClick4SwitchFullScreenMode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableLButtonDBClick4SwitchFullScreenMode(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Float Video Wnd Visibility
       * @param {Boolean} bShow show or not
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFloatVideoWndVisibility: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bShow = clientOpts.bShow;
          return _addon.SetFloatVideoWndVisibility(bShow);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Pre Populate Webinar Registration Information
       * @param {String} email
       * @param {String} userName
       * @return {ZoomSDKError}
       */
      MeetingConfig_PrePopulateWebinarRegistrationInfo: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var email = clientOpts.email;
          var userName = clientOpts.userName;
          return _addon.PrePopulateWebinarRegistrationInfo(email, userName);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Reset
       * @return {ZoomSDKError}
       */
      MeetingConfig_Reset: function () {
        if (_addon) {
          return _addon.Reset();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Auto Adjust Speaker Volume When Join Audio
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableAutoAdjustSpeakerVolumeWhenJoinAudio: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Auto Adjust Mic Volume When Join Audio
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableAutoAdjustMicVolumeWhenJoinAudio: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAutoAdjustMicVolumeWhenJoinAudio(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Config DSCP
       * @param {Number} dscpAudio
       * @param {Number} dscpVideo
       * @param {Boolean} bReset
       * @return {ZoomSDKError}
       */
      MeetingConfig_ConfigDSCP: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let dscpAudio = clientOpts.dscpAudio;
          let dscpVideo = clientOpts.dscpVideo;
          let bReset = clientOpts.bReset;
          return _addon.ConfigDSCP(Number(dscpAudio), Number(dscpVideo), bReset);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Remote Ctrl Copy Paste Feature
       * @param {Boolean} bDisable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableRemoteCtrlCopyPasteFeature: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          return _addon.DisableRemoteCtrlCopyPasteFeature(bDisable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enableb Hide Full Phone Number 4 Pure Call in User
       * @param {Boolean} bHide
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableHideFullPhoneNumber4PureCallinUser: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bHide = clientOpts.bHide;
          return _addon.EnableHideFullPhoneNumber4PureCallinUser(bHide);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Length Limitation Of Meeting Number
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableLengthLimitationOfMeetingNumber: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableLengthLimitationOfMeetingNumber(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Share IOS Device
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableShareIOSDevice: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableShareIOSDevice(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
       /** 
       * mode: Enable Share White Board
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableShareWhiteBoard: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableShareWhiteBoard(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
       /** 
       * mode: Force Disable Multi Share
       * @param {Boolean} bDisable
       * @return {ZoomSDKError}
       */
      MeetingConfig_ForceDisableMultiShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          return _addon.ForceDisableMultiShare(bDisable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
       /** 
       * mode: Set Max Duration For Only Host InMeeting
       * @param {Boolean} bDisable
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetMaxDurationForOnlyHostInMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let nDuration = clientOpts.nDuration;
          return _addon.SetMaxDurationForOnlyHostInMeeting(Number(nDuration));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Configuration Module
     * @return {ZoomMeetingConfiguration}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomMeetingConfiguration: ZoomMeetingConfiguration
}