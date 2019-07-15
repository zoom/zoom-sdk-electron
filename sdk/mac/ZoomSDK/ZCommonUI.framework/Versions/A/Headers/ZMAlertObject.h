//
//  ZMAlertObject.h
//  ZCommonUI
//
//  Created by javenlee on 2019/5/30.
//  Copyright © 2019 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef  NS_ENUM(NSInteger, ZMAlertButtonTag) {
    ZMAlert_First = 0,
    ZMAlert_Second,
    ZMAlert_Third,
    ZMAlert_Cancel,// "esc" key
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^ZMAlertCompletionHandler)(NSString *_Nullable identifier, ZMAlertButtonTag tag);

@protocol ZMAlertDelegate
@optional
- (void)alertDidClickedWithIdentifier:(NSString *)identifier buttonTag:(long)buttonTag;
- (void)alertCancelWithIdentifier:(NSString *)identifier;

@end

@interface ZMAlertObject : NSWindow

@property(nonatomic, assign, nullable) id actionDelegate;
@property (readonly, getter=isShowing) BOOL showing;

- (void)addButtonWithTitle:(NSString*)inTitle tag:(ZMAlertButtonTag)tag isDefaultButton:(BOOL)inbDefault;

- (void)showAlert;
- (void)showWindowWithCompletionHandler:(ZMAlertCompletionHandler)handler;

- (void)setAlertTitle:(NSString*)inTitle;
- (void)setAlertContent:(NSString*)inString;
- (void)setAlertContent:(NSString *)inString title:(NSString*)inTitle;
- (void)setAttributedAlertContent:(NSAttributedString *)inString title:(NSAttributedString *)inTitle;

@end

@interface ZMAlertObject (lifeTime)

+ (void)forceCloseAllAlerts;

- (void)forceClose;//!< close without invoke completionHandler

+ (nullable instancetype)fetchAlertWithIdentifier:(NSString *)identifer;

@end

NS_ASSUME_NONNULL_END
