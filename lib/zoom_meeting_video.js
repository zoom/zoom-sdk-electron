var ZoomMeetingVideo = (function () {
  var instance;
   /**
   * mode: Zoom SDK Meeting video module Init
   * @param {Object} addon zoom sdk module
   * @return {ZoomMeetingVideo}
   */
  function init(opts) {
    var clientOpts = opts || {};
    // Private methods and variables
    var _addon = clientOpts.addon.GetMeetingVideoCtrl();

    function onUserVideoStatusChange(result) {
      console.log('onUserVideoStatusChange', result);
    }

    return {
      // Public methods and variables
      /** 
      * mode: Mute video
      * @return {ZoomSDKError}
      */
      MeetingVideo_MuteVideo: function(opts) {
        if(_addon) {
          return _addon.MuteVideo(onUserVideoStatusChange);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Unmute video
      * @return {ZoomSDKError}
      */
      MeetingVideo_UnMuteVideo: function () {
        if(_addon) {
          return _addon.UnMuteVideo(onUserVideoStatusChange);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: pin video
      * @param {Boolean} bPin bPin or not
      * @param {Boolean} bFirstView bFirstView or not
      * @param {String} userid Specifies which the user's video to pin
      * @return {ZoomSDKError}
      */
      MeetingVideo_PinVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bPin = clientOpts.bPin;
          let bFirstView = clientOpts.bFirstView;
          let userid = clientOpts.userid;
          return _addon.PinVideo(bPin, bFirstView, userid, onUserVideoStatusChange);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Spotlight video
      * @param {Boolean} bSpotlight bSpotlight or not
      * @param {String} userid Specifies which the user's video to pin
      * @return {ZoomSDKError}
      */
      MeetingVideo_SpotlightVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bSpotlight = clientOpts.bSpotlight;
          let userid = clientOpts.userid;
          return _addon.SpotlightVideo(bSpotlight, userid, onUserVideoStatusChange);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Hide Or Show No Video User On Video Wall 
      * @param {Boolean} bHide bHide or not
      * @return {ZoomSDKError}
      */
      MeetingVideo_HideOrShowNoVideoUserOnVideoWall: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let bHide = clientOpts.bHide;
          return _addon.HideOrShowNoVideoUserOnVideoWall(bHide, onUserVideoStatusChange);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      }
    };
  };
  return {
    /**
     * mode: Get Zoom SDK Meeting Video Module
     * @return {ZoomMeetingVideo}
    */
    getInstance: function(opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    }
  };
})();

module.exports = {
  ZoomMeetingVideo: ZoomMeetingVideo
}