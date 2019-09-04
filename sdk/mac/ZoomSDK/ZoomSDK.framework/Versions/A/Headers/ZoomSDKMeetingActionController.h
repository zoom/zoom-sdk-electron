//
//  ZoomSDKMeetingActionController.h
//  ZoomSDK
//
//  Created by TOTTI on 9/1/17.
//  Copyright © 2017 Zoom Video Communications,Inc. All rights reserved.
//
#import "ZoomSDKErrors.h"

@interface ZoomSDKMultiToSingleShareConfirmHandler : NSObject
/**
 * @brief Cancel to switch to single share from multi-share. All the shares are remained.
 * @return If the function succeeds, it will return ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)cancelSwitch;
/**
 * @brief Confirm to switch to single share from multi-share. All the shares are stopped.
 * @return If the function succeeds, it will return ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)confirmSwitch;
@end

/**
 * @brief ZOOM SDK chat information.
 */
@interface ZoomSDKChatInfo : NSObject
{
    unsigned int _sendID;
    unsigned int _receiverID;
    NSString*    _sendName;
    NSString*    _receiverName;
    NSString*    _content;
    time_t       _timestamp;
}
/**
 * @brief Get the user ID of whom sending message.
 * @return If the function succeeds, the return value is the user ID of sender.
 */
- (unsigned int)getSenderUserID;
/**
 * @brief Get the screen name of the sender.
 * @return If the function succeeds, the return value is the screen name.
 */
- (NSString*)getSenderDisplayName;
/**
 * @brief Get the user ID of whom receiving the message.
 * @return If the function succeeds, the return value is the user ID.
 */
- (unsigned int)getReceiverUserID;
/**
 * @brief Get the screen name of receiver.
 * @return If the function succeeds, the return value is the screen name.
 */
- (NSString*)getReceiverDisplayName;
/**
 * @brief Get the content of message.
 * @return If the function succeeds, the return value is the content of message.
 */
- (NSString*)getMsgContent;
/**
 * @brief Get the timestamps of the current message.
 * @return If the function succeeds, the return value is the timestamps of the current message. 
 */
- (time_t)getTimeStamp;
@end
/**
 * @brief ZOOM SDK audio information.
 */
@interface ZoomSDKUserAudioStauts : NSObject
{
    unsigned int _userID;
    ZoomSDKAudioStatus _status;
    ZoomSDKAudioType _type;
}
/**
 * @brief Get the user ID.
 * @return If the function succeeds, it will return user ID.
 */
- (unsigned int)getUserID;
/**
 * @brief Get the status of the audio.
 * @return The audio status.
 */
- (ZoomSDKAudioStatus)getStatus;
/**
 * @brief Get the audio type of the user.
 * @return The audio type.
 */
- (ZoomSDKAudioType)getType;
@end
/**
 * @brief ZOOM SDK Attendee's status in the webinar.
 */
@interface ZoomSDKWebinarAttendeeStatus : NSObject
{
    BOOL _isAttendeeCanTalk;
}
@property(nonatomic, assign)BOOL  isAttendeeCanTalk;
@end
/**
 * @brief ZOOM SDK user information.
 */
@interface ZoomSDKUserInfo :NSObject
{
    unsigned int _userID;
}
/**
 * @brief Determine if the information corresponds to the current user.
 * @return YES means that the information corresponds to the current user, otherwise not.
 */
- (BOOL)isMySelf;
/**
 * @brief Get the username matched with the current user information.
 * @return The username.
 */
- (NSString*)getUserName;
/**
 * @brief Get the email matched with the current user information.
 * @return The email.
 */
- (NSString*)getEmail;
/**
 * @brief Get the user ID matched with the current user information.
 * @return The user ID. 
 */
- (unsigned int)getUserID;
/**
 * @brief Determine whether the member corresponding with the current information is the host or not.
 * @return YES means host.
 */
- (BOOL)isHost;
/**
 * @brief Determine the video status of the user specified by the current information.
 * @return YES means that the video is turned on.
 */
- (BOOL)isVideoOn;
/**
 * @brief Determine the audio status of the user specified by the current information.
 * @return YES means that the audio status is muted.
 */
- (BOOL)isAudioMuted;
/**
 * @brief Get the type of role of the user specified by the current information.
 * @return The role of the user.
 */
- (UserRole)getUserRole;
/**
 * @brief Determine whether the user corresponding to the current information joins the meeting by telephone or not.
 * @return YES indicates that the user joins the meeting by telephone.
 */
- (BOOL)isPurePhoneUser;
/**
 * @brief Determine if it is able to change the specified user role as the co-host.
 * @return If the specified user can be the co-host, the return value is YES. Otherwise failed.
 */
- (BOOL)canBeCoHost;
/**
 * @brief Get the webinar status of the user specified by the current information.
 * @return The object of ZoomSDKWebinarAttendeeStatus.
 */
- (ZoomSDKWebinarAttendeeStatus*)GetWebinarAttendeeStatus;
@end
/**
 * @brief Join meeting helper.
 */
@interface ZoomSDKJoinMeetingHelper :NSObject
{
    JoinMeetingReqInfoType   _reqInfoType;
}
/**
 * @brief Get the type of register information.
 * @return The type of the information.
 */
-(JoinMeetingReqInfoType)getReqInfoType;
/**
 * @brief Input the password to join meeting.
 * @param password The meeting password of the meeting.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
-(ZoomSDKError)inputPassword:(NSString*)password;
/**
 * @brief Cancel to join meeting.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.										
 */
-(ZoomSDKError)cancel;
@end


@protocol ZoomSDKMeetingActionControllerDelegate <NSObject>

/**
 * @brief Notification of user's audio status changes. 
 * @param userAudioStatusArray An array contains ZoomSDKUserAudioStauts elements of each user's audio status.
 *
 */
- (void)onUserAudioStatusChange:(NSArray*)userAudioStatusArray;

/**
 * @brief In-meeting users receive the notification of chat messages.
 * @param chatInfo Chat information received by user.
 *
 */
- (void)onChatMessageNotification:(ZoomSDKChatInfo*)chatInfo;

/**
 * @brief Notification of user joins meeting.
 * @param array Array of users who join meeting. 
 *
 */
- (void)onUserJoin:(NSArray*)array;

/**
 * @brief Notification of user leaves meeting.
 * @param array Array of users leave meeting. 
 *
 */
- (void)onUserLeft:(NSArray*)array;

/**
 * @brief Upgrade the information of the specified user.
 * @param userID The ID of the specified user.
 *
 */
- (void)onUserInfoUpdate:(unsigned int)userID;

/**
 * @brief Notification of host changes.
 * @param userID User ID of new host.
 *
 */
- (void)onHostChange:(unsigned int)userID;

/**
 * @brief Notification of co-host changes. 
 * @param userID User ID of new co-host.
 *
 */
- (void)onCoHostChange:(unsigned int)userID;

/**
 * @brief Notification of user whose video is spotlighted changes.
 * @param spotlight YES means spotlighted, otherwise not.
 * @param userID The ID of user whose video is currently spotlighted.
 *
 */
- (void)onSpotlightVideoUserChange:(BOOL)spotlight User:(unsigned int)userID;

/**
 * @brief Notify that user's video status changes.
 * @param videoOn YES means that user's video is on, otherwise not.
 * @param userID The ID of user who video status changes.
 *
 */
- (void)onVideoStatusChange:(BOOL)videoOn UserID:(unsigned int)userID;

/**
 * @brief Notification of user's hand status changes.
 * @param raise YES means that the specified user raises hand, otherwise, puts hand down.  
 * @param userID The ID of user whose hand status changes.
 *
 */
- (void)onLowOrRaiseHandStatusChange:(BOOL)raise UserID:(unsigned int)userID;

/**
 * @brief Callback event of user joins meeting. 
 * @param joinMeetingHelper An object for inputing password or canceling to join meeting.
 */
- (void)onJoinMeetingResponse:(ZoomSDKJoinMeetingHelper*)joinMeetingHelper;

/**
 * @brief Notification of in-meeting active speaker changes.
 * @param userID The ID of new active speaker.
 */
- (void)onActiveSpeakerChanged:(unsigned int)userID;

/**
 * @brief Notify user to confirm or cancel to switch to single share from multi-share.
 * @param confirmHandle An object used to handle the action to switch to single share from multi-share.
 */
- (void)onMultiToSingleShareNeedConfirm:(ZoomSDKMultiToSingleShareConfirmHandler*)confirmHandle;
/**
 * @brief Notify that video of active user changes.
 * @param userID The user's user ID.						  
 */
- (void)onActiveVideoUserChanged:(unsigned int)userID;
/**
 * @brief Notify that video of active speaker changes.
 * @param userID The user's user ID.
 */
- (void)onActiveSpeakerVideoUserChanged:(unsigned int)userID;
/**
 * @brief Notify that host ask you to unmute yourself.
 */
- (void)onHostAskUnmute;

@end

@interface ZoomSDKMeetingActionController : NSObject
{
    id<ZoomSDKMeetingActionControllerDelegate> _delegate;
    NSMutableArray*             _participantsArray;
}
@property(nonatomic, assign) id<ZoomSDKMeetingActionControllerDelegate> delegate;

/**
 * @brief Get the list of participants.
 * @return An array of participant ID.
 */
- (NSArray*)getParticipantsList;
/**
 * @brief Commands in the meeting.
 * @param cmd The commands in the meeting. 
 * @param userID The ID of user. Zero(0) means that the current user can control the commands. If it is other participant, it will return the corresponding user ID.
 * @param screen Specify the screen on which you want to do action.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)actionMeetingWithCmd:(ActionMeetingCmd)cmd userID:(unsigned int)userID onScreen:(ScreenType)screen;

/**
 * @brief Send a chat message.
 * @param content The content of message.
 * @param userID The ID of user who will receive the message. 
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)sendChat:(NSString*)content toUser:(unsigned int)userID;

/**
 * @brief Get the information of the specified user. 
 * @param userID The ID of the specified user. 
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKUserInfo*)getUserByUserID:(unsigned int)userID;

/**
 * @brief Change user's screen name in the meeting.
 * @param userID The ID of user whose screen name will be changed. Normal participants can change only their personal screen name while the host/co-host can change all participants' names. 
 * @param name The new screen name. 
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)changeUserName:(unsigned int)userID newName:(NSString*)name;

/**
 * @brief Assign a participant to be a new host, or original host who loose the privilege reclaims to be the host.
 * @param userID User ID of new host. Zero(0) means that the original host takes back the privilege.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)makeHost:(unsigned int)userID;

/**
 * @brief Make the specified user to raise hand or lower hand.
 * @param raise YES means to raise hand, NO means lower hand for this specified user.
 * @param userid User ID of the user to be modified.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)raiseHand:(BOOL)raise UserID:(unsigned int)userid;

/**
 * @brief Remove the specified user from meeting.
 * @param userid User ID of the user to be modified.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)expelUser:(unsigned int)userid;

/**
 * @brief Start or stop the cloud recording.
 * @param start YES means to start, NO means stop.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)startCMR:(BOOL)start;

/**
 * @brief Get the meeting UI display type.
 * @param type Select the screen where you want to operate on.
 * @param bFullScreen A point to A BOOL, if the function call successfully, the value of 'bFullScreen' means whether the specified screen is in full screen mode.
  * @param meetingUIType A point to A MeetingUIType, if the function call successfully, the value of 'meetingUIType' means the meeting UI display type.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)getMeetingUIType:(ScreenType)type isFullScreen:(BOOL*)bFullScreen meetingUIType:(MeetingUIType*)meetingUIType;

/**
 * @brief Allow or disallow the specified user to local recording.
 * @param allow YES means allow, NO means disallow.
 * @param userid User ID of the user to be modified.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)allowLocalRecord:(BOOL)allow UserID:(unsigned int)userid;

/**
 * @brief Query if user can claim host(be host) or not. 
 * @return YES means able, otherwise not.
 */
- (BOOL)canReclaimHost;
/**
 * @brief Normal participant claims host by host-key.
 * @param hostKey Host key.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)claimHostByKey:(NSString*)hostKey;
/**
 * @brief Assign a user as co-host in meeting. 
 * @param userid The ID of user to be a co-host. 
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 * @note The co-host cannot be assigned as co-host by himself. And the user should have the power to assign the role.
 */
-(ZoomSDKError)assignCoHost:(unsigned int)userid;

/**
 * @brief Revoke co-host role of another user in meeting.
 * @param userid The ID of co-host who will loose the co-host privilege. 
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 * @note Only meeting host can run the function.
 */
-(ZoomSDKError)revokeCoHost:(unsigned int)userid;

/**
 * @brief Set sharing types for the host or co-host in meeting.
 * @param ZoomSDKShareSettingType Custom setting types of ZOOM SDK sharing.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
-(ZoomSDKError)setShareSettingType:(ZoomSDKShareSettingType)shareType;

/**
 * @brief Get the sharing types for the host or co-host in meeting.
 * @param ZoomSDKShareSettingType Custom setting types of ZOOM SDK sharing.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 */
- (ZoomSDKError)getShareSettingType:(ZoomSDKShareSettingType*)type;

/**
 * @brief Determine if user's original sound is enabled.
 * @return YES means enabled, otherwise not.
 */
- (BOOL)isUseOriginalSoundOn;

/**
 * @brief Set to output original sound of mic in meeting.
 * @param enable YES means using original sound, No disabling.
 * @return If the function succeeds, it will return ZoomSDKError_success, otherwise failed.
 */
- (ZoomSDKError)enableUseOriginalSound:(BOOL)enable;

/**
 * @brief Determine if the meeting supports user's original sound.
 * @return YES means supported, otherwise not.
 */
- (BOOL)isSupportUseOriginalSound;

/**
 * @brief Swap to show sharing screen or video.
 * @param share YES means swap to sharing screen, NO means swap to video.
 * @return  If the function succeeds, it will return ZoomSDKError_success, otherwise not.
 * @note Only available for Zoom native ui mode.
 */
- (ZoomSDKError)swapToShowShareViewOrVideo:(BOOL)share;

/**
 * @brief Determine if the user can swap to show sharing screen or video now.
 * @return YES means can, otherwise not.
 */
- (BOOL)canSwapToShowShareViewOrVideo;

/**
 * @brief Determine if the meeting is displaying the sharing screen now.
 * @return YES means is showing sharing screen, NO means is showing video.
 */
- (BOOL)isDisplayingShareViewOrVideo;
@end
