//
//  ZoomSDKErrors.h
//  ZoomSDK
//
//  Created by TOTTI on 7/18/16.
//  Copyright (c) 2016 Zoom Video Communications,Inc. All rights reserved.
//
#pragma once

//Client Key or Secret is empty
#define kSDKAuthKeyOrSecretEmpty        300
//Client Key or Secret is wrong
#define kSDKAuthKeyOrSecretWrong        3023
//Account does not support SDK feature
#define kSDKAuthAccountNotSupport       3024
//Account did not enable SDK feature
#define kSDKAuthAccountNotEnableSDK     3025

/** 
 @brief An enumeration of user types. 
 */
typedef enum {
    //API user.
    ZoomSDKUserType_APIUser     = 99,
    //User logs in with working email.
    ZoomSDKUserType_ZoomUser    = 100,
    //Single-sign-on user.
    ZoomSDKUserType_SSOUser     = 101,
}ZoomSDKUserType;

typedef enum {
	//API user.
    SDKUserType_APIUser,
	//User logs in with email.
    SDKUserType_EmailLogin,
	//User logs in with Facebook account.
    SDKUserType_FaceBook,
	//User logs in with Google authentication.
    SDKUserType_GoogleOAuth,
	//User logs in with SSO token.
    SDKUserType_SSO,
	//Unknown user type.
    SDKUserType_Unknown,
}SDKUserType;
/**
 @brief An enumeration of commands for leaving meeting.
 */
typedef enum {
    //Command of leaving meeting.
    LeaveMeetingCmd_Leave,
    //Command of ending Meeting.
    LeaveMeetingCmd_End,
}LeaveMeetingCmd;

/**
 @brief An enumeration of all the commands in the meeting.
 */
typedef enum{
    //Mute the video.
    ActionMeetingCmd_MuteVideo,
	//Unmute the video.
    ActionMeetingCmd_UnMuteVideo,
    //Mute the audio.
    ActionMeetingCmd_MuteAudio,
	//Unmute the audio.
    ActionMeetingCmd_UnMuteAudio,
    //Enable the feature that user can unmute himself when muted.
    ActionMeetingCmd_EnableUnmuteBySelf,
	//Disable the feature that user can not unmute himself when muted.
    ActionMeetingCmd_DisableUnmuteBySelf,
    //Mute all participants in the meeting, available only for the host/co-host. 
    ActionMeetingCmd_MuteAll,
	//Unmute all participants in the meeting, available only for the host/co-host. 
    ActionMeetingCmd_UnmuteAll,
    //Lock the meeting, available only for the host/co-host. Once locked, the new participants can no longer join the meeting/co-host.
    ActionMeetingCmd_LockMeeting,
	//Unlock the meeting, available only for the host/co-host. 
    ActionMeetingCmd_UnLockMeeting,
    //Send the request of remote control to the specified user
    ActionMeetingCmd_RequestRemoteControl,
	//Abandon remote control of the specified user.
    ActionMeetingCmd_GiveUpRemoteControl,
	//Give the authority of remote control to the specified user.
    ActionMeetingCmd_GiveRemoteControlTo,
	//Refuse the request to remote control from the specified user.
    ActionMeetingCmd_DeclineRemoteControlRequest,
	//Get back the authority of remote control.
    ActionMeetingCmd_RevokeRemoteControl,
    //Lock the share, available only for the host/co-host. Once locked, only host/co-host can share, this is unsupported from v4.4.
    ActionMeetingCmd_LockShare,
	//Unlock the share, available only for the host/co-host, this is unsupported from v4.4.
    ActionMeetingCmd_UnlockShare,
    //Put all participants' hands down, available only for the host/co-host.     
    ActionMeetingCmd_LowerAllHands,
    //Adjust the display size fit to the window.
    ActionMeetingCmd_ShareFitWindowMode,
	//Share in original size.
    ActionMeetingCmd_ShareOriginSizeMode,
    //Pin the video of specified user. Once the video is pined, it will show fixed video in main view.
    ActionMeetingCmd_PinVideo,
	//Unpin the video of specified user.
    ActionMeetingCmd_UnPinVideo,
    //Spotlight the video of the specified user.
    ActionMeetingCmd_SpotlightVideo,
	//Spotlight falloff the video of the specified user.
    ActionMeetingCmd_UnSpotlightVideo,
    //Pause sharing.
    ActionMeetingCmd_PauseShare,
    //Resume sharing.
    ActionMeetingCmd_ResumeShare,
    //Join meeting by VoIP.
    ActionMeetingCmd_JoinVoip,
    //Disconnect VoIP from meeting.
    ActionMeetingCmd_LeaveVoip,
    
}ActionMeetingCmd;

/**
 @brief Get default information of meeting. 
 */
typedef enum {
	//The topic of meeting.
    MeetingPropertyCmd_Topic,
	//The template of email invitation.
    MeetingPropertyCmd_InviteEmailTemplate,
	//The title of email invitation.
    MeetingPropertyCmd_InviteEmailTitle,
	//The invitation URL.
    MeetingPropertyCmd_JoinMeetingUrl,
	//The default path to save the recording files.
    MeetingPropertyCmd_DefaultRecordPath,
	//The meeting number.
    MeetingPropertyCmd_MeetingNumber,
	//The tag of host.
    MeetingPropertyCmd_HostTag, 
	//Meeting ID.
    MeetingPropertyCmd_MeetingID,
}MeetingPropertyCmd;

/**
 @brief Type of annotation tools.
 */
typedef enum{
	//Switch to mouse cursor. For initialization.
    AnnotationToolType_None,
	//Pen
    AnnotationToolType_Pen,
	//Highlighter.
    AnnotationToolType_HighLighter,
	//A straight line changes automatically in pace with the mouse cursor.
    AnnotationToolType_AutoLine,
	//A rectangle changes automatically in pace with the mouse cursor.
    AnnotationToolType_AutoRectangle,
	//An ellipse changes automatically in pace with the mouse cursor.
    AnnotationToolType_AutoEllipse,
	//An arrow changes automatically in pace with the mouse cursor.
    AnnotationToolType_AutoArrow,
	//A filled rectangle.
    AnnotationToolType_AutoRectangleFill,
	//A filled ellipse.
    AnnotationToolType_AutoEllipseFill,
	//Laser pointer.
    AnnotationToolType_SpotLight,
	//An arrow.
    AnnotationToolType_Arrow,
	//An eraser.
    AnnotationToolType_ERASER,
}AnnotationToolType;

/**
 @brief Types of clearing annotations.
 */
typedef enum{
	//Clear all annotations.
    AnnotationClearType_All,
	//Clear only your own annotations.
    AnnotationClearType_Self,
	//Clear only others' annotations.
    AnnotationClearType_Other,
}AnnotationClearType;

/**
 @brief In-meeting UI components.
 */
typedef enum{
	//Meeting window.
    MeetingComponent_MainWindow,
	//Audio.
    MeetingComponent_Audio,
	//Chat.
    MeetingComponent_Chat,
	//Participants.
    MeetingComponent_Participants,
	//Main toolbar at the bottom of meeting window.
    MeetingComponent_MainToolBar,
	//Main toolbar for sharing on the primary view.
    MeetingComponent_MainShareToolBar,
	//Toolbar for sharing on the subview.
    MeetingComponent_AuxShareToolBar,
	//Setting components.
    MeetingComponent_Setting,
	//Window for joining meeting before host.
    MeetingComponent_JBHWindow,
	//Window for sharing options. 
    MeetingComponent_ShareOptionWindow,
	//Thumbnail video layout.
    MeetingComponent_ThumbnailVideo,
	//Window for invite other into meeting.
    MeetingComponent_InviteWindow,
	//Window for sharing select.
    MeetingComponent_ShareSelectWindow,
}MeetingComponent;

/**
 * @brief Enumeration of Meeting settings.
 */
typedef enum{
	//Dual screen mode.
    MeetingSettingCmd_DualScreenMode,
	//Adjust the size of sharing content to fit the window.
    MeetingSettingCmd_AutoFitToWindowWhenViewShare,
	//Enter full screen mode when user joins the meeting.
    MeetingSettingCmd_AutoFullScreenWhenJoinMeeting,
	//Enable to mute attendees when they join the meeting.
    MeetingSettingCmd_EnableMuteOnEntry,
	//Enable to play chime when user joins or exits the meeting.
    MeetingSettingCmd_EnablePlayChimeWhenEnterOrExit,
}MeetingSettingCmd;

/**
 * @brief Enumeration of common errors of SDK.
 */
typedef enum{
	//Success.
    ZoomSDKError_Success,
	//Failed.
    ZoomSDKError_Failed,
	//SDK is not initialize.
    ZoomSDKError_Uninit,
	//Service is failed.
    ZoomSDKError_ServiceFailed,
	//Incorrect usage of the feature. 
    ZoomSDKError_WrongUsage,
	//Wrong parameter.
    ZoomSDKError_InvalidPrameter,
	//No permission.
    ZoomSDKError_NoPermission,
	//There is no recording in process.
    ZoomSDKError_NoRecordingInProgress,
    //Api calls are too frequent.
    ZoomSDKError_TooFrequentCall,
    //unsupported feature
    ZoomSDKError_UnSupportedFeature,
	//Unknown error.
    ZoomSDKError_UnKnow,
}ZoomSDKError;

/**
 * @brief Enumeration of SDK authentication results.
 */
typedef enum {
    //Authentication is successful
    ZoomSDKAuthError_Success = 0,
    //Key or secret is wrong
    ZoomSDKAuthError_KeyOrSecretWrong = 1,
    //Client account does not support
    ZoomSDKAuthError_AccountNotSupport = 2,
    //Client account does not enable SDK
    ZoomSDKAuthError_AccountNotEnableSDK = 3,
    //Auth timeout
    ZoomSDKAuthError_Timeout = 4,
    //Network issue
    ZoomSDKAuthError_NetworkIssue = 5,
    //Unknown error
    ZoomSDKAuthError_Unknown = 6,
}ZoomSDKAuthError;

/**
 * @brief Enumeration of SDK pre-meeting errors.
 */
typedef enum {
    //Calls SDK successfully.
    ZoomSDKPremeetingError_Success,
    //Calls SDK failed.
    ZoomSDKPremeetingError_Failed,
    //Timeout.
    ZoomSDKPremeetingError_TimeOut,
    //Unknown errors.
    ZoomSDKPremeetingError_Unknown,
    
}ZoomSDKPremeetingError;

/**
 * @brief Enumeration of errors to start/join meeting.
 */
typedef enum {
    //Start/Join meeting successfully.
    ZoomSDKMeetingError_Success                         = 0,
    //Network issue, please check the network connection.
    ZoomSDKMeetingError_NetworkUnavailable              = 1,
    //Failed to reconnect the meeting.
    ZoomSDKMeetingError_ReconnectFailed                 = 2,
    //MMR issue, please check MMR configuration.
    ZoomSDKMeetingError_MMRError                        = 3,
    //The meeting password is incorrect.
    ZoomSDKMeetingError_PasswordError                   = 4,
    //Failed to create video and audio data connection with MMR.
    ZoomSDKMeetingError_SessionError                    = 5,
    //Meeting is over.
    ZoomSDKMeetingError_MeetingOver                     = 6,
    //Meeting is not started.
    ZoomSDKMeetingError_MeetingNotStart                 = 7,
    //The meeting does not exist.
    ZoomSDKMeetingError_MeetingNotExist                 = 8,
    //The amount of attendees reaches the upper limit.
    ZoomSDKMeetingError_UserFull                        = 9,
    //The ZOOM SDK version is incompatible.
    ZoomSDKMeetingError_ClientIncompatible              = 10,
    //No MMR is valid.
    ZoomSDKMeetingError_NoMMR                           = 11,
    //The meeting is locked by the host.
    ZoomSDKMeetingError_MeetingLocked                   = 12,
    //The meeting is restricted.
    ZoomSDKMeetingError_MeetingRestricted               = 13,
    //The meeting is restricted to join before host.
    ZoomSDKMeetingError_MeetingJBHRestricted            = 14,
    //Failed to request the web server.
    ZoomSDKMeetingError_EmitWebRequestFailed            = 15,
    //Failed to start meeting with expired token.
    ZoomSDKMeetingError_StartTokenExpired               = 16,
    //The user's video does not work.
    ZoomSDKMeetingError_VideoSessionError               = 17,
	//The user's audio cannot auto-start.
    ZoomSDKMeetingError_AudioAutoStartError             = 18,
	//The amount of webinar attendees reaches the upper limit.
    ZoomSDKMeetingError_RegisterWebinarFull             = 19,
    //User needs to register a webinar account if he wants to start a webinar.
    ZoomSDKMeetingError_RegisterWebinarHostRegister     = 20,
	//User needs to register an account if he wants to join the webinar by the link.
    ZoomSDKMeetingError_RegisterWebinarPanelistRegister = 21,
	//The host has denied your webinar registration.
    ZoomSDKMeetingError_RegisterWebinarDeniedEmail      = 22,
	//Sign in with the specified account to join webinar.
    ZoomSDKMeetingError_RegisterWebinarEnforceLogin     = 23,
    //The certificate of ZC has been changed.
    ZoomSDKMeetingError_ZCCertificateChanged            = 24,
    //Failed to write configure file.
    ZoomSDKMeetingError_ConfigFileWriteFailed           = 50,
	// User is removed from meeting by host.
    ZoomSDKMeetingError_RemovedByHost                   = 61,
    //Unknown error.
    ZoomSDKMeetingError_Unknown                         = 100,
	//No error.
    ZoomSDKMeetingError_None                            = 101,
}ZoomSDKMeetingError;



/**
 * @brief Enumeration of ZOOM SDK login status.
 */
typedef enum {
	//User does not login.
    ZoomSDKLoginStatus_Idle = 0,
	//Login successfully.
    ZoomSDKLoginStatus_Success = 1,
	//Login failed.
    ZoomSDKLoginStatus_Failed = 2,
	//Login in progress.
    ZoomSDKLoginStatus_Processing = 3
}ZoomSDKLoginStatus;


/**
 * @brief Enumeration of meeting status.
 */
typedef enum {
    //No meeting is running.
    ZoomSDKMeetingStatus_Idle             = 0,
    //Connecting to the meeting server.
    ZoomSDKMeetingStatus_Connecting       = 1,
    //Waiting for the host to start the meeting.
    ZoomSDKMeetingStatus_WaitingForHost   = 2,
    //Meeting is ready, in meeting status.
    ZoomSDKMeetingStatus_InMeeting        = 3,
    //Disconnect the meeting server, leave meeting status.
    ZoomSDKMeetingStatus_Disconnecting    = 4,
    //Reconnecting meeting server status.
    ZoomSDKMeetingStatus_Reconnecting     = 5,
    //Join/Start meeting failed.
    ZoomSDKMeetingStatus_Failed           = 6,
    //Meeting ends.
    ZoomSDKMeetingStatus_Ended            = 7,
    //Audio is connected.
    ZoomSDKMeetingStatus_AudioReady       = 8,
    //There is another ongoing meeting on the server. 
    ZoomSDKMeetingStatus_OtherMeetingInProgress = 9,
	//Participants who join the meeting before the start are in the waiting room.
    ZoomSDKMeetingStatus_InWaitingRoom      = 10,
    //End to end meeting. Available for Huawei
    ZoomSDKMeetingStatus_WaitExternalSessionKey =11,
    //Promote the attendees to panelist in webinar.
    ZoomSDKMeetingStatus_Webinar_Promote = 12,
    //Demote the attendees from the panelist.
    ZoomSDKMeetingStatus_Webinar_Depromote = 13,
    //Join breakout room.
    ZoomSDKMeetingStatus_Join_Breakout_Room = 14,
    //Leave breakout room.
    ZoomSDKMeetingStatus_Leave_Breakout_Room = 15,
    
}ZoomSDKMeetingStatus;

/**
 * @brief Enumeration of sharing status.
 */
typedef enum{
	//For initialization.
    ZoomSDKShareStatus_None,
	//The current user begins the share.
    ZoomSDKShareStatus_SelfBegin,
	//The current user ends the share.
    ZoomSDKShareStatus_SelfEnd,
	//Other user begins the share.
    ZoomSDKShareStatus_OtherBegin,
	//Other user ends the share.
    ZoomSDKShareStatus_OtherEnd,
	//The current user is viewing the share by others.
    ZoomSDKShareStatus_ViewOther,
	//The share is paused.
    ZoomSDKShareStatus_Pause,
	//The share is resumed.
    ZoomSDKShareStatus_Resume,
	//The sharing content changes.
    ZoomSDKShareStatus_ContentTypeChange,
	//The current user begins to share the sounds of computer audio.
    ZoomSDKShareStatus_SelfStartAudioShare,
	//The current user stops sharing the sounds of computer audio.
    ZoomSDKShareStatus_SelfStopAudioShare,
	//Other user begins to share the sounds of computer audio.
    ZoomSDKShareStatus_OtherStartAudioShare,
	//Other user stops sharing the sounds of computer audio.
    ZoomSDKShareStatus_OtherStopAudioShare,
}ZoomSDKShareStatus;

/**
 * @brief Enumeration of Audio status.
 */
typedef enum{
	//For initialization.
    ZoomSDKAudioStatus_None = 0,
	//The audio is muted.
    ZoomSDKAudioStatus_Muted = 1,
	//The audio is unmuted.
    ZoomSDKAudioStatus_UnMuted = 2,
	//The audio is muted by the host.
    ZoomSDKAudioStatus_MutedByHost = 3,
	//The audio is unmuted by the host.
    ZoomSDKAudioStatus_UnMutedByHost = 4,
	//Host mutes all participants.
    ZoomSDKAudioStatus_MutedAllByHost = 5,
	//Host unmutes all participants.
    ZoomSDKAudioStatus_UnMutedAllByHost = 6,
}ZoomSDKAudioStatus;

typedef enum{
	//No audio.
    ZoomSDKAudioType_None = 0,
	//VoIP.
    ZoomSDKAudioType_Voip = 1,
	//Phone.
    ZoomSDKAudioType_Phone = 2,
	//Unknown audio type.
    ZoomSDKAudioType_Unknow = 3,
}ZoomSDKAudioType;
/**
 * @brief Enumeration of status of remote control.
 */
typedef enum{
	//For initialization.
    ZoomSDKRemoteControlStatus_None,
    //Viewer can request to control the sharer remotely.
    ZoomSDKRemoteControlStatus_CanRequestFromWho,
    //Sharer receives the request from viewer.
    ZoomSDKRemoteControlStatus_RequestFromWho,
    //Sharer declines your request to be remote controlled.
    ZoomSDKRemoteControlStatus_DeclineByWho,
    //Sharer is remote controlled by viewer
    ZoomSDKRemoteControlStatus_RemoteControlledByWho,
    //Notify user that controller of the shared content changes.
    ZoomSDKRemoteControlStatus_StartRemoteControllWho,
	//Remote control ends.
    ZoomSDKRemoteControlStatus_EndRemoteControllWho,
    //Viewer gets the privilege of remote control.
    ZoomSDKRemoteControlStatus_HasPrivilegeFromWho,
    //Viewer loses the privilege of remote control.
    ZoomSDKRemoteControlStatus_LostPrivilegeFromWho,
}ZoomSDKRemoteControlStatus;

/**
 * @brief Enumeration of Recording status.
 */
typedef enum{
	//For initialization.
    ZoomSDKRecordingStatus_None,
	//Start recording.
    ZoomSDKRecordingStatus_Start,
	//Stop recording.
    ZoomSDKRecordingStatus_Stop,
	//The space of storage is full.
    ZoomSDKRecordingStatus_DiskFull,
    //Pause recording.
    ZoomSDKRecordingStatus_Pause,
}ZoomSDKRecordingStatus;

/**
 * @brief Enumeration of connection quality.
 */
typedef enum{
	//Unknown connection status.
    ZoomSDKConnectionQuality_Unknow,
	//The connection quality is very poor.
    ZoomSDKConnectionQuality_VeryBad,
	//The connection quality is poor. 
    ZoomSDKConnectionQuality_Bad,
	//The connection quality is not good.
    ZoomSDKConnectionQuality_NotGood,
	//The connection quality is normal.
    ZoomSDKConnectionQuality_Normal,
	//The connection quality is good.
    ZoomSDKConnectionQuality_Good,
	//The connection quality is excellent.
    ZoomSDKConnectionQuality_Excellent,
}ZoomSDKConnectionQuality;

/**
 * @brief Enumeration of H.323 device outgoing call status.
 * @note The order of enumeration members has been changed.H323CalloutStatus_Unknown has been moved.
 */
typedef enum
{
	//Call out successfully.
    H323CalloutStatus_Success,
	//In process of ringing.
    H323CalloutStatus_Ring,
	//Timeout.
    H323CalloutStatus_Timeout,
	//Failed to call out.
    H323CalloutStatus_Failed,
    //Unknown status.
    H323CalloutStatus_Unknown,
}H323CalloutStatus;

/**
 * @brief Enumeration of H.323 device pairing Status.
 */
typedef enum
{
	//Unknown status.
    H323PairingResult_Unknown,
	//Pairing successfully.
    H323PairingResult_Success,
	//Pairing meeting does not exist.
    H323PairingResult_Meeting_Not_Exist,
	//Pairing code does not exist.
    H323PairingResult_Paringcode_Not_Exist,
	//No pairing privilege.
    H323PairingResult_No_Privilege,
	//Other errors.
    H323PairingResult_Other_Error,
}H323PairingResult;

/**
 * @brief Enumeration of H.323 device types.
 */
typedef enum
{
	//Unknown types.
    H323DeviceType_Unknown,
	//H.323 device
    H323DeviceType_H323,
	//SIP
    H323DeviceType_SIP,
}H323DeviceType;

/**
 * @brief Enumeration of screen types for multi-sharing.
 */
typedef enum
{
  //Primary displayer.
  ScreenType_First,
  //Secondary displayer.
  ScreenType_Second,
}ScreenType;

/**
 * @brief Enumeration of video UI types in the meeting.
 */
typedef enum
{
   //No video in the meeting.
   MeetingUIType_None,
   //Video wall mode..
   MeetingUIType_VideoWall,
   //Display the video of active user. 
   MeetingUIType_ActiveRender,
}MeetingUIType;

/**
 * @brief Join meeting with required information.
 */
typedef enum
{
	//For initialization.
    JoinMeetingReqInfoType_None,
	//Join meeting with password.
    JoinMeetingReqInfoType_Password,
	//The password for join meeting is incorrect.
    JoinMeetingReqInfoType_Password_Wrong,
}JoinMeetingReqInfoType;

/**
 * @brief Enumeration of meeting types
 */
typedef enum
{
	//There is no meeting.
    MeetingType_None,
	//Normal meeting.
    MeetingType_Normal,
	//Breakout meeting.
    MeetingType_BreakoutRoom,
	//Webinar.
    MeetingType_Webinar,
}MeetingType;

/**
 * @brief Enumeration of user roles.
 */
typedef enum
{
	//For initialization.
    UserRole_None,
	//Host.
    UserRole_Host,
	//Co-host.
    UserRole_CoHost,
	//Attendee in the webinar.
    UserRole_Attendee,
	//Panelist.
    UserRole_Panelist,
	//Moderator of breakout room.
    UserRole_BreakoutRoom_Moderator,
}UserRole;

/**
 * @brief Enumeration of phone call status
 */
typedef enum
{
	//No status.
    PhoneStatus_None,
	//In process of calling out.
    PhoneStatus_Calling,
	//In process of ringing.
    PhoneStatus_Ringing,
	//The call is accepted.
    PhoneStatus_Accepted,
	//Call successful.
    PhoneStatus_Success,
	//Call failed.
    PhoneStatus_Failed,
	//In process of canceling the response to the previous state.
    PhoneStatus_Canceling,
	//Cancel successfully.
    PhoneStatus_Canceled,
	//Failed to cancel.
    PhoneStatus_Cancel_Failed,
	//Timeout.
    PhoneStatus_Timeout,
}PhoneStatus;

/**
 * @brief Enumeration of reasons of phone calls failed
 */
typedef enum
{
	//For initialization.
    PhoneFailedReason_None,
	//The telephone service is busy.
    PhoneFailedReason_Busy,
	//The telephone is out of service.
    PhoneFailedReason_Not_Available,
	//The phone is hung up.
    PhoneFailedReason_User_Hangup,
	//Other reasons.
    PhoneFailedReason_Other_Fail,
	//The call is not answered.
    PhoneFailedReason_No_Answer,
	//Disable the function of international callout before the host joins the meeting.
    PhoneFailedReason_Block_No_Host,
	//The call-out is blocked by the system due to the high cost.
    PhoneFailedReason_Block_High_Rate,
	//All the invitees invited by the call should press the button one(1) to join the meeting. In case that many invitees do not press the button that leads to time out, the call invitation for this meeting shall be banned.
    PhoneFailedReason_Block_Too_Frequent,
}PhoneFailedReason;

/**
 * @brief Enumeration of types of shared content.
 */
typedef enum
{
	//Type unknown.
    ZoomSDKShareContentType_UNKNOWN,
	//Type of sharing the application.
    ZoomSDKShareContentType_AS,
	//Type of sharing the desktop.
    ZoomSDKShareContentType_DS,
	//Type of sharing the white-board.
    ZoomSDKShareContentType_WB,
	//Type of sharing data from the device connected WIFI.
    ZoomSDKShareContentType_AIRHOST,
	//Type of sharing the camera.
    ZoomSDKShareContentType_CAMERA,
	//Type of sharing the data.
    ZoomSDKShareContentType_DATA,
	//Wired device, connect Mac and iPhone.
    ZoomSDKShareContentType_WIRED_DEVICE,
	//Share a portion of screen in the frame.
    ZoomSDKShareContentType_FRAME,
	//Share a document.
    ZoomSDKShareContentType_DOCUMENT,
	//Share only the audio sound of computer.
    ZoomSDKShareContentType_COMPUTER_AUDIO
}ZoomSDKShareContentType;

/**
 * @brief Enumeration of the number types for calling to join the audio into a meeting.
 */
typedef enum
{
	//For initialization.
    CallInNumberType_None,
	//Paid.
    CallInNumberType_Toll,
	//Free.
    CallInNumberType_TollFree,
}CallInNumberType;

/**
 * @brief Enumeration of in-meeting buttons on the toolbar.
 */
typedef enum
{
	//Invitation button: invite others.
    ToolBarInviteButton,
	//Audio button: manage in-meeting audio of the current user.
    FitBarAudioButton,
	//Video button: manage in-meeting video of the current user.
    FitBarVideoButton,
	//Participant button: manage or check the participants.
    FitBarParticipantButton,
	//Share button: share screen or application, etc.
    FitBarNewShareButton,
	//Remote control button when sharing or viewing the share. 
    FitBarRemoteControlButton,
	//Pause the share.
    FitBarPauseShareButton,
	//Annotation button.
    FitBarAnnotateButton,
	//Question and answer(QA) button. Available only in webinar.
    FitBarQAButton,
	//Broadcast the webinar so user can join the webinar.
    FitBarBroadcastButton,
	//Poll button: questionnaire.
    FitBarPolling,
	//More: other functions in the menu.
    FitBarMoreButton,
	//Exit full screen.
    MainExitFullScreenButton,
	//Button for getting host.
    ClaimHostButton,
	//Upgarde button of free meeting remain time tooltip view.
    UpgradeButtonInFreeMeetingRemainTimeTooltip,
    //Video button: manage in-meeting video of the current user.
    ToolBarVideoButton,
    //Swap share and video button: swap to display share or video.
    SwapShareContentAndVideoButton,
    //Chat button: manage in-meeting chat of the current user.
    ChatButton,
    //Question and answer(QA) button on toolbar. Available only in webinar.
    ToolBarQandAButton,
    //Poll button: questionnaire.
    ToolBarPollingButton
}SDKButton;

/**
 * @brief Enumeration of security session types.
 */
typedef enum
{
	//Unknown component
    SecuritySessionComponet_Unknown,
	//Chat.
    SecuritySessionComponet_Chat,
	//File Transfer.
    SecuritySessionComponet_FT,
	//Audio.
    SecuritySessionComponet_Audio,
	//Video.
    SecuritySessionComponet_Video,
	//Share application.
    SecuritySessionComponet_AS,
}SecuritySessionComponet;

/**
 * @brief Enumeration of warning types.
 */
typedef enum
{
	//No warnings.
    StatisticWarningType_None,
	//The quality of the network connection is very poor.
    StatisticWarningType_NetworkBad,
	//The CPU is highly occupied.
    StatisticWarningType_CPUHigh,
	//The system is busy.
    StatisticWarningType_SystemBusy,
}StatisticWarningType;

/**
 * @brief Enumeration of component types.
 */
typedef enum{
	//For initialization.
    ConnectionComponent_None,
	//Share.
    ConnectionComponent_Share,
	//Video.
    ConnectionComponent_Video,
	//Audio.
    ConnectionComponent_Audio,
}ConnectionComponent;

/**
 * @brief Enumeration of ending meeting errors.
 */
typedef enum{
	//For initialization.
    EndMeetingReason_None = 0,
	//The user is kicked off by the host and leaves the meeting.
    EndMeetingReason_KickByHost = 1,
	//Host ends the meeting.
    EndMeetingReason_EndByHost = 2,
	//Join the meeting before host (JBH) timeout.
    EndMeetingReason_JBHTimeOut = 3,
	//Meeting is ended for there is no attendee joins it.
    EndMeetingReason_NoAttendee = 4,
	//Host ends the meeting for he will start another meeting.
    EndMeetingReason_HostStartAnotherMeeting = 5,
	//Meeting is ended for the free meeting timeout.
    EndMeetingReason_FreeMeetingTimeOut = 6,
	//Meeting is ended for network broken.
    EndMeetingReason_NetworkBroken = 7,
}EndMeetingReason;

/**
 * @brief Enumeration of H.323/SIP encryption types. Available only for Huawei.
 */
typedef enum
{
	//Meeting room system is not encrypted.
    EncryptType_NO,
	//Meeting room system is encrypted.
    EncryptType_YES,
	//Meeting room system is encrypted automatically.
    EncryptType_Auto
}EncryptType;

/**
 * @brief Enumeration of connection types. 
 */
typedef enum{
	//Unknown connection types.
    SettingConnectionType_Unknow,
	//Peer to peer.
    SettingConnectionType_P2P,
	//Connect to the cloud.
    SettingConnectionType_Cloud,
}SettingConnectionType;

/**
 * @brief Enumeration of network types. 
 */
typedef enum{
	//Unknown network type.
    SettingNetworkType_Unknow,
	//Wired LAN
    SettingNetworkType_Wired,
	//WIFI
    SettingNetworkType_WiFi,
	//PPP
    SettingNetworkType_PPP,
	//3G
    SettingNetworkType_3G,
	//Other network types.
    SettingNetworkType_Other,
}SettingNetworkType;

/**
 * @brief Enumeration of video render element types.
 */
typedef enum{
	//For initialization.
    VideoRenderElementType_None,
	//Preview the video of user himself.
    VideoRenderElementType_Preview,
	//Render the video of active speaker.
    VideoRenderElementType_Active,
	//Render normal video. 
    VideoRenderElementType_Normal,
}VideoRenderElementType;

/**
 * @brief Enumeration of video render data types.
 */
typedef enum{
	//For initialization.
    VideoRenderDataType_None,
	//Video data.
    VideoRenderDataType_Video,
	//Avatar data.
    VideoRenderDataType_Avatar,
}VideoRenderDataType;

/**
 * @brief Enumeration of sharing modes.
 */
typedef enum{
	//The mode of shared content adaptive pattern in the view.
    ViewShareMode_FullFill,
	//Letterbox. It is the practice of transferring film shot in a widescreen aspect ratio to standard-width video formats while preserving the film's original aspect ratio. 
    ViewShareMode_LetterBox,
}ViewShareMode;

/**
 * @brief Enumeration of annotation status.
 */
typedef enum{
	//Ready to annotate.
    AnnotationStatus_Ready,
	//Annotation is closed.
    AnnotationStatus_Close,
	//For initialization.
    AnnotationStatus_None,
}AnnotationStatus;

/**
 * @brief Enumeration of live stream status.
 */
typedef enum{
	//Only for initialization.
    LiveStreamStatus_None,
	//Live stream in process.
    LiveStreamStatus_InProgress,
	//Be connecting.
    LiveStreamStatus_Connecting,
	//Connect timeout.
    LiveStreamStatus_StartFailedTimeout,
	//Connect failed to the live streaming. 
    LiveStreamStatus_StartFailed,
	//End.
    LiveStreamStatus_Ended,
}LiveStreamStatus;

/**
 * @brief Enumeration of reminder types.
 * @note This enum has been deprecated, will be deleted next release.
 */
typedef enum{
	//Remind user that he can start the free, unlimited group meeting for two times.
    SDKReminderType_CanFreeTrial,  
	//Upgrade to the priority meeting at once. 
    SDKReminderType_CanUpgradeAccount,  
	//The participants in the meeting receives the reminder that the free meeting will be ended for time is running out.
    SDKReminderType_GuestReminder, 
	//Upgrade successfully.
    SDKReminderType_UpgradeSuccess,
	//Failed to upgrade the account.
    SDKReminderType_UpgradeFailed,
	//For initialization.
    SDKReminderType_None,
}SDKReminderType;

typedef enum{
    FreeMeetingNeedUpgradeType_NONE,
    FreeMeetingNeedUpgradeType_BY_ADMIN,
    FreeMeetingNeedUpgradeType_BY_GIFTURL,
}FreeMeetingNeedUpgradeType;

/**
 * @brief Enumeration of direct sharing status.
 */
typedef enum{
	//For initialization.
    DirectShareStatus_None = 0,
	//Waiting for enabling the direct sharing.
    DirectShareStatus_Connecting = 1,  
	//In direct sharing mode.
    DirectShareStatus_InProgress = 2,  
	//End the direct sharing.
    DirectShareStatus_Ended = 3,  
	//Input the meeting ID/pairing code.
    DirectShareStatus_NeedMeetingIDOrSharingKey = 4,  
	//The meeting ID or pairing code is wrong.
    DirectShareStatus_WrongMeetingIDOrSharingKey = 5,
	//Network issue. Reconnect later. 
    DirectShareStatus_NetworkError = 6,  
	//Unknown share status.
    DirectShareStatus_Unknow = 7,
}DirectShareStatus;

/**
 * @brief Enumeration of audio types when schedules a meeting.
 */
typedef enum{
	//Normal audio type.
    ScheduleMeetingAudioType_None = 0,
	//In telephone mode.
    ScheduleMeetingAudioType_Telephone = 1,  
	//In VoIP mode.
    ScheduleMeetingAudioType_Voip = 1<<1,  
	//Use telephone and VoIP.
    ScheduleMeetingAudioType_Both = 1<<2,  
	//Use the third party audio.
    ScheduleMeetingAudioType_3rd= 1<<3,  
}ScheduleMeetingAudioType;

/**
 * @brief Enumeration of meeting recording types.
 */
typedef enum{
	//For initialization.
    ScheduleMeetingRecordType_None = 0,
	//Local Recording
    ScheduleMeetingRecordType_Local = 1,
	//Cloud Recording
    ScheduleMeetingRecordType_Cloud = 1<<1,
}ScheduleMeetingRecordType;

/**
 * @brief Enumeration of types to register webinar.
 */
typedef enum
{
	//For initialization.
    WebinarRegisterType_None,
	//Register webinar with URL.
    WebinarRegisterType_URL,
	//Register webinar with email.
    WebinarRegisterType_Email,
}WebinarRegisterType;

/**
 * @brief Enumeration of microphone test types.
 */
typedef enum{
	//Normal status.
    testMic_Normal = 0,
	//Recording.
    testMic_Recording,
	//Stop recording.
    testMic_RecrodingStoped,
	//Playing.
    testMic_Playing,
}ZoomSDKTestMicStatus;

/**
 * @brief Enumeration of device status.
 */
typedef enum{
	//Unknown device.
    Device_Error_Unknow,
	//New device is detected by the system.
    New_Device_Found,
	//The device is not found.
    Device_Error_Found,
	//No device.
    No_Device,
	//No sound can be detected from the microphone.
    Audio_No_Input, 
	//The audio is muted. Press Command+Shift+A to unmute
    Audio_Error_Be_Muted, 
	//The device list is updated.
    Device_List_Update,
	//The audio is disconnected once detected echo.
    Audio_Disconnect_As_Detected_Echo,
}ZoomSDKDeviceStatus;

/**
 * @brief Enumerations of sharing types.
 */
typedef enum{
	//Anyone can share, but only one can share at a  moment, and only the host can start sharing when another user is sharing. The previous share will be ended once the host grabs the sharing.
    ShareSettingType_OnlyHostCanGrab = 0,
	//Only host can share.
    ShareSettingType_OnlyHostCanShare = 1,//Only host can start sharing when someone else is sharing.
	//Only one participant can share at a time. And anyone can start sharing when someone else is sharing.
    ShareSettingType_AnyoneCanGrab = 2,
	//Multi participant can share at a moment.
    ShareSettingType_MutiShare = 3,
    ShareSettingType_None = 4,
}ZoomSDKShareSettingType;

/**
 *@brief Enumerations of General setting about share
 */
typedef enum {
    //When user share screen will enter full screen
    shareSettingCmd_enterFullScreen,
    //When user to share screen will enter max window
    shareSettingCmd_enterMaxWindow,
    //When user user side to side mode
    shareSettingCmd_sideToSideMode,
}shareSettingCmd;

/**
 * @brief Enumerations of attendee view question type.
 */
typedef enum {
    //Attendee only view the answered question.
    ViewType_OnlyAnswered_Question = 0,
    //Attendee view the all question.
    ViewType_All_Question,
}AttendeeViewQuestionType;

/**
 * @brief Enumerations of question status.
 */
typedef enum {
    //The question state is init.
    QAQuestionState_Init = 0,
    //The question is sent.
    QAQuestionState_Sent,
    //The question is received.
    QAQuestionState_Received,
    //The question send fail.
    QAQuestionState_SendFail,
    //The question is sending.
    QAQuestionState_Sending,
    //The question state is unknow for init.
    QAQuestionState_Unknow,
}ZoomSDKQAQuestionState;

/**
 * @brief Enumerations of Q&A connect status.
 */
typedef enum {
    //The Q&A is connecting.
    QAConnectStatus_Connecting = 0,
    //The Q&A is connected.
    QAConnectStatus_Connected,
    //The Q&A is disonnected.
    QAConnectStatus_Disonnected,
    //The Q&A is disonnected conflict.
    QAConnectStatus_Disconnect_Conflict,
}ZoomSDKQAConnectStatus;

/**
 * @brief Enumerations of Audio action info.
 */
typedef enum {
    //The audio button action info is none.
    ZoomSDKAudioActionInfo_none = 0,
    //The audio button action info is need to join voip.
    ZoomSDKAudioActionInfo_needJoinVoip,
    //The audio button action info is need to mute/unmute audio.
    ZoomSDKAudioActionInfo_muteOrUnmenuAudio,
    //The audio button action info is no audio device connected.
    ZoomSDKAudioActionInfo_noAudioDeviceConnected,
    //The audio button action info is computer audio device error.
    ZoomSDKAudioActionInfo_computerAudioDeviceError,
}ZoomSDKAudioActionInfo;




