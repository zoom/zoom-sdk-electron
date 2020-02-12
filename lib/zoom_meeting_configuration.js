const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
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
    let _onFreeMeetingNeedToUpgrade = clientOpts.onFreeMeetingNeedToUpgrade || null;
    let _onFreeMeetingUpgradeToGiftFreeTrialStart = clientOpts.onFreeMeetingUpgradeToGiftFreeTrialStart || null;
    let _onFreeMeetingUpgradeToGiftFreeTrialStop = clientOpts.onFreeMeetingUpgradeToGiftFreeTrialStop || null;
    let _onFreeMeetingUpgradeToProMeeting = clientOpts.onFreeMeetingUpgradeToProMeeting || null;
    let _onInputMeetingPasswordAndScreenNameNotification = clientOpts.onInputMeetingPasswordAndScreenNameNotification || null;
    let _onAirPlayInstructionWndNotification = clientOpts.onAirPlayInstructionWndNotification || null;
    let _onWebinarNeedRegisterNotification = clientOpts.onWebinarNeedRegisterNotification || null;
    let _onEndOtherMeetingToJoinMeetingNotification = clientOpts.onEndOtherMeetingToJoinMeetingNotification || null;
    let _onFreeMeetingRemainTime = clientOpts.onFreeMeetingRemainTime || null;
    let _onFreeMeetingRemainTimeStopCountDown = clientOpts.onFreeMeetingRemainTimeStopCountDown || null;

    function onFreeMeetingNeedToUpgrade(type, gift_url) {
      if (_onFreeMeetingNeedToUpgrade) {
        _onFreeMeetingNeedToUpgrade(type, gift_url)
      }
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStart() {
      if (_onFreeMeetingUpgradeToGiftFreeTrialStart) {
        _onFreeMeetingUpgradeToGiftFreeTrialStart()
      }
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStop() {
      if (_onFreeMeetingUpgradeToGiftFreeTrialStop) {
        _onFreeMeetingUpgradeToGiftFreeTrialStop()
      }
    }

    function onFreeMeetingUpgradeToProMeeting() {
      if (_onFreeMeetingUpgradeToProMeeting) {
        _onFreeMeetingUpgradeToProMeeting()
      }
    }

    function onInputMeetingPasswordAndScreenNameNotification() {
      if (_onInputMeetingPasswordAndScreenNameNotification) {
        _onInputMeetingPasswordAndScreenNameNotification()
      }
    }

    function onAirPlayInstructionWndNotification(bShow, airhostName) {
      if (_onAirPlayInstructionWndNotification) {
        _onAirPlayInstructionWndNotification(bShow, airhostName)
      }
    }

    function onWebinarNeedRegisterNotification() {
      if (_onWebinarNeedRegisterNotification) {
        _onWebinarNeedRegisterNotification()
      }
    }

    function onEndOtherMeetingToJoinMeetingNotification() {
      if (_onEndOtherMeetingToJoinMeetingNotification) {
        _onEndOtherMeetingToJoinMeetingNotification()
      }
    }

    function onFreeMeetingRemainTime(leftTime) {
      if (_onFreeMeetingRemainTime) {
        _onFreeMeetingRemainTime(leftTime)
      }
    }

    function onFreeMeetingRemainTimeStopCountDown() {
      if (_onFreeMeetingRemainTimeStopCountDown) {
        _onFreeMeetingRemainTimeStopCountDown()
      }
    }

    if (_addon) {
      _addon.SetFreeMeetingNeedToUpgradeCB(onFreeMeetingNeedToUpgrade);
      _addon.SetFreeMeetingUpgradeToGiftFreeTrialStartCB(onFreeMeetingUpgradeToGiftFreeTrialStart);
      _addon.SetFreeMeetingUpgradeToGiftFreeTrialStopCB(onFreeMeetingUpgradeToGiftFreeTrialStop);
      _addon.SetFreeMeetingUpgradeToProMeetingCB(onFreeMeetingUpgradeToProMeeting);
      _addon.SetInputMeetingPasswordAndScreenNameNotificationCB(onInputMeetingPasswordAndScreenNameNotification);
      _addon.SetAirPlayInstructionWndNotificationCB(onAirPlayInstructionWndNotification);
      _addon.SetonWebinarNeedRegisterNotificationCB(onWebinarNeedRegisterNotification);
      _addon.SetonEndOtherMeetingToJoinMeetingNotificationCB(onEndOtherMeetingToJoinMeetingNotification);
      _addon.SetonFreeMeetingRemainTimeCB(onFreeMeetingRemainTime);
      _addon.SetonFreeMeetingRemainTimeStopCountDownCB(onFreeMeetingRemainTimeStopCountDown);
    }

    return {
      // Public methods and variables
      /**
       * mode: Set Free Meeting Need To Upgrade CB
       * @param {Function} onFreeMeetingNeedToUpgrade
       * @return {Boolean}
       */
      MeetingConfig_SetFreeMeetingNeedToUpgradeCB: function (onFreeMeetingNeedToUpgrade) {
        if (addon && onFreeMeetingNeedToUpgrade && onFreeMeetingNeedToUpgrade instanceof Function) {
          _onFreeMeetingNeedToUpgrade = onFreeMeetingNeedToUpgrade
          return true
        }
        return false
      },
      /**
       * mode: Set Free Meeting Upgrade To Gift Free Trial Start CB
       * @param {Function} onFreeMeetingUpgradeToGiftFreeTrialStart
       * @return {Boolean}
       */
      MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStartCB: function (onFreeMeetingUpgradeToGiftFreeTrialStart) {
        if (addon && onFreeMeetingUpgradeToGiftFreeTrialStart && onFreeMeetingUpgradeToGiftFreeTrialStart instanceof Function) {
          _onFreeMeetingUpgradeToGiftFreeTrialStart = onFreeMeetingUpgradeToGiftFreeTrialStart
          return true
        }
        return false
      },
      /**
       * mode: Set Free Meeting Upgrade To Gift Free Trial Stop CB
       * @param {Function} onFreeMeetingUpgradeToGiftFreeTrialStop
       * @return {Boolean}
       */
      MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStopCB: function (onFreeMeetingUpgradeToGiftFreeTrialStop) {
        if (addon && onFreeMeetingUpgradeToGiftFreeTrialStop && onFreeMeetingUpgradeToGiftFreeTrialStop instanceof Function) {
          _onFreeMeetingUpgradeToGiftFreeTrialStop = onFreeMeetingUpgradeToGiftFreeTrialStop
          return true
        }
        return false
      },
      /**
       * mode: Set Free Meeting Upgrade To Pro Meeting CB
       * @param {Function} onFreeMeetingUpgradeToProMeeting
       * @return {Boolean}
       */
      MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB: function (onFreeMeetingUpgradeToProMeeting) {
        if (addon && onFreeMeetingUpgradeToProMeeting && onFreeMeetingUpgradeToProMeeting instanceof Function) {
          _onFreeMeetingUpgradeToProMeeting = onFreeMeetingUpgradeToProMeeting
          return true
        }
        return false
      },
      /**
       * mode: Set Input Meeting Password And Screen Name Notification CB
       * @param {Function} onInputMeetingPasswordAndScreenNameNotification
       * @return {Boolean}
       */
      MeetingConfig_SetInputMeetingPasswordAndScreenNameNotificationCB: function (onInputMeetingPasswordAndScreenNameNotification) {
        if (addon && onInputMeetingPasswordAndScreenNameNotification && onInputMeetingPasswordAndScreenNameNotification instanceof Function) {
          _onInputMeetingPasswordAndScreenNameNotification = onInputMeetingPasswordAndScreenNameNotification
          return true
        }
        return false
      },
      /**
       * mode: Set Air Play Instruction Wnd Notification CB
       * @param {Function} onAirPlayInstructionWndNotification
       * @return {Boolean}
       */
      MeetingConfig_SetAirPlayInstructionWndNotificationCB: function (onAirPlayInstructionWndNotification) {
        if (addon && onAirPlayInstructionWndNotification && onAirPlayInstructionWndNotification instanceof Function) {
          _onAirPlayInstructionWndNotification = onAirPlayInstructionWndNotification
          return true
        }
        return false
      },
      /**
       * mode: Set on Webinar Need Register Notification CB
       * @param {Function} onWebinarNeedRegisterNotification
       * @return {Boolean}
       */
      MeetingConfig_SetonWebinarNeedRegisterNotificationCB: function (onWebinarNeedRegisterNotification) {
        if (addon && onWebinarNeedRegisterNotification && onWebinarNeedRegisterNotification instanceof Function) {
          _onWebinarNeedRegisterNotification = onWebinarNeedRegisterNotification
          return true
        }
        return false
      },
      /**
       * mode: Set on End Other Meeting To Join Meeting Notification CB
       * @param {Function} onEndOtherMeetingToJoinMeetingNotification
       * @return {Boolean}
       */
      MeetingConfig_SetonEndOtherMeetingToJoinMeetingNotificationCB: function (onEndOtherMeetingToJoinMeetingNotification) {
        if (addon && onEndOtherMeetingToJoinMeetingNotification && onEndOtherMeetingToJoinMeetingNotification instanceof Function) {
          _onEndOtherMeetingToJoinMeetingNotification = onEndOtherMeetingToJoinMeetingNotification
          return true
        }
        return false
      },
      /**
       * mode: Set on Free Meeting Remain Time CB
       * @param {Function} onFreeMeetingRemainTime
       * @return {Boolean}
       */
      MeetingConfig_SetonFreeMeetingRemainTimeCB: function (onFreeMeetingRemainTime) {
        if (addon && onFreeMeetingRemainTime && onFreeMeetingRemainTime instanceof Function) {
          _onFreeMeetingRemainTime = onFreeMeetingRemainTime
          return true
        }
        return false
      },
      /**
       * mode: Set on Free Meeting Remain Time Stop Count Down CB
       * @param {Function} onFreeMeetingRemainTimeStopCountDown
       * @return {Boolean}
       */
      MeetingConfig_SetonFreeMeetingRemainTimeStopCountDownCB: function (onFreeMeetingRemainTimeStopCountDown) {
        if (addon && onFreeMeetingRemainTimeStopCountDown && onFreeMeetingRemainTimeStopCountDown instanceof Function) {
          _onFreeMeetingRemainTimeStopCountDown = onFreeMeetingRemainTimeStopCountDown
          return true
        }
        return false
      },
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
      },
      /** 
       * mode: Enable Approve Remote Control Dlg
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableApproveRemoteControlDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableApproveRemoteControlDlg(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Decline Remote Control Response Dlg
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableDeclineRemoteControlResponseDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableDeclineRemoteControlResponseDlg(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Leave Meeting Option For Host
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableLeaveMeetingOptionForHost: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableLeaveMeetingOptionForHost(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Video Button On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableVideoButtonOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableVideoButtonOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Enter And Exit Full Screen Button On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableEnterAndExitFullScreenButtonOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableEnterAndExitFullScreenButtonOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click Share BTN Event
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickShareBTNEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectClickShareBTNEvent(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click End Meeting BTN Event
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickEndMeetingBTNEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectClickEndMeetingBTNEvent(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Free Meeting Ending Reminder Dlg
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectFreeMeetingEndingReminderDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectFreeMeetingEndingReminderDlg(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click Custom Live Stream Menu Event
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickCustomLiveStreamMenuEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectClickCustomLiveStreamMenuEvent(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click Participant List BTN Event
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickParticipantListBTNEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectClickParticipantListBTNEvent(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click CC BTN Event
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickCCBTNEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectClickCCBTNEvent(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Meeting Warning Msg
       * @param {Boolean} bRedirectBadNetwork
       * @param {Boolean} bRedirectWarnHighCPU
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectMeetingWarningMsg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bRedirectBadNetwork = clientOpts.bRedirectBadNetwork;
          let bRedirectWarnHighCPU = clientOpts.bRedirectWarnHighCPU;
          return _addon.RedirectMeetingWarningMsg(Boolean(bRedirectBadNetwork), Boolean(bRedirectWarnHighCPU));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Tool Tips Show
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableToolTipsShow: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableToolTipsShow(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Airplay Instruction Window
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableAirplayInstructionWindow: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAirplayInstructionWindow(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Claim Host Feature
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableClaimHostFeature: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableClaimHostFeature(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Auto Hide Join Audio Dialog
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableAutoHideJoinAudioDialog: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAutoHideJoinAudioDialog(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Always Show Icon On Task Bar
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_AlwaysShowIconOnTaskBar: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.AlwaysShowIconOnTaskBar(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Split Screen Mode UI Elements
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableSplitScreenModeUIElements: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.DisableSplitScreenModeUIElements(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Show Audio Use Computer Sound Chkbox
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetShowAudioUseComputerSoundChkbox: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.SetShowAudioUseComputerSoundChkbox(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Show Call In Tab
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetShowCallInTab: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.SetShowCallInTab(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Show Call Me Tab
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetShowCallMeTab: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.SetShowCallMeTab(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Always Show Meeting ID On Title
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetAlwaysShowMeetingIDOnTitle: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.SetAlwaysShowMeetingIDOnTitle(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Top Most Attr4 Setting Dialog
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableTopMostAttr4SettingDialog: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.DisableTopMostAttr4SettingDialog(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Grab Share Without Reminder
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableGrabShareWithoutReminder: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableGrabShareWithoutReminder(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Show Share Switch Multi To Single Confirm Dlg
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableShowShareSwitchMultiToSingleConfirmDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableShowShareSwitchMultiToSingleConfirmDlg(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Free Meeting Remain Time Notify
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableFreeMeetingRemainTimeNotify: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.DisableFreeMeetingRemainTimeNotify(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Chat Item On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideChatItemOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideChatItemOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Record Item On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideRecordItemOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideRecordItemOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Upgrade Free Meeting Button
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideUpgradeFreeMeetingButton: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideUpgradeFreeMeetingButton(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Show Invite Dlg Tab Page
       * @param {Number} tabPage
       * @param {Boolean} bShow
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetShowInviteDlgTabPage: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let tabPage = clientOpts.tabPage;
          let bShow = clientOpts.bShow;
          return _addon.SetShowInviteDlgTabPage(Number(tabPage), Boolean(bShow));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Show H323 Sub Tab Page
       * @param {Number} tabPage
       * @param {Boolean} bShow
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetShowH323SubTabPage: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let tabPage = clientOpts.tabPage;
          let bShow = clientOpts.bShow;
          return _addon.SetShowH323SubTabPage(Number(tabPage), Boolean(bShow));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Upgrade Warning Msg For Free User When Schedule
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideUpgradeWarningMsgForFreeUserWhenSchedule: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideUpgradeWarningMsgForFreeUserWhenSchedule(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Switch Camera Button
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideSwitchCameraButton: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideSwitchCameraButton(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Copy Url On Invite Window
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideCopyUrlOnInviteWindow: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideCopyUrlOnInviteWindow(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Copy Invitation On Invite Window
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideCopyInvitationOnInviteWindow: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideCopyInvitationOnInviteWindow(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Key pad Button On Meeting Window
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideKeypadButtonOnMeetingWindow: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideKeypadButtonOnMeetingWindow(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Remote Control On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideRemoteControlOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideRemoteControlOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide QA On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HideQAOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HideQAOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Hide Poll On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_HidePollOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.HidePollOnMeetingUI(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Input Meeting Password Dlg
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableInputMeetingPasswordDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableInputMeetingPasswordDlg(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Input Meeting Screen Name Dlg
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableInputMeetingScreenNameDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableInputMeetingScreenNameDlg(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Webinar Need Register
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectWebinarNeedRegister: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectWebinarNeedRegister(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect End Other Meeting
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectEndOtherMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.RedirectEndOtherMeeting(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Force Auto Start My Video When Join Meeting
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableForceAutoStartMyVideoWhenJoinMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableForceAutoStartMyVideoWhenJoinMeeting(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Force Auto Stop My Video When Join Meeting
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableForceAutoStopMyVideoWhenJoinMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableForceAutoStopMyVideoWhenJoinMeeting(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Auto Show Select Join Audio Dlg When Join Meeting
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Remote Ctrl Copy Paste Feature
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableRemoteCtrlCopyPasteFeature: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.DisableRemoteCtrlCopyPasteFeature(Boolean(bEnable));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Set Show Video Optimize Chkbox
       * @param {Boolean} bShow
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetShowVideoOptimizeChkbox: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bShow = clientOpts.bShow;
          return _addon.SetShowVideoOptimizeChkbox(Boolean(bShow));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Get Required Info Type
       * @return {ZoomSDKError}
       */
      MeetingConfig_GetRequiredInfoType: function () {
        if (_addon) {
          return _addon.GetRequiredInfoType();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Get Required Info Type
       * @param {String} meeting_Password
       * @param {String} screenName
       * @return {Boolean}
       */
      MeetingConfig_InputMeetingPasswordAndScreenName: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meeting_Password = clientOpts.meeting_Password;
          let screenName = clientOpts.screenName;
          return _addon.InputMeetingPasswordAndScreenName(meeting_Password, screenName);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Input Meeting ID And Screen Name
       * @param {String} meetingID
       * @param {String} screenName
       * @return {Boolean}
       */
      MeetingConfig_InputMeetingIDAndScreenName: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingID = clientOpts.meetingID;
          let screenName = clientOpts.screenName;
          return _addon.InputMeetingIDAndScreenName(meetingID, screenName);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Input Meeting Screen Name
       * @param {String} screenName
       * @return {Boolean}
       */
      MeetingConfig_InputMeetingScreenName: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let screenName = clientOpts.screenName;
          return _addon.InputMeetingScreenName(screenName);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Input Meeting Screen Name
       * @return {ZoomSDKError}
       */
      MeetingConfig_MeetingPasswordAndScreenNameHandler_Cancel: function () {
        if (_addon) {
          return _addon.MeetingPasswordAndScreenNameHandler_Cancel();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Get Webinar Need Register Type
       * @return {ZoomSDKError}
       */
      MeetingConfig_GetWebinarNeedRegisterType: function () {
        if (_addon) {
          return _addon.GetWebinarNeedRegisterType();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Get Webinar Register Url
       * @return {String}
       */
      MeetingConfig_GetWebinarRegisterUrl: function () {
        if (_addon) {
          return _addon.GetWebinarRegisterUrl();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Release Register Webinar By Url
       * @return {ZoomSDKError}
       */
      MeetingConfig_ReleaseRegisterWebinarByUrl: function () {
        if (_addon) {
          return _addon.ReleaseRegisterWebinarByUrl();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Input Webinar Register Email And Screen Name
       * @param {String} email
       * @param {String} screenName
       * @return {ZoomSDKError}
       */
      MeetingConfig_InputWebinarRegisterEmailAndScreenName: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let email = clientOpts.email;
          let screenName = clientOpts.screenName;
          return _addon.InputWebinarRegisterEmailAndScreenName(email, screenName);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Cancel Register Webinar By Email
       * @return {ZoomSDKError}
       */
      MeetingConfig_CancelRegisterWebinarByEmail: function () {
        if (_addon) {
          return _addon.CancelRegisterWebinarByEmail();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click Audio BTN Event
       * @param {Boolean} bRedirect
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickAudioBTNEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bRedirect = clientOpts.bRedirect;
          return _addon.RedirectClickAudioBTNEvent(bRedirect);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Redirect Click Audio Menu BTN Event
       * @param {Boolean} bRedirect
       * @return {ZoomSDKError}
       */
      MeetingConfig_RedirectClickAudioMenuBTNEvent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bRedirect = clientOpts.bRedirect;
          return _addon.RedirectClickAudioMenuBTNEvent(bRedirect);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Enable Audio Button On Meeting UI
       * @param {Boolean} bEnable
       * @return {ZoomSDKError}
       */
      MeetingConfig_EnableAudioButtonOnMeetingUI: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAudioButtonOnMeetingUI(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Show Join Meeting Wnd
       * @param {Boolean} bDisable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableShowJoinMeetingWnd: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          return _addon.DisableShowJoinMeetingWnd(bDisable);
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