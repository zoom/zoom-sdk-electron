//
//  ZMHotkey.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

typedef void(^keyDownAction)(id attachment,NSEvent* event);
typedef void(^keyUpAction)(id attachment, NSEvent* event);

@class ZMHotkeyCombo;
@class ZMHotkeyCenter;
@interface ZMHotkey : NSObject<NSCopying>
{
@private
    NSString*       _identifier;
    ZMHotkeyCombo*  _hotkeyCombo;
    id              _attachment;
    
    id              _target;
    SEL             _action;//keyDown Action
    SEL             _keyUpAction;
    
    keyDownAction   _keyDownActionBlock;
    keyUpAction     _keyUpActionBlock;
    
    CGFloat         _keyDownLongPressDelay;
    
    UInt32          _carbonHotKeyID;
    void*       	_eventHotKeyRef;
    
    ZMHotkeyCenter* _hotkeyCenter;
    NSEvent*        _downEvent;
    BOOL            _isKeyDown;
}
@property(nonatomic, copy) NSString* identifier;
@property(nonatomic, readwrite, copy) ZMHotkeyCombo*  hotkeyCombo;
@property(nonatomic, retain) id attachment;

@property(nonatomic, assign) id target;
@property(nonatomic, assign) SEL action;
@property(nonatomic, assign) SEL keyUpAction;
@property(nonatomic, copy) keyDownAction keyDownActionBlock;
@property(nonatomic, copy) keyUpAction keyUpActionBlock;

@property(nonatomic, assign) CGFloat keyDownLongPressDelay;
@property(nonatomic, assign) UInt32 carbonHotKeyID;
@property(nonatomic, assign) void* eventHotKeyRef;
@property(nonatomic, readonly, assign) BOOL isSingleKeyCombo;
@property(nonatomic, assign) ZMHotkeyCenter* hotkeyCenter;

@property(nonatomic, readonly, assign) BOOL isKeyDown;
@property(nonatomic, readonly, assign) BOOL isLongPressHotkey;
/**
 * if the hotcombo modifier is equal 0, the default value is YES
 * otherwise the default value is NO.
 */
@property(nonatomic, assign) BOOL skipWhenTyping;
+ (id)hotkeyWithIdentifier:(NSString*)identifier withObject:(id)attachment;
+ (id)hotkeyWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo withObject:(id)attachment;
- (id)init;
- (id)initWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo;
- (id)initWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo withObject:(id)attachment;
- (void)cleanUp;
- (void)keyDown:(NSEvent*)event;
- (void)keyUp:(NSEvent*)event;
@end
