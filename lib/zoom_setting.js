const ZOOMSDKMOD_GeneralSetting = require('./zoom_setting_general.js');
const ZOOMSDKMOD_RecordingSetting = require('./zoom_setting_recording.js')
const ZOOMSDKMOD_VideoSetting = require('./zoom_setting_video.js');
const ZOOMSDKMOD_AudioSetting = require('./zoom_setting_audio.js');
const ZoomSettingUIMOD = require('./zoom_setting_ui_ctrl.js');
const ZoomSettingStatisticMOD = require('./zoom_setting_statistic_ctrl.js');
const ZoomSettingAccessibilityMOD = require('./zoom_setting_accessibility_ctrl.js');

let ZoomGeneralSetting;
let ZoomVideoSetting;
let ZoomAudioSetting;
let ZoomRecordingSetting;
let ZoomSettingUICtrl;
let ZoomSettingStatisticCtrl;
let ZoomSettingAccessibilityCtrl;

/**
*@module
*/
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
      GetGeneralSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomGeneralSetting) {
            ZoomGeneralSetting = ZOOMSDKMOD_GeneralSetting.ZoomGeneralSetting.getInstance(clientOpts);
          }
          return ZoomGeneralSetting;
        }
        return null;
      },
      GetVideoSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {}
          clientOpts.addon = _addon
          if (!ZoomVideoSetting) {
            ZoomVideoSetting = ZOOMSDKMOD_VideoSetting.ZoomVideoSetting.getInstance(clientOpts);
          }
          return ZoomVideoSetting;
        }
        return null;
      },
      GetAudioSetting : function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomAudioSetting) {
            ZoomAudioSetting = ZOOMSDKMOD_AudioSetting.ZoomAudioSetting.getInstance(clientOpts);
          }
          return ZoomAudioSetting;
        }
        return null;
      },
      GetRecordingSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomRecordingSetting) {
            ZoomRecordingSetting = ZOOMSDKMOD_RecordingSetting.ZoomRecordingSetting.getInstance(clientOpts);
          }
          return ZoomRecordingSetting;
        }
        return null;
      },
      GetSettingUICtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomSettingUICtrl) {
            ZoomSettingUICtrl = ZoomSettingUIMOD.ZoomSettingUICtrl.getInstance(clientOpts);
          }
          return ZoomSettingUICtrl;
        }
        return null;
      },
      GetSettingStatisticCtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomSettingStatisticCtrl) {
            ZoomSettingStatisticCtrl = ZoomSettingStatisticMOD.ZoomSettingStatisticCtrl.getInstance(clientOpts);
          }
          return ZoomSettingStatisticCtrl;
        }
        return null;
      },
      GetSettingAccessibilityCtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomSettingAccessibilityCtrl) {
            ZoomSettingAccessibilityCtrl = ZoomSettingAccessibilityMOD.ZoomSettingAccessibilityCtrl.getInstance(clientOpts);
          }
          return ZoomSettingAccessibilityCtrl;
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