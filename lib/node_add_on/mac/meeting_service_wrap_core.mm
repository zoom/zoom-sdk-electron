

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
    ZoomSDKUserType  type = Help_type.ZNSDKUserTypeChange(startParam.userType);
    NSString *user_id = [NSString stringWithCString:startParam.userId.c_str() encoding:NSUTF8StringEncoding];
    NSString *token = [NSString stringWithCString:startParam.userToken.c_str() encoding:NSUTF8StringEncoding];
    NSString *displayName = [NSString stringWithCString:startParam.username.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:startParam.meetingNumber];
    NSString *num = [number stringValue];
    BOOL isDirecShare = startParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:startParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    
    CGDirectDisplayID  displayID = [display  intValue];
    NSString *vanID = [NSString stringWithCString:startParam.sdkVanityID.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [service startMeeting:type userID:user_id userToken:token displayName:displayName meetingNumber:num isDirectShare:isDirecShare sharedApp:displayID isVideoOff:startParam.isVideoOff isAuidoOff:startParam.isAudioOff vanityID:vanID];
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Start_WithoutLogin(ZNStartParam startParam)
{
    nativeErrorTypeHelp  Help_type;
    NSString *zak = [NSString stringWithCString:startParam.userZAK.c_str() encoding:NSUTF8StringEncoding];
    SDKUserType  type = Help_type.SDKUserTypeChange(startParam.zoomUserType);
    NSString *userid = [NSString stringWithCString:startParam.userId.c_str() encoding:NSUTF8StringEncoding];
    NSString *userToken = [NSString stringWithCString:startParam.userToken.c_str() encoding:NSUTF8StringEncoding];
    NSString *disName = [NSString stringWithCString:startParam.username.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:startParam.meetingNumber];
    NSString *num = [number stringValue];
    BOOL isDirecShare = startParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:startParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    CGDirectDisplayID  displayID = [display  intValue];
    NSString *vanID = [NSString stringWithCString:startParam.sdkVanityID.c_str() encoding:NSUTF8StringEncoding];
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [service startMeetingWithZAK:zak userType:type userID:userid userToken:userToken displayName:disName meetingNumber:num isDirectShare:isDirecShare sharedApp:displayID isVideoOff:startParam.isVideoOff isAuidoOff:startParam.isAudioOff vanityID:vanID];
    return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Join(ZNJoinParam joinParam)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKUserType type = Help_type.ZNSDKUserTypeChange(joinParam.userType);
    NSString *tokenLogin = [NSString stringWithCString:joinParam.token4EnforceLogin.c_str() encoding:NSUTF8StringEncoding];
    NSString *webToken = [NSString stringWithCString:joinParam.webinarToken.c_str() encoding:NSUTF8StringEncoding];
    NSString *particpanid = [NSString stringWithCString:joinParam.participantId.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:joinParam.meetingNumber];
    NSString *num = [number stringValue];
    NSString *name = [NSString stringWithCString:joinParam.username.c_str() encoding:NSUTF8StringEncoding];
    NSString *pwd = [NSString stringWithCString:joinParam.psw.c_str() encoding:NSUTF8StringEncoding];
    BOOL isDirecShare = joinParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:joinParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    CGDirectDisplayID  displayID = [display  intValue];
    NSString *vanID = [NSString stringWithCString:joinParam.vanityID.c_str() encoding:NSUTF8StringEncoding];
    if (num.intValue == 0) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [service joinMeeting:type toke4enfrocelogin:tokenLogin webinarToken:webToken participantId:particpanid meetingNumber:num displayName:name password:pwd isDirectShare:isDirecShare sharedApp:displayID isVideoOff:joinParam.isVideoOff isAuidoOff:joinParam.isAudioOff vanityID:vanID];
     return Help_type.ZoomSDKErrorType(ret);
}

ZNSDKError ZMeetingServiceWrap::Join_WithoutLogin(ZNJoinParam joinParam)
{
    nativeErrorTypeHelp  Help_type;
    ZoomSDKUserType type = Help_type.ZNSDKUserTypeChange(joinParam.userType);
    NSString *tokenLogin = [NSString stringWithCString:joinParam.token4EnforceLogin.c_str() encoding:NSUTF8StringEncoding];
    NSString *webToken = [NSString stringWithCString:joinParam.webinarToken.c_str() encoding:NSUTF8StringEncoding];
    NSString *particpanid = [NSString stringWithCString:joinParam.participantId.c_str() encoding:NSUTF8StringEncoding];
    NSNumber *number = [NSNumber numberWithUnsignedLong:joinParam.meetingNumber];
    NSString *num = [number stringValue];
    NSString *name = [NSString stringWithCString:joinParam.username.c_str() encoding:NSUTF8StringEncoding];
    NSString *pwd = [NSString stringWithCString:joinParam.psw.c_str() encoding:NSUTF8StringEncoding];
    BOOL isDirecShare = joinParam.isDirectShareDesktop;
    NSString *display = [NSString stringWithCString:joinParam.hDirectShareAppWnd.c_str() encoding:NSUTF8StringEncoding];
    CGDirectDisplayID  displayID = [display  intValue];
    NSString *vanID = [NSString stringWithCString:joinParam.vanityID.c_str() encoding:NSUTF8StringEncoding];
    
    if (num.intValue == 0) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    
    ZoomSDKMeetingService *service = [[ZoomSDK sharedSDK] getMeetingService];
    if (!service) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    ZoomSDKError ret = [service joinMeeting:type toke4enfrocelogin:tokenLogin webinarToken:webToken participantId:particpanid meetingNumber:num displayName:name password:pwd isDirectShare:isDirecShare sharedApp:displayID isVideoOff:joinParam.isVideoOff isAuidoOff:joinParam.isAudioOff vanityID:vanID];
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






