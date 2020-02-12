
const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomAudioRawData = (function () {
  let instance;
   /**
   * mode: Zoom SDK Video Raw Data Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomAudioRawData}
   */
  function init(opts) {
 
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetAudioRawDataObj() || null;
    let _onMixedAudioRawDataReceived = clientOpts.onMixedAudioRawDataReceived || null;
    let _onOneWayAudioRawDataReceived = clientOpts.onOneWayAudioRawDataReceived || null;

    function onMixedAudioRawDataReceived(databuf, data_format) {
      if (_onMixedAudioRawDataReceived) {
        _onMixedAudioRawDataReceived(databuf, data_format)
      }
    }

    function onOneWayAudioRawDataReceived(databuf, data_format, nodeid) {
      if (_onOneWayAudioRawDataReceived) {
        _onOneWayAudioRawDataReceived(databuf, data_format, nodeid)
      }
    }

    if (_addon) {
      _addon.SetRawDataCB(onMixedAudioRawDataReceived, onOneWayAudioRawDataReceived);
    }

    return {
      /** mode: Set Mixed Audio Raw Data CB
       * @param {Function} onMixedAudioRawDataReceived
       * @return {Boolean}
       */
      SetMixedAudioRawDataCB: function(onMixedAudioRawDataReceived) {
        if (_addon && onMixedAudioRawDataReceived && onMixedAudioRawDataReceived instanceof Function) {
          _onMixedAudioRawDataReceived = onMixedAudioRawDataReceived;
          return true;
        }
        return false;
      },
      /** mode: Set One Way Audio Raw Data CB
       * @param {Function} onOneWayAudioRawDataReceived
       * @return {Boolean}
       */
      SetOneWayAudioRawDataCB: function(onOneWayAudioRawDataReceived) {
        if (_addon && onOneWayAudioRawDataReceived && onOneWayAudioRawDataReceived instanceof Function) {
          _onOneWayAudioRawDataReceived = onOneWayAudioRawDataReceived;
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
      /** mode: Stop
      * @return {ZoomSDKError}
      */
      Stop: function () {
        if (_addon) {
          return _addon.Stop();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
};
  return {
    /**
     * mode: Get Zoom SDK Video Raw Data Module
     * @return {ZoomAudioRawData}
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
  ZoomAudioRawData: ZoomAudioRawData
}