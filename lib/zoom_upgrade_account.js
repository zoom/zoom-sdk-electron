const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
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
    let _onFreeMeetingNeedToUpgrade = clientOpts.onFreeMeetingNeedToUpgrade || null;
    let _onFreeMeetingUpgradeToGiftFreeTrialStart = clientOpts.onFreeMeetingUpgradeToGiftFreeTrialStart || null;
    let _onFreeMeetingUpgradeToGiftFreeTrialStop = clientOpts.onFreeMeetingUpgradeToGiftFreeTrialStop || null;
    let _onFreeMeetingUpgradeToProMeeting = clientOpts.onFreeMeetingUpgradeToProMeeting || null;

    function onFreeMeetingNeedToUpgrade (type, gift_url) {
      if (_onFreeMeetingNeedToUpgrade) {
        _onFreeMeetingNeedToUpgrade(type, gift_url)
      }
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStart (result) {
      if (_onFreeMeetingUpgradeToGiftFreeTrialStart) {
        _onFreeMeetingUpgradeToGiftFreeTrialStart(result)
      }
    }

    function onFreeMeetingUpgradeToGiftFreeTrialStop (result) {
      if (_onFreeMeetingUpgradeToGiftFreeTrialStop) {
        _onFreeMeetingUpgradeToGiftFreeTrialStop(result)
      }
    }

    function onFreeMeetingUpgradeToProMeeting (result) {
      if (_onFreeMeetingUpgradeToProMeeting) {
        _onFreeMeetingUpgradeToProMeeting(result)
      }
    }

    if (_addon) {
      _addon.SetFreeMeetingNeedToUpgradeCB(onFreeMeetingNeedToUpgrade);
      _addon.SetFreeMeetingUpgradeToGiftFreeTrialStartCB(onFreeMeetingUpgradeToGiftFreeTrialStart);
      _addon.SetFreeMeetingUpgradeToGiftFreeTrialStopCB(onFreeMeetingUpgradeToGiftFreeTrialStop);
      _addon.SetFreeMeetingUpgradeToProMeetingCB(onFreeMeetingUpgradeToProMeeting);
    }

    return {
      /** mode: Set Free Meeting Need T oUpgrade CB
       * @param {Function} onFreeMeetingNeedToUpgrade
       * @return {Boolean}
       */
      MeetingConfig_SetFreeMeetingNeedToUpgradeCB: function (onFreeMeetingNeedToUpgrade) {
        if (_addon && onFreeMeetingNeedToUpgrade && onFreeMeetingNeedToUpgrade instanceof Function) {
          _onFreeMeetingNeedToUpgrade = onFreeMeetingNeedToUpgrade;
          return true;
        }
        return false;
      },
      /** mode: Set Free Meeting Upgrade To Gift Free TrialStop CB
       * @param {Function} onFreeMeetingUpgradeToGiftFreeTrialStart
       * @return {Boolean}
       */
      MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStartCB: function (onFreeMeetingUpgradeToGiftFreeTrialStart) {
        if (_addon && onFreeMeetingUpgradeToGiftFreeTrialStart && onFreeMeetingUpgradeToGiftFreeTrialStart instanceof Function) {
          _onFreeMeetingUpgradeToGiftFreeTrialStart = onFreeMeetingUpgradeToGiftFreeTrialStart;
          return true;
        }
        return false;
      },
      /** mode: Set Free Meeting Upgrade To Gift Free TrialStop CB
       * @param {Function} onFreeMeetingUpgradeToGiftFreeTrialStop
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStopCB: function (onFreeMeetingUpgradeToGiftFreeTrialStop) {
        if (_addon && onFreeMeetingUpgradeToGiftFreeTrialStop && onFreeMeetingUpgradeToGiftFreeTrialStop instanceof Function) {
          _onFreeMeetingUpgradeToGiftFreeTrialStop = onFreeMeetingUpgradeToGiftFreeTrialStop;
          return true;
        }
        return false;
      },
      /** mode: Set Free Meeting Upgrade To ProMeeting CB
       * @param {Function} onFreeMeetingUpgradeToProMeeting
       * @return {ZoomSDKError}
       */
      MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB: function (onFreeMeetingUpgradeToProMeeting) {
        if (_addon && onFreeMeetingUpgradeToProMeeting && onFreeMeetingUpgradeToProMeeting instanceof Function) {
          _onFreeMeetingUpgradeToProMeeting = onFreeMeetingUpgradeToProMeeting;
          return true;
        }
        return false;
      },
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