
const { ZoomSDKError } = require('./settings.js');

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

    return {
      /** mode: Set Raw Data CB
      * @return {ZoomSDKError}
      */
      SetRawDataCB: function(onMixedAudioRawDataReceived, onOneWayAudioRawDataReceived) {
        if (_addon) {
          return _addon.SetRawDataCB(onMixedAudioRawDataReceived, onOneWayAudioRawDataReceived);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
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