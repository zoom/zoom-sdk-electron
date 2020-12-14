const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

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
          try {
            let SelectVideoCameraParams = new messages.SelectVideoCameraParams();
            SelectVideoCameraParams.setDeviceid(zn_deviceId);
            let bytes = SelectVideoCameraParams.serializeBinary();
            return _addon.SelectVideoCamera(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableVideoMirrorEffectParams = new messages.EnableVideoMirrorEffectParams();
            EnableVideoMirrorEffectParams.setBenable(zn_bEnable);
            let bytes = EnableVideoMirrorEffectParams.serializeBinary();
            return _addon.EnableVideoMirrorEffect(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableFaceBeautyEffectParams = new messages.EnableFaceBeautyEffectParams();
            EnableFaceBeautyEffectParams.setBenable(zn_bEnable);
            let bytes = EnableFaceBeautyEffectParams.serializeBinary();
            return _addon.EnableFaceBeautyEffect(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let EnableHDVideoParams = new messages.EnableHDVideoParams();
            EnableHDVideoParams.setBenable(bEnable);
            let bytes = EnableHDVideoParams.serializeBinary();
            return _addon.EnableHDVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is HD Video Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsHDVideoEnabled: function () {
        if (_addon) {
          return _addon.IsHDVideoEnabled();
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
          try {
            let EnableAlwaysShowNameOnVideoParams = new messages.EnableAlwaysShowNameOnVideoParams();
            EnableAlwaysShowNameOnVideoParams.setBenable(bEnable);
            let bytes = EnableAlwaysShowNameOnVideoParams.serializeBinary();
            return _addon.EnableAlwaysShowNameOnVideo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Always Show Name On Video Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysShowNameOnVideoEnabled: function () {
        if (_addon) {
          return _addon.IsAlwaysShowNameOnVideoEnabled();
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
          try {
            let EnableAutoTurnOffVideoWhenJoinMeetingParams = new messages.EnableAutoTurnOffVideoWhenJoinMeetingParams();
            EnableAutoTurnOffVideoWhenJoinMeetingParams.setBenable(bEnable);
            let bytes = EnableAutoTurnOffVideoWhenJoinMeetingParams.serializeBinary();
            return _addon.EnableAutoTurnOffVideoWhenJoinMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Auto Turn Off Video When Join Meeting Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsAutoTurnOffVideoWhenJoinMeetingEnabled: function () {
        if (_addon) {
          return _addon.IsAutoTurnOffVideoWhenJoinMeetingEnabled();
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
          try {
            let EnableAlwaysUse16v9Params = new messages.EnableAlwaysUse16v9Params();
            EnableAlwaysUse16v9Params.setBenable(bEnable);
            let bytes = EnableAlwaysUse16v9Params.serializeBinary();
            return _addon.EnableAlwaysUse16v9(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Always Use 16v9
      * @return {ZoomSDKError}
      */
      Setting_IsAlwaysUse16v9: function (ops) {
        if (_addon) {
          return _addon.IsAlwaysUse16v9();
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
          try {
            let EnableSpotlightSelfParams = new messages.EnableSpotlightSelfParams();
            EnableSpotlightSelfParams.setBenable(bEnable);
            let bytes = EnableSpotlightSelfParams.serializeBinary();
            return _addon.EnableSpotlightSelf(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Spot light Self Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsSpotlightSelfEnabled: function () {
        if (_addon) {
          return _addon.IsSpotlightSelfEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Hardware Encode
      * @param {Boolean} bEnable Enable or not
      * @param {Number} encodeType see ZoomSDKVideoHardwareEncodeType in setting.js
      * @return {ZoomSDKError}
      */
      Setting_EnableHardwareEncode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          let encodeType = clientOpts.encodeType;
          try {
            let EnableHardwareEncodeParams = new messages.EnableHardwareEncodeParams();
            EnableHardwareEncodeParams.setBenable(bEnable);
            EnableHardwareEncodeParams.setEncodetype(encodeType);
            let bytes = EnableHardwareEncodeParams.serializeBinary();
            return _addon.EnableHardwareEncode(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Hardware Encode Enabled
      * @param {Number} encodeType see ZoomSDKVideoHardwareEncodeType in setting.js
      * @return {ZoomSDKError}
      */
      Setting_IsHardwareEncodeEnabled: function () {
        if (_addon) {
          let clientOpts = opts || {};
          let encodeType = clientOpts.encodeType;
          try {
            let IsHardwareEncodeEnabledParams = new messages.IsHardwareEncodeEnabledParams();
            IsHardwareEncodeEnabledParams.setEncodetype(encodeType);
            let bytes = IsHardwareEncodeEnabledParams.serializeBinary();
            return _addon.IsHardwareEncodeEnabled(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let Enable49VideoesInGallaryViewParams = new messages.Enable49VideoesInGallaryViewParams();
            Enable49VideoesInGallaryViewParams.setBenable(bEnable);
            let bytes = Enable49VideoesInGallaryViewParams.serializeBinary();
            return _addon.Enable49VideoesInGallaryView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is b49 Videoes In Gallary View Enabled
      * @return {ZoomSDKError}
      */
      Setting_Is49VideoesInGallaryViewEnabled: function () {
        if (_addon) {
          return _addon.Is49VideoesInGallaryViewEnabled();
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
          try {
            let EnableHideNoVideoUsersOnWallViewParams = new messages.EnableHideNoVideoUsersOnWallViewParams();
            EnableHideNoVideoUsersOnWallViewParams.setBenable(bEnable);
            let bytes = EnableHideNoVideoUsersOnWallViewParams.serializeBinary();
            return _addon.EnableHideNoVideoUsersOnWallView(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Hide No Video Users On Wall View Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsHideNoVideoUsersOnWallViewEnabled: function () {
        if (_addon) {
          return _addon.IsHideNoVideoUsersOnWallViewEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Enable Video Preview Dialog
      * @param {Boolean} bEnable Enable or not
      * @return {ZoomSDKError}
      */
      Setting_EnableVideoPreviewDialog: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableVideoPreviewDialogParams = new messages.EnableVideoPreviewDialogParams();
            EnableVideoPreviewDialogParams.setBenable(bEnable);
            let bytes = EnableVideoPreviewDialogParams.serializeBinary();
            return _addon.EnableVideoPreviewDialog(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Is Video Preview Dialog Enabled
      * @return {Boolean}
      */
      Setting_IsVideoPreviewDialogEnabled: function () {
        if (_addon) {
          return _addon.IsVideoPreviewDialogEnabled();
        }
        return false;
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