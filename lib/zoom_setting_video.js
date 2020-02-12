
const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
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
    let _onComputerCamDeviceChanged = clientOpts.onComputerCamDeviceChanged || null;
    let _onDefaultCamDeviceChanged = clientOpts.onDefaultCamDeviceChanged || null;
    
    let deviceItem = {};
    function ParseDeviceList(str) {
      str.forEach(function (item, index) {
        deviceItem.deviceName = item.deviceName
        deviceItem.deviceId = item.deviceId
        deviceItem.isSelected = item.isSelected
      });
      return deviceItem;
    }
    
    function onComputerCamDeviceChanged(newCameraList) {
      if (_onComputerCamDeviceChanged) {
        _onComputerCamDeviceChanged(newCameraList)
      }
    }
    
    function onDefaultCamDeviceChanged(deviceId, deviceName) {
      if (_onDefaultCamDeviceChanged) {
        _onDefaultCamDeviceChanged(deviceId, deviceName)
      }
    }
    
    if (_addon) {
      _addon.SetComputerCamDeviceChangedCB(onComputerCamDeviceChanged);
      _addon.SetDefaultCamDeviceChangedCB(onDefaultCamDeviceChanged);
    }

    return {
      /**
      * mode: Set Computer Cam Device Changed CB
      * @param {Function} onComputerCamDeviceChanged
      * @return {Boolean}
      */
      Setting_SetComputerCamDeviceChangedCB: function (onComputerCamDeviceChanged) {
        if (_addon && onComputerCamDeviceChanged && onComputerCamDeviceChanged instanceof Function) {
          _onComputerCamDeviceChanged = onComputerCamDeviceChanged;
          return true;
        }
        return false;
      },
      /**
      * mode: Set Default Cam Device Changed CB
      * @param {Function} onDefaultCamDeviceChanged
      * @return {Boolean}
      */
      Setting_SetDefaultCamDeviceChangedCB: function (onDefaultCamDeviceChanged) {
        if (_addon && onDefaultCamDeviceChanged && onDefaultCamDeviceChanged instanceof Function) {
          _onDefaultCamDeviceChanged = onDefaultCamDeviceChanged;
          return true;
        }
        return false;
      },
      /** mode: Select Camera
      * @param {String} zn_deviceId Device id of camera
      * @return {ZoomSDKError}
      */
      Setting_SelectVideoCamera: function(opts) {
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
      },
      /** mode: Enable HD Video
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableHDVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableHDVideo(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is HD Video Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsHDVideoEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsHDVideoEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Always Show Name On Video
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAlwaysShowNameOnVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAlwaysShowNameOnVideo(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Always Show Name On Video Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysShowNameOnVideoEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAlwaysShowNameOnVideoEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Auto Turn Off Video When Join Meeting
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAutoTurnOffVideoWhenJoinMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAutoTurnOffVideoWhenJoinMeeting(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Auto Turn Off Video When Join Meeting Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsAutoTurnOffVideoWhenJoinMeetingEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAutoTurnOffVideoWhenJoinMeetingEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Always Use 16v9
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableAlwaysUse16v9: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableAlwaysUse16v9(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Always Use 16v9
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysUse16v9: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAlwaysUse16v9(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Spot light Self
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableSpotlightSelf: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableSpotlightSelf(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Spot light Self Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsSpotlightSelfEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsSpotlightSelfEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Hardware Encode
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableHardwareEncode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableHardwareEncode(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Hardware Encode Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsHardwareEncodeEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsHardwareEncodeEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable 49Videoes InGallary View
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_Enable49VideoesInGallaryView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.Enable49VideoesInGallaryView(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is b49 Videoes In Gallary View Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_Is49VideoesInGallaryViewEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.Is49VideoesInGallaryViewEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Hide No Video Users On WallView
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableHideNoVideoUsersOnWallView: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.EnableHideNoVideoUsersOnWallView(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Hide No Video Users On Wall View Enabled
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_IsHideNoVideoUsersOnWallViewEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsHideNoVideoUsersOnWallViewEnabled(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
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