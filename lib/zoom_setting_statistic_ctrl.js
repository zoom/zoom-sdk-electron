const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomSettingStatisticCtrl = (function () {
  var instance;
   /**
   * mode: Zoom SDK Setting Statistic Controller Init
   * @return {ZoomSettingStatisticCtrl}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingStatisticCtrl() || null;

    return {
      // Public methods and variables
      /** 
      * mode: Query Over all Statistic Info
      * @return {ZoomSDKError}
      */
      Setting_QueryOverallStatisticInfo: function () {
        if (_addon){
          return _addon.QueryOverallStatisticInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Query Audio Statistic Info
      * @return {ZoomSDKError}
      */
      Setting_QueryAudioStatisticInfo: function () {
        if (_addon){
          return _addon.QueryAudioStatisticInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Query Video Statistic Info
      * @return {ZoomSDKError}
      */
      Setting_QueryVideoStatisticInfo: function () {
        if (_addon){
          return _addon.QueryVideoStatisticInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Query Share Statistic Info
      * @return {ZoomSDKError}
      */
      Setting_QueryShareStatisticInfo: function () {
        if (_addon){
          return _addon.QueryShareStatisticInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Setting Service Module
     * @return {ZoomSettingStatisticCtrl}
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
  ZoomSettingStatisticCtrl: ZoomSettingStatisticCtrl
}
