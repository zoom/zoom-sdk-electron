//
//  ZoomSDK.h
//  ZoomSDK
//
//  Created by TOTTI on 7/18/16.
//  Copyright (c) 2016 Zoom Video Communications, Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>

//ZOOM SDK Errors
#import "ZoomSDKErrors.h"

//ZOOM SDK Authentication Service
#import "ZoomSDKAuthService.h"

//ZOOM SDK Meeting Service
#import "ZoomSDKMeetingService.h"

//ZOOM SDK Setting Service
#import "ZoomSDKSettingService.h"

//ZOOM SDK Pre-meeting Service
#import "ZoomSDKPremeetingService.h"

//ZOOM SDK Network Service
#import "ZoomSDKNetworkService.h"

//ZOOM SDK Custom Video UI
#import "ZoomSDKVideoContainer.h"

//ZOOM SDK Custom Share UI
#import "ZoomSDKShareContainer.h"
#import "ZoomSDKRawDataVideoSourceController.h"
#import "ZoomSDKRawDataController.h"
/**
 * Initialize the class to acquire all the services. 
 *
 * Access to the class and all the other components of the SDK by merging <ZoomSDK/ZoomSDK.h> into source code.
 * The user can preconfigure SDK client by functions in this class. Before calling initSDK:YES/NO, you should get the object of this class via sharedSDK and call the corresponding functions.
 */

typedef enum
{
    ZoomSDKLocale_Def = 0,
    ZoomSDKLocale_CN  = 1,
}ZoomSDKLocale;

@interface ZoomSDKInitParams : NSObject
{
    BOOL                        _needCustomizedUI;
    //Set whether to enable default log of which the capacity is less than 5M.
    BOOL                        _enableLog;
    //The size of the log file, the unit is MB. The size of log file is between 1 to 50M.
    int                         _logFileSize;
    //Set the locale of the App.
    ZoomSDKLocale               _appLocale;
    //Set the team identifier of certificate, zoom will verify the certificate when loading.
    NSString*                   _teamIdentifier;
    //Set the language of the App, usually if user does not specify the language, it will follow up the systematical language.
    NSString*                   _preferedLanguage;
    //Set custom localizable string file name.
    NSString*                   _customLocalizationFileName;
}
@property (assign, nonatomic) BOOL needCustomizedUI;
@property (assign, nonatomic) BOOL enableLog;
@property (assign, nonatomic) int logFileSize;
@property (assign, nonatomic) ZoomSDKLocale appLocale;
@property (retain, nonatomic) NSString *teamIdentifier;
@property (retain, nonatomic) NSString *preferedLanguage;
@property (retain, nonatomic) NSString *customLocalizationFileName;
/**
 * @brief Get the languages supported by the SDK.
 * @return The supported languages.
 */
- (NSArray*)getLanguageArray;
@end


@interface ZoomSDK : NSObject
{
    NSString               *_zoomDomain;
    ZoomSDKMeetingService  *_meetingService;
    ZoomSDKAuthService     *_authService;
    ZoomSDKSettingService  *_settingService;
    ZoomSDKPremeetingService *_premeetingService;
    ZoomSDKNetworkService    *_networkService;
    //BOOL                     _needCustomizedUI;
    ZoomSDKRawDataMemoryMode _videoRawDataMode;
    ZoomSDKRawDataMemoryMode _shareRawDataMode;
    ZoomSDKRawDataMemoryMode _audioRawDataMode;
}

@property (retain, nonatomic) NSString *zoomDomain;
//@property (assign, nonatomic) BOOL needCustomizedUI;
@property (assign, nonatomic) BOOL enableRawdataIntermediateMode;
@property (assign, nonatomic) ZoomSDKRawDataMemoryMode videoRawDataMode;
@property (assign, nonatomic) ZoomSDKRawDataMemoryMode shareRawDataMode;
@property (assign, nonatomic) ZoomSDKRawDataMemoryMode audioRawDataMode;
/**
 * @brief The sharedSDK will be instantiated only once over the lifespan of the application. Configure the client with the specified key and secret. 
 * @note Configure the client with the specified key and secret. 
 * @return A preconfigured ZOOM SDK client. 
 */
+ (ZoomSDK*)sharedSDK;

/**
* @brief This method is used to initialize Zoom SDK.
* @param customizedFlag YES means Custom UI, No ZOOM original UI.
*/
- (void)initSDK:(BOOL)customizedFlag NS_DEPRECATED_MAC(4.0, 5.2);
- (ZoomSDKError)initSDKWithParams:(ZoomSDKInitParams*)initParams NS_AVAILABLE_MAC(5.2);
/**
 * @brief Set client domain of ZOOM SDK.
 * @note The format of domain should like "zoom.us" or "www.zoom.us", please do not add the protocol "http" or "https".
 * @param domain A domain for starting/joining ZOOM meeting. 
 */
- (void)setZoomDomain:(NSString*)domain;
/**
 * @brief Get the default authentication service.
 * @note The ZOOM SDK can not be called unless the authentication service is called successfully. 
 * @return A preconfigured authentication service.
 */
- (ZoomSDKAuthService*)getAuthService;

/**
 * @brief Get the default meeting service.  
 * @return A preconfigured meeting Service
 */
- (ZoomSDKMeetingService*)getMeetingService;

/**
 * @brief Get the default meeting service.  
 * @return An object of setting service.
 */
- (ZoomSDKSettingService*)getSettingService;

/**
 * @brief Get the default pre-meeting service. 
 * @return An object of pre-meeting Service
 */
- (ZoomSDKPremeetingService*)getPremeetingService;

/**
 * @brief Get the default Network service.  
 * @return An object of Network Service
 */
- (ZoomSDKNetworkService*)getNetworkService;

/**
 * @brief Get object of controller ZoomSDKRawDataController.
 * @return If the function succeeds, it will return a ZoomSDKRawDataController object which you can use to handle raw data in meeting.
 */
- (ZoomSDKRawDataController*)getRawDataController;

/**
 * @brief Get the serial number of SDK version.
 * @return The default serial number of ZOOM SDK version.
 */
- (NSString*)getSDKVersionNumber;

/**
 * @brief Get the languages supported by the SDK. 
 * @return The supported languages.
 */
- (NSArray*)getLanguageArray NS_DEPRECATED_MAC(4.0, 5.2);

/**
 * @brief Set the language of the App.
 * @param preferLanguage Usually if user does not specify the language, it will follow up the systematical language of the device. 
 * @return If the function succeeds, it will return ZoomSDKError_Success, otherwise failed. 
 * @note You should call the method before calling [[ZoomSDK sharedSDK]initSDK:NO/YES] in the App, or no, you should restart the App once you reset the preferred Language.
 */
- (ZoomSDKError)setPreferLanguage:(NSString *)preferLanguage NS_DEPRECATED_MAC(4.0, 5.2);

/**
 * @brief Set whether to enable default log of which the capacity is less than 5M.
 * @param enable YES mean enabled, NO disabled.
 * @param size The size of the log file, the unit is MB. The size of log file is between 1 to 50M.
 * @note Call Api firstly before you call [[ZoomSDK sharedSDK]initSDK:NO/YES] in the App.
 */
- (void)enableDefaultLog:(BOOL)enable NS_DEPRECATED_MAC(4.1, 4.3);
- (void)enableDefaultLog:(BOOL)enable fileSize:(unsigned int)size NS_DEPRECATED_MAC(4.4, 5.2);

/**
 * @brief Set custom localizable string file name.
 * @param fileName Specify the localizable string file name.
 */
- (void)setCustomLocalizationFileName:(NSString*)fileName NS_DEPRECATED_MAC(4.0, 5.2);

/**
 * @brief Set the locale of the App.
 * @param locale The locale you want set for the App.
 * @note You should call the method before calling [[ZoomSDK sharedSDK]initSDK:NO/YES] in the App.
 */
- (void)setAppLocale:(ZoomSDKLocale)locale NS_DEPRECATED_MAC(4.0, 5.2);

/**
 * @brief Switch to the new domain of the App.
 * @param newDomain The new domain user want to switch to.
 * @return If the function succeeds, it will return ZoomSDKError_Success, otherwise failed.
 */
- (ZoomSDKError)switchDomain:(NSString*)newDomain force:(BOOL)force;

/**
 * @brief Set support dark model to the app.
 * @param isSupport YES means support dark model,NO is not support.
 * @note Support for Mac OS 10.14 and above
 * @note Call this interface in '- (void)applicationWillFinishLaunching:(NSNotification *)notification' in the App.
 */
- (ZoomSDKError)setSupportDarkModel:(BOOL)isSupport;

/**
 * @brief Set identifier of team.
 * @param identifier Subject.OU value of the signing certificate, zoom will verify the certificate before loading.
 * @note After you re-sign the SDK, you should call this interface to set the identifier of signature. You should call the method before calling [[ZoomSDK sharedSDK]initSDK:NO/YES] in the App.
 */
- (void)setTeamIdentifier:(NSString*)identifier NS_DEPRECATED_MAC(4.0, 5.2);

@end


