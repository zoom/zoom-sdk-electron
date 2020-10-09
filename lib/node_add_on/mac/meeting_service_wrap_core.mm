

#include "../meeting_service_wrap_core.h"
#include "Header_include.h"
#include "sdk_native_error.h"
#import "meetingServiceDelegate.h"
ZMeetingServiceWrap::ZMeetingServiceWrap()
{
    m_pSink = 0;
}

ZMeetingServiceWrap::~ZMeetingServiceWrap()
{
    m_pSink = 0;
    [[[ZoomSDK sharedSDK] getMeetingService] setDelegate:nil];
    [[[[ZoomSDK sharedSDK] getMeetingService] getMeetingActionController] setDelegate:nil];
    [[[[ZoomSDK sharedSDK] getMeetingService] getMeetingUIController] setDelegate:nil];
    [[[[ZoomSDK sharedSDK] getMeetingService] getH323Helper] setDelegate:nil];
    [[[[ZoomSDK sharedSDK] getMeetingService] getASController] setDelegate:nil];
    [[[[ZoomSDK sharedSDK] getMeetingService] getRealNameController] setDelegate:nil];
}

void ZMeetingServiceWrap::Init()
{
    m_meeting_audio_ctrl.Init();
    m_meeting_video_ctrl.Init();
    m_meeting_annotation.Init();
    m_meeting_ui_ctrl.Init();
    m_meeting_participants_ctrl.Init();
}

void ZMeetingServiceWrap::Uninit()
{
      
}

void ZMeetingServiceWrap::SetSink(ZNativeSDKMeetingWrapSink *pSink)
{
    [[[ZoomSDK sharedSDK] getMeetingService] setDelegate:[meetingServiceDelegate share]];
    [[[[ZoomSDK sharedSDK] getMeetingService] getMeetingActionController] setDelegate:[meetingServiceDelegate share]];
    [[[[ZoomSDK sharedSDK] getMeetingService] getMeetingUIController] setDelegate:[meetingServiceDelegate share]];
    [[[[ZoomSDK sharedSDK] getMeetingService] getH323Helper] setDelegate:[meetingServiceDelegate share]];
    [[[[ZoomSDK sharedSDK] getMeetingService] getRealNameController] setDelegate:[meetingServiceDelegate share]];
    m_pSink = pSink;
}

ZNSDKError ZMeetingServiceWrap::Start(ZNStartParam startParam)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKStartMeetingElements *elements = [[[ZoomSDKStartMeetingElements alloc] init] autorelease];
    elements.userType = Help_type.ZNSDKUserTypeChange(startParam.userType);
    elements.userId = [NSString stringWithCString:startParam.userId.c_str() encoding:NSUTF8StringEncoding];
    elements.displayName = [NSString stringWithCString:startParam.username.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:startParam.meetingNumber];
    elements.meetingNumber = [number longLongValue];
    elements.isDirectShare = startParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:startParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    
    elements.displayID = [display  intValue];
    elements.vanityID = [NSString stringWithCString:startParam.sdkVanityID.c_str() encoding:NSUTF8StringEncoding];
    elements.isNoVideo = startParam.isVideoOff;
    elements.isNoAuido = startParam.isAudioOff;
    elements.participantId = [NSString stringWithCString:startParam.participantId.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    
    if (elements.meetingNumber == 0 && elements.vanityID.length == 0) {
        elements.vanityID = nil;
    }
    ZoomSDKError ret = [service startMeeting:elements];
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Start_WithoutLogin(ZNStartParam startParam)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKStartMeetingUseZakElements *elements = [[[ZoomSDKStartMeetingUseZakElements alloc] init] autorelease];
    elements.zak = [NSString stringWithCString:startParam.userZAK.c_str() encoding:NSUTF8StringEncoding];
    elements.userType = Help_type.SDKUserTypeChange(startParam.zoomUserType);
    elements.userId = [NSString stringWithCString:startParam.userId.c_str() encoding:NSUTF8StringEncoding];
    elements.displayName = [NSString stringWithCString:startParam.username.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:startParam.meetingNumber];
    elements.meetingNumber = [number longLongValue];
    elements.isDirectShare = startParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:startParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    elements.displayID = [display  intValue];
    elements.vanityID = [NSString stringWithCString:startParam.sdkVanityID.c_str() encoding:NSUTF8StringEncoding];
   
    elements.isNoVideo = startParam.isVideoOff;
    elements.isNoAuido = startParam.isAudioOff;
    elements.participantId = [NSString stringWithCString:startParam.participantId.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    
    if (elements.meetingNumber == 0 && elements.vanityID.length == 0) {
        elements.vanityID = nil;
    }
    
    ZoomSDKError ret = [service startMeetingWithZAK:elements];
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Join(ZNJoinParam joinParam)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKJoinMeetingElements *elements = [[[ZoomSDKJoinMeetingElements alloc] init] autorelease];
    elements.userType = Help_type.ZNSDKUserTypeChange(joinParam.userType);
    elements.zak = [NSString stringWithCString:joinParam.userZAK.c_str() encoding:NSUTF8StringEncoding];
    elements.webinarToken = [NSString stringWithCString:joinParam.webinarToken.c_str() encoding:NSUTF8StringEncoding];
    elements.participantId = [NSString stringWithCString:joinParam.participantId.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:joinParam.meetingNumber];
    elements.meetingNumber = [number longLongValue];
    elements.displayName = [NSString stringWithCString:joinParam.username.c_str() encoding:NSUTF8StringEncoding];
    elements.password = [NSString stringWithCString:joinParam.psw.c_str() encoding:NSUTF8StringEncoding];
    elements.isDirectShare = joinParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:joinParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    elements.displayID = [display  intValue];
    elements.vanityID = [NSString stringWithCString:joinParam.vanityID.c_str() encoding:NSUTF8StringEncoding];
    
    elements.isNoVideo = joinParam.isVideoOff;
    elements.isNoAuido = joinParam.isAudioOff;
    
    if (elements.meetingNumber == 0 && elements.vanityID.length == 0) {
        elements.vanityID = nil;
    }
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [service joinMeeting:elements];
     return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Join_WithoutLogin(ZNJoinParam joinParam)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKJoinMeetingElements *elements = [[[ZoomSDKJoinMeetingElements alloc] init] autorelease];
    elements.userType = Help_type.ZNSDKUserTypeChange(joinParam.userType);
    elements.zak = [NSString stringWithCString:joinParam.userZAK.c_str() encoding:NSUTF8StringEncoding];
    elements.webinarToken = [NSString stringWithCString:joinParam.webinarToken.c_str() encoding:NSUTF8StringEncoding];
    elements.participantId = [NSString stringWithCString:joinParam.participantId.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:joinParam.meetingNumber];
    elements.meetingNumber = [number longLongValue];
    elements.displayName = [NSString stringWithCString:joinParam.username.c_str() encoding:NSUTF8StringEncoding];
    elements.password = [NSString stringWithCString:joinParam.psw.c_str() encoding:NSUTF8StringEncoding];
    elements.isDirectShare = joinParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:joinParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    elements.displayID = [display  intValue];
    elements.vanityID = [NSString stringWithCString:joinParam.vanityID.c_str() encoding:NSUTF8StringEncoding];
    
    elements.isNoVideo = joinParam.isVideoOff;
    elements.isNoAuido = joinParam.isAudioOff;
    
    if (elements.meetingNumber == 0 && elements.vanityID.length == 0) {
        elements.vanityID = nil;
    }
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    
    ZoomSDKError ret = [service joinMeeting:elements];
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Leave(ZNLeaveMeetingCmd cmd)
{
    nativeErrorTypeHelp  Help_type;
    LeaveMeetingCmd  leave = Help_type.ZoomSDKLeaveMeetingCmd(cmd);
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    [service leaveMeetingWithCmd:leave];
    return ZNSDKERR_SUCCESS;
}

ZNSDKError ZMeetingServiceWrap::Lock()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *actionController = [service getMeetingActionController];
    if (!actionController) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [actionController actionMeetingWithCmd:ActionMeetingCmd_LockMeeting userID:0 onScreen:ScreenType_First];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Unlock()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKMeetingActionController *actionController = [service getMeetingActionController];
    if (!actionController) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [actionController actionMeetingWithCmd:ActionMeetingCmd_UnLockMeeting userID:0 onScreen:ScreenType_First];
    nativeErrorTypeHelp  Help_type;
    return Help_type.ZoomSDKErrorType(ret);
}


ZNConnectionQuality  ZMeetingServiceWrap::GetAudioConnQuality()
{
    ZoomSDKMeetingService *meetingService = [[ZoomSDK sharedSDK] getMeetingService];
    if (!meetingService) {
        return ZNConn_Quality_Unknow;
    }
    ZoomSDKConnectionQuality audio = [meetingService getConnectionQuality:ConnectionComponent_Audio Sending:YES];
    nativeErrorTypeHelp  Help_type;
    return  Help_type.ZNSDKConnectionQuatity(audio);
}


ZNConnectionQuality ZMeetingServiceWrap::GetVideoConnQuality()
{
    ZoomSDKMeetingService *meetingService = [[ZoomSDK sharedSDK] getMeetingService];
    if (!meetingService) {
        return ZNConn_Quality_Unknow;
    }
    ZoomSDKConnectionQuality video = [meetingService getConnectionQuality:ConnectionComponent_Video Sending:YES];
    nativeErrorTypeHelp  Help_type;
    return  Help_type.ZNSDKConnectionQuatity(video);
}

ZNConnectionQuality  ZMeetingServiceWrap::GetSharingConnQuality()
{
    ZoomSDKMeetingService *meetingService = [[ZoomSDK sharedSDK] getMeetingService];
    if (!meetingService) {
        return ZNConn_Quality_Unknow;
    }
    ZoomSDKConnectionQuality share = [meetingService getConnectionQuality:ConnectionComponent_Share Sending:YES];
    nativeErrorTypeHelp  Help_type;
    return  Help_type.ZNSDKConnectionQuatity(share);
}

ZNSDKError ZMeetingServiceWrap::HandleZoomWebUriProtocolAction(ZoomSTRING protocol_action)
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    NSString *url = [NSString stringWithCString:protocol_action.c_str() encoding:NSUTF8StringEncoding];
    if (url == nil || url.length == 0) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKError ret = [service handleZoomWebUrlAction:url];
    nativeErrorTypeHelp help;
    return help.ZoomSDKErrorType(ret);
}

//callback
void ZMeetingServiceWrap::onMeetingStatusChanged(ZNMeetingStatus meetingStatus, int iResult)
{
    if (meetingStatus == ZNMEETING_STATUS_INMEETING)
    {
        [[[[ZoomSDK sharedSDK] getMeetingService] getASController] setDelegate:[meetingServiceDelegate share]];
    }
    if (m_pSink)
    {
        m_pSink -> onMeetingStatusChanged(meetingStatus, iResult);
    }
}

#pragma mark meeting info
ZMeetingInfoWrap &ZMeetingServiceWrap::GetMeetingInfo()
{
    return m_meeting_info;
}

ZoomSTRING  ZMeetingInfoWrap::GetMeetingTopic()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString  *meetingtopic = [service getMeetingProperty:MeetingPropertyCmd_Topic];
        if (!meetingtopic) {
            return "";
        }
        return   meetingtopic.UTF8String;
    }
    return "";
}

ZNMeetingType ZMeetingInfoWrap::GetMeetingType()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        MeetingType  type = [service getMeetingType];
        nativeErrorTypeHelp  Help_type;
        return  Help_type.ZNSDKMeetingType(type);
    }
    return ZNMEETING_TYPE_NONE;
}

unsigned long long  ZMeetingInfoWrap::GetMeetingNumber()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString *meetingNumber = [service  getMeetingProperty:MeetingPropertyCmd_MeetingNumber];
        if (!meetingNumber) {
            return 0;
        }
        return meetingNumber.longLongValue;
    }
    return 0;
}

ZoomSTRING ZMeetingInfoWrap::GetMeetingID()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString *meetingID = [service  getMeetingProperty:MeetingPropertyCmd_MeetingID];
        if (!meetingID) {
            return "";
        }
        return meetingID.UTF8String;
    }
    return "";
}

ZoomSTRING ZMeetingInfoWrap::GetInviteEmailTeamplate()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString *meetingInviteURL = [service  getMeetingProperty:MeetingPropertyCmd_InviteEmailTemplate];
        if (!meetingInviteURL) {
            return "";
        }
        return meetingInviteURL.UTF8String;
    }
    return "";
}

ZoomSTRING ZMeetingInfoWrap::GetInviteEmailTitle()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString *meetingEmailTitle = [service  getMeetingProperty:MeetingPropertyCmd_InviteEmailTitle];
        if (!meetingEmailTitle) {
            return "";
        }
        return meetingEmailTitle.UTF8String;
    }
    return "";
}

ZoomSTRING ZMeetingInfoWrap::GetJoinMeetingUrl()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString *meetingJoinUrl = [service  getMeetingProperty:MeetingPropertyCmd_JoinMeetingUrl];
        if (!meetingJoinUrl) {
            return "";
        }
        return meetingJoinUrl.UTF8String;
    }
    return "";
}

ZoomSTRING ZMeetingInfoWrap::GetMeetingHostTag()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        NSString *meetingHostTag = [service  getMeetingProperty:MeetingPropertyCmd_HostTag];
        if (meetingHostTag) {
            return meetingHostTag.UTF8String;
        }
        return "";
    }
    return "";
}

bool ZMeetingInfoWrap::CheckingIsInternalMeeting()
{
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (service) {
        return [service isInternalMeeting];
    }
    return false;
}






