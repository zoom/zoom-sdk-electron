
#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

NS_ASSUME_NONNULL_BEGIN
@interface ZoomSDKBOMeetingInfo : NSObject

/**
 *@brief Get breakout meeting id.
 *@return The breakout meeting id.
 */
-(NSString *)getBOID;

/**
 *@brief Get breakout meeting nmae.
 *@return The breakout meeting name.
 */
-(NSString *)getBOName;

/**
 *@brief Get breakout meeting user list.
 *@return If the function succeeds,will get the breakout meeting user list.
 */
-(NSArray *)getBOUserlist;
@end


@interface ZoomSDKBOMeetingCreator : NSObject

/**
 *@brief Creator breakout meeting.
 *@param name Breakout meeting name.
 *@return If the function succeeds,will return breakout meeting id, otherwise return nil,
 */
-(NSString *)createBOWithBOName:(NSString*)name;

/**
 *@brief Update breakout meeting information.
 *@param newName Breakout meeting new name.
 *@param ID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)updateBOName:(NSString*)newName  BOID:(NSString *)ID;

/**
 *@brief Remove breakout meeting by ID.
 *@param BOID Need remove breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)removeBO:(NSString*)BOID;

/**
 *@brief Assign user to Breakout meeting.
 *@param userID Assigned user ID.
 *@param ID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)assignUserToBO:(NSString *)userID  BOID:(NSString *)ID;

/**
 *@brief Removed user from Breakout meeting.
 *@param userID Removed user ID.
 *@param ID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)removeUserFromBO:(NSString *)userID  BOID:(NSString *)ID;
@end


@interface ZoomSDKBOMeetingAdmin : NSObject

/**
 *@brief Start breakout meeting.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)startBO;

/**
 *@brief Stop breakout meeting
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)stopBO;

/**
 *@brief Assign user to is runing breakout meeting.
 *@param userID Assigned user ID.
 *@param ID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)assignNewUserToRunningBO:(NSString *)userID  BOID:(NSString *)ID;

/**
 *@brief Switch Assigned user to differnt Breakout meeting(BO-A to BO-B).
 *@param userID Assigned user ID.
 *@param ID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)switchAssignedUserToRunningBO:(NSString *)userID  BOID:(NSString *)ID;
@end

@interface ZoomSDKBOMeetingAssistant : NSObject

/**
 *@brief Join Breakout meeting by Breakout meeting ID.
 *@param ID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)joinBO:(NSString*)ID;

/**
 *@brief Leave Breakout meeting.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)leaveBO;
@end

@interface ZoomSDKBOMeetingAttendee : NSObject

/**
 *@brief Join Breakout meeting.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)joinBO;

/**
 *@brief Leave breakout meeting.
 *@return If the function succeeds,will return ZoomSDKError_Success.
 */
-(ZoomSDKError)leaveBO;

/**
 *@brief Get breakout meeting name.
 *@return If the function succeeds,will return breakout meeting name.
 */
-(NSString*)getBOName;
@end

@protocol ZoomSDKBOMeetingDataHelpDelegate <NSObject>
@optional

/**
 *@brief If breakout meeting info chanaged,will receive the callback.
 *@param boID Breakout meeting ID.
 */
-(void)onBOMeetingInfoUpdata:(NSString *)boID;

/**
 *@brief If the unassigned user chanaged,will receive the callback.
 */
-(void)onUnAssignedUserUpdated;
@end

@interface ZoomSDKBOMeetingDataHelp : NSObject

/**
 *@brief Sets the delegate.
 */
@property(nonatomic,assign)id<ZoomSDKBOMeetingDataHelpDelegate>  delegate;

/**
 *@brief Get unassigned user list.
 *@return If the function succeeds,will return unassigned user array.
 */
-(NSArray *)getUnassignedUserList;

/**
 *@brief Get breakout meeting ID list.
 *@return If the function succeeds,will return breakout meeting ID array.
 */
-(NSArray *)getBOMeetingIDList;

/**
 *@brief Get breakout meeting user name.
 *@param userID The user's user ID.
 *@return If the function succeeds,will return user name.
 */
-(NSString *)getBOUserNameWithUserID:(NSString *)userID;

/**
 *@brief Get breakout meeting user Status.
 *@param userID The user's user ID.
 *@return If the function succeeds,will return user status.
 */
-(ZoomSDKBOUserStatus)getBOUserStatusWithUserID:(NSString *)userID;

/**
 *@brief Get breakout meeting info.
 *@param BOID Breakout meeting ID.
 *@return If the function succeeds,will return ZoomSDKBOMeetingInfo object.
 */
-(ZoomSDKBOMeetingInfo *)getBOMeetingInfoWithBOID:(NSString *)BOID;
@end


@protocol ZoomSDKNewBreakoutRoomControllerDelegate <NSObject>
@optional

/**
 *@brief If the creator's permissions change,will receive the callback.
 *@param creatorObject ZoomSDKBOMeetingCreator class object.
 */
-(void)onHasCreatorPermission:(ZoomSDKBOMeetingCreator *)creatorObject;

/**
 *@brief If the admin's permissions change,will receive the callback.
 *@param adminObject ZoomSDKBOMeetingAdmin class object.
 */
-(void)onHasAdminPermission:(ZoomSDKBOMeetingAdmin *)adminObject;

/**
 *@brief If the assistant's permissions change,will receive the callback.
 *@param assistantObject ZoomSDKBOMeetingAssistant class object.
 */
-(void)onHasAssistantPermission:(ZoomSDKBOMeetingAssistant *)assistantObject;

/**
 *@brief If the attendee's permissions change,will receive the callback.
 *@param attendeeObject ZoomSDKBOMeetingAttendee class object.
 */
-(void)onHasAttendeePermission:(ZoomSDKBOMeetingAttendee *)attendeeObject;

/**
 *@brief If the dataHelper's permissions change,will receive the callback.
 *@param dataHelpObject ZoomSDKBOMeetingDataHelp class object.
 */
-(void)onHasDataHelperPermission:(ZoomSDKBOMeetingDataHelp *)dataHelpObject;

/**
 *@brief If lost creator's permissions change,will receive the callback.
 */
-(void)onLostCreatorPermission;

/**
 *@brief If lost admin's permissions change,will receive the callback.
 */
-(void)onLostAdminPermission;

/**
 *@brief If lost assistant's permissions change,will receive the callback.
 */
-(void)onLostAssistantPermission;

/**
 *@brief If lost attendee's permissions change,will receive the callback.
 */
-(void)onLostAttendeePermission;

/**
 *@brief If lost dataHelper's permissions change,will receive the callback.
 */
-(void)onLostDataHelperPermission;
@end

@interface ZoomSDKNewBreakoutRoomController : NSObject

@property(nonatomic,assign)id<ZoomSDKNewBreakoutRoomControllerDelegate>  delegate;

/**
 *@brief Get ZoomSDKBOMeetingCreator Class object.
 *@return If the function succeeds,will return ZoomSDKBOMeetingCreator Class object.
 @note Only host can get this object.
 */
-(ZoomSDKBOMeetingCreator *)getBOMeetingCreator;

/**
 *@brief Get ZoomSDKBOMeetingAdmin Class object.
 *@return If the function succeeds,will return ZoomSDKBOMeetingAdmin Class object.
 *@note Host in master meeting or breakout meeting can get this object.
 */
-(ZoomSDKBOMeetingAdmin *)getBOMeetingAdmin;

/**
 *@brief Get ZoomSDKBOMeetingAssistant Class object
 *@return If the function succeeds,will return ZoomSDKBOMeetingAssistant Class object.
 *@note Host in master/breakout meeting or cohost in breakmeeting can get this object.
 */
-(ZoomSDKBOMeetingAssistant *)getBOMeetingAssistant;

/**
 *@brief Get ZoomSDKBOMeetingAttendee Class object.
 *@return If the function succeeds,will return ZoomSDKBOMeetingAttendee Class object.
 *@note If you are CoHost/attendee, and are assigned to BO, you will get this object.
 */
-(ZoomSDKBOMeetingAttendee *)getBOMeetingAttendee;

/**
 *@brief Get ZoomSDKBOMeetingDataHelp Class object.
 *@return If the function succeeds,will return ZoomSDKBOMeetingDataHelp Class object.
 *@note Host in master/breakout meeting or cohost in breakmeeting can get this object.
 */
-(ZoomSDKBOMeetingDataHelp *)getBOMeetingDataHelp;

/**
 @brief Determine if breakout meeting is start.
 @return If the function succeeds, it will return YES, otherwise not.
 */
-(BOOL)isBOStart;

/**
 @brief Determine if breakout meeting is enable.
 @return If the function succeeds, it will return YES, otherwise not.
 */
-(BOOL)isBOEnable;

/**
 @brief Determine if user is in breakout meeting.
 @return If the function succeeds, it will return YES, otherwise not.
 */
-(BOOL)isInBOMeeting;
@end

NS_ASSUME_NONNULL_END
