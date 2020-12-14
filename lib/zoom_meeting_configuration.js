const { ZoomSDKError } = require('./settings.js');
const os = require('os');
const platform = os.platform();
const messages = require('./electron_sdk_pb.js');
const console = require('console');

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
          try {
            let EnableInviteButtonOnMeeitngUIParams = new messages.EnableInviteButtonOnMeeitngUIParams();
            EnableInviteButtonOnMeeitngUIParams.setBenable(bEnable);
            let bytes = EnableInviteButtonOnMeeitngUIParams.serializeBinary();
            return _addon.EnableInviteButtonOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetFloatVideoPosParams = new messages.SetFloatVideoPosParams();
            SetFloatVideoPosParams.setLeft(left);
            SetFloatVideoPosParams.setTop(top);
            SetFloatVideoPosParams.setHselfwnd(hSelfWnd);
            SetFloatVideoPosParams.setHparent(hParent);
            let bytes = SetFloatVideoPosParams.serializeBinary();
            return _addon.SetFloatVideoPos(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetBottomFloatToolBarWndVisibilityParams = new messages.SetBottomFloatToolBarWndVisibilityParams();
            SetBottomFloatToolBarWndVisibilityParams.setBshow(bShow);
            let bytes = SetBottomFloatToolBarWndVisibilityParams.serializeBinary();
            return _addon.SetBottomFloatToolbarWndVisibility(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetSharingToolBarVisibilityParams = new messages.SetSharingToolBarVisibilityParams();
            SetSharingToolBarVisibilityParams.setBshow(bShow);
            let bytes = SetSharingToolBarVisibilityParams.serializeBinary();
            return _addon.SetSharingToolbarVisibility(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetDirectShareMonitorIDParams = new messages.SetDirectShareMonitorIDParams();
            SetDirectShareMonitorIDParams.setMonitorid(monitorID);
            let bytes = SetDirectShareMonitorIDParams.serializeBinary();
            return _addon.SetDirectShareMonitorID(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetMeetingUIPosParams = new messages.SetMeetingUIPosParams();
            SetMeetingUIPosParams.setLeft(left);
            SetMeetingUIPosParams.setTop(top);
            SetMeetingUIPosParams.setHselfwnd(hSelfWnd);
            SetMeetingUIPosParams.setHparent(hParent);
            let bytes = SetMeetingUIPosParams.serializeBinary();
            return _addon.SetMeetingUIPos(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableWaitingForHostDialogParams = new messages.DisableWaitingForHostDialogParams();
            DisableWaitingForHostDialogParams.setBdisable(bDisable);
            let bytes = DisableWaitingForHostDialogParams.serializeBinary();
            return _addon.DisableWaitingForHostDialog(bytes)
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisablePopupMeetingWrongPSWDlgParams = new messages.DisablePopupMeetingWrongPSWDlgParams();
            DisablePopupMeetingWrongPSWDlgParams.setBdisable(bDisable);
            let bytes = DisablePopupMeetingWrongPSWDlgParams.serializeBinary();
            return _addon.DisablePopupMeetingWrongPSWDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAutoEndOtherMeetingWhenStartMeetingParams = new messages.EnableAutoEndOtherMeetingWhenStartMeetingParams();
            EnableAutoEndOtherMeetingWhenStartMeetingParams.setBenable(bEnable);
            let bytes = EnableAutoEndOtherMeetingWhenStartMeetingParams.serializeBinary();
            return _addon.EnableAutoEndOtherMeetingWhenStartMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableLButtonDBClick4SwitchFullScreenModeParams = new messages.EnableLButtonDBClick4SwitchFullScreenModeParams();
            EnableLButtonDBClick4SwitchFullScreenModeParams.setBenable(bEnable);
            let bytes = EnableLButtonDBClick4SwitchFullScreenModeParams.serializeBinary();
            return _addon.EnableLButtonDBClick4SwitchFullScreenMode(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetFloatVideoWndVisibilityParams = new messages.SetFloatVideoWndVisibilityParams();
            SetFloatVideoWndVisibilityParams.setBshow(bShow);
            let bytes = SetFloatVideoWndVisibilityParams.serializeBinary();
            return _addon.SetFloatVideoWndVisibility(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let PrePopulateWebinarRegistrationInfoParams = new messages.PrePopulateWebinarRegistrationInfoParams();
            PrePopulateWebinarRegistrationInfoParams.setEmail(email);
            PrePopulateWebinarRegistrationInfoParams.setUsername(userName);
            let bytes = PrePopulateWebinarRegistrationInfoParams.serializeBinary();
            return _addon.PrePopulateWebinarRegistrationInfo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAutoAdjustSpeakerVolumeWhenJoinAudioParams = new messages.EnableAutoAdjustSpeakerVolumeWhenJoinAudioParams();
            EnableAutoAdjustSpeakerVolumeWhenJoinAudioParams.setBenable(bEnable);
            let bytes = EnableAutoAdjustSpeakerVolumeWhenJoinAudioParams.serializeBinary();
            return _addon.EnableAutoAdjustSpeakerVolumeWhenJoinAudio(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAutoAdjustMicVolumeWhenJoinAudioParams = new messages.EnableAutoAdjustMicVolumeWhenJoinAudioParams();
            EnableAutoAdjustMicVolumeWhenJoinAudioParams.setBenable(bEnable);
            let bytes = EnableAutoAdjustMicVolumeWhenJoinAudioParams.serializeBinary();
            return _addon.EnableAutoAdjustMicVolumeWhenJoinAudio(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let ConfigDSCPParams = new messages.ConfigDSCPParams();
            ConfigDSCPParams.setDscpaudio(dscpAudio);
            ConfigDSCPParams.setDscpvideo(dscpVideo);
            ConfigDSCPParams.setBreset(bReset);
            let bytes = ConfigDSCPParams.serializeBinary();
            return _addon.ConfigDSCP(bytes); 
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableHIdeFullPhoneNumber4PureCallinUserParams = new messages.EnableHIdeFullPhoneNumber4PureCallinUserParams();
            EnableHIdeFullPhoneNumber4PureCallinUserParams.setBenable(bHide);
            let bytes = EnableHIdeFullPhoneNumber4PureCallinUserParams.serializeBinary();
            return _addon.EnableHideFullPhoneNumber4PureCallinUser(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableLengthLimitationOfMeetingNumberParams = new messages.EnableLengthLimitationOfMeetingNumberParams();
            EnableLengthLimitationOfMeetingNumberParams.setBenable(bEnable);
            let bytes = EnableLengthLimitationOfMeetingNumberParams.serializeBinary();
            return _addon.EnableLengthLimitationOfMeetingNumber(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableShareIOSDeviceParams = new messages.EnableShareIOSDeviceParams();
            EnableShareIOSDeviceParams.setBenable(bEnable);
            let bytes = EnableShareIOSDeviceParams.serializeBinary();
            return _addon.EnableShareIOSDevice(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableShareWhiteBoardParams = new messages.EnableShareWhiteBoardParams();
            EnableShareWhiteBoardParams.setBenable(bEnable);
            let bytes = EnableShareWhiteBoardParams.serializeBinary();
            return _addon.EnableShareWhiteBoard(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let ForceDisableMultiShareParams = new messages.ForceDisableMultiShareParams();
            ForceDisableMultiShareParams.setBdisable(bDisable);
            let bytes = EnableShareWhiteBoardParams.serializeBinary();
            return _addon.ForceDisableMultiShare(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetMaxDurationForOnlyHostInMeetingParams = new messages.SetMaxDurationForOnlyHostInMeetingParams();
            SetMaxDurationForOnlyHostInMeetingParams.setNduration(nDuration);
            let bytes = SetMaxDurationForOnlyHostInMeetingParams.serializeBinary();
            return _addon.SetMaxDurationForOnlyHostInMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableLocalRecordingConverProgressBarDialogParams = new messages.EnableLocalRecordingConverProgressBarDialogParams();
            EnableLocalRecordingConverProgressBarDialogParams.setBenable(bShow);
            let bytes = EnableLocalRecordingConverProgressBarDialogParams.serializeBinary();
            return _addon.EnableLocalRecordingConvertProgressBarDialog(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableApproveRemoteControlDlgParams = new messages.EnableApproveRemoteControlDlgParams();
            EnableApproveRemoteControlDlgParams.setBenable(bEnable);
            let bytes = EnableApproveRemoteControlDlgParams.serializeBinary();
            return _addon.EnableApproveRemoteControlDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableDeclineRemoteControlResponseDlgParams = new messages.EnableDeclineRemoteControlResponseDlgParams();
            EnableDeclineRemoteControlResponseDlgParams.setBenable(bEnable);
            let bytes = EnableDeclineRemoteControlResponseDlgParams.serializeBinary();
            return _addon.EnableDeclineRemoteControlResponseDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableLeaveMeetingOptionForHostParams = new messages.EnableLeaveMeetingOptionForHostParams();
            EnableLeaveMeetingOptionForHostParams.setBenable(bEnable);
            let bytes = EnableLeaveMeetingOptionForHostParams.serializeBinary();
            return _addon.EnableLeaveMeetingOptionForHost(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableVideoButtonOnMeetingUIParams = new messages.EnableVideoButtonOnMeetingUIParams();
            EnableVideoButtonOnMeetingUIParams.setBenable(bEnable);
            let bytes = EnableVideoButtonOnMeetingUIParams.serializeBinary();
            return _addon.EnableVideoButtonOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableEnterAndExitFullScreenButtonOnMeetingUIParams = new messages.EnableEnterAndExitFullScreenButtonOnMeetingUIParams();
            EnableEnterAndExitFullScreenButtonOnMeetingUIParams.setBenable(bEnable);
            let bytes = EnableEnterAndExitFullScreenButtonOnMeetingUIParams.serializeBinary();
            return _addon.EnableEnterAndExitFullScreenButtonOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickShareBTNEventParams = new messages.RedirectClickShareBTNEventParams();
            RedirectClickShareBTNEventParams.setBredirect(bEnable);
            let bytes = RedirectClickShareBTNEventParams.serializeBinary();
            return _addon.RedirectClickShareBTNEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickEndMeetingBTNEventParams = new messages.RedirectClickEndMeetingBTNEventParams();
            RedirectClickEndMeetingBTNEventParams.setBredirect(bEnable);
            let bytes = RedirectClickEndMeetingBTNEventParams.serializeBinary();
            return _addon.RedirectClickEndMeetingBTNEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectFreeMeetingEndingReminderDlgParams = new messages.RedirectFreeMeetingEndingReminderDlgParams();
            RedirectFreeMeetingEndingReminderDlgParams.setBredirect(bEnable);
            let bytes = RedirectFreeMeetingEndingReminderDlgParams.serializeBinary();
            return _addon.RedirectFreeMeetingEndingReminderDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickCustomLiveStreamMenuEventParams = new messages.RedirectClickCustomLiveStreamMenuEventParams();
            RedirectClickCustomLiveStreamMenuEventParams.setBredirect(bEnable);
            let bytes = RedirectClickCustomLiveStreamMenuEventParams.serializeBinary();
            return _addon.RedirectClickCustomLiveStreamMenuEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickParticipantListBTNEventParams = new messages.RedirectClickParticipantListBTNEventParams();
            RedirectClickParticipantListBTNEventParams.setBredirect(bEnable);
            let bytes = RedirectClickParticipantListBTNEventParams.serializeBinary();
            return _addon.RedirectClickParticipantListBTNEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickCCBTNEventParams = new messages.RedirectClickCCBTNEventParams();
            RedirectClickCCBTNEventParams.setBredirect(bEnable);
            let bytes = RedirectClickCCBTNEventParams.serializeBinary();
            return _addon.RedirectClickCCBTNEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectMeetingWarningMsgParams = new messages.RedirectMeetingWarningMsgParams();
            RedirectMeetingWarningMsgParams.setBredirectbadnetwork(bRedirectBadNetwork);
            RedirectMeetingWarningMsgParams.setBredirectwarnhighcpu(bRedirectWarnHighCPU);
            let bytes = RedirectMeetingWarningMsgParams.serializeBinary();
            return _addon.RedirectMeetingWarningMsg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableToolTipsShowParams = new messages.EnableToolTipsShowParams();
            EnableToolTipsShowParams.setBenable(bEnable);
            let bytes = EnableToolTipsShowParams.serializeBinary();
            return _addon.EnableToolTipsShow(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAirplayInstructionWindowParams = new messages.EnableAirplayInstructionWindowParams();
            EnableAirplayInstructionWindowParams.setBenable(bEnable);
            let bytes = EnableAirplayInstructionWindowParams.serializeBinary();
            return _addon.EnableAirplayInstructionWindow(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableClaimHostFeatureParams = new messages.EnableClaimHostFeatureParams();
            EnableClaimHostFeatureParams.setBenable(bEnable);
            let bytes = EnableClaimHostFeatureParams.serializeBinary();
            return _addon.EnableClaimHostFeature(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAutoHideJoinAudioDialogParams = new messages.EnableAutoHideJoinAudioDialogParams();
            EnableAutoHideJoinAudioDialogParams.setBenable(bEnable);
            let bytes = EnableAutoHideJoinAudioDialogParams.serializeBinary();
            return _addon.EnableAutoHideJoinAudioDialog(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let AlwaysShowIconOnTaskBarParams = new messages.AlwaysShowIconOnTaskBarParams();
            AlwaysShowIconOnTaskBarParams.setBalwaysshow(bEnable);
            let bytes = AlwaysShowIconOnTaskBarParams.serializeBinary();
            return _addon.AlwaysShowIconOnTaskBar(bytes); 
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableSplitScreenModeUIElementsParams = new messages.DisableSplitScreenModeUIElementsParams();
            DisableSplitScreenModeUIElementsParams.setBdisable(bEnable);
            let bytes = DisableSplitScreenModeUIElementsParams.serializeBinary();
            return _addon.DisableSplitScreenModeUIElements(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetShowAudioUseComputerSoundChkboxParams = new messages.SetShowAudioUseComputerSoundChkboxParams();
            SetShowAudioUseComputerSoundChkboxParams.setBshow(bEnable);
            let bytes = SetShowAudioUseComputerSoundChkboxParams.serializeBinary();
            return _addon.SetShowAudioUseComputerSoundChkbox(bytes);  
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetShowCallInTabParams = new messages.SetShowCallInTabParams();
            SetShowCallInTabParams.setBshow(bEnable);
            let bytes = SetShowCallInTabParams.serializeBinary();
            return _addon.SetShowCallInTab(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetShowCallMeTabParams = new messages.SetShowCallMeTabParams();
            SetShowCallMeTabParams.setBshow(bEnable);
            let bytes = SetShowCallMeTabParams.serializeBinary();
            return _addon.SetShowCallMeTab(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableTopMostAttr4SettingDialogParams = new messages.DisableTopMostAttr4SettingDialogParams();
            DisableTopMostAttr4SettingDialogParams.setBdisable(bEnable);
            let bytes = DisableTopMostAttr4SettingDialogParams.serializeBinary();
            return _addon.DisableTopMostAttr4SettingDialog(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableGrabShareWithoutReminderParams = new messages.EnableGrabShareWithoutReminderParams();
            EnableGrabShareWithoutReminderParams.setBenable(bEnable);
            let bytes = EnableGrabShareWithoutReminderParams.serializeBinary();
            return _addon.EnableGrabShareWithoutReminder(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableShowShareSwitchMultiToSingleConfirmDlgParams = new messages.EnableShowShareSwitchMultiToSingleConfirmDlgParams();
            EnableShowShareSwitchMultiToSingleConfirmDlgParams.setBenable(bEnable);
            let bytes = EnableShowShareSwitchMultiToSingleConfirmDlgParams.serializeBinary();
            return _addon.EnableShowShareSwitchMultiToSingleConfirmDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableFreeMeetingRemainTimeNotifyParams = new messages.DisableFreeMeetingRemainTimeNotifyParams();
            DisableFreeMeetingRemainTimeNotifyParams.setBdisable(bEnable);
            let bytes = DisableFreeMeetingRemainTimeNotifyParams.serializeBinary();
            return _addon.DisableFreeMeetingRemainTimeNotify(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideChatItemOnMeetingUIParams = new messages.HideChatItemOnMeetingUIParams();
            HideChatItemOnMeetingUIParams.setBhide(bEnable);
            let bytes = HideChatItemOnMeetingUIParams.serializeBinary();
            return _addon.HideChatItemOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideRecordItemOnMeetingUIParams = new messages.HideRecordItemOnMeetingUIParams();
            HideRecordItemOnMeetingUIParams.setBhide(bEnable);
            let bytes = HideRecordItemOnMeetingUIParams.serializeBinary();
            return _addon.HideRecordItemOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideUpgradeFreeMeetingButtonParams = new messages.HideUpgradeFreeMeetingButtonParams();
            HideUpgradeFreeMeetingButtonParams.setBhide(bEnable);
            let bytes = HideUpgradeFreeMeetingButtonParams.serializeBinary();
            return _addon.HideUpgradeFreeMeetingButton(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetShowInviteDlgTabPageParams = new messages.SetShowInviteDlgTabPageParams();
            SetShowInviteDlgTabPageParams.setTabpage(tabPage);
            SetShowInviteDlgTabPageParams.setBshow(bShow);
            let bytes = SetShowInviteDlgTabPageParams.serializeBinary();
            return _addon.SetShowInviteDlgTabPage(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetShowH323SubTabPageParams = new messages.SetShowH323SubTabPageParams();
            SetShowH323SubTabPageParams.setTabpage(tabPage);
            SetShowH323SubTabPageParams.setBshow(bShow);
            let bytes = SetShowH323SubTabPageParams.serializeBinary();
            return _addon.SetShowH323SubTabPage(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideUpgradeWarningMsgForFreeUserWhenScheduleParams = new messages.HideUpgradeWarningMsgForFreeUserWhenScheduleParams();
            HideUpgradeWarningMsgForFreeUserWhenScheduleParams.setBhide(bEnable);
            let bytes = HideUpgradeWarningMsgForFreeUserWhenScheduleParams.serializeBinary();
            return _addon.HideUpgradeWarningMsgForFreeUserWhenSchedule(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideSwitchCameraButtonParams = new messages.HideSwitchCameraButtonParams();
            HideSwitchCameraButtonParams.setBhide(bEnable);
            let bytes = HideSwitchCameraButtonParams.serializeBinary();
            return _addon.HideSwitchCameraButton(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideCopyUrlOnInviteWindowParams = new messages.HideCopyUrlOnInviteWindowParams();
            HideCopyUrlOnInviteWindowParams.setBhide(bEnable);
            let bytes = HideCopyUrlOnInviteWindowParams.serializeBinary();
            return _addon.HideCopyUrlOnInviteWindow(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideCopyInvitationOnInviteWindowParams = new messages.HideCopyInvitationOnInviteWindowParams();
            HideCopyInvitationOnInviteWindowParams.setBhide(bEnable);
            let bytes = HideCopyInvitationOnInviteWindowParams.serializeBinary();
            return _addon.HideCopyInvitationOnInviteWindow(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideKeypadButtonOnMeetingWindowParams = new messages.HideKeypadButtonOnMeetingWindowParams();
            HideKeypadButtonOnMeetingWindowParams.setBhide(bEnable);
            let bytes = HideKeypadButtonOnMeetingWindowParams.serializeBinary();
            return _addon.HideKeypadButtonOnMeetingWindow(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideRemoteControlOnMeetingUIParams = new messages.HideRemoteControlOnMeetingUIParams();
            HideRemoteControlOnMeetingUIParams.setBhide(bEnable);
            let bytes = HideRemoteControlOnMeetingUIParams.serializeBinary();
            return _addon.HideRemoteControlOnMeetingUI(bytes);  
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HideQAOnMeetingUIParams = new messages.HideQAOnMeetingUIParams();
            HideQAOnMeetingUIParams.setBhide(bEnable);
            let bytes = HideQAOnMeetingUIParams.serializeBinary();
            return _addon.HideQAOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let HidePollOnMeetingUIParams = new messages.HidePollOnMeetingUIParams();
            HidePollOnMeetingUIParams.setBhide(bEnable);
            let bytes = HidePollOnMeetingUIParams.serializeBinary();
            return _addon.HidePollOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableInputMeetingPasswordDlgParams = new messages.EnableInputMeetingPasswordDlgParams();
            EnableInputMeetingPasswordDlgParams.setBenable(bEnable);
            let bytes = EnableInputMeetingPasswordDlgParams.serializeBinary();
            return _addon.EnableInputMeetingPasswordDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableInputMeetingScreenNameDlgParams = new messages.EnableInputMeetingScreenNameDlgParams();
            EnableInputMeetingScreenNameDlgParams.setBenable(bEnable);
            let bytes = EnableInputMeetingScreenNameDlgParams.serializeBinary();
            return _addon.EnableInputMeetingScreenNameDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectWebinarNeedRegisterParams = new messages.RedirectWebinarNeedRegisterParams();
            RedirectWebinarNeedRegisterParams.setBredirect(Boolean(bEnable));
            let bytes = RedirectWebinarNeedRegisterParams.serializeBinary();
            return _addon.RedirectWebinarNeedRegister(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectEndOtherMeetingParams = new messages.RedirectEndOtherMeetingParams();
            RedirectEndOtherMeetingParams.setBredirect(Boolean(bEnable));
            let bytes = RedirectEndOtherMeetingParams.serializeBinary();
            return _addon.RedirectEndOtherMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableForceAutoStartMyVideoWhenJoinMeetingParams = new messages.EnableForceAutoStartMyVideoWhenJoinMeetingParams();
            EnableForceAutoStartMyVideoWhenJoinMeetingParams.setBenable(Boolean(bEnable));
            let bytes = EnableForceAutoStartMyVideoWhenJoinMeetingParams.serializeBinary();
            return _addon.EnableForceAutoStartMyVideoWhenJoinMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableForceAutoStopMyVideoWhenJoinMeetingParams = new messages.EnableForceAutoStopMyVideoWhenJoinMeetingParams();
            EnableForceAutoStopMyVideoWhenJoinMeetingParams.setBenable(Boolean(bEnable));
            let bytes = EnableForceAutoStopMyVideoWhenJoinMeetingParams.serializeBinary();
            return _addon.EnableForceAutoStopMyVideoWhenJoinMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams = new messages.DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams();
            DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams.setBdisable(Boolean(bEnable));
            let bytes = DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams.serializeBinary();
            return _addon.DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams = new messages.DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams();
            DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams.setBdisable(Boolean(bEnable));
            let bytes = DisableAutoShowSelectJoinAudioDlgWhenJoinMeetingParams.serializeBinary();
            return _addon.DisableRemoteCtrlCopyPasteFeature(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetShowVideoOptimizeChkboxParams = new messages.SetShowVideoOptimizeChkboxParams();
            SetShowVideoOptimizeChkboxParams.setBshow(Boolean(bShow));
            let bytes = SetShowVideoOptimizeChkboxParams.serializeBinary();
            return _addon.SetShowVideoOptimizeChkbox(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let InputMeetingPasswordAndScreenNameParams = new messages.InputMeetingPasswordAndScreenNameParams();
            InputMeetingPasswordAndScreenNameParams.setPsw(meeting_Password);
            InputMeetingPasswordAndScreenNameParams.setScreenname(screenName);
            let bytes = InputMeetingPasswordAndScreenNameParams.serializeBinary();
            return _addon.InputMeetingPasswordAndScreenName(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let InputMeetingIDAndScreenNameParams = new messages.InputMeetingIDAndScreenNameParams();
            InputMeetingIDAndScreenNameParams.setMeetingid(meetingID);
            InputMeetingIDAndScreenNameParams.setScreenname(screenName);
            let bytes = InputMeetingIDAndScreenNameParams.serializeBinary();
            return _addon.InputMeetingIDAndScreenName(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let InputMeetingScreenNameParams = new messages.InputMeetingScreenNameParams();
            InputMeetingScreenNameParams.setScreenname(screenName);
            let bytes = InputMeetingScreenNameParams.serializeBinary();
            return _addon.InputMeetingScreenName(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let InputWebinarRegisterEmailAndScreenNameParams = new messages.InputWebinarRegisterEmailAndScreenNameParams();
            InputWebinarRegisterEmailAndScreenNameParams.setEmail(email);
            InputWebinarRegisterEmailAndScreenNameParams.setScreenname(screenName);
            let bytes = InputWebinarRegisterEmailAndScreenNameParams.serializeBinary();
            return _addon.InputWebinarRegisterEmailAndScreenName(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickAudioBTNEventParams = new messages.RedirectClickAudioBTNEventParams();
            RedirectClickAudioBTNEventParams.setBredirect(bRedirect);
            let bytes = RedirectClickAudioBTNEventParams.serializeBinary();
            return _addon.RedirectClickAudioBTNEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedirectClickAudioMenuBTNEventParams = new messages.RedirectClickAudioMenuBTNEventParams();
            RedirectClickAudioMenuBTNEventParams.setBredirect(bRedirect);
            let bytes = RedirectClickAudioMenuBTNEventParams.serializeBinary();
            return _addon.RedirectClickAudioMenuBTNEvent(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAudioButtonOnMeetingUIParams = new messages.EnableAudioButtonOnMeetingUIParams();
            EnableAudioButtonOnMeetingUIParams.setBenable(bEnable);
            let bytes = EnableAudioButtonOnMeetingUIParams.serializeBinary();
            return _addon.EnableAudioButtonOnMeetingUI(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DisableShowJoinMeetingWndParams = new messages.DisableShowJoinMeetingWndParams();
            DisableShowJoinMeetingWndParams.setBdisable(bDisable);
            let bytes = DisableShowJoinMeetingWndParams.serializeBinary();
            return _addon.DisableShowJoinMeetingWnd(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Toolbar Invite Button Click Origin Action, only support for MAC platform
       * @param {Boolean} bDisable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableToolbarInviteButtonClickOriginAction: function (opts) {
        if (platform == 'darwin' && _addon) {
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          try {
            let DisableToolbarInviteButtonClickOriginActionParams = new messages.DisableToolbarInviteButtonClickOriginActionParams();
            DisableToolbarInviteButtonClickOriginActionParams.setBdisable(bDisable);
            let bytes = DisableToolbarInviteButtonClickOriginActionParams.serializeBinary();
            return _addon.DisableToolbarInviteButtonClickOriginAction(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Disable Confidential Watermark
       * @param {Boolean} bDisable
       * @return {ZoomSDKError}
       */
      MeetingConfig_DisableConfidentialWatermark: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          try {
            let DisableConfidentialWatermarkParams = new messages.DisableConfidentialWatermarkParams();
            DisableConfidentialWatermarkParams.setBdisable(bDisable);
            let bytes = DisableConfidentialWatermarkParams.serializeBinary();
            return _addon.DisableConfidentialWatermark(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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