const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

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
      SetMeetingAudioStatusCB: function (onUserAudioStatusChange) {
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
      SetUserActiveAudioChangeCB: function (onUserActiveAudioChange) {
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
          try {
            let MuteAudioParams = new messages.MuteAudioParams();
            MuteAudioParams.setUserid(userid);
            MuteAudioParams.setAllowunmutebyself(allowunmutebyself);
            let bytes = MuteAudioParams.serializeBinary();
            return _addon.MuteAudio(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
        * mode: Unmute audio 
        * @param {Number} userid Specifies which the user's audio to mute
        * @return {ZoomSDKError}
        */
      MeetingAudio_UnMuteAudio: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var userid = clientOpts.userid;        
          try {
            let UnmuteAudioParams = new messages.UnmuteAudioParams();
            UnmuteAudioParams.setUserid(userid);
            let bytes = UnmuteAudioParams.serializeBinary();
            return _addon.UnMuteAudio(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
      },
      /** 
      * mode: User joins or leaves the meeting in silence or no
      * @param {Boolean} bEnable TRUE indicates to play chime when the user joins or leaves the meeting
      * @return {ZoomSDKError}
      */
      MeetingAudio_EnablePlayChimeWhenEnterOrExit: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var bEnable = clientOpts.bEnable; 
          try {
            let EnablePlayChimeWhenEnterOrExitParams = new messages.EnablePlayChimeWhenEnterOrExitParams();
            EnablePlayChimeWhenEnterOrExitParams.setBenable(bEnable);
            let bytes = EnablePlayChimeWhenEnterOrExitParams.serializeBinary();     
            return _addon.EnablePlayChimeWhenEnterOrExit(bytes);
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