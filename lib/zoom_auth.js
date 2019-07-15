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
          return _addon.Auth(appkey, appsecret, onAuthenticationReturn);
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
          return _addon.Login(username, psw, onLoginRet, rememberme);
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
          return _addon.Logout(onLogout);
        return _isSDKAuthentication ? ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNAUTHENTICATION : ZOOMSDKMOD_4AUTH.ZoomSDKError.SDKERR_UNINITIALIZE;
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