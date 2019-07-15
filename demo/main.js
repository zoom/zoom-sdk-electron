const { app, BrowserWindow, ipcMain } = require('electron');
const { ZOOM_TYPE_OS_TYPE, ZoomSDK_LANGUAGE_ID, ZoomSDKError, ZoomAuthResult, ZoomLoginStatus, ZoomMeetingStatus, ZoomMeetingUIFloatVideoType } = require('../lib/settings.js');
const ZOOMSDKMOD = require('../lib/zoom_sdk.js');
const os = require('os');
const platform = os.platform();
const arch = os.arch();

const initoptions = {
  apicallretcb: apicallresultcb,
  ostype: ZOOM_TYPE_OS_TYPE.WIN_OS,
}
initoptions.path = platform == 'darwin' ? './../sdk/mac/' : arch == 'x64' ? './../sdk/win64/' : './../sdk/win32/';

const zoomsdk = ZOOMSDKMOD.ZoomSDK.getInstance(initoptions);

let zoomauth = null;
let mainWindow = null;
let loginWindow = null;
let startjoinWindow = null;
let waitingWindow = null;
let inmeetingWindow = null;
let startjoinUnLoginWindow = null;
let domainWindow = null;
let zoommeeting;
let zoominfomod;
let zoomuicontroller;
let zoomannotation;
let zoomaudio;
let zoomshare;
let zoomconfiguration;
let zoomupdateaccount;
let zoomcustomizedresource;
let mymeetinguserid = 0;

function sdkauthCB(status) {
  if (ZoomAuthResult.AUTHRET_SUCCESS == status){
    let opts = {
      meetingstatuscb: meetingstatuscb,
      meetinguserjoincb: meetinguserjoincb,
      meetinguserleftcb: meetinguserleftcb,
      meetinghostchangecb: meetinghostchangecb,
    }
    zoommeeting = zoomsdk.GetMeeting(opts);
    zoominfomod = zoommeeting.GetMeetingInfo();
    zoomuicontroller = zoommeeting.GetMeetingUICtrl();
    zoomannotation = zoommeeting.GetAnnotationCtrl();
    zoomshare = zoommeeting.GetMeetingShare();
    zoomh323 = zoommeeting.GetMeetingH323();
    zoomconfiguration = zoommeeting.GetMeetingConfiguration();
    zoomupdateaccount = zoommeeting.GetUpdateAccount();

    let optsaudio = {
      onUserAudioStatusChange: onUserAudioStatusChange
    }
    zoomaudio = zoommeeting.GetMeetingAudio(optsaudio);
    let optsvideo = {
      onUserVideoStatusChange: onUserVideoStatusChange
    }
    zoomvideo = zoommeeting.GetMeetingVideo(optsvideo);
    zoomsetting = zoomsdk.GetSetting();
    zoomsetgeneral = zoomsetting.GetGeneralSetting();
    zoomsetrecord = zoomsetting.GetRecordingSetting();
    zoomsetvideo = zoomsetting.GetVideoSetting();
    zoomsetaudio = zoomsetting.GetAudioSetting();
    zoomcustomizedresource = zoomsdk.GetCustomizedResource();
    showLoginWindow();
  } else {
    showAuthwindow();
  }
}

function loginretCB(status) {
  switch(status)
  {
    case ZoomLoginStatus.LOGIN_SUCCESS:
      showSatrtJoinWindow();
    break;
    case ZoomLoginStatus.LOGIN_PROCESSING:
      showWaitingWindow();
    break;
    case ZoomLoginStatus.LOGIN_FAILED:
      showLoginWindow();
    break;
    default:
    break;
  }
}

function meetinguserjoincb(useritem) {
  if (useritem.isme == 'true')
    mymeetinguserid = useritem.userid
}

function meetinguserleftcb(userid) {
}

function meetinghostchangecb(userid) {
}

function onUserAudioStatusChange(result) {
  console.log('onUserAudioStatusChange', result);
}

function onUserVideoStatusChange(result) {
  console.log('onUserVideoStatusChange', result);
}

function meetingstatuscb(status, errorcode) {
  switch (status)
  {
    case ZoomMeetingStatus.MEETING_STATUS_CONNECTING:
    case ZoomMeetingStatus.MEETING_STATUS_DISCONNECTING:
    case ZoomMeetingStatus.MEETING_STATUS_RECONNECTING:
      showWaitingWindow();
    break;
    case ZoomMeetingStatus.MEETING_STATUS_INMEETING:
      showInMeetingWindow();
    break
    case ZoomMeetingStatus.MEETING_STATUS_FAILED:
    case ZoomMeetingStatus.MEETING_STATUS_ENDED:
      showSatrtJoinWindow();
    break;
    default:
    break;
  }
}

function showWaitingWindow() {
  if (!waitingWindow)
  {
    waitingWindow = new BrowserWindow({ width: 700, height: 400,
      webPreferences: {
        nodeIntegration: true
      }
    });
    waitingWindow.loadURL('file://' + __dirname + '/pages/waiting.html');
  }
  if (mainWindow){
    mainWindow.close();
    mainWindow = null;
  }
  if (loginWindow){
    loginWindow.close();
    loginWindow = null;
  }
  if (startjoinWindow){
    startjoinWindow.close();
    startjoinWindow = null;
  }
  if (inmeetingWindow){
    inmeetingWindow.close();
    inmeetingWindow = null;
  }
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function showInMeetingWindow(){
  if (!inmeetingWindow)
  {
    inmeetingWindow = new BrowserWindow({ width: 700, height: 400,
      webPreferences: {
        nodeIntegration: true
      } 
    });
    inmeetingWindow.loadURL('file://' + __dirname + '/pages/inmeeting.html');
  }
  if (mainWindow){
    mainWindow.close();
    mainWindow = null;
  }
  if (loginWindow){
    loginWindow.close();
    loginWindow = null;
  }
  if (startjoinWindow){
    startjoinWindow.close();
    startjoinWindow = null;
  }
  if (waitingWindow){
    waitingWindow.close();
    waitingWindow = null;
  }
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function showDomainwindow(){
  if (!domainWindow)
  {
    domainWindow = new BrowserWindow({ 
      width: 700, 
      height: 400, 
      webPreferences: {
        nodeIntegration: true
      } 
    });
    domainWindow.loadURL('file://' + __dirname + '/pages/domain.html');
  }
  if (mainWindow) {
    mainWindow.close();
    mainWindow = null;
  }
  if (loginWindow) {
    loginWindow.close();
    loginWindow = null;
  }
  if (startjoinWindow) {
    startjoinWindow.close();
    startjoinWindow = null;
  }
  if (waitingWindow) {
    waitingWindow.close();
    waitingWindow = null;
  }
  if (inmeetingWindow) {
    inmeetingWindow.close();
    inmeetingWindow = null;
  }
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
}

function showAuthwindow(){
  if (!mainWindow)
  {
    mainWindow = new BrowserWindow({ 
      width: 700, 
      height: 400, 
      webPreferences: {
        nodeIntegration: true
      } 
    });
    mainWindow.loadURL('file://' + __dirname + '/pages/index.html');
  }
  if (loginWindow){
    loginWindow.close();
    loginWindow = null;
  }
  if (startjoinWindow){
    startjoinWindow.close();
    startjoinWindow = null;
  }
  if (waitingWindow){
    waitingWindow.close();
    waitingWindow = null;
  }
  if (inmeetingWindow){
    inmeetingWindow.close();
    inmeetingWindow = null;
  }
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function showLoginWindow(){
  if (!loginWindow)
  {
    loginWindow = new BrowserWindow({ width: 700, height: 400,
      webPreferences: {
        nodeIntegration: true
      }  
    });
    loginWindow.loadURL('file://' + __dirname + '/pages/login.html');
  }
  if (mainWindow){
    mainWindow.close();
    mainWindow = null;
  }
  if (startjoinWindow){
    startjoinWindow.close();
    startjoinWindow = null;
  }
  if (waitingWindow){
    waitingWindow.close();
    waitingWindow = null;
  }
  if (inmeetingWindow){
    inmeetingWindow.close();
    inmeetingWindow = null;
  }
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function showSatrtJoinWindow(){
  if (!startjoinWindow)
  {
    startjoinWindow = new BrowserWindow({ width: 700, height: 400,
      webPreferences: {
        nodeIntegration: true
      } 
    });
    startjoinWindow.loadURL('file://' + __dirname + '/pages/start_join.html'); 
  }
  if (mainWindow){
    mainWindow.close();
    mainWindow = null;
  }
  if (loginWindow){
    loginWindow.close();
    loginWindow = null;
  }
  if (waitingWindow){
    waitingWindow.close();
    waitingWindow = null;
  }
  if (inmeetingWindow){
    inmeetingWindow.close();
    inmeetingWindow = null;
  }
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function ProcSDKReady(){
  showAuthwindow()
  var options={
    authcb: sdkauthCB,
    logincb: loginretCB,
    logoutcb: null
  }
  zoomauth = zoomsdk.GetAuth(options)
}

function apicallresultcb(apiname, ret) {
  if ('InitSDK' == apiname && ZoomSDKError.SDKERR_SUCCESS == ret){
    ProcSDKReady()
  } else if ('CleanUPSDK' == apiname) {
    app.quit();
  }
}

let functionObj = {
  showSatrtJoinUnLoginWindow: function() {
    if (!startjoinUnLoginWindow) {
      startjoinUnLoginWindow = new BrowserWindow({ width: 700, height: 400,
        webPreferences: {
          nodeIntegration: true
        } 
      });
      startjoinUnLoginWindow.loadURL('file://' + __dirname + '/pages/start_join_without_login.html'); 
    }
    if (startjoinWindow)
    {
      startjoinWindow.close();
      startjoinWindow = null; 
    }
    if (mainWindow){
      mainWindow.close();
      mainWindow = null;
    }
    if (loginWindow){
      loginWindow.close();
      loginWindow = null;
    }
    if (waitingWindow){
      waitingWindow.close();
      waitingWindow = null;
    }
    if (inmeetingWindow){
      inmeetingWindow.close();
      inmeetingWindow = null;
    }
    if (domainWindow) {
      domainWindow.close();
      domainWindow = null;
    }
  },
  setDomain: function(domain, enable_log) {
    const opts = {
      path: '', // win require absolute path, mac require ''
      domain: domain,
      enable_log: enable_log,
      langid: ZoomSDK_LANGUAGE_ID.LANGUAGE_English
    }
    var ret = zoomsdk.InitSDK(opts);
    if (ZoomSDKError.SDKERR_SUCCESS == ret){
      ProcSDKReady();
    }
  },
  sdkauth: function(appkey, appsecret){
    zoomauth.SDKAuth(appkey, appsecret);
    showWaitingWindow();
  },
  login: function(username, psw) {
    if (username && psw) {
      showWaitingWindow();
    }
    zoomauth.Login(username, psw, false);
  },
  loginWithSSOToken: function(ssotoken) {
    let ret = zoomauth.LoginWithSSOToken(ssotoken);
    console.log('LoginWithSSOToken', ret);
  },
  logout: function() {
    zoomauth.Logout();
    showLoginWindow();
  },
  start: function(meetingnum){
    var opt = {
      meetingnum: meetingnum
    }
    let ret = zoommeeting.StartMeeting(opt);
    console.log('StartMeeting', ret);
  }, 
  join: function(meetingnum, username) {
    var opt = {
      meetingnum: meetingnum,
      username: username
    }
    zoommeeting.JoinMeeting(opt);
  },
  startunlogin: function(meetingnum){
    var opt = {
      meetingnum: meetingnum
    }
    let ret = zoommeeting.StartMeetingWithOutLogin(opt);
    console.log('StartMeetingWithOutLogin', ret);
  },
  joinunlogin: function(meetingnum, username) {
    var opt = {
      meetingnum: meetingnum,
      username: username
    }
    zoommeeting.JoinMeetingWithoutLogin(opt);
  },
  leave: function(endMeeting) {
    var opt = {
      endMeeting: endMeeting
    }
    zoommeeting.LeaveMeeting(opt);
  },
  end: function(endMeeting) {
    var opt = {
      endMeeting: endMeeting
    }
    zoommeeting.LeaveMeeting(opt);
  },
  lock: function() {
    let ret = zoommeeting.Lock_Meeting();
    console.log('Lock_Meeting', ret);
  },
  unlock: function() {
    let ret = zoommeeting.Un_lock_Meeting();
    console.log('Un_lock_Meeting', ret);
  },
  getSharingConnQuality: function() {
    let ret = zoommeeting.GetSharingConnQuality();
    console.log('GetSharingConnQuality', ret);
    return ret;
  },
  getVideoConnQuality: function() {
    let ret = zoommeeting.GetVideoConnQuality();
    console.log('GetVideoConnQuality', ret);
    return ret;
  },
  getAudioConnQuality: function() {
    let ret = zoommeeting.GetAudioConnQuality();
    console.log('GetAudioConnQuality', ret);
    return ret;
  },
  getMeetingTopic: function() {
    let ret = zoominfomod.GetMeetingTopic();
    console.log('GetMeetingTopic', ret);
    return ret;
  },
  getMeetingType: function () {
    let ret = zoominfomod.GetMeetingType();
    console.log('GetMeetingType', ret);
    return ret;
  },
  getMeetingNumber: function () {
    let ret = zoominfomod.GetMeetingNumber();
    console.log('GetMeetingNumber', ret);
    return ret;
  },
  getMeetingID: function() {
    let ret = zoominfomod.GetMeetingID();
    console.log('GetMeetingID', ret);
    return ret;
  },
  getInviteEmailTeamplate: function() {
    let ret = zoominfomod.GetInviteEmailTeamplate();
    console.log('GetInviteEmailTeamplate', ret);
    return ret;
  },
  getInviteEmailTitle: function() {
    let ret = zoominfomod.GetInviteEmailTitle();
    console.log('GetInviteEmailTitle', ret);
    return ret;
  },
  getJoinMeetingUrl: function() {
    let ret = zoominfomod.GetJoinMeetingUrl();
    console.log('GetJoinMeetingUrl', ret);
    return ret;
  },
  getMeetingHostTag: function() {
    let ret = zoominfomod.GetMeetingHostTag();
    console.log('GetMeetingHostTag', ret);
    return ret;
  },
  checkingIsInternalMeeting: function() {
    let ret = zoominfomod.CheckingIsInternalMeeting();
    console.log('CheckingIsInternalMeeting', ret);
    return ret;
  },
  showChat: function() {
    let opts = {
      left: '200',
      top: '200'
    }
    zoomuicontroller.MeetingUI_ShowChatDlg(opts);
  },
  hideChat: function() {
    zoomuicontroller.MeetingUI_HideChatDlg();
  },
  enterFullscreen: function() {
    var opts = {
      bFirstView: '1',
      bSecView: '0'
    }
    zoomuicontroller.MeetingUI_EnterFullScreen(opts);
  },
  exitFullScreen: function() {
    var opts = {
      bFirstView: '1',
      bSecView: '0'
    }
    zoomuicontroller.MeetingUI_ExitFullScreen(opts);
  },
  switchToVideoWall: function() {
    let ret = zoomuicontroller.MeetingUI_SwitchToVideoWall();
    console.log('SwitchToVideoWall', ret);
  },
  swtichToAcitveSpeaker: function() {
    let ret = zoomuicontroller.MeetingUI_SwtichToAcitveSpeaker();
    console.log('SwtichToAcitveSpeaker', ret);
  },
  moveFloatVideoWnd: function() {
    let opts = {
      left: '200',
      top: '200'
    }
    let ret = zoomuicontroller.MeetingUI_MoveFloatVideoWnd(opts);
    console.log('MoveFloatVideoWnd', ret);
  },
  showSharingToolbar: function(show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowSharingToolbar(opts);
    console.log('ShowSharingToolbar', ret);
  },
  switchFloatVideoToActiveSpkMod: function() {
    let ret = zoomuicontroller.MeetingUI_SwitchFloatVideoToActiveSpkMod();
    console.log('SwitchFloatVideoToActiveSpkMod', ret);
  },
  changeFloatoActiveSpkVideoSize: function() {
    console.log('ZoomMeetingUIFloatVideoType', ZoomMeetingUIFloatVideoType.FLOATVIDEO_Large);
    let obj = {
      floatvideotype: ZoomMeetingUIFloatVideoType.FLOATVIDEO_Large
    }
    let ret = zoomuicontroller.MeetingUI_ChangeFloatoActiveSpkVideoSize(obj);
    console.log('ChangeFloatoActiveSpkVideoSize', ret);
  },
  switchFloatVideoToGalleryMod: function() {
    let ret = zoomuicontroller.MeetingUI_SwitchFloatVideoToGalleryMod();
    console.log('switchFloatVideoToGalleryMod', ret);
  },
  showParticipantsListWnd: function(show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowParticipantsListWnd(opts);
    console.log('ShowParticipantsListWnd', ret);
  },
  showBottomFloatToolbarWnd: function (show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowBottomFloatToolbarWnd(opts);
    console.log('ShowBottomFloatToolbarWnd', ret);
  },
  showJoinAudioDlg: function() {
    let ret = zoomuicontroller.MeetingUI_ShowJoinAudioDlg();
    console.log('ShowJoinAudioDlg', ret);
  },
  hideJoinAudioDlg: function() {
    let ret = zoomuicontroller.MeetingUI_HideJoinAudioDlg();
    console.log('HideJoinAudioDlg', ret);
  },
  getWallViewPageInfo: function(arg2, arg3) {
    let opts = {
      currentPage: arg2,
      totalPages: arg3
    }
    let ret = zoomuicontroller.MeetingUI_GetWallViewPageInfo(opts);
    console.log('GetWallViewPageInfo', ret);
  },
  showPreOrNextPageVideo: function(show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowPreOrNextPageVideo(opts);
    console.log('ShowPreOrNextPageVideo', ret);
    return ret;
  },
  showSharingFrameWindows: function(show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowSharingFrameWindows(opts);
    console.log('ShowSharingFrameWindows', ret);
    return ret;
  },
  switchSplitScreenMode: function (isSwitch) {
    console.log('isSwitch', isSwitch);
    let opts = {
      isSwitch: isSwitch
    }
    let ret = zoomuicontroller.MeetingUI_SwitchSplitScreenMode(opts);
    console.log('SwitchSplitScreenMode', ret);
    return ret;
  },
  getCurrentSplitScreenModeInfo: function(arg2, arg3) {
    let opts = {
      bZNSupportSplitScreen: arg2,
      bZNInSplitScreenMode: arg3
    }
    let ret = zoomuicontroller.MeetingUI_GetCurrentSplitScreenModeInfo(opts);
    console.log('GetCurrentSplitScreenModeInfo', ret);
    return ret;
  },
  isAnnotaionDisable: function() {
    let ret = zoomannotation.Annotaion_IsAnnotaionDisable();
    console.log('IsAnnotaionDisable', ret);
    return ret;
  },
  startAnnotation: function(viewtype, left, top) {
    let opts = {
      viewtype: viewtype,
      left: '300',
      top: '300'
    }
    let ret = zoomannotation.Annotaion_StartAnnotation(opts);
    console.log('StartAnnotation', ret);
  },
  stopAnnotation: function(viewtype) {
    let ret = zoomannotation.Annotaion_StopAnnotation(viewtype);
    console.log('StopAnnotation', ret);
  },
  setTool: function(viewtype, tooltype) {
    let opts = {
      viewtype: viewtype,
      tooltype: tooltype
    }
    let ret = zoomannotation.Annotaion_SetTool(opts);
    console.log('SetTool', ret);
  },
  setClear: function(viewtype, cleartype) {
    let opts = {
      viewtype: viewtype,
      cleartype: cleartype
    }
    let ret = zoomannotation.Annotaion_Clear(opts);
    console.log('Clear', ret);
  },
  setColor: function(viewtype, color) {
    let opts = {
      viewtype: viewtype,
      color: color
    }
    let ret = zoomannotation.Annotaion_SetColor(opts);
    console.log('SetColor', ret);
  },
  SetLineWidth: function(viewtype, lineWidth) {
    let opts = {
      viewtype: viewtype,
      lineWidth: lineWidth
    }
    let ret = zoomannotation.Annotaion_SetLineWidth(opts);
    console.log('SetLineWidth', ret);
  },
  undo: function(viewtype) {
    let opts = {
      viewtype: viewtype
    }
    let ret = zoomannotation.Annotaion_Undo(opts)
    console.log('Undo', ret);
  },
  redo: function(viewtype) {
    let opts = {
      viewtype: viewtype
    }
    let ret = zoomannotation.Annotaion_Redo(opts)
    console.log('Redo', ret);
  },
  muteAudio: function(userid) {
    let opts = {
      userid: userid,
      allowunmutebyself: false
    }
    let ret = zoomaudio.MeetingAudio_MuteAudio(opts);
    console.log('MuteAudio', ret);
  },
  unMuteAudio: function(userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomaudio.MeetingAudio_UnMuteAudio(opts);
    console.log('UnMuteAudio', ret);
  },
  joinVoip: function() {
    let ret = zoomaudio.MeetingAudio_JoinVoip();
    console.log('JoinVoip', ret);
  },
  leaveVoip: function() {
    let ret = zoomaudio.MeetingAudio_LeaveVoip();
    console.log('LeaveVoip', ret);
  },
  muteVideo: function() {
    let ret = zoomvideo.MeetingVideo_MuteVideo();
    console.log('MuteVideo', ret);
  },
  unMuteVideo: function () {
    let ret = zoomvideo.MeetingVideo_UnMuteVideo();
    console.log('UnMuteVideo', ret);
  },
  pinVideo: function(userid) {
    let opts = {
      bPin: true,
      bFirstView: true,
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_PinVideo(opts);
    console.log('PinVideo', ret);
  },
  spotlightVideo: function(userid) {
    let opts = {
      bSpotlight: true,
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_SpotlightVideo(opts);
    console.log('SpotlightVideo', ret);
  },
  hideOrShowNoVideoUserOnVideoWall: function(bHide) {
    let opts = {
      bHide: bHide
    }
    let ret = zoomvideo.MeetingVideo_HideOrShowNoVideoUserOnVideoWall(opts);
    console.log('HideOrShowNoVideoUserOnVideoWall', ret);
  },
  selectCamera: function (zn_deviceId) {
    let opts = {
      zn_deviceId: zn_deviceId
    }
    let ret = zoomsetvideo.Setting_SelectVideoCamera(opts);
    console.log('SelectCamera', ret);
  },
  getCameraList: function() {
    let ret = zoomsetvideo.Setting_GetCameraList();
    console.log('GetCameraList', ret);
  },
  enableVideoMirrorEffect: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetvideo.Setting_EnableVideoMirrorEffect(opts);
    console.log('EnableVideoMirrorEffect', ret);
  },
  enableFaceBeautyEffect: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetvideo.Setting_EnableFaceBeautyEffect(opts);
    console.log('EnableFaceBeautyEffect', ret);
  },
  isMirrorEffectEnabled: function() {
    let ret = zoomsetvideo.Checking_IsMirrorEffectEnabled();
    console.log('IsMirrorEffectEnabled', ret);
  },
  isFaceBeautyEffectEnabled: function() {
    let ret = zoomsetvideo.Checking_IsFaceBeautyEffectEnabled();
    console.log('IsFaceBeautyEffectEnabled', ret);
  },
  getMicList: function() {
    zoomsetaudio.Setting_GetMicList();
    // console.log('GetMicList', ret);
  },
  selectMic: function(zn_deviceId, zn_deviceName) {
    let opts = {
      zn_deviceId: zn_deviceId,
      zn_deviceName: zn_deviceName
    }
    let ret = zoomsetaudio.Setting_SelectMic(opts);
    console.log('SelectMic', ret);
  },
  selectSpeaker: function(zn_deviceId, zn_deviceName) {
    let opts = {
      zn_deviceId: zn_deviceId,
      zn_deviceName: zn_deviceName
    }
    let ret = zoomsetaudio.Setting_SelectSpeaker(opts);
    console.log('SelectSpeaker', ret);
  },
  getSpeakerList: function() {
    let ret = zoomsetaudio.Setting_GetSpeakerList();
    // console.log('GetSpeakerList', ret);
  },
  isAutoJoinAudioEnabled: function() {
    let ret = zoomsetaudio.Checking_IsAutoJoinAudioEnabled();
    console.log('IsAutoJoinAudioEnabled', ret);
  },
  isAutoAdjustMicEnabled: function() {
    let ret = zoomsetaudio.Checking_IsAutoAdjustMicEnabled();
    console.log('IsAutoAdjustMicEnabled', ret);
  },
  enableAutoJoinAudio: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAutoJoinAudio(opts);
    console.log('EnableAutoJoinAudio', ret);
  },
  enableAutoAdjustMic: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAutoAdjustMic(opts);
    console.log('EnableAutoAdjustMic', ret);
  },
  showSettingDlg: function() {
    let ret = zoomsetting.SettingUI_ShowTheSettingDlg();
    console.log('ShowSettingDlg', ret);
  },
  hideSettingDlg: function() {
    let ret = zoomsetting.SettingUI_HideSettingDlg();
    console.log('HideSettingDlg', ret);
  },
  enableDualScreenMode: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableDualScreenMode(opts);
    console.log('EnableDualScreenMode', ret);
  },
  turnOffAeroModeInSharing: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_TurnOffAeroModeInSharing(opts);
    console.log('TurnOffAeroModeInSharing', ret);
  },
  enableAutoFitToWindowWhenViewSharing: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFitToWindowWhenViewSharing(opts);
    console.log('EnableAutoFitToWindowWhenViewSharing', ret);
  },
  enableAutoFullScreenVideoWhenJoinMeeting: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFullScreenVideoWhenJoinMeeting(opts);
    console.log('EnableAutoFullScreenVideoWhenJoinMeeting', ret);
  },
  enableSplitScreenMode: function(zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableSplitScreenMode(opts);
    console.log('EnableSplitScreenMode', ret);
  },
  isDualScreenModeEnabled: function() {
    let ret = zoomsetgeneral.Checking_IsDualScreenModeEnabled();
    console.log('IsDualScreenModeEnabled', ret);
  },
  isAeroModeInSharingTurnOff: function() {
    let ret = zoomsetgeneral.Checking_IsAeroModeInSharingTurnOff();
    console.log('IsAeroModeInSharingTurnOff', ret);
  },
  isAutoFitToWindowWhenViewSharingEnabled: function() {
    let ret = zoomsetgeneral.Checking_IsAutoFitToWindowWhenViewSharingEnabled();
    console.log('IsAutoFitToWindowWhenViewSharingEnabled', ret);
  },
  isAutoFullScreenVideoWhenJoinMeetingEnabled: function() {
    let ret = zoomsetgeneral.Checking_IsAutoFullScreenVideoWhenJoinMeetingEnabled();
    console.log('isAutoFullScreenVideoWhenJoinMeetingEnabled', ret);
  },  
  isSplitScreenModeEnabled: function() {
    let ret = zoomsetgeneral.Checking_IsSplitScreenModeEnabled();
    console.log('IsSplitScreenModeEnabled', ret);
  },
  setRecordingPath: function(zn_szPath) {
    let opts = {
      zn_szPath: zn_szPath
    }
    let ret = zoomsetrecord.Setting_SetRecordingPath(opts);
    console.log('SetRecordingPath', ret);
  },
  getRecordingPath: function() {
    let ret = zoomsetrecord.Getting_GetRecordingPath();
    console.log('GetRecordingPath', ret);
  },
  startAppShare: function(zn_hShare_app) {
    let opts = {
      zn_hShare_app: zn_hShare_app
    }
    let ret = zoomshare.MeetingShare_StartAppShare(opts);
    console.log('StartAppShare', ret);
  },
  startMonitorShare: function(zn_monitorID) {
    let opts = {
      zn_monitorID: zn_monitorID
    }
    let ret = zoomshare.MeetingShare_StartMonitorShare(opts);
    console.log('StartMonitorShare', ret);
  },
  stopShare: function() {
    let ret = zoomshare.MeetingShare_StopShare();
    console.log('StopShare', ret);
  },
  callOutH323: function() {
    let opts = {
      'deviceName': 'xxx',
      'deviceIP': '1234',
      'deviceE164num': '1234',
      'type': 1
    }
    let ret = zoomh323.H323_CallOutH323(opts);
    console.log('CallOutH323', ret);
  },
  cancelCallOutH323: function() {
    let ret = zoomh323.H323_CancelCallOutH323();
    console.log('CancelCallOutH323', ret);
  },
  getH323Address: function() {
    let ret = zoomh323.H323_GetH323Address();
    console.log('GetH323Address', ret);
  },
  getH323Password: function() {
    let ret = zoomh323.H323_GetH323Password();
    console.log('GetH323Password', ret);
  },
  getCalloutH323DeviceList: function() {
    let ret = zoomh323.H323_GetCalloutH323DeviceList();
    console.log('GetCalloutH323DeviceList', ret);
  },
  enableInviteButtonOnMeetingUI: function(bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInviteButtonOnMeetingUI(opts);
    console.log('EnableInviteButtonOnMeetingUI', ret);
  },
  setFloatVideoPos: function() {
    let opts = {
      left: '10',
      top: '10'
    }
    let ret = zoomconfiguration.MeetingConfig_SetFloatVideoPos(opts);
    console.log('SetFloatVideoPos', ret);
  },
  setBottomFloatToolbarWndVisibility: function(bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetBottomFloatToolbarWndVisibility(opts);
    console.log('SetBottomFloatToolbarWndVisibility', ret);
  },
  setSharingToolbarVisibility: function(bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetSharingToolbarVisibility(opts);
    console.log('SetSharingToolbarVisibility', ret);
  },
  setDirectShareMonitorID: function(monitorID) {
    let opts = {
      monitorID: monitorID
    }
    let ret = zoomconfiguration.MeetingConfig_SetDirectShareMonitorID(opts);
    console.log('SetDirectShareMonitorID', ret);
  },
  setMeetingUIPos: function() {
    let opts = {
      left: '10',
      top: '10'
    }
    let ret = zoomconfiguration.MeetingConfig_SetMeetingUIPos(opts);
    console.log('SetMeetingUIPos', ret);
  },
  disableWaitingForHostDialog: function(bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableWaitingForHostDialog(opts);
    console.log('DisableWaitingForHostDialog', ret);
  },
  hideMeetingInfoFromMeetingUITitle: function(bHide) {
    let opts = {
      bHide: bHide
    }
    let ret = zoomconfiguration.MeetingConfig_HideMeetingInfoFromMeetingUITitle(opts);
    console.log('HideMeetingInfoFromMeetingUITitle', ret);
  },
  setMeetingIDForMeetingUITitle: function(meetingNumber) {
    let opts = {
      meetingNumber: meetingNumber
    }
    let ret = zoomconfiguration.MeetingConfig_SetMeetingIDForMeetingUITitle(opts);
    console.log('SetMeetingIDForMeetingUITitle', ret);
  },
  disablePopupMeetingWrongPSWDlg: function(bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisablePopupMeetingWrongPSWDlg(opts);
    console.log('DisablePopupMeetingWrongPSWDlg', ret);
  },
  enableAutoEndOtherMeetingWhenStartMeeting: function(bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoEndOtherMeetingWhenStartMeeting(opts);
    console.log('EnableAutoEndOtherMeetingWhenStartMeeting', ret);
  },
  enableLButtonDBClick4SwitchFullScreenMode: function(bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLButtonDBClick4SwitchFullScreenMode(opts);
    console.log('EnableLButtonDBClick4SwitchFullScreenMode', ret);
  },
  setFloatVideoWndVisibility: function(bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetFloatVideoWndVisibility(opts);
    console.log('SetFloatVideoWndVisibility', ret);
  },
  prePopulateWebinarRegistrationInfo: function(email, userName) {
    let opts = {
      email: email,
      userName: userName
    }
    let ret = zoomconfiguration.MeetingConfig_PrePopulateWebinarRegistrationInfo(opts);
    console.log('PrePopulateWebinarRegistrationInfo', ret);
  },
  getReminderType: function() {
    let ret = zoomupdateaccount.MeetingConfig_GetReminderType();
    console.log('GetReminderType', ret);
  },
  upgradeMeeting: function() {
    let ret = zoomupdateaccount.MeetingConfig_UpgradeMeeting();
    console.log('UpgradeMeeting', ret);
  },
  upgradeAccount: function() {
    let ret = zoomupdateaccount.MeetingConfig_UpgradeAccount();
    console.log('UpgradeAccount', ret);
  },
  cancelUpdate: function() {
    let ret = zoomupdateaccount.MeetingConfig_CancelUpdate();
    console.log('CancelUpdate', ret);
  },
  setFreeMeetingNeedToUpgradeCB: function() {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingNeedToUpgradeCB();
    console.log('SetFreeMeetingNeedToUpgradeCB', ret);
  },
  setFreeMeetingUpgradeToGiftFreeTrialStartCB: function() {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStartCB();
    console.log('SetFreeMeetingUpgradeToGiftFreeTrialStartCB', ret);
  },
  setFreeMeetingUpgradeToGiftFreeTrialStopCB: function() {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStopCB();
    console.log('SetFreeMeetingUpgradeToGiftFreeTrialStopCB', ret);
  },
  setFreeMeetingUpgradeToProMeetingCB: function() {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
    console.log('SetFreeMeetingUpgradeToProMeetingCB', ret);
  },
  setFreeMeetingUpgradeToProMeetingCB: function() {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
    console.log('SetFreeMeetingUpgradeToProMeetingCB', ret);
  },
  addCustomizedPictureResource: function(strPNGID, strPNGPath) {
    let opts = {
      strPNGID: strPNGID,
      strPNGPath: strPNGPath
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedPictureResource(opts);
    console.log('AddCustomizedPictureResource', ret);
  },
  addCustomizedStringResource: function(CustomizedStringType, strCustomizedString) {
    let opts = {
      CustomizedStringType: CustomizedStringType,
      strCustomizedString: strCustomizedString
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedStringResource(opts);
    console.log('AddCustomizedStringResource', ret);
  },
  addCustomizedURLResource: function(CustomizedURLType, strCustomizeURL) {
    let opts = {
      CustomizedURLType: CustomizedURLType,
      strCustomizeURL: strCustomizeURL
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedURLResource(opts);
    console.log('AddCustomizedURLResource', ret);
  }
}

ipcMain.on('asynchronous-message', (event, arg1, arg2, arg3) => {
  functionObj[arg1](arg2, arg3);
})

app.on('window-all-closed', function () {
  if (process.platform != 'darwin') {
    zoomsdk.CleanUPSDK();
    app.quit();
  }
});

function createWindow () {
  // Create the browser window.
  showDomainwindow();
}

app.on('ready', createWindow)