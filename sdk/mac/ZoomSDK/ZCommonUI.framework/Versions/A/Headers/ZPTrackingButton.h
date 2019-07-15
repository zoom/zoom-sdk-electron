//
//  ZPTrackingButton.h
//  SaasBeeUILib
//
//  Created by zoom on 13-2-25.
//  Copyright (c) 2013年 zoom. All rights reserved.
//

#import "ZMRichKeyButton.h"

@interface ZPTrackingButton : ZMRichKeyButton
{
    BOOL    _hovered;
    NSTrackingArea* _trackingArea;
    NSString*   _customTooltip;
}

@property(nonatomic, assign) BOOL hovered;
@property(nonatomic, retain) NSTrackingArea* trackingArea;
@property(nonatomic, retain) NSString* customTooltip;
@property SEL hoverAction;
- (NSRect)getRectInScreen;
- (void)cleanUp;
@end
