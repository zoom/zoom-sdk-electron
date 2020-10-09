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
var ZoomRawData = (function () {
  let instance;
   /**
   * mode: Zoom SDK Video Raw Data Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomRawData}
   */
  function init(opts) {
    
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetRawdataAPIWrap() || null;
    let _onRawDataStatusChanged = clientOpts.onRawDataStatusChanged || null;

    function onRawDataStatusChanged(databuf, format, receivers) {
      if (_onRawDataStatusChanged) {
        _onRawDataStatusChanged(databuf, format, receivers)
      }
    }

    if (_addon) {
      _addon.SetonRawDataStatusChangedCB(onRawDataStatusChanged);
    }

    return {
      /** mode: SetonRawDataStatusChangedCB
      * @param {Function} onRawDataStatusChanged
      * @return {ZoomSDKError}
      */
      SetonRawDataStatusChangedCB: function (onRawDataStatusChanged) {
        if (_addon && onRawDataStatusChanged && onRawDataStatusChanged instanceof Function) {
          _onRawDataStatusChanged = onRawDataStatusChanged;
          return true;
        }
        return false;
      },
      /** mode: HasRawDataLicense
      * @return {Boolean}
      */
      HasRawDataLicense: function () {
        if (_addon) {
          return _addon.HasRawDataLicense();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: CreateRenderer
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      CreateRenderer: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recv_handle = clientOpts.recv_handle;
          return _addon.CreateRenderer(Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: DestroyRenderer
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      DestroyRenderer: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recv_handle = clientOpts.recv_handle;
          return _addon.DestroyRenderer(Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: Subscribe
      * @param {Number} userid
      * @param {Number} rawdataType
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      Subscribe: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid;
          let rawdataType = clientOpts.rawdataType;
          let recv_handle = clientOpts.recv_handle;
          return _addon.Subscribe(Number(userid), Number(rawdataType), Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: UnSubscribe
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      UnSubscribe: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recv_handle = clientOpts.recv_handle;
          return _addon.UnSubscribe(Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: SetRawDataResolution
      * @param {Number} resolution
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      SetRawDataResolution: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let resolution = clientOpts.resolution;
          let recv_handle = clientOpts.recv_handle;
          return _addon.SetRawDataResolution(Number(resolution), Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: SetRawDataResolution
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      GetResolution: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recv_handle = clientOpts.recv_handle;
          return _addon.GetResolution(Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: GetRawDataType
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      GetRawDataType: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recv_handle = clientOpts.recv_handle;
          return _addon.GetRawDataType(Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: GetUserId
      * @param {Number} recv_handle
      * @return {ZoomSDKError}
      */
      GetUserId: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let recv_handle = clientOpts.recv_handle;
          return _addon.GetUserId(Number(recv_handle));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: InitAudioRawDataHelper
      * @return {ZoomSDKError}
      */
      InitAudioRawDataHelper: function () {
        if (_addon) {
          return _addon.InitAudioRawDataHelper();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: SubscribeAudioRawdata
      * @return {ZoomSDKError}
      */
      SubscribeAudioRawdata: function () {
        if (_addon) {
          return _addon.SubscribeAudioRawdata();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: SubscribeAudioRawdata
      * @return {ZoomSDKError}
      */
      UnSubscribeAudioRawdata: function () {
        if (_addon) {
          return _addon.UnSubscribeAudioRawdata();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE
      }
    };
};
  return {
    /**
     * mode: Get Zoom SDK Video Raw Data Module
     * @return {ZoomRawData}
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
  ZoomRawData: ZoomRawData
}