const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
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
    let _onNeedRealNameAuthMeetingNotification = clientOpts.onNeedRealNameAuthMeetingNotification || null;
    let _onRetrieveSMSVerificationCodeResultNotification = clientOpts.onRetrieveSMSVerificationCodeResultNotification || null;
    let _onVerifySMSVerificationCodeResultNotification = clientOpts.onVerifySMSVerificationCodeResultNotification || null;

    function onNeedRealNameAuthMeetingNotification(support_country_list, privacy_url) {
      if (_onNeedRealNameAuthMeetingNotification) {
        _onNeedRealNameAuthMeetingNotification(support_country_list, privacy_url)
      }
    }

    function onRetrieveSMSVerificationCodeResultNotification(result) {
      if (_onRetrieveSMSVerificationCodeResultNotification) {
        _onRetrieveSMSVerificationCodeResultNotification(result)
      }
    }

    function onVerifySMSVerificationCodeResultNotification(result) {
      if (_onVerifySMSVerificationCodeResultNotification) {
        _onVerifySMSVerificationCodeResultNotification(result)
      }
    }

    if (_addon) {
      _addon.SetNeedRealNameAuthMeetingNotificationCB(onNeedRealNameAuthMeetingNotification);
      _addon.SetRetrieveSMSVerificationCodeResultNotificationCB(onRetrieveSMSVerificationCodeResultNotification);
      _addon.SetVerifySMSVerificationCodeResultNotificationCB(onVerifySMSVerificationCodeResultNotification);
    }

    return {
      /**
      * mode: Set Need Real Name Auth Meeting Notification CB
      * @param {Function} onNeedRealNameAuthMeetingNotification
      * @return {Boolean}
      */
      SetNeedRealNameAuthMeetingNotificationCB: function (onNeedRealNameAuthMeetingNotification) {
        if (_addon && onNeedRealNameAuthMeetingNotification && onNeedRealNameAuthMeetingNotification instanceof Function) {
          _onNeedRealNameAuthMeetingNotification = onNeedRealNameAuthMeetingNotification;
          return true;
        }
        return false;
      },
      /**
      * mode: Set Retrieve SMS Verification Code Result Notification CB
      * @param {Function} onRetrieveSMSVerificationCodeResultNotification
      * @return {Boolean}
      */
      SetRetrieveSMSVerificationCodeResultNotificationCB: function (onRetrieveSMSVerificationCodeResultNotification) {
        if (_addon && onRetrieveSMSVerificationCodeResultNotification && onRetrieveSMSVerificationCodeResultNotification instanceof Function) {
          _onRetrieveSMSVerificationCodeResultNotification = onRetrieveSMSVerificationCodeResultNotification;
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Set Verify SMS Verification Code Result Notification CB
      * @param {Function} onVerifySMSVerificationCodeResultNotification
      * @return {Boolean}
      */
      SetVerifySMSVerificationCodeResultNotificationCB: function (onVerifySMSVerificationCodeResultNotification) {
        if (_addon && onVerifySMSVerificationCodeResultNotification && onVerifySMSVerificationCodeResultNotification instanceof Function) {
          _onVerifySMSVerificationCodeResultNotification = onVerifySMSVerificationCodeResultNotification;
          return true;
        }
        return false;
      },
      /**
      * mode: Enable Zoom Auth Real Name Meeting UI Shown
      * @param {Boolean} b_enable
      * @return {Boolean}
      */
      EnableZoomAuthRealNameMeetingUIShown: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let b_enable = clientOpts.b_enable;
          try {
            let EnableZoomAuthRealNameMeetingUIShownParams = new messages.EnableZoomAuthRealNameMeetingUIShownParams();
            EnableZoomAuthRealNameMeetingUIShownParams.setBenable(b_enable);
            let bytes = EnableZoomAuthRealNameMeetingUIShownParams.serializeBinary();
            return _addon.EnableZoomAuthRealNameMeetingUIShown(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RetrieveParams = new messages.RetrieveParams();
            RetrieveParams.setCountrycode(country_code);
            RetrieveParams.setPhonenum(phone_number);
            let bytes = RetrieveParams.serializeBinary();
            return _addon.Retrieve(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let VerifyParams = new messages.VerifyParams();
            VerifyParams.setCountrycode(country_code);
            VerifyParams.setPhonenum(phone_number);
            VerifyParams.setVerificationcode(verification_code);
            let bytes = VerifyParams.serializeBinary();
            return _addon.Verify(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetDefaultCellPhoneInfoParams = new messages.SetDefaultCellPhoneInfoParams();
            SetDefaultCellPhoneInfoParams.setCountrycode(country_code);
            SetDefaultCellPhoneInfoParams.setPhonenum(phone_number);
            let bytes = SetDefaultCellPhoneInfoParams.serializeBinary();
            return _addon.SetDefaultCellPhoneInfo(bytes);
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