//
//  ZoomSDKShareRender.h
//  ZoomSDK
//
//  Created by TOTTI on 19/01/2018.
//  Copyright © 2018 Zoom Video Communications,Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

@protocol ZoomSDKShareElementDelegate <NSObject>
/**
 * @brief Callback event of sharer starts to send data.
 */
-(void)onShareContentStartReceiving;
/**
 * @brief Callback of the sharer changing.
 * @param userid The ID of the new sharer. 
 */
-(void)onShareSourceUserIDNotify:(unsigned int)userid;

@end

@interface ZoomSDKShareElement : NSObject
{
    unsigned int         _userId;
    ViewShareMode        _viewMode;
    NSView*              _shareView;
    id<ZoomSDKShareElementDelegate>   _delegate;
    NSRect                            _frame;
}
@property(nonatomic, assign) unsigned int userId;
@property(nonatomic, assign) ViewShareMode viewMode;
@property(nonatomic, assign) NSView*  shareView;
@property(nonatomic, assign) id<ZoomSDKShareElementDelegate> delegate;
/**
 * @brief Create a share element.
 * @param frame The coordinates of _shareView.
 */
- (id)initWithFrame:(NSRect)frame;
/**
 * @brief Resize the frame of the share view owned by this element
 * @param frame The coordinates of _shareView.
 */
- (ZoomSDKError)resize:(NSRect)frame;
/**
 * @brief Set whether to show the share view or not.
 * @param show YES means to show, NO to hide.
 */
- (ZoomSDKError)ShowShareRender:(BOOL)show;
/**
 * @brief Clean up and reset the sharing element.
 */
- (void)cleanUp;
@end
