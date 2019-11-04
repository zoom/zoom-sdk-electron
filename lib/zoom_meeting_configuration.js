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
      * @param {String} left Float Video left pos
      * @param {String} top Float Video pos
      * @param {String} hSelfWnd SelfWnd (require hexadecimal)
      * @param {String} hParent parent window handle (require hexadecimal)
      * @return {ZoomSDKError}
      */
      MeetingConfig_SetFloatVideoPos: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          return _addon.SetFloatVideoPos(left, top, hSelfWnd, hParent);
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
       * @param {String} left Float Video left pos
       * @param {String} top Float Video pos
       * @param {String} hSelfWnd (require hexadecimal)
       * @param {String} hParent (require hexadecimal)
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetMeetingUIPos: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          return _addon.SetMeetingUIPos(left, top, hSelfWnd, hParent);
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
       * mode: Reset the meeting configuration and back to the default state
       * @return {ZoomSDKError}
       */
      MeetingConfig_Reset: function () {
        if (_addon) {
          return _addon.Reset();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set if it is able to auto-adjust the volume of the speaker when joining the meeting
       * @param {Boolean} bEnable TRUE indicates to auto-adjust the volume of the speaker. FALSE not
       * @return {ZoomSDKError} If it is 0, the SDK will adjust the speaker volume automatically. It will unmute if the speaker was muted.
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
       * mode: Set if it is able to auto-adjust the volume of the mic when joining the meeting
       * @param {Boolean} bEnable TRUE indicates to auto-adjust the volume of the mic. FALSE not
       * @return {ZoomSDKError} If it is 0, the SDK will adjust the mic volume automatically. It will unmute if the mic was muted
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
       * mode: Configure DSCP(Differential services code point) values
       * @param {Number} dscpAudio Configure DSCP value for audio
       * @param {Number} dscpVideo Configure DSCP value for video
       * @param {Boolean} bReset Reset DSCP values. This param is just used for Windows. For Mac, you can pass TRUE or FALSE as you like
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
       * mode: Set if it is able to display the full phone number for the user who joins the meeting with phone. Default: FALSE
       * @param {Boolean} bHide TRUE indicates to hide the partial phone number. FALSE not
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
       * mode: Set if it is able to limit the length of meeting ID. Default: FALSE
       * @param {Boolean} bEnable TRUE indicates to limit the length of meeting ID. FALSE not
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
       * mode: Set if it is able to share IOS device. Default: FALSE
       * @param {Boolean} bEnable TRUE indicates to enable to share. FALSE not
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
       * mode: Set if it is able to share white board. Default: TRUE
       * @param {Boolean} bEnable TRUE indicates to enable to share on the white board. FALSE not
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
       * mode: Set whether to forbid multi-share. Default: FALSE
       * @param {Boolean} bDisable TRUE indicates to forbid multi-share. FALSE not
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
       * mode: Set the maximum duration of the meeting when there is no attendee in the meeting. Default: 24*60
       * @param {Number} nDuration Specify the maximum duration in minutes
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetMaxDurationForOnlyHostInMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let nDuration = clientOpts.nDuration;
          return _addon.SetMaxDurationForOnlyHostInMeeting(Number(nDuration));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set the visibility of the local recording convert progress bar dialog. Default: TRUE
       * @param {Boolean} bShow TRUE indicates to show the dialog box. FALSE not
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableLocalRecordingConvertProgressBarDialog: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bShow = clientOpts.bShow;
          return _addon.EnableLocalRecordingConvertProgressBarDialog(Boolean(bShow));
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