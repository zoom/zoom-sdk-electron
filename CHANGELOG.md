# CHANGELOG

## Note
In version 5.2.42037.1112 of the Electron SDK,the support for Protocol Buffers is being added.

If you are building your own version of the Electron SDK, you will need to follow these steps:
* Download  protobuf 3.4.0 source file and rename the src folder to protobuf_src.
* Copy the src folder into the lib/node_add_on folder.
* Run the build_nodeaddon script.

If you would like to use recent versions of protobuf(higher than 3.4.0), in addition to following the above steps, you must also do the following:

* Download the execution file of the corresponding protobuf and add its directory into the system path.
* In the terminal, navigate to the root directory of the Electron SDK(same level as the build_nodeaddon file).
* Run protoc.exe —js_out=import_style=common.js,binary:. lib/electron_sdk_proto command in the terminal to generate a electron_sdk_pb.js file. After generating this file, you will be able to use the interfaces provided by the Electron SDK.

If you are not building your own version of the Electron SDK and are using the Electron SDK provided by Zoom, this change will not impact your app and no further action is required on your end.

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
         "exp": long, // access token expire timestamp, max: iat + 2 days
         "tokenExp": long // token expire timestamp, MIN:30 minutes
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

## 2020-11-17 @ v5.2.42037.1112

## Added
* Added new enums.
  * `ZoomSDKVideoCaptureMethod`
  * `ZoomSDKRenderPostProcessing`
  * `ZoomSDKVideoHardwareEncodeType`
* Added a new interface to set team identifier on macOS
  * `SetTeamIdentifier`
* Added new parameters to interface `initSDK` in zoom_sdk.js
  * Added `renderPostProcessing` and `videoCaptureMethod`
* Added new parameters to interface `Setting_EnableHardwareEncode` in zoom_setting_video.js
  * Added `encodeType`
* Added new parameters to interface `Setting_IsHardwareEncodeEnabled` in zoom_setting_video.js
  * Added `encodeType`
* Removed the watermark by default. If you wish to retain the Zoom watermark, please contact us via developersupport@zoom.us.

## 2020-10-26 @ v5.2.41762.1027

## Changed & Fixed
* [Mac] Fixed an issue that the virtual background does not work after re-signing the SDK libraries.
  * SDK will verify the signature of all libraries. When the SDK libraries have been resigned, please call the interface `setTeamIdentifier` to set the organization unit of the signature before intializing in the app.
  ```
     setTeamIdentifier(“the ou of certificate”);
  ```

* [Mac] Fixed an issue that the keychain popup dialog contains 'Zoom', the new keychain pops up will use the app's name instead.

## 2020-10-09 @ v5.2.41735.0929

## Added
* Upgrade Electron support to v8.2.4
* Added a new interface isH323User to check whether the user is an H.323 user
* Added a new interfaces to get participant ID
* Added local and cloud recording feature.
  * Interfaces in `zoom_meeting_recording.js`
* Added Vietnamese and Italian language support.

## Changed & Fixed
* Fixed an issue that the customized XML file does not work.
* Fixed an issue that the onFreeMeetingNeedToUpgrade callback is causing a crash

## 2020-06-30 @ v5.0.24433.0616

## Added

* Upgraded Zoom default UI to match Zoom client 5.0.
* Optimized the status of H.323 call out by adding the following status:
  * `H323Callout_Busy`
  * `H323Callout_Decline`
* [MacOS only] Added a new interface `HideRecordingsNotification` to hide recording notification.
* Added a new parameter `userZAK` in `JoinMeetingWithoutLogin`
* Added a new parameter to generate dump for troubleshooting in the `initsdk` interface
  * `enableGenerateDump`
* Added a new interface to enable or to check the video preview dialog
  * `EnableVideoPreviewDialog`
  * `IsVideoPreviewDialogEnabled`

## Changed & Fixed
* Redefine the parameters in the interface `StartMeetingWithOutLogin` and remove `usertoken`.
* Predefine the value of the `langid` parameter in the `initsdk` to be `unknown`, which means the SDK will use the language configuration of the OS.
* Temporary remove the "Unmute all" interfaces.

## 2020-04-28 @ v4.6.21666.0428

## Added:
* Added support for AES 256-bit GCM encryption.
  * **Please plan to upgrade your SDK accordingly. See the announcement in [README](https://github.com/zoom/zoom-sdk-electron) for more information**

## Changed & Fixed:
* Upgraded OpenSSL to version 1.1.1e

## 2020-04-04 @ v4.6.15798.0403

## Added:
* [Electron SDK on Mac only]Add a new interface to disable the toolbar invite button
  * `MeetingConfig_DisableToolbarInviteButtonClickOriginAction` in `zoom_meeting_configuration.js`
* Add a new interface to control the chime sound when someone enters or exits the meeting
  * `MeetingAudio_EnablePlayChimeWhenEnterOrExit` in `zoom_meeting_audio.js`
* Add new option in InitSDK to configure the size of the log file
  * Use the new option `InitSDK.logfilesize` in `zoom_sdk.js` to customize the log file size. The unit of the file size is MB, with default size 5MB.

## Changed & Fixed:
* Fixed an issue that the interface `MeetingUI_BackToMeeting` does not work as expected for webinar attendee on Windows
* Fixed an issue that user could not join a meeting with vanityID

## 2020-02-10 @ v4.6.15088.0210

## Added:
* New enhancements follow the changes in Windows SDK and Mac OS SDK.

## Changed & Fixed:
* Enhanced security and upgraded OpenSSL to 1.0.2u.
* Changes and fixes follow the changes in Windows SDK and Mac OS SDK.

## 2019-12-16 @ v4.4.57220.1211

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

## 2019-11-04 @ v4.4.56616.1029

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

## 2019-09-04 @ v4.4.55968.0904

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

## 2019-07-15 @ v4.4.55130.0712

We have merged and unified the `windows-electron-sdk` and the `mac-electron-sdk` into one single SDK.

The new Electron SDK has a brand new structure, consist of the `node-interface` and the `node-core`:

* **Node-interface**: contains all the implementations by V8 engine
* **Node-core**: contains all the uniform interfaces for both Windows and Mac

Due to the open source nature of this SDK, you will be able to configure and compile the new Zoom Electron SDK with any versions of Electron.

**Added**

* Added newly developed interfaces by referring to the previous Windows Electron SDK
* Added newly developed interfaces by referring to the previous Mac Electron SDK
* Can support any version of Electron
