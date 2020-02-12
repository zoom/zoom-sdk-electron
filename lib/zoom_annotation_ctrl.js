const { ZoomAnnotationToolType, ZoomAnnotationClearType, ZoomMeetingUIViewType, ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomAnnotationCtrl = (function () {
  var instance;
   /**
   * mode: Zoom SDK Annotation Controller Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomAnnotationCtrl}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingAnnotation() || null;
    return {
      // Public methods and variables
      /** mode: Check if Annotation is disable.
       * @return {Boolean}
       */
      Annotaion_IsAnnotaionDisable: function () {
        if (_addon){
          return _addon.IsAnnoataionDisable();
        }
        return false;
      },
      /** mode: Start annotation
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @param {String} left Float Video left pos
      * @param {String} top Float Video pos
      * @return {ZoomSDKError}
      */
      Annotaion_StartAnnotation: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let left = clientOpts.left;
          let top = clientOpts.top;
          return _addon.StartAnnotation(viewtype, left, top);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Stop annotation.
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @return {ZoomSDKError}
      */
      Annotaion_StopAnnotation: function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          return _addon.StopAnnotation(viewtype);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Stop annotation.
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @param {String} toolType the tool type of annotation, define at ZoomAnnotationToolType
      * @return {ZoomSDKError}
      */
      Annotaion_SetTool: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let toolType = clientOpts.toolType || ZoomAnnotationToolType.ANNOTOOL_NONE_DRAWING;
          return _addon.SetTool(viewtype, toolType);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Clear annotation.
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @param {String} clearType the clear type of annotation, define at ZoomAnnotationClearType
      * @return {ZoomSDKError}
      */
      Annotaion_Clear: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let clearType = clientOpts.clearType || ZoomAnnotationClearType.ANNOCLEAR_ALL;
          return _addon.Clear(viewtype, clearType);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Set annotation color
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @param {String} color the color of annotation
      * @return {ZoomSDKError}
      */
      Annotaion_SetColor: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let color = clientOpts.color;
          return _addon.SetColor(viewtype, color);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Set line width of annotation.
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @param {String} lineWidth the line width of annotation
      * @return {ZoomSDKError}
      */
      Annotaion_SetLineWidth: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          let lineWidth = clientOpts.lineWidth;
          return _addon.SetLineWidth(viewtype, lineWidth);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Undo annotation.
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @return {ZoomSDKError}
      */
      Annotaion_Undo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          return _addon.Undo(viewtype);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** mode: Redo annotation.
      * @param {String} viewtype the view type of which monitor, define at ZoomMeetingUIViewType
      * @return {ZoomSDKError}
      */
      Annotaion_Redo : function (opts) {
        if (_addon){
          let clientOpts = opts || {};
          let viewtype = clientOpts.viewtype || ZoomMeetingUIViewType.MEETINGUI_FIRST_MONITOR;
          return _addon.Redo(viewtype);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Annotation Service Module
     * @return {ZoomAnnotationCtrl}
    */
    getInstance: function (opts) {
      if(!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomAnnotationCtrl: ZoomAnnotationCtrl
}