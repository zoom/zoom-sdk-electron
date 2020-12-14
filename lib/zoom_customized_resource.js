const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

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
          try {
            let AddCustomizedPictureResourceParams = new messages.AddCustomizedPictureResourceParams();
            AddCustomizedPictureResourceParams.setStrpngid(strPNGID);
            AddCustomizedPictureResourceParams.setStrpngpath(strPNGPath);
            let bytes = AddCustomizedPictureResourceParams.serializeBinary();
            return _addon.AddCustomizedPictureResource(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let AddCustomizedStringResourceParams = new messages.AddCustomizedStringResourceParams();
            AddCustomizedStringResourceParams.setCustomizedstringtype(CustomizedStringType);
            AddCustomizedStringResourceParams.setStrcustomizedstring(strCustomizedString);
            let bytes = AddCustomizedStringResourceParams.serializeBinary();
            return _addon.AddCustomizedStringResource(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let AddCustomizedURLResourceParams = new messages.AddCustomizedURLResourceParams();
            AddCustomizedURLResourceParams.setCustomizedurltype(CustomizedURLType);
            AddCustomizedURLResourceParams.setStrcustomizedurl(strCustomizeURL);
            let bytes = AddCustomizedURLResourceParams.serializeBinary();
            return _addon.AddCustomizedURLResource(bytes);
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