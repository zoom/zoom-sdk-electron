
#ifdef  __OBJC__
#import "Header_include.h"
#endif
#include "../zoom_native_sdk_wrap_core_def.h"

class nativeErrorTypeHelp {
    
public:
    nativeErrorTypeHelp();
    ~nativeErrorTypeHelp();
    ZNSDKError ZoomSDKErrorType(ZoomSDKError &error);
    ZNAuthResult ZoomSDKAuthErrorTpye(ZoomSDKAuthError &error);
    ZNLOGINSTATUS ZoomSDKLoginStatusType(ZoomSDKLoginStatus &status);
    
    ZNSDKUserType ZoomSDKUserTypeChange(ZoomSDKUserType &type);
    ZoomSDKUserType ZNSDKUserTypeChange(ZNSDKUserType &type);
    SDKUserType  SDKUserTypeChange(ZNZoomUserType &type);
    LeaveMeetingCmd  ZoomSDKLeaveMeetingCmd(ZNLeaveMeetingCmd &cmd);
    
    NSString *ZNSDKLanaguageChanage(ZNSDK_LANGUAGE_ID &lanaguageid);
    ZNMeetingStatus  ZNSDKMeetingStatus(ZoomSDKMeetingStatus &status);
    ZoomSDKMeetingStatus ZoomSDKMeetingStatusC(ZNMeetingStatus  &status);
    
    ZNMeetingType ZNSDKMeetingType(MeetingType &type);
    ZNConnectionQuality  ZNSDKConnectionQuatity(ZoomSDKConnectionQuality &quatity);
    ZNSDKViewType  ZNSDKViewTypeC(ScreenType &type);
    ScreenType  ZoomSDKScreenViewType(ZNSDKViewType &type);
    AnnotationToolType  ZoomSDKAnnotationToolType(ZNAnnotationToolType &type);
    AnnotationClearType  ZoomSDKAnnotationClearType(ZNAnnotationClearType &type);
    
    ZNAudioStatus  ZNSDKUserAudioStatus(ZoomSDKAudioStatus &status);
    H323DeviceType ZoomSDKH323DeviceType(ZNH323DeviceType &type);
    ZNH323DeviceType ZNSDKH323DeviceType(H323DeviceType &type);
    
    ZNH323CalloutStatus ZoomSDKH323Status(H323CalloutStatus &status);
    
    ZNFreeMeetingEndingReminderType ZoomSDKFreeMeetingEndReminderType(SDKReminderType &type);
    ZNFreeMeetingNeedUpgradeType  ZoomSDKFreeMeetingNeedUpgradeType(FreeMeetingNeedUpgradeType &type);
    ZNPremeetingAPIResult  ZNSDKPreMeetingError(ZoomSDKPremeetingError &error);
    ZNDirectShareStatus   ZNSDKDirectShareStatus(DirectShareStatus &status);
    ZNShareStatus  ZNSDKShareStatus(ZoomSDKShareStatus &status);
    ZNUserRole ZNSDKUserRole(UserRole &role);
    ZNMeetingFailCode  ZNSDKMeetingFailCode(ZoomSDKMeetingError &error);
    ZNMeetingEndReason  ZNSDKMeetingEndReason(EndMeetingReason &reason);
    ZoomSDKLocale ZNSDKAPPLocalType(ZNSDK_APP_Locale &local);
    ZNSMSVerificationCodeErr ZNSDKSMSVerificationCodeError(ZoomSDKSMSVerificationCodeError &code);
    ZNAudioCallbackActionInfo ZNSDKAudioCallbackAction(ZoomSDKAudioActionInfo &info);
    ZNWebinarNeedRegisterType ZNSDKWebinarNeedRegisterType(WebinarRegisterType &type);
    ZNRequiredInfoType ZNSDKRequiredInfoType(JoinMeetingReqInfoType &type);
    
};

