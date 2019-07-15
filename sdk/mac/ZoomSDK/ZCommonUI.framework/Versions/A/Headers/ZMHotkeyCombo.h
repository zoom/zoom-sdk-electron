//
//  ZMHotkeyCombo.h
//  ZCommonUI
//
//  Created by francis on 2017/7/24.
//  Copyright © 2017 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

extern NSString* const kZMHotkeyCodeKey;
extern NSString* const kZMHotkeyModifierKey;

@interface ZMHotkeyCombo : NSObject<NSCopying,NSCoding>
{
    SInt32  _hotKeyCode;
    UInt32  _eventRefModifiers;
    UInt32  _nsEventModifiers;
}
@property(nonatomic, readonly, assign)SInt32 hotkeyCode;
@property(nonatomic, readonly, assign)UInt32 eventRefModifiers;
@property(nonatomic, readonly, assign)UInt32 nsEventModifiers;
@property(assign) NSDictionary* value;
+ (id)keyComboWithKeyCode:(SInt32)keyCode modifiers:(UInt32)modifiers;
- (id)initWithKeyCode:(SInt32)keyCode modifiers:(UInt32)modifiers;

+ (UInt32)convertToEventRefModifier:(UInt32)modifiers;
+ (UInt32)convertToNSEventModifier:(UInt32)modifiers;

@end
