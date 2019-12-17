const { ZoomSDKError } = require('./settings.js');

var ZoomDirectShareHelper = (function () {
  var instance;
  /**
   * mode: Zoom SDK ZoomDirectShareHelper Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomDirectShareHelper}
   */
  function init(opts) { 
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetDirectShareHelperObj() || null;

    function OnDirectShareStatusUpdate(status) {
    }

    if (_addon) {
      _addon.SetDirectShareStatusUpdateCB(OnDirectShareStatusUpdate);
    }

    return {
      /**
      * mode: Can Start Direct Share
      * @return {ZoomSDKError}
      */
      CanStartDirectShare: function () {
        if (_addon) {
          return _addon.CanStartDirectShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Is Direct Share In Progress
      * @return {ZoomSDKError}
      */
      IsDirectShareInProgress: function () {
        if (_addon) {
          return _addon.IsDirectShareInProgress();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Start Direct Share
      * @return {ZoomSDKError}
      */
      StartDirectShare: function () {
        if (_addon) {
          return _addon.StartDirectShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Stop Direct Share
      * @return {ZoomSDKError}
      */
      StopDirectShare: function () {
        if (_addon) {
          return _addon.StopDirectShare();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Set Direct Share Status Update CB
      * @return {ZoomSDKError}
      */
      SetDirectShareStatusUpdateCB: function (OnDirectShareStatusUpdate) {
        if (_addon) {
          return _addon.SetDirectShareStatusUpdateCB(OnDirectShareStatusUpdate);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Try With Meeting Number
      * @param {Number} meetingNumber
      * @return {ZoomSDKError}
      */
      TryWithMeetingNumber: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingNumber = clientOpts.meetingNumber;
          return _addon.TryWithMeetingNumber(Number(meetingNumber));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Try With Pairing Code
      * @param {String} pairingCode
      * @return {ZoomSDKError}
      */
      TryWithPairingCode: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let pairingCode = clientOpts.pairingCode;
          return _addon.TryWithPairingCode(pairingCode);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Cancel
      * @return {ZoomSDKError}
      */
      Cancel: function () {
        if (_addon) {
          return _addon.Cancel();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK ZoomDirectShareHelper Service Module
     * @return {ZoomDirectShareHelper}
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
  ZoomDirectShareHelper: ZoomDirectShareHelper
}