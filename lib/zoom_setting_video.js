
const { ZoomSDKError } = require('./settings.js');

var ZoomVideoSetting = (function () {
  let instance;
   /**
   * mode: Zoom SDK VideoSettings Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomVideoSetting}
   */
  function init(opts) {
 
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingVideoCtrl() || null;
    let deviceItem = {};
    function ParseDeviceList(str) {
      str.forEach(function (item, index) {
        deviceItem.deviceName = item.deviceName
        deviceItem.deviceId = item.deviceId
        deviceItem.isSelected = item.isSelected
      });
      return deviceItem;
    }
    return {
      /** mode: Select Camera
      * @param {String} zn_deviceId Device id of camera
      * @return {ZoomSDKError}
      */
      Setting_SelectVideoCamera : function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_deviceId = clientOpts.zn_deviceId || deviceItem.deviceId;
          return _addon.SelectVideoCamera(zn_deviceId);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Get Camera List
      * @return {ZoomSDKError}
      */
      Setting_GetCameraList: function () {
        if (_addon) {
          let devicelist_str = _addon.GetCameraList();
          return ParseDeviceList(devicelist_str);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Setting Enable Video Mirror Effect
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableVideoMirrorEffect: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          return _addon.EnableVideoMirrorEffect(zn_bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: Setting Enable Face Beauty Effect
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableFaceBeautyEffect: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          return _addon.EnableFaceBeautyEffect(zn_bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Check if Video Mirror Effect Enabled.
      * @return {ZoomSDKError}
      */
      Checking_IsMirrorEffectEnabled: function () {
        if (_addon) {
          return _addon.IsMirrorEffectEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: Check if Face Beauty Effect Enabled.
      * @return {ZoomSDKError}
      */
      Checking_IsFaceBeautyEffectEnabled: function (opts) {
        if (_addon) {
          return _addon.IsFaceBeautyEffectEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      }
    };
};
  return {
    /**
     * mode: Get Zoom SDK Video Setting Service Module
     * @return {ZoomVideoSetting}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts)
      }
      return instance
    }
  };
})();

module.exports = {
  ZoomVideoSetting: ZoomVideoSetting
}