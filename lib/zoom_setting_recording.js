const { ZoomSDKError } = require('./settings.js');

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
          return _addon.SetRecordingPath(zn_szPath);
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
      * @param {Boolean} bCan
      * @return {ZoomSDKError}
      */
      Setting_CanGetCloudRecordingStorageInfo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bCan = clientOpts.bCan;
          return _addon.CanGetCloudRecordingStorageInfo(bCan);
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
      * @param {Boolean} bCan
      * @return {ZoomSDKError}
      */
      Setting_CanGetRecordingManagementURL: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bCan = clientOpts.bCan;
          return _addon.CanGetRecordingManagementURL(bCan);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Can Get Recording Management URL
      * @param {Boolean} bCan
      * @return {ZoomSDKError}
      */
      Setting_CanGetRecordingManagementURL: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bCan = clientOpts.bCan;
          return _addon.CanGetRecordingManagementURL(bCan);
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
          return _addon.EnableSelectRecordFileLocationAfterMeeting(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Select Record File Location After Meeting Enabled
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_IsSelectRecordFileLocationAfterMeetingEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsSelectRecordFileLocationAfterMeetingEnabled(bEnable);
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
          return _addon.EnableMultiAudioStreamRecord(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Multi Audio Stream Record Enabled
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_IsMultiAudioStreamRecordEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsMultiAudioStreamRecordEnabled(bEnable);
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
          return _addon.EnableAddTimestampWatermark(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Add Time stamp Water mark Enabled
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_IsAddTimestampWatermarkEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsAddTimestampWatermarkEnabled(bEnable);
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
          return _addon.EnableOptimizeFor3rdPartyVideoEditor(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Optimize For 3rd Party Video Editor Enabled
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_IsOptimizeFor3rdPartyVideoEditorEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsOptimizeFor3rdPartyVideoEditorEnabled(bEnable);
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
          return _addon.EnableShowVideoThumbnailWhenShare(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Show Video Thumbnail When Share Enabled
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_IsShowVideoThumbnailWhenShareEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsShowVideoThumbnailWhenShareEnabled(bEnable);
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
          return _addon.EnablePlaceVideoNextToShareInRecord(bEnable);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** Is Place Video Next To Share In Record Enabled
      * @param {Boolean} bEnable
      * @return {ZoomSDKError}
      */
      Setting_IsPlaceVideoNextToShareInRecordEnabled: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bEnable = clientOpts.bEnable;
          return _addon.IsPlaceVideoNextToShareInRecordEnabled(bEnable);
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