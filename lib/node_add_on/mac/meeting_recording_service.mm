
#include "../meeting_recording_wrap_core.h"
#import "Header_include.h"
#import "sdk_native_error.h"
#import "meetingServiceDelegate.h"
#include "../meeting_service_wrap_core.h"

ZMeetingRecordingWrap &ZMeetingServiceWrap::GetMeetingRecordingCtrl()
{
    return m_meeting_recording_ctrl;
}

ZMeetingRecordingWrap::ZMeetingRecordingWrap()
{
    m_pSink = nil;
}

ZMeetingRecordingWrap::~ZMeetingRecordingWrap()
{
    [[[[ZoomSDK sharedSDK] getMeetingService] getRecordController] setDelegate:nil];
    m_pSink = nil;
}

void ZMeetingRecordingWrap::Init()
{
    
}

void ZMeetingRecordingWrap::Uninit()
{
    
}

void ZMeetingRecordingWrap::SetSink(ZNativeSDKMeetingRecordingWrapSink *pSink)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            [recordingController setDelegate:[meetingServiceDelegate share]];
        }
    }
    m_pSink = pSink;
}

ZNSDKError ZMeetingRecordingWrap::StartRecording(time_t &startTimestamp, ZoomSTRING recPath)
{
    if (recPath.empty()) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    NSString *path = [NSString stringWithUTF8String:recPath.c_str()];
    BOOL isExist = [[NSFileManager defaultManager] fileExistsAtPath:path];
    if (!path || path.length == 0 || !isExist) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service){
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController startRecording:&startTimestamp saveFilePath:path];
            nativeErrorTypeHelp  Help_type;
            return Help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::StopRecording(time_t &stopTimestamp)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController stopRecording:&stopTimestamp];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::CanStartRecording(bool cloud_recording, unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController canStartRecording:cloud_recording];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::CanAllowDisAllowLocalRecording()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController canAllowDisallowRecording];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZNSDKError ZMeetingRecordingWrap::StartCloudRecording()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController startCloudRecording:YES];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::StopCloudRecording()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController startCloudRecording:NO];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}


ZNSDKError ZMeetingRecordingWrap::IsSupportLocalRecording(unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController isSupportLocalRecording:userid];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::DisAllowLocalRecording(unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController allowLocalRecording:NO User:userid];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::AllowLocalRecording(unsigned int userid)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController allowLocalRecording:YES User:userid];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

ZNSDKError ZMeetingRecordingWrap::RequestCustomizedLocalRecordingSource()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        ZoomSDKMeetingRecordController* recordingController = [service  getRecordController];
        if (recordingController) {
            ZoomSDKError ret = [recordingController requestCustomizedLocalRecordingNotification:YES];
            nativeErrorTypeHelp help_type;
            return help_type.ZoomSDKErrorType(ret);
        }
    }
    return ZNSDKERR_SERVICE_FAILED;
}

//callback

void ZMeetingRecordingWrap::onRecording2MP4Done(bool bsuccess, int iResult, ZoomSTRING szPath)
{
    if (m_pSink) {
        m_pSink->onRecording2MP4Done(bsuccess, iResult, szPath);
    }
}

void ZMeetingRecordingWrap::onRecording2MP4Processing(int iPercentage)
{
    if (m_pSink) {
        m_pSink->onRecording2MP4Processing(iPercentage);
    }
    
}

void ZMeetingRecordingWrap::onRecordingStatus(ZNRecordingStatus status)
{
    if (m_pSink) {
        m_pSink->onRecordingStatus(status);
    }
}


void ZMeetingRecordingWrap::onRecordPriviligeChanged(bool bCanRec)
{
    if (m_pSink) {
        m_pSink->onRecordPriviligeChanged(bCanRec);
    }
}

void ZMeetingRecordingWrap::onCustomizedLocalRecordingSourceNotification()
{
    return;
}

void ZMeetingRecordingWrap::onCloudRecordingStatus(ZNRecordingStatus status)
{
    if (m_pSink) {
        m_pSink->onCloudRecordingStatus(status);
    }
}
