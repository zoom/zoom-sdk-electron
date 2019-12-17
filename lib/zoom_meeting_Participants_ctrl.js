const { ZoomSDKError } = require('./settings.js');

var ZoomMeetingParticipantsCtrl = (function () {
  var instance;
   /**
   * mode: Zoom SDK Meeting audio module Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingParticipantsCtrl}
   */
  function init(opts) {
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetMeetingParticipantsCtrl() || null;   

    let _meetinguserjoincb = clientOpts.meetinguserjoincb || null;
    let _meetinguserleftcb = clientOpts.meetinguserleftcb || null;
    let _meetinghostchangecb = clientOpts.meetinghostchangecb || null;

    if (_addon) {
      _addon.SetMeetingUserJoinCB(_meetinguserjoincb);
      _addon.SetMeetingUserLeftCB(_meetinguserleftcb);
      _addon.SetMeetingHostChangeCB(_meetinghostchangecb);
    }

    return {
      // Public methods and variables
      /**
       * mode: Get ParticipantsList
       * @return {GetParticipantsList}
       */
      GetParticipantsList: function () {
        if (_addon) {
          return _addon.GetParticipantsList();
        }
        return "";
      },
      /**
       * mode: Get UserInfoByUserID
       * @return {ZoomSDKError}
       */
      GetUserInfoByUserID: function(userid) {
        if (_addon) {
          return _addon.GetUserInfoByUserID(Number(userid));
        }
        return "";
      },
      /**
       * mode: Set Meeting User Join CB
       * @return {ZoomSDKError}
       */
      SetMeetingUserJoinCB: function(onUserJoin) {
        if (_addon) {
          _addon.SetMeetingUserJoinCB(onUserJoin);
        }
      },
      /**
       * mode: Set Meeting User Left CB
       * @return {ZoomSDKError}
       */
      SetMeetingUserLeftCB: function(onUserLeft) {
        if (_addon) {
          _addon.SetMeetingUserLeftCB(onUserLeft);
        }
      },
      /**
       * mode: Set Meeting Host Change CB
       * @return {ZoomSDKError}
       */
      SetMeetingHostChangeCB: function(onHostChangeNotification) {
        if (_addon) {
          _addon.SetMeetingHostChangeCB(onHostChangeNotification);
        }
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Audio Module
     * @return {ZoomMeetingParticipantsCtrl}
    */
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance
    }
  };
})();

module.exports = {
  ZoomMeetingParticipantsCtrl: ZoomMeetingParticipantsCtrl
}