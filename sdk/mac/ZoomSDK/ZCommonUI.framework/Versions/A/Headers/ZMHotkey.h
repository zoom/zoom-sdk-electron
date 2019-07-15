//
//  ZMHotkey.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Carbon/Carbon.h>

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
    EventHotKeyRef	_eventHotKeyRef;
    
    short           _skipWhenTyping;
    
    ZMHotkeyCenter* _hotkeyCenter;
    NSEvent*        _downEvent;
    BOOL            _isKeyDownForLastEvent;
}
@property(nonatomic, readwrite, copy) NSString* identifier;
@property(nonatomic, readwrite, copy) ZMHotkeyCombo*  hotkeyCombo;
@property(nonatomic, readwrite, retain) id attachment;
@property(nonatomic, readwrite, assign) id target;
@property(nonatomic, readwrite, assign) SEL action;
@property(nonatomic, readwrite, assign) SEL keyUpAction;
@property(nonatomic, readwrite, copy) keyDownAction keyDownActionBlock;
@property(nonatomic, readwrite, copy) keyUpAction keyUpActionBlock;
@property(nonatomic, readwrite, assign) CGFloat keyDownLongPressDelay;
@property(nonatomic, readwrite, assign) UInt32 carbonHotKeyID;
@property(nonatomic, readwrite, assign) EventHotKeyRef eventHotKeyRef;
@property(nonatomic, readonly, assign) BOOL isSingleKeyCombo;
@property(nonatomic, readwrite, assign) ZMHotkeyCenter* hotkeyCenter;
@property(nonatomic, readonly, assign) BOOL isKeyDownForLastEvent;
/**
 * the property is effect for app leve hot key;
 * if the hotcombo modifier is equal 0, the default value is YES
 * otherwise the default value is NO.
 */
@property(nonatomic, readwrite, assign) BOOL skipWhenTyping;
+ (id)hotkeyWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo withObject:(id)attachment;
- (id)init;
- (id)initWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo;
- (id)initWithIdentifier:(NSString*)identifier keyCombo:(ZMHotkeyCombo*)combo withObject:(id)attachment;
- (void)cleanUp;
- (void)keyDown:(NSEvent*)event;
- (void)keyUp:(NSEvent*)event;
@end
