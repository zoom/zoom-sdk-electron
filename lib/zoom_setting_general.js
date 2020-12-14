const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
var ZoomGeneralSetting = (function () {
  var instance;
  /**
   * mode: Zoom SDK GeneralSettings Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomGeneralSetting}
  */
  function init(opts) {
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingGeneralCtrl() || null;
    
    return {
      /** 
       * mode: Enable Dual Screen Mode
       * @param {Boolean} zn_bEnable zn_bEnable or not
       * @return {ZoomSDKError}
       */
      Setting_EnableDualScreenMode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          try {
            let EnableDualScreenModeParams = new messages.EnableDualScreenModeParams();
            EnableDualScreenModeParams.setBenable(zn_bEnable);
            let bytes = EnableDualScreenModeParams.serializeBinary();
            return _addon.EnableDualScreenMode(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Turn Off Aero Mode In Sharing
      * @param {Boolean} zn_bEnable Turnoff or not
      * @return {ZoomSDKError}
      */
      Setting_TurnOffAeroModeInSharing: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          try {
            let TurnOffAeroModeInSharingParams = new messages.TurnOffAeroModeInSharingParams();
            TurnOffAeroModeInSharingParams.setBturnoff(zn_bEnable);
            let bytes = TurnOffAeroModeInSharingParams.serializeBinary();
            return _addon.TurnOffAeroModeInSharing(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Auto Fit To Window When View Sharing
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAutoFitToWindowWhenViewSharing: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          try {
            let EnableAutoFitToWindowWhenViewSharingParams = new messages.EnableAutoFitToWindowWhenViewSharingParams();
            EnableAutoFitToWindowWhenViewSharingParams.setBenable(zn_bEnable);
            let bytes = EnableAutoFitToWindowWhenViewSharingParams.serializeBinary();
            return _addon.EnableAutoFitToWindowWhenViewSharing(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Auto Full Screen Video When Join Meeting
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAutoFullScreenVideoWhenJoinMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          try {
            let EnableAutoFullScreenVideoWhenJoinMeetingParams = new messages.EnableAutoFullScreenVideoWhenJoinMeetingParams();
            EnableAutoFullScreenVideoWhenJoinMeetingParams.setBenable(zn_bEnable);
            let bytes = EnableAutoFullScreenVideoWhenJoinMeetingParams.serializeBinary();
            return _addon.EnableAutoFullScreenVideoWhenJoinMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Split Screen Mode
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableSplitScreenMode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          try {
            let EnableSplitScreenModeParams = new messages.EnableSplitScreenModeParams();
            EnableSplitScreenModeParams.setBenable(zn_bEnable);
            let bytes = EnableSplitScreenModeParams.serializeBinary();
            return _addon.EnableSplitScreenMode(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Check if Is Dual Screen Mode Enabled.
      * @return {ZoomSDKError}
      */
      Checking_IsDualScreenModeEnabled: function (opts) {
        if (_addon) {
          return _addon.IsDualScreenModeEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Check if Is Aero Mode In Sharing Turn Off.
      * @return {ZoomSDKError}
      */
      Checking_IsAeroModeInSharingTurnOff: function (opts) {
        if (_addon) {
          return _addon.IsAeroModeInSharingTurnOff();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Check if Is Auto Fit To Window When View Sharing Enabled.
      * @return {ZoomSDKError}
      */
      Checking_IsAutoFitToWindowWhenViewSharingEnabled: function (opts) {
        if (_addon) {
          return _addon.IsAutoFitToWindowWhenViewSharingEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Check if IsAutoFullScreenVideoWhenJoinMeetingEnabled.
      * @return {ZoomSDKError}
      */
      Checking_IsAutoFullScreenVideoWhenJoinMeetingEnabled: function (opts) {
        if (_addon) {
          return _addon.IsAutoFullScreenVideoWhenJoinMeetingEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Check if Is Split Screen Mode Enabled.
       * @return {ZoomSDKError}
       */
      Checking_IsSplitScreenModeEnabled: function (opts) {
        if (_addon) {
          return _addon.IsSplitScreenModeEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Auto Full Screen Video When View Share
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAutoFullScreenVideoWhenViewShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableAutoFullScreenVideoWhenViewShareParams = new messages.EnableAutoFullScreenVideoWhenViewShareParams();
            EnableAutoFullScreenVideoWhenViewShareParams.setBenable(bEnable);
            let bytes = EnableAutoFullScreenVideoWhenViewShareParams.serializeBinary();
            return _addon.EnableAutoFullScreenVideoWhenViewShare(bytes); 
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Auto Full Screen Video When View Share Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsAutoFullScreenVideoWhenViewShareEnabled: function () {
        if (_addon) {
          return _addon.IsAutoFullScreenVideoWhenViewShareEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Display Reminder Window When Exit
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableDisplayReminderWindowWhenExit: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableDisplayReminderWindowWhenExitParams = new messages.EnableDisplayReminderWindowWhenExitParams();
            EnableDisplayReminderWindowWhenExitParams.setBenable(bEnable);
            let bytes = EnableDisplayReminderWindowWhenExitParams.serializeBinary();
            return _addon.EnableDisplayReminderWindowWhenExit(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Display Reminder Window When Exit Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsDisplayReminderWindowWhenExitEnabled: function () {
        if (_addon) {
          return _addon.IsDisplayReminderWindowWhenExitEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Show My Meeting Elapse Time
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableShowMyMeetingElapseTime: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableShowMyMeetingElapseTimeParams = new messages.EnableShowMyMeetingElapseTimeParams();
            EnableShowMyMeetingElapseTimeParams.setBenable(bEnable);
            let bytes = EnableShowMyMeetingElapseTimeParams.serializeBinary();
            return _addon.EnableShowMyMeetingElapseTime(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Show My Meeting Elapse Time Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsShowMyMeetingElapseTimeEnabled: function () {
        if (_addon) {
          return _addon.IsShowMyMeetingElapseTimeEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Current OS Support Accelerate GPU When Share
      * @return {ZoomSDKError}
      */
      Setting_IsCurrentOSSupportAccelerateGPUWhenShare: function () {
        if (_addon) {
          return _addon.IsCurrentOSSupportAccelerateGPUWhenShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Accelerate GPU When Share
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAccelerateGPUWhenShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableAccelerateGPUWhenShareParams = new messages.EnableAccelerateGPUWhenShareParams();
            EnableAccelerateGPUWhenShareParams.setBenable(bEnable);
            let bytes = EnableAccelerateGPUWhenShareParams.serializeBinary();
            return _addon.EnableAccelerateGPUWhenShare(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Accelerate GPU When Share Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsAccelerateGPUWhenShareEnabled: function () {
        if (_addon) {
          return _addon.IsAccelerateGPUWhenShareEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Remote Control All Applications
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableRemoteControlAllApplications: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableRemoteControlAllApplicationsParams = new messages.EnableRemoteControlAllApplicationsParams();
            EnableRemoteControlAllApplicationsParams.setBenable(bEnable);
            let bytes = EnableRemoteControlAllApplicationsParams.serializeBinary();
            return _addon.EnableRemoteControlAllApplications(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Remote Control All Applications Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsRemoteControlAllApplicationsEnabled: function () {
        if (_addon) {
          return _addon.IsRemoteControlAllApplicationsEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK General Setting Service Module
     * @return {ZoomGeneralSetting}
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
  ZoomGeneralSetting: ZoomGeneralSetting
}