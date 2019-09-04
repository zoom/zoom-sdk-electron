


#include "sdk_native_error.h"

nativeErrorTypeHelp::nativeErrorTypeHelp(){
    
}
nativeErrorTypeHelp::~nativeErrorTypeHelp(){
    
}
#pragma mark  zoom error
ZNSDKError nativeErrorTypeHelp::ZoomSDKErrorType(ZoomSDKError &error){
    switch (error) {
            case ZoomSDKError_Success:
                return ZNSDKERR_SUCCESS;
                break;
            case ZoomSDKError_Failed:
                return ZNSDKERR_MEMORY_FAILED;
                break;
            case ZoomSDKError_UnKnow:
                return ZNSDKERR_UNKNOWN;
                break;
            case ZoomSDKError_Uninit:
                return ZNSDKERR_UNINITIALIZE;
                break;
            case ZoomSDKError_ServiceFailed:
                return ZNSDKERR_SERVICE_FAILED;
                break;
            case ZoomSDKError_WrongUsage:
                return ZNSDKERR_WRONG_USEAGE;
                break;
            case ZoomSDKError_InvalidPrameter:
                return ZNSDKERR_INVALID_PARAMETER;
                break;
            case ZoomSDKError_NoPermission:
                return ZNSDKERR_NO_PERMISSION;
                break;
            case ZoomSDKError_NoRecordingInProgress:
                return ZNSDKERR_NORECORDINGINPROCESS;
                break;
            case ZoomSDKError_TooFrequentCall:
                return ZNSDKERR_TOO_FREQUENT_CALL;
                break;
            
        default:
            break;
    }
}

#pragma mark  auth error
ZNAuthResult nativeErrorTypeHelp::ZoomSDKAuthErrorTpye(ZoomSDKAuthError &error){

    switch (error) {
            case ZoomSDKAuthError_Success:
                return ZNAUTHRET_SUCCESS;
                break;
            case ZoomSDKAuthError_KeyOrSecretWrong:
                return ZNAUTHRET_KEYORSECRETWRONG;
                break;
            case ZoomSDKAuthError_AccountNotSupport:
                return ZNAUTHRET_ACCOUNTNOTSUPPORT;
                break;
            case ZoomSDKAuthError_AccountNotEnableSDK:
                return ZNAUTHRET_ACCOUNTNOTENABLESDK;
                break;
            case ZoomSDKAuthError_Unknown:
                return ZNAUTHRET_UNKNOWN;
                break;
            case ZoomSDKAuthError_Timeout:
                return ZNAUTHRET_OVERTIME;
                break;
            case ZoomSDKAuthError_NetworkIssue:
                return ZNAUTHRET_NETWORKISSUE;
                break;
            
        default:
            break;
    }
}

#pragma mark  login status
ZNLOGINSTATUS nativeErrorTypeHelp::ZoomSDKLoginStatusType(ZoomSDKLoginStatus &status){
    
    switch (status) {
            case ZoomSDKLoginStatus_Idle:
                return ZNLOGIN_IDLE;
                break;
            case ZoomSDKLoginStatus_Success:
                return ZNLOGIN_SUCCESS;
                break;
            case ZoomSDKLoginStatus_Failed:
                return ZNLOGIN_FAILED;
                break;
            case ZoomSDKLoginStatus_Processing:
                return ZNLOGIN_PROCESSING;
                break;
        default:
            break;
    }
}
#pragma mark user type
ZNSDKUserType nativeErrorTypeHelp::ZoomSDKUserTypeChange(ZoomSDKUserType &type){

    switch (type) {
            case ZoomSDKUserType_APIUser:
                return ZNSDK_UT_APIUSER;
                break;
            case ZoomSDKUserType_ZoomUser:
                return ZNSDK_UT_NORMALUSER;
                break;
            case ZoomSDKUserType_SSOUser:
                return ZNSDK_UT_WITHOUT_LOGIN;
                break;
            
        default:
            break;
    }
}

ZoomSDKUserType nativeErrorTypeHelp::ZNSDKUserTypeChange(ZNSDKUserType &type){

    switch (type) {
            case ZNSDK_UT_WITHOUT_LOGIN:
                return ZoomSDKUserType_SSOUser;
                break;
            case ZNSDK_UT_NORMALUSER:
                return ZoomSDKUserType_ZoomUser;
                break;
            case ZNSDK_UT_APIUSER:
                return ZoomSDKUserType_APIUser;
                break;
            
        default:
            break;
    }
}

SDKUserType  nativeErrorTypeHelp::SDKUserTypeChange(ZNZoomUserType &type){
    
    switch (type) {
            case ZNZoomUserType_APIUSER:
                return SDKUserType_APIUser;
                break;
            case ZNZoomUserType_EMAIL_LOGIN:
                return SDKUserType_EmailLogin;
                break;
            case ZNZoomUserType_FACEBOOK:
                return SDKUserType_FaceBook;
                break;
            case ZNZoomUserType_GoogleOAuth:
                return SDKUserType_GoogleOAuth;
                break;
            case ZNZoomUserType_SSO:
                return SDKUserType_SSO;
                break;
            case ZNZoomUserType_Unknown:
                return SDKUserType_Unknown;
                break;
            
        default:
            break;
    }
}

LeaveMeetingCmd nativeErrorTypeHelp::ZoomSDKLeaveMeetingCmd(ZNLeaveMeetingCmd &cmd){

    switch (cmd) {
            case ZNLEAVE_MEETING:
                return LeaveMeetingCmd_Leave;
                break;
            case ZNEND_MEETING:
                return LeaveMeetingCmd_End;
                break;
        default:
            break;
    }
}

#pragma mark meeting status
ZNMeetingStatus  nativeErrorTypeHelp::ZNSDKMeetingStatus(ZoomSDKMeetingStatus &status){
    switch (status) {
        case ZoomSDKMeetingStatus_Idle:
            return ZNMEETING_STATUS_IDLE;
            break;
        case ZoomSDKMeetingStatus_Connecting:
            return ZNMEETING_STATUS_CONNECTING;
            break;
        case ZoomSDKMeetingStatus_WaitingForHost:
            return ZNMEETING_STATUS_WAITINGFORHOST;
            break;
        case ZoomSDKMeetingStatus_InMeeting:
            return ZNMEETING_STATUS_INMEETING;
            break;
        case ZoomSDKMeetingStatus_Disconnecting:
            return ZNMEETING_STATUS_DISCONNECTING;
            break;
        case ZoomSDKMeetingStatus_Reconnecting:
            return ZNMEETING_STATUS_RECONNECTING;
            break;
        case ZoomSDKMeetingStatus_Failed:
            return ZNMEETING_STATUS_FAILED;
            break;
        case ZoomSDKMeetingStatus_Ended:
            return ZNMEETING_STATUS_ENDED;
            break;
        case ZoomSDKMeetingStatus_AudioReady:
            return ZNMEETING_STATUS_AUDIO_READY;
            break;
        case ZoomSDKMeetingStatus_OtherMeetingInProgress:
            return ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS;
            break;
        case ZoomSDKMeetingStatus_InWaitingRoom:
            return ZNMEETING_STATUS_IN_WAITING_ROOM;
            break;
        case ZoomSDKMeetingStatus_WaitExternalSessionKey:
            return ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY;
            break;
        case ZoomSDKMeetingStatus_Webinar_Promote:
            return ZNMEETING_STATUS_WEBINAR_PROMOTE;
            break;
        case ZoomSDKMeetingStatus_Webinar_Depromote:
            return ZNMEETING_STATUS_WEBINAR_DEPROMOTE;
            break;
            
        default:
            break;
    }
}

ZoomSDKMeetingStatus nativeErrorTypeHelp::ZoomSDKMeetingStatusC(ZNMeetingStatus &status){
    switch (status) {
        case ZNMEETING_STATUS_IDLE:
            return ZoomSDKMeetingStatus_Idle;
            break;
        case ZNMEETING_STATUS_CONNECTING:
            return ZoomSDKMeetingStatus_Connecting;
            break;
        case ZNMEETING_STATUS_WAITINGFORHOST:
            return ZoomSDKMeetingStatus_WaitingForHost;
            break;
        case ZNMEETING_STATUS_INMEETING:
            return ZoomSDKMeetingStatus_InMeeting;
            break;
        case ZNMEETING_STATUS_DISCONNECTING:
            return ZoomSDKMeetingStatus_Disconnecting;
            break;
        case ZNMEETING_STATUS_RECONNECTING:
            return ZoomSDKMeetingStatus_Reconnecting;
            break;
        case ZNMEETING_STATUS_FAILED:
            return ZoomSDKMeetingStatus_Failed;
            break;
        case ZNMEETING_STATUS_ENDED:
            return ZoomSDKMeetingStatus_Ended;
            break;
        case ZNMEETING_STATUS_AUDIO_READY:
            return ZoomSDKMeetingStatus_AudioReady;
            break;
        case ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS:
            return ZoomSDKMeetingStatus_OtherMeetingInProgress;
            break;
        case ZNMEETING_STATUS_IN_WAITING_ROOM:
            return ZoomSDKMeetingStatus_InWaitingRoom;
            break;
        case ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY:
            return ZoomSDKMeetingStatus_WaitExternalSessionKey;
            break;
        case ZNMEETING_STATUS_WEBINAR_PROMOTE:
            return ZoomSDKMeetingStatus_Webinar_Promote;
            break;
        case ZNMEETING_STATUS_WEBINAR_DEPROMOTE:
            return ZoomSDKMeetingStatus_Webinar_Depromote;
            break;
            
        default:
            break;
    }
    return ZoomSDKMeetingStatus_Failed;
}
#pragma lanaguage
NSString *nativeErrorTypeHelp::ZNSDKLanaguageChanage(ZNSDK_LANGUAGE_ID &lanaguageid){
    if (lanaguageid == ZNLANGUAGE_Unknow) {
        return @"en";
    }
    if (lanaguageid == ZNLANGUAGE_English) {
        return @"en";
    }
    if (lanaguageid == ZNLANGUAGE_Chinese_Simplified) {
        return @"zh-Hans";
    }
    if (lanaguageid == ZNLANGUAGE_Chinese_Traditional) {
        return @"zh-Hant";
    }
    if (lanaguageid == ZNLANGUAGE_Japanese) {
        return @"ja";
    }
    if (lanaguageid == ZNLANGUAGE_Spanish) {
        return @"es";
    }
    if (lanaguageid == ZNLANGUAGE_German) {
        return @"de";
    }
    if (lanaguageid == ZNLANGUAGE_French) {
        return @"fr";
    }
    if (lanaguageid == ZNLANGUAGE_Portuguese) {
        return @"pt-PT";
    }
    if (lanaguageid == ZNLANGUAGE_Russian) {
        return @"ru";
    }
    
    return @"en";
}

ZNMeetingType nativeErrorTypeHelp::ZNSDKMeetingType(MeetingType &type){
    switch (type) {
        case MeetingType_None:
            return ZNMEETING_TYPE_NONE;
            break;
        case MeetingType_Normal:
            return ZNMEETING_TYPE_NORMAL;
            break;
        case MeetingType_BreakoutRoom:
            return ZNMEETING_TYPE_BREAKOUTROOM;
            break;
        case MeetingType_Webinar:
            return ZNMEETING_TYPE_WEBINAR;
            break;
        default:
            break;
    }
}

ZNConnectionQuality nativeErrorTypeHelp::ZNSDKConnectionQuatity(ZoomSDKConnectionQuality &quatity){
    switch (quatity) {
        case ZoomSDKConnectionQuality_Unknow:
            return ZNConn_Quality_Unknow;
            break;
        case ZoomSDKConnectionQuality_VeryBad:
            return ZNConn_Quality_Very_Bad;
            break;
        case ZoomSDKConnectionQuality_Bad:
            return ZNConn_Quality_Bad;
            break;
        case ZoomSDKConnectionQuality_NotGood:
            return ZNConn_Quality_Not_Good;
            break;
        case ZoomSDKConnectionQuality_Normal:
            return ZNConn_Quality_Normal;
            break;
        case ZoomSDKConnectionQuality_Good:
            return ZNConn_Quality_Good;
            break;
        case ZoomSDKConnectionQuality_Excellent:
            return ZNConn_Quality_Excellent;
            break;
        default:
            break;
    }
}

#pragma mark screenViewType
ZNSDKViewType nativeErrorTypeHelp::ZNSDKViewTypeC(ScreenType &type){
    switch (type) {
        case ScreenType_First:
            return ZNSDK_FIRST_VIEW;
            break;
        case ScreenType_Second:
            return ZNSDK_SECOND_VIEW;
        default:
            break;
    }
}

ScreenType nativeErrorTypeHelp::ZoomSDKScreenViewType(ZNSDKViewType &type){
    switch (type) {
        case ZNSDK_FIRST_VIEW:
            return ScreenType_First;
            break;
        case ZNSDK_SECOND_VIEW:
            return ScreenType_Second;
            break;
        default:
            break;
    }
}

AnnotationToolType nativeErrorTypeHelp::ZoomSDKAnnotationToolType(ZNAnnotationToolType &type){
    switch (type) {
        case ZN_ANNOTOOL_NONE_DRAWING:
            return AnnotationToolType_None;
            break;
        case ZN_ANNOTOOL_PEN:
            return AnnotationToolType_Pen;
            break;
        case ZN_ANNOTOOL_HIGHLIGHTER:
            return AnnotationToolType_HighLighter;
            break;
        case ZN_ANNOTOOL_AUTO_LINE:
            return AnnotationToolType_AutoLine;
            break;
        case ZN_ANNOTOOL_AUTO_RECTANGLE:
            
            return AnnotationToolType_AutoRectangle;
            break;
        case ZN_ANNOTOOL_AUTO_ELLIPSE:
            return AnnotationToolType_AutoEllipse;
            break;
        case ZN_ANNOTOOL_AUTO_ARROW:
            return AnnotationToolType_AutoArrow;
            break;
        case ZN_ANNOTOOL_AUTO_RECTANGLE_FILL:
            return AnnotationToolType_AutoRectangleFill;
            break;
        case ZN_ANNOTOOL_AUTO_ELLIPSE_FILL:
            return AnnotationToolType_AutoEllipseFill;
            break;
        case ZN_ANNOTOOL_SPOTLIGHT:
            return AnnotationToolType_SpotLight;
            break;
        case ZN_ANNOTOOL_ARROW:
            return AnnotationToolType_Arrow;
            break;
        case ZN_ANNOTOOL_ERASER:
            return AnnotationToolType_ERASER;
            break;
        default:
            break;
    }
}

AnnotationClearType nativeErrorTypeHelp::ZoomSDKAnnotationClearType(ZNAnnotationClearType &type){
    switch (type) {
        case ZN_ANNOCLEAR_ALL:
            return  AnnotationClearType_All;
            break;
        case ZN_ANNOCLEAR_SELF:
            return AnnotationClearType_Self;
            break;
        case ZN_ANNOCLEAR_OTHER:
            return AnnotationClearType_Other;
            break;
        default:
            break;
    }
}


ZNAudioStatus nativeErrorTypeHelp::ZNSDKUserAudioStatus(ZoomSDKAudioStatus &status){
    switch (status) {
        case ZoomSDKAudioStatus_None:
            return  ZN_Audio_None;
            break;
        case ZoomSDKAudioStatus_Muted:
            return ZN_Audio_Muted;
            break;
        case ZoomSDKAudioStatus_UnMuted:
            return ZN_Audio_UnMuted;
            break;
        case ZoomSDKAudioStatus_MutedByHost:
            return ZN_Audio_Muted_ByHost;
            break;
        case ZoomSDKAudioStatus_UnMutedByHost:
            return ZN_Audio_UnMuted_ByHost;
            break;
        case ZoomSDKAudioStatus_MutedAllByHost:
            return ZN_Audio_MutedAll_ByHost;
            break;
        case ZoomSDKAudioStatus_UnMutedAllByHost:
            return ZN_Audio_UnMutedAll_ByHost;
            break;
        default:
            break;
    }
}


H323DeviceType nativeErrorTypeHelp::ZoomSDKH323DeviceType(ZNH323DeviceType &type){
    switch (type) {
        case ZN_H323DeviceType_Unknown:
            return H323DeviceType_Unknown;
            break;
        case ZN_H323DeviceType_SIP:
            return H323DeviceType_SIP;
            break;
        case ZN_H323DeviceType_H323:
            return H323DeviceType_H323;
            break;
            
        default:
            break;
    }
}

ZNH323DeviceType nativeErrorTypeHelp::ZNSDKH323DeviceType(H323DeviceType &type){

    switch (type) {
        case H323DeviceType_Unknown:
            return ZN_H323DeviceType_Unknown;
            break;
        case H323DeviceType_SIP:
            return ZN_H323DeviceType_SIP;
            break;
        case H323DeviceType_H323:
            return ZN_H323DeviceType_H323;
            break;
        default:
            break;
    }
}

ZNH323CalloutStatus nativeErrorTypeHelp::ZoomSDKH323Status(H323CalloutStatus &status){
    switch (status) {
        case H323CalloutStatus_Unknown:
            return ZN_H323Callout_Unknown;
            break;
        case H323CalloutStatus_Success:
            return ZN_H323Callout_Success;
            break;
        case H323CalloutStatus_Ring:
            return ZN_H323Callout_Ring;
            break;
        case H323CalloutStatus_Timeout:
            return ZN_H323Callout_Timeout;
            break;
        case H323CalloutStatus_Failed:
            return ZN_H323Callout_Failed;
            break;
        default:
            break;
    }
}

ZNFreeMeetingEndingReminderType nativeErrorTypeHelp::ZoomSDKFreeMeetingEndReminderType(SDKReminderType &type){
    
    switch (type) {
        case SDKReminderType_None:
            return ZN_FreeMeetingEndingReminder_NONE;
            break;
        case SDKReminderType_UpgradeSuccess:
            return ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Success;
            break;
        case SDKReminderType_UpgradeFailed:
            return ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Failed;
            break;
        case SDKReminderType_CanUpgradeAccount:
            return ZN_FreeMeetingEndingReminder_Can_UpgradeMeeting_ToPro_Once;
            break;
        case SDKReminderType_CanFreeTrial:
            return ZN_FreeMeetingEndingReminder_Can_UpgradeAccount;
            break;
        case SDKReminderType_GuestReminder:
            return ZN_FreeMeetingEndingReminder_Reminder;
            break;
        default:
            break;
    }
    
}

ZNFreeMeetingNeedUpgradeType nativeErrorTypeHelp::ZoomSDKFreeMeetingNeedUpgradeType(FreeMeetingNeedUpgradeType &type){
    
    switch (type) {
        case FreeMeetingNeedUpgradeType_NONE:
            return ZN_FreeMeetingNeedUpgradeType_NONE;
            break;
        case FreeMeetingNeedUpgradeType_BY_ADMIN:
            return ZN_FreeMeetingNeedUpgradeType_BY_ADMIN;
            break;
        case FreeMeetingNeedUpgradeType_BY_GIFTURL:
            return ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL;
            break;
        default:
            break;
    }
    
}

ZNPremeetingAPIResult nativeErrorTypeHelp::ZNSDKPreMeetingError(ZoomSDKPremeetingError &error){
    
    switch (error) {
        case ZoomSDKPremeetingError_Success:
            return ZN_PREMETAPIRET_SUCCESS;
            break;
        case ZoomSDKPremeetingError_Failed:
            return ZN_PREMETAPIRET_UNKNOW;
            break;
        case ZoomSDKPremeetingError_TimeOut:
            return ZN_PREMETAPIRET_UNKNOW;
            break;
        case ZoomSDKPremeetingError_Unknown:
            return ZN_PREMETAPIRET_UNKNOW;
            break;
        default:
            break;
    }
}

ZNDirectShareStatus nativeErrorTypeHelp::ZNSDKDirectShareStatus(DirectShareStatus &status){
    
    switch (status) {
        case DirectShareStatus_None:
            return ZN_DirectShare_Unknown;
            break;
        case DirectShareStatus_Connecting:
            return ZN_DirectShare_Connecting;
            break;
        case DirectShareStatus_InProgress:
            return ZN_DirectShare_In_Direct_Share_Mode;
            break;
        case DirectShareStatus_Ended:
            return ZN_DirectShare_Ended;
            break;
        case DirectShareStatus_NeedMeetingIDOrSharingKey:
            return ZN_DirectShare_Need_MeetingID_Or_PairingCode;
            break;
        case DirectShareStatus_WrongMeetingIDOrSharingKey:
            return ZN_DirectShare_WrongMeetingID_Or_SharingKey;
            break;
        case DirectShareStatus_NetworkError:
            return ZN_DirectShare_NetWork_Error;
            break;
        case DirectShareStatus_Unknow:
            return ZN_DirectShare_Other_Error;
            break;
        default:
            break;
    }
}

ZNShareStatus nativeErrorTypeHelp::ZNSDKShareStatus(ZoomSDKShareStatus &status){
    switch (status) {
        case ZoomSDKShareStatus_None:
            return ZN_Sharing_None;
            break;
        case ZoomSDKShareStatus_SelfBegin:
            return ZN_Sharing_Self_Send_Begin;
            break;
        case ZoomSDKShareStatus_SelfEnd:
            return ZN_Sharing_Self_Send_End;
            break;
        case ZoomSDKShareStatus_OtherBegin:
            return ZN_Sharing_Other_Share_Begin;
            break;
        case ZoomSDKShareStatus_OtherEnd:
            return ZN_Sharing_Other_Share_End;
            break;
        case ZoomSDKShareStatus_ViewOther:
            return ZN_Sharing_View_Other_Sharing;
            break;
        case ZoomSDKShareStatus_Pause:
            return ZN_Sharing_Pause;
            break;
        case ZoomSDKShareStatus_Resume:
            return ZN_Sharing_Resume;
            break;
        case ZoomSDKShareStatus_ContentTypeChange:
            return ZN_Sharing_ContentTypeChange;
            break;
        case ZoomSDKShareStatus_SelfStartAudioShare:
            return ZN_Sharing_SelfStartAudioShare;
            break;
        case ZoomSDKShareStatus_SelfStopAudioShare:
            return ZN_Sharing_SelfStopAudioShare;
            break;
        case ZoomSDKShareStatus_OtherStartAudioShare:
            return ZN_Sharing_OtherStartAudioShare;
            break;
        case ZoomSDKShareStatus_OtherStopAudioShare:
            return ZN_Sharing_OtherStopAudioShare;
            break;
        default:
            break;
    }
}

ZNUserRole nativeErrorTypeHelp::ZNSDKUserRole(UserRole &role){
    switch (role) {
        case UserRole_None:
            return ZN_USERROLE_NONE;
            break;
        case UserRole_Host:
            return ZN_USERROLE_HOST;
            break;
        case UserRole_CoHost:
            return ZN_USERROLE_COHOST;
            break;
        case UserRole_Attendee:
            return ZN_USERROLE_ATTENDEE;
            break;
        case UserRole_Panelist:
            return ZN_USERROLE_PANELIST;
            break;
        case UserRole_BreakoutRoom_Moderator:
            return ZN_USERROLE_BREAKOUTROOM_MODERATOR;
            break;
        default:
            break;
    }
}
