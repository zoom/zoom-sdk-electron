const ZOOMSDKMOD_GeneralSetting = require('./zoom_setting_general.js');
const ZOOMSDKMOD_RecordingSetting = require('./zoom_setting_recording.js')
const ZOOMSDKMOD_VideoSetting = require('./zoom_setting_video.js');
const ZOOMSDKMOD_AudioSetting = require('./zoom_setting_audio.js');
const ZoomSettingUIMOD = require('./zoom_setting_ui_ctrl.js');
 
var ZoomSetting = (function () {
  var instance;
   /**
   * mode: Zoom SDK Settings Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomSetting}
   */
  function init(opts) { 
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetSetObj() || null
    return {
      /** mode: Show The Setting Dlg
      * @param {String} hParent parent setting handle (require hexadecimal)
      * @param {String} left setting dlg left pos
      * @param {String} top setting dlg top pos
      * @param {String} hSettingWnd Setting Wnd (require hexadecimal)
      * @param {Boolean} bShow show or not 
      * @return {ZoomSDKError}
      */
      SettingUI_ShowTheSettingDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {}
          clientOpts.addon = _addon
          let hParent = clientOpts.hParent || '0'
          let top = clientOpts.top || '0'
          let left = clientOpts.left || '0'
          let hSettingWnd = clientOpts.hSettingWnd || '0'
          let bShow = clientOpts.bShow || true
          return _addon.ShowSettingDlg(hParent, top, left, hSettingWnd, bShow);
        }
        return ZOOMSDKMOD_4Setting.ZoomSDKError.SDKERR_UNINITIALIZE
      },
      /** mode: Hide Setting Dlg
      */
      SettingUI_HideSettingDlg: function () {
        if (_addon) {
          return _addon.HideSettingDlg();
        }
        return ZOOMSDKMOD_4Setting.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get General Setting Module
      */
      GetGeneralSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZOOMSDKMOD_GeneralSetting.ZoomGeneralSetting.getInstance(clientOpts);
        }
        return null;
      },
      /**
      * mode: Get Zoom SDK Video Setting Module
      */
      GetVideoSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {}
          clientOpts.addon = _addon
          return ZOOMSDKMOD_VideoSetting.ZoomVideoSetting.getInstance(clientOpts)
        }
        return null;
      },
      /**
      * mode: Get Zoom SDK Audio Setting Module
      */
      GetAudioSetting : function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZOOMSDKMOD_AudioSetting.ZoomAudioSetting.getInstance(clientOpts);
        }
        return null;
      },
      /**
      * mode: Get Recording Setting
      */
      GetRecordingSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZOOMSDKMOD_RecordingSetting.ZoomRecordingSetting.getInstance(clientOpts);
        }
        return null;
      },
      /**
      * mode: Get Setting UI Ctrl
      */
      GetSettingUICtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZoomSettingUIMOD.ZoomSettingUICtrl.getInstance(clientOpts);
        }
        return null;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK Setting Service Module
     * @return {ZoomSetting}
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
  ZoomSetting: ZoomSetting
}