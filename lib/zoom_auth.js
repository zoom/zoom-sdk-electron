const { ZoomAuthResult } = require('./settings.js');

const ZoomAuth = (function () {
  let instance;

  /**
   * mode: Zoom SDK Authentication Service Init
   * @param {Function} authcb The authcb method specifies a callback method to call on sdk authentication request return.
   * @param {Function} logincb The logincb method specifies a callback method to call on login request return.
   * @param {Function} logoutcb The logoutcb method specifies a callback method to call on logout request return.
   * @return {ZoomAuth}
   */
  function init(opts) {
    let clientOpts = opts || {};
    let ZOOMSDKMOD_4AUTH = require('./zoom_sdk.js');
    let _addon = clientOpts.addon.GetAuthObj() || null;
    let _authcb = clientOpts.authcb || null;
    let _logincb = clientOpts.logincb || null;
    let _logoutcb = clientOpts.logoutcb || null;
    let _isSDKAuthentication = false;
    
    function onAuthenticationReturn(result) {
      console.log('result == GetAuthResult', result == GetAuthResult());
      if (ZoomAuthResult.AUTHRET_SUCCESS == result) {
        _isSDKAuthentication = true;
      } else {
        _isSDKAuthentication = false;
      }
      if (null != _authcb)
        _authcb(result);
    }
    
    function GetAuthResult () {
      return _addon.GetAuthResult();
    }
    
    function onLoginRet(status) {
      console.log('status == GetLoginStatus', status == GetLoginStatus())
      if (null != _logincb)
        _logincb(status)
    }

    function GetLoginStatus () {
      return _addon.GetLoginStatus();
    }

    function onLogout() {
      if (null != _logoutcb)
        _logoutcb();
    }
    
    function OnDirectShareStatusUpdate(status) {
      console.log('OnDirectShareStatusUpdate', status);
    }

    function onZoomIdentityExpired(result) {
      console.log('onZoomIdentityExpired', result);
    }

    if (_addon) {
      _addon.SetLoginCB(onLoginRet);
      _addon.SetLogoutCB(onLogout);
      _addon.SetOnAuthReturnCB(onAuthenticationReturn);
      _addon.SetOnZoomIdentityExpiredCB(onZoomIdentityExpired);
      _addon.GetDirectShareHelperObj().SetDirectShareStatusUpdateCB(OnDirectShareStatusUpdate);
    }

    return {
      // Public methods and variables
      /**
       * mode: SDK Auth
       * @param {String} appkey
       * @param {String} appsecret
       * @return {ZoomSDKError}
       */
      SDKAuth: function (appkey, appsecret){
        if (_addon){
          return _addon.Auth(appkey, appsecret);
        }
        return ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Login
       * @param {String} username
       * @param {String} psw
       * @param {Boolean} rememberme
       * @return {ZoomSDKError}
       */
      Login: function (username, psw, rememberme) {
        if (_isSDKAuthentication && _addon) {
          return _addon.Login(username, psw, rememberme);
        }
        return _isSDKAuthentication ? ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNAUTHENTICATION : ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: LoginWithSSOToken
       * @param {String} ssotoken
       * @return {ZoomSDKError}
       */
      LoginWithSSOToken: function (ssotoken) {
        if (_isSDKAuthentication && _addon)
          return _addon.LoginWithSSOToken(ssotoken, onLoginRet, true);
        return _isSDKAuthentication ? ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNAUTHENTICATION : ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Logout
       * @return {ZoomSDKError}
       */
      Logout: function () {
        if (_isSDKAuthentication && _addon)
          return _addon.Logout();
        return _isSDKAuthentication ? ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNAUTHENTICATION : ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Can Start Direct Share
      * @return {ZoomSDKError}
      */
      CanStartDirectShare: function () {
        if (_addon) {
          return _addon.GetDirectShareHelperObj().CanStartDirectShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Is Direct Share In Progress
      * @return {ZoomSDKError}
      */
      IsDirectShareInProgress: function () {
        if (_addon) {
          return _addon.GetDirectShareHelperObj().IsDirectShareInProgress();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Start Direct Share
      * @return {ZoomSDKError}
      */
      StartDirectShare: function () {
        if (_addon) {
          return _addon.GetDirectShareHelperObj().StartDirectShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Stop Direct Share
      * @return {ZoomSDKError}
      */
      StopDirectShare: function () {
        if (_addon) {
          return _addon.GetDirectShareHelperObj().StopDirectShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Set Direct Share Status Update CB
      * @return {ZoomSDKError}
      */
      SetDirectShareStatusUpdateCB: function (OnDirectShareStatusUpdate) {
        if (_addon) {
          return _addon.GetDirectShareHelperObj().SetDirectShareStatusUpdateCB(OnDirectShareStatusUpdate);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Try With Meeting Number
      * @param {Number} meetingNumber
      * @return {ZoomSDKError}
      */
      TryWithMeetingNumber: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingNumber = clientOpts.meetingNumber;
          return _addon.GetDirectShareHelperObj().TryWithMeetingNumber(Number(meetingNumber));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Try With Pairing Code
      * @param {String} pairingCode
      * @return {ZoomSDKError}
      */
      TryWithPairingCode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let pairingCode = clientOpts.pairingCode;
          return _addon.GetDirectShareHelperObj().TryWithPairingCode(pairingCode);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Cancel
      * @return {ZoomSDKError}
      */
      Cancel: function () {
        if (_addon) {
          return _addon.GetDirectShareHelperObj().Cancel();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    }
  };
 
  return {
    /**
     * mode: Get Zoom SDK Auth Service Module
     * @return {ZoomAuth}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance
    }
  };
 
})();

module.exports = {
  ZoomAuth: ZoomAuth
}