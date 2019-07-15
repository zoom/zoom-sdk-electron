const { ZoomSDKError } = require('./settings.js');

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