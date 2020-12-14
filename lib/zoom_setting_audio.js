
const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
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
    let _onComputerMicDeviceChanged = clientOpts.onComputerMicDeviceChanged || null;
    let _onComputerSpeakerDeviceChanged = clientOpts.onComputerSpeakerDeviceChanged || null;
    let _onDefaultMicDeviceChanged = clientOpts.onDefaultMicDeviceChanged || null;
    let _onDefaultSpeakerDeviceChanged = clientOpts.onDefaultSpeakerDeviceChanged || null;

    function onComputerMicDeviceChanged(newMicList) {
      if (_onComputerMicDeviceChanged) {
        _onComputerMicDeviceChanged(newMicList)
      }
    }
    
    function onComputerSpeakerDeviceChanged(newSpeakerList) {
      if (_onComputerSpeakerDeviceChanged) {
        _onComputerSpeakerDeviceChanged(newSpeakerList)
      }
    }

    function onDefaultMicDeviceChanged(deviceId, deviceName) {
      if (_onDefaultMicDeviceChanged) {
        _onDefaultMicDeviceChanged(deviceId, deviceName)
      }
    }
    
    function onDefaultSpeakerDeviceChanged(deviceId, deviceName) {
      if (_onDefaultSpeakerDeviceChanged) {
        _onDefaultSpeakerDeviceChanged(deviceId, deviceName)
      }
    }
    
    if (_addon) {
      _addon.SetComputerMicDeviceChangedCB(onComputerMicDeviceChanged);
      _addon.SetComputerSpeakerDeviceChangedCB(onComputerSpeakerDeviceChanged);
      _addon.SetDefaultMicDeviceChangedCB(onDefaultMicDeviceChanged);
      _addon.SetDefaultSpeakerDeviceChangedCB(onDefaultSpeakerDeviceChanged);
    }

    let micObj = {};
    let speakerObj = {};

    return {
      /**
      * mode: Set Computer Mic Device Changed CB
      * @param {Function} onComputerMicDeviceChanged
      * @return {Boolean}
      */
      Setting_SetComputerMicDeviceChangedCB: function (onComputerMicDeviceChanged) {
        if (_addon && onComputerMicDeviceChanged && onComputerMicDeviceChanged instanceof Function) {
          _onComputerMicDeviceChanged = onComputerMicDeviceChanged;
          return true;
        }
        return false;
      },
      /**
      * mode: Set Computer Speaker Device Changed CB
      * @param {Function} onComputerSpeakerDeviceChanged
      * @return {Boolean}
      */
      Setting_SetComputerSpeakerDeviceChangedCB: function (onComputerSpeakerDeviceChanged) {
        if (_addon && onComputerSpeakerDeviceChanged && onComputerSpeakerDeviceChanged instanceof Function) {
          _onComputerSpeakerDeviceChanged = onComputerSpeakerDeviceChanged;
          return true;
        }
        return false;
      },
      /**
      * mode: Set Default Mic Device Changed CB
      * @param {Function} onDefaultMicDeviceChanged
      * @return {Boolean}
      */
      Setting_SetDefaultMicDeviceChangedCB: function (onDefaultMicDeviceChanged) {
        if (_addon && onDefaultMicDeviceChanged && onDefaultMicDeviceChanged instanceof Function) {
          _onDefaultMicDeviceChanged = onDefaultMicDeviceChanged;
          return true;
        }
        return false;
      },
      /**
      * mode: Set Default Speaker Device Changed CB
      * @param {Function} onDefaultSpeakerDeviceChanged
      * @return {ZoomSDKError}
      */
      Setting_SetDefaultSpeakerDeviceChangedCB: function (onDefaultSpeakerDeviceChanged) {
        if (_addon && onDefaultSpeakerDeviceChanged && onDefaultSpeakerDeviceChanged instanceof Functio) {
          _onDefaultSpeakerDeviceChanged = onDefaultSpeakerDeviceChanged;
          return true;
        }
        return false;
      },
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
          try {
            let SelectMicParams = new messages.SelectMicParams();
            SelectMicParams.setDeviceid(deviceId);
            SelectMicParams.setDevicename(deviceName);
            let bytes = SelectMicParams.serializeBinary();
            return _addon.SelectMic(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SelectSpeakerParams = new messages.SelectSpeakerParams();
            SelectSpeakerParams.setDeviceid(deviceId);
            SelectSpeakerParams.setDevicename(deviceName);
            let bytes = SelectSpeakerParams.serializeBinary();
            return _addon.SelectSpeaker(bytes)
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
      Checking_IsAutoJoinAudioEnabled: function () {
        if (_addon) {
          return _addon.IsAutoJoinAudioEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Check if Auto Adjust Mic.
      * @return {Boolean}
      */
      Checking_IsAutoAdjustMicEnabled: function () {
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
          try {
            let EnableAutoJoinAudioParams = new messages.EnableAutoJoinAudioParams();
            EnableAutoJoinAudioParams.setBenable(zn_bEnable);
            let bytes = EnableAutoJoinAudioParams.serializeBinary();
            return _addon.EnableAutoJoinAudio(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableAutoAdjustMicParams = new messages.EnableAutoAdjustMicParams();
            EnableAutoAdjustMicParams.setBenable(zn_bEnable);
            let bytes = EnableAutoAdjustMicParams.serializeBinary();
            return _addon.EnableAutoAdjustMic(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Stereo Audio
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableStereoAudio: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableStereoAudioParams = new messages.EnableStereoAudioParams();
            EnableStereoAudioParams.setBenable(bEnable);
            let bytes = EnableStereoAudioParams.serializeBinary();
            return _addon.EnableStereoAudio(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Stereo Audio Enable
      * @return {ZoomSDKError}
      */
      Setting_IsStereoAudioEnable: function () {
        if (_addon) {
          return _addon.IsStereoAudioEnable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Mic Original Input
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableMicOriginalInput: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableMicOriginalInputParams = new messages.EnableMicOriginalInputParams();
            EnableMicOriginalInputParams.setBenable(bEnable);
            let bytes = EnableMicOriginalInputParams.serializeBinary();
            return _addon.EnableMicOriginalInput(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Mic Original Input Enable
      * @return {ZoomSDKError}
      */
      Setting_IsMicOriginalInputEnable: function () {
        if (_addon) {
          return _addon.IsMicOriginalInputEnable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Hold Space Key To Speak
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableHoldSpaceKeyToSpeak: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableHoldSpaceKeyToSpeakParams = new messages.EnableHoldSpaceKeyToSpeakParams();
            EnableHoldSpaceKeyToSpeakParams.setBenable(bEnable);
            let bytes = EnableHoldSpaceKeyToSpeakParams.serializeBinary();
            return _addon.EnableHoldSpaceKeyToSpeak(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Hold Space Key To Speak Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsHoldSpaceKeyToSpeakEnabled: function () {
        if (_addon) {
          return _addon.IsHoldSpaceKeyToSpeakEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Always Mute Mic When Join Voip
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAlwaysMuteMicWhenJoinVoip: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableAlwaysMuteMicWhenJoinVoipParams = new messages.EnableAlwaysMuteMicWhenJoinVoipParams();
            EnableAlwaysMuteMicWhenJoinVoipParams.setBenable(bEnable);
            let bytes = EnableAlwaysMuteMicWhenJoinVoipParams.serializeBinary();
            return _addon.EnableAlwaysMuteMicWhenJoinVoip(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Always Mute Mic When Join Voip Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysMuteMicWhenJoinVoipEnabled: function () {
        if (_addon) {
          return _addon.IsAlwaysMuteMicWhenJoinVoipEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Suppress Audio Notify
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableSuppressAudioNotify: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableSuppressAudioNotifyParams = new messages.EnableSuppressAudioNotifyParams();
            EnableSuppressAudioNotifyParams.setBenable(bEnable);
            let bytes = EnableSuppressAudioNotifyParams.serializeBinary();
            return _addon.EnableSuppressAudioNotify(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Suppress Audio Notify Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsSuppressAudioNotifyEnabled: function () {
        if (_addon) {
          return _addon.IsSuppressAudioNotifyEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Enable Echo Cancel lation
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableEchoCancellation: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableEchoCancellationParams = new messages.EnableEchoCancellationParams();
            EnableEchoCancellationParams.setBenable(bEnable);
            let bytes = EnableEchoCancellationParams.serializeBinary();
            return _addon.EnableEchoCancellation(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Echo Cancel lation Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsEchoCancellationEnabled: function () {
        if (_addon) {
          return _addon.IsEchoCancellationEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Set Mic Vol
      * @param {Number} value
      * @return {ZoomSDKError}
      */
      Setting_SetMicVol: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let value = clientOpts.value;
          try {
            let SetMicVolParams = new messages.SetMicVolParams();
            SetMicVolParams.setValue(Number(value));
            let bytes = SetMicVolParams.serializeBinary();
            return _addon.SetMicVol(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Mic Vol
      * @return {ZoomSDKError}
      */
      Setting_GetMicVol: function () {
        if (_addon) {
          return _addon.GetMicVol();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Set Speaker Vol
      * @param {Number} value
      * @return {ZoomSDKError}
      */
      Setting_SetSpeakerVol: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let value = clientOpts.value;
          try {
            let SetSpeakerVolParams = new messages.SetSpeakerVolParams();
            SetSpeakerVolParams.setValue(Number(value));
            let bytes = SetSpeakerVolParams.serializeBinary();
            return _addon.SetSpeakerVol(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Speaker Vol
      * @return {ZoomSDKError}
      */
      Setting_GetSpeakerVol: function () {
        if (_addon) {
          return _addon.GetSpeakerVol();
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