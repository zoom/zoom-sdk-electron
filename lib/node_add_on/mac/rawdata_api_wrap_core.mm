#include "../zoom_native_raw_api_wrap_core.h"
#import "sdk_native_error.h"
#import "rawdataDelegate.h"

ZNZoomSDKRawDataType mapRawDataType(ZoomSDKRawDataType &type)
{
    ZNZoomSDKRawDataType ZNType = ZNRAW_DATA_TYPE_VIDEO;
    switch (type) {
        case ZoomSDKRawDataType_Video:
            ZNType = ZNRAW_DATA_TYPE_VIDEO;
            break;
            
        case ZoomSDKRawDataType_Share:
            ZNType = ZNRAW_DATA_TYPE_SHARE;
            break;
        default:
            break;
    }
    return ZNType;
}

ZoomSDKRawDataType ZoomMapRawDataType(ZNZoomSDKRawDataType &type)
{
    ZoomSDKRawDataType ZNType = ZoomSDKRawDataType_Video;
    switch (type) {
        case ZNRAW_DATA_TYPE_VIDEO:
            ZNType = ZoomSDKRawDataType_Video;
            break;
            
        case ZNRAW_DATA_TYPE_SHARE:
            ZNType = ZoomSDKRawDataType_Share;
            break;
        default:
            break;
    }
    return ZNType;
}

ZNZoomSDKResolution mapRawDataResolution(ZoomSDKResolution &resolution)
{
    ZNZoomSDKResolution ZNResolution = ZNZoomSDKResolution_360P;
    switch (resolution) {
        case ZoomSDKResolution_90P:
            ZNResolution = ZNZoomSDKResolution_90P;
            break;
        case ZoomSDKResolution_180P:
            ZNResolution = ZNZoomSDKResolution_180P;
            break;
        case ZoomSDKResolution_360P:
            ZNResolution = ZNZoomSDKResolution_360P;
            break;
        case ZoomSDKResolution_720P:
            ZNResolution = ZNZoomSDKResolution_720P;
            break;
        case ZoomSDKResolution_1080P:
            ZNResolution = ZNZoomSDKResolution_1080P;
            break;
        case ZoomSDKResolution_NoUse:
            ZNResolution = ZNZoomSDKResolution_NoUse;
            break;
        default:
            break;
    }
    return ZNResolution;
}

ZoomSDKResolution ZoomMapRawDataResolution(ZNZoomSDKResolution &resolution)
{
    ZoomSDKResolution ZNResolution = ZoomSDKResolution_360P;
    switch (resolution) {
        case ZNZoomSDKResolution_90P:
            ZNResolution = ZoomSDKResolution_90P;
            break;
        case ZNZoomSDKResolution_180P:
            ZNResolution = ZoomSDKResolution_180P;
            break;
        case ZNZoomSDKResolution_360P:
            ZNResolution = ZoomSDKResolution_360P;
            break;
        case ZNZoomSDKResolution_720P:
            ZNResolution = ZoomSDKResolution_720P;
            break;
        case ZNZoomSDKResolution_1080P:
            ZNResolution = ZoomSDKResolution_1080P;
            break;
        case ZNZoomSDKResolution_NoUse:
            ZNResolution = ZoomSDKResolution_NoUse;
            break;
        default:
            break;
    }
    return ZNResolution;
}

ZNativeRawAPIWrap::ZNativeRawAPIWrap()
{
    if(!renderDic)
        renderDic = [[NSMutableDictionary alloc] init];
    
}

ZNativeRawAPIWrap::~ZNativeRawAPIWrap()
{
    if (renderDic){
        if (renderDic.allKeys.count > 0) {
            [renderDic.allKeys enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                NSNumber *num = renderDic.allKeys[idx];
                DestroyRenderer([num unsignedLongLongValue]);
            }];
        }
        [renderDic release];
        renderDic = nil;
    }
}

bool ZNativeRawAPIWrap::HasRawDataLicense()
{
    ZoomSDKRawDataController *rawdataCtrl = [[ZoomSDK sharedSDK] getRawDataController];
    if (!rawdataCtrl)
        return ZNSDKERR_SERVICE_FAILED;
    ZoomSDKError ret = [rawdataCtrl hasRawDataLicense];
    if (ret == ZoomSDKError_Success)
        return true;
    return false;
}

ZNSDKError ZNativeRawAPIWrap::InitAudioRawDataHelper()
{
    ZoomSDKRawDataController *rawdataCtrl = [[ZoomSDK sharedSDK] getRawDataController];
    if (!rawdataCtrl)
        return ZNSDKERR_SERVICE_FAILED;
    
    audioRawDataWrap = nil;
    ZoomSDKError ret = [rawdataCtrl getAudioRawDataHelper:&audioRawDataWrap];
    if (ret == ZoomSDKError_Success) {
        if (audioRawDataWrap)
            [audioRawDataWrap setDelegate:[rawdataDelegate shareRawData]];
    }
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

void ZNativeRawAPIWrap::GetRawdataVideoSourceHelper()
{
    
}

ZNSDKError ZNativeRawAPIWrap::CreateRenderer(unsigned long long recv_handle)
{
    ZoomSDKRawDataController *rawdataCtrl = [[ZoomSDK sharedSDK] getRawDataController];
    if (!rawdataCtrl)
        return ZNSDKERR_SERVICE_FAILED;
    
    ZoomNodeRenderClass *RenderClass = [[ZoomNodeRenderClass alloc] init];
    ZoomSDKRenderer *videoRender = nil;
    ZoomSDKError ret = [rawdataCtrl creatRender:&videoRender];
    if (ret == ZoomSDKError_Success) {
        if (videoRender) {
            RenderClass.render = videoRender;
            [videoRender setResolution:ZoomSDKResolution_90P];
            RenderClass.delegate = [rawdataDelegate shareRawData];
            [videoRender  setDelegate:RenderClass.delegate];
            RenderClass.delegate.rev_handle = recv_handle;
            [renderDic setObject:RenderClass forKey:[NSNumber numberWithLongLong:recv_handle]];
        }
    }
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZNativeRawAPIWrap::DestroyRenderer(unsigned long long recv_handle)
{
    ZoomSDKRawDataController *rawdataCtrl = [[ZoomSDK sharedSDK] getRawDataController];
    if (!rawdataCtrl)
        return ZNSDKERR_SERVICE_FAILED;
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKError ret = [rawdataCtrl destoryRender:renderClass.render];
            if(ret == ZoomSDKError_Success){
                [renderClass.delegate release];
                [renderClass release];
                renderClass = nil;
                [renderDic removeObjectForKey:num];
                return  ZNSDKERR_SUCCESS;
            }else{
                nativeErrorTypeHelp  Help_type;
                return Help_type.ZoomSDKErrorType(ret);
            }
        }
    }
    return ZNSDKERR_WRONG_USEAGE;
}

ZNSDKError ZNativeRawAPIWrap::Subscribe(uint32_t userId, ZNZoomSDKRawDataType type, unsigned long long recv_handle)
{
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKRenderer *render = renderClass.render;
            if (render){
                ZoomSDKError ret = [render subscribe:userId rawDataType:ZoomMapRawDataType(type)];
                if (ret == ZoomSDKError_Success){
                    rawdataDelegate *RenderDel = renderClass.delegate;
                    RenderDel.data_type = ZoomMapRawDataType(type);
                    return ZNSDKERR_SUCCESS;
                }else{
                    nativeErrorTypeHelp  Help_type;
                    return Help_type.ZoomSDKErrorType(ret);
                }
            }
        }
    }
    return ZNSDKERR_MEMORY_FAILED;
}

ZNSDKError ZNativeRawAPIWrap::UnSubscribe(unsigned long long recv_handle)
{
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKRenderer *render = renderClass.render;
            if (render){
                ZoomSDKError ret = [render unSubscribe];
                if (ret == ZoomSDKError_Success){
                    return ZNSDKERR_SUCCESS;
                }else{
                    nativeErrorTypeHelp  Help_type;
                    return Help_type.ZoomSDKErrorType(ret);
                }
            }
        }
    }
    return ZNSDKERR_MEMORY_FAILED;
}

ZNSDKError ZNativeRawAPIWrap::SetRawDataResolution(ZNZoomSDKResolution resolution, unsigned long long recv_handle)
{
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKRenderer *render = renderClass.render;
            if (render){
                ZoomSDKError ret = [render setResolution:ZoomMapRawDataResolution(resolution)];
                if (ret == ZoomSDKError_Success){
                    return ZNSDKERR_SUCCESS;
                }else{
                    nativeErrorTypeHelp  Help_type;
                    return Help_type.ZoomSDKErrorType(ret);
                }
            }
        }
    }
    return ZNSDKERR_MEMORY_FAILED;
}

ZNSDKError ZNativeRawAPIWrap::GetResolution(ZNZoomSDKResolution& resolution, unsigned long long recv_handle)
{
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKRenderer *render = renderClass.render;
            if (render){
                ZoomSDKResolution ret = [render getResolution];
                resolution = mapRawDataResolution(ret);
                return ZNSDKERR_SUCCESS;
            }
        }
    }
    return ZNSDKERR_MEMORY_FAILED;
}

ZNSDKError ZNativeRawAPIWrap::GetRawDataType(ZNZoomSDKRawDataType& type, unsigned long long recv_handle)
{
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKRenderer *render = renderClass.render;
            if (render){
                ZoomSDKRawDataType ret = [render getRawDataType];
                type = mapRawDataType(ret);
                return ZNSDKERR_SUCCESS;
            }
        }
    }
    return ZNSDKERR_MEMORY_FAILED;
}

ZNSDKError ZNativeRawAPIWrap::GetUserId(uint32_t& user_id, unsigned long long recv_handle)
{
    NSArray *arr = renderDic.allKeys;
    for (NSNumber *num in arr) {
        unsigned long long handle = [num unsignedLongLongValue];
        if(handle == recv_handle){
            ZoomNodeRenderClass *renderClass = [renderDic objectForKey:num];
            ZoomSDKRenderer *render = renderClass.render;
            if (render){
                user_id = [render getUserID];
                return ZNSDKERR_SUCCESS;
            }
        }
    }
    return ZNSDKERR_WRONG_USEAGE;
}


ZNSDKError ZNativeRawAPIWrap::SubscribeAudioRawdata()
{
    if (!audioRawDataWrap)
        return ZNSDKERR_SERVICE_FAILED;
    ZoomSDKError ret = [audioRawDataWrap subscribe];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZNativeRawAPIWrap::UnSubscribeAudioRawdata()
{
    if (!audioRawDataWrap)
        return ZNSDKERR_SERVICE_FAILED;
    ZoomSDKError ret = [audioRawDataWrap unSubscribe];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

void ZNativeRawAPIWrap::HandleNativeRendererBeDestroyed(unsigned long long recv_handle)
{
    return;
}
