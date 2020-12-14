const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
var ZoomRecordingSetting = (function () {

  var instance;
   /**
   * mode: Zoom SDK RecordingSetting Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomRecordingSetting}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetSettingRecordingCtrl() || null;
    let _onCloudRecordingStorageInfo = clientOpts.onCloudRecordingStorageInfo || null;

    function onCloudRecordingStorageInfo(storage_total_size, storage_used_size, allow_exceed_storage) {
      if (_onCloudRecordingStorageInfo) {
        _onCloudRecordingStorageInfo(storage_total_size, storage_used_size, allow_exceed_storage)
      }
    }
    
    if (_addon) {
      _addon.SetonCloudRecordingStorageInfoCB(onCloudRecordingStorageInfo);
    }

    return {
      /**
      * mode: Setb on Cloud Recording Storage Info CB
      * @param {Function} onCloudRecordingStorageInfo
      * @return {Boolean}
      */
      Setting_SetonCloudRecordingStorageInfoCB: function (onCloudRecordingStorageInfo) {
        if (_addon && onCloudRecordingStorageInfo && onCloudRecordingStorageInfo instanceof Function) {
          _onCloudRecordingStorageInfo = onCloudRecordingStorageInfo;
          return true;
        }
        return false;
      },
      /** Set Recording Path
      * @param {String} szPath
      * @return {ZoomSDKError}
      */
      Setting_SetRecordingPath: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_szPath = clientOpts.zn_szPath;
          try {
            let SetRecordingPathParams = new messages.SetRecordingPathParams();
            SetRecordingPathParams.setRecpath(zn_szPath);
            let bytes = SetRecordingPathParams.serializeBinary();
            return _addon.SetRecordingPath(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Get Recording Path
      * @return {ZoomSDKError}
      */
      Getting_GetRecordingPath: function () {
        if (_addon) {
          return _addon.GetRecordingPath();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Can Get Cloud Recording Storage Info
      * @return {ZoomSDKError}
      */
      Setting_CanGetCloudRecordingStorageInfo: function () {
        if (_addon) {
          return _addon.CanGetCloudRecordingStorageInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Get Cloud Recording Storage Info
      * @return {ZoomSDKError}
      */
      Getting_GetCloudRecordingStorageInfo: function () {
        if (_addon) {
          return _addon.GetCloudRecordingStorageInfo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Get Recording Management URL
      * @return {ZoomSDKError}
      */
      Getting_GetRecordingManagementURL: function () {
        if (_addon) {
          return _addon.GetRecordingManagementURL();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Can Get Recording Management URL
      * @return {ZoomSDKError}
      */
      Setting_CanGetRecordingManagementURL: function () {
        if (_addon) {
          return _addon.CanGetRecordingManagementURL();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Enable Select Record File Location After Meeting
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnableSelectRecordFileLocationAfterMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableSelectRecordFileLocationAfterMeetingParams = new messages.EnableSelectRecordFileLocationAfterMeetingParams();
            EnableSelectRecordFileLocationAfterMeetingParams.setBenable(bEnable);
            let bytes = EnableSelectRecordFileLocationAfterMeetingParams.serializeBinary();
            return _addon.EnableSelectRecordFileLocationAfterMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Select Record File Location After Meeting Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsSelectRecordFileLocationAfterMeetingEnabled: function () {
        if (_addon) {
          return _addon.IsSelectRecordFileLocationAfterMeetingEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Enable Multi Audio Stream Record
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnableMultiAudioStreamRecord: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableMultiAudioStreamRecordParams = new messages.EnableMultiAudioStreamRecordParams();
            EnableMultiAudioStreamRecordParams.setBenable(bEnable);
            let bytes = EnableMultiAudioStreamRecordParams.serializeBinary();
            return _addon.EnableMultiAudioStreamRecord(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Multi Audio Stream Record Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsMultiAudioStreamRecordEnabled: function () {
        if (_addon) {
          return _addon.IsMultiAudioStreamRecordEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Enable Add Time stamp Water mark
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnableAddTimestampWatermark: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableAddTimestampWatermarkParams = new messages.EnableAddTimestampWatermarkParams();
            EnableAddTimestampWatermarkParams.setBenable(bEnable);
            let bytes = EnableAddTimestampWatermarkParams.serializeBinary();
            return _addon.EnableAddTimestampWatermark(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Add Time stamp Water mark Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsAddTimestampWatermarkEnabled: function () {
        if (_addon) {
          return _addon.IsAddTimestampWatermarkEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Enable Optimize For 3rd Party Video Editor
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnableOptimizeFor3rdPartyVideoEditor: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableOptimizeFor3rdPartyVideoEditorParams = new messages.EnableOptimizeFor3rdPartyVideoEditorParams();
            EnableOptimizeFor3rdPartyVideoEditorParams.setBenable(bEnable);
            let bytes = EnableOptimizeFor3rdPartyVideoEditorParams.serializeBinary();
            return _addon.EnableOptimizeFor3rdPartyVideoEditor(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Optimize For 3rd Party Video Editor Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsOptimizeFor3rdPartyVideoEditorEnabled: function () {
        if (_addon) {
          return _addon.IsOptimizeFor3rdPartyVideoEditorEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Enable Show Video Thumbnail When Share
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnableShowVideoThumbnailWhenShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnableShowVideoThumbnailWhenShareParams = new messages.EnableShowVideoThumbnailWhenShareParams();
            EnableShowVideoThumbnailWhenShareParams.setBenable(bEnable);
            let bytes = EnableShowVideoThumbnailWhenShareParams.serializeBinary();
            return _addon.EnableShowVideoThumbnailWhenShare(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Show Video Thumbnail When Share Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsShowVideoThumbnailWhenShareEnabled: function () {
        if (_addon) {
          return _addon.IsShowVideoThumbnailWhenShareEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Enable Place Video Next To Share In Record
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_EnablePlaceVideoNextToShareInRecord: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          try {
            let EnablePlaceVideoNextToShareInRecordParams = new messages.EnablePlaceVideoNextToShareInRecordParams();
            EnablePlaceVideoNextToShareInRecordParams.setBenable(bEnable);
            let bytes = EnablePlaceVideoNextToShareInRecordParams.serializeBinary();
            return _addon.EnablePlaceVideoNextToShareInRecord(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Place Video Next To Share In Record Enabled
      * @return {ZoomSDKError}
      */
      Setting_IsPlaceVideoNextToShareInRecordEnabled: function () {
        if (_addon) {
          return _addon.IsPlaceVideoNextToShareInRecordEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK General Setting Service Module
     * @return {ZoomGeneralSetting}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomRecordingSetting: ZoomRecordingSetting
} 