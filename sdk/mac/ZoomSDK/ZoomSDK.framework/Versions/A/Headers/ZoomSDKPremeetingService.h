//
//  ZoomSDKPremeetingService.h
//  ZoomSDK
//
//  Created by TOTTI on 8/23/16.
//  Copyright © 2016 Zoom Video Communications,Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

typedef enum{
    ScheduleComponent_UpgradeAccountTipForFreeUser,
}ScheduleComponent;


@interface ZoomSDKDirectShareHandler: NSObject
/**
 * @brief Input meeting number to share the screen directly. 
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)inputMeetingNumber:(NSString*)meetingNumber;
/**
 * @brief Input pairing code in ZOOM Rooms to share the screen directly. 
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)inputSharingKey:(NSString*)shareKey;
/**
 * @brief Designated to cancel input action.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)cancel;
@end

@protocol ZoomSDKDirectShareHelperDelegate<NSObject>
/**
 * @brief Notification if the status of direct sharing changes. 
 * @param status The status of direct sharing.
 * @param handler The handler works only when the value of status is DirectShareStatus_NeedMeetingIDOrSharingKey or DirectShareStatus_WrongMeetingIDOrSharingKey
 */
-(void)onDirectShareStatusReceived:(DirectShareStatus)status DirectShareReceived:(ZoomSDKDirectShareHandler*)handler;
@end

@interface ZoomSDKDirectShareHelper: NSObject
{
    id<ZoomSDKDirectShareHelperDelegate> _delegate;
}
@property(nonatomic, assign) id<ZoomSDKDirectShareHelperDelegate> delegate;
/**
 * @brief Query if user can auto-share directly by using ultrasonic proximity signal.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)canDirectShare;
/**
 * @brief Start direct sharing by using ultrasonic proximity signal. 
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)startDirectShare;
/**
 * @brief Stop direct sharing by using ultrasonic proximity signal. 
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)stopDirectShare;
@end

@protocol ZoomSDKOutlookPluginDelegate <NSObject>
/**
 * @brief Notification of requirement to login from Outlook.
 */
-(void)onOutlookPluginNeedLoginRequest;

/**
 * @brief Notification of requirement to schedule a meeting from outlook.
 */
-(void)onOutlookPluginScheduleMeetingRequest;

/**
 * @brief The callback will be triggered when the outlook plugin requests to assign a meeting topic.
 * @param scheduleForEmail The meeting that you scheduled for whom. The email owner will be the host of the scheduled meeting.	
 * @param topic The meeting topic in default. It is able to be changed.
 */
-(void)onOutlookPluginDefaultMeetingTopicRequest:(NSString*)scheduleForEmail DefaultMeetingTopic:(NSString**)topic;
@end


@interface ZoomSDKOutlookPluginHelper : NSObject
{
    id<ZoomSDKOutlookPluginDelegate> _delegate;
}
@property(nonatomic, assign)id<ZoomSDKOutlookPluginDelegate> delegate;
/**
 * @brief Start outlook plugin helper service.
 * @param ipcName The channel of ipc used to connect SDK to outlookplugin.
 * @param ipcNoti The channel of ipc used to connect outlookplugin to sdk. 
 * @param appName Name of user's App.
 * @param identity User's App identity.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)start:(NSString*)ipcName IPCNoti:(NSString*)ipcNoti AppName:(NSString*)appName AppIdentity:(NSString*)identity;
/**
 * @brief Stop outlook plugin helper service.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
-(ZoomSDKError)stop;
@end

@interface IMeetingDateOption : NSObject
/**
 * @brief Get the start time of meeting.
 * @return If the function succeeds, it will return the start time of the meeting.
 */
-(time_t) getMeetingStartTime;
/**
 * @brief Get the duration of meeting.
 * @return If the function succeeds, it will return the duration of the meeting.
 */
-(unsigned int)getMeetingDuration;
/**
 * @brief Query if the meeting is a recurring one.
 * @return YES means that the meeting is a recurring one, otherwise not.
 */
-(BOOL) isRecurringMeeting;
@end

@interface ScheduleMeetingDateOption : IMeetingDateOption
/**
 * @brief Set the start time of meeting.
 * @param startime The start time of meeting.
 */
- (void)setMeetingStartTime:(time_t)starttime;
/**
 * @brief Set the duration time of meeting.
 * @param duration The duration of meeting.
 */
- (void)setMeetingDuration:(unsigned int)duration;
/**
 * @brief Set if the meeting is a recurring one.
 */
- (void)enableRecurringMeeting:(BOOL)recurring;
@end

@interface IMeetingAudioOption: NSObject
/**
 * @brief Get the audio type of the scheduled meeting.
 * @param availableAudioType Type of available audio.
 */
- (ScheduleMeetingAudioType)getScheduleMeetingAudioType:(int*)availableAudioType;
/**
 * @brief Query if user can get the information of dialing in.
* @return YES means that user can get the information, otherwise not.
 */
- (BOOL)canGetDialinInfo;
/**
 * @brief Get the array of available countries where user can dial in.
 * @return An NSArray contains all available dial-in countries.
 */
- (NSArray*)getAvailableDialinCountry;
/**
 * @brief Get the selected country listed in the array.
 * @return An NSArray contains all selected dial-in countries.
 */
- (NSArray*)getSelectedDialinCountry;
/**
 * @brief Query if the toll-free numbers are enabled in the call-in number list.
 * @return YES means that the toll-free numbers are enabled.
 */
- (BOOL)enableIncludeTollFreeNum;
@end

@interface ScheduleMeetingAudioOption :IMeetingAudioOption
/**
 * @brief Set the audio type of scheduled meeting.
 * @param type The type of audio.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
- (ZoomSDKError)setScheduleMeetingAudioType:(ScheduleMeetingAudioType)type;
/**
 * @brief Set an array of dialing countries to be selected.
 * @param array The array of countries.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)selectDialinCountry:(NSArray*)array;
/**
 * @brief Set if the feature is selected that the toll-free numbers are included.
 * @param include The toll-free numbers are included.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)selectIncludeTollFreeNum:(BOOL)include;
@end

@interface IMeetingVideoOption :NSObject
/**
 * @brief Query if the video of host is on.
 * @return YES means that host's video is on, otherwise not.
 */
- (BOOL)isHostVideoOn;
/**
 * @brief Query if the video of participant is on.
 * @return YES means that participant's video is on, otherwise not.
 */
- (BOOL)isParticipantVideoOn;
@end

@interface ScheduleMeetingVideoOption: IMeetingVideoOption
/**
 * @brief Set whether to turn on the host's video.
 * @param on YES means turning on, otherwise not.
 */
- (void)setHostVideoOn:(BOOL)on;
/**
 * @brief Set whether to turn on the participants' video.
 * @param on YES means turning on, otherwise not.
 */
- (void)setParticipantVideoOn:(BOOL)on;
@end

@interface IScheduleForUser: NSObject
{
    NSString* _email;
    NSString* _displayName;
}
/**
 * @brief The email of the host for whom the meeting is scheduled.
 * @param email Host's email.
 */
@property(nonatomic, readwrite, retain) NSString* email;
/**
 * @brief The screen name of the host for whom the meeting is scheduled.
 * @param displayName The screen name of host.
 */
@property(nonatomic, readwrite, retain) NSString* displayName;
@end

@interface IMeetingConfigOption : NSObject
/**
 * @brief Get the meeting topic.
 * @return The meeting topic. 
 */
-(NSString*)getMeetingTopic;
/**
 * @brief Query if the feature is enabled that the password is required when user joins meeting.
 * @return YES means enabled, otherwise not. 
 */
-(BOOL)enableRequiredPassword;
/**
 * @brief Get the meeting password.
 * @return The meeting password.
 */
-(NSString*)getMeetingPassword;
/**
 * @brief Query if the feature is enabled that user can join meeting before host.
 * @return YES means enabled, otherwise not.
 */
-(BOOL)enableJBH;
/**
 * @brief Query if the feature is enabled when user joins meeting with audio muted. 
 * @return YES means enabled, otherwise not. 
 */
-(BOOL)enableMuteOnEntry;
/**
 * @brief Query if the feature is enabled to use PMI to schedule meeting.
 * @return YES means enabled, otherwise not.
 */
-(BOOL)enableUsePMI;
/**
 * @brief Query if it is able to host a meeting in China.
 * @param canModify The pointer to BOOL. If the meeting supports to host a meeting in China, the value will be YES.
 * @return YES means that it is able to host a meeting in China, otherwise not.
 */
-(BOOL)enableHostInChina:(BOOL*)canModify;
/**
 * @brief Query if the feature is enabled that only signed user can join meeting.
 * @param canModify The pointer to Bool. YES means that the meeting supports ONLY SIGNED USER CAN JOIN meeting. 
 * @return YES means that ONLY SIGNED USER CAN JOIN meeting, otherwise not.
 */
-(BOOL)enableOnlySignedUserJoin:(BOOL*)canModify;
/**
 * @brief Query if the feature is enabled that only the user in specified domain can join meeting.
 * @param canModify The pointer to Bool. YES means that the meeting supports to allow users in special domain to join meeting.
 * @return YES means enabled the feature of only special domain user can join, otherwise not.
 */
-(BOOL)enableSpecialDomainUserJoin:(BOOL*)canModify;
/**
 * @brief Get the specified domains.
 * @return The specified domains.
 */
-(NSString*)getSpecialDomains;
/**
 * @brief Query if the feature is enabled to record meeting automatically.
 * @param supportRecordType The pointer to int. If the function calls successfully, the value of supportRecordType will be the sum of all the supported recording types.
 * @return YES means enabled the feature of auto-record, otherwise not.
 */
-(BOOL)enableAutoRecord:(int*)supportRecordType;
/**
 * @brief Get the recording type of meeting.
 * @return The recording type of meeting.
 */
-(ScheduleMeetingRecordType)getMeetingRecordType;
/**
 * @brief Get the array of the user for whom the meeting is scheduled.
 * @param canModify The pointer to Bool. YES means that the meeting supports to schedule meeting for others, otherwise not.
 * @return An NSArray of users for whom the meeting is scheduled.
 */
-(NSArray*)getScheduleForUser:(BOOL*)canModify;  
@end

@interface ScheduleMeetingConfigOption: IMeetingConfigOption
/**
 * @brief Set the meeting topic.
 * @param topic The topic of meeting.
 */
-(void)setMeetingTopic:(NSString*)topic;
/**
 * @brief Set if it is required to enable the password when user joins meeting.
 * @param require YES means required, otherwise not.
 */
-(void)setRequirePassword:(BOOL)require;
/**
 * @brief Set the meeting password.
 * @param password The password of meeting.
 */
-(void)setMeetingPassword:(NSString*)password;
/**
 * @brief Set whether to enable the feature that user joins meeting before host.
 * @param enable YES means enabled, otherwise not.
 */
-(void)setEnableJBH:(BOOL)enable;
/**
 * @brief Set whether to enable the feature that user joins meeting with audio muted.
 * @param enable YES means enabled, otherwise not.
 */
-(void)setEnableMuteOnEntry:(BOOL)enable;
/**
 * @brief Set if it is enabled to use PMI.
 * @param user YES means enabled, NO disabled.
 */
-(void)setUsePMI:(BOOL)use;
/**
 * @brief Set whether to enable host in China.
 * @param enable YES means enabled, NO disabled.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.   
 */
-(ZoomSDKError)setEnableHostInChina:(BOOL)enable;
/**
 * @brief Set whether to enable the feature ONLY SINGED USER CAN JOIN MEETING.
 * @param enable YES means enabled, NO disabled.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)setEnableOnlySignedUserJoin:(BOOL)enable;
/**
 * @brief Set whether to enable the feature ONLY USER IN SPECIAL DOMAIN CAN JOIN MEETING.
 * @param enable YES means enabled, NO disabled.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)setEnableSpecialDomainUserJoin:(BOOL)enable;
/**
 * @brief Set the specified domains.
 * @param domains Custom domains.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)selectSpecialDomains:(NSString*)domains;
/**
 * @brief Set whether to enable recording meeting automatically.
 * @param enable YES means enabled, NO disabled.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)setEnableAutoRecord:(BOOL)enable;
/**
 * @brief Set the type for recording.
 * @param type Recording types.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)setRecordType:(ScheduleMeetingRecordType)type;
/**
 * @brief Select a user for whom the meeting is scheduled for.
 * @param users The array of users.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)selectScheduleForUser:(NSArray*)users;
@end

@interface ZoomSDKScheduleMeetingItem : NSObject
{
    ScheduleMeetingDateOption* _dateOption;
    ScheduleMeetingAudioOption* _audioOption;
    ScheduleMeetingVideoOption* _videoOption;
    ScheduleMeetingConfigOption* _configOption;
}
@property(nonatomic, retain) ScheduleMeetingDateOption* dateOption;
@property(nonatomic, retain) ScheduleMeetingAudioOption* audioOption;
@property(nonatomic, retain) ScheduleMeetingVideoOption* videoOption;
@property(nonatomic, retain) ScheduleMeetingConfigOption* configOption;
@end

@interface ZoomSDKMeetingItem : NSObject
{
    IMeetingDateOption*  _dateOption;
    IMeetingAudioOption*  _audioOption;
    IMeetingVideoOption*  _videoOption;
    IMeetingConfigOption* _configOption;
    long long             _meetingUniqueID;
}
/**
 * @brief Get the object of IMeetingDateOption.
 * @return If the function succeeds, it will return the object of IMeetingDateOption.
 */
-(IMeetingDateOption*)getDateOption;
/**
 * @brief Get the object of IMeetingAudioOption.
 * @return If the function succeeds, it will return the object of IMeetingAudioOption.
 */
-(IMeetingAudioOption*)getAudioOption;
/**
 * @brief Get the object of IMeetingVideoOption.
 * @return If the function succeeds, it will return the object of IMeetingVideoOption.
 */
-(IMeetingVideoOption*)getVideoOption;
/**
 * @brief Get the the object of IMeetingConfigOption.
 * @return If the function succeeds, it will return the object of IMeetingConfigOption.
 */
-(IMeetingConfigOption*)getConfigOption;
/**
 * @brief Get the meeting unique ID.
 * @return If the function succeeds, it will return the meeting unique ID.
 */
-(long long)getMeetingUniqueID;
/**
 * @brief Get the content of the email to invite the users to join the meeting.
 * @return If the function succeeds, it will return the email contents.
 */
-(NSString*)getInviteEmailContent;
/**
 * @brief Get the URL to invite the users to join the meeting.
 * @return If the function succeeds, it will return the join meeting URL.
 */
-(NSString*)getJoinMeetingUrl;

/**
 * @brief Get the meeting number.
 * @return If the function succeeds, it will return the meeting number.
 */
-(long long)getMeetingNumber;

@end

@protocol ZoomSDKPremeetingServiceDelegate;
@interface ZoomSDKPremeetingService : NSObject
{
    id<ZoomSDKPremeetingServiceDelegate> _delegate;
    ZoomSDKOutlookPluginHelper* _outlookPluginHelper;
    ZoomSDKDirectShareHelper* _directShareHelper;
}

/**
 * It provides support for premeeting event once logged in with working email or with SSO.
 */
@property (assign, nonatomic) id<ZoomSDKPremeetingServiceDelegate> delegate;
 /**
 * @brief Create an object of ZoomSDKScheduleMeetingItem.
 * @return If the function succeeds, it will return the object of ZoomSDKScheduleMeetingItem. 
 */
- (ZoomSDKScheduleMeetingItem*)createScheduleMeetingItem;

/**
 * @brief Create an object of ZoomSDKScheduleMeetingItem for edit meeting.
 * @param meetingUniqueID The unique ID of meeting to be edited.
 * @return If the function succeeds, it will return the object of ZoomSDKScheduleMeetingItem.
 */
- (ZoomSDKScheduleMeetingItem*)createEditMeetingItemWithMeetingID:(long long)meetingUniqueID;

 /**
 * @brief Destroy the object of ZoomSDKScheduleMeetingItem.
 * @param meetingItem The object of ZoomSDKScheduleMeetingItem that you created by Api of createScheduleMeetingItem.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)destoryScheduleMeetingItem:(ZoomSDKScheduleMeetingItem*)meetingItem;
/**
 * @brief Schedule a ZOOM meeting with the items you created.
 * @param meetingItem The object of ZoomSDKScheduleMeetingItem that you created by Api of createScheduleMeetingItem.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)scheduleMeeting:(ZoomSDKScheduleMeetingItem*)meetingItem;

/**
 * @brief Edit the specified meeting.
 * @param meetingItem The object of ZoomSDKScheduleMeetingItem that you created by Api of createEditMeetingItemWithMeetingID.
 * @param meetingUniqueID The unique ID of meeting to be edited.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)editMeeting:(ZoomSDKScheduleMeetingItem*)meetingItem MeetingUniqueID:(long long)meetingUniqueID;

/**
 * @brief Delete the specified meeting. 
 * @param meetingUniqueID The specified meeting unique ID.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)deleteMeeting:(long long)meetingUniqueID;

/**
 * @brief List all meetings.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
- (ZoomSDKError)listMeeting;

/**
 * @brief Get meeting item information of the specified meeting.
 * @param meetingUniqueID The unique ID of the specified meeting. 
 * @return If the function succeeds, it will return a ZoomSDKMeetingItem object. Otherwise failed. 
 */
- (ZoomSDKMeetingItem*)getMeetingItem:(long long)meetingUniqueID;

/**
 * @brief Display the Zoom native window of schedule or edit meeting.
 * @note  Webinar or meeting using PMI are not supported.
 * @param show One(1) means display the window, zero(0) not.  
 * @param window If the function succeeds, it will return a window object to schedule/edit meeting.
 * @param meetingUniqueID The ID of the specified meeting to be edited. 
 * @return If the function succeeds, it will return a ZoomSDKError_Success. Otherwise failed.
 */
- (ZoomSDKError)showScheduleEditMeetingWindow:(BOOL)show Window:(NSWindow**)window MeetingID:(long long)meetingUniqueID;

/**
 * @brief Get Outlook plugin integration helper object.
 * @return If the function succeeds, it will return a ZoomSDKOutlookPluginHelper object. Otherwise failed.  
 */
- (ZoomSDKOutlookPluginHelper*)getOutlookPluginHelper;

/**
 * @brief Turn on the video of participant when he joins the meeting. 
 * @param enable YES means enabled, otherwise not.
 */
- (void)enableForceAutoStartMyVideoWhenJoinMeeting:(BOOL)enable;

/**
 * @brief Turn off the video of participant when he joins the meeting.
 * @param enable YES means enabled, otherwise not.
 */
- (void)enableForceAutoStopMyVideoWhenJoinMeeting:(BOOL)enable;

/**
 * @brief Set the visibility of the dialog SELECT JOIN AUDIO when joining meeting. Default: enabled.
 * @param disable YES means disabled, otherwise not.
 */
- (void)disableAutoShowSelectJoinAudioDlgWhenJoinMeeting:(BOOL)disable;

/**
 * @brief Query if the current user is forced to enable video when joining the meeting.
 * @return YES means to force the current user to enable video, otherwise not. 
 */
- (BOOL)isUserForceStartMyVideoWhenInMeeting;

/**
 * @brief Query if the current user is forced to turn off video when joining the meeting.
 * @return YES means that the current user's video is forced to stop, otherwise not. 
 */
- (BOOL)isUserForceStopMyVideoWhenInMeeting;

/**
 * @brief Query if the feature that hide the dialog of joining meeting with audio in the meeting is enabled.
 * @return YES means hiding the dialog, otherwise not.
 */
- (BOOL)isUserForceDisableShowJoinAudioDlgWhenInMeeting;

/**
 * @brief Get the helper to share directly.
 * @return If the function succeeds, it will return a ZoomSDKDirectShareHelper object.
 */
- (ZoomSDKDirectShareHelper*)getDirectShareHelper;

/**
 * @brief Hide schedule window components.
 * @param component An enumeration of components for schedule window.
 * @param hide YES means to hide, NO to show.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
- (void)hideScheduleComponent:(ScheduleComponent)component hide:(BOOL)hide;
@end


@protocol ZoomSDKPremeetingServiceDelegate <NSObject>

@optional
/**
 * @brief Callback event of listing meeting.
 * @param error Tell the result of listing meeting. If the function succeeds, it will return ZoomSDKPremeetingError_Success. Otherwise failed, returns errors.
 * @param meetingList The list of the scheduled upcoming meetings.
 *
 */
- (void)onListMeeting:(ZoomSDKPremeetingError)error MeetingList:(NSArray*)meetingList;

/**
 * @brief Notification of scheduling or editing a meeting.
 * @param error Tell the result of scheduling/editing a meeting. If the function succeeds, it will return ZoomSDKPremeetingError_Success. Otherwise failed, returns errors.
 * @param meetingUniqueID The unique ID of the specified meeting to be scheduled or edited.
 *
 */
- (void)onScheduleOrEditMeeting:(ZoomSDKPremeetingError)error MeetingUniqueID:(long long)meetingUniqueID;

/**
 * @brief Notification of deleting a meeting. 
 * @param error Tell the result of deleting the meeting. If the function succeeds, it will return ZoomSDKPremeetingError_Success. Otherwise failed, returns errors.
 *
 */
- (void)onDeleteMeeting:(ZoomSDKPremeetingError)error;
@end
