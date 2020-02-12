//  ======================================================================      //
//  ZMAuthentication.h                                                                                                          //
//                                                                                                                                              //
//  Last Modified on Tuesday April 24 2001                                                                      //
//  Copyright 2001 Ben Lachman                                                                                          //
//                                                                                                                                                      //
//      Thanks to Brian R. Hill <http://personalpages.tds.net/~brian_hill/>             //
//  ======================================================================      //

#import <Cocoa/Cocoa.h>
#import <Security/Authorization.h>

typedef NS_ENUM(NSUInteger, ZMRunAppleScriptResult)
{
    ZMRunAppleScriptResultSuccess,
    ZMRunAppleScriptResultCancel,
    ZMRunAppleScriptResultError
};

@interface ZMAuthentication : NSObject
{
    AuthorizationRef _authorizationRef;
    id _delegate;
}

// returns a shared instance of the class
+ sharedInstance;

- (id)delegate;
- (void)setDelegate:(id)delegate;

- (OSStatus)isAuthenticated:(NSString *)forCommand;
- (OSStatus)authenticate:(NSString *)forCommand;
- (void)deauthenticate;

- (int)getPID:(NSString *)forProcess;

- (OSStatus)executeCommand:(NSString *)pathToCommand withArgs:(NSArray *)arguments;
- (OSStatus)executeCommandSynced:(NSString *)pathToCommand withArgs:(NSArray *)arguments;
- (BOOL)killProcess:(NSString *)commandFromPS withSignal:(int)signal;

- (BOOL)authRemovePath:(NSString*)rmPath;
- (BOOL)authCopyPath:(NSString*)srcPath toPath:(NSString*)destPath;

/*
 when Macos >= 10.15, use the way of AppleScript to Authenticate Permission,
 which can avoid crash by using AuthorizationExecuteWithPrivileges in Masos 10.15.
 */
- (ZMRunAppleScriptResult)runAppleScript:(NSString *)script errorDescription:(NSString **)errorDescription;

@end


/*!
 @category NSObject(ZMAuthenticationDelegate)
 @abstract Optionally implement these delegate methods to obtain the state of the authorization object.
 */
@interface NSObject (ZMAuthenticationDelegate)

- (void)authenticationDidFinish:(int)resultCode;

- (void)authenticationDidDeauthorize:(ZMAuthentication *)authentication;

- (NSString*)authenticationGetPromptText;
@end
