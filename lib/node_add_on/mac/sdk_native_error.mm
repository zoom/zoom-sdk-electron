


#include "sdk_native_error.h"

nativeErrorTypeHelp::nativeErrorTypeHelp(){
    
}
nativeErrorTypeHelp::~nativeErrorTypeHelp(){
    
}
#pragma mark  zoom error
ZNSDKError nativeErrorTypeHelp::ZoomSDKErrorType(ZoomSDKError &error){
    if (error == ZoomSDKError_Success) {
        return ZNSDKERR_SUCCESS;
    }
    if (error == ZoomSDKError_Failed) {
        return ZNSDKERR_MEMORY_FAILED;
    }
    if (error == ZoomSDKError_UnKnow) {
        return ZNSDKERR_UNKNOWN;
    }
    
    if (error == ZoomSDKError_Uninit) {
        return ZNSDKERR_UNINITIALIZE;
    }
    if (error == ZoomSDKError_ServiceFailed) {
        return ZNSDKERR_SERVICE_FAILED;
    }
    if (error == ZoomSDKError_WrongUsage) {
        return ZNSDKERR_WRONG_USEAGE;
    }
    if (error == ZoomSDKError_InvalidPrameter) {
        return ZNSDKERR_INVALID_PARAMETER;
    }
    if (error == ZoomSDKError_NoPermission) {
        return ZNSDKERR_NO_PERMISSION;
    }
    if (error == ZoomSDKError_NoRecordingInProgress) {
        return ZNSDKERR_NORECORDINGINPROCESS;
    }
    
    if (error == ZoomSDKError_UnKnow) {
        return ZNSDKERR_UNKNOWN;
    }
    return ZNSDKERR_UNKNOWN;
}
#pragma mark  auth error
ZNAuthResult nativeErrorTypeHelp::ZoomSDKAuthErrorTpye(ZoomSDKAuthError &error){
    if (error == ZoomSDKAuthError_Success) {
        return ZNAUTHRET_SUCCESS;
    }
    if (error == ZoomSDKAuthError_KeyOrSecretWrong) {
        return ZNAUTHRET_KEYORSECRETWRONG;
    }
    if (error == ZoomSDKAuthError_AccountNotSupport) {
        return ZNAUTHRET_ACCOUNTNOTSUPPORT;
    }
    if (error == ZoomSDKAuthError_AccountNotEnableSDK) {
        return ZNAUTHRET_ACCOUNTNOTENABLESDK;
    }
    if (error == ZoomSDKAuthError_Unknown) {
        return ZNAUTHRET_UNKNOWN;
    }
    return ZNAUTHRET_UNKNOWN;
}

#pragma mark  login status
ZNLOGINSTATUS nativeErrorTypeHelp::ZoomSDKLoginStatusType(ZoomSDKLoginStatus &status){
    if (status == ZoomSDKLoginStatus_Idle) {
        return ZNLOGIN_IDLE;
    }
    if (status == ZoomSDKLoginStatus_Success){
        return ZNLOGIN_SUCCESS;
    }
    if (status == ZoomSDKLoginStatus_Failed) {
        return ZNLOGIN_FAILED;
    }
    if (status == ZoomSDKLoginStatus_Processing){
        return ZNLOGIN_PROCESSING;
    }
    return ZNLOGIN_FAILED;
}
#pragma mark user type
ZNSDKUserType nativeErrorTypeHelp::ZoomSDKUserTypeChange(ZoomSDKUserType &type){
    if (type == ZoomSDKUserType_APIUser) {
        return ZNSDK_UT_APIUSER;
    }
    if (type == ZoomSDKUserType_ZoomUser) {
        return ZNSDK_UT_NORMALUSER;
    }
    if (type == ZoomSDKUserType_SSOUser) {
        return ZNSDK_UT_WITHOUT_LOGIN;
    }
    
    return ZNSDK_UT_NORMALUSER;
}

ZoomSDKUserType nativeErrorTypeHelp::ZNSDKUserTypeChange(ZNSDKUserType &type){
    if (type == ZNSDK_UT_WITHOUT_LOGIN) {
        return ZoomSDKUserType_SSOUser;
    }
    
    if (type == ZNSDK_UT_NORMALUSER) {
        return ZoomSDKUserType_ZoomUser;
    }
    if (type == ZNSDK_UT_APIUSER) {
        return ZoomSDKUserType_APIUser;
    }
    
    return ZoomSDKUserType_ZoomUser;
}

SDKUserType  nativeErrorTypeHelp::SDKUserTypeChange(ZNZoomUserType &type){
    
    if (type == ZNZoomUserType_APIUSER) {
        return SDKUserType_APIUser;
    }
    if (type == ZNZoomUserType_EMAIL_LOGIN) {
        return SDKUserType_EmailLogin;
    }
    if (type == ZNZoomUserType_FACEBOOK) {
        return SDKUserType_FaceBook;
    }
    if (type == ZNZoomUserType_GoogleOAuth) {
        return SDKUserType_GoogleOAuth;
    }
    if (type == ZNZoomUserType_SSO) {
        return SDKUserType_SSO;
    }
    if (type == ZNZoomUserType_Unknown) {
        return SDKUserType_Unknown;
    }
    return SDKUserType_Unknown;
}

LeaveMeetingCmd nativeErrorTypeHelp::ZoomSDKLeaveMeetingCmd(ZNLeaveMeetingCmd &cmd){
    if (cmd == ZNLEAVE_MEETING) {
        
        return LeaveMeetingCmd_Leave;
    }
    
    if (cmd == ZNEND_MEETING) {
        return LeaveMeetingCmd_End;
    }
    
    return LeaveMeetingCmd_End;
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
