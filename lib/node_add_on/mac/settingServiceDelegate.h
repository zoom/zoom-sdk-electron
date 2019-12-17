

#import <Foundation/Foundation.h>
#import "Header_include.h"
NS_ASSUME_NONNULL_BEGIN
@interface settingServiceDelegate : NSObject<ZoomSDKSettingRecordDelegate,ZoomSDKSettingAudioDeviceDelegate,ZoomSDKSettingVideoDelegate>
+(settingServiceDelegate *)share;
@end
NS_ASSUME_NONNULL_END
