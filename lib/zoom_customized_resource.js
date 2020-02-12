const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomCustomizedResource = (function () {
  var instance;
  /**
   * mode: Zoom SDK ZoomCustomizedResource Service Init
   * @param {Object} addon: zoom sdk module
   * @return {ZoomCustomizedResource}
   */
  function init(opts) { 
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetCustomizedResourceObj() || null;

    return {
      /**
      * mode: Add Customized Picture Resource
      * @param {String} strPNGID
      * @param {String} strPNGPath
      * @return {ZoomCustomizedResource}
      */
      Resource_AddCustomizedPictureResource: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let strPNGID = clientOpts.strPNGID;
          let strPNGPath = clientOpts.strPNGPath;
          return _addon.AddCustomizedPictureResource(strPNGID, strPNGPath);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Add Customized String Resource
      * @param {String} CustomizedStringType
      * @param {String} strCustomizedString
      * @return {ZoomCustomizedResource}
      */
      Resource_AddCustomizedStringResource: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let CustomizedStringType = clientOpts.CustomizedStringType;
          let strCustomizedString = clientOpts.strCustomizedString;
          return _addon.AddCustomizedStringResource(CustomizedStringType, strCustomizedString);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Add Customized URL Resource
      * @param {String} CustomizedURLType
      * @param {String} strCustomizeURL
      * @return {ZoomCustomizedResource}
      */
      Resource_AddCustomizedURLResource: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let CustomizedURLType = clientOpts.CustomizedURLType;
          let strCustomizeURL = clientOpts.strCustomizeURL;
          return _addon.AddCustomizedURLResource(CustomizedURLType, strCustomizeURL);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK ZoomCustomizedResource Service Module
     * @return {ZoomCustomizedResource}
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
  ZoomCustomizedResource: ZoomCustomizedResource
}