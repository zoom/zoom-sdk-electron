const { ZoomAnnotationToolType, ZoomAnnotationClearType, ZoomMeetingUIViewType, ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

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
          try {
            let StartAnnotationParams = new messages.StartAnnotationParams();
            StartAnnotationParams.setViewtype(viewtype);
            StartAnnotationParams.setLeft(left);
            StartAnnotationParams.setTop(top);
            let bytes = StartAnnotationParams.serializeBinary();
            return _addon.StartAnnotation(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let StopAnnotationParams = new messages.StopAnnotationParams();
            StopAnnotationParams.setViewtype(viewtype);
            let bytes = StopAnnotationParams.serializeBinary();
            return _addon.StopAnnotation(bytes);            
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetToolParams = new messages.SetToolParams();
            SetToolParams.setViewtype(viewtype);
            SetToolParams.setTooltype(toolType);
            let bytes = StartAnnotationParams.serializeBinary();
            return _addon.SetTool(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let ClearAnnotationParams = new messages.ClearAnnotationParams();
            ClearAnnotationParams.setViewtype(viewtype);
            ClearAnnotationParams.setCleartype(clearType);
            let bytes = ClearAnnotationParams.serializeBinary();
            return _addon.Clear(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetColorParams = new messages.SetColorParams();
            SetColorParams.setViewtype(viewtype);
            SetColorParams.setColor(color);
            let bytes = SetColorParams.serializeBinary();
            return _addon.SetColor(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let SetLineWidthParams = new messages.SetLineWidthParams();
            SetLineWidthParams.setViewtype(viewtype);
            SetLineWidthParams.setLinewidth(lineWidth);
            let bytes = SetLineWidthParams.serializeBinary();
            return _addon.SetLineWidth(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let UndoParams = new messages.UndoParams();
            UndoParams.setViewtype(viewtype);
            let bytes = UndoParams.serializeBinary();
            return _addon.Undo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let RedoParams = new messages.RedoParams();
            RedoParams.setViewtype(viewtype);
            let bytes = RedoParams.serializeBinary();
            return _addon.Redo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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