

#import <Foundation/Foundation.h>
#import "Header_include.h"
NS_ASSUME_NONNULL_BEGIN
@interface meetingServiceDelegate : NSObject<ZoomSDKMeetingServiceDelegate,ZoomSDKMeetingUIControllerDelegate,ZoomSDKMeetingActionControllerDelegate,ZoomSDKH323HelperDelegate,ZoomSDKASControllerDelegate,ZoomSDKRealNameAuthenticationDelegate>

@property(nonatomic,strong)ZoomSDKRetrieveSMSVerificationCodeController *retriveController;
@property(nonatomic,strong)ZoomSDKVerifySMSVerificationCodeController *verifyCintroller;

+(meetingServiceDelegate *)share;
-(ZoomSDKRetrieveSMSVerificationCodeController *)getRetriveController;
-(ZoomSDKVerifySMSVerificationCodeController *)getVerifyCintroller;
-(BOOL)getResendRetriveController;
-(BOOL)getReVerifyCintroller;
@end

NS_ASSUME_NONNULL_END
