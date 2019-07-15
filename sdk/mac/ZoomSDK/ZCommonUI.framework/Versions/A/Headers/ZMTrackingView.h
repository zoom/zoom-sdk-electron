//
//  ZMTrackingView.h
//  ZCommonUI
//
//  Created by John Zhang on 13-4-2.
//  Copyright (c) 2013年 zoom. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ZMTrackingView : NSView
{
    BOOL    _hovered;
    NSTrackingArea* _trackingArea;
    id  _delegate;
}

@property(nonatomic, assign) BOOL hovered;
@property(nonatomic, retain) NSTrackingArea* trackingArea;
@property(nonatomic, assign) id delegate;

- (void)viewWillMoveToWindow:(NSWindow *)newWindow NS_REQUIRES_SUPER;
- (void)viewDidMoveToWindow NS_REQUIRES_SUPER;

- (void)cleanUp;
@end

@interface ZMTrackingViewOutSide : NSView
{
    BOOL    _hovered;
    NSTrackingArea* _trackingArea;
}

@property(nonatomic, assign) BOOL hovered;
@property(nonatomic, retain) NSTrackingArea* trackingArea;

- (void)cleanUp;
@end
