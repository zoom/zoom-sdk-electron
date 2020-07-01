const { app, BrowserWindow, ipcMain, nativeTheme } = require('electron');
const { ZOOM_TYPE_OS_TYPE, ZoomSDK_LANGUAGE_ID, ZoomSDKError, ZoomAuthResult, ZoomLoginStatus, ZoomMeetingStatus,
  ZoomMeetingUIFloatVideoType, SDKCustomizedStringType, SDKCustomizedURLType, ZoomAPPLocale } = require('../lib/settings.js');
const ZOOMSDKMOD = require('../lib/zoom_sdk.js');
const os = require('os');
const platform = os.platform();
const arch = os.arch();

const initoptions = {
  apicallretcb: apicallresultcb,
  ostype: ZOOM_TYPE_OS_TYPE.WIN_OS,
}
initoptions.path = platform == 'darwin' ? './../sdk/mac/' : arch == 'x64' ? './../sdk/win64/' : './../sdk/win32/';

if (platform == 'darwin' && nativeTheme) {
  nativeTheme.themeSource = 'light';
}

const zoomsdk = ZOOMSDKMOD.ZoomSDK.getInstance(initoptions);
let zoomauth = null;
let mainWindow = null;
let loginWindow = null;
let startjoinWindow = null;
let waitingWindow = null;
let inmeetingWindow = null;
let startjoinUnLoginWindow = null;
let domainWindow = null;
let YUVWindow = null;
let zoommeeting;
let zoominfomod;
let zoomuicontroller;
let zoomannotation;
let zoomaudio;
let zoomshare;
let zoomdirectshare;
let zoomconfiguration;
let zoomupdateaccount;
let zoomparticipantsctrl;
let zoomcustomizedresource;
let zoompremeeting;
let zoomvideorawdata;
let zoomsharerawdata;
let zoomaudiorawdata;
let zoomsms;
let zoomsetui;
let zoomsetstatistic;
let zoomsetaccessibility;
let hasRDLicense;
let autoCloseYUV = false;
let hasLogin = false;

function sdkauthCB(status) {
  if (ZoomAuthResult.AUTHRET_SUCCESS == status) {
    hasRDLicense = hasRawDataLicense();
    global.hasRDLicense = hasRDLicense;
    let opts = {
      meetingstatuscb: meetingstatuscb,
      meetinguserjoincb: meetinguserjoincb,
      meetinguserleftcb: meetinguserleftcb,
      meetinghostchangecb: meetinghostchangecb,
    }
    zoommeeting = zoomsdk.GetMeeting(opts);
    app.zoommeeting = zoommeeting;
    zoomparticipantsctrl = zoommeeting.GetMeetingParticipantsCtrl(opts);
    app.zoomparticipantsctrl = zoomparticipantsctrl;
    zoomvideorawdata = zoomsdk.VideoRawData();
    zoomaudiorawdata = zoomsdk.AudioRawData();
    zoomsharerawdata = zoomsdk.ShareRawData();
    app.zoomvideorawdata = zoomvideorawdata;
    app.zoomsharerawdata = zoomsharerawdata;
    app.zoomaudiorawdata = zoomaudiorawdata;
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
    app.zoomvideo = zoomvideo;
    zoomsetting = zoomsdk.GetSetting();
    zoomsetgeneral = zoomsetting.GetGeneralSetting();
    zoomsetrecord = zoomsetting.GetRecordingSetting();
    zoomsetvideo = zoomsetting.GetVideoSetting();
    zoomsetaudio = zoomsetting.GetAudioSetting();
    zoomsetui = zoomsetting.GetSettingUICtrl();
    zoomsetstatistic = zoomsetting.GetSettingStatisticCtrl();
    zoomsetaccessibility = zoomsetting.GetSettingAccessibilityCtrl();
    zoomcustomizedresource = zoomsdk.GetCustomizedResource();
    zoompremeeting = zoomsdk.PreMeeting();
    zoomsms = zoomsdk.SMSHelper();
    zoomdirectshare = zoomauth.GetDirectShare();
    showLoginWindow();
  } else {
    showAuthwindow();
  }
}

function loginretCB(status) {
  hasLogin = false;
  switch (status) {
    case ZoomLoginStatus.LOGIN_SUCCESS:
      hasLogin = true;
      showStartJoinWindow();
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
  console.log('meetinguserjoincb', useritem)
}

function meetinguserleftcb(userList) {
}

function meetinghostchangecb(userList) {
}

function onUserAudioStatusChange(result) {
  console.log('onUserAudioStatusChange', result);
}

function onUserVideoStatusChange(result) {
  console.log('onUserVideoStatusChange', result);
}

function meetingstatuscb(status, result) {
  console.log('meetingstatus', status, result);
  switch (status) {
    case ZoomMeetingStatus.MEETING_STATUS_CONNECTING:
      YUVWindow ? YUVWindow.webContents.send('main-process-meetingstatus', 'connecting') : null;
      break;
    case ZoomMeetingStatus.MEETING_STATUS_DISCONNECTING:
    case ZoomMeetingStatus.MEETING_STATUS_RECONNECTING:
      showWaitingWindow();
      break;
    case ZoomMeetingStatus.MEETING_STATUS_INMEETING:
      showInMeetingWindow();
      YUVWindow ? YUVWindow.webContents.send('main-process-meetingstatus', 'inmeeting') : null;
      break
    case ZoomMeetingStatus.MEETING_STATUS_FAILED:
    case ZoomMeetingStatus.MEETING_STATUS_ENDED:
      if (hasLogin) {
        showStartJoinWindow();
      } else {
        showLoginWindow();
      }
      break;
    default:
      break;
  }
}

function showWaitingWindow() {
  if (!waitingWindow) {
    waitingWindow = new BrowserWindow({
      width: 700, height: 400,
      webPreferences: {
        nodeIntegration: true
      }
    });
    waitingWindow.loadURL('file://' + __dirname + '/pages/waiting.html');
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
  if (inmeetingWindow) {
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
  if (YUVWindow) {
    autoCloseYUV = true;
    YUVWindow.close();
    YUVWindow = null;
  }
}

function showInMeetingWindow() {
  if (!inmeetingWindow) {
    inmeetingWindow = new BrowserWindow({
      width: 700, height: 400, x: YUVWindow ? 10 : null, y: YUVWindow ? 10 : null,
      webPreferences: {
        nodeIntegration: true
      }
    });
    inmeetingWindow.on('close', () => {
      inmeetingWindow = null;
    });
    inmeetingWindow.loadURL('file://' + __dirname + '/pages/inmeeting.html');
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
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function clearSetCallBack() {
  zoomparticipantsctrl.SetMeetingUserJoinCB(null);
  zoomparticipantsctrl.SetMeetingUserLeftCB(null);
  zoomparticipantsctrl.SetMeetingHostChangeCB(null);
  zoomvideorawdata.SetRawDataVideoUserDataOffCB(null);
  zoomvideorawdata.SetRawDataVideoUserLeftCB(null);
  zoomvideorawdata.SetRawDataVideoUserDataOnCB(null);
  zoomvideo.SetMeetingVideoStatusCB(null);
  zoomvideorawdata.SetRawDataCB(null);
  zoomsharerawdata.SetRawDataShareUserDataOnCB(null);
  zoomsharerawdata.SetRawDataShareUserDataOffCB(null);
  zoomsharerawdata.SetRawDataShareUserLeftCB(null);
  zoomsharerawdata.SetRawDataCB(null);
  zoommeeting.GetMeetingShare().SetOnSharingStatusCB(null);
  zoomaudiorawdata.SetMixedAudioRawDataCB(null);
  zoomaudiorawdata.SetOneWayAudioRawDataCB(null);
}

function showYUVWindow() {
  if (!YUVWindow) {
    YUVWindow = new BrowserWindow({
      width: 1920, height: 1080,
      webPreferences: {
        nodeIntegration: true
      }
    });
    YUVWindow.on('close', (flag) => {
      YUVWindow.webContents.send('main-process-meetingstatus', 'ended');
      clearSetCallBack();
      let opt = {
        endMeeting: false
      }
      console.log('autoCloseYUV', autoCloseYUV);
      if (!autoCloseYUV) {
        let ret = zoommeeting.LeaveMeeting(opt);
        console.log('leave', ret);
      }
      YUVWindow = null;
      if (startjoinWindow) {
        startjoinWindow.close();
        startjoinWindow = null;
      }
      zoommeeting.StopVideoServer();
      zoommeeting.StopShareServer();
      showStartJoinWindow();
    });
    YUVWindow.loadURL('file://' + __dirname + '/pages/yuv.html');
    autoCloseYUV = false
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
  if (startjoinUnLoginWindow) {
    startjoinUnLoginWindow.close();
    startjoinUnLoginWindow = null;
  }
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
}

function showDomainwindow() {
  if (!domainWindow) {
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
  if (YUVWindow) {
    autoCloseYUV = true;
    YUVWindow.close();
    YUVWindow = null;
  }
}

function showAuthwindow() {
  if (!mainWindow) {
    mainWindow = new BrowserWindow({
      width: 700,
      height: 400,
      webPreferences: {
        nodeIntegration: true
      }
    });
    mainWindow.loadURL('file://' + __dirname + '/pages/index.html');
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
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
  if (YUVWindow) {
    autoCloseYUV = true;
    YUVWindow.close();
    YUVWindow = null;
  }
}

function showLoginWindow() {
  if (!loginWindow) {
    loginWindow = new BrowserWindow({
      width: 700, height: 500,
      webPreferences: {
        nodeIntegration: true
      }
    });
    loginWindow.loadURL('file://' + __dirname + '/pages/login.html');
  }
  if (mainWindow) {
    mainWindow.close();
    mainWindow = null;
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
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
  if (YUVWindow) {
    autoCloseYUV = true;
    YUVWindow.close();
    YUVWindow = null;
  }
}

function showStartJoinWindow() {
  if (!startjoinWindow) {
    startjoinWindow = new BrowserWindow({
      width: 700, height: 400,
      webPreferences: {
        nodeIntegration: true
      }
    });
    startjoinWindow.loadURL('file://' + __dirname + '/pages/start_join.html');
  }
  if (mainWindow) {
    mainWindow.close();
    mainWindow = null;
  }
  if (loginWindow) {
    loginWindow.close();
    loginWindow = null;
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
  if (domainWindow) {
    domainWindow.close();
    domainWindow = null;
  }
  if (YUVWindow) {
    autoCloseYUV = true;
    YUVWindow.close();
    YUVWindow = null;
  }
}

function ProcSDKReady() {
  showAuthwindow()
  var options = {
    authcb: sdkauthCB,
    logincb: loginretCB,
    logoutcb: null
  }
  zoomauth = zoomsdk.GetAuth(options);
}

function apicallresultcb(apiname, ret) {
  if ('InitSDK' == apiname && ZoomSDKError.SDKERR_SUCCESS == ret) {
    ProcSDKReady()
  } else if ('CleanUPSDK' == apiname) {
    app.quit();
  }
}

function OnDirectShareStatusUpdate(status) {
  console.log('OnDirectShareStatusUpdate', status);
  startjoinWindow ? startjoinWindow.webContents.send('main-process-onDirectShareStatusUpdate', status) : null;
}

function onLibUVRawDataReceived(databuf) {
  console.log('onLibUVRawDataReceived -- pipe works! -- data:', databuf);
}

function onVideoRawDataReceived(databuf, format, receivers) {
  let videoObj = {
    databuf: databuf,
    format: format,
    receivers: receivers
  }
  YUVWindow ? YUVWindow.webContents.send('main-process-videomessages', videoObj) : null;
}

function onShareRawDataReceived(databuf, format, receivers) {
  let shareObj = {
    databuf: databuf,
    format: format,
    receivers: receivers
  }
  YUVWindow ? YUVWindow.webContents.send('main-process-sharemessages', shareObj) : null;
}

function onMixedAudioRawDataReceived(databuf, data_format) {
  if (YUVWindow) {
    let mixAudioObj = {
      databuf: databuf,
      data_format: data_format
    }
    YUVWindow ? YUVWindow.webContents.send('main-process-mixaudiomessages', mixAudioObj) : null;
  }
}

function onOneWayAudioRawDataReceived(databuf, data_format, nodeid) {
  if (YUVWindow) {
    let oneWayAudioObj = {
      databuf: databuf,
      data_format: data_format,
      nodeid: nodeid
    }
    YUVWindow ? YUVWindow.webContents.send('main-process-onewayaudiomessages', oneWayAudioObj) : null;
  }
}

function hasRawDataLicense() {
  let ret = zoomsdk.HasRawDataLicense();
  console.log('hasRawDataLicense', ret);
  return ret;
}

function customizedresource() {
  zoomcustomizedresource = zoomsdk.GetCustomizedResource();
  const optCustomizedResouce = {
    CustomizedStringType: SDKCustomizedStringType.SDK_Customized_Title_App,
    strCustomizedString: 'zoom demo'
  }
  const optCustomizedURLResouce = {
    CustomizedURLType: SDKCustomizedURLType.ZN_SDKCustomizedURL_SUPPORTURL,
    strCustomizeURL: 'https://www.baidu.com/'
  }
  const optCustomizedPictureResouce = {
    strPNGID: 'ZOOMAPPICON.PNG',
    strPNGPath: 'D:\\emoticons.png'
  }
  if (zoomcustomizedresource) {
    let retCustomize = zoomcustomizedresource.Resource_AddCustomizedStringResource(optCustomizedResouce);
    console.log('retCustomize', retCustomize);
    let retURLCustomize = zoomcustomizedresource.Resource_AddCustomizedURLResource(optCustomizedURLResouce);
    console.log('retURLCustomize', retURLCustomize);
    let retPictureCustomize = zoomcustomizedresource.Resource_AddCustomizedPictureResource(optCustomizedPictureResouce);
    console.log('retPictureCustomize', retPictureCustomize);
  }
}

let functionObj = {
  showSatrtJoinUnLoginWindow: function () {
    if (!startjoinUnLoginWindow) {
      startjoinUnLoginWindow = new BrowserWindow({
        width: 700, height: 400,
        webPreferences: {
          nodeIntegration: true
        }
      });
      startjoinUnLoginWindow.loadURL('file://' + __dirname + '/pages/start_join_without_login.html');
    }
    if (startjoinWindow) {
      startjoinWindow.close();
      startjoinWindow = null;
    }
    if (mainWindow) {
      mainWindow.close();
      mainWindow = null;
    }
    if (loginWindow) {
      loginWindow.close();
      loginWindow = null;
    }
    if (waitingWindow) {
      waitingWindow.close();
      waitingWindow = null;
    }
    if (inmeetingWindow) {
      inmeetingWindow.close();
      inmeetingWindow = null;
    }
    if (domainWindow) {
      domainWindow.close();
      domainWindow = null;
    }
  },
  setDomain: function (domain, enable_log) {
    const opts = {
      path: '', // win require absolute path, mac require ''
      domain: domain,
      enable_log: enable_log,
      langid: ZoomSDK_LANGUAGE_ID.LANGUAGE_English,
      locale: ZoomAPPLocale.ZNSDK_APP_Locale_Default,
      logfilesize: 5
    }
    if (platform == 'win32') {
      customizedresource(); // CustomizedResource only support windows, should call before initSDK
    }
    var ret = zoomsdk.InitSDK(opts);
    if (ZoomSDKError.SDKERR_SUCCESS == ret) {
      ProcSDKReady();
    }
  },
  getZoomSDKVersion: function () {
    let ret = zoomsdk.GetZoomSDKVersion()
    console.log('GetZoomSDKVersion', ret);
  },
  login: function (username, psw) {
    if (username && psw) {
      showWaitingWindow();
    }
    zoomauth.Login(username, psw, false);
  },
  loginWithSSOToken: function (ssotoken) {
    let ret = zoomauth.LoginWithSSOToken(ssotoken);
    console.log('LoginWithSSOToken', ret);
  },
  logout: function () {
    zoomauth.Logout();
    showLoginWindow();
  },
  authWithJwtToken: function (sdk_context) {
    let ret = zoomauth.AuthWithJwtToken(sdk_context);
    console.log('AuthWithJwtToken', ret);
    if (ret == 0) {
      showWaitingWindow();
    }
  },
  start: function (meetingnum, startCBOption) {
    var opt = {
      meetingnum: meetingnum,
      startCBOption: startCBOption
    }
    let ret = zoommeeting.StartMeeting(opt);
    console.log('StartMeeting', ret);
  },
  join: function (meetingnum, username, startCBOption) {
    var opt = {
      meetingnum: meetingnum,
      username: username,
      startCBOption: startCBOption
    }
    zoommeeting.JoinMeeting(opt);
  },
  startunlogin: function (meetingnum, zoomaccesstoken, username) {
    var opt = {
      meetingnum: meetingnum,
      zoomaccesstoken: zoomaccesstoken,
      username: username
    }
    let ret = zoommeeting.StartMeetingWithOutLogin(opt);
    console.log('StartMeetingWithOutLogin', ret);
  },
  joinunlogin: function (meetingnum, vanityid, username) {
    var opt = {
      meetingnum: meetingnum,
      vanityid: vanityid,
      username: username
    }
    zoommeeting.JoinMeetingWithoutLogin(opt);
  },
  leave: function (endMeeting) {
    var opt = {
      endMeeting: endMeeting
    }
    let ret = zoommeeting.LeaveMeeting(opt);
    console.log('leave', ret);
  },
  end: function (endMeeting) {
    var opt = {
      endMeeting: endMeeting
    }
    let ret = zoommeeting.LeaveMeeting(opt);
    console.log('end', ret);
  },
  lock: function () {
    let ret = zoommeeting.Lock_Meeting();
    console.log('Lock_Meeting', ret);
  },
  unlock: function () {
    let ret = zoommeeting.Un_lock_Meeting();
    console.log('Un_lock_Meeting', ret);
  },
  getSharingConnQuality: function () {
    let ret = zoommeeting.GetSharingConnQuality();
    console.log('GetSharingConnQuality', ret);
    return ret;
  },
  getVideoConnQuality: function () {
    let ret = zoommeeting.GetVideoConnQuality();
    console.log('GetVideoConnQuality', ret);
    return ret;
  },
  getAudioConnQuality: function () {
    let ret = zoommeeting.GetAudioConnQuality();
    console.log('GetAudioConnQuality', ret);
    return ret;
  },
  getParticipantsList: function () {
    let ret = zoomparticipantsctrl.GetParticipantsList();
    console.log('GetParticipantsList', ret);
    return ret;
  },
  getUserInfoByUserID: function (userid) {
    let ret = zoomparticipantsctrl.GetUserInfoByUserID(userid);
    console.log('GetUserInfoByUserID', ret);
    return ret;
  },
  handleZoomWebUriProtocolAction: function (protocol_action) {
    let ret = zoommeeting.HandleZoomWebUriProtocolAction(protocol_action);
    console.log('HandleZoomWebUriProtocolAction', ret);
    return ret;
  },
  getMeetingTopic: function () {
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
  getMeetingID: function () {
    let ret = zoominfomod.GetMeetingID();
    console.log('GetMeetingID', ret);
    return ret;
  },
  getInviteEmailTeamplate: function () {
    let ret = zoominfomod.GetInviteEmailTeamplate();
    console.log('GetInviteEmailTeamplate', ret);
    return ret;
  },
  getInviteEmailTitle: function () {
    let ret = zoominfomod.GetInviteEmailTitle();
    console.log('GetInviteEmailTitle', ret);
    return ret;
  },
  getJoinMeetingUrl: function () {
    let ret = zoominfomod.GetJoinMeetingUrl();
    console.log('GetJoinMeetingUrl', ret);
    return ret;
  },
  getMeetingHostTag: function () {
    let ret = zoominfomod.GetMeetingHostTag();
    console.log('GetMeetingHostTag', ret);
    return ret;
  },
  checkingIsInternalMeeting: function () {
    let ret = zoominfomod.CheckingIsInternalMeeting();
    console.log('CheckingIsInternalMeeting', ret);
    return ret;
  },
  showChat: function () {
    let opts = {
      left: '200',
      top: '200'
    }
    zoomuicontroller.MeetingUI_ShowChatDlg(opts);
  },
  hideChat: function () {
    zoomuicontroller.MeetingUI_HideChatDlg();
  },
  enterFullscreen: function () {
    var opts = {
      bFirstView: '1',
      bSecView: '0'
    }
    zoomuicontroller.MeetingUI_EnterFullScreen(opts);
  },
  exitFullScreen: function () {
    var opts = {
      bFirstView: '1',
      bSecView: '0'
    }
    zoomuicontroller.MeetingUI_ExitFullScreen(opts);
  },
  switchToVideoWall: function () {
    let ret = zoomuicontroller.MeetingUI_SwitchToVideoWall();
    console.log('SwitchToVideoWall', ret);
  },
  swtichToAcitveSpeaker: function () {
    let ret = zoomuicontroller.MeetingUI_SwtichToAcitveSpeaker();
    console.log('SwtichToAcitveSpeaker', ret);
  },
  moveFloatVideoWnd: function () {
    let opts = {
      left: '200',
      top: '200'
    }
    let ret = zoomuicontroller.MeetingUI_MoveFloatVideoWnd(opts);
    console.log('MoveFloatVideoWnd', ret);
  },
  showSharingToolbar: function (show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowSharingToolbar(opts);
    console.log('ShowSharingToolbar', ret);
  },
  switchFloatVideoToActiveSpkMod: function () {
    let ret = zoomuicontroller.MeetingUI_SwitchFloatVideoToActiveSpkMod();
    console.log('SwitchFloatVideoToActiveSpkMod', ret);
  },
  changeFloatoActiveSpkVideoSize: function () {
    console.log('ZoomMeetingUIFloatVideoType', ZoomMeetingUIFloatVideoType.FLOATVIDEO_Large);
    let obj = {
      floatvideotype: ZoomMeetingUIFloatVideoType.FLOATVIDEO_Large
    }
    let ret = zoomuicontroller.MeetingUI_ChangeFloatoActiveSpkVideoSize(obj);
    console.log('ChangeFloatoActiveSpkVideoSize', ret);
  },
  switchFloatVideoToGalleryMod: function () {
    let ret = zoomuicontroller.MeetingUI_SwitchFloatVideoToGalleryMod();
    console.log('switchFloatVideoToGalleryMod', ret);
  },
  showParticipantsListWnd: function (show) {
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
  showJoinAudioDlg: function () {
    let ret = zoomuicontroller.MeetingUI_ShowJoinAudioDlg();
    console.log('ShowJoinAudioDlg', ret);
  },
  hideJoinAudioDlg: function () {
    let ret = zoomuicontroller.MeetingUI_HideJoinAudioDlg();
    console.log('HideJoinAudioDlg', ret);
  },
  getWallViewPageInfo: function (arg2, arg3) {
    let opts = {
      currentPage: arg2,
      totalPages: arg3
    }
    let ret = zoomuicontroller.MeetingUI_GetWallViewPageInfo(opts);
    console.log('GetWallViewPageInfo', ret);
  },
  showPreOrNextPageVideo: function (show) {
    console.log('show', show);
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowPreOrNextPageVideo(opts);
    console.log('ShowPreOrNextPageVideo', ret);
    return ret;
  },
  showSharingFrameWindows: function (show) {
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
  getCurrentSplitScreenModeInfo: function (arg2, arg3) {
    let opts = {
      bZNSupportSplitScreen: arg2,
      bZNInSplitScreenMode: arg3
    }
    let ret = zoomuicontroller.MeetingUI_GetCurrentSplitScreenModeInfo(opts);
    console.log('GetCurrentSplitScreenModeInfo', ret);
    return ret;
  },
  isAnnotaionDisable: function () {
    let ret = zoomannotation.Annotaion_IsAnnotaionDisable();
    console.log('IsAnnotaionDisable', ret);
    return ret;
  },
  startAnnotation: function (viewtype, left, top) {
    let opts = {
      viewtype: viewtype,
      left: '300',
      top: '300'
    }
    let ret = zoomannotation.Annotaion_StartAnnotation(opts);
    console.log('StartAnnotation', ret);
  },
  stopAnnotation: function (viewtype) {
    let ret = zoomannotation.Annotaion_StopAnnotation(viewtype);
    console.log('StopAnnotation', ret);
  },
  setTool: function (viewtype, tooltype) {
    let opts = {
      viewtype: viewtype,
      tooltype: tooltype
    }
    let ret = zoomannotation.Annotaion_SetTool(opts);
    console.log('SetTool', ret);
  },
  setClear: function (viewtype, cleartype) {
    let opts = {
      viewtype: viewtype,
      cleartype: cleartype
    }
    let ret = zoomannotation.Annotaion_Clear(opts);
    console.log('Clear', ret);
  },
  setColor: function (viewtype, color) {
    let opts = {
      viewtype: viewtype,
      color: color
    }
    let ret = zoomannotation.Annotaion_SetColor(opts);
    console.log('SetColor', ret);
  },
  SetLineWidth: function (viewtype, lineWidth) {
    let opts = {
      viewtype: viewtype,
      lineWidth: lineWidth
    }
    let ret = zoomannotation.Annotaion_SetLineWidth(opts);
    console.log('SetLineWidth', ret);
  },
  undo: function (viewtype) {
    let opts = {
      viewtype: viewtype
    }
    let ret = zoomannotation.Annotaion_Undo(opts)
    console.log('Undo', ret);
  },
  redo: function (viewtype) {
    let opts = {
      viewtype: viewtype
    }
    let ret = zoomannotation.Annotaion_Redo(opts)
    console.log('Redo', ret);
  },
  muteAudio: function (userid, allowunmutebyself) {
    let opts = {
      userid: userid,
      allowunmutebyself: allowunmutebyself
    }
    let ret = zoomaudio.MeetingAudio_MuteAudio(opts);
    console.log('MuteAudio', ret);
  },
  unMuteAudio: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomaudio.MeetingAudio_UnMuteAudio(opts);
    console.log('UnMuteAudio', ret);
  },
  joinVoip: function () {
    let ret = zoomaudio.MeetingAudio_JoinVoip();
    console.log('JoinVoip', ret);
  },
  leaveVoip: function () {
    let ret = zoomaudio.MeetingAudio_LeaveVoip();
    console.log('LeaveVoip', ret);
  },
  enablePlayChimeWhenEnterOrExit: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomaudio.MeetingAudio_EnablePlayChimeWhenEnterOrExit(opts);
    console.log('EnablePlayChimeWhenEnterOrExit', ret);
  },
  muteVideo: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_MuteVideo(opts);
    console.log('MuteVideo', ret);
  },
  unMuteVideo: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_UnMuteVideo(opts);
    console.log('UnMuteVideo', ret);
  },
  pinVideo: function (userid) {
    let opts = {
      bPin: true,
      bFirstView: true,
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_PinVideo(opts);
    console.log('PinVideo', ret);
  },
  spotlightVideo: function (userid) {
    let opts = {
      bSpotlight: true,
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_SpotlightVideo(opts);
    console.log('SpotlightVideo', ret);
  },
  hideOrShowNoVideoUserOnVideoWall: function (bHide) {
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
  getCameraList: function () {
    let ret = zoomsetvideo.Setting_GetCameraList();
    console.log('GetCameraList', ret);
  },
  enableVideoMirrorEffect: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetvideo.Setting_EnableVideoMirrorEffect(opts);
    console.log('EnableVideoMirrorEffect', ret);
  },
  enableFaceBeautyEffect: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetvideo.Setting_EnableFaceBeautyEffect(opts);
    console.log('EnableFaceBeautyEffect', ret);
  },
  isMirrorEffectEnabled: function () {
    let ret = zoomsetvideo.Checking_IsMirrorEffectEnabled();
    console.log('IsMirrorEffectEnabled', ret);
  },
  isFaceBeautyEffectEnabled: function () {
    let ret = zoomsetvideo.Checking_IsFaceBeautyEffectEnabled();
    console.log('IsFaceBeautyEffectEnabled', ret);
  },
  enableStereoAudio: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableStereoAudio(opts);
    console.log('EnableStereoAudio', ret);
  },
  isStereoAudioEnable: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsStereoAudioEnable(opts);
    console.log('IsStereoAudioEnable', ret);
  },
  enableMicOriginalInput: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableMicOriginalInput(opts);
    console.log('EnableMicOriginalInput', ret);
  },
  enableHoldSpaceKeyToSpeak: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableHoldSpaceKeyToSpeak(opts);
    console.log('EnableHoldSpaceKeyToSpeak', ret);
  },
  isHoldSpaceKeyToSpeakEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsHoldSpaceKeyToSpeakEnabled(opts);
    console.log('IsHoldSpaceKeyToSpeakEnabled', ret);
  },
  enableAlwaysMuteMicWhenJoinVoip: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAlwaysMuteMicWhenJoinVoip(opts);
    console.log('EnableAlwaysMuteMicWhenJoinVoip', ret);
  },
  isAlwaysMuteMicWhenJoinVoipEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsAlwaysMuteMicWhenJoinVoipEnabled(opts);
    console.log('IsAlwaysMuteMicWhenJoinVoipEnabled', ret);
  },
  enableSuppressAudioNotify: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableSuppressAudioNotify(opts);
    console.log('EnableSuppressAudioNotify', ret);
  },
  isSuppressAudioNotifyEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsSuppressAudioNotifyEnabled(opts);
    console.log('IsSuppressAudioNotifyEnabled', ret);
  },
  enableEchoCancellation: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableEchoCancellation(opts);
    console.log('EnableEchoCancellation', ret);
  },
  isEchoCancellationEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsEchoCancellationEnabled(opts);
    console.log('IsEchoCancellationEnabled', ret);
  },
  setMicVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_SetMicVol(opts);
    console.log('SetMicVol', ret);
  },
  getMicVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_GetMicVol(opts);
    console.log('GetMicVol', ret);
  },
  setSpeakerVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_SetSpeakerVol(opts);
    console.log('SetSpeakerVol', ret);
  },
  getSpeakerVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_GetSpeakerVol(opts);
    console.log('GetSpeakerVol', ret);
  },
  isMicOriginalInputEnable: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsMicOriginalInputEnable(opts);
    console.log('isMicOriginalInputEnable', ret);
  },
  enableHDVideo: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableHDVideo(opts);
    console.log('EnableHDVideo', ret);
  },
  isHDVideoEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsHDVideoEnabled(opts);
    console.log('IsHDVideoEnabled', ret);
  },
  enableAlwaysShowNameOnVideo: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableAlwaysShowNameOnVideo(opts);
    console.log('EnableAlwaysShowNameOnVideo', ret);
  },
  isAlwaysShowNameOnVideoEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsAlwaysShowNameOnVideoEnabled(opts);
    console.log('IsAlwaysShowNameOnVideoEnabled', ret);
  },
  enableAutoTurnOffVideoWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableAutoTurnOffVideoWhenJoinMeeting(opts);
    console.log('EnableAutoTurnOffVideoWhenJoinMeeting', ret);
  },
  isAutoTurnOffVideoWhenJoinMeetingEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsAutoTurnOffVideoWhenJoinMeetingEnabled(opts);
    console.log('IsAutoTurnOffVideoWhenJoinMeetingEnabled', ret);
  },
  enableAlwaysUse16v9: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableAlwaysUse16v9(opts);
    console.log('EnableAlwaysUse16v9', ret);
  },
  isAlwaysUse16v9: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsAlwaysUse16v9(opts);
    console.log('IsAlwaysUse16v9', ret);
  },
  enableSpotlightSelf: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableSpotlightSelf(opts);
    console.log('EnableSpotlightSelf', ret);
  },
  isSpotlightSelfEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsSpotlightSelfEnabled(opts);
    console.log('IsSpotlightSelfEnabled', ret);
  },
  enableHardwareEncode: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableHardwareEncode(opts);
    console.log('EnableHardwareEncode', ret);
  },
  isHardwareEncodeEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsHardwareEncodeEnabled(opts);
    console.log('IsHardwareEncodeEnabled', ret);
  },
  enable49VideoesInGallaryView: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_Enable49VideoesInGallaryView(opts);
    console.log('Enable49VideoesInGallaryView', ret);
  },
  is49VideoesInGallaryViewEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_Is49VideoesInGallaryViewEnabled(opts);
    console.log('Is49VideoesInGallaryViewEnabled', ret);
  },
  enableHideNoVideoUsersOnWallView: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableHideNoVideoUsersOnWallView(opts);
    console.log('EnableHideNoVideoUsersOnWallView', ret);
  },
  isHideNoVideoUsersOnWallViewEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsHideNoVideoUsersOnWallViewEnabled(opts);
    console.log('IsHideNoVideoUsersOnWallViewEnabled', ret);
  },
  enableVideoPreviewDialog: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableVideoPreviewDialog(opts);
    console.log('enableVideoPreviewDialog', ret);
  },
  isVideoPreviewDialogEnabled: function () {
    let ret = zoomsetvideo.Setting_IsVideoPreviewDialogEnabled();
    console.log('isVideoPreviewDialogEnabled', ret);
  },
  getMicList: function () {
    zoomsetaudio.Setting_GetMicList();
  },
  selectMic: function (zn_deviceId, zn_deviceName) {
    let opts = {
      zn_deviceId: zn_deviceId,
      zn_deviceName: zn_deviceName
    }
    let ret = zoomsetaudio.Setting_SelectMic(opts);
    console.log('SelectMic', ret);
  },
  selectSpeaker: function (zn_deviceId, zn_deviceName) {
    let opts = {
      zn_deviceId: zn_deviceId,
      zn_deviceName: zn_deviceName
    }
    let ret = zoomsetaudio.Setting_SelectSpeaker(opts);
    console.log('SelectSpeaker', ret);
  },
  getSpeakerList: function () {
    let ret = zoomsetaudio.Setting_GetSpeakerList();
    // console.log('GetSpeakerList', ret);
  },
  isAutoJoinAudioEnabled: function () {
    let ret = zoomsetaudio.Checking_IsAutoJoinAudioEnabled();
    console.log('IsAutoJoinAudioEnabled', ret);
  },
  isAutoAdjustMicEnabled: function () {
    let ret = zoomsetaudio.Checking_IsAutoAdjustMicEnabled();
    console.log('IsAutoAdjustMicEnabled', ret);
  },
  enableAutoJoinAudio: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAutoJoinAudio(opts);
    console.log('EnableAutoJoinAudio', ret);
  },
  enableAutoAdjustMic: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAutoAdjustMic(opts);
    console.log('EnableAutoAdjustMic', ret);
  },
  showSettingDlg: function () {
    let ret = zoomsetting.SettingUI_ShowTheSettingDlg();
    console.log('ShowSettingDlg', ret);
  },
  hideSettingDlg: function () {
    let ret = zoomsetting.SettingUI_HideSettingDlg();
    console.log('HideSettingDlg', ret);
  },
  enableDualScreenMode: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableDualScreenMode(opts);
    console.log('EnableDualScreenMode', ret);
  },
  turnOffAeroModeInSharing: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_TurnOffAeroModeInSharing(opts);
    console.log('TurnOffAeroModeInSharing', ret);
  },
  enableAutoFitToWindowWhenViewSharing: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFitToWindowWhenViewSharing(opts);
    console.log('EnableAutoFitToWindowWhenViewSharing', ret);
  },
  enableAutoFullScreenVideoWhenJoinMeeting: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFullScreenVideoWhenJoinMeeting(opts);
    console.log('EnableAutoFullScreenVideoWhenJoinMeeting', ret);
  },
  enableSplitScreenMode: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableSplitScreenMode(opts);
    console.log('EnableSplitScreenMode', ret);
  },
  isDualScreenModeEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsDualScreenModeEnabled();
    console.log('IsDualScreenModeEnabled', ret);
  },
  isAeroModeInSharingTurnOff: function () {
    let ret = zoomsetgeneral.Checking_IsAeroModeInSharingTurnOff();
    console.log('IsAeroModeInSharingTurnOff', ret);
  },
  isAutoFitToWindowWhenViewSharingEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsAutoFitToWindowWhenViewSharingEnabled();
    console.log('IsAutoFitToWindowWhenViewSharingEnabled', ret);
  },
  isAutoFullScreenVideoWhenJoinMeetingEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsAutoFullScreenVideoWhenJoinMeetingEnabled();
    console.log('isAutoFullScreenVideoWhenJoinMeetingEnabled', ret);
  },
  isSplitScreenModeEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsSplitScreenModeEnabled();
    console.log('IsSplitScreenModeEnabled', ret);
  },
  enableAutoFullScreenVideoWhenViewShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFullScreenVideoWhenViewShare(opts);
    console.log('EnableAutoFullScreenVideoWhenViewShare', ret);
  },
  isAutoFullScreenVideoWhenViewShareEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsAutoFullScreenVideoWhenViewShareEnabled(opts);
    console.log('IsAutoFullScreenVideoWhenViewShareEnabled', ret);
  },
  enableDisplayReminderWindowWhenExit: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableDisplayReminderWindowWhenExit(opts);
    console.log('EnableDisplayReminderWindowWhenExit', ret);
  },
  isDisplayReminderWindowWhenExitEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsDisplayReminderWindowWhenExitEnabled(opts);
    console.log('IsDisplayReminderWindowWhenExitEnabled', ret);
  },
  enableShowMyMeetingElapseTime: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableShowMyMeetingElapseTime(opts);
    console.log('EnableShowMyMeetingElapseTime', ret);
  },
  isShowMyMeetingElapseTimeEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsShowMyMeetingElapseTimeEnabled(opts);
    console.log('IsShowMyMeetingElapseTimeEnabled', ret);
  },
  isCurrentOSSupportAccelerateGPUWhenShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsCurrentOSSupportAccelerateGPUWhenShare(opts);
    console.log('IsCurrentOSSupportAccelerateGPUWhenShare', ret);
  },
  enableAccelerateGPUWhenShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAccelerateGPUWhenShare(opts);
    console.log('EnableAccelerateGPUWhenShare', ret);
  },
  isAccelerateGPUWhenShareEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsAccelerateGPUWhenShareEnabled(opts);
    console.log('IsAccelerateGPUWhenShareEnabled', ret);
  },
  enableRemoteControlAllApplications: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableRemoteControlAllApplications(opts);
    console.log('EnableRemoteControlAllApplications', ret);
  },
  isRemoteControlAllApplicationsEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsRemoteControlAllApplicationsEnabled(opts);
    console.log('IsRemoteControlAllApplicationsEnabled', ret);
  },
  setRecordingPath: function (zn_szPath) {
    let opts = {
      zn_szPath: zn_szPath
    }
    let ret = zoomsetrecord.Setting_SetRecordingPath(opts);
    console.log('SetRecordingPath', ret);
  },
  getRecordingPath: function () {
    let ret = zoomsetrecord.Getting_GetRecordingPath();
    console.log('GetRecordingPath', ret);
  },
  canGetCloudRecordingStorageInfo: function (bCan) {
    let opts = {
      bCan: bCan
    }
    let ret = zoomsetrecord.Setting_CanGetCloudRecordingStorageInfo(opts);
    console.log('CanGetCloudRecordingStorageInfo', ret);
  },
  getCloudRecordingStorageInfo: function () {
    let ret = zoomsetrecord.Getting_GetCloudRecordingStorageInfo();
    console.log('GetCloudRecordingStorageInfo', ret);
  },
  getRecordingManagementURL: function () {
    let ret = zoomsetrecord.Getting_GetRecordingManagementURL();
    console.log('GetRecordingManagementURL', ret);
  },
  canGetRecordingManagementURL: function (bCan) {
    let opts = {
      bCan: bCan
    }
    let ret = zoomsetrecord.Setting_CanGetRecordingManagementURL(opts);
    console.log('CanGetRecordingManagementURL', ret);
  },
  enableSelectRecordFileLocationAfterMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableSelectRecordFileLocationAfterMeeting(opts);
    console.log('EnableSelectRecordFileLocationAfterMeeting', ret);
  },
  isSelectRecordFileLocationAfterMeetingEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsSelectRecordFileLocationAfterMeetingEnabled(opts);
    console.log('IsSelectRecordFileLocationAfterMeetingEnabled', ret);
  },
  enableMultiAudioStreamRecord: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableMultiAudioStreamRecord(opts);
    console.log('EnableMultiAudioStreamRecord', ret);
  },
  isMultiAudioStreamRecordEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsMultiAudioStreamRecordEnabled(opts);
    console.log('IsMultiAudioStreamRecordEnabled', ret);
  },
  enableAddTimestampWatermark: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableAddTimestampWatermark(opts);
    console.log('EnableAddTimestampWatermark', ret);
  },
  isAddTimestampWatermarkEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsAddTimestampWatermarkEnabled(opts);
    console.log('IsAddTimestampWatermarkEnabled', ret);
  },
  enableOptimizeFor3rdPartyVideoEditor: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableOptimizeFor3rdPartyVideoEditor(opts);
    console.log('EnableOptimizeFor3rdPartyVideoEditor', ret);
  },
  isOptimizeFor3rdPartyVideoEditorEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsOptimizeFor3rdPartyVideoEditorEnabled(opts);
    console.log('IsOptimizeFor3rdPartyVideoEditorEnabled', ret);
  },
  enableShowVideoThumbnailWhenShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableShowVideoThumbnailWhenShare(opts);
    console.log('EnableShowVideoThumbnailWhenShare', ret);
  },
  isShowVideoThumbnailWhenShareEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsShowVideoThumbnailWhenShareEnabled(opts);
    console.log('IsShowVideoThumbnailWhenShareEnabled', ret);
  },
  enablePlaceVideoNextToShareInRecord: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnablePlaceVideoNextToShareInRecord(opts);
    console.log('EnablePlaceVideoNextToShareInRecord', ret);
  },
  isPlaceVideoNextToShareInRecordEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsPlaceVideoNextToShareInRecordEnabled(opts);
    console.log('IsPlaceVideoNextToShareInRecordEnabled', ret);
  },
  startAppShare: function (zn_hShare_app) {
    let opts = {
      zn_hShare_app: zn_hShare_app
    }
    let ret = zoomshare.MeetingShare_StartAppShare(opts);
    console.log('StartAppShare', ret);
  },
  startMonitorShare: function (zn_monitorID) {
    let opts = {
      zn_monitorID: zn_monitorID
    }
    let ret = zoomshare.MeetingShare_StartMonitorShare(opts);
    console.log('StartMonitorShare', ret);
  },
  stopShare: function () {
    let ret = zoomshare.MeetingShare_StopShare();
    console.log('StopShare', ret);
  },
  callOutH323: function () {
    let opts = {
      'deviceName': 'xxx',
      'deviceIP': '1234',
      'deviceE164num': '1234',
      'type': 1
    }
    let ret = zoomh323.H323_CallOutH323(opts);
    console.log('CallOutH323', ret);
  },
  cancelCallOutH323: function () {
    let ret = zoomh323.H323_CancelCallOutH323();
    console.log('CancelCallOutH323', ret);
  },
  getH323Address: function () {
    let ret = zoomh323.H323_GetH323Address();
    console.log('GetH323Address', ret);
  },
  getH323Password: function () {
    let ret = zoomh323.H323_GetH323Password();
    console.log('GetH323Password', ret);
  },
  getCalloutH323DeviceList: function () {
    let ret = zoomh323.H323_GetCalloutH323DeviceList();
    console.log('GetCalloutH323DeviceList', ret);
  },
  enableInviteButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInviteButtonOnMeetingUI(opts);
    console.log('EnableInviteButtonOnMeetingUI', ret);
  },
  setFloatVideoPos: function () {
    let opts = {
      left: '10',
      top: '10'
    }
    let ret = zoomconfiguration.MeetingConfig_SetFloatVideoPos(opts);
    console.log('SetFloatVideoPos', ret);
  },
  setBottomFloatToolbarWndVisibility: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetBottomFloatToolbarWndVisibility(opts);
    console.log('SetBottomFloatToolbarWndVisibility', ret);
  },
  setSharingToolbarVisibility: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetSharingToolbarVisibility(opts);
    console.log('SetSharingToolbarVisibility', ret);
  },
  setDirectShareMonitorID: function (monitorID) {
    let opts = {
      monitorID: monitorID
    }
    let ret = zoomconfiguration.MeetingConfig_SetDirectShareMonitorID(opts);
    console.log('SetDirectShareMonitorID', ret);
  },
  setMeetingUIPos: function () {
    let opts = {
      left: '10',
      top: '10'
    }
    let ret = zoomconfiguration.MeetingConfig_SetMeetingUIPos(opts);
    console.log('SetMeetingUIPos', ret);
  },
  disableWaitingForHostDialog: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableWaitingForHostDialog(opts);
    console.log('DisableWaitingForHostDialog', ret);
  },
  disablePopupMeetingWrongPSWDlg: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisablePopupMeetingWrongPSWDlg(opts);
    console.log('DisablePopupMeetingWrongPSWDlg', ret);
  },
  enableAutoEndOtherMeetingWhenStartMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoEndOtherMeetingWhenStartMeeting(opts);
    console.log('EnableAutoEndOtherMeetingWhenStartMeeting', ret);
  },
  enableLButtonDBClick4SwitchFullScreenMode: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLButtonDBClick4SwitchFullScreenMode(opts);
    console.log('EnableLButtonDBClick4SwitchFullScreenMode', ret);
  },
  setFloatVideoWndVisibility: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetFloatVideoWndVisibility(opts);
    console.log('SetFloatVideoWndVisibility', ret);
  },
  prePopulateWebinarRegistrationInfo: function (email, userName) {
    let opts = {
      email: email,
      userName: userName
    }
    let ret = zoomconfiguration.MeetingConfig_PrePopulateWebinarRegistrationInfo(opts);
    console.log('PrePopulateWebinarRegistrationInfo', ret);
  },
  redirectClickAudioBTNEvent: function (bRedirect) {
    let opts = {
      bRedirect: bRedirect
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickAudioBTNEvent(opts);
    console.log('RedirectClickAudioBTNEvent', ret);
  },
  redirectClickAudioMenuBTNEvent: function (bRedirect) {
    let opts = {
      bRedirect: bRedirect
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickAudioMenuBTNEvent(opts);
    console.log('RedirectClickAudioMenuBTNEvent', ret);
  },
  enableAudioButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAudioButtonOnMeetingUI(opts);
    console.log('EnableAudioButtonOnMeetingUI', ret);
  },
  disableShowJoinMeetingWnd: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableShowJoinMeetingWnd(opts);
    console.log('DisableShowJoinMeetingWnd', ret);
  },
  getReminderType: function () {
    let ret = zoomupdateaccount.MeetingConfig_GetReminderType();
    console.log('GetReminderType', ret);
  },
  upgradeMeeting: function () {
    let ret = zoomupdateaccount.MeetingConfig_UpgradeMeeting();
    console.log('UpgradeMeeting', ret);
  },
  upgradeAccount: function () {
    let ret = zoomupdateaccount.MeetingConfig_UpgradeAccount();
    console.log('UpgradeAccount', ret);
  },
  cancelUpdate: function () {
    let ret = zoomupdateaccount.MeetingConfig_CancelUpdate();
    console.log('CancelUpdate', ret);
  },
  setFreeMeetingNeedToUpgradeCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingNeedToUpgradeCB();
    console.log('SetFreeMeetingNeedToUpgradeCB', ret);
  },
  setFreeMeetingUpgradeToGiftFreeTrialStartCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStartCB();
    console.log('SetFreeMeetingUpgradeToGiftFreeTrialStartCB', ret);
  },
  setFreeMeetingUpgradeToGiftFreeTrialStopCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStopCB();
    console.log('SetFreeMeetingUpgradeToGiftFreeTrialStopCB', ret);
  },
  setFreeMeetingUpgradeToProMeetingCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
    console.log('SetFreeMeetingUpgradeToProMeetingCB', ret);
  },
  setFreeMeetingUpgradeToProMeetingCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
    console.log('SetFreeMeetingUpgradeToProMeetingCB', ret);
  },
  addCustomizedPictureResource: function (strPNGID, strPNGPath) {
    let opts = {
      strPNGID: strPNGID,
      strPNGPath: strPNGPath
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedPictureResource(opts);
    console.log('AddCustomizedPictureResource', ret);
  },
  addCustomizedStringResource: function (CustomizedStringType, strCustomizedString) {
    let opts = {
      CustomizedStringType: CustomizedStringType,
      strCustomizedString: strCustomizedString
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedStringResource(opts);
    console.log('AddCustomizedStringResource', ret);
  },
  addCustomizedURLResource: function (CustomizedURLType, strCustomizeURL) {
    let opts = {
      CustomizedURLType: CustomizedURLType,
      strCustomizeURL: strCustomizeURL
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedURLResource(opts);
    console.log('AddCustomizedURLResource', ret);
  },
  setFreeMeetingUpgradeToProMeetingCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
    console.log('SetFreeMeetingUpgradeToProMeetingCB', ret);
  },
  scheduleMeetingWithWndParams: function () {
    let ret = zoompremeeting.ScheduleMeetingWithWndParams();
    console.log('scheduleMeetingWithWndParams', ret);
  },
  scheduleMeeting: function () {
    let ret = zoompremeeting.ScheduleMeeting();
    console.log('scheduleMeeting', ret);
  },
  editMeeting: function (meetingUniqueID) {
    let opts = {
      meetingUniqueID: meetingUniqueID
    }
    let ret = zoompremeeting.EditMeeting(opts);
    console.log('editMeeting', ret);
  },
  listMeeting: function () {
    let ret = zoompremeeting.ListMeeting();
    console.log('listMeeting', ret);
  },
  deleteMeeting: function (meetingUniqueID) {
    let opts = {
      meetingUniqueID: meetingUniqueID
    }
    let ret = zoompremeeting.DeleteMeeting(opts);
    console.log('deleteMeeting', ret);
  },
  editMeetingWithWndParams: function (meetingUniqueID) {
    let opts = {
      left: '10',
      top: '10',
      meetingUniqueID: meetingUniqueID
    }
    let ret = zoompremeeting.EditMeetingWithWndParams(opts);
    console.log('editMeetingWithWndParams', ret);
  },
  canStartDirectShare: function () {
    let ret = zoomdirectshare.CanStartDirectShare();
    console.log('canStartDirectShare', ret);
  },
  isDirectShareInProgress: function () {
    let ret = zoomdirectshare.IsDirectShareInProgress();
    console.log('isDirectShareInProgress', ret);
  },
  startDirectShare: function () {
    let ret = zoomdirectshare.StartDirectShare(OnDirectShareStatusUpdate);
    console.log('startDirectShare', ret);
  },
  stopDirectShare: function () {
    let ret = zoomdirectshare.StopDirectShare(OnDirectShareStatusUpdate);
    console.log('stopDirectShare', ret);
  },
  setDirectShareStatusUpdateCB: function () {
    let ret = zoomdirectshare.SetDirectShareStatusUpdateCB(OnDirectShareStatusUpdate);
    console.log('setDirectShareStatusUpdateCB', ret);
  },
  tryWithMeetingNumber: function (meetingNumber) {
    let opts = {
      meetingNumber: meetingNumber
    }
    let ret = zoomdirectshare.TryWithMeetingNumber(opts);
    console.log('tryWithMeetingNumber', ret);
  },
  tryWithPairingCode: function (pairingCode) {
    let opts = {
      pairingCode: pairingCode
    }
    let ret = zoomdirectshare.TryWithPairingCode(opts);
    console.log('tryWithPairingCode', ret);
  },
  cancel: function () {
    let ret = zoomdirectshare.Cancel();
    console.log('Cancel', ret);
  },
  handleYUV: function (startCBOption) {
    global.startCBOption = startCBOption;
    showYUVWindow(startCBOption);
  },
  setVideoRawDataCB: function () {
    let ret = zoomvideorawdata.SetRawDataCB(onVideoRawDataReceived);
    console.log('SetVideoRawDataCB', ret);
  },
  startVideoRawData: function (videoRawDataMemoryMode) {
    let opts = {
      RawDataMemoryMode: videoRawDataMemoryMode
    }
    let ret = zoomvideorawdata.Start(opts);
    console.log('StartVideoRawData', ret);
  },
  subscribeVideo: function (nodeID, RawDataResolution, recever_handle) {
    let opts = {
      nodeID: nodeID,
      RawDataResolution: RawDataResolution,
      recever_handle: recever_handle
    }
    let ret = zoomvideorawdata.Subscribe(opts);
    console.log('SubscribeVideo', nodeID, RawDataResolution, recever_handle, ret);
  },
  unsubscribeVideo: function (nodeID, recever_handle) {
    let opts = {
      nodeID: nodeID,
      recever_handle: recever_handle
    }
    let ret = zoomvideorawdata.UnSubscribe(opts);
    console.log('UnsubscribeVideo', nodeID, recever_handle, ret);
  },
  stopVideo: function () {
    let ret = zoomvideorawdata.Stop();
    console.log('StopVideo', ret);
  },
  setShareRawDataCB: function () {
    let ret = zoomsharerawdata.SetRawDataCB(onShareRawDataReceived);
    console.log('SetShareRawDataCB', ret);
  },
  startShareRawData: function () {
    let opts = {
      RawDataMemoryMode: 1
    }
    let ret = zoomsharerawdata.Start(opts);
    console.log('StartShareRawData', ret);
  },
  subscribeShare: function (nodeID, RawDataResolution, recever_handle) {
    let opts = {
      nodeID: nodeID,
      RawDataResolution: RawDataResolution,
      recever_handle: recever_handle
    }
    let ret = zoomsharerawdata.Subscribe(opts);
    console.log('SubscribeShare', ret, nodeID, RawDataResolution, recever_handle);
  },
  unsubscribeShare: function (nodeID, recever_handle) {
    let opts = {
      nodeID: nodeID,
      recever_handle: recever_handle
    }
    let ret = zoomsharerawdata.UnSubscribe(opts);
    console.log('UnsubscribeShare', ret, nodeID, recever_handle);
  },
  stopShareRawdata: function () {
    let ret = zoomsharerawdata.Stop();
    console.log('StopShare', ret);
  },
  setAudioRawDataCB: function () {
    let SetMixedAudioRawDataCB = zoomaudiorawdata.SetMixedAudioRawDataCB(onMixedAudioRawDataReceived);
    console.log('SetMixedAudioRawDataCB', SetMixedAudioRawDataCB);
    let SetOneWayAudioRawDataCB = zoomaudiorawdata.SetOneWayAudioRawDataCB(onOneWayAudioRawDataReceived);
    console.log('SetOneWayAudioRawDataCB', SetOneWayAudioRawDataCB);
  },
  startAudioRawData: function (audioRawDataMemoryMode) {
    let opts = {
      RawDataMemoryMode: audioRawDataMemoryMode
    }
    let ret = zoomaudiorawdata.Start(opts);
    console.log('StartAudioRawData', ret);
  },
  stopAudio: function () {
    let ret = zoomaudiorawdata.Stop();
    console.log('StopAudio', ret);
  },
  backToMeeting: function () {
    let ret = zoomuicontroller.MeetingUI_BackToMeeting();
    console.log('BackToMeeting', ret);
  },
  getMeetingUIWnd: function () {
    let ret = zoomuicontroller.MeetingUI_GetMeetingUIWnd();
    console.log('GetMeetingUIWnd', ret);
  },
  switchMinimizeUIMode4FristScreenMeetingUIWnd: function (mode) {
    let opts = {
      mode: mode
    }
    let ret = zoomuicontroller.MeetingUI_SwitchMinimizeUIMode4FristScreenMeetingUIWnd(opts);
    console.log('SwitchMinimizeUIMode4FristScreenMeetingUIWnd', ret);
  },
  isMinimizeModeOfFristScreenMeetingUIWnd: function () {
    let ret = zoomuicontroller.MeetingUI_IsMinimizeModeOfFristScreenMeetingUIWnd();
    console.log('IsMinimizeModeOfFristScreenMeetingUIWnd', ret);
  },
  swapToShowShareViewOrVideo: function (bToDisplayShare) {
    let opts = {
      bToDisplayShare: bToDisplayShare
    }
    let ret = zoomuicontroller.MeetingUI_SwapToShowShareViewOrVideo(opts);
    console.log('SwapToShowShareViewOrVideo', ret);
  },
  isDisplayingShareViewOrVideo: function () {
    let ret = zoomuicontroller.MeetingUI_IsDisplayingShareViewOrVideo();
    console.log('IsDisplayingShareViewOrVideo', ret);
  },
  canSwapToShowShareViewOrVideo: function () {
    let ret = zoomuicontroller.MeetingUI_CanSwapToShowShareViewOrVideo();
    console.log('CanSwapToShowShareViewOrVideo', ret);
  },
  reset: function () {
    let ret = zoomconfiguration.MeetingConfig_Reset();
    console.log('Reset', ret);
  },
  enableAutoAdjustSpeakerVolumeWhenJoinAudio: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoAdjustSpeakerVolumeWhenJoinAudio(opts);
    console.log('EnableAutoAdjustSpeakerVolumeWhenJoinAudio', ret);
  },
  enableAutoAdjustMicVolumeWhenJoinAudio: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoAdjustMicVolumeWhenJoinAudio(opts);
    console.log('EnableAutoAdjustMicVolumeWhenJoinAudio', ret);
  },
  configDSCP: function (dscpAudio, dscpVideo, bReset) {
    let opts = {
      dscpAudio: dscpAudio,
      dscpVideo: dscpVideo,
      bReset: bReset
    }
    let ret = zoomconfiguration.MeetingConfig_ConfigDSCP(opts);
    console.log('ConfigDSCP', ret);
  },
  enableHideFullPhoneNumber4PureCallinUser: function (bHide) {
    let opts = {
      bHide: bHide
    }
    let ret = zoomconfiguration.MeetingConfig_EnableHideFullPhoneNumber4PureCallinUser(opts);
    console.log('EnableHideFullPhoneNumber4PureCallinUser', ret);
  },
  enableLengthLimitationOfMeetingNumber: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLengthLimitationOfMeetingNumber(opts);
    console.log('EnableLengthLimitationOfMeetingNumber', ret);
  },
  enableShareIOSDevice: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableShareIOSDevice(opts);
    console.log('EnableShareIOSDevice', ret);
  },
  enableShareWhiteBoard: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableShareWhiteBoard(opts);
    console.log('EnableShareWhiteBoard', ret);
  },
  forceDisableMultiShare: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_ForceDisableMultiShare(opts);
    console.log('ForceDisableMultiShare', ret);
  },
  setMaxDurationForOnlyHostInMeeting: function (nDuration) {
    let opts = {
      nDuration: nDuration
    }
    let ret = zoomconfiguration.MeetingConfig_SetMaxDurationForOnlyHostInMeeting(opts);
    console.log('SetMaxDurationForOnlyHostInMeeting', ret);
  },
  enableLocalRecordingConvertProgressBarDialog: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLocalRecordingConvertProgressBarDialog(opts);
    console.log('EnableLocalRecordingConvertProgressBarDialog', ret);
  },
  enableApproveRemoteControlDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableApproveRemoteControlDlg(opts);
    console.log('EnableApproveRemoteControlDlg', ret);
  },
  enableDeclineRemoteControlResponseDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableDeclineRemoteControlResponseDlg(opts);
    console.log('EnableDeclineRemoteControlResponseDlg', ret);
  },
  enableLeaveMeetingOptionForHost: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLeaveMeetingOptionForHost(opts);
    console.log('EnableLeaveMeetingOptionForHost', ret);
  },
  enableVideoButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableVideoButtonOnMeetingUI(opts);
    console.log('EnableVideoButtonOnMeetingUI', ret);
  },
  enableEnterAndExitFullScreenButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableEnterAndExitFullScreenButtonOnMeetingUI(opts);
    console.log('EnableEnterAndExitFullScreenButtonOnMeetingUI', ret);
  },
  redirectClickShareBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickShareBTNEvent(opts);
    console.log('RedirectClickShareBTNEvent', ret);
  },
  redirectClickEndMeetingBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickEndMeetingBTNEvent(opts);
    console.log('RedirectClickEndMeetingBTNEvent', ret);
  },
  redirectFreeMeetingEndingReminderDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectFreeMeetingEndingReminderDlg(opts);
    console.log('RedirectFreeMeetingEndingReminderDlg', ret);
  },
  redirectClickCustomLiveStreamMenuEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickCustomLiveStreamMenuEvent(opts);
    console.log('RedirectClickCustomLiveStreamMenuEvent', ret);
  },
  redirectClickParticipantListBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickParticipantListBTNEvent(opts);
    console.log('RedirectClickParticipantListBTNEvent', ret);
  },
  redirectClickCCBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickCCBTNEvent(opts);
    console.log('RedirectClickCCBTNEvent', ret);
  },
  redirectMeetingWarningMsg: function (bRedirectBadNetwork, bRedirectWarnHighCPU) {
    let opts = {
      bRedirectBadNetwork: bRedirectBadNetwork,
      bRedirectWarnHighCPU: bRedirectWarnHighCPU
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectMeetingWarningMsg(opts);
    console.log('RedirectMeetingWarningMsg', ret);
  },
  enableToolTipsShow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableToolTipsShow(opts);
    console.log('EnableToolTipsShow', ret);
  },
  enableAirplayInstructionWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAirplayInstructionWindow(opts);
    console.log('EnableAirplayInstructionWindow', ret);
  },
  enableClaimHostFeature: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableClaimHostFeature(opts);
    console.log('EnableClaimHostFeature', ret);
  },
  enableAutoHideJoinAudioDialog: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoHideJoinAudioDialog(opts);
    console.log('EnableAutoHideJoinAudioDialog', ret);
  },
  alwaysShowIconOnTaskBar: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_AlwaysShowIconOnTaskBar(opts);
    console.log('AlwaysShowIconOnTaskBar', ret);
  },
  disableSplitScreenModeUIElements: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableSplitScreenModeUIElements(opts);
    console.log('DisableSplitScreenModeUIElements', ret);
  },
  setShowAudioUseComputerSoundChkbox: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowAudioUseComputerSoundChkbox(opts);
    console.log('SetShowAudioUseComputerSoundChkbox', ret);
  },
  setShowCallInTab: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowCallInTab(opts);
    console.log('SetShowCallInTab', ret);
  },
  setShowCallMeTab: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowCallMeTab(opts);
    console.log('SetShowCallMeTab', ret);
  },
  disableTopMostAttr4SettingDialog: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableTopMostAttr4SettingDialog(opts);
    console.log('DisableTopMostAttr4SettingDialog', ret);
  },
  enableGrabShareWithoutReminder: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableGrabShareWithoutReminder(opts);
    console.log('EnableGrabShareWithoutReminder', ret);
  },
  enableShowShareSwitchMultiToSingleConfirmDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableShowShareSwitchMultiToSingleConfirmDlg(opts);
    console.log('EnableShowShareSwitchMultiToSingleConfirmDlg', ret);
  },
  disableFreeMeetingRemainTimeNotify: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableFreeMeetingRemainTimeNotify(opts);
    console.log('DisableFreeMeetingRemainTimeNotify', ret);
  },
  disableFreeMeetingRemainTimeNotify: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableFreeMeetingRemainTimeNotify(opts);
    console.log('DisableFreeMeetingRemainTimeNotify', ret);
  },
  hideChatItemOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideChatItemOnMeetingUI(opts);
    console.log('HideChatItemOnMeetingUI', ret);
  },
  hideRecordItemOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideRecordItemOnMeetingUI(opts);
    console.log('HideRecordItemOnMeetingUI', ret);
  },
  hideUpgradeFreeMeetingButton: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideUpgradeFreeMeetingButton(opts);
    console.log('HideUpgradeFreeMeetingButton', ret);
  },
  setShowInviteDlgTabPage: function (tabPage, bShow) {
    let opts = {
      tabPage: tabPage,
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowInviteDlgTabPage(opts);
    console.log('SetShowInviteDlgTabPage', ret);
  },
  setShowH323SubTabPage: function (tabPage, bShow) {
    let opts = {
      tabPage: tabPage,
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowH323SubTabPage(opts);
    console.log('SetShowH323SubTabPage', ret);
  },
  hideUpgradeWarningMsgForFreeUserWhenSchedule: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideUpgradeWarningMsgForFreeUserWhenSchedule(opts);
    console.log('HideUpgradeWarningMsgForFreeUserWhenSchedule', ret);
  },
  hideSwitchCameraButton: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideSwitchCameraButton(opts);
    console.log('HideSwitchCameraButton', ret);
  },
  hideCopyUrlOnInviteWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideCopyUrlOnInviteWindow(opts);
    console.log('HideCopyUrlOnInviteWindow', ret);
  },
  hideCopyInvitationOnInviteWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideCopyInvitationOnInviteWindow(opts);
    console.log('HideCopyInvitationOnInviteWindow', ret);
  },
  hideKeypadButtonOnMeetingWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideKeypadButtonOnMeetingWindow(opts);
    console.log('HideKeypadButtonOnMeetingWindow', ret);
  },
  hideRemoteControlOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideRemoteControlOnMeetingUI(opts);
    console.log('HideRemoteControlOnMeetingUI', ret);
  },
  hideQAOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideQAOnMeetingUI(opts);
    console.log('HideQAOnMeetingUI', ret);
  },
  hidePollOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HidePollOnMeetingUI(opts);
    console.log('HidePollOnMeetingUI', ret);
  },
  enableInputMeetingPasswordDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInputMeetingPasswordDlg(opts);
    console.log('EnableInputMeetingPasswordDlg', ret);
  },
  enableInputMeetingScreenNameDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInputMeetingScreenNameDlg(opts);
    console.log('EnableInputMeetingScreenNameDlg', ret);
  },
  redirectWebinarNeedRegister: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectWebinarNeedRegister(opts);
    console.log('RedirectWebinarNeedRegister', ret);
  },
  redirectEndOtherMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectEndOtherMeeting(opts);
    console.log('RedirectEndOtherMeeting', ret);
  },
  enableForceAutoStartMyVideoWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableForceAutoStartMyVideoWhenJoinMeeting(opts);
    console.log('EnableForceAutoStartMyVideoWhenJoinMeeting', ret);
  },
  enableForceAutoStopMyVideoWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableForceAutoStopMyVideoWhenJoinMeeting(opts);
    console.log('EnableForceAutoStopMyVideoWhenJoinMeeting', ret);
  },
  disableAutoShowSelectJoinAudioDlgWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(opts);
    console.log('DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting', ret);
  },
  disableRemoteCtrlCopyPasteFeature: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableRemoteCtrlCopyPasteFeature(opts);
    console.log('DisableRemoteCtrlCopyPasteFeature', ret);
  },
  setShowVideoOptimizeChkbox: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowVideoOptimizeChkbox(opts);
    console.log('SetShowVideoOptimizeChkbox', ret);
  },
  getRequiredInfoType: function () {
    let ret = zoomconfiguration.MeetingConfig_GetRequiredInfoType();
    console.log('GetRequiredInfoType', ret);
  },
  inputMeetingPasswordAndScreenName: function (meeting_Password, screenName) {
    let opts = {
      meeting_Password: meeting_Password,
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputMeetingPasswordAndScreenName(opts);
    console.log('InputMeetingPasswordAndScreenName', ret);
  },
  inputMeetingIDAndScreenName: function (meetingID, screenName) {
    let opts = {
      meetingID: meetingID,
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputMeetingIDAndScreenName(opts);
    console.log('InputMeetingIDAndScreenName', ret);
  },
  inputMeetingScreenName: function (screenName) {
    let opts = {
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputMeetingScreenName(opts);
    console.log('InputMeetingScreenName', ret);
  },
  meetingPasswordAndScreenNameHandler_Cancel: function () {
    let ret = zoomconfiguration.MeetingConfig_MeetingPasswordAndScreenNameHandler_Cancel();
    console.log('MeetingPasswordAndScreenNameHandler_Cancel', ret);
  },
  getWebinarNeedRegisterType: function () {
    let ret = zoomconfiguration.MeetingConfig_GetWebinarNeedRegisterType();
    console.log('GetWebinarNeedRegisterType', ret);
  },
  getWebinarRegisterUrl: function () {
    let ret = zoomconfiguration.MeetingConfig_GetWebinarRegisterUrl();
    console.log('GetWebinarRegisterUrl', ret);
  },
  releaseRegisterWebinarByUrl: function () {
    let ret = zoomconfiguration.MeetingConfig_ReleaseRegisterWebinarByUrl();
    console.log('ReleaseRegisterWebinarByUrl', ret);
  },
  inputWebinarRegisterEmailAndScreenName: function (email, screenName) {
    let opts = {
      email: email,
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputWebinarRegisterEmailAndScreenName(opts);
    console.log('InputWebinarRegisterEmailAndScreenName', ret);
  },
  cancelRegisterWebinarByEmail: function () {
    let ret = zoomconfiguration.MeetingConfig_CancelRegisterWebinarByEmail();
    console.log('CancelRegisterWebinarByEmail', ret);
  },
  disableAdvancedFeatures4GeneralSetting: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomsetui.SettingUI_DisableAdvancedFeatures4GeneralSetting(opts);
    console.log('DisableAdvancedFeatures4GeneralSetting', ret);
  },
  disableAccountSettingTabPage: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomsetui.SettingUI_DisableAccountSettingTabPage(opts);
    console.log('DisableAccountSettingTabPage', ret);
  },
  confSettingDialogShownTabPage: function (number) {
    let opts = {
      number: number
    }
    let ret = zoomsetui.SettingUI_ConfSettingDialogShownTabPage(opts);
    console.log('ConfSettingDialogShownTabPage', ret);
  },
  queryOverallStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryOverallStatisticInfo();
    console.log('QueryOverallStatisticInfo', ret);
  },
  queryAudioStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryAudioStatisticInfo();
    console.log('QueryAudioStatisticInfo', ret);
  },
  queryVideoStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryVideoStatisticInfo();
    console.log('QueryVideoStatisticInfo', ret);
  },
  queryShareStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryShareStatisticInfo();
    console.log('QueryShareStatisticInfo', ret);
  },
  enableAlwaysShowMeetingControls: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaccessibility.Setting_EnableAlwaysShowMeetingControls(opts);
    console.log('EnableAlwaysShowMeetingControls', ret);
  },
  isAlwaysShowMeetingControlsEnable: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaccessibility.Setting_IsAlwaysShowMeetingControlsEnable(opts);
    console.log('IsAlwaysShowMeetingControlsEnable', ret);
  },
  enableZoomAuthRealNameMeetingUIShown: function (b_enable) {
    let opts = {
      b_enable: b_enable
    }
    let ret = zoomsms.EnableZoomAuthRealNameMeetingUIShown(opts);
    console.log('EnableZoomAuthRealNameMeetingUIShown', ret);
  },
  getResendSMSVerificationCodeHandler: function () {
    let ret = zoomsms.GetResendSMSVerificationCodeHandler();
    console.log('GetResendSMSVerificationCodeHandler', ret);
  },
  retrieve: function (country_code, phone_number) {
    let opts = {
      country_code: country_code,
      phone_number: phone_number
    }
    let ret = zoomsms.Retrieve(opts);
    console.log('Retrieve', ret);
  },
  retrieve_CancelAndLeaveMeeting: function () {
    let ret = zoomsms.Retrieve_CancelAndLeaveMeeting();
    console.log('Retrieve_CancelAndLeaveMeeting', ret);
  },
  getReVerifySMSVerificationCodeHandler: function () {
    let ret = zoomsms.GetReVerifySMSVerificationCodeHandler();
    console.log('GetReVerifySMSVerificationCodeHandler', ret);
  },
  verify: function (country_code, phone_number, verification_code) {
    let opts = {
      country_code: country_code,
      phone_number: phone_number,
      verification_code: verification_code
    }
    let ret = zoomsms.Verify(opts);
    console.log('Verify', ret);
  },
  verify_CancelAndLeaveMeeting: function () {
    let ret = zoomsms.Verify_CancelAndLeaveMeeting();
    console.log('Verify_CancelAndLeaveMeeting', ret);
  },
  getSupportPhoneNumberCountryList: function () {
    let ret = zoomsms.GetSupportPhoneNumberCountryList();
    console.log('GetSupportPhoneNumberCountryList', ret);
  },
  setDefaultCellPhoneInfo: function (country_code, phone_number) {
    let opts = {
      country_code: country_code,
      phone_number: phone_number
    }
    let ret = zoomsms.SetDefaultCellPhoneInfo(opts);
    console.log('SetDefaultCellPhoneInfo', ret);
  }
}

ipcMain.on('asynchronous-message', (event, arg1, arg2, arg3, arg4, arg5) => {
  functionObj[arg1](arg2, arg3, arg4, arg5);
})

app.on('window-all-closed', function () {
  if (process.platform != 'darwin') {
    zoomsdk.CleanUPSDK();
    app.quit();
  }
});

function createWindow() {
  // Create the browser window.
  showDomainwindow();
}

app.on('ready', createWindow)