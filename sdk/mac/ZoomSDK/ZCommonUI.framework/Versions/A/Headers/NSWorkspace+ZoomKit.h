//
//  NSWorkspace+ZoomKit.h
//  ZCommonUI
//
//  Created by 10.14 on 2020/4/1.
//  Copyright © 2020 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSWorkspace (ZoomKit)
- (BOOL)safeOpenFile:(NSString *)filePath;
@end

NS_ASSUME_NONNULL_END
