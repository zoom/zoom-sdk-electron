#include "../meeting_h323_wrap_core.h"
#include "sdk_native_error.h"
#import "Header_include.h"
#include "../meeting_service_wrap_core.h"
ZMeetingH323Wrap &ZMeetingServiceWrap::GetMeetingH323Ctrl()
{
    return m_meeting_h323_ctrl;
}

ZMeetingH323Wrap::ZMeetingH323Wrap()
{
    m_pSink = 0;
}

ZMeetingH323Wrap::~ZMeetingH323Wrap()
{
    m_pSink = 0;
}

void ZMeetingH323Wrap::Init()
{
    
}

void ZMeetingH323Wrap::Uninit()
{
    
}

void  ZMeetingH323Wrap::SetSink(ZNativeSDKMeetingH323WrapSink *pSink)
{
    m_pSink = pSink;
}

ZNSDKError ZMeetingH323Wrap::CallOutH323(ZoomSTRING deviceName, ZoomSTRING deviceIP, ZoomSTRING device164Num, ZNH323DeviceType deviceType)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKH323Helper *help = [service getH323Helper];
    H323DeviceInfo *info = [[[H323DeviceInfo alloc]init] autorelease];
    info.name = [NSString stringWithCString:deviceName.c_str() encoding:NSUTF8StringEncoding];
    info.ip = [NSString stringWithCString:deviceIP.c_str() encoding:NSUTF8StringEncoding];
    info.e164num = [NSString stringWithCString:device164Num.c_str() encoding:NSUTF8StringEncoding];
    nativeErrorTypeHelp  Help_type;
    info.type = Help_type.ZoomSDKH323DeviceType(deviceType);
    info.encryptType = EncryptType_Auto;
    if (service && help) {
        ZoomSDKError error = [help calloutH323Device:info];
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingH323Wrap::CancelCallOutH323()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKH323Helper *help = [service getH323Helper];
    if (help) {
        ZoomSDKError error = [help cancelCallOutH323];
        nativeErrorTypeHelp  Help_type;
        return Help_type.ZoomSDKErrorType(error);
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNList<ZoomSTRING> ZMeetingH323Wrap::GetH323Address()
{
    ZNList<ZoomSTRING> list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return list;
    }
    ZoomSDKH323Helper *help = [service getH323Helper];
    if (service && help) {
        NSArray *arr = [help getH323DeviceAddress];
        if (arr && arr.count > 0) {
            for (NSString *address in arr) {
                list.push_back(address.UTF8String);
            }
        }
        return list;
    }
    return list;
}

ZoomSTRING ZMeetingH323Wrap::GetH323Password()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return "";
    }
    ZoomSDKH323Helper *help = [service getH323Helper];
    if (service && help) {
        NSString *psd = [help getH323Password];
        if (psd != nil) {
            return [psd UTF8String];
        }
        return "";
    }
    return "";
}

ZNList<ZNH323DeviecInfo> ZMeetingH323Wrap::GetCalloutH323DviceList()
{
    ZNList<ZNH323DeviecInfo> list;
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service){
        return list;
    }
    ZoomSDKH323Helper *help = [service getH323Helper];
    ZNH323DeviecInfo ZN_info;
    if (!service || !help) {
        return list;
    }
    NSArray *deviceArr = [help getRoomH323DeviceArray];
    if (!deviceArr || deviceArr.count == 0) {
        return list;
    }
    for (H323DeviceInfo *info in deviceArr) {
        ZN_info.h323_deviceName = info.name.UTF8String;
        ZN_info.h323_deviceIP = info.ip.UTF8String;
        ZN_info.h323_deviceE164Name = info.e164num.UTF8String;
        H323DeviceType DVType = info.type;
        nativeErrorTypeHelp  Help_type;
        ZN_info.h323_DeviceType = Help_type.ZNSDKH323DeviceType(DVType);
        list.push_back(ZN_info);
    }
    return list;
}


//callback
void ZMeetingH323Wrap::onH323CalloutStatusNotify(ZNH323CalloutStatus status)
{
    if (m_pSink)
    {
        m_pSink->onH323CalloutStatusNotify(status);
    }
}
