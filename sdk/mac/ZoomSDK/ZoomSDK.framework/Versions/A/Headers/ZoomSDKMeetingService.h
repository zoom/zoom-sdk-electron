//
//  ZoomSDKMeetingService.h
//  ZoomSDK
//
//  Created by TOTTI on 7/18/16.
//  Copyright (c) 2016 Zoom Video Communications,Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"
#import "ZoomSDKH323Helper.h"
#import "ZoomSDKPhoneHelper.h"
#import "ZoomSDKWaitingRoomController.h"
#import "ZoomSDKMeetingUIController.h"
#import "ZoomSDKBreakoutRoomsController.h"
#import "ZoomSDKMeetingConfiguration.h"
#import "ZoomSDKASController.h"
#import "ZoomSDKMeetingActionController.h"
#import "ZoomSDKLiveStreamHelper.h"
#import "ZoomSDKVideoContainer.h"
#import "ZoomSDKMeetingRecordController.h"
#import "ZoomSDKUpgradeAccountHelper.h"
#import "ZoomSDKWebinarController.h"
#import "ZoomSDKCloseCaptionController.h"
#import "ZoomSDKRawDataController.h"
#import "ZoomSDKRealNameAuthenticationController.h"
#import "ZoomSDKQAController.h"
@interface ZoomSDKSecuritySessionKey : NSObject
{
    SecuritySessionComponet _component;
    NSData*                 _sessionKey;
    NSData*                 _iv;
}
@property(nonatomic, assign) SecuritySessionComponet component;
@property(nonatomic, retain) NSData* iv;
@property(nonatomic, retain) NSData* sessionKey;

@end

@protocol ZoomSDKMeetingServiceDelegate <NSObject>

@optional

/**
 * @brief Notify if ZOOM meeting status Changes.
 * @param state The status of ZOOM meeting.
 * @param error The enum of ZoomSDKMeetingError.
 * @param reason The enum of EndMeetingReason.
 */
- (void)onMeetingStatusChange:(ZoomSDKMeetingStatus)state meetingError:(ZoomSDKMeetingError)error EndReason:(EndMeetingReason)reason;

/**
 * @brief Notify that meeting needs external session key.
 * @param key The external session key
 */
- (void)onWaitMeetingSessionKey:(NSData*)key;

/**
 * @brief Notification of statistic warnings of Zoom Meeting.
 * @param type The statistic type.
 */
- (void)onMeetingStatisticWarning:(StatisticWarningType)type;

/**
 * @brief Inform user to upgrade the account. 
 * @param upgradeHelper The object of ZoomSDKUpgradeAccountHelper.
 */
- (void)onPaymentReminder:(ZoomSDKUpgradeAccountHelper*)upgradeHelper NS_DEPRECATED_MAC(4.0, 4.3);

/**
 * @brief Designated for notify the free meeting need upgrade.
 * @param type The enumeration of FreeMeetingNeedUpgradeType, if the type is FreeMeetingNeedUpgradeType_BY_GIFTURL, user can upgrade free meeting through url. if the type is FreeMeetingNeedUpgradeType_BY_ADMIN, user can ask admin user to upgrade the meeting.
 * @param giftURL User can upgrade the free meeting through the url.
 */
- (void)onFreeMeetingNeedToUpgrade:(FreeMeetingNeedUpgradeType)type giftUpgradeURL:(NSString*)giftURL;

/**
 * @brief Designated for notify the free meeting which has been upgraded to free trail meeting has started.
 */
- (void)onFreeMeetingUpgradeToGiftFreeTrialStart;

/**
 * @brief Designated for notify the free meeting which has been upgraded to free trail meeting has stoped.
 */
- (void)onFreeMeetingUpgradeToGiftFreeTrialStop;

/**
 * @brief Designated for notify the free meeting has been upgraded to professional meeting.
 */
- (void)onFreeMeetingUpgradedToProMeeting;

/**
 * @brief Designated for notify the free meeting remain time has been stoped to count down.
 */
- (void)onFreeMeetingRemainTimeStopCountDown;

/**
 * @brief Inform user the remaining time of free meeting.
 * @param seconds The remaining time of the free meeting.
 */
- (void)onFreeMeetingRemainTime:(unsigned int)seconds;
@end

/**
 * @brief It is an implementation for client to start/join a Meeting.
 * @note The meeting service allows only one concurrent operation at a time, which means, only one API call is in progress at any given time.		 
 */
@interface ZoomSDKMeetingService : NSObject
{
    id<ZoomSDKMeetingServiceDelegate> _delegate;
    ZoomSDKMeetingUIController* _meetingUIController;
    ZoomSDKMeetingConfiguration* _meetingConfiguration;
    ZoomSDKBreakoutRoomsController*  _boController;
    ZoomSDKH323Helper*           _h323Helper;
    ZoomSDKWaitingRoomController* _waitingRoomController;
    ZoomSDKPhoneHelper*           _phoneHelper;
    ZoomSDKASController*          _asController;
    ZoomSDKMeetingActionController*  _actionController;
    ZoomSDKLiveStreamHelper*         _liveStreamHelper;
    //customized UI
    ZoomSDKVideoContainer*           _videoContainer;
    ZoomSDKMeetingRecordController*  _recordController;
    ZoomSDKWebinarController*        _webinarController;
    ZoomSDKCloseCaptionController*   _closeCaptionController;
    ZoomSDKRawDataController*        _rawDataController;
    ZoomSDKRealNameAuthenticationController*       _realNameController;
    ZoomSDKQAController*             _QAController;
    
}
/**
 * Callback of receiving meeting events.
 */
@property (assign, nonatomic) id<ZoomSDKMeetingServiceDelegate> delegate;

/**
 * @brief Get the meeting UI controller interface.
 * @return If the function succeeds, the return value is an object of ZoomSDKMeetingUIController. Otherwise returns nil.
 */
- (ZoomSDKMeetingUIController*)getMeetingUIController;

/**
 * @brief Get the configuration of the meeting.
 * @return If the function succeeds, the return value is an object of ZoomSDKMeetingConfiguration. Otherwise returns nil.
 */
- (ZoomSDKMeetingConfiguration*)getMeetingConfiguration;

/**
 * @brief Get the default H.323 helper of ZOOM meeting service. 
 * @return If the function succeeds, the return value is a ZoomSDKH323Helper object of H.323 Helper. 
 */
- (ZoomSDKH323Helper*)getH323Helper;

/**
 * @brief Get the default Breakout Rooms Helper of ZOOM meeting service.
 * @return If the function succeeds, the return value is an object of ZoomSDKBreakoutRoomsController. Otherwise returns nil. 
 */
- (ZoomSDKBreakoutRoomsController*)getBreakoutRoomsController;

/**
 * @brief Get default Waiting Room Controller of ZOOM meeting service.
 * @return If the function succeeds, the return value is an object of ZoomSDKWaitingRoomController. Otherwise returns nil. 
 */
- (ZoomSDKWaitingRoomController*)getWaitingRoomController;

/**
 * @brief Get the default AS(APP share) Controller of ZOOM meeting service.
 * @return If the function succeeds, the return value is an object of ZoomSDKASController. Otherwise returns nil.  
 */
- (ZoomSDKASController*)getASController;

/**
 * @brief Get the  default Phone Callout Helper of Zoom meeting service.
 * @return If the function succeeds, the return value is an object of ZoomSDKPhoneHelper. Otherwise returns nil. 
 */
- (ZoomSDKPhoneHelper*)getPhoneHelper;

/**
 * @brief Get the default action controller(mute audio/video etc) of ZOOM meeting service.
 * @return If the function succeeds, the return value is an object of ZoomSDKMeetingActionController. Otherwise returns nil. 
 */
- (ZoomSDKMeetingActionController*)getMeetingActionController;

/**
 * @brief Get the default live stream helper of ZOOM meeting service.
 * @return If the function succeeds, the return value is an object of ZoomSDKLiveStreamHelper. Otherwise returns nil. 
 */
- (ZoomSDKLiveStreamHelper*)getLiveStreamHelper;

/**
 * @brief Get the custom video container of ZOOM SDK.
 * @return If the function succeeds, the return value is an object of ZoomSDKVideoContainer which allows user to customize in-meeting UI. Otherwise returns nil. 
 */
- (ZoomSDKVideoContainer*)getVideoContainer;

/**
 * @brief Get the custom recording object of ZOOM SDK.
 * @return If the function succeeds, the return value is an object of ZoomSDKMeetingRecordController which allows user to customize meeting recording. Otherwise returns nil. 
 */
- (ZoomSDKMeetingRecordController*)getRecordController;
/**
 * @brief Get the custom webinar controller.
 * @return If the function succeeds, the return value is an object of ZoomSDKWebinarController which allows you to customize webinar. Otherwise returns nil. 
 */
- (ZoomSDKWebinarController*)getWebinarController;

/**
 * @brief Get controller of close caption in Zoom meeting.
 * @return If the function succeeds, it will return a ZoomSDKCloseCaptionController object which you can use to handle close caption in meeting.
 */
- (ZoomSDKCloseCaptionController*)getCloseCaptionController;

/**
 * @brief Get object of controller ZoomSDKRawDataController.
 * @return If the function succeeds, it will return a ZoomSDKRawDataController object which you can use to handle raw data in meeting.
 */
- (ZoomSDKRawDataController*)getRawDataController;

/**
 * @brief Get object of controller ZoomSDKRealNameAuthenticationController.
 * @return If the function succeeds, it will return a ZoomSDKRealNameAuthenticationController object which you can use to Real-name authentication.
 */
-(ZoomSDKRealNameAuthenticationController *)getRealNameController;

/**
 * @brief Get object of ZoomSDKQAController.
 * @return If the function succeeds, it will return a ZoomSDKQAController object.
 */
-(ZoomSDKQAController *)getQAController;
/**
 * @brief Start a ZOOM meeting with meeting number.
 * @note userId\userToken\username is for API user.
 * @param userType It depends on the type of client account.
 * @param userId The userId generates from ZOOM site of user account. 
 * @param userToken The userToken generates from ZOOM site of user account. 
 * @param username User's screen name displayed in the meeting.
 * @param meetingNumber It may be the number of a scheduled meeting or a Personal Meeting ID. Set it to nil to start an instant meeting.  
 * @param directShare Set it to YES to start sharing computer desktop directly when meeting starts.
 * @param displayID The APP to be shared.
 * @param noVideo Set it to YES to turn off the video when user joins meeting. 
 * @param noAuido Set it to YES to turn off the audio when user joins meeting. 
 * @param sdkVanityID Set meetingNumber to nil if you want to start a meeting with vanityID. 
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
- (ZoomSDKError)startMeeting:(ZoomSDKUserType)userType userID:(NSString*)userId userToken:(NSString*)userToken displayName:(NSString*)username meetingNumber:(NSString*)meetingNumber isDirectShare:(BOOL)directShare sharedApp:(CGDirectDisplayID)displayID isVideoOff:(BOOL)noVideo isAuidoOff:(BOOL)noAuido vanityID:(NSString*)sdkVanityID;

/**
 * @brief Start a ZOOM meeting with ZAK.
 * @note It is just for non-logged-in user. 
 * @param ZAK Security session key got from web.
 * @param type User type.
 * @param userId The ID of user got from ZOOM website.
 * @param username User's screen name displayed in the meeting.
 * @param meetingNumber It may be the number of a scheduled meeting or a Personal Meeting ID. Set it to nil to start an instant meeting.  
 * @param directShare Set it to YES to start sharing computer desktop directly when meeting starts.
 * @param displayID The APP to be shared.
 * @param noVideo Set it to YES to turn off the video when user joins meeting. 
 * @param noAuido Set it to YES to turn off the audio when user joins meeting. 
 * @param sdkVanityID Set meetingNumber to nil if you want to start a meeting with vanityID. 
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed. 
 */
- (ZoomSDKError)startMeetingWithZAK:(NSString*)zak userType:(SDKUserType)type userID:(NSString*)userId userToken:(NSString*)userToken displayName:(NSString*)username meetingNumber:(NSString*)meetingNumber isDirectShare:(BOOL)directShare sharedApp:(CGDirectDisplayID)displayID isVideoOff:(BOOL)noVideo isAuidoOff:(BOOL)noAuido vanityID:(NSString*)sdkVanityID;
/**
 * @brief Join a Zoom meeting.
 * @note toke4enfrocelogin/participantId is for API user.
 * @param userType It depends on the type of client account.
 * @param toke4enfrocelogin Set the parameter if user joins a meeting that requires to login.
 * @param webinarToken It is indispensable for a panelist when user joins a webinar.
 * @param participantId Participant ID displayed in web report.
 * @param meetingNumber The number of meeting that you want to join.
 * @param username User's screen name displayed in the meeting.
 * @param pwd Meeting password. Set it to nil or @"" to remove the password.
 * @param directShare Set it to YES to start sharing computer desktop directly when meeting starts.
 * @param displayID The APP to be shared.
 * @param noVideo Set it to YES to turn off the video when user joins meeting. 
 * @param noAuido Set it to YES to turn off the audio when user joins meeting. 
 * @param sdkVanityID Personal meeting URL, set meetingNumber to nil if you want to start meeting with vanityID.
 * @return If the function succeeds, it will return ZoomSDKError_Success. 
 */
- (ZoomSDKError)joinMeeting:(ZoomSDKUserType)userType toke4enfrocelogin:(NSString*)toke4enfrocelogin webinarToken:(NSString*)webinarToken participantId:(NSString*)participantId meetingNumber:(NSString*)meetingNumber displayName:(NSString*)username password:(NSString*)pwd isDirectShare:(BOOL)directShare sharedApp:(CGDirectDisplayID)displayID isVideoOff:(BOOL)noVideo isAuidoOff:(BOOL)noAuido  vanityID:(NSString*)sdkVanityID;

/**
 * @brief End/Leave the current meeting.
 * @param cmd The command for leaving the current meeting. Only host can end the meeting.
 */
- (void)leaveMeetingWithCmd:(LeaveMeetingCmd)cmd;

/**
 * @brief Get the status of meeting.
 * @return The status of meeting. 
 */
- (ZoomSDKMeetingStatus)getMeetingStatus;

/**
 * @brief Get the property of meeting.
 * @param command Commands for user to get different properties.
 * @return If the function succeeds, it will return an NSString of meeting property, otherwise failed.
 */
- (NSString*)getMeetingProperty:(MeetingPropertyCmd)command;

/**
 * @brief Get the network quality of meeting connection.
 * @param component Video/audio/share.
 * @param sending Set it to YES to get the status of sending data, NO to get the status of receiving data.
 * @return If the function succeeds, it will return an enumeration of network connection quality, otherwise failed.
 */
- (ZoomSDKConnectionQuality)getConnectionQuality:(ConnectionComponent)component Sending:(BOOL)sending;
/**
 * @brief Get the type of current meeting.
 * @return If the function succeeds, it will return the type of meeting, otherwise failed.
 */
- (MeetingType)getMeetingType;

/**
 * @brief Determine whether the current meeting is internal or not. Available only for Huawei.
 * @return YES means the current meeting is internal, otherwise not. 
 */

-(BOOL)isInternalMeeting;

/**
 * @brief Determine whether the meeting is failover or not. Available only for Huawei.
 * @return YES means the current meeting is failover, otherwise not. 
 */

-(BOOL)isFailoverMeeting;

/**
 * @brief This method is used to set security session key and iv for audio/video etc. Available only for Huawei.
 * @param keyArray An array of session security key. 
 * @param leaveMeeting Notification of user leaving meeting. 
 * @return The result of setting security key, successfully or not.
 */
-(ZoomSDKError)setSecuritySessionKey:(NSArray*)keyArray isLeaveMeeting:(BOOL)leaveMeeting;

/**
 * @brief Handle the event that user joins meeting from web or meeting URL.
 * @param urlAction The URL string got from web.
 * @return If the function succeeds, it will return ZoomSDKError_Succuss, otherwise failed.
 */
- (ZoomSDKError)handleZoomWebUrlAction:(NSString*)urlAction;
@end





