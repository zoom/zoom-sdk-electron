#import <Foundation/Foundation.h>
#import "Header_include.h"
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN



@interface rawdataDelegate : NSObject<ZoomSDKRendererDelegate,ZoomSDKAudioRawDataDelegate>

@property(nonatomic,assign)unsigned long long  rev_handle;
@property(nonatomic,assign)ZoomSDKRawDataType  data_type;

+(rawdataDelegate *)shareRawData;

@end


@interface ZoomNodeRenderClass : NSObject
@property(nonatomic,retain)ZoomSDKRenderer *render;
@property(nonatomic,retain)rawdataDelegate *delegate;
@end

NS_ASSUME_NONNULL_END

