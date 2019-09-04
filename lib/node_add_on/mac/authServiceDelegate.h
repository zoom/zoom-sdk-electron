

#import <Foundation/Foundation.h>
#include "sdk_native_error.h"
NS_ASSUME_NONNULL_BEGIN

@interface authServiceDelegate : NSObject<ZoomSDKAuthDelegate,ZoomSDKPremeetingServiceDelegate,ZoomSDKDirectShareHelperDelegate>
@property(nonatomic,assign)ZNAuthResult authResult;
@property(nonatomic,assign)ZNLOGINSTATUS loginStatus;
@property(nonatomic,assign)DirectShareStatus  directStatus;
@property(nonatomic,strong)ZoomSDKDirectShareHandler *DirectShareHandler;

+(authServiceDelegate *)share;

-(ZNAuthResult)getAuthResult;
-(ZNLOGINSTATUS)getLoginStatus;
-(DirectShareStatus)getDirectShare;
-(ZoomSDKDirectShareHandler *)getDirectShareHandler;
@end

NS_ASSUME_NONNULL_END
