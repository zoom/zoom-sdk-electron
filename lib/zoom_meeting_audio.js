const { ZoomSDKError } = require('./settings.js');

/**
*@module
*/
var ZoomMeetingAudio = (function () {
  var instance;
   /**
   * mode: Zoom SDK Meeting audio module Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingAudio}
   */
  function init(opts) {
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetMeetingAudioCtrl() || null;   
    let _onUserAudioStatusChange = clientOpts.onUserAudioStatusChange || null;
    let _onUserActiveAudioChange = clientOpts.onUserActiveAudioChange || null;

    function onUserAudioStatusChange(lstAudioStatusChange, strAudioStatusList) {
      if (_onUserAudioStatusChange) {
        _onUserAudioStatusChange(lstAudioStatusChange, strAudioStatusList)
      }
    }

    function onUserActiveAudioChange(lstActiveAudio) {
      if (_onUserActiveAudioChange) {
        _onUserActiveAudioChange(lstActiveAudio)
      }
    }

    if (_addon) {
      _addon.SetMeetingAudioStatusCB(onUserAudioStatusChange);
      _addon.SetUserActiveAudioChangeCB(onUserActiveAudioChange);
    }

    return {
      // Public methods and variables
      /**
       * mode: Set Meeting Audio Status CB
       * @param {Function} onUserAudioStatusChange
       * @return {Boolean}
       */
      MeetingAudio_SetMeetingAudioStatusCB: function (onUserAudioStatusChange) {
        if (addon && onUserAudioStatusChange && onUserAudioStatusChange instanceof Function) {
          _onUserAudioStatusChange = onUserAudioStatusChange
          return true
        }
        return false
      },
      /**
       * mode: Set User Active Audio Change CB
       * @param {Function} onUserActiveAudioChange
       * @return {Boolean}
       */
      MeetingAudio_SetUserActiveAudioChangeCB: function (onUserActiveAudioChange) {
        if (addon && onUserActiveAudioChange && onUserActiveAudioChange instanceof Function) {
          _onUserActiveAudioChange = onUserActiveAudioChange
          return true
        }
        return false
      },
      /** 
      * mode: Mute audio 
      * @param {Number} userid Specifies which the user's audio to mute.if is zero, mute all of users
      * @param {Boolean} allowunmutebyself Specifies can unmute by self or not when mute all
      * @return {ZoomSDKError}
      */
      MeetingAudio_MuteAudio: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid || '';
          let allowunmutebyself = clientOpts.allowunmutebyself;
          return _addon.MuteAudio(Number(userid), allowunmutebyself);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Unmute audio 
        * @param {Number} userid Specifies which the user's audio to mute.if is zero, unmute all of users
        * @return {ZoomSDKError}
        */
      MeetingAudio_UnMuteAudio: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var userid = clientOpts.userid;        
          return _addon.UnMuteAudio(Number(userid));
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Join Voip audio 
      * @return {ZoomSDKError}
      */
      MeetingAudio_JoinVoip: function () {
        if (_addon){
          return _addon.JoinVoip();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Leave Voip audio 
      * @return {ZoomSDKError}
      */
      MeetingAudio_LeaveVoip: function () {
        if (_addon) {
          return _addon.LeaveVoip();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Audio Module
     * @return {ZoomMeetingAudio}
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
  ZoomMeetingAudio: ZoomMeetingAudio
}