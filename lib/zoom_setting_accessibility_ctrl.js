const { ZoomSDKError } = require('./settings.js');

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
      * @return {ZoomSDKError}
      */
      Setting_EnableAlwaysShowMeetingControls: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAlwaysShowMeetingControls(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Always Show Meeting Controls Enable
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysShowMeetingControlsEnable: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAlwaysShowMeetingControlsEnable(bEnable);
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
