//
//  ZoomSDKUpgradeAccountHelper.h
//  ZoomSDK
//
//  Created by TOTTI on 2018/6/29.
//  Copyright © 2018 Zoom Video Communications,Inc. All rights reserved.
//

#import "ZoomSDKErrors.h"

/**
 * @brief Helper for upgrading user's account.
 * @note This interface has been deprecated, will be deleted next release.
 */
@interface ZoomSDKUpgradeAccountHelper : NSObject
{
    SDKReminderType                          _type;
}
/**
 * @brief Get the reminder type.
 * @return If the function succeeds, it will return SDKReminderType.
 */
-(SDKReminderType)getReminderType;
/**
 * @brief Free user start a group meeting over 40 minutes.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)upgradeAccountFreeTrial;
/**
 * @brief Upgrade account of free user.
 * @return If the function succeeds, it will return ZoomSDKError_Success. Otherwise failed.
 */
-(ZoomSDKError)upgradeAccount;
@end
