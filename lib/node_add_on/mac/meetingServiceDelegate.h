

#import <Foundation/Foundation.h>

#import "Header_include.h"
NS_ASSUME_NONNULL_BEGIN

@interface meetingServiceDelegate : NSObject<ZoomSDKMeetingServiceDelegate,ZoomSDKMeetingUIControllerDelegate,ZoomSDKMeetingActionControllerDelegate,ZoomSDKH323HelperDelegate,ZoomSDKASControllerDelegate>

+(meetingServiceDelegate *)share;
@end

NS_ASSUME_NONNULL_END
