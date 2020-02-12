/**
*@module
*/
var ZoomMeetingInfo = (function () {
  var instance;
  /**
  * Zoom SDK Meeting Info module Init
  * @param {Object} addon zoom sdk module
  * @return {ZoomMeetingInfo}
  */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingInfo() || null;
    return {
      /**
       * mode: Get Meeting Number
       * @return {String}
       */
      GetMeetingNumber: function () {
        if (_addon) {
          return _addon.GetMeetingNumber();
        }
        return "";
      },
      /**
       * mode: Get Meeting Topic
       * @return {String}
       */
      GetMeetingTopic: function () {
        if (_addon) {
          return _addon.GetMeetingTopic();
        }
        return "";
      },
      /**
       * mode: Get Meeting ID
       * @return {String}
       */
      GetMeetingID: function () {
        if (_addon) {
          return _addon.GetMeetingID();
        }
        return "";
      },
      /**
      * mode: Get Meeting Type
      * @return {MeetingType}
      */
      GetMeetingType: function () {
        if (_addon) {
          return _addon.GetMeetingType();
        }
        return "";
      },
      /** 
       * mode: Get Invite Email Teamplate
       * @return {String}
       */
      GetInviteEmailTeamplate: function () {
        if (_addon) {
          return _addon.GetInviteEmailTeamplate();
        }
        return "";
      },
      /** 
       * mode: Get Invite Email Title
       * @return {String}
       */
      GetInviteEmailTitle: function () {
        if (_addon) {
          return _addon.GetInviteEmailTitle();
        }
        return "";
      },
      /** 
       * mode: Get Join Meeting Url
       * @return {String}
       */
      GetJoinMeetingUrl: function () {
        if (_addon) {
          return _addon.GetJoinMeetingUrl();
        }
        return "";
      },
      /** 
      * mode: Get Meeting Host Tag
      * @return {String}
      */
      GetMeetingHostTag: function () {
        if (_addon) {
          return _addon.GetMeetingHostTag();
        }
        return "";
      },
      /** 
      * mode: Check if Internal Meeting.
      * @return {Boolean}
      */
      CheckingIsInternalMeeting: function () {
        if (_addon) {
          return _addon.CheckingIsInternalMeeting();
        }
        return false;
      }
    };
  };

  return {
    /**
     * mode: Get Meeting Info Module
     * @return {ZoomMeetingInfo}
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
  ZoomMeetingInfo: ZoomMeetingInfo
}