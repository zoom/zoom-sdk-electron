//
//  ZMTabView.h
//  ZCommonUI
//
//  Created by John on 11/25/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTabView : NSTabView
{
    NSColor*    _backgroundColor;
}
@property(nonatomic, retain) NSColor* backgroundColor;
@end
