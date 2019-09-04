//
//  ZoomSDKRawDataController.h
//  ZoomSDK
//

#import <Foundation/Foundation.h>
#import "ZoomSDKErrors.h"

typedef enum
{
    ZoomSDKRawDataError_SUCCESS,
    ZoomSDKRawDataError_UNINITIALIZED,
    ZoomSDKRawDataError_MALLOC_FAILED,
    ZoomSDKRawDataError_WRONGUSAGE,
    ZoomSDKRawDataError_INVALID_PARAM,
    ZoomSDKRawDataError_NOT_IN_MEETING,
    ZoomSDKRawDataError_NO_LICENSE,
    
    ZoomSDKRawDataError_VIDEO_MODULE_NOT_READY,
    ZoomSDKRawDataError_VIDEO_MODULE_ERROR,
    ZoomSDKRawDataError_VIDEO_DEVICE_ERROR,
    ZoomSDKRawDataError_NO_VIDEO_DATA,
    
    ZoomSDKRawDataError_SHARE_MODULE_NOT_READY,
    ZoomSDKRawDataError_SHARE_MODULE_ERROR,
    ZoomSDKRawDataError_NO_SHARE_DATA,
    
    ZoomSDKRawDataError_AUDIO_MODULE_NOT_READY,
    ZoomSDKRawDataError_AUDIO_MODULE_ERROR,
    ZoomSDKRawDataError_NO_AUDIO_DATA,
    //For initialization.
    ZoomSDKRawDataError_None,
}ZoomSDKRawDataError;

typedef enum
{
    ZoomSDKRawDataMemoryMode_Stack,
    ZoomSDKRawDataMemoryMode_Heap,
}ZoomSDKRawDataMemoryMode;

typedef enum
{
    ZoomSDKRawDataResolution_90,
    ZoomSDKRawDataResolution_180,
    ZoomSDKRawDataResolution_360,
    ZoomSDKRawDataResolution_720,
    ZoomSDKRawDataResolution_1080,
}ZoomSDKRawDataResolution;

typedef enum
{
    ZoomSDKLOCAL_DEVICE_ROTATION_ACTION_UNKnown,
    ZoomSDKLOCAL_DEVICE_ROTATION_ACTION_0,
    ZoomSDKLOCAL_DEVICE_ROTATION_ACTION_CLOCK90,
    ZoomSDKLOCAL_DEVICE_ROTATION_ACTION_CLOCK180,
    ZoomSDKLOCAL_DEVICE_ROTATION_ACTION_ANTI_CLOCK90,
}ZoomSDKLocalVideoDeviceRotation;

@interface ZoomSDKLocalVideoDeviceStatus : NSObject
{
    BOOL _working;
    ZoomSDKLocalVideoDeviceRotation _rotation;
}
@property (nonatomic, assign, readwrite) BOOL working;
@property (nonatomic, assign, readwrite) ZoomSDKLocalVideoDeviceRotation rotation;
@end

@interface ZoomSDKAudioRawData : NSObject
/**
 * @brief Get if this object can add ref.
 * @return If can add ref, it will return YES. Otherwise NO.
 */
-(BOOL)CanAddRef;
/**
 * @brief Add reference for this object, if you doesn't add ref, this object will be released when the callback response ends.
 * @return If the function succeeds, it will return YES. Otherwise NO.
 */
-(BOOL)AddRef;
/**
 * @brief Release the object, if you has add ref, remeber to call this api to release when you wantn't to use this object.
 * @return If the function succeeds, it will return reference count of this object.
 */
-(int)Release;
/**
 * @brief Get the buffer data.
 * @return If the function succeeds, it will return the buffer data.
 */
-(char*)GetBuffer;
/**
 * @brief Get the buffer length of this data.
 * @return If the function succeeds, it will return the buffer length of this data.
 */
-(unsigned int)GetBufferLen;
/**
 * @brief Get the sample rate of this data.
 * @return If the function succeeds, it will return the sample rate of this data.
 */
-(unsigned int)GetSampleRate;
/**
 * @brief Get the channel number of this data.
 * @return If the function succeeds, it will return the channel number of this data.
 */
-(unsigned int)GetChannelNum;
@end

@protocol ZoomSDKAudioRawDataDelegate <NSObject>
/**
 * @brief Notify to receive the mixed audio raw data.
 * @param data The received audio raw data.
 */
- (void)onMixedAudioRawDataReceived:(ZoomSDKAudioRawData*)data;
/**
 * @brief Notify to receive the one way audio raw data.
 * @param data The received audio raw data.
 * @param nodeID The user id of received user's data.
 */
- (void)onOneWayAudioRawDataReceived:(ZoomSDKAudioRawData*)data nodeID:(unsigned int)nodeID;
@end

@interface ZoomSDKAudioRawDataHelper : NSObject
{
    id<ZoomSDKAudioRawDataDelegate> _delegate;
}
@property(nonatomic, assign)id<ZoomSDKAudioRawDataDelegate> delegate;
/**
 * @brief Start the audio raw data process.
 * @param mode, the patterns to processing the audio raw data.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)start:(ZoomSDKRawDataMemoryMode)mode;
/**
 * @brief Stop the audio raw data process.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)stop;
@end


@interface ZoomSDKYUVRawDataI420 : NSObject
/**
 * @brief Get if this object can add ref.
 * @return If can add ref, it will return YES. Otherwise NO.
 */
-(BOOL)CanAddRef;
/**
 * @brief Add reference for this object, if you doesn't add ref, this object will be released when the callback response ends.
 * @return If the function succeeds, it will return YES. Otherwise NO.
 */
-(BOOL)AddRef;
/**
 * @brief Release the object, if you has add ref, remeber to call this api to release when you wantn't to use this object.
 * @return If the function succeeds, it will return reference count of this object.
 */
-(int)Release;
/**
 * @brief Get the Y data.
 * @return If the function succeeds, it will return the Y data.
 */
-(char*)GetYBuffer;
/**
 * @brief Get the U data.
 * @return If the function succeeds, it will return the U data.
 */
-(char*)GetUBuffer;
/**
 * @brief Get the V data.
 * @return If the function succeeds, it will return the V data.
 */
-(char*)GetVBuffer;
/**
 * @brief Get the buffer data.
 * @return If the function succeeds, it will return the buffer data.
 */
-(char*)GetBuffer;
/**
 * @brief Get the buffer length of this data.
 * @return If the function succeeds, it will return the buffer length of this data.
 */
-(unsigned int)GetBufferLen;
/**
 * @brief Get if this data is limited I420 format.
 * @return If is limited I420 format, it will return YES. Otherwise NO.
 */
-(BOOL)IsLimitedI420;
/**
 * @brief Get the stream width of this data.
 * @return If the function succeeds, it will return the stream width of this data.
 */
-(unsigned int)GetStreamWidth;
/**
 * @brief Get the stream height of this data.
 * @return If the function succeeds, it will return the stream height of this data.
 */
-(unsigned int)GetStreamHeight;
/**
 * @brief Get the rotation of this data.
 * @return If the function succeeds, it will return the rotation of this data.
 */
-(unsigned int)GetRotation;
@end

@protocol ZoomSDKVideoRawDataDelegate <NSObject>
/**
 * @brief Notify to specified device is running.
 * @param device The specified device.
 */
- (void)onDeviceRunning:(void*)device;
/**
 * @brief Notify to specified device stop.
 * @param device The specified device.
 */
- (void)onDeviceStop:(void*)device;
/**
 * @brief Notify the subscribed video raw data of the specified user is on.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onSubscribedVideoUserDataOn:(NSArray*)handleList;
/**
 * @brief Notify the subscribed video raw data of the specified user is off.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onSubscribedVideoUserDataOff:(NSArray*)handleList;
/**
 * @brief Notify the subscribed video raw data of the specified user has left.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onSubscribedVideoUserLeft:(NSArray*)handleList;
/**
 * @brief Notify received the video raw data.
 * @param data The received video raw data.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onVideoRawDataReceived:(ZoomSDKYUVRawDataI420*)data receiveHandleList:(NSArray*)handleList;
@end

@interface ZoomSDKVideoRawDataHelper : NSObject
{
    id<ZoomSDKVideoRawDataDelegate> _delegate;
}
@property(nonatomic, assign)id<ZoomSDKVideoRawDataDelegate> delegate;
/**
 * @brief Start the video raw data process.
 * @param mode, the patterns to processing the video raw data.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)start:(ZoomSDKRawDataMemoryMode)mode;
/**
 * @brief Subscribe the specified user's video raw data.
 * @param nodeID, the user id the specified user.
 * @param resolution, the resolution user want to subscribed.
 * @param ReceiveHandle, the receive handle user set to help identify.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)Subscribe:(unsigned int)nodeID Resolution:(ZoomSDKRawDataResolution)resolution ReceiveHandle:(unsigned long long)handle;
/**
 * @brief UnSubscribe the specified user's video raw data.
 * @param nodeID, the user id the specified user.
 * @param handle, the receive handle user set to help identify.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)UnSubscribe:(unsigned int)nodeID ReceiveHandle:(unsigned long long)handle;
/**
 * @brief Get the local device status.
 * @param device, the specified device you want to get the status.
 * @param status, the point to the object of ZoomSDKLocalVideoDeviceStatus.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)GetLocalDeviceStatus:(void*)device Status:(ZoomSDKLocalVideoDeviceStatus**)status;
/**
 * @brief Rotate the local device.
 * @param device, the specified device you want to get the status.
 * @param rotation, the rotation you want to rotate.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)RotateLocalDevice:(void*)device Rotation:(ZoomSDKLocalVideoDeviceRotation)rotation;
/**
 * @brief Stop the video raw data process.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)stop;
@end

@protocol ZoomSDKShareRawDataDelegate <NSObject>
/**
 * @brief Notify to receive the share raw data.
 * @param data The received share raw data.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onShareRawDataReceived:(ZoomSDKYUVRawDataI420*)data receiveHandleList:(NSArray*)handleList;
/**
 * @brief Notify the subscribed share data of the specified user is on.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onSubscribedShareUserDataOn:(NSArray*)handleList;
/**
 * @brief Notify the subscribed share data of the specified user is off.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onSubscribedShareUserDataOff:(NSArray*)handleList;
/**
 * @brief Notify the subscribed share data of the specified user has left.
 * @param handleList The array of handle list of this received video raw data.
 */
- (void)onSubscribedShareUserLeft:(NSArray*)handleList;
@end

@interface ZoomSDKShareRawDataHelper : NSObject
{
    id<ZoomSDKShareRawDataDelegate> _delegate;
}
@property(nonatomic, assign)id<ZoomSDKShareRawDataDelegate> delegate;
/**
 * @brief Start the share raw data process.
 * @param mode, the patterns to processing the share raw data.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)start:(ZoomSDKRawDataMemoryMode)mode;
/**
 * @brief Subscribe the specified user's share raw data.
 * @param nodeID, the user id the specified user.
 * @param resolution, the resolution user want to subscribed.
 * @param handle, the receive handle user set to help identify.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)Subscribe:(unsigned int)nodeID Resolution:(ZoomSDKRawDataResolution)resolution receiveHandle:(unsigned long long)handle;
/**
 * @brief UnSubscribe the specified user's share raw data.
 * @param nodeID, the user id the specified user.
 * @param handle, the receive handle user set to help identify.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)UnSubscribe:(unsigned int)nodeID receiveHandle:(unsigned long long)handle;
/**
 * @brief Stop the share raw data process.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)stop;
@end

@interface ZoomSDKRawDataController : NSObject
{
    ZoomSDKAudioRawDataHelper*     _audioRawDataHelper;
    ZoomSDKVideoRawDataHelper*     _videoRawDataHelper;
    ZoomSDKShareRawDataHelper*     _shareRawDataHelper;
}
/**
 * @brief Query if the user has raw data license.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not ZoomSDKRawDataError_NO_LICENSE.
 */
- (ZoomSDKRawDataError)hasRawDataLicense;
/**
 * @brief Get the object of ZoomSDKAudioRawDataHelper.
 * @param audioRawDataHelper, the point to the object of ZoomSDKAudioRawDataHelper.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)getAudioRawDataHelper:(ZoomSDKAudioRawDataHelper**)audioRawDataHelper;
/**
 * @brief Get the object of ZoomSDKVideoRawDataHelper.
 * @param videoRawDataHelper, the point to the object of ZoomSDKVideoRawDataHelper.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)getVideoRawDataHelper:(ZoomSDKVideoRawDataHelper**)videoRawDataHelper;
/**
 * @brief Get the object of ZoomSDKShareRawDataHelper.
 * @param shareRawDataHelper, the point to the object of ZoomSDKShareRawDataHelper.
 * @return If the function succeeds, it will return ZoomSDKRawDataError_SUCCESS, otherwise not.
 */
- (ZoomSDKRawDataError)getShareRawDataHelper:(ZoomSDKShareRawDataHelper**)shareRawDataHelper;
@end
