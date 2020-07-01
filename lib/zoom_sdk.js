const { ZoomSDK_LANGUAGE_ID, ZoomSDKError } = require('./settings.js');
const ZOOMAUTHMOD = require('./zoom_auth.js');
const ZOOMMEETINGMOD = require('./zoom_meeting.js');
const ZOOMSETTINGMOD = require('./zoom_setting.js');
const ZOOMRESOURCE = require('./zoom_customized_resource.js');
const ZOOMPREMEETING = require('./zoom_premeeting.js');
const ZOOMVIDEORAWDATA = require('./zoom_video_rawdata.js');
const ZOOMAUDIORAWDATA = require('./zoom_audio_rawdata.js');
const ZOOMSHARERAWDATA = require('./zoom_share_rawdata.js');
const ZOOMSMS = require('./zoom_sms_helper.js');
const os = require('os');
const platform = os.platform();
const arch = os.arch();

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
    let addon = requireFunc(zoomnodepath)();
    let _isSDKInitialized = false;

    return {
      // Public methods and variables
      /**
       * mode: Zoom SDK Init
       * @param {String} path sdk.dll path on win os, todo: mac os.
       * @param {String} domain
       * @param {String} langname
       * @param {String} langinfo
       * @param {String} strSupportUrl
       * @param {String} langid ZoomSDK_LANGUAGE_ID,
       * @param {Boolean} enable_log
       * @param {Number} locale see ZoomAPPLocale in setings.js
       * @param {Number} logfilesize Size of a log file in M(megabyte). The default size is 5M. There are 5 log files in total and the file size varies from 1M to 50M. 
       * @param {Boolean} enableGenerateDump
       * @return {ZoomSDKError}
       */
      InitSDK: function (opts) {
        let clientOpts = opts || {};
        let path = clientOpts.path || '';
        let domain = clientOpts.domain || 'https://www.zoom.us'; 
        let langname = clientOpts.langname || '';
        let langinfo = clientOpts.langinfo || '';
        let strSupportUrl = clientOpts.strSupportUrl || 'https://zoom.us';
        let langid = clientOpts.langid || ZoomSDK_LANGUAGE_ID.LANGUAGE_Unknow;
        let enable_log = clientOpts.enable_log;
        let locale = Number(clientOpts.locale);
        let logfilesize = Number(clientOpts.logfilesize);
        let enableGenerateDump = clientOpts.enableGenerateDump || false;
        let ret = addon.InitSDK(path, domain, langname, langinfo, strSupportUrl, langid, enable_log, locale, logfilesize, enableGenerateDump);
        console.log('InitSDK', ret)
        if (ZoomSDKError.SDKERR_SUCCESS == ret){
          _isSDKInitialized = true;
        } else {
          _isSDKInitialized = false;
        }  
        return ret
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
      VideoRawData: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMVIDEORAWDATA.ZoomVideoRawData.getInstance(clientOpts);
        }
        return null;
      },
      AudioRawData: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMAUDIORAWDATA.ZoomAudioRawData.getInstance(clientOpts);
        }
        return null;
      },
      ShareRawData: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZOOMSHARERAWDATA.ZoomShareRawData.getInstance(clientOpts);
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
      },
      HasRawDataLicense: () => {
        if (_isSDKInitialized) {
          return addon.GetRawDataLicenseObj().HasRawDataLicense();
        }
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
