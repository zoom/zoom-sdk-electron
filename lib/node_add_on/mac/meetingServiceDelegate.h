

#import <Foundation/Foundation.h>
#import "Header_include.h"
NS_ASSUME_NONNULL_BEGIN
@interface meetingServiceDelegate : NSObject<ZoomSDKMeetingServiceDelegate,ZoomSDKMeetingUIControllerDelegate,ZoomSDKMeetingActionControllerDelegate,ZoomSDKH323HelperDelegate,ZoomSDKASControllerDelegate,ZoomSDKRealNameAuthenticationDelegate,ZoomSDKWebinarControllerDelegate>


+(meetingServiceDelegate *)share;
-(ZoomSDKRetrieveSMSVerificationCodeController *)getRetriveController;
-(ZoomSDKVerifySMSVerificationCodeController *)getVerifyCintroller;
-(BOOL)getResendRetriveController;
-(BOOL)getReVerifyCintroller;
-(ZoomSDKWebinarRegisterHelper *)getWebinarRegisterHelper;
-(ZoomSDKJoinMeetingHelper *)getJoinMeetingHelper;
@end

NS_ASSUME_NONNULL_END
