
const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomShareRawData = (function () {
  let instance;
   /**
   * mode: Zoom SDK Video Raw Data Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomShareRawData}
   */
  function init(opts) {
 
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetShareRawDataObj() || null;
    let _onShareRawDataReceived = clientOpts.onShareRawDataReceived || null;

    function onShareRawDataReceived(databuf, format, receivers) {
      if (_onShareRawDataReceived) {
        _onShareRawDataReceived(databuf, format, receivers)
      }
    }

    if (_addon) {
      _addon.SetRawDataCB(onShareRawDataReceived);
    }

    return {
      /** mode: Set Raw Data CB
      * @return {Boolean}
      */
      SetRawDataCB: function(onShareRawDataReceived) {
        if (_addon && onShareRawDataReceived && onShareRawDataReceived instanceof Function) {
          _onShareRawDataReceived = onShareRawDataReceived;
          return true;
        }
        return false;
      },
      /** mode: Start
      * @param {Number} RawDataMemoryMode
      * @return {ZoomSDKError}
      */
      Start: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let RawDataMemoryMode = clientOpts.RawDataMemoryMode;
          return _addon.Start(Number(RawDataMemoryMode));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Subscribe
      * @param {Number} nodeID
      * @param {Number} RawDataResolution
      * @param {Number} recever_handle
      * @return {ZoomSDKError}
      */
      Subscribe: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let nodeID = clientOpts.nodeID;
          let RawDataResolution = clientOpts.RawDataResolution;
          let recever_handle = clientOpts.recever_handle;
          return _addon.Subscribe(Number(nodeID), Number(RawDataResolution), Number(recever_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: UnSubscribe
      * @param {Number} nodeID
      * @param {Number} recever_handle
      * @return {ZoomSDKError}
      */
      UnSubscribe: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let nodeID = clientOpts.nodeID;
          let recever_handle = clientOpts.recever_handle;
          return _addon.UnSubscribe(Number(nodeID), Number(recever_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Stop
      * @return {ZoomSDKError}
      */
      Stop: function () {
        if (_addon) {
          return _addon.Stop();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: SetRawDataShareUserDataOnCB
      * @param {Function} onSubscribedShareUserDataOn
      * @return {ZoomSDKError}
      */
      SetRawDataShareUserDataOnCB: function (onSubscribedShareUserDataOn) {
        if (_addon) {
          return _addon.SetRawDataShareUserDataOnCB(onSubscribedShareUserDataOn);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: SetRawDataShareUserDataOffCB
      * @param {Function} onSubscribedShareUserDataOff
      * @return {ZoomSDKError}
      */
      SetRawDataShareUserDataOffCB: function (onSubscribedShareUserDataOff) {
        if (_addon) {
          return _addon.SetRawDataShareUserDataOffCB(onSubscribedShareUserDataOff);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: SetRawDataShareUserLeftCB
      * @param {Function} onSubscribedShareUserLeft
      * @return {ZoomSDKError}
      */
      SetRawDataShareUserLeftCB: function (onSubscribedShareUserLeft) {
        if (_addon) {
          return _addon.SetRawDataShareUserLeftCB(onSubscribedShareUserLeft);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
};
  return {
    /**
     * mode: Get Zoom SDK Video Raw Data Module
     * @return {ZoomShareRawData}
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
  ZoomShareRawData: ZoomShareRawData
}