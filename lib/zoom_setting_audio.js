
const { ZoomSDKError } = require('./settings.js');

var ZoomAudioSetting = (function () {
  let instance;
   /**
   * mode: Zoom SDK Audio Settings Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomAudioSetting}
   */
  function init(opts) {
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingAudioCtrl() || null;

    let micObj = {};
    let speakerObj = {};
    return {
    	/** 
       * mode: Select mic
		   * @param {String} deviceId
       * @param {String} deviceName Device&deviceName id of camera
		   * @return {ZoomSDKError}
		   */
      Setting_SelectMic: function (opts) {
      	if (_addon) {
      		let clientOpts = opts || {};
      		let deviceId = clientOpts.deviceId || micObj.deviceId;
      		let deviceName = clientOpts.deviceName || micObj.deviceName;
      		return _addon.SelectMic(deviceId, deviceName);
      	}
      	return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Mic List
      * @return {ZoomSDKError}
      */
      Setting_GetMicList: function () {
      	if (_addon) {
          let micList = _addon.GetMicList();
          micList.forEach(item => {
            micObj.deviceName = item.deviceName
            micObj.deviceId = item.deviceId
            micObj.isSelected = item.isSelected
          })
          return micObj;
      	}
      	return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
    	/** 
      * mode: Select Speaker
      * @param {String} deviceId
      * @param {String} deviceName Device&deviceName id of camera
      * @return {ZoomSDKError}
      */
      Setting_SelectSpeaker: function (opts) {
      	if (_addon) {
      		let clientOpts = opts || {}
      		let deviceId = clientOpts.deviceId || speakerObj.deviceId;
          let deviceName = clientOpts.deviceName || speakerObj.deviceName;
      		return _addon.SelectSpeaker(deviceId, deviceName)
      	}
      	return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode:  Get Speaker List
      * @return {ZoomSDKError}
      */
      Setting_GetSpeakerList: function () {
      	if (_addon) {
          let speakerList = _addon.GetSpeakerList();
          speakerList.forEach(function (item, index) {
            speakerObj.deviceName = item.deviceName
            speakerObj.deviceId = item.deviceId
            speakerObj.isSelected = item.isSelected
          });
          return speakerObj;
      	}
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Check if Auto Join Audio.
      * @return {Boolean}
      */
      Checking_IsAutoJoinAudioEnabled: function (opts) {
        if (_addon) {
          return _addon.IsAutoJoinAudioEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Check if Auto Adjust Mic.
      * @return {Boolean}
      */
      Checking_IsAutoAdjustMicEnabled: function (opts) {
        if (_addon) {
          return _addon.IsAutoAdjustMicEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode:  Setting Enable Auto Join Audio
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAutoJoinAudio: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          return _addon.EnableAutoJoinAudio(zn_bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Setting Enable Auto Adjust Mic
      * @param {Boolean} zn_bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAutoAdjustMic: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_bEnable = clientOpts.zn_bEnable;
          return _addon.EnableAutoAdjustMic(zn_bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK Audio Setting Service Module
     * @return {ZoomSetting}
    */
    getInstance: function (opts) {
      if(!instance) {
        instance = init(opts);
      }
      return instance;;
    }
  };
})();

module.exports = {
  ZoomAudioSetting: ZoomAudioSetting
}