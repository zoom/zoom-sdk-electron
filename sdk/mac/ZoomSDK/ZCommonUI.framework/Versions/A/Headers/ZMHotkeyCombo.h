//
//  ZMHotkeyCombo.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

extern NSString* const kZMHotkeyName;
extern NSString* const kZMHotkeyCodeKey;
extern NSString* const kZMHotkeyModifierKey;
extern NSString* const kZMHotkeyInvalidFlag;

@interface ZMHotkeyCombo : NSObject<NSCopying,NSCoding>
{
    SInt32  _hotKeyCode;
    UInt32  _eventRefModifiers;
    UInt32  _nsEventModifiers;
}
@property(nonatomic, readonly, assign) SInt32 hotkeyCode;
@property(nonatomic, readonly, assign) UInt32 eventRefModifiers;
@property(nonatomic, readonly, assign) UInt32 nsEventModifiers;//NSEventModifierFlags
@property(copy) NSDictionary* value;
@property(class, readonly, retain) ZMHotkeyCombo* nullCombo;
/**
 * the default value is NO;
 */
@property(assign) BOOL isInvalid;
@property(readonly) BOOL isNullCombo;
@property(readonly) NSString* hotkeyLetter;
@property(readonly) SInt32 keyCodeForCurrentKeyboardLayout;

+ (id)comboWithValue:(NSDictionary*)value;
+ (id)keyComboWithKeyCode:(SInt32)keyCode modifiers:(UInt32)modifiers;
- (id)initWithKeyCode:(SInt32)keyCode modifiers:(UInt32)modifiers;

+ (UInt32)convertToEventRefModifier:(UInt32)modifiers;
+ (UInt32)convertToNSEventModifier:(UInt32)modifiers;

- (NSString*)emojiSymbol;
- (NSString*)characterSymbol;
@end

@interface ZMHotkeyCombo(ZMCustom)
+ (ZMHotkeyCombo*)hotkeyCombo:(NSString*)name global:(BOOL)isGlobal;
@end
