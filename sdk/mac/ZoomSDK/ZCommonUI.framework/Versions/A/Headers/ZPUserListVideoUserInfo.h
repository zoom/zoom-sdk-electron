//
//  ZPUserListVideoUserInfo.h
//  SaasBeeConfUIModule
//
//  Created by Justin Fang on 2/10/12.
//  Copyright (c) 2012 Zipow. All rights reserved.
//

#import <Foundation/Foundation.h>

enum _userAudioType
{
    AUDIO_TYPE_VOIP,
    AUDIO_TYPE_TELE,
    AUDIO_TYPE_NONE,
};

@interface ZPListVideoStatus : NSObject {
    BOOL        _isSending;
    BOOL        _isSource;
    BOOL        _isReceiving;
}

@property (nonatomic, readwrite, assign)BOOL        isSending;
@property (nonatomic, readwrite, assign)BOOL        isReceiving;
@property (nonatomic, readwrite, assign)BOOL        isSource;

@end


@interface ZPListAudioStatus : NSObject {
    BOOL            _isMuted;
    BOOL            _isTalking;
    int             _type;
}
@property (nonatomic, readwrite, assign)BOOL        isMuted;
@property (nonatomic, readwrite, assign)BOOL        isTalking;
@property (nonatomic, readwrite, assign)int         type;

@end


@interface ZPUserListVideoUserInfo : NSObject {
    int                                 _userID;
    int                                 _attendeeID;
    NSString*                           _userName;
#ifndef BUILD_FOR_MIMO
    NSImage*                            _avatar;
#endif
    NSString*                           _avatarURL;
    BOOL                                _isHost;
    BOOL                                _isCoHost;
    BOOL                                _canRecord;
    BOOL                                _isRecording;
    BOOL                                _isLocalRecordingEnabled;
    BOOL                                _isPureCallInUser;
    BOOL                                _isH323User;
    BOOL                                _isTrueUser;//user this to judge if user are not h323 or pure telephone user
    BOOL                                _isRaiseHand;
    
    ZPListVideoStatus*                  _videoStatus;
    ZPListAudioStatus*                  _audioStatus;
    NSString*                           _jID;   //for webinar attendee
    BOOL                                _isInBOMeeting;
    int                                 _activeVideoOrder;
    BOOL                                _isVideoCanMutebyHost;
    BOOL                                _isVideoCanUnMutebyHost;
    BOOL                                _isSupportSwitchCamera;
    unsigned long long                  _raiseHandTimeStamp;
    BOOL                                _isClientSupportClosedCaption;
    BOOL                                _canEditClosedCaption;
    BOOL                                _isClientSupportCohost;
    BOOL                                _isInSilentMode;
    BOOL                                _isClientSupportSilentMode;
    BOOL                                _isGuest;

}

@property (nonatomic, readwrite, assign)int                                     userID;
@property (nonatomic, readwrite, assign)int                                     attendeeID;
@property (nonatomic, readwrite, copy)NSString*                                 userName;
#ifndef BUILD_FOR_MIMO
@property (nonatomic, readwrite, retain)NSImage*                                avatar;
#endif
@property (nonatomic, readwrite, copy)NSString*                                 avatarURL;
@property (nonatomic, readwrite, assign)BOOL                                    isHost;
@property (nonatomic, readwrite, assign)BOOL                                    isCoHost;
@property (nonatomic, readwrite, assign)BOOL                                    canRecord;
@property (nonatomic, readwrite, assign)BOOL                                    isRecording;
@property (nonatomic, readwrite, assign)BOOL                                    isLocalRecordingEnabled;
@property (nonatomic, readwrite, assign)BOOL                                    isPureCallInUser;
@property (nonatomic, readwrite, assign)BOOL                                    isH323User;
@property (nonatomic, readwrite, assign)BOOL                                    isTrueUser;
@property (nonatomic, readwrite, assign)BOOL                                    isRaiseHand;
@property (nonatomic, readwrite, retain)ZPListVideoStatus*                      videoStatus;
@property (nonatomic, readwrite, retain)ZPListAudioStatus*                      audioStatus;
@property (nonatomic, readwrite, retain)NSString*                               jID;
@property (nonatomic, readwrite, assign)BOOL                                    isInBOMeeting;
@property (nonatomic, readwrite, assign)int                                     activeVideoOrder;
@property (nonatomic, readwrite, assign)BOOL                                    isVideoCanMutebyHost;
@property (nonatomic, readwrite, assign)BOOL                                    isVideoCanUnMutebyHost;
@property (nonatomic, readwrite, assign)BOOL                                    isSupportSwitchCamera;
@property (nonatomic, readwrite, assign)unsigned long long                      raiseHandTimeStamp;
@property (nonatomic, readwrite, assign)BOOL                                    isClientSupportClosedCaption;
@property (nonatomic, readwrite, assign)BOOL                                    canEditClosedCaption;
@property (nonatomic, readwrite, assign)BOOL                                    isClientSupportCohost;
@property (nonatomic, readwrite, assign)BOOL                                    isInSilentMode;
@property (nonatomic, readwrite, assign)BOOL                                    isClientSupportSilentMode;
@property (nonatomic, readwrite, assign)BOOL                                    isGuest;

@end

