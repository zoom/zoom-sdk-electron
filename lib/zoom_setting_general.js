const { ZoomSDKError } = require('./settings.js');

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
          return _addon.EnableDualScreenMode(zn_bEnable);
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
          return _addon.TurnOffAeroModeInSharing(zn_bEnable);
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
          return _addon.EnableAutoFitToWindowWhenViewSharing(zn_bEnable);
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
          return _addon.EnableAutoFullScreenVideoWhenJoinMeeting(zn_bEnable);
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
          return _addon.EnableSplitScreenMode(zn_bEnable);
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
          return _addon.EnableAutoFullScreenVideoWhenViewShare(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Auto Full Screen Video When View Share Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsAutoFullScreenVideoWhenViewShareEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAutoFullScreenVideoWhenViewShareEnabled(bEnable);
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
          return _addon.EnableDisplayReminderWindowWhenExit(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Display Reminder Window When Exit Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsDisplayReminderWindowWhenExitEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsDisplayReminderWindowWhenExitEnabled(bEnable);
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
          return _addon.EnableShowMyMeetingElapseTime(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Show My Meeting Elapse Time Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsShowMyMeetingElapseTimeEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsShowMyMeetingElapseTimeEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Current OS Support Accelerate GPU When Share
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsCurrentOSSupportAccelerateGPUWhenShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsCurrentOSSupportAccelerateGPUWhenShare(bEnable);
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
          return _addon.EnableAccelerateGPUWhenShare(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Accelerate GPU When Share Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsAccelerateGPUWhenShareEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAccelerateGPUWhenShareEnabled(bEnable);
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
          return _addon.EnableRemoteControlAllApplications(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Remote Control All Applications Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsRemoteControlAllApplicationsEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsRemoteControlAllApplicationsEnabled(bEnable);
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