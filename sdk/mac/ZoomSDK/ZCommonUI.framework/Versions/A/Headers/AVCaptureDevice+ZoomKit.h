//
//  AVCaptureDevice+ZoomKit.h
//  ZCommonUI
//
//  Created by francis zhuo on 2018/10/9.
//  Copyright © 2018 zoom. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>

enum {
    ZMAuthorizationStatusNotDetermined = 0,
    ZMAuthorizationStatusRestricted,
    ZMAuthorizationStatusDenied,
    ZMAuthorizationStatusAuthorized
};

@interface AVCaptureDevice (ZoomKit)
+ (NSInteger)zm_authorizationStatusForMediaType:(AVMediaType)mediaType;
+ (void)zm_requestAccessForMediaType:(AVMediaType)mediaType
                   completionHandler:(void (^)(BOOL granted))handler;
@end
