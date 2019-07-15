//
//  ZMLocalization.h
//  ZCommonUI
//
//  Created by John on 12/20/16.
//  Copyright © 2016 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AUDIO_WINDOW_TITLE      @"Choose ONE of the audio conference options"
#define PHONE_CALL              @"Phone Call"
#define COMPUTER_AUDIO          @"Computer Audio"

//HotKey
//#define KEY_NAVIGATE_WINDOW     @"Navigate among Zoom popup windows"
#define KEY_PREVIOUS_GALLERY    @"View the previous 25 video participants in gallery view"
#define KEY_NEXT_GALLERY        @"View the next 25 video participants in gallery view"
#define KEY_SWITCH_MINIMAL      @"Switch to minimal window"
#define KEY_SWITCH_SPEAKER      @"Switch to speaker view"
#define KEY_SWITCH_GALLERY      @"Switch to gallery view"
#define KEY_ONOFF_VIDEO         @"Start/Stop video"
#define KEY_ONOFF_AUDIO         @"Mute/Unmute my audio"
#define KEY_OFF_ALL_AUDIO       @"Mute audio for everyone except host (available only to the host)"
#define KEY_ON_ALL_AUDIO        @"Unmute audio for everyone except host (available only to the host)"
#define KEY_ONOFF_SHARE         @"Start/Stop share screen"
#define KEY_PAUSE_RESUME_SHARE  @"Pause/Resume share (available only when you are sharing your screen)"
#define KEY_ONOFF_LOCAL_RECORD  @"Start/Stop local recording"
#define KEY_ONOFF_CLOUD_RECORD  @"Start/Stop cloud recording"
//#define KEY_PAUSE_RESUME_RECORD @"Pause/Resume recording"
#define KEY_SWITCH_CAMERA       @"Switch camera"
#define KEY_ENTER_EXIT_FULLSCR  @"Enter/Exit full screen mode"
#define KEY_ONOFF_CHAT          @"Display/Hide chat"
#define KEY_ONOFF_PARTICIPANTS  @"Display/Hide manage participants"
#define KEY_ON_INVITE           @"Open the invite window"
#define KEY_KEYBOARD_SHORTCUTS  @"Keyboard Shortcuts:"
//#define KEY_DESCRIPTION         @"Description"
#define KEY_ENABEL_SHORTCUTS    @"Enable shortcuts even when the Zoom app is not in focus"
#define KEY_ALWAYS_SHOW_MEETING_CONTROLS @"Always show meeting controls"
#define KEY_TOGGLE_HAND         @"Raise hand/Lower hand"

//Live Stream
#define LIVE_STREAM_STOP        @"Stop Live Stream"
#define LIVE_STREAM_ON          @"Live on"
#define LIVE_STREAM_PREPARING   @"Preparing..."
#define LIVE_STREAM_VIEW_STEAM  @"View Stream on %@"
#define LIVE_STREAM_ON_WEBSITE  @"on %@"
#define LIVE_STREAM_COPY_URL    @"Copy Streaming Link"
#define LIVE_STREAM_TIP_LVEON   @"Webinar is now streaming live on %@"
#define LIVE_STREAM_TIP_COPY    @"The streaming link has been copied to the clipboard"
#define LIVE_STREAM_TIP_TIMEOUT @"Unable to stream your webinar to %@.\nYou need to restart steaming."
#define LIVE_STREAM_LIVE        @"LIVE"

//waiting list
#define WAITING_HOST                @"Please wait, the meeting host will let you in soon."
#define WAITING_1USER_TITLE         @"1 person is waiting"
#define WAITING_MOREUSER_TITLE      @"%d people are waiting"
#define IN_MEETING_1USER_TITLE      @"1 participant in the meeting"
#define IN_MEETING_MOREUSER_TITLE   @"%d participants in the meeting"
#define WAITING_ADMIT               @"Admit"
#define WAITING_SEEWAITINGLIST      @"See waiting room"
#define WAITING_TIP_SINGLE_WAIT     @"%@ has entered the waiting room for this meeting"
#define WAITING_TIP_MULTI_WAIT      @"%d people have entered the waiting room for this meeting"
#define WAITING_PUTIN               @"Put attendee in Waiting Room on Entry"
#define WAITING_PUTON_HOLD          @"Put on hold"
#define WAITING_TAKEOFF_HOLD        @"Take off hold"
#define PUTIN_WAITING_ROOM          @"Put in waiting room"
//on hold
#define ONHOLD_1USER_TITLE          @"1 person is on hold"
#define ONHOLD_MOREUSER_TITLE       @"%d people are on hold"
#define UNMUTE_OR_INCREASE_VOLUME   @"Unmute your speaker or increase volume to hear other participants"

//#define PT_MAIN_SHARE_SCREEN        @"Share screen"

//polling
#define POLL_VOTE_LABEL             @"%d of %d (%d%%) voted"
#define POLL_HAS_BEEN_CLOSED        @"The poll was closed before you submitted your answer"

//
//#define LOGIN_COMMON_ERROR @"LN_Schedule_UnableConnect_NewIM"
//feedback in meeting
#define FEEDBACK_RAISEHAND          @"raise hand"
#define FEEDBACK_YES                @"yes"
#define FEEDBACK_NO                 @"no"
#define FEEDBACK_SLOWER             @"go slower"
#define FEEDBACK_FASTER             @"go faster"
#define FEEDBACK_EMOJI              @"more"
#define FEEDBACK_CLEANALL           @"clear all"
#define FEEDBACK_EMOJI_DISLIKE      @"dislike"
#define FEEDBACK_EMOJI_LIKE         @"like"
#define FEEDBACK_EMOJI_ENLIGHTENED  @"clap"
#define FEEDBACK_EMOJI_COFFEE       @"need a break"
#define FEEDBACK_EMOJI_CLOCK        @"away"
#define FEEDBACK_CLEAR_ALL          @"Clear All Feedback"

//audio dialog
#define AUDIO_DIALOG_JOIN_TIP           @"To hear others,\nclick the Join Audio button."
#define AUDIO_DIALOG_TEL_BIND_TEXT      @"Enter %@ on your phone\nto associate your phone call with this computer as one participant."
#define AUDIO_DIALOG_SHOW_DAILIN_NUMBER @"Show Dial-in Number"

//
#define IM_NOT_SUPPORTED_MSG_PROMPT   @"[Upgrade to the latest version to see this message.]"

//toolbar
#define TIP_SELECE_AUDIO_DEVICE     @"Click if you want to switch to a different microphone or speaker"

//sip
//#define SIP_NAVIGATEOR_ITEM @"Phone"
//#define SIP_ENTER_URL_TIP   @"Contact name or phone number"
//#define SIP_FROM_SIP_NUM    @"From: %@"
#define TIP_CANNOT_JOIN_AUDIO_IN_SIP_CALL @"Your audio has been switched to the connected voice call, and your audio will automatically reconnect back after the end of the voice call."
#define ACCEPT_END_SIPCALL @"End phone call and Start a meeting"
//#define CLEAR_ALL_HISTORY @"Clear all recents"
#define HISTORYMENU_VIDEO_CALL @"Start a video call"
#define HISTORYMENU_AUDIO_CALL @"Start a non-video call"
//#define HISTORYMENU_DELETE @"Delete"
//#define SIP_SEGMENT_KEYPAD @"Keypad"
//#define SIP_SEGMENT_CALLHISTORY @"Call History"
#define HISTORYITEM_TYPE_AUDIO @"Zoom Audio"
#define HISTORYITEM_TYPE_VIDEO @"Zoom Video"
//#define HISTORYITEM_TYPE_UNKNOWN  @"unknown"
//#define SIP_CLOSE_KEYPAD @"Close Keypad"
#define SIP_CALL_WHEN_MEETINGAUDIO_TITLE @"You have a meeting in progress"
#define SIP_CALL_WHEN_MEETINGAUDIO_INFORMATION @"If you continue to make a call, your audio will be transferred from the meeting to your phone call."
#define MEETING_WHEN_INSIPCALL_TITLE @"You have a phone call in progress"
#define JOIN_MEETING_WHEN_INSIPCALL_INFORMATION  @"If you continue, your phone call will end and you will join the meeting."
#define START_MEETING_WHEN_INSIPCALL_INFORMATION @"If you continue, your phone call will end and you will start the meeting."
//#define SIP_CALLING_STRING_FROMAT @"Calling %@..."
#define SIP_CALL_ACCEPT @"Accept"
#define SIP_CALL_DECLINE @"Decline"
#define SIP_HOLD_MEET_AUDIO_AND_ANSWER @"Hold meeting audio and Anwser"
//#define NO_CALL_HSTORY_TXT @"No Recents"
//#define PHONE_SERVICE_NOT_AVALIABLE  @"Phone service is not avaliable"
//#define SIP_PHONE @"(Internal)"
//#define SIP_CALL_FAILED @"Call Failed"
//#define END_CALL @"End call"
//#define SIP_REGISTER_ERROR_404 @"Your account is not available"
//#define SIP_REGISTER_ERROR_408 @"Your service is affected by a network issue"
//#define SIP_REGISTER_ERROR_480 @"The call recipient is not available"
//#define SIP_REGISTER_ERROR_403 @"Your phone has an internal configuration error"


#define UNMUTE_MYSELF               @"Unmute Myself"
#define YOU_ARE_MUTED               @"You are muted."
//#define ENABLE_FACE_BEAUTITY        @"Touch up my appearance"

#define ERROR_CODE                  @"error code"

#define MAINMENU_SERVICES           @"Services"
//#define IM_ADD_CUSTOM_STATUS        @"Add a Personal Note"
//#define IM_REMOVE_CUSTOM_STATUS     @"Remove Personal Note"
//#define SHOW_MEETING_TIME           @"Show my connected time"

#define TAB_ACCESSIBILITY_COUNT @"count"
//free trial extend ZOOM-15607
//#define FREE_TRIAL_EXTEND_TITLE         @"Here's a gift\n\n"//ZOOM-47442
//#define FREE_TRIAL_EXTEND_DETAIL        @"We've removed the 40-minute time limit on your first group meeting."//ZOOM-47442
#define FREE_TRIAL_EXTEND_ERROR_TITLE   @"Unable to extend this meeting\n"
#define FREE_TRIAL_EXTEND_ERROR_DETAIL  @"Zoom cannot extend your free meeting at this time. Your meeting will end when the duration reaches 40 minutes.\n\n(ERROR : %d)"
#define HOST_MEETING_UNLIMITED          @"This meeting now has unlimited minutes." //[Zoom-17617]
#define ATTENDEE_MEETING_UNLIMITED      @"This meeting has been upgraded by the host and now includes unlimited minutes." //[Zoom-17617]
#define RESTRICTED_LOGIN_DOMAIN         @"Login is restricted to email addresses that have the following domains:"
//#define RESTRICTED_START_MEETING        @"You are not authorized to start the meeting using the credentials you signed in with."
#define CONTINUE_WITHOUT_AUDIO          @"Continue Without Audio"
//#define RECORD_NOT_INCLUDE_RECORD       @"Recording will not include audio"
#define YOU_ARE_USING_PHONE_FOR_AUDIO   @"You are now using your phone for audio in this meeting"
#define START_VIDEO_MEETING             @"Start a meeting with video"
#define START_NOVIDEO_MEETING           @"Start a meeting without video"
#define JOIN_MEETING                    @"Join a Meeting"
#define SCHEDULE                        @"Schedule"
#define SHARE_SCREEN                    @"Share screen"
#define SIGN_IN                         @"Sign In"
#define LOG_OUT                         @"Log Out"
#define SWITCH_ACCOUNT                  @"Switch Account"
#define QUIT_ZOOM                       @"Quit Zoom"
#define PREFERENCES                     @"Preferences..."
#define AUDIO_SETTINGS                  @"Audio Settings"

//setting
#define SETTING_LOCAL_RECORD_LABEL          @"Local Recording :"
#define SETTING_CLOUD_RECORD_LABEL          @"Cloud Recording :"
#define SETTING_MANAGE_CMR_MORE_BUTTON      @"Manage..."
#define SETTING_CLOUD_STORAGE               @"You have %@ of cloud record storage"
#define SETTING_CLOUD_USED_STORAGE          @"%@ used"

//meeting alter
#define OK_UPPERCASE                        @"OK"
#define ALERT_CMR_MANAGE_BUTTON             @"Manage cloud storage"
#define ALERT_CMR_RECORD_BUTTON             @"Record on this computer"
#define ALERT_CMR_FULL_LABEL                @"Cloud recording not started.\n"
#define ALERT_CMR_FULL_DESCRIBE_ORIGNALHOST_CAN_UPGRADE      @"Your account has used up all of the cloud storage space currently available. To record to the cloud, delete some older recordings or upgrade your cloud recording plan."
#define ALERT_CMR_FULL_DESCRIBE_ORIGNALHOST_CANNOT_UPGRADE  @"Your account has used up all of the cloud storage space currently available. To record to the cloud, delete some older recordings."
#define ALERT_CMR_FULL_DESCRIBE_OTHER_CAN_LOCALRECORD       @"Host has used the maximum storage space available. To record to the cloud, ask the meeting organizer to delete some older recordings or upgrade the cloud recording plan."
#define ALERT_CMR_FULL_DESCRIBE_OTHER_CANNOT_LOCALRECORD    @"Coud storage does not have enough space. Please contact host to upgrade plan or remove some old recording files."
#define MEETING_AUTHORIZE_HEADLINE          @"This meeting is for authorized attendees only"
#define MEETING_AUTHORIZE_CONTENT           @"Click \"Sign In to Join\" to sign into Zoom with an email address authorized for joining this meeting"
#define MEETING_AUTHORIZE_LOGIN_CONTENT     @"Click \"Switch Account to Join\" to sign into Zoom with an email address authorized for joining this meeting"
#define SIGNIN_TO_JOIN                      @"Sign In to Join"
#define SWITCH_ACCOUNT_TO_JOIN              @"Switch Account to Join"
#define OPEN_MANAGE_PARTICIPANT             @"Open Manage Participants"
#define I_WILL_TYPE                         @"I will type"

//#define VIDEO_SCALE_TYPE                    @"Corp images to fit to window when watch video (do not letterbox)"//[Zoom-18244]
#define LOCK_MEETING                        @"Lock Meeting"//[Zoom-18265]
#define LOCK_MEETING_DESCRIPTION            @"No new attendees can join this meeting once locked."//[Zoom-18265]
#define UNLOCK_MEETING                      @"Unlock Meeting"//[Zoom-18265]
#define UNLOCK_MEETING_DESCRIPTION          @"New attendees can join this meeting once unlocked."//[Zoom-18265]
#define LOCK_WEBINAR                        @"Lock Webinar"//[Zoom-18265]
#define LOCK_WEBINAR_DESCRIPTION            @"No new attendees can join this webinar once locked."//[Zoom-18265]
#define UNLOCK_WEBINAR                      @"Unlock Webinar"//[Zoom-18266]
#define UNLOCK_WEBINAR_DESCRIPTION          @"New attendees can join this webinar once unlocked."//[Zoom-18265]

//#define SETTING_RECORD_AUDIO_TRACK          @"Record a separate audio file for each participant who speaks"

#define KEY_GAIN_REMOTECONTROL              @"Gain remote control"
#define CONTINUE                            @"Continue"
#define VOICROVER_CONNECTED_MEETING_TIME    @"My connected time is %d hour %d minute"

#define DIRECT_SHARE_STOP                   @"Stop share"
#define AIRHOST_AIRPLAY                     @"iPhone/iPad via AirPlay"//[Zoom-16943]
#define AIRHOST_CABLE                       @"iPhone/iPad via Cable"//[Zoom-16943]
#define AIRHOST_CONNECT_DEVICE              @"Connect your iPhone or iPad to this computer"//[Zoom-16943]
#define AIRHOST_SELECT_TRUST                @"When prompted on your iPhone or iPad, select \"Trust\""//[Zoom-16943]
//#define SETTING_SHOW_ZOOM_IN_MENUBAR        @"Show Zoom menu in menu bar"//[Zoom-21260]
#define ORIGINAL_SOUND_SELECT_DEFAULT       @"Select a microphone to always use original sound"//[Zoom-17822]
#define GUEST                               @"Guest"//[Zoom-20772]


//#define QA_ANSWER_VERBALLY                  @"Answered this question verbally."//[Zoom-18899]
//#define QA_DISMISS                          @"Dismiss"//[Zoom-18899]
//#define QA_DISMISSED                        @"Dismissed"//[Zoom-18899]
//#define SETTING_SHOW_ZOOM_IN_MENUBAR        @"Show Zoom menu in menu bar"//[Zoom-21260]

//#define STOP_REMOTE_CONTROL                 @"Stop remote control" //[zoom-27176]

