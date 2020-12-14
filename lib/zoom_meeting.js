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
const ZoomMeetingParticipantsMOD = require('./zoom_meeting_Participants_ctrl.js');
const ZoomMeetingRecordingMOD = require('./zoom_meeting_recording.js');
const messages = require('./electron_sdk_pb.js');

let ZoomMeetingInfo;
let ZoomMeetingUICtrl;
let ZoomAnnotationCtrl;
let ZoomMeetingAudio;
let ZoomMeetingVideo;
let ZoomMeetingShare;
let ZoomH323;
let ZoomMeetingConfiguration;
let ZoomPaymentReminder;
let ZoomMeetingParticipantsCtrl;
let ZoomMeetingRecording;
let startOrJoinWithRawdata;

/**
*@module
*/
const ZoomMeeting = (function () {
  let instance;
  /**
  * mode: Zoom SDK Meeting Service Init
  * @param {Object} addon zoom sdk module
  * @param {Function} meetingstatuscb meeting status callback
  * @return {ZoomMeeting}
  */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingObj() || null;
    let _rawdataAddon = clientOpts.addon.GetRawdataAPIWrap() || null;
    let _meetingstatuscb = clientOpts.meetingstatuscb || null;

    function meetingstatuscb(meetingStatus, result) {
      switch (meetingStatus) {
        case ZoomMeetingStatus.MEETING_STATUS_CONNECTING:
          if (startOrJoinWithRawdata) {
            StartPipeServe()
          }
          break;
        case ZoomMeetingStatus.MEETING_STATUS_DISCONNECTING:
        case ZoomMeetingStatus.MEETING_STATUS_RECONNECTING: 
          if (startOrJoinWithRawdata) {
            StopPipeServe();
          }
          break;
        default:
          break;
      }
      if (_meetingstatuscb) {
        _meetingstatuscb(meetingStatus, result)
      }
    }

    function StartPipeServe() {
      if (_rawdataAddon) {
        return _rawdataAddon.StartPipeServe();
      }
      return ZoomSDKError.SDKERR_UNINITIALIZE
    }

    function StopPipeServe() {
      if (_rawdataAddon) {
        return _rawdataAddon.StopPipeServe();
      }
      return ZoomSDKError.SDKERR_UNINITIALIZE
    }

    if (_addon) {
      _addon.SetMeetingStatusCB(meetingstatuscb);
    }

    return {
      // Public methods and variables
      /**
      * mode: Set Meeting Status CB
      * @param {Function} meetingstatuscb
      * @return {Boolean}
      */
      SetMeetingStatusCB: function (meetingstatuscb) {
        if (_addon && meetingstatuscb && meetingstatuscb instanceof Function) {
          _meetingstatuscb = meetingstatuscb;
          return true;
        }
        return false;
      },
      /**
      * mode: Start meeting
      * @param {Number} meetingnum A number to the meeting to be started.
      * @param {String} directshareappwndhandle Windows handle of which window you want to share directly (require hexadecimal)
      * @param {String} participantid ID for meeting participant report list, need web backend enable.
      * @param {Boolean} isvideooff
      * @param {Boolean} isaudiooff
      * @param {Boolean} isdirectsharedesktop
      * @return {ZoomSDKError}
      */
      StartMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingnum = clientOpts.meetingnum || 0;
          let directshareappwndhandle = clientOpts.directshareappwndhandle || 0;
          let participantid = clientOpts.participantid || '';
          let isvideooff = (clientOpts.isvideooff === undefined) ? false : clientOpts.isvideooff;
          let isaudiooff = (clientOpts.isaudiooff === undefined) ? false : clientOpts.isaudiooff;
          let isdirectsharedesktop = (clientOpts.isdirectsharedesktop === undefined) ? false : clientOpts.isdirectsharedesktop;
          try {
            let StartMeetingParams = new messages.StartMeetingParams();
            StartMeetingParams.setMeetingnumber(Number(meetingnum));
            StartMeetingParams.setHdirectshareappwnd(directshareappwndhandle.toString());
            StartMeetingParams.setParticipantid(participantid);
            StartMeetingParams.setIsvideooff(isvideooff);
            StartMeetingParams.setIsaudiooff(isaudiooff);
            StartMeetingParams.setIsdirectsharedesktop(isdirectsharedesktop);
            let bytes = StartMeetingParams.serializeBinary();
            let result = _addon.Start(bytes);
            if (result == 0) {
              startOrJoinWithRawdata = clientOpts.withRawdata;
            }
            return result;
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Start meeting without login
      * @param {String} userid [Required] User ID
      * @param {String} zoomaccesstoken [Required] ZOOM access token
      * @param {String} username [Required] User Name
      * @param {Number} zoomusertype [Required] User type, See ZoomUserType in settings.js
      * @param {Number} meetingnum [Optinal] Meeting number, meetingnum or vanityid is Required
      * @param {String} vanityid [Optinal] vanityid is suffix of Personal Link, meetingnum or vanityid is Required
      * @param {Number} directshareappwndhandle [Optinal] The window handle of the direct sharing application (require hexadecimal)
      * @param {String} participantid [Optinal] The ID of attendees, The SDK will set this value when the associated settings are turned on
      * @param {Boolean} isdirectsharedesktop [Optinal] Share the desktop directly or not. True indicates to share
      * @param {Boolean} isvideooff [Optinal] Turn off the video or not, True indicates to turn off. In addition, this flag is affected by meeting attributes
      * @param {Boolean} isaudiooff [Optinal] Turn off the audio or not, True indicates to turn off. In addition, this flag is affected by meeting attributes.
      * @return {ZoomSDKError}
      */
      StartMeetingWithOutLogin: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userid = clientOpts.userid || '0';
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
          try {
            let StartWithoutLoginParams = new messages.StartWithoutLoginParams();
            StartWithoutLoginParams.setUserid(userid);
            StartWithoutLoginParams.setUserzak(zoomaccesstoken);
            StartWithoutLoginParams.setUsername(username);
            StartWithoutLoginParams.setNodeusertype(Number(zoomusertype));
            StartWithoutLoginParams.setMeetingnumber(Number(meetingnumber));
            StartWithoutLoginParams.setSdkvanityid(vanityid);
            StartWithoutLoginParams.setHdirectshareappwnd(directshareappwndhandle.toString());
            StartWithoutLoginParams.setParticipantid(participantid);
            StartWithoutLoginParams.setIsdirectsharedesktop(isdirectsharedesktop);
            StartWithoutLoginParams.setIsvideooff(isvideooff);
            StartWithoutLoginParams.setIsaudiooff(isaudiooff);
            let bytes = StartWithoutLoginParams.serializeBinary();
            return _addon.Start_WithoutLogin(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Join meeting
      * @param {Number} meetingnum A number to the meeting to be joined, meetingnum or vanityid is Required
      * @param {String} vanityid vanityid is suffix of Personal Link, meetingnum or vanityid is Required
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
          startOrJoinWithRawdata = clientOpts.withRawdata;
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
          try {
            let JoinMeetingParams = new messages.JoinMeetingParams();
            JoinMeetingParams.setMeetingnumber(Number(meetingnum));
            JoinMeetingParams.setVanityid(vanityid);
            JoinMeetingParams.setUsername(username);
            JoinMeetingParams.setPsw(psw);
            JoinMeetingParams.setHdirectshareappwnd(directshareappwndhandle.toString());
            JoinMeetingParams.setParticipantid(participantid);
            JoinMeetingParams.setWebinartoken(webinartoken);
            JoinMeetingParams.setIsvideooff(isvideooff);
            JoinMeetingParams.setIsaudiooff(isaudiooff);
            JoinMeetingParams.setIsdirectsharedesktop(isdirectsharedesktop);
            let bytes = JoinMeetingParams.serializeBinary();
            let result = _addon.Join(bytes);
            if (result == 0) {
              startOrJoinWithRawdata = clientOpts.withRawdata;
            }
            return result;
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Join meeting withoutlogin
      * @param {Number} meetingnum [Required] Meeting Number, meetingnum or vanityid is Required
      * @param {String} vanityid [Optinal] vanityid is suffix of Personal Link, meetingnum or vanityid is Required
      * @param {String} username [Optinal] User Name
      * @param {String} psw [Optinal] Meeting password
      * @param {Number} directshareappwndhandle: [Optinal] The window handle of the direct sharing application (require hexadecimal)
      * @param {String} userZAK [Optinal] ZOOM access token
      * @param {String} participantid [Optinal] The ID of attendees. The SDK will set this value when the associated settings are turned on
      * @param {String} webinartoken [Optinal] Webinar token, if try to join webinar as a panelist
      * @param {Boolean} isdirectsharedesktop [Optinal] Share the desktop directly or not. True indicates to share
      * @param {Boolean} isvideooff [Optinal] Turn off the video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes
      * @param {Boolean} isaudiooff [Optinal] Turn off the audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes
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
          let userZAK = clientOpts.userZAK || '';
          let participantid = clientOpts.participantid || '';
          let webinartoken = clientOpts.webinartoken || '';
          let isdirectsharedesktop = (clientOpts.isdirectsharedesktop === undefined) ? false : clientOpts.isdirectsharedesktop;
          let isvideooff = (clientOpts.isvideooff === undefined) ? false : clientOpts.isvideooff;
          let isaudiooff = (clientOpts.isaudiooff === undefined) ? false : clientOpts.isaudiooff;
          try {
            let JoinWithoutLoginParams = new messages.JoinWithoutLoginParams();
            JoinWithoutLoginParams.setMeetingnumber(Number(meetingnum));
            JoinWithoutLoginParams.setVanityid(vanityid);
            JoinWithoutLoginParams.setUsername(username);
            JoinWithoutLoginParams.setPsw(psw);
            JoinWithoutLoginParams.setHdirectshareappwnd(directshareappwndhandle.toString());
            JoinWithoutLoginParams.setUserzak(userZAK);
            JoinWithoutLoginParams.setParticipantid(participantid);
            JoinWithoutLoginParams.setWebinartoken(webinartoken);
            JoinWithoutLoginParams.setIsdirectsharedesktop(isaudiooff);
            JoinWithoutLoginParams.setIsdirectsharedesktop(isdirectsharedesktop);
            JoinWithoutLoginParams.setIsvideooff(isvideooff);
            JoinWithoutLoginParams.setIsaudiooff(isaudiooff);
            let bytes = JoinWithoutLoginParams.serializeBinary();
            return _addon.Join_WithoutLogin(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
          try {
            let LeaveMeetingParams = new messages.LeaveMeetingParams();
            LeaveMeetingParams.setBend(endMeeting);
            let bytes = LeaveMeetingParams.serializeBinary();
            return _addon.Leave(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
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
       * mode: Get UserInfoByUserID
       * @return {ZoomSDKError}
       */
      HandleZoomWebUriProtocolAction: function (protocol_action) {
        if (_addon) {
          return _addon.HandleZoomWebUriProtocolAction(protocol_action);
        }
        return "";
      },
      GetMeetingInfo: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomMeetingInfo) {
            ZoomMeetingInfo = ZoomMeetingINFOMOD.ZoomMeetingInfo.getInstance(clientOpts);
          }
          return ZoomMeetingInfo;
        }
        return null;
      },
      GetMeetingUICtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingUICtrl) {
            ZoomMeetingUICtrl = ZoomMeetingUIMOD.ZoomMeetingUICtrl.getInstance(clientOpts);
          }
          return ZoomMeetingUICtrl;
        }
      },
      GetAnnotationCtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomAnnotationCtrl) {
            ZoomAnnotationCtrl = ZoomAnnotationMOD.ZoomAnnotationCtrl.getInstance(clientOpts);
          }
          return ZoomAnnotationCtrl;
        }
      },
      GetMeetingAudio: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingAudio) {
            ZoomMeetingAudio = ZoomMeetingAudioMOD.ZoomMeetingAudio.getInstance(clientOpts);
          }
          return ZoomMeetingAudio;
        }
      },
      GetMeetingVideo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingVideo) {
            ZoomMeetingVideo = ZoomMeetingVideoMOD.ZoomMeetingVideo.getInstance(clientOpts);
          }
          return ZoomMeetingVideo
        }
      },
      GetMeetingShare: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingShare) {
            ZoomMeetingShare = ZoomMeetingShareMOD.ZoomMeetingShare.getInstance(clientOpts);
          }
          return ZoomMeetingShare;
        }
      },
      GetMeetingH323: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomH323) {
            ZoomH323 = ZoomMeetingH323MOD.ZoomH323.getInstance(clientOpts);
          }
          return ZoomH323;
        }
      },
      GetMeetingConfiguration: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingConfiguration) {
            ZoomMeetingConfiguration = ZoomMeetingConfigurationMOD.ZoomMeetingConfiguration.getInstance(clientOpts);
          }
          return ZoomMeetingConfiguration;
        }
      },
      GetUpdateAccount: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomPaymentReminder) {
            ZoomPaymentReminder = ZoomUpdateAccountMOD.ZoomPaymentReminder.getInstance(clientOpts);
          }
          return ZoomPaymentReminder;
        }
      },
      GetMeetingParticipantsCtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingParticipantsCtrl) {
            ZoomMeetingParticipantsCtrl = ZoomMeetingParticipantsMOD.ZoomMeetingParticipantsCtrl.getInstance(clientOpts);
          }
          return ZoomMeetingParticipantsCtrl;
        }
      },
      GetMeetingRecording: function(opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          clientOpts.zoommeeting = instance;
          if (!ZoomMeetingRecording) {
            ZoomMeetingRecording = ZoomMeetingRecordingMOD.ZoomMeetingRecording.getInstance(clientOpts);
          }
          return ZoomMeetingRecording;
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
