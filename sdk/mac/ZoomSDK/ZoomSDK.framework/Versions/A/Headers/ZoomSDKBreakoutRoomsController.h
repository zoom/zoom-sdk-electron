//
//  ZoomSDKBreakoutRoomsInfo.h
//  ZoomSDK
//
//  Created by TOTTI on 8/4/17.
//  Copyright © 2017 Zoom Video Communications,Inc. All rights reserved.
//

@interface ZoomSDKBreakoutRoomsInfo : NSObject
{
    NSString* _bID;
    NSString* _roomName;
}
/**
 * @brief Get the ID of breakout room.
 * @return If the function succeeds, it will return a NSString of breakout room's ID.
 */
-(NSString*)getBID;
/**
 * @brief Get the name of breakout room.
 * @return If the function succeeds, it will return the name of breakout room.
 */
-(NSString*)getBreakoutRoomsName;
@end

@protocol ZoomSDKBreakoutRoomsDelegate <NSObject>
/**
 * @brief ZoomSDK supports to receive the request to join breakout room.
 * @param bID The ID of breakout room.
 */
- (void)onBreakoutRoomsStarted:(NSString*)bID;
@end

@interface ZoomSDKBreakoutRoomsController:NSObject
{
    id<ZoomSDKBreakoutRoomsDelegate> _delegate;
}
@property (assign, nonatomic) id<ZoomSDKBreakoutRoomsDelegate> delegate;
/**
 * @brief User joins breakout room with room ID.
 * @param bID The ID of breakout room which you want to join in.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)joinBreakoutRoom:(NSString*)bID;
/**
 * @brief User leaves breakout room.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)leaveBreakoutRoom;
/**
 * @brief Get information of breakout rooms.
 * @param infoArray A pointer of NSMutableArray, the array contains ZoomSDKBreakoutRoomsInfo object.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)getBreakoutRoomsInfo:(NSMutableArray**)infoArray;
@end


