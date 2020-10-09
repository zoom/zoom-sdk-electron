//
//  rawdataDelegate.m
//  testapplication
//
//  Created by Bella on 2020/9/15.
//  Copyright © 2020 admin. All rights reserved.
//

#import "rawdataDelegate.h"
#include "../zoom_node_addon.h"
#include "../zoom_node_rawdata_helper_mgr_class.h"

extern  ZNativeSDKWrap _g_native_wrap;

@implementation rawdataDelegate

+(rawdataDelegate *)shareRawData
{
    return [[rawdataDelegate alloc]init];
}

-(void)dealloc
{
    [super dealloc];
}

- (void)onRawDataReceived:(ZoomSDKYUVRawDataI420 *)data {
    ZoomNodeYUVRawdataI420 rawdata420;
    rawdata420.buff = [data getBuffer];
    rawdata420.ubuff = [data getUBuffer];
    rawdata420.ybuff = [data getYBuffer];
    rawdata420.vbuff = [data getVBuffer];
    rawdata420.dataBufferLen = [data getBufferLen];
    rawdata420.recvHandle = _rev_handle;
    rawdata420.isLimitedI420 = [data isLimitedI420];
    rawdata420.streamWidth = [data getStreamWidth];
    rawdata420.streamHeight = [data getStreamHeight];
    rawdata420.rotation = [data getRotation];
    rawdata420.source_id = [data getSourceID];
    ZNZoomSDKRawDataType ZNType = ZNRAW_DATA_TYPE_VIDEO;
    switch (_data_type) {
     case ZoomSDKRawDataType_Video:
         ZNType = ZNRAW_DATA_TYPE_VIDEO;
         break;

     case ZoomSDKRawDataType_Share:
         ZNType = ZNRAW_DATA_TYPE_SHARE;
         break;
     default:
         break;
    }
    ZoomNodeRawDataHelperMgr::GetInst().onRawDataFrameReceived(&rawdata420, _rev_handle, ZNType);
}
                             
- (void)onSubscribedUserDataOff {
    ZoomNodeRawDataHelperMgr::GetInst().onRawDataStatusChanged(ZNRawData_Off, _rev_handle);
}

- (void)onSubscribedUserDataOn {
    ZoomNodeRawDataHelperMgr::GetInst().onRawDataStatusChanged(ZNRawData_On, _rev_handle);
}

-(void)onSubscribedUserLeft
{
    
}

-(void)onMixedAudioRawDataReceived:(ZoomSDKAudioRawData *)data
{
    ZoomNodeAudioRawdata  audioData;
    audioData.buff = [data getBuffer];
    audioData.dataBufferLen = [data getBufferLen];
    audioData.sampleRate = [data getSampleRate];
    audioData.channelNum = [data getChannelNum];
    ZoomNodeRawDataHelperMgr::GetInst().onMixedAudioRawDataReceived(&audioData);
}

-(void)onOneWayAudioRawDataReceived:(ZoomSDKAudioRawData *)data nodeID:(unsigned int)nodeID
{
    ZoomNodeAudioRawdata  audioData;
    audioData.buff = [data getBuffer];
    audioData.dataBufferLen = [data getBufferLen];
    audioData.sampleRate = [data getSampleRate];
    audioData.channelNum = [data getChannelNum];
    ZoomNodeRawDataHelperMgr::GetInst().onOneWayAudioRawDataReceived(&audioData, nodeID);
}

- (void)onRendererBeDestroyed
{
    _g_native_wrap.GetRawAPIWrap().HandleNativeRendererBeDestroyed(_rev_handle);
}

@end

@implementation ZoomNodeRenderClass
-(instancetype)init
{
    self = [super init];
    if (self) {
        _render = nil;
        _delegate = nil;
        return self;
    }
    return nil;
}

-(void)dealloc
{
    if (_render) {
        _render = nil;
    }
    if (_delegate) {
        [_delegate release];
        _delegate = nil;
    }
}
@end
