const { app, BrowserWindow, ipcMain, nativeTheme } = require('electron');
const { ZOOM_TYPE_OS_TYPE, ZoomSDK_LANGUAGE_ID, ZoomSDKError, ZoomAuthResult, ZoomLoginStatus, ZoomMeetingStatus,
  ZoomMeetingUIFloatVideoType, SDKCustomizedStringType, SDKCustomizedURLType, ZoomAPPLocale } = require('../lib/settings.js');
try {
  require('../lib/electron_sdk_pb.js');
} catch (error) {
  console.log('Please execute npm install google-protobuf at root of the project \nRefer to README.md')
  app.exit()
  return
}
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
let zoomrecording;
let zoomparticipantsctrl;
let zoomcustomizedresource;
let zoompremeeting;
let zoomrawdata;
let zoomsms;
let zoomsetui;
let zoomsetstatistic;
let zoomsetaccessibility;
let hasRDLicense;
let autoCloseYUV = false;
let hasLogin = false;
let startOrJoinWithRawdata;

function sdkauthCB(status) {
  if (ZoomAuthResult.AUTHRET_SUCCESS == status) {
    let opts = {
      meetingstatuscb: meetingstatuscb,
      meetinguserjoincb: meetinguserjoincb,
      meetinguserleftcb: meetinguserleftcb,
      meetinghostchangecb: meetinghostchangecb
    }
    zoommeeting = zoomsdk.GetMeeting(opts);
    app.zoommeeting = zoommeeting;
    zoomparticipantsctrl = zoommeeting.GetMeetingParticipantsCtrl(opts);
    app.zoomparticipantsctrl = zoomparticipantsctrl;
    zoomrawdata = zoomsdk.RawData();
    hasRDLicense = hasRawDataLicense();
    global.hasRDLicense = hasRDLicense;
    app.zoomrawdata = zoomrawdata;
    zoominfomod = zoommeeting.GetMeetingInfo();
    zoomuicontroller = zoommeeting.GetMeetingUICtrl();
    zoomannotation = zoommeeting.GetAnnotationCtrl();
    zoomshare = zoommeeting.GetMeetingShare();
    zoomh323 = zoommeeting.GetMeetingH323();
    zoomconfiguration = zoommeeting.GetMeetingConfiguration();
    zoomupdateaccount = zoommeeting.GetUpdateAccount();
    zoomrecording = zoommeeting.GetMeetingRecording();
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
}

function meetinguserleftcb(userList) {
}

function meetinghostchangecb(userList) {
}

function onUserAudioStatusChange(result) {
}

function onUserVideoStatusChange(result) {
}

function meetingstatuscb(status, result) {
  switch (status) {
    case ZoomMeetingStatus.MEETING_STATUS_CONNECTING:
      if (startOrJoinWithRawdata) {
        showYUVWindow();
      }
      YUVWindow ? YUVWindow.webContents.send('main-process-meetingstatus', 'connecting') : null;
      break;
    case ZoomMeetingStatus.MEETING_STATUS_DISCONNECTING:
    case ZoomMeetingStatus.MEETING_STATUS_RECONNECTING:
      if (startOrJoinWithRawdata) {
        YUVWindow ? YUVWindow.webContents.send('main-process-stopclient') : null;
      }
      showWaitingWindow();
      break;
    case ZoomMeetingStatus.MEETING_STATUS_INMEETING:
      showInMeetingWindow();
      YUVWindow ? YUVWindow.webContents.send('main-process-meetingstatus', 'inmeeting') : null;
      break
    case ZoomMeetingStatus.MEETING_STATUS_FAILED:
    case ZoomMeetingStatus.MEETING_STATUS_ENDED:
      startOrJoinWithRawdata = false
      if (hasLogin) {
        showStartJoinWindow();
      } else {
        showLoginWindow();
      }
      break;
    case ZoomMeetingStatus.MEETING_STATUS_IN_WAITING_ROOM:
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
  zoomvideo.SetMeetingVideoStatusCB(null);
  zoommeeting.GetMeetingShare().SetOnSharingStatusCB(null);
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
      if (!autoCloseYUV) {
        zoommeeting.LeaveMeeting(opt);
      }
      YUVWindow = null;
      if (startjoinWindow) {
        startjoinWindow.close();
        startjoinWindow = null;
      }
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
  startjoinWindow ? startjoinWindow.webContents.send('main-process-onDirectShareStatusUpdate', status) : null;
}

function hasRawDataLicense() {
  let ret = zoomrawdata.HasRawDataLicense();
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
    zoomcustomizedresource.Resource_AddCustomizedStringResource(optCustomizedResouce);
    zoomcustomizedresource.Resource_AddCustomizedURLResource(optCustomizedURLResouce);
    zoomcustomizedresource.Resource_AddCustomizedPictureResource(optCustomizedPictureResouce);
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
  setTeamIdentifier: function (identifier) {
    const opts = {
      identifier: identifier
    }
    var ret = zoomsdk.SetTeamIdentifier(opts);
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
    return ret;
  },
  login: function (username, psw) {
    if (username && psw) {
      showWaitingWindow();
    }
    zoomauth.Login(username, psw, false);
  },
  loginWithSSOToken: function (ssotoken) {
    let ret = zoomauth.LoginWithSSOToken(ssotoken);
    return ret;
  },
  logout: function () {
    zoomauth.Logout();
    showLoginWindow();
  },
  authWithJwtToken: function (sdk_context) {
    let ret = zoomauth.AuthWithJwtToken(sdk_context);
    if (ret == 0) {
      showWaitingWindow();
    }
  },
  start: function (meetingnum, withRawdata) {
    startOrJoinWithRawdata = withRawdata;
    var opt = {
      meetingnum: meetingnum,
      withRawdata: withRawdata
    }
    let ret = zoommeeting.StartMeeting(opt);
    return ret;
  },
  join: function (meetingnum, username, withRawdata) {
    startOrJoinWithRawdata = withRawdata;
    var opt = {
      meetingnum: meetingnum,
      username: username,
      withRawdata: withRawdata
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
    return ret;
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
    return ret;
  },
  end: function (endMeeting) {
    var opt = {
      endMeeting: endMeeting
    }
    let ret = zoommeeting.LeaveMeeting(opt);
    return ret;
  },
  lock: function () {
    let ret = zoommeeting.Lock_Meeting();
    return ret;
  },
  unlock: function () {
    let ret = zoommeeting.Un_lock_Meeting();
    return ret;
  },
  getSharingConnQuality: function () {
    let ret = zoommeeting.GetSharingConnQuality();
    return ret;
  },
  getVideoConnQuality: function () {
    let ret = zoommeeting.GetVideoConnQuality();
    return ret;
  },
  getAudioConnQuality: function () {
    let ret = zoommeeting.GetAudioConnQuality();
    return ret;
  },
  getParticipantsList: function () {
    let ret = zoomparticipantsctrl.GetParticipantsList();
    return ret;
  },
  getUserInfoByUserID: function (userid) {
    let ret = zoomparticipantsctrl.GetUserInfoByUserID(userid);
    return ret;
  },
  handleZoomWebUriProtocolAction: function (protocol_action) {
    let ret = zoommeeting.HandleZoomWebUriProtocolAction(protocol_action);
    return ret;
  },
  getMeetingTopic: function () {
    let ret = zoominfomod.GetMeetingTopic();
    return ret;
  },
  getMeetingType: function () {
    let ret = zoominfomod.GetMeetingType();
    return ret;
  },
  getMeetingNumber: function () {
    let ret = zoominfomod.GetMeetingNumber();
    return ret;
  },
  getMeetingID: function () {
    let ret = zoominfomod.GetMeetingID();
    return ret;
  },
  getInviteEmailTeamplate: function () {
    let ret = zoominfomod.GetInviteEmailTeamplate();
    return ret;
  },
  getInviteEmailTitle: function () {
    let ret = zoominfomod.GetInviteEmailTitle();
    return ret;
  },
  getJoinMeetingUrl: function () {
    let ret = zoominfomod.GetJoinMeetingUrl();
    return ret;
  },
  getMeetingHostTag: function () {
    let ret = zoominfomod.GetMeetingHostTag();
    return ret;
  },
  checkingIsInternalMeeting: function () {
    let ret = zoominfomod.CheckingIsInternalMeeting();
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
    return ret;
  },
  swtichToAcitveSpeaker: function () {
    let ret = zoomuicontroller.MeetingUI_SwtichToAcitveSpeaker();
    return ret;
  },
  moveFloatVideoWnd: function () {
    let opts = {
      left: '200',
      top: '200'
    }
    let ret = zoomuicontroller.MeetingUI_MoveFloatVideoWnd(opts);
    return ret;
  },
  showSharingToolbar: function (show) {
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowSharingToolbar(opts);
  },
  switchFloatVideoToActiveSpkMod: function () {
    let ret = zoomuicontroller.MeetingUI_SwitchFloatVideoToActiveSpkMod();
  },
  changeFloatoActiveSpkVideoSize: function () {
    let obj = {
      floatvideotype: ZoomMeetingUIFloatVideoType.FLOATVIDEO_Large
    }
    let ret = zoomuicontroller.MeetingUI_ChangeFloatoActiveSpkVideoSize(obj);
  },
  switchFloatVideoToGalleryMod: function () {
    let ret = zoomuicontroller.MeetingUI_SwitchFloatVideoToGalleryMod();
    return ret;
  },
  showParticipantsListWnd: function (show) {
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowParticipantsListWnd(opts);
    return ret;
  },
  showBottomFloatToolbarWnd: function (show) {
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowBottomFloatToolbarWnd(opts);
  },
  showJoinAudioDlg: function () {
    let ret = zoomuicontroller.MeetingUI_ShowJoinAudioDlg();
  },
  hideJoinAudioDlg: function () {
    let ret = zoomuicontroller.MeetingUI_HideJoinAudioDlg();
  },
  getWallViewPageInfo: function (arg2, arg3) {
    let opts = {
      currentPage: arg2,
      totalPages: arg3
    }
    let ret = zoomuicontroller.MeetingUI_GetWallViewPageInfo(opts);
  },
  showPreOrNextPageVideo: function (show) {
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowPreOrNextPageVideo(opts);
    return ret;
  },
  showSharingFrameWindows: function (show) {
    let opts = {
      show: show
    }
    let ret = zoomuicontroller.MeetingUI_ShowSharingFrameWindows(opts);
    return ret;
  },
  switchSplitScreenMode: function (isSwitch) {
    let opts = {
      isSwitch: isSwitch
    }
    let ret = zoomuicontroller.MeetingUI_SwitchSplitScreenMode(opts);
    return ret;
  },
  getCurrentSplitScreenModeInfo: function (arg2, arg3) {
    let opts = {
      bZNSupportSplitScreen: arg2,
      bZNInSplitScreenMode: arg3
    }
    let ret = zoomuicontroller.MeetingUI_GetCurrentSplitScreenModeInfo(opts);
    return ret;
  },
  isAnnotaionDisable: function () {
    let ret = zoomannotation.Annotaion_IsAnnotaionDisable();
    return ret;
  },
  startAnnotation: function (viewtype, left, top) {
    let opts = {
      viewtype: viewtype,
      left: '300',
      top: '300'
    }
    let ret = zoomannotation.Annotaion_StartAnnotation(opts);
  },
  stopAnnotation: function (viewtype) {
    let ret = zoomannotation.Annotaion_StopAnnotation(viewtype);
  },
  setTool: function (viewtype, tooltype) {
    let opts = {
      viewtype: viewtype,
      tooltype: tooltype
    }
    let ret = zoomannotation.Annotaion_SetTool(opts);
  },
  setClear: function (viewtype, cleartype) {
    let opts = {
      viewtype: viewtype,
      cleartype: cleartype
    }
    let ret = zoomannotation.Annotaion_Clear(opts);
  },
  setColor: function (viewtype, color) {
    let opts = {
      viewtype: viewtype,
      color: color
    }
    let ret = zoomannotation.Annotaion_SetColor(opts);
  },
  SetLineWidth: function (viewtype, lineWidth) {
    let opts = {
      viewtype: viewtype,
      lineWidth: lineWidth
    }
    let ret = zoomannotation.Annotaion_SetLineWidth(opts);
  },
  undo: function (viewtype) {
    let opts = {
      viewtype: viewtype
    }
    let ret = zoomannotation.Annotaion_Undo(opts)
  },
  redo: function (viewtype) {
    let opts = {
      viewtype: viewtype
    }
    let ret = zoomannotation.Annotaion_Redo(opts)
  },
  muteAudio: function (userid, allowunmutebyself) {
    let opts = {
      userid: userid,
      allowunmutebyself: allowunmutebyself
    }
    let ret = zoomaudio.MeetingAudio_MuteAudio(opts);
  },
  unMuteAudio: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomaudio.MeetingAudio_UnMuteAudio(opts);
  },
  joinVoip: function () {
    let ret = zoomaudio.MeetingAudio_JoinVoip();
  },
  leaveVoip: function () {
    let ret = zoomaudio.MeetingAudio_LeaveVoip();
  },
  enablePlayChimeWhenEnterOrExit: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomaudio.MeetingAudio_EnablePlayChimeWhenEnterOrExit(opts);
  },
  muteVideo: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_MuteVideo(opts);
  },
  unMuteVideo: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_UnMuteVideo(opts);
  },
  pinVideo: function (userid) {
    let opts = {
      bPin: true,
      bFirstView: true,
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_PinVideo(opts);
  },
  spotlightVideo: function (userid) {
    let opts = {
      bSpotlight: true,
      userid: userid
    }
    let ret = zoomvideo.MeetingVideo_SpotlightVideo(opts);
  },
  hideOrShowNoVideoUserOnVideoWall: function (bHide) {
    let opts = {
      bHide: bHide
    }
    let ret = zoomvideo.MeetingVideo_HideOrShowNoVideoUserOnVideoWall(opts);
  },
  selectCamera: function (zn_deviceId) {
    let opts = {
      zn_deviceId: zn_deviceId
    }
    let ret = zoomsetvideo.Setting_SelectVideoCamera(opts);
  },
  getCameraList: function () {
    let ret = zoomsetvideo.Setting_GetCameraList();
  },
  enableVideoMirrorEffect: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetvideo.Setting_EnableVideoMirrorEffect(opts);
  },
  enableFaceBeautyEffect: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetvideo.Setting_EnableFaceBeautyEffect(opts);
  },
  isMirrorEffectEnabled: function () {
    let ret = zoomsetvideo.Checking_IsMirrorEffectEnabled();
  },
  isFaceBeautyEffectEnabled: function () {
    let ret = zoomsetvideo.Checking_IsFaceBeautyEffectEnabled();
  },
  enableStereoAudio: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableStereoAudio(opts);
  },
  isStereoAudioEnable: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsStereoAudioEnable(opts);
  },
  enableMicOriginalInput: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableMicOriginalInput(opts);
  },
  enableHoldSpaceKeyToSpeak: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableHoldSpaceKeyToSpeak(opts);
  },
  isHoldSpaceKeyToSpeakEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsHoldSpaceKeyToSpeakEnabled(opts);
  },
  enableAlwaysMuteMicWhenJoinVoip: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAlwaysMuteMicWhenJoinVoip(opts);
  },
  isAlwaysMuteMicWhenJoinVoipEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsAlwaysMuteMicWhenJoinVoipEnabled(opts);
  },
  enableSuppressAudioNotify: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableSuppressAudioNotify(opts);
  },
  isSuppressAudioNotifyEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsSuppressAudioNotifyEnabled(opts);
  },
  enableEchoCancellation: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_EnableEchoCancellation(opts);
  },
  isEchoCancellationEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsEchoCancellationEnabled(opts);
  },
  setMicVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_SetMicVol(opts);
  },
  getMicVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_GetMicVol(opts);
  },
  setSpeakerVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_SetSpeakerVol(opts);
  },
  getSpeakerVol: function (value) {
    let opts = {
      value: value
    }
    let ret = zoomsetaudio.Setting_GetSpeakerVol(opts);
  },
  isMicOriginalInputEnable: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaudio.Setting_IsMicOriginalInputEnable(opts);
  },
  enableHDVideo: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableHDVideo(opts);
  },
  isHDVideoEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsHDVideoEnabled(opts);
  },
  enableAlwaysShowNameOnVideo: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableAlwaysShowNameOnVideo(opts);
  },
  isAlwaysShowNameOnVideoEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsAlwaysShowNameOnVideoEnabled(opts);
  },
  enableAutoTurnOffVideoWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableAutoTurnOffVideoWhenJoinMeeting(opts);
  },
  isAutoTurnOffVideoWhenJoinMeetingEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsAutoTurnOffVideoWhenJoinMeetingEnabled(opts);
  },
  enableAlwaysUse16v9: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableAlwaysUse16v9(opts);
  },
  isAlwaysUse16v9: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsAlwaysUse16v9(opts);
  },
  enableSpotlightSelf: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableSpotlightSelf(opts);
  },
  isSpotlightSelfEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsSpotlightSelfEnabled(opts);
  },
  enableHardwareEncode: function (bEnable, encodeType) {
    let opts = {
      bEnable: bEnable,
      encodeType: encodeType
    }
    let ret = zoomsetvideo.Setting_EnableHardwareEncode(opts);
  },
  isHardwareEncodeEnabled: function (bEnable, encodeType) {
    let opts = {
      bEnable: bEnable,
      encodeType: encodeType
    }
    let ret = zoomsetvideo.Setting_IsHardwareEncodeEnabled(opts);
  },
  enable49VideoesInGallaryView: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_Enable49VideoesInGallaryView(opts);
  },
  is49VideoesInGallaryViewEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_Is49VideoesInGallaryViewEnabled(opts);
  },
  enableHideNoVideoUsersOnWallView: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableHideNoVideoUsersOnWallView(opts);
  },
  isHideNoVideoUsersOnWallViewEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_IsHideNoVideoUsersOnWallViewEnabled(opts);
  },
  enableVideoPreviewDialog: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetvideo.Setting_EnableVideoPreviewDialog(opts);
  },
  isVideoPreviewDialogEnabled: function () {
    let ret = zoomsetvideo.Setting_IsVideoPreviewDialogEnabled();
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
  },
  selectSpeaker: function (zn_deviceId, zn_deviceName) {
    let opts = {
      zn_deviceId: zn_deviceId,
      zn_deviceName: zn_deviceName
    }
    let ret = zoomsetaudio.Setting_SelectSpeaker(opts);
  },
  getSpeakerList: function () {
    zoomsetaudio.Setting_GetSpeakerList();
  },
  isAutoJoinAudioEnabled: function () {
    let ret = zoomsetaudio.Checking_IsAutoJoinAudioEnabled();
  },
  isAutoAdjustMicEnabled: function () {
    let ret = zoomsetaudio.Checking_IsAutoAdjustMicEnabled();
  },
  enableAutoJoinAudio: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAutoJoinAudio(opts);
  },
  enableAutoAdjustMic: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetaudio.Setting_EnableAutoAdjustMic(opts);
  },
  showSettingDlg: function () {
    let ret = zoomsetting.SettingUI_ShowTheSettingDlg();
  },
  hideSettingDlg: function () {
    let ret = zoomsetting.SettingUI_HideSettingDlg();
  },
  enableDualScreenMode: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableDualScreenMode(opts);
  },
  turnOffAeroModeInSharing: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_TurnOffAeroModeInSharing(opts);
  },
  enableAutoFitToWindowWhenViewSharing: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFitToWindowWhenViewSharing(opts);
  },
  enableAutoFullScreenVideoWhenJoinMeeting: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFullScreenVideoWhenJoinMeeting(opts);
  },
  enableSplitScreenMode: function (zn_bEnable) {
    let opts = {
      zn_bEnable: zn_bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableSplitScreenMode(opts);
  },
  isDualScreenModeEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsDualScreenModeEnabled();
  },
  isAeroModeInSharingTurnOff: function () {
    let ret = zoomsetgeneral.Checking_IsAeroModeInSharingTurnOff();
  },
  isAutoFitToWindowWhenViewSharingEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsAutoFitToWindowWhenViewSharingEnabled();
  },
  isAutoFullScreenVideoWhenJoinMeetingEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsAutoFullScreenVideoWhenJoinMeetingEnabled();
  },
  isSplitScreenModeEnabled: function () {
    let ret = zoomsetgeneral.Checking_IsSplitScreenModeEnabled();
  },
  enableAutoFullScreenVideoWhenViewShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAutoFullScreenVideoWhenViewShare(opts);
  },
  isAutoFullScreenVideoWhenViewShareEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsAutoFullScreenVideoWhenViewShareEnabled(opts);
  },
  enableDisplayReminderWindowWhenExit: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableDisplayReminderWindowWhenExit(opts);
  },
  isDisplayReminderWindowWhenExitEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsDisplayReminderWindowWhenExitEnabled(opts);
  },
  enableShowMyMeetingElapseTime: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableShowMyMeetingElapseTime(opts);
  },
  isShowMyMeetingElapseTimeEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsShowMyMeetingElapseTimeEnabled(opts);
  },
  isCurrentOSSupportAccelerateGPUWhenShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsCurrentOSSupportAccelerateGPUWhenShare(opts);
  },
  enableAccelerateGPUWhenShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableAccelerateGPUWhenShare(opts);
  },
  isAccelerateGPUWhenShareEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsAccelerateGPUWhenShareEnabled(opts);
  },
  enableRemoteControlAllApplications: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_EnableRemoteControlAllApplications(opts);
  },
  isRemoteControlAllApplicationsEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetgeneral.Setting_IsRemoteControlAllApplicationsEnabled(opts);
  },
  setRecordingPath: function (zn_szPath) {
    let opts = {
      zn_szPath: zn_szPath
    }
    let ret = zoomsetrecord.Setting_SetRecordingPath(opts);
  },
  getRecordingPath: function () {
    let ret = zoomsetrecord.Getting_GetRecordingPath();
  },
  canGetCloudRecordingStorageInfo: function (bCan) {
    let opts = {
      bCan: bCan
    }
    let ret = zoomsetrecord.Setting_CanGetCloudRecordingStorageInfo(opts);
  },
  getCloudRecordingStorageInfo: function () {
    let ret = zoomsetrecord.Getting_GetCloudRecordingStorageInfo();
  },
  getRecordingManagementURL: function () {
    let ret = zoomsetrecord.Getting_GetRecordingManagementURL();
  },
  canGetRecordingManagementURL: function (bCan) {
    let opts = {
      bCan: bCan
    }
    let ret = zoomsetrecord.Setting_CanGetRecordingManagementURL(opts);
  },
  enableSelectRecordFileLocationAfterMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableSelectRecordFileLocationAfterMeeting(opts);
  },
  isSelectRecordFileLocationAfterMeetingEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsSelectRecordFileLocationAfterMeetingEnabled(opts);
  },
  enableMultiAudioStreamRecord: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableMultiAudioStreamRecord(opts);
  },
  isMultiAudioStreamRecordEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsMultiAudioStreamRecordEnabled(opts);
  },
  enableAddTimestampWatermark: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableAddTimestampWatermark(opts);
  },
  isAddTimestampWatermarkEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsAddTimestampWatermarkEnabled(opts);
  },
  enableOptimizeFor3rdPartyVideoEditor: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableOptimizeFor3rdPartyVideoEditor(opts);
  },
  isOptimizeFor3rdPartyVideoEditorEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsOptimizeFor3rdPartyVideoEditorEnabled(opts);
  },
  enableShowVideoThumbnailWhenShare: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnableShowVideoThumbnailWhenShare(opts);
  },
  isShowVideoThumbnailWhenShareEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsShowVideoThumbnailWhenShareEnabled(opts);
  },
  enablePlaceVideoNextToShareInRecord: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_EnablePlaceVideoNextToShareInRecord(opts);
  },
  isPlaceVideoNextToShareInRecordEnabled: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetrecord.Setting_IsPlaceVideoNextToShareInRecordEnabled(opts);
  },
  startAppShare: function (zn_hShare_app) {
    let opts = {
      zn_hShare_app: zn_hShare_app
    }
    let ret = zoomshare.MeetingShare_StartAppShare(opts);
  },
  startMonitorShare: function (zn_monitorID) {
    let opts = {
      zn_monitorID: zn_monitorID
    }
    let ret = zoomshare.MeetingShare_StartMonitorShare(opts);
  },
  stopShare: function () {
    let ret = zoomshare.MeetingShare_StopShare();
  },
  callOutH323: function () {
    let opts = {
      'deviceName': 'xxx',
      'deviceIP': '1234',
      'deviceE164num': '1234',
      'type': 1
    }
    let ret = zoomh323.H323_CallOutH323(opts);
  },
  cancelCallOutH323: function () {
    let ret = zoomh323.H323_CancelCallOutH323();
  },
  getH323Address: function () {
    let ret = zoomh323.H323_GetH323Address();
  },
  getH323Password: function () {
    let ret = zoomh323.H323_GetH323Password();
  },
  getCalloutH323DeviceList: function () {
    let ret = zoomh323.H323_GetCalloutH323DeviceList();
  },
  enableInviteButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInviteButtonOnMeetingUI(opts);
  },
  setFloatVideoPos: function () {
    let opts = {
      left: '10',
      top: '10'
    }
    let ret = zoomconfiguration.MeetingConfig_SetFloatVideoPos(opts);
  },
  setBottomFloatToolbarWndVisibility: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetBottomFloatToolbarWndVisibility(opts);
  },
  setSharingToolbarVisibility: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetSharingToolbarVisibility(opts);
  },
  setDirectShareMonitorID: function (monitorID) {
    let opts = {
      monitorID: monitorID
    }
    let ret = zoomconfiguration.MeetingConfig_SetDirectShareMonitorID(opts);
  },
  setMeetingUIPos: function () {
    let opts = {
      left: '10',
      top: '10'
    }
    let ret = zoomconfiguration.MeetingConfig_SetMeetingUIPos(opts);
  },
  disableWaitingForHostDialog: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableWaitingForHostDialog(opts);
  },
  disablePopupMeetingWrongPSWDlg: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisablePopupMeetingWrongPSWDlg(opts);
  },
  enableAutoEndOtherMeetingWhenStartMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoEndOtherMeetingWhenStartMeeting(opts);
  },
  enableLButtonDBClick4SwitchFullScreenMode: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLButtonDBClick4SwitchFullScreenMode(opts);
  },
  setFloatVideoWndVisibility: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetFloatVideoWndVisibility(opts);
  },
  prePopulateWebinarRegistrationInfo: function (email, userName) {
    let opts = {
      email: email,
      userName: userName
    }
    let ret = zoomconfiguration.MeetingConfig_PrePopulateWebinarRegistrationInfo(opts);
  },
  redirectClickAudioBTNEvent: function (bRedirect) {
    let opts = {
      bRedirect: bRedirect
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickAudioBTNEvent(opts);
  },
  redirectClickAudioMenuBTNEvent: function (bRedirect) {
    let opts = {
      bRedirect: bRedirect
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickAudioMenuBTNEvent(opts);
  },
  enableAudioButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAudioButtonOnMeetingUI(opts);
  },
  disableShowJoinMeetingWnd: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableShowJoinMeetingWnd(opts);
  },
  getReminderType: function () {
    let ret = zoomupdateaccount.MeetingConfig_GetReminderType();
  },
  upgradeMeeting: function () {
    let ret = zoomupdateaccount.MeetingConfig_UpgradeMeeting();
  },
  upgradeAccount: function () {
    let ret = zoomupdateaccount.MeetingConfig_UpgradeAccount();
  },
  cancelUpdate: function () {
    let ret = zoomupdateaccount.MeetingConfig_CancelUpdate();
  },
  setFreeMeetingNeedToUpgradeCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingNeedToUpgradeCB();
  },
  setFreeMeetingUpgradeToGiftFreeTrialStartCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStartCB();
  },
  setFreeMeetingUpgradeToGiftFreeTrialStopCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToGiftFreeTrialStopCB();
  },
  setFreeMeetingUpgradeToProMeetingCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
  },
  setFreeMeetingUpgradeToProMeetingCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
  },
  addCustomizedPictureResource: function (strPNGID, strPNGPath) {
    let opts = {
      strPNGID: strPNGID,
      strPNGPath: strPNGPath
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedPictureResource(opts);
  },
  addCustomizedStringResource: function (CustomizedStringType, strCustomizedString) {
    let opts = {
      CustomizedStringType: CustomizedStringType,
      strCustomizedString: strCustomizedString
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedStringResource(opts);
  },
  addCustomizedURLResource: function (CustomizedURLType, strCustomizeURL) {
    let opts = {
      CustomizedURLType: CustomizedURLType,
      strCustomizeURL: strCustomizeURL
    }
    let ret = zoomcustomizedresource.Resource_AddCustomizedURLResource(opts);
  },
  setFreeMeetingUpgradeToProMeetingCB: function () {
    let ret = zoomupdateaccount.MeetingConfig_SetFreeMeetingUpgradeToProMeetingCB();
  },
  scheduleMeetingWithWndParams: function () {
    let ret = zoompremeeting.ScheduleMeetingWithWndParams();
  },
  scheduleMeeting: function () {
    let ret = zoompremeeting.ScheduleMeeting();
  },
  editMeeting: function (meetingUniqueID) {
    let opts = {
      meetingUniqueID: meetingUniqueID
    }
    let ret = zoompremeeting.EditMeeting(opts);
  },
  listMeeting: function () {
    let ret = zoompremeeting.ListMeeting();
  },
  deleteMeeting: function (meetingUniqueID) {
    let opts = {
      meetingUniqueID: meetingUniqueID
    }
    let ret = zoompremeeting.DeleteMeeting(opts);
  },
  editMeetingWithWndParams: function (meetingUniqueID) {
    let opts = {
      left: '10',
      top: '10',
      meetingUniqueID: meetingUniqueID
    }
    let ret = zoompremeeting.EditMeetingWithWndParams(opts);
  },
  canStartDirectShare: function () {
    let ret = zoomdirectshare.CanStartDirectShare();
  },
  isDirectShareInProgress: function () {
    let ret = zoomdirectshare.IsDirectShareInProgress();
  },
  startDirectShare: function () {
    let ret = zoomdirectshare.StartDirectShare(OnDirectShareStatusUpdate);
  },
  stopDirectShare: function () {
    let ret = zoomdirectshare.StopDirectShare(OnDirectShareStatusUpdate);
  },
  setDirectShareStatusUpdateCB: function () {
    let ret = zoomdirectshare.SetDirectShareStatusUpdateCB(OnDirectShareStatusUpdate);
  },
  tryWithMeetingNumber: function (meetingNumber) {
    let opts = {
      meetingNumber: meetingNumber
    }
    let ret = zoomdirectshare.TryWithMeetingNumber(opts);
  },
  tryWithPairingCode: function (pairingCode) {
    let opts = {
      pairingCode: pairingCode
    }
    let ret = zoomdirectshare.TryWithPairingCode(opts);
  },
  cancel: function () {
    let ret = zoomdirectshare.Cancel();
  },
  backToMeeting: function () {
    let ret = zoomuicontroller.MeetingUI_BackToMeeting();
  },
  getMeetingUIWnd: function () {
    let ret = zoomuicontroller.MeetingUI_GetMeetingUIWnd();
  },
  switchMinimizeUIMode4FristScreenMeetingUIWnd: function (mode) {
    let opts = {
      mode: mode
    }
    let ret = zoomuicontroller.MeetingUI_SwitchMinimizeUIMode4FristScreenMeetingUIWnd(opts);
  },
  isMinimizeModeOfFristScreenMeetingUIWnd: function () {
    let ret = zoomuicontroller.MeetingUI_IsMinimizeModeOfFristScreenMeetingUIWnd();
  },
  swapToShowShareViewOrVideo: function (bToDisplayShare) {
    let opts = {
      bToDisplayShare: bToDisplayShare
    }
    let ret = zoomuicontroller.MeetingUI_SwapToShowShareViewOrVideo(opts);
  },
  isDisplayingShareViewOrVideo: function () {
    let ret = zoomuicontroller.MeetingUI_IsDisplayingShareViewOrVideo();
  },
  canSwapToShowShareViewOrVideo: function () {
    let ret = zoomuicontroller.MeetingUI_CanSwapToShowShareViewOrVideo();
  },
  reset: function () {
    let ret = zoomconfiguration.MeetingConfig_Reset();
  },
  enableAutoAdjustSpeakerVolumeWhenJoinAudio: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoAdjustSpeakerVolumeWhenJoinAudio(opts);
  },
  enableAutoAdjustMicVolumeWhenJoinAudio: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoAdjustMicVolumeWhenJoinAudio(opts);
  },
  configDSCP: function (dscpAudio, dscpVideo, bReset) {
    let opts = {
      dscpAudio: dscpAudio,
      dscpVideo: dscpVideo,
      bReset: bReset
    }
    let ret = zoomconfiguration.MeetingConfig_ConfigDSCP(opts);
  },
  enableHideFullPhoneNumber4PureCallinUser: function (bHide) {
    let opts = {
      bHide: bHide
    }
    let ret = zoomconfiguration.MeetingConfig_EnableHideFullPhoneNumber4PureCallinUser(opts);
  },
  enableLengthLimitationOfMeetingNumber: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLengthLimitationOfMeetingNumber(opts);
  },
  enableShareIOSDevice: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableShareIOSDevice(opts);
  },
  enableShareWhiteBoard: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableShareWhiteBoard(opts);
  },
  forceDisableMultiShare: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_ForceDisableMultiShare(opts);
  },
  setMaxDurationForOnlyHostInMeeting: function (nDuration) {
    let opts = {
      nDuration: nDuration
    }
    let ret = zoomconfiguration.MeetingConfig_SetMaxDurationForOnlyHostInMeeting(opts);
  },
  enableLocalRecordingConvertProgressBarDialog: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLocalRecordingConvertProgressBarDialog(opts);
  },
  enableApproveRemoteControlDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableApproveRemoteControlDlg(opts);
  },
  enableDeclineRemoteControlResponseDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableDeclineRemoteControlResponseDlg(opts);
  },
  enableLeaveMeetingOptionForHost: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableLeaveMeetingOptionForHost(opts);
  },
  enableVideoButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableVideoButtonOnMeetingUI(opts);
  },
  enableEnterAndExitFullScreenButtonOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableEnterAndExitFullScreenButtonOnMeetingUI(opts);
  },
  redirectClickShareBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickShareBTNEvent(opts);
  },
  redirectClickEndMeetingBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickEndMeetingBTNEvent(opts);
  },
  redirectFreeMeetingEndingReminderDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectFreeMeetingEndingReminderDlg(opts);
  },
  redirectClickCustomLiveStreamMenuEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickCustomLiveStreamMenuEvent(opts);
  },
  redirectClickParticipantListBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickParticipantListBTNEvent(opts);
  },
  redirectClickCCBTNEvent: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectClickCCBTNEvent(opts);
  },
  redirectMeetingWarningMsg: function (bRedirectBadNetwork, bRedirectWarnHighCPU) {
    let opts = {
      bRedirectBadNetwork: bRedirectBadNetwork,
      bRedirectWarnHighCPU: bRedirectWarnHighCPU
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectMeetingWarningMsg(opts);
  },
  enableToolTipsShow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableToolTipsShow(opts);
  },
  enableAirplayInstructionWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAirplayInstructionWindow(opts);
  },
  enableClaimHostFeature: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableClaimHostFeature(opts);
  },
  enableAutoHideJoinAudioDialog: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableAutoHideJoinAudioDialog(opts);
  },
  alwaysShowIconOnTaskBar: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_AlwaysShowIconOnTaskBar(opts);
  },
  disableSplitScreenModeUIElements: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableSplitScreenModeUIElements(opts);
  },
  setShowAudioUseComputerSoundChkbox: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowAudioUseComputerSoundChkbox(opts);
  },
  setShowCallInTab: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowCallInTab(opts);
  },
  setShowCallMeTab: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowCallMeTab(opts);
  },
  disableTopMostAttr4SettingDialog: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableTopMostAttr4SettingDialog(opts);
  },
  enableGrabShareWithoutReminder: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableGrabShareWithoutReminder(opts);
  },
  enableShowShareSwitchMultiToSingleConfirmDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableShowShareSwitchMultiToSingleConfirmDlg(opts);
  },
  disableFreeMeetingRemainTimeNotify: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableFreeMeetingRemainTimeNotify(opts);
  },
  disableFreeMeetingRemainTimeNotify: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableFreeMeetingRemainTimeNotify(opts);
  },
  hideChatItemOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideChatItemOnMeetingUI(opts);
  },
  hideRecordItemOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideRecordItemOnMeetingUI(opts);
  },
  hideUpgradeFreeMeetingButton: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideUpgradeFreeMeetingButton(opts);
  },
  setShowInviteDlgTabPage: function (tabPage, bShow) {
    let opts = {
      tabPage: tabPage,
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowInviteDlgTabPage(opts);
  },
  setShowH323SubTabPage: function (tabPage, bShow) {
    let opts = {
      tabPage: tabPage,
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowH323SubTabPage(opts);
  },
  hideUpgradeWarningMsgForFreeUserWhenSchedule: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideUpgradeWarningMsgForFreeUserWhenSchedule(opts);
  },
  hideSwitchCameraButton: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideSwitchCameraButton(opts);
  },
  hideCopyUrlOnInviteWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideCopyUrlOnInviteWindow(opts);
  },
  hideCopyInvitationOnInviteWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideCopyInvitationOnInviteWindow(opts);
  },
  hideKeypadButtonOnMeetingWindow: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideKeypadButtonOnMeetingWindow(opts);
  },
  hideRemoteControlOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideRemoteControlOnMeetingUI(opts);
  },
  hideQAOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HideQAOnMeetingUI(opts);
  },
  hidePollOnMeetingUI: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_HidePollOnMeetingUI(opts);
  },
  enableInputMeetingPasswordDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInputMeetingPasswordDlg(opts);
  },
  enableInputMeetingScreenNameDlg: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableInputMeetingScreenNameDlg(opts);
  },
  redirectWebinarNeedRegister: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectWebinarNeedRegister(opts);
  },
  redirectEndOtherMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_RedirectEndOtherMeeting(opts);
  },
  enableForceAutoStartMyVideoWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableForceAutoStartMyVideoWhenJoinMeeting(opts);
  },
  enableForceAutoStopMyVideoWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_EnableForceAutoStopMyVideoWhenJoinMeeting(opts);
  },
  disableAutoShowSelectJoinAudioDlgWhenJoinMeeting: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableAutoShowSelectJoinAudioDlgWhenJoinMeeting(opts);
  },
  disableRemoteCtrlCopyPasteFeature: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableRemoteCtrlCopyPasteFeature(opts);
  },
  setShowVideoOptimizeChkbox: function (bShow) {
    let opts = {
      bShow: bShow
    }
    let ret = zoomconfiguration.MeetingConfig_SetShowVideoOptimizeChkbox(opts);
  },
  getRequiredInfoType: function () {
    let ret = zoomconfiguration.MeetingConfig_GetRequiredInfoType();
  },
  inputMeetingPasswordAndScreenName: function (meeting_Password, screenName) {
    let opts = {
      meeting_Password: meeting_Password,
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputMeetingPasswordAndScreenName(opts);
  },
  inputMeetingIDAndScreenName: function (meetingID, screenName) {
    let opts = {
      meetingID: meetingID,
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputMeetingIDAndScreenName(opts);
  },
  inputMeetingScreenName: function (screenName) {
    let opts = {
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputMeetingScreenName(opts);
  },
  meetingPasswordAndScreenNameHandler_Cancel: function () {
    let ret = zoomconfiguration.MeetingConfig_MeetingPasswordAndScreenNameHandler_Cancel();
  },
  getWebinarNeedRegisterType: function () {
    let ret = zoomconfiguration.MeetingConfig_GetWebinarNeedRegisterType();
  },
  getWebinarRegisterUrl: function () {
    let ret = zoomconfiguration.MeetingConfig_GetWebinarRegisterUrl();
  },
  releaseRegisterWebinarByUrl: function () {
    let ret = zoomconfiguration.MeetingConfig_ReleaseRegisterWebinarByUrl();
  },
  inputWebinarRegisterEmailAndScreenName: function (email, screenName) {
    let opts = {
      email: email,
      screenName: screenName
    }
    let ret = zoomconfiguration.MeetingConfig_InputWebinarRegisterEmailAndScreenName(opts);
  },
  cancelRegisterWebinarByEmail: function () {
    let ret = zoomconfiguration.MeetingConfig_CancelRegisterWebinarByEmail();
  },
  disableConfidentialWatermark: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomconfiguration.MeetingConfig_DisableConfidentialWatermark(opts);
  },
  disableAdvancedFeatures4GeneralSetting: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomsetui.SettingUI_DisableAdvancedFeatures4GeneralSetting(opts);
  },
  disableAccountSettingTabPage: function (bDisable) {
    let opts = {
      bDisable: bDisable
    }
    let ret = zoomsetui.SettingUI_DisableAccountSettingTabPage(opts);
  },
  confSettingDialogShownTabPage: function (number) {
    let opts = {
      number: number
    }
    let ret = zoomsetui.SettingUI_ConfSettingDialogShownTabPage(opts);
  },
  queryOverallStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryOverallStatisticInfo();
  },
  queryAudioStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryAudioStatisticInfo();
  },
  queryVideoStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryVideoStatisticInfo();
  },
  queryShareStatisticInfo: function () {
    let ret = zoomsetstatistic.Setting_QueryShareStatisticInfo();
  },
  enableAlwaysShowMeetingControls: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaccessibility.Setting_EnableAlwaysShowMeetingControls(opts);
  },
  isAlwaysShowMeetingControlsEnable: function (bEnable) {
    let opts = {
      bEnable: bEnable
    }
    let ret = zoomsetaccessibility.Setting_IsAlwaysShowMeetingControlsEnable(opts);
  },
  enableZoomAuthRealNameMeetingUIShown: function (b_enable) {
    let opts = {
      b_enable: b_enable
    }
    let ret = zoomsms.EnableZoomAuthRealNameMeetingUIShown(opts);
  },
  getResendSMSVerificationCodeHandler: function () {
    let ret = zoomsms.GetResendSMSVerificationCodeHandler();
  },
  retrieve: function (country_code, phone_number) {
    let opts = {
      country_code: country_code,
      phone_number: phone_number
    }
    let ret = zoomsms.Retrieve(opts);
  },
  retrieve_CancelAndLeaveMeeting: function () {
    let ret = zoomsms.Retrieve_CancelAndLeaveMeeting();
  },
  getReVerifySMSVerificationCodeHandler: function () {
    let ret = zoomsms.GetReVerifySMSVerificationCodeHandler();
  },
  verify: function (country_code, phone_number, verification_code) {
    let opts = {
      country_code: country_code,
      phone_number: phone_number,
      verification_code: verification_code
    }
    let ret = zoomsms.Verify(opts);
  },
  verify_CancelAndLeaveMeeting: function () {
    let ret = zoomsms.Verify_CancelAndLeaveMeeting();
  },
  getSupportPhoneNumberCountryList: function () {
    let ret = zoomsms.GetSupportPhoneNumberCountryList();
  },
  setDefaultCellPhoneInfo: function (country_code, phone_number) {
    let opts = {
      country_code: country_code,
      phone_number: phone_number
    }
    let ret = zoomsms.SetDefaultCellPhoneInfo(opts);
  },
  canStartRecording: function (cloud_recording) {
    let opts = {
      cloud_recording: cloud_recording
    }
    let ret = zoomrecording.CanStartRecording(opts);
    return ret;
  },
  startRecording: function (recPath) {
    if (this.canStartRecording(false) == 0) {
      let opts = {
        recPath: recPath
      }
      let ret = zoomrecording.StartRecording(opts);
    }
  },
  stopRecording: function () {
    let ret = zoomrecording.StopRecording();
  },
  canAllowDisAllowLocalRecording: function () {
    let ret = zoomrecording.CanAllowDisAllowLocalRecording();
  },
  startCloudRecording: function () {
    if (this.canStartRecording(true) == 0) {
      let ret = zoomrecording.StartCloudRecording();
    }
  },
  stopCloudRecording: function () {
    let ret = zoomrecording.StopCloudRecording();
  },
  isSupportLocalRecording: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomrecording.IsSupportLocalRecording(opts);
  },
  allowLocalRecording: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomrecording.AllowLocalRecording(opts);
  },
  disAllowLocalRecording: function (userid) {
    let opts = {
      userid: userid
    }
    let ret = zoomrecording.DisAllowLocalRecording(opts);
  },
  requestCustomizedLocalRecordingSource: function () {
    let ret = zoomrecording.RequestCustomizedLocalRecordingSource();
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