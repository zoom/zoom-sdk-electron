const { ZoomSDKError, ZNSDKUserInfoType } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
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

    function meetinguserjoincb(lstUserID, strUserList) {
      if (_meetinguserjoincb) {
        _meetinguserjoincb(lstUserID, strUserList)
      }
    }

    function meetinguserleftcb(lstUserID, strUserList) {
      if (_meetinguserleftcb) {
        _meetinguserleftcb(lstUserID, strUserList)
      }
    }

    function meetinghostchangecb(userList) {
      if (_meetinghostchangecb) {
        _meetinghostchangecb(userList)
      }
    }

    if (_addon) {
      _addon.SetMeetingUserJoinCB(meetinguserjoincb);
      _addon.SetMeetingUserLeftCB(meetinguserleftcb);
      _addon.SetMeetingHostChangeCB(meetinghostchangecb);
    }

    return {
      // Public methods and variables
      /**
       * mode: Set Meeting User Join CB
       * @param {Function} meetinguserjoincb
       * @return {Boolean}
       */
      SetMeetingUserJoinCB: function(meetinguserjoincb) {
        if (_addon && meetinguserjoincb && meetinguserjoincb instanceof Function) {
          _meetinguserjoincb = meetinguserjoincb;
          return true;
        }
        return false;
      },
      /**
       * mode: Set Meeting User Left CB
       * @param {Function} meetinguserleftcb
       * @return {Boolean}
       */
      SetMeetingUserLeftCB: function(meetinguserleftcb) {
        if (_addon && meetinguserleftcb && meetinguserleftcb instanceof Function) {
          _meetinguserleftcb = meetinguserleftcb;
          return true
        }
        return false
      },
      /**
       * mode: Set Meeting Host Change CB
       * @param {Function} onHostChangeNotification
       * @return {Boolean}
       */
      SetMeetingHostChangeCB: function(onHostChangeNotification) {
        if (_addon && onHostChangeNotification && meetinguserleftcb instanceof Function) {
          _onHostChangeNotification = onHostChangeNotification;
          return true;
        }
        return false;
      },
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
       * @return {Object}
       */
      GetUserInfoByUserID: function(userid) {
        if (_addon) {
          try {
            let GetUserInfoByUserIDParams = new messages.GetUserInfoByUserIDParams();
            GetUserInfoByUserIDParams.setUserid(Number(userid));
            let bytes = GetUserInfoByUserIDParams.serializeBinary();
            let userInfo = _addon.GetUserInfoByUserID(bytes);
            if (userInfo.userInfoType == ZNSDKUserInfoType.ZN_FAKE_USERINFO) {
              return {}
            } else {
              return userInfo
            }
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return "";
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