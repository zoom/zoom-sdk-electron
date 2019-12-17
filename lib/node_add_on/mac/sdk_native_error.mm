


#include "sdk_native_error.h"

nativeErrorTypeHelp::nativeErrorTypeHelp()
{
    
}
nativeErrorTypeHelp::~nativeErrorTypeHelp()
{
    
}
#pragma mark  zoom error
ZNSDKError nativeErrorTypeHelp::ZoomSDKErrorType(ZoomSDKError &error)
{
    ZNSDKError ret = ZNSDKERR_UNKNOWN;
    switch (error) {
        case ZoomSDKError_Success:
            ret = ZNSDKERR_SUCCESS;
            break;
        case ZoomSDKError_Failed:
            ret = ZNSDKERR_MEMORY_FAILED;
            break;
        case ZoomSDKError_UnKnow:
            ret = ZNSDKERR_UNKNOWN;
            break;
        case ZoomSDKError_Uninit:
            ret = ZNSDKERR_UNINITIALIZE;
            break;
        case ZoomSDKError_ServiceFailed:
            ret = ZNSDKERR_SERVICE_FAILED;
            break;
        case ZoomSDKError_WrongUsage:
            ret = ZNSDKERR_WRONG_USEAGE;
            break;
        case ZoomSDKError_InvalidPrameter:
            ret = ZNSDKERR_INVALID_PARAMETER;
            break;
        case ZoomSDKError_NoPermission:
            ret = ZNSDKERR_NO_PERMISSION;
            break;
        case ZoomSDKError_NoRecordingInProgress:
            ret = ZNSDKERR_NORECORDINGINPROCESS;
            break;
        case ZoomSDKError_TooFrequentCall:
            ret = ZNSDKERR_TOO_FREQUENT_CALL;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark  auth error
ZNAuthResult nativeErrorTypeHelp::ZoomSDKAuthErrorTpye(ZoomSDKAuthError &error)
{
    ZNAuthResult ret = ZNAUTHRET_UNKNOWN;
    switch (error) {
        case ZoomSDKAuthError_Success:
            ret = ZNAUTHRET_SUCCESS;
            break;
        case ZoomSDKAuthError_KeyOrSecretWrong:
            ret = ZNAUTHRET_KEYORSECRETWRONG;
            break;
        case ZoomSDKAuthError_AccountNotSupport:
            ret = ZNAUTHRET_ACCOUNTNOTSUPPORT;
            break;
        case ZoomSDKAuthError_AccountNotEnableSDK:
            ret = ZNAUTHRET_ACCOUNTNOTENABLESDK;
            break;
        case ZoomSDKAuthError_Unknown:
            ret = ZNAUTHRET_UNKNOWN;
            break;
        case ZoomSDKAuthError_Timeout:
            ret = ZNAUTHRET_OVERTIME;
            break;
        case ZoomSDKAuthError_NetworkIssue:
            ret = ZNAUTHRET_NETWORKISSUE;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark  login status
ZNLOGINSTATUS nativeErrorTypeHelp::ZoomSDKLoginStatusType(ZoomSDKLoginStatus &status)
{
    ZNLOGINSTATUS ret = ZNLOGIN_IDLE;
    switch (status) {
        case ZoomSDKLoginStatus_Idle:
            ret = ZNLOGIN_IDLE;
            break;
        case ZoomSDKLoginStatus_Success:
            ret = ZNLOGIN_SUCCESS;
            break;
        case ZoomSDKLoginStatus_Failed:
            ret = ZNLOGIN_FAILED;
            break;
        case ZoomSDKLoginStatus_Processing:
            ret = ZNLOGIN_PROCESSING;
            break;
        default:
            break;
    }
    return ret;
}
#pragma mark user type
ZNSDKUserType nativeErrorTypeHelp::ZoomSDKUserTypeChange(ZoomSDKUserType &type)
{
    ZNSDKUserType ret = ZNSDK_UT_NORMALUSER;
    switch (type) {
        case ZoomSDKUserType_APIUser:
            ret = ZNSDK_UT_APIUSER;
            break;
        case ZoomSDKUserType_ZoomUser:
            ret = ZNSDK_UT_NORMALUSER;
            break;
        case ZoomSDKUserType_SSOUser:
            ret = ZNSDK_UT_WITHOUT_LOGIN;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKUserType nativeErrorTypeHelp::ZNSDKUserTypeChange(ZNSDKUserType &type)
{
    ZoomSDKUserType ret = ZoomSDKUserType_APIUser;
    switch (type) {
        case ZNSDK_UT_WITHOUT_LOGIN:
            ret = ZoomSDKUserType_SSOUser;
            break;
        case ZNSDK_UT_NORMALUSER:
            ret = ZoomSDKUserType_ZoomUser;
            break;
        case ZNSDK_UT_APIUSER:
            ret = ZoomSDKUserType_APIUser;
            break;
        default:
            break;
    }
    return ret;
}

SDKUserType  nativeErrorTypeHelp::SDKUserTypeChange(ZNZoomUserType &type)
{
    SDKUserType ret = SDKUserType_Unknown;
    switch (type) {
        case ZNZoomUserType_APIUSER:
            ret = SDKUserType_APIUser;
            break;
        case ZNZoomUserType_EMAIL_LOGIN:
            ret = SDKUserType_EmailLogin;
            break;
        case ZNZoomUserType_FACEBOOK:
            ret = SDKUserType_FaceBook;
            break;
        case ZNZoomUserType_GoogleOAuth:
            ret = SDKUserType_GoogleOAuth;
            break;
        case ZNZoomUserType_SSO:
            ret = SDKUserType_SSO;
            break;
        case ZNZoomUserType_Unknown:
            ret = SDKUserType_Unknown;
            break;
        default:
            break;
    }
    return ret;
}

LeaveMeetingCmd nativeErrorTypeHelp::ZoomSDKLeaveMeetingCmd(ZNLeaveMeetingCmd &cmd)
{
    LeaveMeetingCmd ret = LeaveMeetingCmd_End;
    switch (cmd) {
        case ZNLEAVE_MEETING:
            ret = LeaveMeetingCmd_Leave;
            break;
        case ZNEND_MEETING:
            ret = LeaveMeetingCmd_End;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark meeting status
ZNMeetingStatus  nativeErrorTypeHelp::ZNSDKMeetingStatus(ZoomSDKMeetingStatus &status)
{
    ZNMeetingStatus ret = ZNMEETING_STATUS_IDLE;
    switch (status) {
        case ZoomSDKMeetingStatus_Idle:
            ret = ZNMEETING_STATUS_IDLE;
            break;
        case ZoomSDKMeetingStatus_Connecting:
            ret = ZNMEETING_STATUS_CONNECTING;
            break;
        case ZoomSDKMeetingStatus_WaitingForHost:
            ret = ZNMEETING_STATUS_WAITINGFORHOST;
            break;
        case ZoomSDKMeetingStatus_InMeeting:
            ret = ZNMEETING_STATUS_INMEETING;
            break;
        case ZoomSDKMeetingStatus_Disconnecting:
            ret = ZNMEETING_STATUS_DISCONNECTING;
            break;
        case ZoomSDKMeetingStatus_Reconnecting:
            ret = ZNMEETING_STATUS_RECONNECTING;
            break;
        case ZoomSDKMeetingStatus_Failed:
            ret = ZNMEETING_STATUS_FAILED;
            break;
        case ZoomSDKMeetingStatus_Ended:
            ret = ZNMEETING_STATUS_ENDED;
            break;
        case ZoomSDKMeetingStatus_AudioReady:
            ret = ZNMEETING_STATUS_AUDIO_READY;
            break;
        case ZoomSDKMeetingStatus_OtherMeetingInProgress:
            ret = ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS;
            break;
        case ZoomSDKMeetingStatus_InWaitingRoom:
            ret = ZNMEETING_STATUS_IN_WAITING_ROOM;
            break;
        case ZoomSDKMeetingStatus_WaitExternalSessionKey:
            ret = ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY;
            break;
        case ZoomSDKMeetingStatus_Webinar_Promote:
            ret = ZNMEETING_STATUS_WEBINAR_PROMOTE;
            break;
        case ZoomSDKMeetingStatus_Webinar_Depromote:
            ret = ZNMEETING_STATUS_WEBINAR_DEPROMOTE;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKMeetingStatus nativeErrorTypeHelp::ZoomSDKMeetingStatusC(ZNMeetingStatus &status)
{
    ZoomSDKMeetingStatus ret = ZoomSDKMeetingStatus_Idle;
    switch (status) {
        case ZNMEETING_STATUS_IDLE:
            ret = ZoomSDKMeetingStatus_Idle;
            break;
        case ZNMEETING_STATUS_CONNECTING:
            ret = ZoomSDKMeetingStatus_Connecting;
            break;
        case ZNMEETING_STATUS_WAITINGFORHOST:
            ret = ZoomSDKMeetingStatus_WaitingForHost;
            break;
        case ZNMEETING_STATUS_INMEETING:
            ret = ZoomSDKMeetingStatus_InMeeting;
            break;
        case ZNMEETING_STATUS_DISCONNECTING:
            ret = ZoomSDKMeetingStatus_Disconnecting;
            break;
        case ZNMEETING_STATUS_RECONNECTING:
            ret = ZoomSDKMeetingStatus_Reconnecting;
            break;
        case ZNMEETING_STATUS_FAILED:
            ret = ZoomSDKMeetingStatus_Failed;
            break;
        case ZNMEETING_STATUS_ENDED:
            ret = ZoomSDKMeetingStatus_Ended;
            break;
        case ZNMEETING_STATUS_AUDIO_READY:
            ret = ZoomSDKMeetingStatus_AudioReady;
            break;
        case ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS:
            ret = ZoomSDKMeetingStatus_OtherMeetingInProgress;
            break;
        case ZNMEETING_STATUS_IN_WAITING_ROOM:
            ret = ZoomSDKMeetingStatus_InWaitingRoom;
            break;
        case ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY:
            ret = ZoomSDKMeetingStatus_WaitExternalSessionKey;
            break;
        case ZNMEETING_STATUS_WEBINAR_PROMOTE:
            ret = ZoomSDKMeetingStatus_Webinar_Promote;
            break;
        case ZNMEETING_STATUS_WEBINAR_DEPROMOTE:
            ret = ZoomSDKMeetingStatus_Webinar_Depromote;
            break;
        default:
            break;
    }
    return ret;
}
#pragma lanaguage
NSString *nativeErrorTypeHelp::ZNSDKLanaguageChanage(ZNSDK_LANGUAGE_ID &lanaguageid)
{
    NSString *ret = @"en";
    switch (lanaguageid) {
        case ZNLANGUAGE_Unknow:
            ret = @"en";
            break;
        case ZNLANGUAGE_English:
            ret = @"en";
            break;
        case ZNLANGUAGE_Chinese_Simplified:
            ret = @"zh-Hans";
            break;
        case ZNLANGUAGE_Chinese_Traditional:
            ret = @"zh-Hant";
            break;
        case ZNLANGUAGE_Japanese:
            ret = @"ja";
            break;
        case ZNLANGUAGE_Spanish:
            ret = @"es";
            break;
        case ZNLANGUAGE_German:
            ret = @"de";
            break;
        case ZNLANGUAGE_French:
            ret = @"fr";
            break;
        case ZNLANGUAGE_Portuguese:
            ret = @"pt-PT";
            break;
        case ZNLANGUAGE_Russian:
            ret = @"ru";
            break;
        default:
            break;
    }
    return ret;
}

ZNMeetingType nativeErrorTypeHelp::ZNSDKMeetingType(MeetingType &type)
{
    ZNMeetingType ret = ZNMEETING_TYPE_NONE;
    switch (type) {
        case MeetingType_None:
            ret = ZNMEETING_TYPE_NONE;
            break;
        case MeetingType_Normal:
            ret = ZNMEETING_TYPE_NORMAL;
            break;
        case MeetingType_BreakoutRoom:
            ret = ZNMEETING_TYPE_BREAKOUTROOM;
            break;
        case MeetingType_Webinar:
            ret = ZNMEETING_TYPE_WEBINAR;
            break;
        default:
            break;
    }
    return ret;
}

ZNConnectionQuality nativeErrorTypeHelp::ZNSDKConnectionQuatity(ZoomSDKConnectionQuality &quatity)
{
    ZNConnectionQuality ret = ZNConn_Quality_Unknow;
    switch (quatity) {
        case ZoomSDKConnectionQuality_Unknow:
            ret = ZNConn_Quality_Unknow;
            break;
        case ZoomSDKConnectionQuality_VeryBad:
            ret = ZNConn_Quality_Very_Bad;
            break;
        case ZoomSDKConnectionQuality_Bad:
            ret = ZNConn_Quality_Bad;
            break;
        case ZoomSDKConnectionQuality_NotGood:
            ret = ZNConn_Quality_Not_Good;
            break;
        case ZoomSDKConnectionQuality_Normal:
            ret = ZNConn_Quality_Normal;
            break;
        case ZoomSDKConnectionQuality_Good:
            ret = ZNConn_Quality_Good;
            break;
        case ZoomSDKConnectionQuality_Excellent:
            ret = ZNConn_Quality_Excellent;
            break;
        default:
            break;
    }
    return ret;
}

#pragma mark screenViewType
ZNSDKViewType nativeErrorTypeHelp::ZNSDKViewTypeC(ScreenType &type)
{
    ZNSDKViewType ret = ZNSDK_FIRST_VIEW;
    switch (type) {
        case ScreenType_First:
            ret = ZNSDK_FIRST_VIEW;
            break;
        case ScreenType_Second:
            ret = ZNSDK_SECOND_VIEW;
        default:
            break;
    }
    return ret;
}

ScreenType nativeErrorTypeHelp::ZoomSDKScreenViewType(ZNSDKViewType &type)
{
    ScreenType ret = ScreenType_First;
    switch (type) {
        case ZNSDK_FIRST_VIEW:
            ret = ScreenType_First;
            break;
        case ZNSDK_SECOND_VIEW:
            ret = ScreenType_Second;
            break;
        default:
            break;
    }
    return ret;
}

AnnotationToolType nativeErrorTypeHelp::ZoomSDKAnnotationToolType(ZNAnnotationToolType &type)
{
    AnnotationToolType ret = AnnotationToolType_None;
    switch (type) {
        case ZN_ANNOTOOL_NONE_DRAWING:
            ret = AnnotationToolType_None;
            break;
        case ZN_ANNOTOOL_PEN:
            ret = AnnotationToolType_Pen;
            break;
        case ZN_ANNOTOOL_HIGHLIGHTER:
            ret = AnnotationToolType_HighLighter;
            break;
        case ZN_ANNOTOOL_AUTO_LINE:
            ret = AnnotationToolType_AutoLine;
            break;
        case ZN_ANNOTOOL_AUTO_RECTANGLE:
            ret = AnnotationToolType_AutoRectangle;
            break;
        case ZN_ANNOTOOL_AUTO_ELLIPSE:
            ret = AnnotationToolType_AutoEllipse;
            break;
        case ZN_ANNOTOOL_AUTO_ARROW:
            ret = AnnotationToolType_AutoArrow;
            break;
        case ZN_ANNOTOOL_AUTO_RECTANGLE_FILL:
            ret = AnnotationToolType_AutoRectangleFill;
            break;
        case ZN_ANNOTOOL_AUTO_ELLIPSE_FILL:
            ret = AnnotationToolType_AutoEllipseFill;
            break;
        case ZN_ANNOTOOL_SPOTLIGHT:
            ret = AnnotationToolType_SpotLight;
            break;
        case ZN_ANNOTOOL_ARROW:
            ret = AnnotationToolType_Arrow;
            break;
        case ZN_ANNOTOOL_ERASER:
            ret = AnnotationToolType_ERASER;
            break;
        default:
            break;
    }
    return ret;
}

AnnotationClearType nativeErrorTypeHelp::ZoomSDKAnnotationClearType(ZNAnnotationClearType &type)
{
    AnnotationClearType ret = AnnotationClearType_Self;
    switch (type) {
        case ZN_ANNOCLEAR_ALL:
            ret =  AnnotationClearType_All;
            break;
        case ZN_ANNOCLEAR_SELF:
            ret = AnnotationClearType_Self;
            break;
        case ZN_ANNOCLEAR_OTHER:
            ret = AnnotationClearType_Other;
            break;
        default:
            break;
    }
    return ret;
}


ZNAudioStatus nativeErrorTypeHelp::ZNSDKUserAudioStatus(ZoomSDKAudioStatus &status)
{
    ZNAudioStatus ret = ZN_Audio_None;
    switch (status) {
        case ZoomSDKAudioStatus_None:
            ret = ZN_Audio_None;
            break;
        case ZoomSDKAudioStatus_Muted:
            ret = ZN_Audio_Muted;
            break;
        case ZoomSDKAudioStatus_UnMuted:
            ret = ZN_Audio_UnMuted;
            break;
        case ZoomSDKAudioStatus_MutedByHost:
            ret = ZN_Audio_Muted_ByHost;
            break;
        case ZoomSDKAudioStatus_UnMutedByHost:
            ret = ZN_Audio_UnMuted_ByHost;
            break;
        case ZoomSDKAudioStatus_MutedAllByHost:
            ret = ZN_Audio_MutedAll_ByHost;
            break;
        case ZoomSDKAudioStatus_UnMutedAllByHost:
            ret = ZN_Audio_UnMutedAll_ByHost;
            break;
        default:
            break;
    }
    return ret;
}


H323DeviceType nativeErrorTypeHelp::ZoomSDKH323DeviceType(ZNH323DeviceType &type)
{
    H323DeviceType ret = H323DeviceType_Unknown;
    switch (type) {
        case ZN_H323DeviceType_Unknown:
            ret = H323DeviceType_Unknown;
            break;
        case ZN_H323DeviceType_SIP:
            ret = H323DeviceType_SIP;
            break;
        case ZN_H323DeviceType_H323:
            ret = H323DeviceType_H323;
            break;
            
        default:
            break;
    }
    return ret;
}

ZNH323DeviceType nativeErrorTypeHelp::ZNSDKH323DeviceType(H323DeviceType &type)
{
    ZNH323DeviceType ret = ZN_H323DeviceType_Unknown;
    switch (type) {
        case H323DeviceType_Unknown:
            ret = ZN_H323DeviceType_Unknown;
            break;
        case H323DeviceType_SIP:
            ret = ZN_H323DeviceType_SIP;
            break;
        case H323DeviceType_H323:
            ret = ZN_H323DeviceType_H323;
            break;
        default:
            break;
    }
    return ret;
}

ZNH323CalloutStatus nativeErrorTypeHelp::ZoomSDKH323Status(H323CalloutStatus &status)
{
    ZNH323CalloutStatus ret = ZN_H323Callout_Unknown;
    switch (status) {
        case H323CalloutStatus_Unknown:
            ret = ZN_H323Callout_Unknown;
            break;
        case H323CalloutStatus_Success:
            ret = ZN_H323Callout_Success;
            break;
        case H323CalloutStatus_Ring:
            ret = ZN_H323Callout_Ring;
            break;
        case H323CalloutStatus_Timeout:
            ret = ZN_H323Callout_Timeout;
            break;
        case H323CalloutStatus_Failed:
            ret = ZN_H323Callout_Failed;
            break;
        default:
            break;
    }
    return ret;
}

ZNFreeMeetingEndingReminderType nativeErrorTypeHelp::ZoomSDKFreeMeetingEndReminderType(SDKReminderType &type)
{
    ZNFreeMeetingEndingReminderType ret = ZN_FreeMeetingEndingReminder_NONE;
    switch (type) {
        case SDKReminderType_None:
            ret = ZN_FreeMeetingEndingReminder_NONE;
            break;
        case SDKReminderType_UpgradeSuccess:
            ret = ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Success;
            break;
        case SDKReminderType_UpgradeFailed:
            ret = ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Failed;
            break;
        case SDKReminderType_CanUpgradeAccount:
            ret = ZN_FreeMeetingEndingReminder_Can_UpgradeMeeting_ToPro_Once;
            break;
        case SDKReminderType_CanFreeTrial:
            ret = ZN_FreeMeetingEndingReminder_Can_UpgradeAccount;
            break;
        case SDKReminderType_GuestReminder:
            ret = ZN_FreeMeetingEndingReminder_Reminder;
            break;
        default:
            break;
    }
    return  ret;
}

ZNFreeMeetingNeedUpgradeType nativeErrorTypeHelp::ZoomSDKFreeMeetingNeedUpgradeType(FreeMeetingNeedUpgradeType &type)
{
    ZNFreeMeetingNeedUpgradeType ret = ZN_FreeMeetingNeedUpgradeType_NONE;
    switch (type) {
        case FreeMeetingNeedUpgradeType_NONE:
            ret = ZN_FreeMeetingNeedUpgradeType_NONE;
            break;
        case FreeMeetingNeedUpgradeType_BY_ADMIN:
            ret = ZN_FreeMeetingNeedUpgradeType_BY_ADMIN;
            break;
        case FreeMeetingNeedUpgradeType_BY_GIFTURL:
            ret = ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL;
            break;
        default:
            break;
    }
    return ret;
}

ZNPremeetingAPIResult nativeErrorTypeHelp::ZNSDKPreMeetingError(ZoomSDKPremeetingError &error)
{
    ZNPremeetingAPIResult ret = ZN_PREMETAPIRET_UNKNOW;
    switch (error) {
        case ZoomSDKPremeetingError_Success:
            ret = ZN_PREMETAPIRET_SUCCESS;
            break;
        case ZoomSDKPremeetingError_Failed:
            ret = ZN_PREMETAPIRET_FAILED;
            break;
        case ZoomSDKPremeetingError_TimeOut:
            ret = ZN_PREMETAPIRET_TIMEOUT;
            break;
        case ZoomSDKPremeetingError_Unknown:
            ret = ZN_PREMETAPIRET_UNKNOW;
            break;
        default:
            break;
    }
    return ret;
}

ZNDirectShareStatus nativeErrorTypeHelp::ZNSDKDirectShareStatus(DirectShareStatus &status)
{
    ZNDirectShareStatus ret = ZN_DirectShare_Unknown;
    switch (status) {
        case DirectShareStatus_None:
            ret = ZN_DirectShare_Unknown;
            break;
        case DirectShareStatus_Connecting:
            ret = ZN_DirectShare_Connecting;
            break;
        case DirectShareStatus_InProgress:
            ret = ZN_DirectShare_In_Direct_Share_Mode;
            break;
        case DirectShareStatus_Ended:
            ret = ZN_DirectShare_Ended;
            break;
        case DirectShareStatus_NeedMeetingIDOrSharingKey:
            ret = ZN_DirectShare_Need_MeetingID_Or_PairingCode;
            break;
        case DirectShareStatus_WrongMeetingIDOrSharingKey:
            ret = ZN_DirectShare_WrongMeetingID_Or_SharingKey;
            break;
        case DirectShareStatus_NetworkError:
            ret = ZN_DirectShare_NetWork_Error;
            break;
        case DirectShareStatus_Unknow:
            ret = ZN_DirectShare_Other_Error;
            break;
        default:
            break;
    }
    return ret;
}

ZNShareStatus nativeErrorTypeHelp::ZNSDKShareStatus(ZoomSDKShareStatus &status)
{
    ZNShareStatus ret = ZN_Sharing_None;
    switch (status) {
        case ZoomSDKShareStatus_None:
            ret = ZN_Sharing_None;
            break;
        case ZoomSDKShareStatus_SelfBegin:
            ret = ZN_Sharing_Self_Send_Begin;
            break;
        case ZoomSDKShareStatus_SelfEnd:
            ret = ZN_Sharing_Self_Send_End;
            break;
        case ZoomSDKShareStatus_OtherBegin:
            ret = ZN_Sharing_Other_Share_Begin;
            break;
        case ZoomSDKShareStatus_OtherEnd:
            ret = ZN_Sharing_Other_Share_End;
            break;
        case ZoomSDKShareStatus_ViewOther:
            ret = ZN_Sharing_View_Other_Sharing;
            break;
        case ZoomSDKShareStatus_Pause:
            ret = ZN_Sharing_Pause;
            break;
        case ZoomSDKShareStatus_Resume:
            ret = ZN_Sharing_Resume;
            break;
        case ZoomSDKShareStatus_ContentTypeChange:
            ret = ZN_Sharing_ContentTypeChange;
            break;
        case ZoomSDKShareStatus_SelfStartAudioShare:
            ret = ZN_Sharing_SelfStartAudioShare;
            break;
        case ZoomSDKShareStatus_SelfStopAudioShare:
            ret = ZN_Sharing_SelfStopAudioShare;
            break;
        case ZoomSDKShareStatus_OtherStartAudioShare:
            ret = ZN_Sharing_OtherStartAudioShare;
            break;
        case ZoomSDKShareStatus_OtherStopAudioShare:
            ret = ZN_Sharing_OtherStopAudioShare;
            break;
        default:
            break;
    }
    return ret;
}

ZNUserRole nativeErrorTypeHelp::ZNSDKUserRole(UserRole &role)
{
    ZNUserRole ret = ZN_USERROLE_NONE;
    switch (role) {
        case UserRole_None:
            ret = ZN_USERROLE_NONE;
            break;
        case UserRole_Host:
            ret = ZN_USERROLE_HOST;
            break;
        case UserRole_CoHost:
            ret = ZN_USERROLE_COHOST;
            break;
        case UserRole_Attendee:
            ret = ZN_USERROLE_ATTENDEE;
            break;
        case UserRole_Panelist:
            ret = ZN_USERROLE_PANELIST;
            break;
        case UserRole_BreakoutRoom_Moderator:
            ret = ZN_USERROLE_BREAKOUTROOM_MODERATOR;
            break;
        default:
            break;
    }
    return ret;
}

ZNMeetingEndReason  nativeErrorTypeHelp::ZNSDKMeetingEndReason(EndMeetingReason &reason)
{
    ZNMeetingEndReason ret = ZNEndMeetingReason_None;
    switch (reason) {
        case EndMeetingReason_None:
            ret = ZNEndMeetingReason_None;
            break;
        case EndMeetingReason_KickByHost:
            ret = ZNEndMeetingReason_KickByHost;
            break;
        case EndMeetingReason_EndByHost:
            ret = ZNEndMeetingReason_EndByHost;
            break;
        case EndMeetingReason_JBHTimeOut:
            ret = ZNEndMeetingReason_JBHTimeOut;
            break;
        case EndMeetingReason_NoAttendee:
            ret = ZNEndMeetingReason_NoAttendee;
            break;
        case EndMeetingReason_HostStartAnotherMeeting:
            ret = ZNEndMeetingReason_HostStartAnotherMeeting;
            break;
        case EndMeetingReason_FreeMeetingTimeOut:
            ret = ZNEndMeetingReason_FreeMeetingTimeOut;
            break;
        case EndMeetingReason_NetworkBroken:
            ret = ZNEndMeetingReason_NetworkBroken;
            break;
        default:
            break;
    }
    return ret;
}

ZNMeetingFailCode  nativeErrorTypeHelp::ZNSDKMeetingFailCode(ZoomSDKMeetingError &error)
{
    ZNMeetingFailCode ret = ZNMEETING_SUCCESS;
    switch (error) {
        case ZoomSDKMeetingError_Success:
            ret = ZNMEETING_SUCCESS;
            break;
        case ZoomSDKMeetingError_NetworkUnavailable:
            ret = ZNMEETING_FAIL_NETWORK_ERR;
            break;
        case ZoomSDKMeetingError_ReconnectFailed:
            ret =  ZNMEETING_FAIL_RECONNECT_ERR;
            break;
        case ZoomSDKMeetingError_MMRError:
            ret = ZNMEETING_FAIL_MMR_ERR;
            break;
        case ZoomSDKMeetingError_PasswordError:
            ret = ZNMEETING_FAIL_PASSWORD_ERR;
            break;
        case ZoomSDKMeetingError_SessionError:
            ret = ZNMEETING_FAIL_SESSION_ERR;
            break;
        case ZoomSDKMeetingError_MeetingOver:
            ret = ZNMEETING_FAIL_MEETING_OVER;
            break;
        case ZoomSDKMeetingError_MeetingNotStart:
            ret = ZNMEETING_FAIL_MEETING_NOT_START;
            break;
        case ZoomSDKMeetingError_MeetingNotExist:
            ret = ZNMEETING_FAIL_MEETING_NOT_EXIST;
            break;
        case ZoomSDKMeetingError_UserFull:
            ret = ZNMEETING_FAIL_MEETING_USER_FULL;
            break;
        case ZoomSDKMeetingError_ClientIncompatible:
            ret = ZNCONF_FAIL_ZC_CERTIFICATE_CHANGED;
            break;
        case ZoomSDKMeetingError_NoMMR:
            ret = ZNMEETING_FAIL_NO_MMR;
            break;
        case ZoomSDKMeetingError_MeetingLocked:
            ret = ZNMEETING_FAIL_CONFLOCKED;
            break;
        case ZoomSDKMeetingError_MeetingRestricted:
            ret = ZNMEETING_FAIL_MEETING_RESTRICTED;
            break;
        case ZoomSDKMeetingError_MeetingJBHRestricted:
            ret = ZNMEETING_FAIL_MEETING_RESTRICTED_JBH;
            break;
        case ZoomSDKMeetingError_EmitWebRequestFailed:
            ret = ZNMEETING_FAIL_CANNOT_EMIT_WEBREQUEST;
            break;
        case ZoomSDKMeetingError_StartTokenExpired:
            ret = ZNMEETING_FAIL_CANNOT_START_TOKENEXPIRE;
            break;
        case ZoomSDKMeetingError_VideoSessionError:
            ret = ZNSESSION_VIDEO_ERR;
            break;
        case ZoomSDKMeetingError_AudioAutoStartError:
            ret = ZNSESSION_AUDIO_AUTOSTARTERR;
            break;
        case ZoomSDKMeetingError_RegisterWebinarFull:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_FULL;
            break;
        case ZoomSDKMeetingError_RegisterWebinarHostRegister:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_HOSTREGISTER;
            break;
        case ZoomSDKMeetingError_RegisterWebinarPanelistRegister:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_PANELISTREGISTER;
            break;
        case ZoomSDKMeetingError_RegisterWebinarDeniedEmail:
            ret = ZNMEETING_FAIL_REGISTERWEBINAR_DENIED_EMAIL;
            break;
        case ZoomSDKMeetingError_RegisterWebinarEnforceLogin:
            ret = ZNMEETING_FAIL_ENFORCE_LOGIN;
            break;
        case ZoomSDKMeetingError_ZCCertificateChanged:
            ret = ZNCONF_FAIL_ZC_CERTIFICATE_CHANGED;
            break;
        case ZoomSDKMeetingError_ConfigFileWriteFailed:
            ret = ZNMEETING_FAIL_WRITE_CONFIG_FILE;
            break;
        case ZoomSDKMeetingError_RemovedByHost:
            ret = ZNCONF_FAIL_REMOVED_BY_HOST;
            break;
        case ZoomSDKMeetingError_Unknown:
            ret = ZNMEETING_SUCCESS;
            break;
        case ZoomSDKMeetingError_None:
            ret = ZNMEETING_SUCCESS;
            break;
        default:
            break;
    }
    return ret;
}

ZoomSDKLocale nativeErrorTypeHelp::ZNSDKAPPLocalType(ZNSDK_APP_Locale &local)
{
    ZoomSDKLocale applocal = ZoomSDKLocale_Def;
    switch (local) {
        case ZNSDK_APP_Locale_CN:
            applocal = ZoomSDKLocale_CN;
            break;
        case ZNSDK_APP_Locale_Default:
            applocal = ZoomSDKLocale_Def;
            break;
        default:
            break;
    }
    return applocal;
}

ZNSMSVerificationCodeErr nativeErrorTypeHelp::ZNSDKSMSVerificationCodeError(ZoomSDKSMSVerificationCodeError &code)
{
    ZNSMSVerificationCodeErr ret = ZNSMSVerificationCodeErr_Unknown;
    switch (code) {
        case ZoomSDKSMSError_Unkunow:
            ret = ZNSMSVerificationCodeErr_Unknown;
            break;
        case ZoomSDKSMSError_Success:
            ret = ZNSMSVerificationCodeErr_Success;
            break;
        case ZoomSDKSMSError_Retrieve_SendSMSFailed:
            ret = ZNSMSVerificationCodeErr_Retrieve_SendSMSFailed;
            break;
        case ZoomSDKSMSError_Retrieve_InvalidPhoneNum:
            ret = ZNSMSVerificationCodeErr_Retrieve_InvalidPhoneNum;
            break;
        case ZoomSDKSMSError_Retrieve_PhoneNumAlreadyBound:
            ret = ZNSMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound;
            break;
        case ZoomSDKSMSError_Retrieve_PhoneNumSendTooFrequent:
            ret = ZNSMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent;
            break;
        case ZoomSDKSMSError_Verify_CodeIncorrect:
            ret = ZNSMSVerificationCodeErr_Verify_CodeIncorrect;
            break;
        case ZoomSDKSMSError_Verify_CodeExpired:
            ret = ZNSMSVerificationCodeErr_Verify_CodeExpired;
            break;
        case ZoomSDKSMSError_Verify_UnknownError:
            ret = ZNSMSVerificationCodeErr_Verify_UnknownError;
            break;
        default:
            break;
    }
    return ret;
}

ZNAudioCallbackActionInfo nativeErrorTypeHelp::ZNSDKAudioCallbackAction(ZoomSDKAudioActionInfo &info)
{
    ZNAudioCallbackActionInfo ret = ZNACTION_INFO_NONE;
    switch (info) {
        case ZoomSDKAudioActionInfo_none:
            ret = ZNACTION_INFO_NONE;
            break;
        case ZoomSDKAudioActionInfo_needJoinVoip:
            ret = ZNACTION_INFO_NEED_JOIN_VOIP;
            break;
        case ZoomSDKAudioActionInfo_muteOrUnmenuAudio:
            ret = ZNACTION_INFO_MUTE_UNMUTE_AUDIO;
            break;
        case ZoomSDKAudioActionInfo_noAudioDeviceConnected:
            ret = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED;
            break;
        case ZoomSDKAudioActionInfo_computerAudioDeviceError:
            ret = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR;
            break;
        default:
            break;
    }
    return ret;
}

ZNWebinarNeedRegisterType nativeErrorTypeHelp::ZNSDKWebinarNeedRegisterType(WebinarRegisterType &type)
{
    ZNWebinarNeedRegisterType ret = ZNWebinarReg_NONE;
    switch (type) {
        case WebinarRegisterType_None:
            ret = ZNWebinarReg_NONE;
            break;
        case WebinarRegisterType_URL:
            ret = ZNWebinarReg_By_Register_Url;
            break;
        case WebinarRegisterType_Email:
            ret = ZNWebinarReg_By_Email_and_DisplayName;
            break;
        default:
            break;
    }
    return ret;
}

ZNRequiredInfoType nativeErrorTypeHelp::ZNSDKRequiredInfoType(JoinMeetingReqInfoType &type)
{
    ZNRequiredInfoType ret = ZNREQUIRED_INFO_TYPE_NONE;
    switch (type) {
        case JoinMeetingReqInfoType_None:
            ret = ZNREQUIRED_INFO_TYPE_NONE;
            break;
        case JoinMeetingReqInfoType_Password:
            ret = ZNREQUIRED_INFO_TYPE_Password;
            break;
        case JoinMeetingReqInfoType_Password_Wrong:
            ret = ZNREQUIRED_INFO_TYPE_Password4WrongPassword;
            break;
        default:
            break;
    }
    return ret;
}
