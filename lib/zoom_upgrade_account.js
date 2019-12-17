const { ZoomSDKError } = require('./settings.js');

var ZoomPaymentReminder = (function () {
  let instance;

  /**
   * mode: Zoom SDK Payment Reminder Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomPaymentReminder}
   */
  function init(opts) {
    var clientOpts = opts || {};
    // Private methods and variables
    var _addon = clientOpts.addon.GetMeetingConfigCtrl() || null;   
    
    function onFreeMeetingNeedToUpgrade (type, gift_url) {
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStart (result) {
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStop (result) {
    }

    function onFreeMeetingUpgradeToProMeeting (result) {
    }

    return {
      /** mode: Get Reminder Type
       * @return {ZoomSDKError}
       */
      MeetingConfig_GetReminderType: function () {
        if (_addon) {
          return _addon.GetReminderType();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Upgrade Meeting
       * @return {ZoomSDKError}
       */
      MeetingConfig_UpgradeMeeting: function () {
        if (_addon) {
          return _addon.UpgradeMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Upgrade Account
       * @return {ZoomSDKError}
       */
      MeetingConfig_UpgradeAccount: function () {
        if (_addon) {
          return _addon.UpgradeAccount();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Cancel Update
       * @return {ZoomSDKError}
       */
      MeetingConfig_CancelUpdate: function () {
        if (_addon) {
          return _addon.CancelUpdate();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Set Free Meeting Need T oUpgrade CB
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFreeMeetingNeedToUpgradeCB: function () {
        if (_addon) {
          return _addon.SetFreeMeetingNeedToUpgradeCB(onFreeMeetingNeedToUpgrade);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Set Free Meeting Upgrade To Gift Free TrialStop CB
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStartCB: function () {
        if (_addon) {
          return _addon.SetFreeMeetingUpgradeToGiftFreeTrialStartCB(onFreeMeetingUpgradeToGiftFreeTrialStart);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Set Free Meeting Upgrade To Gift Free TrialStop CB
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStopCB: function () {
        if (_addon) {
          return _addon.SetFreeMeetingUpgradeToGiftFreeTrialStopCB(onFreeMeetingUpgradeToGiftFreeTrialStop);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Set Free Meeting Upgrade To ProMeeting CB
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB: function () {
        if (_addon) {
          return _addon.SetFreeMeetingUpgradeToProMeetingCB(onFreeMeetingUpgradeToProMeeting);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    }
  };
  return {
    /**
     * mode: Get Zoom SDK Payment Reminder
     * @return {ZoomPaymentReminder}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  }
 })();
  
module.exports = {
  ZoomPaymentReminder: ZoomPaymentReminder
}