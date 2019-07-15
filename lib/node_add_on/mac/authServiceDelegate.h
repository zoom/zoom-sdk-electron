

#import <Foundation/Foundation.h>
#include "sdk_native_error.h"

NS_ASSUME_NONNULL_BEGIN

@interface authServiceDelegate : NSObject<ZoomSDKAuthDelegate>
@property(nonatomic,assign)ZNAuthResult authResult;
@property(nonatomic,assign)ZNLOGINSTATUS loginStatus;
+(authServiceDelegate *)share;

-(ZNAuthResult)getAuthResult;
-(ZNLOGINSTATUS)getLoginStatus;
@end

NS_ASSUME_NONNULL_END
