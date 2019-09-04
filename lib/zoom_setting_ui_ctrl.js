const { ZoomSDKError } = require('./settings.js');

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
      * mode: Disable Advanced Features 4 General Setting
      * @param {Boolean} bDisable
      * @return {ZoomSDKError}
      */
      SettingUI_DisableAdvancedFeatures4GeneralSetting: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          return _addon.DisableAdvancedFeatures4GeneralSetting(bDisable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Disable Account Setting Tab Page
      * @param {Boolean} bDisable
      * @return {ZoomSDKError}
      */
      SettingUI_DisableAccountSettingTabPage: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let bDisable = clientOpts.bDisable;
          return _addon.DisableAccountSettingTabPage(bDisable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Conf Setting Dialog Shown Tab Page
      * @param {Boolean} bShowAccessibility
      * @param {Boolean} bShowAdvancedFeature
      * @param {Boolean} bShowAudio
      * @param {Boolean} bShowFeedback
      * @param {Boolean} bShowGeneral
      * @param {Boolean} bSHowRecording
      * @param {Boolean} bShowStatistics
      * @param {Boolean} bShowVideo
      * @param {Boolean} bShowVirtualBackGround
      * @return {ZoomSDKError}
      */
      SettingUI_ConfSettingDialogShownTabPage: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let bShowAccessibility = clientOpts.bShowAccessibility;
          let bShowAdvancedFeature = clientOpts.bShowAdvancedFeature;
          let bShowAudio = clientOpts.bShowAudio;
          let bShowFeedback = clientOpts.bShowFeedback;
          let bShowGeneral = clientOpts.bShowGeneral;
          let bSHowRecording = clientOpts.bSHowRecording;
          let bShowStatistics = clientOpts.bShowStatistics;
          let bShowVideo = clientOpts.bShowVideo;
          let bShowVirtualBackGround = clientOpts.bShowVirtualBackGround;
          return _addon.ConfSettingDialogShownTabPage(bShowAccessibility, bShowAdvancedFeature, bShowAudio, bShowFeedback, bShowGeneral,
            bSHowRecording, bShowStatistics, bShowVideo, bShowVirtualBackGround);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Service Module
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
