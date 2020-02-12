const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomH323 = (function () {
  var instance;

  /**
   * Zoom SDK H323 Service Init
   * @param {Function} calloutstatuscb call out status callback
   * @return {ZoomH323}
   */
  function init(opts) {

    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingH323Ctrl() || null;
    let _calloutstatuscb = clientOpts.calloutstatuscb || null;
    
    function onH323CalloutStatusNotify(status) {
      if (null != _calloutstatuscb)
      _calloutstatuscb(status)
    }
    
    if (_addon) {
      _addon.SetH323CallOutStatusCB(onH323CalloutStatusNotify)
    }	

    return {
      /**
       * mode: Set H323 Call Out Status CB
       * @param {Function} calloutstatuscb
       * @return {Boolean}
       */
      H323_SetH323CallOutStatusCB: function (calloutstatuscb) {
        if (addon && calloutstatuscb && calloutstatuscb instanceof Function) {
          _calloutstatuscb = calloutstatuscb
          return true
        }
        return false
      },
      /**
      * mode: H323 CallOut
      * @param {String} deviceName
      * @param {String} deviceIP
      * @param {String} deviceE164Num
      * @param {Number} type
      * @return {ZoomSDKError}
      */
      H323_CallOutH323: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let deviceName = clientOpts.deviceName || '';
          let deviceIP = clientOpts.deviceIP || '';
          let deviceE164num = clientOpts.deviceE164num || '';
          let type = clientOpts.type || 0;
          return _addon.CallOutH323(deviceName, deviceIP, deviceE164num, type);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Cancel H323 CallOut
       * @return {ZoomSDKError}
       */
      H323_CancelCallOutH323: function () {
        if (_addon) {
          return _addon.CancelCallOutH323();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Get H3232 Address
       * @return {ZoomSDKError}
       */
      H323_GetH323Address: function (){
        if (_addon) {
          return _addon.GetH323Address();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Get H323 Password
       * @return {ZoomSDKError}
       */
      H323_GetH323Password: function () {
        if (_addon)
          return _addon.GetH323Password();
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Get Callout H323 Device List
       * @return {ZoomSDKError}
       */
      H323_GetCalloutH323DeviceList: function () {
        if (_addon) {
          return _addon.GetCalloutH323DviceList()
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK H323 Service Module
     * @return {ZoomH323}
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
  ZoomH323: ZoomH323
}