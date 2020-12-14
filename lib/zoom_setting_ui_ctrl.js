const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
var ZoomSettingUICtrl = (function () {
  var instance;
   /**
   * mode: Zoom SDK Setting UI Controller Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomSettingUICtrl}
   */
  function init(opts) {
    let clientOpts = opts || {};
    let _addon = clientOpts.addon.GetSettingUIStrategyCtrl() || null;

    return {
      // Public methods and variables
      /** 
      * mode: Hide the link to check the advanced settings on the General Setting page or not
      * @param {Boolean} bDisable TRUE indicates to hide the link
      * @return {ZoomSDKError}
      */
      SettingUI_DisableAdvancedFeatures4GeneralSetting: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          try {
            let DisableAdvancedFeatures4GeneralSettingParams = new messages.DisableAdvancedFeatures4GeneralSettingParams();
            DisableAdvancedFeatures4GeneralSettingParams.setBdisable(bDisable);
            let bytes = DisableAdvancedFeatures4GeneralSettingParams.serializeBinary();
            return _addon.DisableAdvancedFeatures4GeneralSetting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Hide the Account Setting page or not
      * @param {Boolean} bDisable TRUE indicates to hide the account setting page
      * @return {ZoomSDKError}
      */
      SettingUI_DisableAccountSettingTabPage: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          try {
            let DisableAccountSettingTabPageParams = new messages.DisableAccountSettingTabPageParams();
            DisableAccountSettingTabPageParams.setBdisable(bDisable);
            let bytes = DisableAccountSettingTabPageParams.serializeBinary();
            return _addon.DisableAccountSettingTabPage(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Custome the tab page show or hide
      * @param {Number} number settingDlgShowTabPageOption, Every bit indicates whether to show a certain tab page
      * bit 1: indicates whether to show virtual background page. "1" show, "0" not show
      * bit 2: indicates to whether to show video page. "1" show, "0" not show
      * bit 3: indicates to whether to show staticstics page. "1" show, "0" not show
      * bit 4: indicates to whether to show recording page. "1" show, "0" not show
      * bit 5: indicates to whether to show general page. "1" show, "0" not show
      * bit 6: indicates to whether to show feed back page. "1" show, "0" not show
      * bit 7: indicates to whether to show audio page. "1" show, "0" not show
      * bit 8: indicates to whether to show advance feature page. "1" show, "0" not show
      * bit 9: indicates to whether to show accessibility page. "1" show, "0" not show
      * @return {ZoomSDKError}
      */
      SettingUI_ConfSettingDialogShownTabPage: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let number = clientOpts.number;
          try {
            let ConfSettingDialogShownTabPageParams = new messages.ConfSettingDialogShownTabPageParams();
            ConfSettingDialogShownTabPageParams.setShowoption(number);
            let bytes = ConfSettingDialogShownTabPageParams.serializeBinary();
            return _addon.ConfSettingDialogShownTabPage(bytes);
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
     * mode: Get Zoom SDK Setting Service Module
     * @return {ZoomSettingUICtrl}
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
  ZoomSettingUICtrl: ZoomSettingUICtrl
}
