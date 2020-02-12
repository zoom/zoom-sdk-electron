
const { ZoomSDKError } = require('./settings.js');

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
          return _addon.EnableStereoAudio(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Stereo Audio Enable
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsStereoAudioEnable: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsStereoAudioEnable(bEnable);
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
          return _addon.EnableMicOriginalInput(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Mic Original Input Enable
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsMicOriginalInputEnable: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsMicOriginalInputEnable(bEnable);
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
          return _addon.EnableHoldSpaceKeyToSpeak(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Hold Space Key To Speak Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsHoldSpaceKeyToSpeakEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsHoldSpaceKeyToSpeakEnabled(bEnable);
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
          return _addon.EnableAlwaysMuteMicWhenJoinVoip(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Always Mute Mic When Join Voip Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysMuteMicWhenJoinVoipEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAlwaysMuteMicWhenJoinVoipEnabled(bEnable);
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
          return _addon.EnableSuppressAudioNotify(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Suppress Audio Notify Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsSuppressAudioNotifyEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsSuppressAudioNotifyEnabled(bEnable);
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
          return _addon.EnableEchoCancellation(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Is Echo Cancel lation Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsEchoCancellationEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsEchoCancellationEnabled(bEnable);
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
          return _addon.SetMicVol(Number(value));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Mic Vol
      * @param {Number} value
      * @return {ZoomSDKError}
      */
      Setting_GetMicVol: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let value = clientOpts.value;
          return _addon.GetMicVol(Number(value));
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
          return _addon.SetSpeakerVol(Number(value));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Get Speaker Vol
      * @param {Number} value
      * @return {ZoomSDKError}
      */
      Setting_GetSpeakerVol: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let value = clientOpts.value;
          return _addon.GetSpeakerVol(Number(value));
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