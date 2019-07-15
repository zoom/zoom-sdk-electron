//
//  ZMHotkeyMgr.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class ZMHotkey;
@class ZMHotkeyCombo;
@protocol ZMHotkeyCenterDelegate;
@interface ZMHotkeyCenter : NSObject

@property(nonatomic, readwrite, assign) id<ZMHotkeyCenterDelegate> delegate;
@property(nonatomic, readonly, assign) BOOL isGlobalPaused;
@property(nonatomic, readonly, assign) BOOL isLocalPaused;
@property(nonatomic, readwrite, assign) BOOL supportNoneModifiers;
@property(nonatomic, readwrite, assign) UInt32 globalRequiredModifiers;
@property(nonatomic, readwrite, assign) UInt32 localRequiredModifiers;
- (void)cleanUp;
- (BOOL)registerHotKey:(ZMHotkey*)hotKey global:(BOOL)isGlobal;
- (void)unregisterHotKey:(ZMHotkey*)hotKey global:(BOOL)isGlobal;
- (void)unregisterHotKeyByIdentifier:(NSString*)identifier global:(BOOL)isGlobal;
- (ZMHotkey*)getHotkeyByIdentifier:(NSString*)identifier global:(BOOL)isGlobal;
- (void)pause:(BOOL)isGlobal;
- (void)pauseAll;
- (void)resume:(BOOL)isGlobal;
- (void)resumeAll;

- (void)hotkey:(ZMHotkey*)hotkey longPressFail:(NSEvent*)downEvent upEvent:(NSEvent*)upEvent;
@end

@protocol ZMHotkeyCenterDelegate <NSObject>
@optional
- (BOOL)hotkeyCenter:(ZMHotkeyCenter*)center shouldSkipHotkey:(ZMHotkey*)hotkey event:(NSEvent*)event suggest:(BOOL)shouldSkip;
- (BOOL)hotkeyCenter:(ZMHotkeyCenter*)center longPressFail:(ZMHotkey*)hotkey shouldShortPress:(NSEvent*) downEvent upEvent:(NSEvent*)upEvent;
@end


