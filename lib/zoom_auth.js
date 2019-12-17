const { ZoomAuthResult, ZoomSDKError } = require('./settings.js');
const ZOOMDIRECTSHAREMOD = require('./zoom_direct_share_helper.js');

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
    let _addon = clientOpts.addon.GetAuthObj() || null;
    let _authcb = clientOpts.authcb || null;
    let _logincb = clientOpts.logincb || null;
    let _logoutcb = clientOpts.logoutcb || null;
    let _isSDKAuthentication = false;
    
    function onAuthenticationReturn(result) {
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
    
    function onZoomIdentityExpired(result) {
    }

    function onZoomAuthIdentityExpired(result) {
    }


    if (_addon) {
      _addon.SetLoginCB(onLoginRet);
      _addon.SetLogoutCB(onLogout);
      _addon.SetOnAuthReturnCB(onAuthenticationReturn);
      _addon.SetOnZoomIdentityExpiredCB(onZoomIdentityExpired);
      _addon.SetOnZoomAuthIdentityExpiredCB(onZoomAuthIdentityExpired);
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
        return ZoomSDKError.SDKERR_UNINITIALIZE;
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
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: LoginWithSSOToken
       * @param {String} ssotoken
       * @return {ZoomSDKError}
       */
      LoginWithSSOToken: function (ssotoken) {
        if (_isSDKAuthentication && _addon)
          return _addon.LoginWithSSOToken(ssotoken, onLoginRet, true);
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Logout
       * @return {ZoomSDKError}
       */
      Logout: function () {
        if (_isSDKAuthentication && _addon)
          return _addon.Logout();
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: AuthWithJwtToken
       * @param {String} sdk_context
       * @return {ZoomSDKError}
       */
      AuthWithJwtToken: function (sdk_context) {
        if (_addon) {
          return _addon.AuthWithJwtToken(sdk_context);
        }
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get Zoom SDK Direct Share Helper Service Module
      * @return {ZoomSDKError}
      */
      GetDirectShare: (opts) => {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZOOMDIRECTSHAREMOD.ZoomDirectShareHelper.getInstance(clientOpts);
        }
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
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