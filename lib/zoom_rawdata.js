const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

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
          try {
            let CreateRendererParams = new messages.CreateRendererParams();
            CreateRendererParams.setRecvhandle(Number(recv_handle));
            let bytes = CreateRendererParams.serializeBinary();
            return _addon.CreateRenderer(bytes);            
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let DestroyRendererParams = new messages.DestroyRendererParams();
            DestroyRendererParams.setRecvhandle(Number(recv_handle));
            let bytes = DestroyRendererParams.serializeBinary();
            return _addon.DestroyRenderer(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SubscribeParams = new messages.SubscribeParams();
            SubscribeParams.setUserid(Number(userid));
            SubscribeParams.setRawdatatype(Number(rawdataType));
            SubscribeParams.setRecvhandle(Number(recv_handle));
            let bytes = SubscribeParams.serializeBinary();
            return _addon.Subscribe(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let UnSubscribeParams = new messages.UnSubscribeParams();
            UnSubscribeParams.setRecvhandle(Number(recv_handle));
            let bytes = UnSubscribeParams.serializeBinary();
            return _addon.UnSubscribe(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetRawDataResolutionParams = new messages.SetRawDataResolutionParams();
            SetRawDataResolutionParams.setResolution(Number(resolution));
            SetRawDataResolutionParams.setRecvhandle(Number(recv_handle));
            let bytes = SetRawDataResolutionParams.serializeBinary();
            return _addon.SetRawDataResolution(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let GetResolutionParams = new messages.GetResolutionParams();
            GetResolutionParams.setRecvhandle(Number(recv_handle));
            let bytes = GetResolutionParams.serializeBinary();
            return _addon.GetResolution(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let GetRawDataTypeParams = new messages.GetRawDataTypeParams();
            GetRawDataTypeParams.setRecvhandle(Number(recv_handle));
            let bytes = GetRawDataTypeParams.serializeBinary();
            return _addon.GetRawDataType(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let GetUserIdParams = new messages.GetUserIdParams();
            GetUserIdParams.setRecvhandle(Number(recv_handle));
            let bytes = GetUserIdParams.serializeBinary();
            return _addon.GetUserId(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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