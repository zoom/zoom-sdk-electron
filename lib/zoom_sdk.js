const { ZoomSDK_LANGUAGE_ID, ZoomSDKError, ZNCustomizedLanguageType, ZoomAPPLocale, ZoomSDKVideoRenderMode, SDKRawDataMemoryMode
  ,ZoomSDKVideoCaptureMethod, ZoomSDKRenderPostProcessing } = require('./settings.js');
const ZOOMAUTHMOD = require('./zoom_auth.js');
const ZOOMMEETINGMOD = require('./zoom_meeting.js');
const ZOOMSETTINGMOD = require('./zoom_setting.js');
const ZOOMRESOURCE = require('./zoom_customized_resource.js');
const ZOOMPREMEETING = require('./zoom_premeeting.js');
const ZOOMRAWDATA = require('./zoom_rawdata.js');
const ZOOMSMS = require('./zoom_sms_helper.js');
const os = require('os');
const platform = os.platform();
const arch = os.arch();
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
const ZoomSDK = (() => {
  let instance;
  /**
   * mode: Zoom SDK JS Module Loader  
   * @param {Function} apicallretcb api call ret callback
   * @param {Boolean} threadsafemode
   * @param {String} path zoom.node path on win os, todo: mac os
   * @return {ZoomSDK}
   */
  function init(opts) {
    // Private methods and variables
    let clientOpts = opts || {};
    let _path = clientOpts.path || (platform == 'darwin' ? './../sdk/mac/' : arch == 'x64' ? './../sdk/win64/' : './../sdk/win32/');
    let zoomnodepath = _path + 'zoomsdk.node';
    let requireFunc = typeof __webpack_require__ === 'function' ? __non_webpack_require__ : require;
    let addon = requireFunc(zoomnodepath).exports();
    let _isSDKInitialized = false;

    return {
      // Public methods and variables
      /**
      * mode: Set Team Identifier
      * @param {String} identifier
      * @return {ZoomSDKError}
      */
      SetTeamIdentifier: function (opts) {
        if (addon) {
          let clientOpts = opts || {};
          let identifier = clientOpts.identifier;
          if (!identifier) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let SetTeamIdentifierParams = new messages.SetTeamIdentifierParams();
            SetTeamIdentifierParams.setIdentifier(identifier);
            let bytes = SetTeamIdentifierParams.serializeBinary();
            return addon.SetTeamIdentifier(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Zoom SDK Init
       * @param {String} path [Required] sdk.dll path on win os, todo: mac os.
       * @param {String} domain [Required]
       * @param {String} langname [Optional]
       * @param {String} langinfo [Optional]
       * @param {Number} langtype [Optional] ZNCustomizedLanguageType
       * @param {String} strSupportUrl [Optional]
       * @param {Number} langid [Optional] ZoomSDK_LANGUAGE_ID,
       * @param {Boolean} enable_log [Optional]
       * @param {Number} locale [Optional] see ZoomAPPLocale in setings.js
       * @param {Number} logfilesize [Optional] Size of a log file in M(megabyte). The default size is 5M. There are 5 log files in total and the file size varies from 1M to 50M. 
       * @param {Boolean} enableGenerateDump [Optional]
       * @param {Boolean} permonitorAwarenessMode [Optional]
       * @param {Number} videoRenderMode [Optional]
       * @param {Number} videoRawdataMemoryMode [Optional]
       * @param {Number} shareRawdataMemoryMode [Optional]
       * @param {Number} audioRawdataMemoryMode [Optional]
       * @param {Boolean} enableRawdataIntermediateMode [Optional]
       * @param {Number} renderPostProcessing [Optional]
       * @param {Number} videoCaptureMethod [Optional]
       * @return {ZoomSDKError}
       */
      InitSDK: function (opts) {
        let clientOpts = opts || {};
        let path = clientOpts.path || '';
        let domain = clientOpts.domain || 'https://www.zoom.us'; 
        let langname = clientOpts.langname || '';
        let langinfo = clientOpts.langinfo || '';
        let langtype = Number(clientOpts.langtype) || ZNCustomizedLanguageType.ZN_CustomizedLanguage_None;
        let strSupportUrl = clientOpts.strSupportUrl || 'https://zoom.us';
        let langid = clientOpts.langid || ZoomSDK_LANGUAGE_ID.LANGUAGE_Unknow;
        let enable_log = clientOpts.enable_log || true;
        let locale = Number(clientOpts.locale) || ZoomAPPLocale.ZNSDK_APP_Locale_Default;
        let logfilesize = Number(clientOpts.logfilesize) || 5;
        let enableGenerateDump = clientOpts.enableGenerateDump || false;
        let permonitorAwarenessMode = clientOpts.permonitorAwarenessMode || true;
        let videoRenderMode = clientOpts.videoRenderMode || ZoomSDKVideoRenderMode.SDKVideoRenderMode_None;
        let videoRawdataMemoryMode = clientOpts.videoRawdataMemoryMode || SDKRawDataMemoryMode.SDKRawDataMemoryModeStack;
        let shareRawdataMemoryMode = clientOpts.shareRawdataMemoryMode || SDKRawDataMemoryMode.SDKRawDataMemoryModeStack;
        let audioRawdataMemoryMode = clientOpts.audioRawdataMemoryMode || SDKRawDataMemoryMode.SDKRawDataMemoryModeStack;
        let enableRawdataIntermediateMode = clientOpts.enableRawdataIntermediateMode || platform == 'darwin' ? false : true;
        let renderPostProcessing = clientOpts.renderPostProcessing || ZoomSDKVideoCaptureMethod.ZoomSDKVideoCaptureMethod_Auto;
        let videoCaptureMethod = clientOpts.videoCaptureMethod || ZoomSDKRenderPostProcessing.ZoomSDKRenderPostProcessing_Auto;
        try {
          let InitSDKParams = new messages.InitSDKParams();
          InitSDKParams.setPath(path);
          InitSDKParams.setDomain(domain);
          InitSDKParams.setCustomizedlanguagename(langname);
          InitSDKParams.setCustomizedlanguageinfo(langinfo);
          InitSDKParams.setCustomizedlanguagetype(langtype);
          InitSDKParams.setStrsupporturl(strSupportUrl);
          InitSDKParams.setLangid(langid);
          InitSDKParams.setEnablelog(enable_log);
          InitSDKParams.setApplocale(locale);
          InitSDKParams.setLogfilesize(logfilesize);
          InitSDKParams.setEnablegeneraldump(enableGenerateDump);
          InitSDKParams.setPermonitorawarenessmode(permonitorAwarenessMode);
          InitSDKParams.setVideorendermode(videoRenderMode);
          InitSDKParams.setVideorawdatamemorymode(videoRawdataMemoryMode);
          InitSDKParams.setSharerawdatamemorymode(shareRawdataMemoryMode);
          InitSDKParams.setAudiorawdatamemorymode(audioRawdataMemoryMode);
          InitSDKParams.setEnablerawdataintermediatemode(enableRawdataIntermediateMode);
          InitSDKParams.setRenderpostprocessing(renderPostProcessing);
          InitSDKParams.setVideocapturemethod(videoCaptureMethod);
          let bytes = InitSDKParams.serializeBinary();
          let ret = addon.InitSDK(bytes);
          if (ZoomSDKError.SDKERR_SUCCESS == ret){
            _isSDKInitialized = true;
          } else {
            _isSDKInitialized = false;
          }  
          return ret
        } catch (error) {
          return ZoomSDKError.SDKERR_INVALID_PARAMETER;
        }
      },
      /**
      * mode: Get the version of ZOOM SDK
      * @return {String} The version of ZOOM SDK
      */ 
      GetZoomSDKVersion: () => {
        return addon.GetZoomSDKVersion();
      },
      /**
       * mode: Zoom SDK Cleanup
       * @return {ZoomSDKError}
       */
      CleanUPSDK: function () {
        return addon.CleanUPSDK();
      },
      GetAuth: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMAUTHMOD.ZoomAuth.getInstance(clientOpts);
        }
        return null;
      },
      GetMeeting: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMMEETINGMOD.ZoomMeeting.getInstance(clientOpts);
        }
        return null;
      },
      GetSetting: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMSETTINGMOD.ZoomSetting.getInstance(clientOpts);
        }
        return null;
      },
      GetCustomizedResource: (opts) => {
        let clientOpts = opts || {};
        clientOpts.addon = addon;
        return ZOOMRESOURCE.ZoomCustomizedResource.getInstance(clientOpts);
      },
      PreMeeting: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMPREMEETING.ZoomPreMeeting.getInstance(clientOpts);
        }
        return null;
      },
      RawData: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMRAWDATA.ZoomRawData.getInstance(clientOpts);
        }
        return null;
      },
      SMSHelper: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMSMS.ZoomSMSHelper.getInstance(clientOpts);
        }
        return null;
      }
    };
  };
  
  return {
    /**
     * Get Zoom SDK Module
     * @return {ZoomSDK}
    */
    getInstance: (opts) => {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomSDK: ZoomSDK
}
