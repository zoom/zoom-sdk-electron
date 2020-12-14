const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
var ZoomSettingAccessibilityCtrl = (function () {
  var instance;
   /**
   * mode: Zoom SDK Setting Accessibility Controller Init
   * @return {ZoomSettingAccessibilityCtrl}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingAccessibilityCtrl() || null;

    return {
      // Public methods and variables
      /** 
      * mode: Enable Always Show Meeting Controls
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnableAlwaysShowMeetingControls: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableAlwaysShowMeetingControlsParams = new messages.EnableAlwaysShowMeetingControlsParams();
            EnableAlwaysShowMeetingControlsParams.setBenable(Boolean(bEnable));
            let bytes = EnableAlwaysShowMeetingControlsParams.serializeBinary();
            return _addon.EnableAlwaysShowMeetingControls(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Always Show Meeting Controls Enable
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysShowMeetingControlsEnable: function () {
        if (_addon) {
          return _addon.IsAlwaysShowMeetingControlsEnable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Setting Service Module
     * @return {ZoomSettingAccessibilityCtrl}
    */
    getInstance: function(opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomSettingAccessibilityCtrl: ZoomSettingAccessibilityCtrl
}
