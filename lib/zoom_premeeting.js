const { ZoomSDKError } = require('./settings.js');
const messages = require('./electron_sdk_pb.js');

/**
*@module
*/
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
    let _onScheduleOrEditMeeting = clientOpts.onScheduleOrEditMeeting || null;
    let _onListMeeting = clientOpts.onListMeeting || null;
    let _onDeleteMeeting = clientOpts.onDeleteMeeting || null;

    function onScheduleOrEditMeeting(result, meetingUniqueID) {
      if (_onScheduleOrEditMeeting) {
        _onScheduleOrEditMeeting(result, meetingUniqueID)
      }
    }

    function onListMeeting(result, meetingList) {
      if (_onListMeeting) {
        _onListMeeting(result, meetingList)
      }
    }

    function onDeleteMeeting(result) {
      if (_onDeleteMeeting) {
        _onDeleteMeeting(result)
      }
    }

    if (_addon) {
      _addon.SetOnScheduleOrEditMeetingCB(onScheduleOrEditMeeting);
      _addon.SetOnListMeetingCB(onListMeeting);
      _addon.SetOnDeleteMeetingCB(onDeleteMeeting);
    }

    return {
      /**
      * mode: Set On Schedule Or Edit Meeting CB
      * @param {Function} onScheduleOrEditMeeting
      * @return {Boolean}
      */
      SetOnScheduleOrEditMeetingCB: function (onScheduleOrEditMeeting) {
        if (_addon && onScheduleOrEditMeeting && onScheduleOrEditMeeting instanceof Function) {
          _onScheduleOrEditMeeting = onScheduleOrEditMeeting;
          return true;
        }
        return false;
      },
      /**
      * mode: Set On List Meeting CB
      * @param {Function} onListMeeting
      * @return {Boolean}
      */
      SetOnListMeetingCB: function (onListMeeting) {
        if (_addon && onListMeeting && onListMeeting instanceof Function) {
          _onListMeeting = onListMeeting;
          return true;
        }
        return false;
      },
      /**
      * mode: Set On Delete Meeting CB
      * @param {Function} onDeleteMeeting
      * @return {Boolean}
      */
      SetOnDeleteMeetingCB: function (onDeleteMeeting) {
        if (_addon && onDeleteMeeting && onDeleteMeeting instanceof Function) {
          _onDeleteMeeting = onDeleteMeeting;
          return true;
        }
        return false;
      },
      /**
      * mode: Schedule Meeting With WndParams
      * @param {String} hSelfWnd SelfWnd (win platform require hexadecimal, mac platform means height)
      * @param {String} hParent parent window handle (win platform require hexadecimal, mac platform means width)
      * @param {String} left chat window left pos
      * @param {String} top chat window top pos
      * @return {ZoomSDKError}
      */
      ScheduleMeetingWithWndParams: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          try {
            let ScheduleMeetingWithWndParams = new messages.ScheduleMeetingWithWndParams();
            ScheduleMeetingWithWndParams.setHselfwnd(hSelfWnd);
            ScheduleMeetingWithWndParams.setHparent(hParent);
            ScheduleMeetingWithWndParams.setLeft(left);
            ScheduleMeetingWithWndParams.setTop(top);
            let bytes = ScheduleMeetingWithWndParams.serializeBinary();
            return _addon.ScheduleMeetingWithWndParams(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Schedule Meeting
      * @return {ZoomSDKError}
      */
      ScheduleMeeting: function (opts) {
        if (_addon) {
          return _addon.ScheduleMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Edit Meeting
      * @param {Number} meetingUniqueID
      * @return {ZoomSDKError}
      */
      EditMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingUniqueID = clientOpts.meetingUniqueID;
          try {
            let EditMeetingParams = new messages.EditMeetingParams();
            EditMeetingParams.setMeetingnumber(Number(meetingUniqueID));
            let bytes = EditMeetingParams.serializeBinary();
            return _addon.EditMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Edit Meeting
      * @return {ZoomSDKError}
      */
      ListMeeting: function (opts) {
        if (_addon) {
          return _addon.ListMeeting();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Edit Meeting
      * @param {Number} meetingUniqueID
      * @return {ZoomSDKError}
      */
      DeleteMeeting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let meetingUniqueID = clientOpts.meetingUniqueID;
          try {
            let DeleteMeetingParams = new messages.DeleteMeetingParams();
            DeleteMeetingParams.setMeetingnumber(Number(meetingUniqueID));
            let bytes = DeleteMeetingParams.serializeBinary();
            return _addon.DeleteMeeting(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * mode: Edit Meeting With Wnd Params
      * @param {String} hSelfWnd (win platform require hexadecimal, mac platform means height)
      * @param {String} hParent (win platform require hexadecimal, mac platform means width)
      * @param {String} left Float Video left pos
      * @param {String} top Float Video pos
      * @param {Number} meetingUniqueID
      * @return {ZoomSDKError}
      */
      EditMeetingWithWndParams: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let hSelfWnd = clientOpts.hSelfWnd || '0';
          let hParent = clientOpts.hParent || '0';
          let left = clientOpts.left || '0';
          let top = clientOpts.top || '0';
          let meetingUniqueID = clientOpts.meetingUniqueID;
          try {
            let EditMeetingWithWndParams = new messages.EditMeetingWithWndParams();
            EditMeetingWithWndParams.setHselfwnd(hSelfWnd);
            EditMeetingWithWndParams.setHparent(hParent);
            EditMeetingWithWndParams.setLeft(left);
            EditMeetingWithWndParams.setTop(top);
            EditMeetingWithWndParams.setMeetingnumber(Number(meetingUniqueID));
            let bytes = EditMeetingWithWndParams.serializeBinary();
            return _addon.EditMeetingWithWndParams(bytes);
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