//
//  ZoomSDKMeetingConfiguration.h
//  ZoomSDK
//
//  Created by TOTTI on 8/4/17.
//  Copyright © 2017 Zoom Video Communications,Inc. All rights reserved.
//
#import "ZoomSDKErrors.h"
@interface ZoomSDKMeetingConfiguration :NSObject
{
    //The APP to be shared.
    CGDirectDisplayID  _displayAppID;
    //The monitor ID.
    CGDirectDisplayID  _monitorID;
    //The location of float video.
    NSPoint            _floatVideoPoint;
    //The visibility of toolbar when sharing.
    BOOL               _shareToolBarVisible;
    //The visibility of main toolbar in the meeting. not support since version 4.4
    BOOL               _mainToolBarVisible;
    //The location of main interface of meeting.
    NSPoint            _mainVideoPoint;
    //The visibility of the window of waiting for the host.
    BOOL               _jbhWindowVisible;
    //Attendees join the meeting with audio muted.
    BOOL               _enableMuteOnEntry;
    //Play chime when user joins/leaves meeting
    BOOL               _enableChime;
    //Query whether to share screen or not.
    BOOL               _isDirectShareDesktop;
    //Enable auto-adjust the speaker volume when joining meeting.
    BOOL               _enableAutoAdjustSpeakerVolume;
    //Enable auto-adjust the microphone volume.
    BOOL                _enableAutoAdjustMicVolume;
    //Hide the meeting information on main window.
    BOOL                _hideMainWindowMeetingInfo;
    //The meeting ID customized by user and it is displayed on the title bar of meeting. 
    unsigned int        _newMeetingID;
    //Hide the prompt dialog of wrong password.
    BOOL                _disablePopupWrongPasswordWindow;
    //Auto-adjust speaker volume when joining meeting.  
    BOOL                _autoAdjustSpeakerVolumeWhenJoinAudio;
    //Auto adjust microphone volume when joining meeting.  
    BOOL                _autoAdjustMicVolumeWhenJoinAudio;
    //Disable the alert to end another ongoing meeting.
    BOOL                _disableEndOtherMeetingAlert;
    //Disable the prompt dialog to input password.
    BOOL                _disableInputPasswordWindow;
    //Disable the feature to enter full screen by double click.
    BOOL                _disableDoubleClickToFullScreen;
    //Hide the window of thumbnail video.
    BOOL                _hideThumbnailVideoWindow;
    //Huawei security APP name. 
    NSString*           _securityAppName;
    //Disable to rename in meeting
    BOOL                _disableRenameInMeeting;
    //Disable ZOOM original actions of clicking share button.
    BOOL                _disableShareButtonClickOriginAction;
    //Disable ZOOM original actions of clicking toolbar invite button.
    BOOL                _disableToolbarInviteButtonClickOriginAction;
    //Input meeting information in advance when user joins webinar.
    BOOL                _needPrefillWebinarJoinInfo;
    //Hide the confirm dialog of user leaves/ends meeting.
    BOOL                _hideLeaveMeetingWindow;
    //Disable ZOOM original actions of clicking button participants.
    BOOL                _disableParticipantButtonClickOriginAction;
    //Hide the Full Phone Number of purely Call-in User.
    BOOL                _hideFullPhoneNumber4PureCallinUser;
    //Hide the window of phone dialing in.
    BOOL                _hideTelephoneInAudiowWindow;
    //Hide the window of CALL ME.
    BOOL                _hideCallMeInAudioWindow;
    //Forbid multi-participants sharing at the same time.
    BOOL                _forceDisableMultiShare;
    //Set whether to enable global shortcuts in configuration.not support since version 4.6.
    BOOL                _enableGlobalShortcuts;
	//Disable custom live stream.
    BOOL                _disableCustomLiveStreamAction;
    //Set whether to disable ZOOM original reminder action for free user.
    BOOL                _disableFreeUserOriginAction;
    //Disable the ZOOM original notification of remaining time for meeting organized by free user.
    BOOL                _disableFreeMeetingRemainTimeNotify;
	//Hide the h323 call in tab on invite window.
    BOOL                _hideInviteInMeetingH323CallInTab;
	//Hide the h323 call out tab on invite window.
    BOOL                _hideInviteInMeetingH323CallOutTab;
    //Hide meeting static warning of bad network.
    BOOL                _hideMeetingStaticBadNetWorkWaring;
    //Hide meeting static warning of system busy.
    BOOL                _hideMeetingStaticSystemBusyWaring;
    //Hide switch camera button when sharing camera.
    BOOL                _hideSwitchCameraButton;
    //Disable opening recording file when meeting end.
    BOOL                _disableOpenRecordFileWhenMeetingEnd;
    //Hide 'show keypad' button on meeting window.
    BOOL                _hideShowKeypadButton;
    //Hide copy URL button when invite others join meeting
    BOOL                _hideCopyURLButtonWhenInviteOthers;
    //Hide copy Invitation button when invite others join meeting
    BOOL                _hideCopyInvitationButtonWhenInviteOthers;
    //Hide chat menu item in-meeting.
    BOOL                _hideChatItemInMeeting;
    //Hide remote control item on more menu.
    BOOL                _hideRemoteControlItemOnMoreMenu;
    //Hide choose save recording file path window.
    BOOL                _hideChooseSaveRecordingFilePathWindow;
    //Disable ZOOM original actions of clicking Audio button.
    BOOL                _disableAudioButtonClickOriginAction;
    //Disable audio menu item original action in-meeting.
    BOOL                _disableAudioSettingMenuButtonClickOriginAction;
    //Hide loading window when start meeting without login.
    BOOL                _hideLoadingWindow;
                 
}
@property(nonatomic, assign)CGDirectDisplayID displayAppID;
@property(nonatomic, assign)CGDirectDisplayID monitorID;
@property(nonatomic, assign)NSPoint floatVideoPoint;
@property(nonatomic, assign)NSPoint mainVideoPoint;
@property(nonatomic, assign)BOOL shareToolBarVisible;
@property(nonatomic, assign)BOOL jbhWindowVisible;
@property(nonatomic, assign)BOOL enableMuteOnEntry;
@property(nonatomic, assign)BOOL isDirectShareDesktop;
@property(nonatomic, assign)BOOL enableChime;
@property(nonatomic, assign)BOOL mainToolBarVisible;
@property(nonatomic, assign)BOOL hideMainWindowMeetingInfo;
@property(nonatomic, assign)unsigned int newMeetingID;
@property(nonatomic, assign)BOOL disablePopupWrongPasswordWindow;
@property(nonatomic, assign)BOOL autoAdjustSpeakerVolumeWhenJoinAudio;
@property(nonatomic, assign)BOOL autoAdjustMicVolumeWhenJoinAudio;
@property(nonatomic, assign)BOOL disableEndOtherMeetingAlert;
@property(nonatomic, assign)BOOL disableInputPasswordWindow;
@property(nonatomic, assign)BOOL disableDoubleClickToFullScreen;
@property(nonatomic, assign)BOOL hideThumbnailVideoWindow;
@property(nonatomic, retain)NSString* securityAppName;
@property(nonatomic, assign)BOOL disableRenameInMeeting;
@property(nonatomic, assign)BOOL disableShareButtonClickOriginAction;
@property(nonatomic, assign)BOOL disableToolbarInviteButtonClickOriginAction;
@property(nonatomic, assign)BOOL needPrefillWebinarJoinInfo;
@property(nonatomic, assign)BOOL hideLeaveMeetingWindow;
@property(nonatomic, assign)BOOL disableParticipantButtonClickOriginAction;
@property(nonatomic, assign)BOOL hideFullPhoneNumber4PureCallinUser;
@property(nonatomic, assign)BOOL hideTelephoneInAudiowWindow;
@property(nonatomic, assign)BOOL hideCallMeInAudioWindow;
@property(nonatomic, assign)BOOL forceDisableMultiShare;
@property(nonatomic, assign)BOOL enableGlobalShortcuts;
@property(nonatomic, assign)BOOL disableCustomLiveStreamAction;
@property(nonatomic, assign)BOOL disableFreeUserOriginAction;
@property(nonatomic, assign)BOOL disableFreeMeetingRemainTimeNotify;
@property(nonatomic, assign)BOOL hideInviteInMeetingH323CallInTab;
@property(nonatomic, assign)BOOL hideInviteInMeetingH323CallOutTab;
@property(nonatomic, assign)BOOL hideMeetingStaticBadNetWorkWaring;
@property(nonatomic, assign)BOOL hideMeetingStaticSystemBusyWaring;
@property(nonatomic, assign)BOOL hideSwitchCameraButton;
@property(nonatomic, assign)BOOL disableOpenRecordFileWhenMeetingEnd;
@property(nonatomic, assign)BOOL hideShowKeypadButton;
@property(nonatomic, assign)BOOL hideCopyURLButtonWhenInviteOthers;
@property(nonatomic, assign)BOOL hideCopyInvitationButtonWhenInviteOthers;
@property(nonatomic, assign)BOOL hideChatItemInMeeting;
@property(nonatomic, assign)BOOL hideRemoteControlItemOnMoreMenu;
@property(nonatomic, assign)BOOL hideChooseSaveRecordingFilePathWindow;
@property(nonatomic, assign)BOOL disableAudioButtonClickOriginAction;
@property(nonatomic, assign)BOOL disableAudioSettingMenuButtonClickOriginAction;
@property(nonatomic, assign)BOOL hideLoadingWindow;

- (ZoomSDKError)prefillWebinarUserName:(NSString*)userName Email:(NSString*)email;
- (ZoomSDKError)hideSDKButtons:(BOOL)hide ButtonType:(SDKButton)button;

/**
 @brief Change the title of window in the meeting.
 @param modify Set it to YES to modify the meeting number displayed on the title of window. 
 @param meetingnumber Custom meeting number. 
 @note If you want to show the default meeting number, set newMeetingNum = 0. Otherwise set other number to replace it.
 */
- (ZoomSDKError)modifyWindowTitle:(BOOL)modify NewMeetingNum:(unsigned int)meetingnumber;

/**
 @brief Modify the DSCP of audio and video.
 @param videoDSCP Video values in the meeting.
 @param audioDSCP Audio values in the meeting.
 @note It is necessary to input both values of the videoDSCP and audioDSCP if you want to modify.
 */
- (ZoomSDKError)modifyVideoDSCP:(int)videoDSCP AudioDSCP:(int)audioDSCP;

/**
 @brief Reset all properties in this class.
 */
- (void)reset;

@end


