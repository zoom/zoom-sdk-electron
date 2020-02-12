# CHANGELOG

## Note
### New SDK Initialization method: Using JWT token
Introducing new SDK initialization method -- JWT token, which is more secure, more convenient, and more versatile.

* How to compose JWT token for SDK initialization

You may generate your JWT token using the online tool https://jwt.io/. **It is highly recommended to generate your JWT token in your backend server.**

JWT is generated with three core parts: Header, Payload, and Signature. When combined, these parts are separated by a period to form a token: aaaaa.bbbbb.cccc.

Please follow this template to compose your payload for SDK initialization:

** Header
```
{
  "alg": "HS256",
  "typ": "JWT"
}
```
** Payload
```
{
	       "appKey": "string", // Your SDK key
         "iat": long, // access token issue timestamp
         "exp": long, // access token expire time
         "tokenExp": long // token expire time, MIN:30 minutes
}
```
**The minimum value of `tokenExp` should be at least 30 minutes, otherwise, SDK will reject the authentication request.**
** Signature
```
HMACSHA256(
  base64UrlEncode(header) + "." +
  base64UrlEncode(payload),
  "Your SDK secret here"
)
```
You do not need to secret base64 encoded your signature. Once the JWT token is generated, please do not reveal it or publish it. **It is highly recommended to handle your SDK key and secret and generate JWT in a backend server to be consumed by your application. Do not generate JWT in a production application.**

## 2020-02-10 @ [v4.6.15088.0210](https://github.com/zoom/zoom-sdk-electron/releases/tag/v4.6.15088.0210)

## Added:
* New enhancements follow the changes in Windows SDK and Mac OS SDK.

## Changed & Fixed:
* Enhanced security and upgraded OpenSSL to 1.0.2u.
* Changes and fixes follow the changes in Windows SDK and Mac OS SDK.

## 2019-12-16 @ [v4.4.57220.1211](https://github.com/zoom/zoom-sdk-electron/releases/tag/v4.4.57220.1211)

## Added:
* Add new interfaces for SDK initialization with JWT token.
  * `AuthWithJwtToken(sdk_context)`
* Add new interfaces in the meeting configuration service (Details available in `zoom_meeting_configuration.js`).
 * `MeetingConfig_EnableApproveRemoteControlDlg`
 * `MeetingConfig_EnableDeclineRemoteControlResponseDlg`
 * `MeetingConfig_SetShowCallInTab`
 * `MeetingConfig_SetShowCallMeTab`
 * `MeetingConfig_RedirectClickParticipantListBTNEvent`
 * `MeetingConfig_RedirectClickCCBTNEvent`
* Add new interfaces in the setting service (Details available in `zoom_setting_general.js`).
  * `Setting_EnableAutoFullScreenVideoWhenViewShare`
    * `Setting_IsAutoFullScreenVideoWhenViewShareEnabled`
    * `Setting_EnableShowMyMeetingElapseTime`
    * `Setting_IsShowMyMeetingElapseTimeEnabled`
* Add new callbacks for the events of clicking related buttons.
  * `SetonStartShareBtnClickedCB`
    * `SetonEndMeetingBtnClickedCB`
    * `SetonParticipantListBtnClickedCB`
  * Add support for Electron 6 & 7. (**Note: In order to support Electron 7, the Electron 3 or ealier version is no longer supported**)

## Removed:
* Remove the support for Electron 3 or earlier version.

## Changed & Fixed:
* Fixed an issue that the callback of direct share can not be received accidentally.
* Fixed an issue that the meeting restarts for a few times after pressing the end meeting button.

## 2019-11-04 @ [v4.4.56616.1029](https://github.com/zoom/zoom-sdk-electron/releases/tag/v4.4.56616.1029)

## Added
* Add new interfaces for meeting config controller (locate in `zoom_meeting_configuration.js`)
  * `MeetingConfig_Reset()`
  * `MeetingConfig_EnableAutoAdjustSpeakerVolumeWhenJoinAudio()`
     * param \{Boolean} bEnable
  * `MeetingConfig_EnableAutoAdjustMicVolumeWhenJoinAudio()`
     * param \{Boolean} bEnable
  * `MeetingConfig_ConfigDSCP()`
     * param \{Number} dscpAudio Configure DSCP value for audio
     * param \{Number} dscpVideo Configure DSCP value for video
     * param \{Boolean} bReset
  * `MeetingConfig_EnableHideFullPhoneNumber4PureCallinUser()`
     * param \{Boolean} bHide
  * `MeetingConfig_EnableLengthLimitationOfMeetingNumber()`
     * param \{Boolean} bEnable
  * `MeetingConfig_EnableShareIOSDevice()`
     * param \{Boolean} bEnable
  * `MeetingConfig_EnableShareWhiteBoard()`
     * param \{Boolean} bEnable
  * `MeetingConfig_ForceDisableMultiShare()`
     * param \{Boolean} bDisable
  * `MeetingConfig_SetMaxDurationForOnlyHostInMeeting()`
     * param \{Number} nDuration
  * `MeetingConfig_EnableLocalRecordingConvertProgressBarDialog()`
     * param \{Boolean} bShow
* Add new interfaces for meeting UI controller (locate in `zoom_meeting_ui_ctrl.js`)
  * `MeetingUI_BackToMeeting()`
  * `MeetingUI_GetMeetingUIWnd()`
  * `MeetingUI_SwitchMinimizeUIMode4FristScreenMeetingUIWnd()`
     * param \{Number} mode
  * `MeetingUI_IsMinimizeModeOfFristScreenMeetingUIWnd()`
  * `MeetingUI_SwapToShowShareViewOrVideo()`
     * param \{Boolean} mode
  * `MeetingUI_IsDisplayingShareViewOrVideo()`
  * `MeetingUI_CanSwapToShowShareViewOrVideo()`
* Add a new interface for getting zoom SDK version (locate in `zoom_sdk.js`)
    * `GetZoomSDKVersion()`
* Add a new interface for joining a meeting using zoom web url (locate in `zoom_meeting.js`)
  * `HandleZoomWebUriProtocolAction()`
* Add new interfaces for setting UI strategy (locate in `zoom_setting_ui_ctrl.js`)
  * `SettingUI_DisableAdvancedFeatures4GeneralSetting()`
     * param \{Boolean} bDisable
  * `SettingUI_DisableAccountSettingTabPage()`
     * aram \{Boolean} bDisable
  * `SettingUI_ConfSettingDialogShownTabPage()`
     * param \{Number} number settingDlgShowTabPageOption, Every bit indicates whether to show a certain tab page
      * bit 1: indicates whether to show the virtual background page. "1" show, "0" not show
      * bit 2: indicates whether to show the video page. "1" show, "0" not show
      * bit 3: indicates whether to show the statistics page. "1" show, "0" not show
      * bit 4: indicates whether to show the recording page. "1" show, "0" not show
      * bit 5: indicates whether to show the general page. "1" show, "0" not show
      * bit 6: indicates whether to show the feedback page. "1" show, "0" not show
      * bit 7: indicates whether to show the audio page. "1" show, "0" not show
      * bit 8: indicates whether to show the advance feature page. "1" show, "0" not show
      * bit 9: indicates whether to show the accessibility page. "1" show, "0" not show

## 2019-09-04 @ [v4.4.55968.0904](https://github.com/zoom/zoom-sdk-electron/releases/tag/v4.4.55968.0904)

## Added
*  Add pre-meeting features that include schedule/edit/delete a meeting, get a list of current meetings or set corresponding callbacks. All new interfaces are available in `ZoomNodePremeetingWrap`:
* `ZoomNodePremeetingWrap::ScheduleMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::ScheduleMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::EditMeetingWithWndParams(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::EditMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::ListMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::DeleteMeeting(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::SetOnScheduleOrEditMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::SetOnListMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodePremeetingWrap::SetOnDeleteMeetingCB(const v8::FunctionCallbackInfo<v8::Value>& args);`
*  Add callbacks for scheduling/editing/listing/deleting meeting
* `ZNativeSDKPreMeetingWrapSink::onScheduleOrEditMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID);`
* `ZNativeSDKPreMeetingWrapSink::onListMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID);`
* `ZNativeSDKPreMeetingWrapSink::onDeleteMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID);`
*  Add direct share feature to allow sharing your screen/app/white_board directly after login with meetingNumber/paringCode. All new interfaces are available in `ZoomNodeDirectShareHelperWrap:`
* `ZoomNodeDirectShareHelperWrap::CanStartDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::IsDirectShareInProgress(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::StartDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::StopDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::SetDirectShareStatusUpdateCB(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::TryWithMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::TryWithPairingCode(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeDirectShareHelperWrap::Cancel(const v8::FunctionCallbackInfo<v8::Value>& args);`
*  Add a new callback for the status of direct sharing changes
* `ZNativeSDKDirectShareHelperWrapSink::OnDirectShareStatusUpdate(ZNDirectShareStatus status);`
*  Add 2 new interfaces for getting participants list and specific user's information
* `ZoomNodeMeetingParticipantsCtrlWrap::GetParticipantsList(const v8::FunctionCallbackInfo<v8::Value>& args);`
* `ZoomNodeMeetingParticipantsCtrlWrap::GetUserInfoByUserID(const v8::FunctionCallbackInfo<v8::Value>& args);`
*  Add new callbacks for identifying the active speaker.
* `ZNativeSDKMeetingAudioWrapSink::onUserActiveAudioChange(ZNList<unsigned int > lstActiveAudio);`
* `ZNativeSDKMeetingVideoWrapSink::onActiveSpeakerVideoUserChanged(unsigned int userId);`
* `ZNativeSDKMeetingVideoWrapSink::virtual void onActiveVideoUserChanged(unsigned int userId);`

## Changed & Fixed
*  Optimized the way of setting callback functions. Most of the callbacks are now set by using "Set###CB" interfaces, such as `ZoomNodeAuthWrap::SetOnAuthReturnCB`. Some of the interfaces, such as `ZoomNodeAuthWrap::Auth`, need not pass a callback function as a parameter
*  Modified the types of `userId` and `meetingNumber` from String to Number.

## 2019-07-15 @ [v4.4.55130.0712](https://github.com/zoom/zoom-sdk-electron/releases/tag/v4.4.55130.0712)

We have merged and unified the `windows-electron-sdk` and the `mac-electron-sdk` into one single SDK.

The new Electron SDK has a brand new structure, consist of the `node-interface` and the `node-core`:

* **Node-interface**: contains all the implementations by V8 engine
* **Node-core**: contains all the uniform interfaces for both Windows and Mac

Due to the open source nature of this SDK, you will be able to configure and compile the new Zoom Electron SDK with any versions of Electron.

**Added**

* Added newly developed interfaces by referring to the previous Windows Electron SDK
* Added newly developed interfaces by referring to the previous Mac Electron SDK
* Can support any version of Electron
