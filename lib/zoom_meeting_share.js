let { ZoomSDKError } = require('./settings.js');
let messages = require('./electron_sdk_pb.js');

/**
*@module
*/
var ZoomMeetingShare = (function () {
  var instance;
   /**
   * mode: Zoom SDK Meeting share module Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingShare}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingShareCtrl() || null;
    let _onSharingStatus = clientOpts.onSharingStatus || null;

    function onSharingStatus(status, userId) {
      if (_onSharingStatus) {
        _onSharingStatus(status, userId)
      }
    }

    if (_addon) {
      _addon.SetOnSharingStatusCB(onSharingStatus);
    }

    return {
      // Public methods and variables
      /**
      * mode: Set On Sharing Status CB
      * @param {Function} onSharingStatus
      * @return {Boolean}
      */
      SetOnSharingStatusCB: function (onSharingStatus) {
        if (_addon && onSharingStatus && onSharingStatus instanceof Function) {
          _onSharingStatus = onSharingStatus;
          return true;
        }
        return false;
      },
      /** 
      * mode: Start app share
      * @param {String} zn_hShare_app Specifies which the window is to be shared (require hexadecimal)
      * @return {ZoomSDKError}
      */
      MeetingShare_StartAppShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_hShare_app = clientOpts.zn_hShare_app;
          try {
            let StartAppShareParams = new messages.StartAppShareParams();
            StartAppShareParams.setHshareapp(zn_hShare_app);
            let bytes = StartAppShareParams.serializeBinary();
            return _addon.StartAppShare(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: start desktopshare 
      * @param {String} zn_monitorID Specifies which the monitor is to be shared.Using EnumDisplayMonitors System api to get this value.
      * @return {ZoomSDKError}
      */
      MeetingShare_StartMonitorShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let zn_monitorID = clientOpts.zn_monitorID;
          try {
            let StartMonitorShareParams = new messages.StartMonitorShareParams();
            StartMonitorShareParams.setMonitorid(zn_monitorID);
            let bytes = StartMonitorShareParams.serializeBinary();
            return _addon.StartMonitorShare(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode:  stop share 
      * @return {ZoomSDKError}
      */
      MeetingShare_StopShare: function () {
        if (_addon) {
          return _addon.StopShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Audio Module
     * @return {ZoomMeetingShare}
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
  ZoomMeetingShare: ZoomMeetingShare,
}