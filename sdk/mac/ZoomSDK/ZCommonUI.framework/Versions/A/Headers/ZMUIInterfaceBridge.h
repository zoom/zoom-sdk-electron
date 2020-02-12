//
//  ZMUIInterfaceBridge.h
//  ZCommonUI
//
//  Created by Justin Fang on 6/6/14.
//  Copyright (c) 2014 zoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZMRemoteControlConfActionProtocol.h"
#import "ZMPRemoteControlPTResponseProtocol.h"
#import "ZMPRemoteControlPTNotifyProtocol.h"
#import "ZMPRemoteControlMTResponseProtocol.h"
#import "ZMPRemoteControlMTNotifyProtocol.h"
#import "ZMPRemoteControlMTZRWRequestProtocol.h"
#import "ZMPConfDataProtocol.h"
#import "ZMRemoteControlCommonActionProtocol.h"
#import "ZMPPTDataProtocol.h"

@protocol ZPAudioExternalDeviceProtocol <NSObject>//ZOOM-4319
- (void)setDeviceMicMuted:(BOOL)isMute;
- (BOOL)isDeviceMicMuted;
- (void)updateDefaultMicName:(NSString*)micName;
- (BOOL)isUsingExternalDevice;
- (void)syncMeetingAudioStatus2Device;
- (void)setDeviceCallState:(unsigned char)stateData;
@end

@protocol ZPMainWinowControllerProtocol <NSObject>//ZOOM-5960
- (void)presentToRoomStatusUpdate:(int)status;
- (void)onUserLogin;
@end


@interface ZMUIInterfaceBridge : NSObject {
    id<ZMRemoteControlConfActionProtocol>               _zmpRCConfAction;
    id<ZMPRemoteControlPTResponseProtocol>              _zmpRCPTResponse;
    id<ZMPRemoteControlPTNotifyProtocol>                _zmpRCPTNotify;
    id<ZMPRemoteControlMTResponseProtocol>              _zmpRCMTResponse;
    id<ZMPRemoteControlMTNotifyProtocol>                _zmpRCMTNotify;
    id<ZMPRemoteControlMTZRWRequestProtocol>            _zmpRCMTZRWRequest;
    id<ZMPConfDataProtocol>                             _zmpMTData;
    id<ZMRemoteControlCommonActionProtocol>             _zmRCCommonAction;
    id<ZMPPTDataProtocol>                               _zmPTData;
    id<ZPAudioExternalDeviceProtocol>                   _zmPExternalDeviceHelper;//ZOOM-4319
    id<ZPMainWinowControllerProtocol>                   _zmPMainWindowController;//ZOOM-5960
}

@property(nonatomic, readwrite, assign) id<ZMRemoteControlConfActionProtocol>               zmpRCConfAction;
@property(nonatomic, readwrite, assign) id<ZMPRemoteControlPTResponseProtocol>              zmpRCPTResponse;
@property(nonatomic, readwrite, assign) id<ZMPRemoteControlPTNotifyProtocol>                zmpRCPTNotify;
@property(nonatomic, readwrite, assign) id<ZMPRemoteControlMTResponseProtocol>              zmpRCMTResponse;
@property(nonatomic, readwrite, assign) id<ZMPRemoteControlMTNotifyProtocol>                zmpRCMTNotify;
@property(nonatomic, readwrite, assign) id<ZMPRemoteControlMTZRWRequestProtocol>            zmpRCMTZRWRequest;
@property(nonatomic, readwrite, assign) id<ZMPConfDataProtocol>                             zmpMTData;
@property(nonatomic, readwrite, assign) id<ZMRemoteControlCommonActionProtocol>             zmRCCommonAction;
@property(nonatomic, readwrite, assign) id<ZMPPTDataProtocol>                               zmPTData;
@property(nonatomic, readwrite, assign) id<ZPAudioExternalDeviceProtocol>                   zmPExternalDeviceHelper;//ZOOM-4319
@property(nonatomic, readwrite, assign) id<ZPMainWinowControllerProtocol>                   zmPMainWindowController;//ZOOM-5960

+ (ZMUIInterfaceBridge*)sharedBridge;

@end
