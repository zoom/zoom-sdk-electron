/**
*@module
*/
var ZoomMeetingRecording = (function () {
  var instance;
  /**
  * Zoom SDK Meeting Recording module Init
  * @param {Object} addon zoom sdk module
  * @param {Function} onRecording2MP4Done on Recording 2 MP4 Done callback
  * @param {Function} onRecording2MP4Processing on Recording 2 MP4 Processing callback
  * @param {Function} onRecordingStatus local recording status change callback, enum see in settings.js ZNRecordingStatus
  * @param {Function} onCloudRecordingStatus cloud recording status change callback, enum see in settings.js ZNRecordingStatus
  * @param {Function} onRecordPriviligeChanged on Record Privilige Changed callback
  * @param {Function} onRecordPriviligeChanged on Customized Local Recording Source Notification callback
  * @return {ZoomMeetingRecording}
  */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingRecordingCtrl() || null;
    let _onRecording2MP4Done = clientOpts.onRecording2MP4Done || null;
    let _onRecording2MP4Processing = clientOpts.onRecording2MP4Processing || null;
    let _onRecordingStatus = clientOpts.onRecordingStatus || null;
    let _onCloudRecordingStatus = clientOpts.onCloudRecordingStatus || null;
    let _onRecordPriviligeChanged = clientOpts.onRecordPriviligeChanged || null;
    let _onCustomizedLocalRecordingSourceNotification = clientOpts.onCustomizedLocalRecordingSourceNotification || null;

    function onRecording2MP4Done(success, result, path) {
      if (_onRecording2MP4Done) {
        _onRecording2MP4Done(success, result, path)
      }
    }

    function onRecording2MP4Processing(percentage) {
      if (_onRecording2MP4Processing) {
        _onRecording2MP4Processing(percentage)
      }
    }

    function onRecordingStatus(status) {
      if (_onRecordingStatus) {
        _onRecordingStatus(status)
      }
    }

    function onCloudRecordingStatus(status) {
      if (_onCloudRecordingStatus) {
        _onCloudRecordingStatus(status)
      }
    }

    function onRecordPriviligeChanged(canRec) {
      if (_onRecordPriviligeChanged) {
        _onRecordPriviligeChanged(canRec)
      }
    }

    function onCustomizedLocalRecordingSourceNotification(result) {
      if (_onCustomizedLocalRecordingSourceNotification) {
        _onCustomizedLocalRecordingSourceNotification(result)
      }
    }

    if (_addon) {
      _addon.SetonRecording2MP4DoneCB(onRecording2MP4Done);
      _addon.SetonRecording2MP4ProcessingCB(onRecording2MP4Processing);
      _addon.SetonRecordingStatusCB(onRecordingStatus);
      _addon.SetonCloudRecordingStatusCB(onCloudRecordingStatus);
      _addon.SetonRecordPriviligeChangedCB(onRecordPriviligeChanged);
      _addon.SetonCustomizedLocalRecordingSourceNotificationCB(onCustomizedLocalRecordingSourceNotification);
    }

    return {
      /** 
       * mode: Set on Recording 2MP4 Done CB
       * @param {Function} onRecording2MP4Done
       * @return {Boolean}
       */
      SetonRecording2MP4DoneCB: function (onRecording2MP4Done) {
        if (_addon && onRecording2MP4Done && onRecording2MP4Done instanceof Function) {
          _onRecording2MP4Done = onRecording2MP4Done;
          return true;
        }
        return false
      },
      /** 
       * mode: Set on Recording 2MP4 Processing CB
       * @param {Function} onRecording2MP4Processing
       * @return {Boolean}
       */
      SetonRecording2MP4ProcessingCB: function (onRecording2MP4Processing) {
        if (_addon && onRecording2MP4Processing && onRecording2MP4Processing instanceof Function) {
          _onRecording2MP4Processing = onRecording2MP4Processing;
          return true;
        }
        return false;
      },
      /** 
       * mode: Set on Recording Status CB
       * @param {Function} onRecordingStatus
       * @return {Boolean}
       */
      SetonRecordingStatusCB: function (onRecordingStatus) {
        if (_addon && onRecordingStatus && onRecordingStatus instanceof Function) {
          _onRecordingStatus = onRecordingStatus;
          return true;
        }
        return false;
      },
      /** 
       * mode: Set on Cloud Recording Status CB
       * @param {Function} onCloudRecordingStatus
       * @return {Boolean}
       */
      SetonCloudRecordingStatusCB: function (onCloudRecordingStatus) {
        if (_addon && onCloudRecordingStatus && onCloudRecordingStatus instanceof Function) {
          _onCloudRecordingStatus = onCloudRecordingStatus;
          return true;
        }
        return false;
      },
      /** 
       * mode: Set on Record Privilige Changed CB
       * @param {Function} onRecordPriviligeChanged
       * @return {Boolean}
       */
      SetonRecordPriviligeChangedCB: function (onRecordPriviligeChanged) {
        if (_addon && onRecordPriviligeChanged && onRecordPriviligeChanged instanceof Function) {
          _onRecordPriviligeChanged = onRecordPriviligeChanged;
          return true;
        }
        return false;
      },
      /** 
       * mode: Set on Customized Local Recording Source Notification CB
       * @param {Function} onCustomizedLocalRecordingSourceNotification
       * @return {Boolean}
       */
      SetonCustomizedLocalRecordingSourceNotificationCB: function (onCustomizedLocalRecordingSourceNotification) {
        if (_addon && onCustomizedLocalRecordingSourceNotification && onCustomizedLocalRecordingSourceNotification instanceof Function) {
          _onCustomizedLocalRecordingSourceNotification = onCustomizedLocalRecordingSourceNotification;
          return true;
        }
        return false;
      },
      /** 
       * mode: Start Recording
       * @param {String} recPath
       * @return {ZoomSDKError}
       */
      StartRecording: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recPath = clientOpts.recPath;
          return _addon.StartRecording(recPath);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Stop Recording
       * @return {ZoomSDKError}
       */
      StopRecording: function () {
        if (_addon) {
          return _addon.StopRecording();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Can Start Recording
       * @param {Boolean} cloud_recording
       * @return {ZoomSDKError}
       */
      CanStartRecording: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let cloud_recording = clientOpts.cloud_recording;
          return _addon.CanStartRecording(cloud_recording);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Can Allow Dis Allow Local Recording
      * @return {MeetingType}
      */
      CanAllowDisAllowLocalRecording: function () {
        if (_addon) {
          return _addon.CanAllowDisAllowLocalRecording();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Start Cloud Recording
       * @return {ZoomSDKError}
       */
      StartCloudRecording: function () {
        if (_addon) {
          return _addon.StartCloudRecording();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Stop Cloud Recording
       * @return {ZoomSDKError}
       */
      StopCloudRecording: function () {
        if (_addon) {
          return _addon.StopCloudRecording();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Is Support Local Recording
       * @param {Number} userid
       * @return {ZoomSDKError}
       */
      IsSupportLocalRecording: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          return _addon.IsSupportLocalRecording(Number(userid));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Allow Local Recording
       * @param {Number} userid
       * @return {ZoomSDKError}
       */
      AllowLocalRecording: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          return _addon.AllowLocalRecording(Number(userid));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
       * mode: Dis Allow Local Recording
       * @param {Number} userid
       * @return {ZoomSDKError}
       */
      DisAllowLocalRecording: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          return _addon.DisAllowLocalRecording(Number(userid));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Request Customized Local Recording Source
      * @return {Boolean}
      */
      RequestCustomizedLocalRecordingSource: function () {
        if (_addon) {
          return _addon.RequestCustomizedLocalRecordingSource();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };

  return {
    /**
     * mode: Get Meeting Recording Module
     * @return {ZoomMeetingRecording}
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
  ZoomMeetingRecording: ZoomMeetingRecording
}