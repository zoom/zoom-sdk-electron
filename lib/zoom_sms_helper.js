const { ZoomSDKError } = require('./settings.js');

var ZoomSMSHelper = (function () {
  var instance;
  /**
   * mode: Zoom SDK ZoomSMSHelper Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomSMSHelper}
   */
  function init(opts) { 
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetSDKSMSHelperObj() || null;

    function onNeedRealNameAuthMeetingNotification(support_country_list, privacy_url) {
    }

    function onRetrieveSMSVerificationCodeResultNotification(result) {
    }

    function onVerifySMSVerificationCodeResultNotification(result) {
    }

    if (_addon) {
      _addon.SetNeedRealNameAuthMeetingNotificationCB(onNeedRealNameAuthMeetingNotification);
      _addon.SetRetrieveSMSVerificationCodeResultNotificationCB(onRetrieveSMSVerificationCodeResultNotification);
      _addon.SetVerifySMSVerificationCodeResultNotificationCB(onVerifySMSVerificationCodeResultNotification);
    }

    return {
      /**
      * mode: Enable Zoom Auth Real Name Meeting UI Shown
      * @param {Boolean} b_enable
      * @return {Boolean}
      */
      EnableZoomAuthRealNameMeetingUIShown: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let b_enable = clientOpts.b_enable;
          return _addon.EnableZoomAuthRealNameMeetingUIShown(b_enable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get Resend SMS Verification Code Handler
      * @return {Boolean}
      */
      GetResendSMSVerificationCodeHandler: function () {
        if (_addon) {
          return _addon.GetResendSMSVerificationCodeHandler();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Retrieve
      * @param {String} country_code
      * @param {String} phone_number
      * @return {Boolean}
      */
      Retrieve: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let country_code = clientOpts.country_code;
          let phone_number = clientOpts.phone_number;
          return _addon.Retrieve(country_code, phone_number);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Retrieve Cancel And Leave Meeting
      * @return {Boolean}
      */
      Retrieve_CancelAndLeaveMeeting: function () {
        if (_addon) {
          return _addon.Retrieve_CancelAndLeaveMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get ReVerify SMS Verification Code Handler
      * @return {Boolean}
      */
      GetReVerifySMSVerificationCodeHandler: function () {
        if (_addon) {
          return _addon.GetReVerifySMSVerificationCodeHandler();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Verify
      * @param {string} country_code
      * @param {string} phone_number
      * @param {string} verification_code
      * @return {Boolean}
      */
      Verify: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let country_code = clientOpts.country_code;
          let phone_number = clientOpts.phone_number;
          let verification_code = clientOpts.verification_code;
          return _addon.Verify(country_code, phone_number, verification_code);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Verify Cancel And Leave Meeting
      * @return {Boolean}
      */
      Verify_CancelAndLeaveMeeting: function () {
        if (_addon) {
          return _addon.Verify_CancelAndLeaveMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get Support Phone Number Country List
      * @return {Array}
      */
      GetSupportPhoneNumberCountryList: function () {
        if (_addon) {
          return _addon.GetSupportPhoneNumberCountryList();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Set Default Cell Phone Info
      * @param {string} country_code
      * @param {string} phone_number
      */
      SetDefaultCellPhoneInfo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let country_code = clientOpts.country_code;
          let phone_number = clientOpts.phone_number;
          return _addon.SetDefaultCellPhoneInfo(country_code, phone_number);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK ZoomSMSHelper Service Module
     * @return {ZoomSMSHelper}
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
  ZoomSMSHelper: ZoomSMSHelper
}