const { ZoomSDKError } = require('./settings.js');

var ZoomPreMeeting = (function () {
  var instance;
  /**
   * mode: Zoom SDK ZoomPreMeeting Service Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomPreMeeting}
   */
  function init(opts) { 
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetPremeetingObj() || null;

    function onScheduleOrEditMeeting(result) {
      console.log('onScheduleOrEditMeeting', result)
    }

    return {
      /**
      * mode: Get General ZoomPreMeeting Module
      * @param {String} content
      * @return {ZoomPreMeeting}
      */
      GetInviteEmailContent: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let content = clientOpts.content;
          return _addon.GetPremeetingMeetingItemCtrl().GetInviteEmailContent(content);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Schedule Meeting
      * @param {String} hSelfWnd SelfWnd (require hexadecimal)
      * @param {String} hParent parent window handle (require hexadecimal)
      * @param {String} left chat window left pos
      * @param {String} top chat window top pos
      * @return {ZoomPreMeeting}
      */
      ScheduleMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          return _addon.ScheduleMeeting(hSelfWnd, hParent, left, top, onScheduleOrEditMeeting);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK ZoomPreMeeting Service Module
     * @return {ZoomPreMeeting}
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
  ZoomPreMeeting: ZoomPreMeeting
}