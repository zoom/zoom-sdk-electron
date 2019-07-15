const { ZoomMeetingStatus, ZoomUserType, ZoomSDKError } = require('./settings.js');
const ZoomMeetingINFOMOD = require('./zoom_meeting_info.js');
const ZoomMeetingUIMOD = require('./zoom_meeting_ui_ctrl.js');
const ZoomAnnotationMOD = require('./zoom_annotation_ctrl.js');
const ZoomMeetingAudioMOD = require('./zoom_meeting_audio.js');
const ZoomMeetingVideoMOD = require('./zoom_meeting_video.js');
const ZoomMeetingShareMOD = require('./zoom_meeting_share.js');
const ZoomMeetingH323MOD = require('./zoom_h323.js');
const ZoomMeetingConfigurationMOD = require('./zoom_meeting_configuration.js');
const ZoomUpdateAccountMOD = require('./zoom_upgrade_account.js');

const ZoomMeeting = (function () {
  let instance;
   /**
   * mode: Zoom SDK Meeting Service Init
   * @param {Object} addon zoom sdk module
   * @param {Function} meetingstatuscb The logincb method specifies a callback method to call on meeting status changed
   * @return {ZoomMeeting}
   */
  function init(opts) {
    let clientOpts = opts || {};

    // Private methods and variables 
    let _addon = clientOpts.addon.GetMeetingObj() || null;
    let _meetingstatuscb = clientOpts.meetingstatuscb || null;
    let _meetinguserjoincb = clientOpts.meetinguserjoincb || null;
    let _meetinguserleftcb = clientOpts.meetinguserleftcb || null
    let _meetinghostchangecb = clientOpts.meetinghostchangecb || null
    let _isInmeeting = false;
    let _lasthostid = 0;
    let userlist = new Map();
    if (_addon) {
      _addon.GetMeetingParticipantsCtrl().SetMeetingUserJoinCB(onUserJoin);
      _addon.GetMeetingParticipantsCtrl().SetMeetingUserLeftCB(onUserLeft);
      _addon.GetMeetingParticipantsCtrl().SetMeetingHostChangeCB(onHostChangeNotification);
    }

    function onMeetingStatus(status, errorcode) {
      if (ZoomMeetingStatus.MEETING_STATUS_INMEETING == status || ZoomMeetingStatus.MEETING_STATUS_LOCKED == status || ZoomMeetingStatus.MEETING_STATUS_UNLOCKED == status) {
        _isInmeeting = true
      } else if (ZoomMeetingStatus.MEETING_STATUS_ENDED == status || ZoomMeetingStatus.MEETING_STATUS_DISCONNECTING == status || ZoomMeetingStatus.MEETING_STATUS_RECONNECTING == status) {
        _isInmeeting = false
        userlist.clear()
      } else {
        _isInmeeting = false
      }
      if (null != _meetingstatuscb)
        _meetingstatuscb(status, errorcode)
    }

    function onUserJoin(userinfolist) {
      if (typeof userinfolist === 'string')
        var userarray = JSON.parse(userinfolist);
      else
        var userarray = userinfolist;
      if (userarray.userlist) {
        userarray.userlist.forEach(function (item, index) {
          let useritem = new Object();
          useritem.userid = parseInt(item.userid, 10);
          useritem.username = item.username;
          useritem.isme = item.isme;
          useritem.ishost = item.ishost;
          _lasthostid = useritem.userid;
          useritem.audiostatus = ZoomMeetingAudioMOD.ZoomMeetingAudioStatus.Audio_None;
          useritem.videostatus = ZoomMeetingVideoMOD.ZoomMeetingVideoStatus.Video_OFF;
          
          if(!userlist.has(useritem.userid))
            userlist.set(useritem.userid, useritem);
          if (null != _meetinguserjoincb){
            _meetinguserjoincb(useritem);
          }
        });
      }
    }

    function onUserLeft(userinfolist, nouse) {
    	if (typeof userinfolist === 'string')
			  var userarray = JSON.parse(userinfolist);
		  else
			  var userarray = userinfolist;		
        userarray.userlist.forEach(function (item, index) {
          var userid = parseInt(item.userid, 10)
          userlist.delete(userid)
          if (null != _meetinguserleftcb){
            _meetinguserleftcb(userid)
          }
        });
    }

    function UpdateHostId(newid, oldid) {
      var newhost = userlist.get(newid);
      if (newhost === undefined)
          return;
      newhost.ishost = 'true';
      _lasthostid = newid;
      var oldhost = userlist.get(oldid)
      if (oldhost === undefined)
          return;
      oldhost.ishost = 'false';
    }

    function onHostChangeNotification(userid) {
      if (_lasthostid == userid)
        return
      UpdateHostId(userid, _lasthostid)
      if (_meetinghostchangecb)
        _meetinghostchangecb(userid)
    }

    return {
      // Public methods and variables
      /** 
      * mode: Start meeting
      * @param {String} meetingnum A number to the meeting to be started.
      * @param {String} directshareappwndhandle Windows handle of which window you want to share directly (require hexadecimal)
      * @param {String} participantid ID for meeting participant report list, need web backend enable.
      * @param {Boolean} isvideooff
      * @param {Boolean} isaudiooff
      * @param {Boolean} isdirectsharedesktop
      * @return {ZoomSDKError}
      */
      StartMeeting: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingnum = clientOpts.meetingnum || 0;
          let directshareappwndhandle = clientOpts.directshareappwndhandle || 0;
          let participantid = clientOpts.participantid || '';
          let isvideooff = (clientOpts.isvideooff === undefined) ? false : clientOpts.isvideooff;
          let isaudiooff = (clientOpts.isaudiooff === undefined) ? false : clientOpts.isaudiooff;
          let isdirectsharedesktop = (clientOpts.isdirectsharedesktop === undefined) ? false : clientOpts.isdirectsharedesktop;
          return _addon.Start(meetingnum.toString(), directshareappwndhandle.toString(), participantid, isvideooff, isaudiooff, isdirectsharedesktop, onMeetingStatus);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Start meeting without login
      * @param {String} userid user id. From Rest API
      * @param {String} usertoken user token. From Rest API
      * @param {String} zoomaccesstoken zoom access token
      * @param {String} username
      * @param {String} zoomusertype ZoomUserType
      * @param {Number} meetingnum A number to the meeting to be started.
      * @param {String} vanityid String. Meeting vanity ID
      * @param {Number} directshareappwndhandle Windows handle of which window you want to share directly (require hexadecimal)
      * @param {String} participantid ID for meeting participant report list, need web backend enable
      * @param {Boolean} isdirectsharedesktop: 
      * @param {Boolean} isvideooff
      * @param {Boolean} isaudiooff
      * @return {ZoomSDKError}
      */
      StartMeetingWithOutLogin: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid || '';
          let usertoken = clientOpts.usertoken || '';
          let zoomaccesstoken = clientOpts.zoomaccesstoken || '';
          let username = clientOpts.username || '';
          let zoomusertype = clientOpts.zoomusertype || ZoomUserType.ZoomUserType_APIUSER;
          let meetingnumber = clientOpts.meetingnum || 0;
          let vanityid = clientOpts.vanityid || '';
          let directshareappwndhandle = clientOpts.directshareappwndhandle || 0;
          let participantid = clientOpts.participantid || '';
          let isdirectsharedesktop = (clientOpts.isdirectsharedesktop === undefined) ? false : clientOpts.isdirectsharedesktop;
          let isvideooff = (clientOpts.isvideooff === undefined) ? false : clientOpts.isvideooff;
          let isaudiooff = (clientOpts.isaudiooff === undefined) ? false : clientOpts.isaudiooff;
			    return _addon.Start_WithoutLogin(userid, usertoken, zoomaccesstoken, username, zoomusertype, meetingnumber.toString(),
			      vanityid, directshareappwndhandle.toString(), participantid, isdirectsharedesktop, isvideooff, isaudiooff, onMeetingStatus);
          }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Join meeting
      * @param {Number} meetingnum A number to the meeting to be joined.
      * @param {String} vanityid Meeting vanity ID
      * @param {String} username
      * @param {String} psw Meeting password
      * @param {Number} directshareappwndhandle Windows handle of which window you want to share directly (require hexadecimal)
      * @param {String} participantid ID for meeting participant report list, need web backend enable.
      * @param {String} webinartoken webinar token
      * @param {Boolean} isvideooff 
      * @param {Boolean} isaudiooff
      * @param {Boolean} isdirectsharedesktop
      * @return {ZoomSDKError}
      */
      JoinMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingnum = clientOpts.meetingnum || 0;
          let vanityid = clientOpts.vanityid || '';
          let username = clientOpts.username || '';
          let psw = clientOpts.psw || '';
          let directshareappwndhandle = clientOpts.directshareappwndhandle || 0;
          let participantid = clientOpts.participantid || '';
          let webinartoken = clientOpts.webinartoken || '';
          let isvideooff = (clientOpts.isvideooff === undefined) ? false : clientOpts.isvideooff;
          let isaudiooff = (clientOpts.isaudiooff === undefined) ? false : clientOpts.isaudiooff;
          let isdirectsharedesktop = (clientOpts.isdirectsharedesktop === undefined) ? false : clientOpts.isdirectsharedesktop;
          return _addon.Join(meetingnum.toString(), vanityid, username, psw, directshareappwndhandle.toString(), 
            participantid, webinartoken, isvideooff, isaudiooff, isdirectsharedesktop, onUserJoin);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Join meeting withoutlogin
      * @param {Number} meetingnum A number to the meeting to be joined.
      * @param {String} vanityid Meeting vanity ID
      * @param {String} username
      * @param {String} psw Meeting password
      * @param {Number} directshareappwndhandle: Number, Windows handle of which window you want to share directly (require hexadecimal)
      * @param {String} toke4enfrocelogin Token of the meeting only for login user
      * @param {String} participantid ID for meeting participant report list, need web backend enable.
      * @param {String} webinartoken webinar token
      * @param {Boolean} isdirectsharedesktop 
      * @param {Boolean} isvideooff
      * @param {Boolean} isaudiooff
      * @return {ZoomSDKError}
      */
      JoinMeetingWithoutLogin: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingnum = clientOpts.meetingnum || 0;
          let vanityid = clientOpts.vanityid || '';
          let username = clientOpts.username || '';
          let psw = clientOpts.psw || '';
          let directshareappwndhandle = clientOpts.directshareappwndhandle || 0;
          let toke4enfrocelogin = clientOpts.toke4enfrocelogin || '';
          let participantid = clientOpts.participantid || '';
          let webinartoken = clientOpts.webinartoken || '';
          let isdirectsharedesktop = (clientOpts.isdirectsharedesktop === undefined) ? false : clientOpts.isdirectsharedesktop;
          let isvideooff = (clientOpts.isvideooff === undefined) ? false : clientOpts.isvideooff;
          let isaudiooff = (clientOpts.isaudiooff === undefined) ? false : clientOpts.isaudiooff;
          return _addon.Join_WithoutLogin(meetingnum.toString(), vanityid, username, psw, directshareappwndhandle.toString(), toke4enfrocelogin, 
            participantid, webinartoken, isdirectsharedesktop, isvideooff, isaudiooff, onUserJoin);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * mode: Leave meeting
      * @param {Boolean} endMeeting
      * @return {ZoomSDKError}
      */
      LeaveMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let endMeeting = clientOpts.endMeeting || false;
          return _addon.Leave(endMeeting);
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * mode: Lock Meeting
       * @return {ZoomSDKError}
      */
      Lock_Meeting: function () {
        if (_addon) {
          return _addon.Lock();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Unlock Meeting
      * @return {ZoomSDKError}
      */
      Un_lock_Meeting: function () {
        if (_addon) {
          return _addon.Unlock();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Get Share Session ConnQuality
      * @return {ZNConnectionQuality(int)}
      */
      GetSharingConnQuality: function () {
        if (_addon) {
          return _addon.GetSharingConnQuality();
        }
        return "";
      },
      /**
       * mode: Get Video Session ConnQuality
       * @return {ZNConnectionQuality(int)}
       */
      GetVideoConnQuality: function () {
        if (_addon) {
          return _addon.GetVideoConnQuality();
        }
        return "";
      },
      /**
       * mode: Get Audio Session ConnQuality
       * @return {AudioConnQuality}
       */
      GetAudioConnQuality: function () {
        if (_addon) {
          return _addon.GetAudioConnQuality();
        }
        return "";
      },
      /**
       * Get Meetin Info
      */
      GetMeetingInfo: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          clientOpts.addon = _addon;
          return ZoomMeetingINFOMOD.ZoomMeetingInfo.getInstance(clientOpts);
        }
        return null;
      },
      GetMeetingUICtrl: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomMeetingUIMOD.ZoomMeetingUICtrl.getInstance(clientOpts);
        }
      },
      GetAnnotationCtrl: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomAnnotationMOD.ZoomAnnotationCtrl.getInstance(clientOpts);
        }
      },
      GetMeetingAudio: function(opts) {
        if (_addon){
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomMeetingAudioMOD.ZoomMeetingAudio.getInstance(clientOpts);
        } 
      },
      GetMeetingVideo: function(opts) {
        if (_addon){
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomMeetingVideoMOD.ZoomMeetingVideo.getInstance(clientOpts);
        } 
      },
      GetMeetingShare: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomMeetingShareMOD.ZoomMeetingShare.getInstance(clientOpts);
        } 
      },
      GetMeetingH323: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomMeetingH323MOD.ZoomH323.getInstance(clientOpts);
        }		
      },
      GetMeetingConfiguration: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomMeetingConfigurationMOD.ZoomMeetingConfiguration.getInstance(clientOpts);
        }
      },
      GetUpdateAccount: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          return ZoomUpdateAccountMOD.ZoomPaymentReminder.getInstance(clientOpts);
        }
      }
    };
  };
 
  return {
    /**
     * mode: Get Zoom SDK Meeting Service Module
     * @return {ZoomMeeting}
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
  ZoomMeeting: ZoomMeeting
}