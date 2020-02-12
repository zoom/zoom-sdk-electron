/*
 * @Description: In User Settings Edit
 * @Author: your name
 * @Date: 2019-08-09 18:14:09
 * @LastEditTime: 2019-08-13 16:42:29
 * @LastEditors: Please set LastEditors
 */
const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomVideoRawData = (function () {
  let instance;
   /**
   * mode: Zoom SDK Video Raw Data Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomVideoRawData}
   */
  function init(opts) {
    
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetVideoRawDataObj() || null;
    let _onVideoRawDataReceived = clientOpts.onVideoRawDataReceived || null;

    function onVideoRawDataReceived(databuf, format, receivers) {
      if (_onVideoRawDataReceived) {
        _onVideoRawDataReceived(databuf, format, receivers)
      }
    }

    if (_addon) {
      _addon.SetRawDataCB(onVideoRawDataReceived);
    }

    return {
      /** mode: Set Raw Data CB
      * @return {Boolean}
      */
      SetRawDataCB: function(onVideoRawDataReceived) {
        if (_addon && onVideoRawDataReceived && onVideoRawDataReceived instanceof Function) {
          _onVideoRawDataReceived = onVideoRawDataReceived;
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
      /** mode: SetRawDataVideoUserDataOnCB
      * @param {Function} onSubscribedVideoUserDataOn
      * @return {ZoomSDKError}
      */
      SetRawDataVideoUserDataOnCB: function (onSubscribedVideoUserDataOn) {
        if (_addon) {
          return _addon.SetRawDataVideoUserDataOnCB(onSubscribedVideoUserDataOn);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: SetRawDataVideoUserDataOffCB
      * @param {Function} onSubscribedVideoUserDataOff
      * @return {ZoomSDKError}
      */
      SetRawDataVideoUserDataOffCB: function (onSubscribedVideoUserDataOff) {
        if (_addon) {
          return _addon.SetRawDataVideoUserDataOffCB(onSubscribedVideoUserDataOff);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: SetRawDataVideoUserLeftCB
      * @param {Function} onSubscribedVideoUserLeft
      * @return {ZoomSDKError}
      */
      SetRawDataVideoUserLeftCB: function (onSubscribedVideoUserLeft) {
        if (_addon) {
          return _addon.SetRawDataVideoUserLeftCB(onSubscribedVideoUserLeft);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
};
  return {
    /**
     * mode: Get Zoom SDK Video Raw Data Module
     * @return {ZoomVideoRawData}
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
  ZoomVideoRawData: ZoomVideoRawData
}