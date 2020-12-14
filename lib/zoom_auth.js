const { ZoomAuthResult, ZoomSDKError } = require('./settings.js');
const ZOOMDIRECTSHAREMOD = require('./zoom_direct_share_helper.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
const ZoomAuth = (function () {
  let instance;

  /**
   * mode: Zoom SDK Authentication Service Init
   * @param {Function} authcb authcb callback
   * @param {Function} logincb logincb callback
   * @param {Function} logoutcb logoutcb callback
   * @param {Function} onZoomIdentityExpired onZoomIdentityExpired callback
   * @param {Function} onZoomAuthIdentityExpired onZoomAuthIdentityExpired callback
   * @return {ZoomAuth}
   */
  function init(opts) {
    let clientOpts = opts || {};
    let _addon = clientOpts.addon.GetAuthObj() || null;
    let _authcb = clientOpts.authcb || null;
    let _logincb = clientOpts.logincb || null;
    let _logoutcb = clientOpts.logoutcb || null;
    let _onZoomIdentityExpired = clientOpts.onZoomIdentityExpired || null;
    let _onZoomAuthIdentityExpired = clientOpts.onZoomAuthIdentityExpired || null;
    let _isSDKAuthentication = false;
    
    function onAuthenticationReturn(authResult) {
      if (ZoomAuthResult.AUTHRET_SUCCESS == authResult) {
        _isSDKAuthentication = true;
      } else {
        _isSDKAuthentication = false;
      }
      if (_authcb)
        _authcb(authResult);
    }
    
    function logincb(status) {
      if (_logincb)
        _logincb(status)
    }

    function logoutcb() {
      if (_logoutcb)
        _logoutcb();
    }
    
    function onZoomIdentityExpired() {
      if (_onZoomIdentityExpired) {
        _onZoomIdentityExpired()
      }
    }

    function onZoomAuthIdentityExpired() {
      if (_onZoomAuthIdentityExpired) {
        _onZoomAuthIdentityExpired()
      }
    }


    if (_addon) {
      _addon.SetOnAuthReturnCB(onAuthenticationReturn);
      _addon.SetLoginCB(logincb);
      _addon.SetLogoutCB(logoutcb);
      _addon.SetOnZoomIdentityExpiredCB(onZoomIdentityExpired);
      _addon.SetOnZoomAuthIdentityExpiredCB(onZoomAuthIdentityExpired);
    }

    return {
      // Public methods and variables
      /**
       * mode: Set On Auth Return CB
       * @param {Function} calloutstatuscb
       * @return {Boolean}
       */
      SetOnAuthReturnCB: function (authcb) {
        if (addon && authcb && authcb instanceof Function) {
          _authcb = authcb
          return true
        }
        return false
      },
      /**
       * mode: Set Login CB
       * @param {Function} logincb
       * @return {Boolean}
       */
      SetLoginCB: function (logincb) {
        if (addon && logincb && logincb instanceof Function) {
          _logincb = logincb
          return true
        }
        return false
      },
      /**
       * mode: Set Logout CB
       * @param {Function} logoutcb
       * @return {Boolean}
       */
      SetLogoutCB: function (logoutcb) {
        if (addon && logoutcb && logoutcb instanceof Function) {
          _logoutcb = logoutcb
          return true
        }
        return false
      },
      /**
       * mode: Set On Zoom Identity Expired CB
       * @param {Function} onZoomIdentityExpired
       * @return {Boolean}
       */
      SetOnZoomIdentityExpiredCB: function (onZoomIdentityExpired) {
        if (addon && onZoomIdentityExpired && onZoomIdentityExpired instanceof Function) {
          _onZoomIdentityExpired = onZoomIdentityExpired
          return true
        }
        return false
      },
      /**
       * mode: Set On Zoom Auth Identity Expired CB
       * @param {Function} onZoomAuthIdentityExpired
       * @return {Boolean}
       */
      SetOnZoomAuthIdentityExpiredCB: function (onZoomAuthIdentityExpired) {
        if (addon && onZoomAuthIdentityExpired && onZoomAuthIdentityExpired instanceof Function) {
          _onZoomAuthIdentityExpired = onZoomAuthIdentityExpired
          return true
        }
        return false
      },
      /**
       * mode: SDK Auth
       * @param {String} appkey
       * @param {String} appsecret
       * @return {ZoomSDKError}
       */
      SDKAuth: function (appkey, appsecret){
        if (_addon){
          try {
            let AuthParams = new messages.AuthParams()
            AuthParams.setKey(appkey)
            AuthParams.setSecret(appsecret)
            let bytes = AuthParams.serializeBinary()
            return _addon.Auth(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let LoginParams = new messages.LoginParams()
            LoginParams.setUsername(username)
            LoginParams.setPsw(psw)
            LoginParams.setRememberme(rememberme)
            let bytes = LoginParams.serializeBinary()
            return _addon.Login(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: LoginWithSSOToken
       * @param {String} ssotoken
       * @param {String} rememberme
       * @return {ZoomSDKError}
       */
      LoginWithSSOToken: function (ssotoken, rememberme) {
        if (_isSDKAuthentication && _addon) {
          try {
            let LoginWithSSOTokenParams = new messages.LoginWithSSOTokenParams()
            LoginWithSSOTokenParams.setSsotoken(ssotoken)
            LoginWithSSOTokenParams.setRememberme(rememberme || false)
            let bytes = LoginWithSSOTokenParams.serializeBinary()
            return _addon.LoginWithSSOToken(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
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
          try {
            let AuthWithJwtTokenParams = new messages.AuthWithJwtTokenParams()
            AuthWithJwtTokenParams.setSdkjwttoken(sdk_context)
            let bytes = AuthWithJwtTokenParams.serializeBinary()
            return _addon.AuthWithJwtToken(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      GetDirectShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZOOMDIRECTSHAREMOD.ZoomDirectShareHelper.getInstance(clientOpts);
        }
        return _isSDKAuthentication ? ZoomSDKError.SDKERR_UNAUTHENTICATION : ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get Auth Result
      * @return {ZoomSDKError}
      */
      GetAuthResult: function () {
        return _addon.GetAuthResult();
      },
      /**
      * mode: Get Auth Result
      * @return {ZoomSDKError}
      */
      GetLoginStatus: function () {
        return _addon.GetLoginStatus();
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
