const { ZoomSDKError } = require('./settings.js');

var ZoomRecordingSetting = (function () {

  var instance;
   /**
   * mode: Zoom SDK RecordingSetting Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomRecordingSetting}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingRecordingCtrl() || null;

    return {
      /** Set Recording Path
      * @param {String} szPath
      * @return {ZoomSDKError}
      */
      Setting_SetRecordingPath: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_szPath = clientOpts.zn_szPath;
          return _addon.SetRecordingPath(zn_szPath);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Get Recording Path
      * @return {ZoomSDKError}
      */
      Getting_GetRecordingPath: function () {
        if (_addon) {
          return _addon.GetRecordingPath();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK General Setting Service Module
     * @return {ZoomGeneralSetting}
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
  ZoomRecordingSetting: ZoomRecordingSetting
} 