

#include "../meeting_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
#import "meetingServiceDelegate.h"
#include "../meeting_annotation_wrap_core.h"

extern nativeErrorTypeHelp  Help_type;

ZMeetingAnnotationWrap  &ZMeetingServiceWrap::GetMeetingAnnotation(){
    
    return m_meeting_annotation;
}

ZNSDKError ZMeetingUICtrlWrap::GetCurrentSplitScreenModeInfo(ZNSplitScreenInfo &info){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller)
        return ZNSDKERR_SERVICE_FAILED;
    ZoomSDKSplitScreenInfo  *screeninfo = [controller getCurrentSplitScreenModeInfo];
    info.bZNInSplitScreenMode = screeninfo.isInSplitScreenMode;
    info.bZNSupportSplitScreen = screeninfo.isSupportSplitScreenMode;
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZMeetingUICtrlWrap::SwitchSplitScreenMode(bool bSplit){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *as = [service getASController];
    if (!service || !as){
        
         return ZNSDKERR_SERVICE_FAILED;
    }
   
    ZoomSDKError ret = [as switchSplitScreenMode:bSplit];
    return Help_type.ZoomSDKErrorType(ret);
}


ZMeetingAnnotationWrap::ZMeetingAnnotationWrap(){
    
}

ZMeetingAnnotationWrap::~ZMeetingAnnotationWrap(){
    
}

void ZMeetingAnnotationWrap::Init(){
    
}

void ZMeetingAnnotationWrap::Uninit(){
    
}

bool ZMeetingAnnotationWrap::IsAnnoataionDisable(){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller)
        return  NO;
    return [[controller getAnnotationController]isAnnotationDisable];
}

ZNSDKError ZMeetingAnnotationWrap::StartAnnotation(ZNSDKViewType type, ZoomSTRING left, ZoomSTRING top){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
     ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    float X = [[NSString stringWithCString:left.c_str() encoding:NSUTF8StringEncoding] floatValue];
    float Y = [[NSString stringWithCString:top.c_str() encoding:NSUTF8StringEncoding] floatValue];
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(type);
    ZoomSDKError ret = [controller startAnnotation:NSMakePoint(X, Y) onScreen:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingAnnotationWrap::StopAnnotation(ZNSDKViewType type){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(type);
    ZoomSDKError ret = [controller stopAnnotation:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}
ZNSDKError ZMeetingAnnotationWrap::SetTool(ZNSDKViewType viewType, ZNAnnotationToolType toolType){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(viewType);
    AnnotationToolType ZoomType = Help_type.ZoomSDKAnnotationToolType(toolType);
    ZoomSDKError ret = [[controller getAnnotationController]setTool:ZoomType onScreen:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}
ZNSDKError ZMeetingAnnotationWrap::Clear(ZNSDKViewType viewType, ZNAnnotationClearType toolType){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(viewType);
    AnnotationClearType ZoomType = Help_type.ZoomSDKAnnotationClearType(toolType);
    ZoomSDKError ret = [[controller getAnnotationController]clear:ZoomType onScreen:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingAnnotationWrap::SetColor(ZNSDKViewType viewType, ZoomSTRING color){
//    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
//    if (!service) {
//        return ZNSDKERR_SERVICE_FAILED;
//    }
//    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(viewType);
//    ZoomSDKError ret = [[[service getASController]getAnnotationController]setColor:<#(float)#> Green:<#(float)#> Black:<#(float)#> onScreen:<#(ScreenType)#>];
//    return  Help_type.ZoomSDKErrorType(ret);
    return ZNSDKERR_NO_IMPL;
}

ZNSDKError ZMeetingAnnotationWrap::SetLineWidth(ZNSDKViewType viewType, ZoomSTRING lineWidth){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(viewType);
    long long width = [[NSString stringWithCString:lineWidth.c_str() encoding:NSUTF8StringEncoding] longLongValue];
    ZoomSDKError ret = [[controller getAnnotationController]setLineWidth:width onScreen:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingAnnotationWrap::Undo(ZNSDKViewType viewType){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(viewType);
    ZoomSDKError ret = [[controller getAnnotationController]undo:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingAnnotationWrap::Redo(ZNSDKViewType viewType){
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK]getMeetingService];
    ZoomSDKASController *controller = [service getASController];
    if (!service || !controller) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ScreenType  screenType = Help_type.ZoomSDKScreenViewType(viewType);
    ZoomSDKError ret = [[controller getAnnotationController]redo:screenType];
    return  Help_type.ZoomSDKErrorType(ret);
}
