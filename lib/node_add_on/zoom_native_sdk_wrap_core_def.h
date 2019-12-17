#ifndef _zoom_native_sdk_wrap_core_def_h_
#define _zoom_native_sdk_wrap_core_def_h_
#include <string>
#include <vector>
#if (defined BUILD_WIN)
#define ZoomSTRING std::wstring
#else
#define ZoomSTRING std::string
#endif
#ifdef BUILD_WIN
#define ZOOM_HIDE_SYMBOL
#else
#define ZOOM_HIDE_SYMBOL __attribute__((visibility("hidden")))
#endif

enum ZNSDKError
{
	
	ZNSDKERR_SUCCESS = 0,///<Success.
	ZNSDKERR_NO_IMPL,///<This feature is currently invalid. 
	ZNSDKERR_WRONG_USEAGE,///<Incorrect usage of the feature. 
	ZNSDKERR_INVALID_PARAMETER,///<Wrong parameter.
	ZNSDKERR_MODULE_LOAD_FAILED,///<Loading module failed.
	ZNSDKERR_MEMORY_FAILED,///<No memory is allocated. 
	ZNSDKERR_SERVICE_FAILED,///<Internal service error.
	ZNSDKERR_UNINITIALIZE,///<Not initialized before the usage.
	ZNSDKERR_UNAUTHENTICATION,///<Not authorized before the usage.
	ZNSDKERR_NORECORDINGINPROCESS,///<No recording in process.
	ZNSDKERR_TRANSCODER_NOFOUND,///<Transcoder module is not found.
	ZNSDKERR_VIDEO_NOTREADY,///<The video service is not ready.
	ZNSDKERR_NO_PERMISSION,///<No permission.
	ZNSDKERR_UNKNOWN,///<Unknown error.
	ZNSDKERR_OTHER_SDK_INSTANCE_RUNNING,///<The other instance of the SDK is in process.
	ZNSDKERR_INTELNAL_ERROR,///<SDK internal error.
	ZNSDKERR_NO_AUDIODEVICE_ISFOUND,///<No audio device found.
	ZNSDKERR_NO_VIDEODEVICE_ISFOUND,///<No video device found.
	ZNSDKERR_TOO_FREQUENT_CALL,///<API calls too frequently.
	ZNSDKERR_FAIL_ASSIGN_USER_PRIVILEGE, ///<User can't be assigned with new privilege.
	ZNSDKERR_MEETING_DONT_SUPPORT_FEATURE,///<The current meeting doesn't support the feature.
	ZNSDKERR_MEETING_NOT_SHARE_SENDER,///<The current user is not the presenter.
	ZNSDKERR_MEETING_YOU_HAVE_NO_SHARE,///<There is no sharing.
	ZNSDKERR_MEETING_VIEWTYPE_PARAMETER_IS_WRONG, ///<Incorrect ViewType parameters.
	ZNSDKERR_MEETING_ANNOTATION_IS_OFF, ///<Annotation is disabled.
	ZNSDKERR_SETTING_OS_DONT_SUPPORT, ///<Current OS doesn't support the setting.
};
enum ZNSDK_LANGUAGE_ID
{
	ZNLANGUAGE_Unknow = 0,///<For initialization.
	ZNLANGUAGE_English,///<In English.
	ZNLANGUAGE_Chinese_Simplified,///<In simplified Chinese.
	ZNLANGUAGE_Chinese_Traditional,///<In traditional Chinese.
	ZNLANGUAGE_Japanese,///<In Japanese.
	ZNLANGUAGE_Spanish,///<In Spanish.
	ZNLANGUAGE_German,///<In German.
	ZNLANGUAGE_French,///<In French.
	ZNLANGUAGE_Portuguese,///<In Portuguese.
	ZNLANGUAGE_Russian,///<In Russian.
};

enum ZNAuthResult
{
	ZNAUTHRET_SUCCESS = 0,///<Authentication is successful.
	ZNAUTHRET_KEYORSECRETEMPTY,///<The key or secret to authenticate is empty.
	ZNAUTHRET_KEYORSECRETWRONG,///<The key or secret to authenticate is wrong.
	ZNAUTHRET_ACCOUNTNOTSUPPORT,///<The user account does not support.
	ZNAUTHRET_ACCOUNTNOTENABLESDK,///<The user account is not enabled for SDK.
	ZNAUTHRET_UNKNOWN,///<Unknown error.
	ZNAUTHRET_SERVICE_BUSY,///<Service is busy.
	ZNAUTHRET_NONE,///<Initial status.
	ZNAUTHRET_OVERTIME,///<Time out.
	ZNAUTHRET_NETWORKISSUE,///<Network issues.
};
enum ZNCustomizedLanguageType
{
	ZN_CustomizedLanguage_None,///<No use of the custom resource.
	ZN_CustomizedLanguage_FilePath,///<Use the specified file path to assign the custom resource.
	ZN_CustomizedLanguage_Content,///<Use the specified content to assign the custom resource.
};
typedef struct _ZNCustomizedLanguageInfo
{
	ZoomSTRING langName;///<Resource name.
	ZoomSTRING langInfo;///<The value should be the full path of the resource file when the langType value is CustomizedLanguage_FilePath, including the file name. When the langType value is CustomizedLanguage_Content, the value saves the content of the resource.
	ZNCustomizedLanguageType langType;///<Use the custom resource type.
	_ZNCustomizedLanguageInfo()
	{
		langType = ZN_CustomizedLanguage_None;
	}

}ZNCustomizedLanguageInfo;
typedef struct _ZNConfigurableOptions
{
	ZNCustomizedLanguageInfo customizedLang;///<The custom resource information.
	int optionalFeatures;///<Additional functional configuration. The function currently supports only whether to use the custom UI mode. When the value of the optionalFeatures&ENABLE_CUSTOMIZED_UI_FLAG is TRUE, it means to the Use the custom UI mode. Otherwise use the traditional interface mode.
	_ZNConfigurableOptions()
	{
		optionalFeatures = 0;
	}

}ZNConfigurableOptions;

enum ZNSDK_APP_Locale
{
	ZNSDK_APP_Locale_Default,
	ZNSDK_APP_Locale_CN,
};
typedef struct _ZNInitParam
{
	ZoomSTRING path;///<The path of sdk.dll
	ZoomSTRING domain;///<Web domain.
	bool enable_log;///<Enable log feature.
	ZNSDK_LANGUAGE_ID langid;///<The ID of the language.
	ZoomSTRING strSupportUrl;///<Support URL.
	ZoomSTRING strBrandingName;///<Branding name.
	ZNConfigurableOptions obConfigOpts;///<The configuration options of the SDK.
	ZNSDK_APP_Locale locale;
	_ZNInitParam(){
		enable_log = true;
		langid = ZNLANGUAGE_English;
		locale = ZNSDK_APP_Locale_Default;
	}
}ZNInitParam;

typedef struct _ZNAuthParam
{
	ZoomSTRING sdk_key;///<APP Key string.
	ZoomSTRING sdk_secret;///<APP Secret string.
}ZNAuthParam;

typedef struct _ZNAuthContext
{
	ZoomSTRING sdk_jwt_token;///<Jwt token.
}ZNAuthContext;

typedef struct _ZNLoginParam
{
	ZoomSTRING user_name;///<Username. It is usually working mailbox or other mailbox.
	ZoomSTRING psw;///<Account password.
	ZoomSTRING ssotoken;///<Account SSO token when logging.
	bool remember_me;///<True indicates to save the information for next login.
	_ZNLoginParam() {
		remember_me = false;
	}
}ZNLoginParam;

enum ZNLOGINSTATUS
{
	ZNLOGIN_IDLE = 0,///<Unlogged in.
	ZNLOGIN_PROCESSING,///<In process of login.
	ZNLOGIN_SUCCESS,///<Login successful.
	ZNLOGIN_FAILED,///<Login failed.
};

enum ZNLoginType
{
	ZNLoginType_Unknown = 0,///<Unknown type.
	ZNLoginType_Email,///<Login with work mailbox.
	ZNLoginType_SSO,///<Login with SSO token.
};

typedef struct _ZNAccountInfo {
	ZoomSTRING dispaly_name;///<The screen name of user.
	ZNLoginType login_type;///<The login type.
}ZNAccountInfo;
enum ZNMeetingFailCode
{
	ZNMEETING_SUCCESS = 0,///<Start meeting successfully.
	ZNMEETING_FAIL_NETWORK_ERR = 1,///<Network error.
	ZNMEETING_FAIL_RECONNECT_ERR = 2,///<Reconnect error.
	ZNMEETING_FAIL_MMR_ERR = 3,///<Multi-media Router error.
	ZNMEETING_FAIL_PASSWORD_ERR = 4,///<Password is wrong.
	ZNMEETING_FAIL_SESSION_ERR = 5,///<Session error.
	ZNMEETING_FAIL_MEETING_OVER = 6,///<Meeting is over.
	ZNMEETING_FAIL_MEETING_NOT_START = 7,///<Meeting has not begun.
	ZNMEETING_FAIL_MEETING_NOT_EXIST = 8,///<Meeting does not exist.
	ZNMEETING_FAIL_MEETING_USER_FULL = 9,///<The capacity of meeting is full.
	ZNMEETING_FAIL_CLIENT_INCOMPATIBLE = 10,///<The client is incompatible.
	ZNMEETING_FAIL_NO_MMR = 11,///<The Multi-media router is not founded. 
	ZNMEETING_FAIL_CONFLOCKED = 12,///<The meeting is locked.
	ZNMEETING_FAIL_MEETING_RESTRICTED = 13,///<The meeting is failed because of the restriction by the same account.
	ZNMEETING_FAIL_MEETING_RESTRICTED_JBH = 14,///<The meeting is restricted by the same account while the attendee is allowed to join before the host.
	ZNMEETING_FAIL_CANNOT_EMIT_WEBREQUEST = 15,///<Unable to send web request.
	ZNMEETING_FAIL_CANNOT_START_TOKENEXPIRE = 16,///The token is expired.
	ZNSESSION_VIDEO_ERR = 17,///<Video hardware or software error.
	ZNSESSION_AUDIO_AUTOSTARTERR = 18,///<Audio autostart error.
	ZNMEETING_FAIL_REGISTERWEBINAR_FULL = 19,///<The number of webinar registered has reached the upper limit.
	ZNMEETING_FAIL_REGISTERWEBINAR_HOSTREGISTER = 20,///<Register webinar with the role of webinar host.
	ZNMEETING_FAIL_REGISTERWEBINAR_PANELISTREGISTER = 21,///<Register webinar with the role of panelist member.
	ZNMEETING_FAIL_REGISTERWEBINAR_DENIED_EMAIL = 22,///<Register webinar with the denied email.
	ZNMEETING_FAIL_ENFORCE_LOGIN = 23,///<Webinar request to login.
	ZNCONF_FAIL_ZC_CERTIFICATE_CHANGED = 24,  ///<Invalid for Windows SDK.
	ZNCONF_FAIL_VANITY_NOT_EXIST = 27, ///<Vanity conference ID does not exist.
	ZNCONF_FAIL_JOIN_WEBINAR_WITHSAMEEMAIL = 28, ///<Join webinar with the same email.
	ZNCONF_FAIL_DISALLOW_HOST_MEETING = 29, ///<Meeting settings is not allowed to start a meeting.
	ZNMEETING_FAIL_WRITE_CONFIG_FILE = 50,	///<Disabled to write the configure file.
	ZNMEETING_FAIL_FORBID_TO_JOIN_INTERNAL_MEETING = 60, ///<Forbidden to join the internal meeting.
	ZNCONF_FAIL_REMOVED_BY_HOST = 61, ///<Removed by the host. 
};
enum ZNMeetingEndReason
{
	ZNEndMeetingReason_None = 0,
	ZNEndMeetingReason_KickByHost = 1,
	ZNEndMeetingReason_EndByHost = 2,
	ZNEndMeetingReason_JBHTimeOut = 3,
	ZNEndMeetingReason_NoAttendee = 4,
	ZNEndMeetingReason_HostStartAnotherMeeting = 5,
	ZNEndMeetingReason_FreeMeetingTimeOut = 6,
	ZNEndMeetingReason_NetworkBroken,
};
enum ZNMeetingStatus
{
	ZNMEETING_STATUS_IDLE = 0,///<No meeting is running.
	ZNMEETING_STATUS_CONNECTING,///<Connect to the meeting server status.
	ZNMEETING_STATUS_WAITINGFORHOST,///<Waiting for the host to start the meeting.
	ZNMEETING_STATUS_INMEETING,///<Meeting is ready, in meeting status.
	ZNMEETING_STATUS_DISCONNECTING,///<Disconnect the meeting server, leave meeting status.
	ZNMEETING_STATUS_RECONNECTING,///<Reconnecting meeting server status.
	ZNMEETING_STATUS_FAILED,///<Failed to connect the meeting server.
	ZNMEETING_STATUS_ENDED,///<Meeting ends.
	ZNMEETING_STATUS_UNKNOW,///<Unknown status.
	ZNMEETING_STATUS_LOCKED,///<Meeting is locked to prevent the further participants to join the meeting.
	ZNMEETING_STATUS_UNLOCKED,///<Meeting is open and participants can join the meeting. 
	ZNMEETING_STATUS_IN_WAITING_ROOM,///<Participants who join the meeting before the start are in the waiting room.
	ZNMEETING_STATUS_WEBINAR_PROMOTE,///<Upgrade the attendees to panelist in webinar.
	ZNMEETING_STATUS_WEBINAR_DEPROMOTE,///<Downgrade the attendees from the panelist.
	ZNMEETING_STATUS_JOIN_BREAKOUT_ROOM,///<Join the breakout room.
	ZNMEETING_STATUS_LEAVE_BREAKOUT_ROOM,///<Leave the breakout room.
	ZNMEETING_STATUS_AUDIO_READY,///<Audio is ready.
	ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS,///Other meeting is in progress.
	ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY,///<Waiting for the additional secret key.
};
enum ZNSDKUserType
{
	ZNSDK_UT_APIUSER = 99,///<API user type, quits later.
	ZNSDK_UT_NORMALUSER = 100,///<Type of ordinary user who needs to login.
	ZNSDK_UT_WITHOUT_LOGIN,///<Start meeting without login.
};
enum ZNZoomUserType
{
	ZNZoomUserType_APIUSER,///<API user.
	ZNZoomUserType_EMAIL_LOGIN,///<User logged in with email.
	ZNZoomUserType_FACEBOOK,///<User logged in with Facebook.
	ZNZoomUserType_GoogleOAuth,///<User logged in with Google.
	ZNZoomUserType_SSO,///<User logged in with SSO.
	ZNZoomUserType_Unknown,///<User of unknown type.
};
typedef struct _ZNStartParam
{
	ZNSDKUserType userType;///<SDK user type. For more details, see \link ZNSDKUserType \endlink enum.
	unsigned long long meetingNumber;///<Meeting number.
	ZoomSTRING hDirectShareAppWnd;///<The window handle of the direct sharing application.
	ZoomSTRING participantId;///<The ID of attendees. The SDK will set this value when the associated settings are turned on.
	ZoomSTRING userId;///<User ID.
	ZoomSTRING userToken;///<User token
	ZoomSTRING username;///<Username when logged in.
	ZoomSTRING sdkVanityID;///<Meeting vanity ID.
	ZoomSTRING userZAK;///<ZOOM access token.
	ZNZoomUserType zoomUserType;///<Zoom user type. For more details, see \link ZNZoomUserType \endlink enum.
	bool isVideoOff;///<Turn off the video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	bool isAudioOff;///<Turn off the audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	bool isDirectShareDesktop;///<Share the desktop directly or not. True indicates to share.
	_ZNStartParam() {
		userType = ZNSDK_UT_APIUSER;
	}
}ZNStartParam;
typedef struct _ZNJoinParam
{
	ZNSDKUserType userType;///<SDK user type. For more details, see \link ZNSDKUserType \endlink enum.
	unsigned long long meetingNumber;///<Meeting number.
	ZoomSTRING hDirectShareAppWnd;///<The window handle of the direct sharing application.
	ZoomSTRING participantId;///<The ID of attendees. The SDK will set this value when the associated settings are turned on.
	ZoomSTRING userId;///<User ID.
	ZoomSTRING userToken;///<User token
	ZoomSTRING username;///<Username when logged in.
	ZoomSTRING psw;///<Meeting password.
	ZoomSTRING vanityID;///<Meeting vanity ID.
	ZoomSTRING webinarToken;///<Webinar token.
	ZoomSTRING token4EnforceLogin;///<Use the token if the meeting requests to login.
	ZoomSTRING displayID;
	bool isVideoOff;///<Turn off the video or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	bool isAudioOff;///<Turn off the audio or not. True indicates to turn off. In addition, this flag is affected by meeting attributes.
	bool isDirectShareDesktop;///<Share the desktop directly or not. True indicates to share.
	_ZNJoinParam() {
		userType = ZNSDK_UT_APIUSER;
	}
}ZNJoinParam;
enum ZNLeaveMeetingCmd
{
	ZNLEAVE_MEETING,///<Leave meeting
	ZNEND_MEETING,///<End meeting
};
enum ZNMeetingType
{
	ZNMEETING_TYPE_NONE,///<For initialization.
	ZNMEETING_TYPE_NORMAL,///<Ordinary meeting.
	ZNMEETING_TYPE_WEBINAR,///<Webinar.
	ZNMEETING_TYPE_BREAKOUTROOM,///<Breakout meeting.
};
enum ZNConnectionQuality
{
	ZNConn_Quality_Unknow,///<Unknown connection status
	ZNConn_Quality_Very_Bad,///<The connection quality is very poor.
	ZNConn_Quality_Bad,///<The connection quality is poor. 
	ZNConn_Quality_Not_Good,///<The connection quality is not good.
	ZNConn_Quality_Normal,///<The connection quality is normal.
	ZNConn_Quality_Good,///<The connection quality is good.
	ZNConn_Quality_Excellent,///<The connection quality is excellent.
};
typedef struct _ZNShowChatDlgParam
{
	ZoomSTRING hParent;///<Parent window handle.
	ZoomSTRING rect_top;
	ZoomSTRING rect_bottom;
	ZoomSTRING rect_left;
	ZoomSTRING rect_right;
	ZoomSTRING hChatWnd;///<Chat dialog handle.
}ZNShowChatDlgParam;
enum ZNSDKFloatVideoType
{
	ZN_FLOATVIDEO_List,///<Type of list.
	ZN_FLOATVIDEO_Small,///<Small. 
	ZN_FLOATVIDEO_Large,///<Large.
	ZN_FLOATVIDEO_Minimize,///<Minimized.
};
typedef struct _ZNVideoWallPageInfoParam
{
	ZoomSTRING currentPage;///<The page in video wall mode for the moment.
	ZoomSTRING totalPages;///<The total number of pages in video wall mode.
}ZNVideoWallPageInfoParam;
typedef struct _ZNSplitScreenInfo
{
	bool bZNSupportSplitScreen;///<The page in video wall mode for the moment.
	bool bZNInSplitScreenMode;///<The total number of pages in video wall mode.
	_ZNSplitScreenInfo()
	{
		bZNSupportSplitScreen = false;
		bZNInSplitScreenMode = false;
	}
}ZNSplitScreenInfo;
enum ZNSDKViewType
{
	ZNSDK_FIRST_VIEW,///Primary displayer.
	ZNSDK_SECOND_VIEW,///<Secondary displayer.
};
enum ZNAnnotationToolType
{
	ZN_ANNOTOOL_NONE_DRAWING,///<Switch to mouse cursor.

	ZN_ANNOTOOL_PEN,///<Pen.
	ZN_ANNOTOOL_HIGHLIGHTER,///<Highlighter.
	ZN_ANNOTOOL_AUTO_LINE,///<A straight line changes automatically in pace with the mouse cursor.
	ZN_ANNOTOOL_AUTO_RECTANGLE,///<A rectangle changes automatically in pace with the mouse cursor.
	ZN_ANNOTOOL_AUTO_ELLIPSE,///<An ellipse changes automatically in pace with the mouse cursor.
	ZN_ANNOTOOL_AUTO_ARROW,///<An arrow changes automatically in pace with the mouse cursor.
	ZN_ANNOTOOL_AUTO_RECTANGLE_FILL,///<A filled rectangle.
	ZN_ANNOTOOL_AUTO_ELLIPSE_FILL,///<A filled ellipse.
	ZN_ANNOTOOL_SPOTLIGHT,///<Laser pointer.
	ZN_ANNOTOOL_ARROW,///<An arrow showing the name of whom click on the sharing content.
	ZN_ANNOTOOL_ERASER,///<An eraser.

	ZN_ANNOTOOL_TEXTBOX, ///<Insert a textbox in order to input letters.
	ZN_ANNOTOOL_PICKER, ///<Select the annotations.
	ZN_ANNOTOOL_AUTO_RECTANGLE_SEMI_FILL, ///<A fair rectangle changes automatically in pace with the mouse cursor.
	ZN_ANNOTOOL_AUTO_ELLIPSE_SEMI_FILL, ///<A fair ellipse changes automatically in pace with the mouse cursor.
	ZN_ANNOTOOL_AUTO_DOUBLE_ARROW, ///<A line with double-arrow. 
	ZN_ANNOTOOL_AUTO_DIAMOND, ///<An unfilled rhombus.
	ZN_ANNOTOOL_AUTO_STAMP_ARROW, ///<A fixed-size arrow for marking.
	ZN_ANNOTOOL_AUTO_STAMP_CHECK, ///<A sign marking that something is correct.
	ZN_ANNOTOOL_AUTO_STAMP_X, ///<A sign marking that something is wrong.
	ZN_ANNOTOOL_AUTO_STAMP_STAR, ///<A star for marking.
	ZN_ANNOTOOL_AUTO_STAMP_HEART, ///<A heart for marking.
	ZN_ANNOTOOL_AUTO_STAMP_QM, ///<A sign for interrogation.
};
enum ZNAnnotationClearType
{
	ZN_ANNOCLEAR_ALL,///<Clear all annotations.
	ZN_ANNOCLEAR_SELF,///<Clear only your own annotations.
	ZN_ANNOCLEAR_OTHER,///<Clear only the others' annotations.
};
enum ZNAudioStatus
{
	ZN_Audio_None,///<Initialization.
	ZN_Audio_Muted,///<Muted status.
	ZN_Audio_UnMuted,///<Unmuted status.
	ZN_Audio_Muted_ByHost,///<Muted by the host.
	ZN_Audio_UnMuted_ByHost,///<Unmuted by the host.
	ZN_Audio_MutedAll_ByHost,///<The host mutes all.
	ZN_Audio_UnMutedAll_ByHost,///<The host unmutes all.
};
typedef struct _ZNUserAudioStatus
{
	unsigned int userId;///<The page in video wall mode for the moment.
	ZNAudioStatus audioStauts;///<The total number of pages in video wall mode.
}ZNUserAudioStatus;
enum ZNVideoStatus
{
	ZN_Video_ON, ///<Video is on.
	ZN_Video_OFF, ///<Video is off.
};
enum ZNShareStatus
{
	ZN_Sharing_None,///<For initialization.
	ZN_Sharing_Self_Send_Begin,///<Begin to share by the user himself.
	ZN_Sharing_Self_Send_End,///<Stop sharing by the user.
	ZN_Sharing_Other_Share_Begin,///<Others begin to share.
	ZN_Sharing_Other_Share_End,///<Others stop sharing.
	ZN_Sharing_View_Other_Sharing,///<View the sharing of others.
	ZN_Sharing_Pause,///<Pause sharing.
	ZN_Sharing_Resume,///<Resume sharing.
	ZN_Sharing_ContentTypeChange,///<Sharing content changes.
	ZN_Sharing_SelfStartAudioShare,///<The current user begins to share the sounds of computer audio.
	ZN_Sharing_SelfStopAudioShare,///<The current user stops to share the sounds of computer audio.
	ZN_Sharing_OtherStartAudioShare,///<Other user begins to share the sounds of computer audio.
	ZN_Sharing_OtherStopAudioShare,///<Other user stops to share the sounds of computer audio.
};
typedef struct _ZNCameraInfo
{
	ZoomSTRING deviceId; ///<The camera device ID.
	ZoomSTRING deviceName;///<The camera device name.
	bool isSelectedDevice;///<Is the current device is selected to use or not.
}ZNCameraInfo;
typedef struct _ZNMicInfo
{
	ZoomSTRING deviceId;///<The microphone device ID.
	ZoomSTRING deviceName;///<The microphone device name.
	bool isSelectedDevice;///<Is the current device is selected to use or not.
}ZNMicInfo;
typedef struct _ZNSpeakerInfo
{
	ZoomSTRING deviceId;///<The speaker device ID.
	ZoomSTRING deviceName;///<The speaker device name.
	bool isSelectedDevice;///<Is the current device is selected to use or not.
}ZNSpeakerInfo;
enum ZNSettingTabPage
{
	ZN_SettingTabPage_General,///<General setting page.
	ZN_SettingTabPage_Audio,///<Audio setting page.
	ZN_SettingTabPage_Video,///<Video setting page.
};
typedef struct _ZNShowSettingDlgParam
{
	ZoomSTRING hParent;///<Parent window handle.
	ZoomSTRING top;///<The Y-axis value of the top-left corner of the dialog uses the coordinate system of the monitor.
	ZoomSTRING left;///<The X-axis value of the top-left corner of the dialog uses the coordinate system of the monitor.
	ZoomSTRING hSettingWnd;///<Window handle of the dialog setting.
	bool bShow;///<Enable to display or nor.
	ZNSettingTabPage eTabPageType; ///<The tab page shown at the top of the displayed setting dialog.
	_ZNShowSettingDlgParam()
	{
		bShow = true;
		eTabPageType = ZN_SettingTabPage_General;
	}
}ZNShowSettingDlgParam;
enum ZNSDKCustomizedStringType
{
	ZN_SDK_Customized_LiveStream_MenuString_LiveOn_String = 0,///<The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item ON %S on live streaming. 
	ZN_SDK_Customized_LiveStream_MenuString_LiveView_String,///<The new string must end up with "%s" so that the menu item can show correctly. This type is used to define a string to replace the menu item VIEW STREAM ON %S on live streaming.
	ZN_SDK_Customized_LiveStream_MenuString_LiveStop_String,///<The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item STOP LIVE STREAM on live streaming.
	ZN_SDK_Customized_LiveStream_MenuString_CopyURL_String,///<The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the menu item COPY STREAMING LINK on live streaming.
	ZN_SDK_Customized_Title_App,	///<The new string must be a pure string so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI.
	ZN_SDK_Customized_Title_ZoomVideo,  ///<The new string must be the same format as "Zoom Participant ID: %s   Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI.
	ZN_SDK_Customized_Title_FreeZoomVideo, ///<The new string must be the same format as "Zoom Participant ID: %s  %d-Minutes Meeting ID:%s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status. 
	ZN_SDK_Customized_Title_ViewOnly_ZoomVideo, ///<The new string must end up with "%s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI.
	ZN_SDK_Customized_Title_ViewOnly_FreeZoomVideo, ///<The new string must be the same format as "Zoom %d-Minutes Meeting ID: %s" so that it can show correctly. This type is used to define a string to replace the title of the meeting video UI when the user is free user and in view-only status. 
};
enum ZNSDKCustomizedURLType
{
	ZN_SDKCustomizedURL_VITRULBG_HELP, ///<Set the custom help URL in the virtual background tab page.
	ZN_SDKCustomizedURL_VITRULBG_LEARN_MORE,///<Set the custom Learn More URL in the virtual background tab page.
	ZN_SDKCustomizedURL_SUPPORTURL, ///<Set the Support URL in the meeting.
};
enum ZNH323CalloutStatus
{
	ZN_H323Callout_Unknown, ///<Used only for initialization.
	ZN_H323Callout_Success, ///<Call out successfully.
	ZN_H323Callout_Ring,   ///<Bell during the call.
	ZN_H323Callout_Timeout, ///<Call timeout.
	ZN_H323Callout_Failed, ///<Call fails.
};
enum ZNH323DeviceType
{
	ZN_H323DeviceType_Unknown,///<Unknown device, only for initialization.
	ZN_H323DeviceType_H323,///<H.323 device.
	ZN_H323DeviceType_SIP,///<SIP device.
	ZN_H323DeviceType_BOTH,///<H.323 device and SIP device.
};
typedef struct _ZNH323DeviecInfo
{
	ZoomSTRING h323_deviceName;///<The H.323 device ID.
	ZoomSTRING h323_deviceIP;///<The H.323 device IP.
	ZoomSTRING h323_deviceE164Name;///<The H.323 device E164 name.
	ZNH323DeviceType h323_DeviceType;///<The H.323 device type. For more infomation, see \link ZNH323DeviceType \endlink enum.
}ZNH323DeviecInfo;
typedef struct _ZNWndPosition
{
	ZoomSTRING z_left;///<Specifies the X-axis coordinate of the top-left corner of the window
	ZoomSTRING z_top;///<Specifies the Y-axis coordinate of the top-left of the window.
#if (defined BUILD_WIN)
	ZoomSTRING z_hSelfWnd;///<Specifies the window handle of the window itself.
	ZoomSTRING z_hParent;///<Specifies the window handle of the parent window. If the value is NULL, the position coordinate is the monitor coordinate.
#else
	ZoomSTRING z_height;
	ZoomSTRING z_width;
#endif
}ZNWndPosition;
enum ZNFreeMeetingEndingReminderType
{
	ZN_FreeMeetingEndingReminder_NONE,///<Initialization.
	ZN_FreeMeetingEndingReminder_Can_UpgradeMeeting_ToPro_Once,///<Upgrade to the priority meeting at once. 
	ZN_FreeMeetingEndingReminder_Can_UpgradeAccount,///<Upgrade the account.
	ZN_FreeMeetingEndingReminder_Reminder,///<Remind to pay.
	ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Failed,///<Upgrade failed.
	ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Success,///<Upgrade successfully.
};
enum ZNFreeMeetingNeedUpgradeType
{
	ZN_FreeMeetingNeedUpgradeType_NONE,///<Initialization.
	ZN_FreeMeetingNeedUpgradeType_BY_ADMIN,///<It is necessary for administrator to upgrade the free meeting.
	ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL,///<Upgrade the free meeting by the gift link.
};
enum ZNPremeetingAPIResult
{
	ZN_PREMETAPIRET_UNKNOW,///<API returns unknown error.
	ZN_PREMETAPIRET_SUCCESS,///<Calls API successfully.
	ZN_PREMETAPIRET_FAILED,
	ZN_PREMETAPIRET_TIMEOUT,
};
enum ZNDirectShareStatus
{
	ZN_DirectShare_Unknown = 0,///<Only for initialization.
	ZN_DirectShare_Connecting,///<Waiting for enabling the direct sharing.
	ZN_DirectShare_In_Direct_Share_Mode,///<In direct sharing mode.
	ZN_DirectShare_Ended,///<End the direct sharing.
	ZN_DirectShare_Need_MeetingID_Or_PairingCode,///<Re-enter the meeting ID/paring code.
	ZN_DirectShare_NetWork_Error,///<Network error. Please try again later.
	ZN_DirectShare_Other_Error,///<Other errors. Mainly occur in SIP call mode.
	ZN_DirectShare_WrongMeetingID_Or_SharingKey,
};
enum ZNAudioType
{
	ZN_AUDIOTYPE_NONE,///<Normal audio type.
	ZN_AUDIOTYPE_VOIP,///<In VoIP mode.
	ZN_AUDIOTYPE_PHONE,///<In telephone mode.
	ZN_AUDIOTYPE_UNKNOW,///<Unknown mode.
};
enum ZNUserRole
{
	ZN_USERROLE_NONE,///<For initialization.
	ZN_USERROLE_HOST,///<Role of the host.
	ZN_USERROLE_COHOST,///<Role of co-host.
	ZN_USERROLE_PANELIST,///<Role of the panelist, valid only in webinar.
	ZN_USERROLE_BREAKOUTROOM_MODERATOR,///<Host role in breakout room.
	ZN_USERROLE_ATTENDEE,///<Role of attendee.
};
typedef struct _ZNUserInfomation
{
	ZoomSTRING userName;///<Current user name.
	ZoomSTRING email;///<Current user email.
	bool isHost; ///<Whether the member corresponding with the current information is the host or not.
	unsigned int userID;///<Current user's ID.
	bool isVideoOn;///<The video status of the user specified by the current information.
	bool isAudioMuted;///<The audio status of the user specified by the current information.
	bool isMySelf;///<Whether the current information corresponds to the user himself or not.
	ZNUserRole userRole;///<The type of role of the user specified by the current information. For more infomation, see \link ZNUserRole \endlink enum.
	bool isPurePhoneUser;///<Whether the user corresponding to the current information joins the meeting by telephone or not.
	bool webinarAttendeeStatus;///<The webinar status of the user specified by the current information. TRUE indicates that it is able to talk.
#if (defined BUILD_WIN)
	ZNAudioType audioJoinType;///<the audio type of the user specified by the current information when joins the meeting. For more infomation, see \link ZNAudioType \endlink enum.
	bool isInWaitingRoom;///<Whether the user specified by the current information is in the waiting room or not.
	bool isRaiseHand;///<Whether the user specified by the current information raises hand or not.
	ZoomSTRING AudioVoiceLevel;///<The Mic level of the user corresponding to the current information.
	bool isClosedCaptionSender;///<Whether the user corresponding to the current information is the sender of Closed Caption or not.
#endif
}ZNUserInfomation;

/*! \enum SDKMinimizeUIMode
\brief The type of minimize user interface mode.
Here are more detailed structural descriptions.
*/
enum ZNSDKMinimizeUIMode
{
	ZN_MinimizeUIMode_NONE,///<For initialization.
	ZN_MinimizeUIMode_SHARE,///<Minimized mode for sharing.
	ZN_MinimizeUIMode_VIDEO,///<Minimized mode for video.
	ZN_MinimizeUIMode_ACTIVESPEAKER,///<Minimized mode for speaking.
};
typedef struct _ZNSettingDlgShowTabPageOption
{
	bool z_bShowGeneral;///<True indicates to show general page
	bool z_bShowVideo; ///<True indicates to show video page
	bool z_bShowAudio;///<True indicates to show audio page
	bool z_bShowVirtualBackGround;///<True indicates to show virtual background page
	bool z_bSHowRecording;///<True indicates to show recording page
	bool z_bShowAdvancedFeature;///<True indicates to show advance feature page
	bool z_bShowStatistics;///<True indicates to show staticstics page
	bool z_bShowFeedback;///<True indicates to show feed back page
	bool z_bShowAccessibility;///<True indicates to show accessibility page
	_ZNSettingDlgShowTabPageOption()
	{
		z_bShowGeneral = true;
		z_bShowVideo = true;
		z_bShowAudio = true;
		z_bShowVirtualBackGround = true;
		z_bSHowRecording = true;
		z_bShowStatistics = true;
		z_bShowAccessibility = true;
		z_bShowAdvancedFeature = false;
		z_bShowFeedback = false;
	}

}ZNSettingDlgShowTabPageOption;

enum ZNSMSVerificationCodeErr
{
	ZNSMSVerificationCodeErr_Unknown,
	ZNSMSVerificationCodeErr_Success,
	ZNSMSVerificationCodeErr_Retrieve_SendSMSFailed,
	ZNSMSVerificationCodeErr_Retrieve_InvalidPhoneNum,
	ZNSMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound,
	ZNSMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent,
	ZNSMSVerificationCodeErr_Verify_CodeIncorrect,
	ZNSMSVerificationCodeErr_Verify_CodeExpired,
	ZNSMSVerificationCodeErr_Verify_UnknownError,
};
typedef struct _ZNZoomRealNameAuthCountryInfo
{
	ZoomSTRING countryID;
	ZoomSTRING countryName;
	ZoomSTRING countryCode;
}ZNZoomRealNameAuthCountryInfo;

enum ZNSDKInviteDlgTabPage
{
	SDK_INVITEDLG_TAB_EMAILCONTACT = 0, ///<'Invite by Email' tab page
	SDK_INVITEDLG_TAB_PHONECONTACT, ///<'Invite by Phone' tab pag
	SDK_INVITEDLG_TAB_ROOMSYSTEM, ///<'Invite a Room System' tab page
};

enum ZNSDKH323TabPage
{
	SDK_INVITEDLG_H323_DIALIN = 0, ///<'Dial In' sub-tab page under Room System invitation tab page
	SDK_INVITEDLG_H323_CALLOUT, ///<'Call Out' sub-tab page under Room System invitation tab page
};

typedef struct _ZNZoomRedirectWarningMsgOption
{
	bool bRedirectBadNetwork;
	bool bRedirectWarnHighCPU;
	_ZNZoomRedirectWarningMsgOption()
	{
		bRedirectBadNetwork = false;
		bRedirectWarnHighCPU = false;
	}
}ZNZoomRedirectWarningMsgOption;

//SettingDlgShowTabPageOptionDef
#define SETTING_DLG_SHOW_VIRTUAL_BACK_GROUND_TABPAGE 1UL
#define SETTING_DLG_SHOW_VIDEO_TABPAGE (1UL << 1)
#define SETTING_DLG_SHOW_STATISTICS_TABPAGE (1UL << 2)
#define SETTING_DLG_SHOW_RECORDING_TABPAGE (1UL << 3)
#define SETTING_DLG_SHOW_GENERAL_TABPAGE (1UL << 4)
#define SETTING_DLG_SHOW_FEEDBACK_TABPAGE (1UL << 5)
#define SETTING_DLG_SHOW_AUDIO_TABPAGE (1UL << 6)
#define SETTING_DLG_SHOW_ADVANCED_FEATURE_TABPAGE (1UL << 7)
#define SETTING_DLG_SHOW_ACCESSIBILITY_TABPAGE (1UL << 8)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*! \enum ZNSettingsNetWorkType
\brief Notify network type.
Here are more detailed structural descriptions.
*/
enum ZNSettingsNetWorkType
{
	ZNSETTINGS_NETWORK_WIRED = 0,///<Wired LAN
	ZNSETTINGS_NETWORK_WIFI = 1,///<WIFI
	ZNSETTINGS_NETWORK_PPP = 2,///<PPP
	ZNSETTINGS_NETWORK_3G = 3,///<3G
	ZNSETTINGS_NETWORK_OTHERS = 4,///<Others

	ZNSETTINGS_NETWORK_UNKNOWN = -1,///<Unknown network.
};
/*! \enum ZNSettingConnectionType
\brief Notify connection type.
Here are more detailed structural descriptions.
*/
enum ZNSettingConnectionType
{
	ZNSETTINGS_CONNECTION_TYPE_CLOUD,///<Cloud connection.
	ZNSETTINGS_CONNECTION_TYPE_DIRECT,///<Direct connection.
	ZNSETTINGS_CONNECTION_TYPE_UNKNOWN = -1,///<Unknown connection.
};
/*! \struct ZNOverallStatisticInfo
\brief Notify overall statistic information.
Here are more detailed structural descriptions.
*/
typedef struct _ZNOverallStatisticInfo
{
	ZNSettingsNetWorkType net_work_type;///<Network type.
	ZNSettingConnectionType connection_type;///<Connection type
	ZoomSTRING proxy_addr;///<Proxy address.
	_ZNOverallStatisticInfo()
	{
		net_work_type = ZNSETTINGS_NETWORK_UNKNOWN;
		connection_type = ZNSETTINGS_CONNECTION_TYPE_UNKNOWN;
	}
}ZNOverallStatisticInfo;
/*! \struct ZNAudioSessionStatisticInfo
\brief Notify the audio status information.
Here are more detailed structural descriptions.
*/
typedef struct _ZNAudioSessionStatisticInfo
{
	int frequency_send;///<Sending frequency, unit: KHz.
	int frequency_recv;///<Receiving frequency, unit: KHz.
	int latency_send;///<Sending latency, unit: ms.
	int latency_recv;///<Receiving latency, unit: ms.
	int jitter_send;///<Sending jitter, unit: ms.
	int jitter_recv;///<Receiving jitter, unit: ms.
	float packetloss_send;///<Sending packet loss, unit: %.
	float packetloss_recv;///<Receiving packet loss, unit: %.

}ZNAudioSessionStatisticInfo;
/*! \struct ZNASVSessionStatisticInfo
\brief Notify video status information.
Here are more detailed structural descriptions.
*/
typedef struct ZNASVSessionStatisticInfo
{
	int latency_send;///<Sending latency, unit: ms.
	int latency_recv;///<Receiving latency, unit: ms.
	int jitter_send;///<Sending jitter, unit: ms.
	int jitter_recv;///<Receiving jitter, unit: ms.
	float packetloss_send_max;///<Sending max packet loss, unit: %.
	float packetloss_recv_max;///<Receiving max packet loss, unit: %.
	float packetloss_send_avg;///<Sending average packet loss, unit: %.
	float packetloss_recv_avg;///<Receiving average packet loss, unit: %.
	int resolution_send;///<HIWORD->height, LOWORD->width.
	int resolution_recv;///<HIWORD->height, LOWORD->width. 
	int fps_send;///<Frame per second sending.
	int fps_recv;///<Frame per second receiving.

}ZNASVSessionStatisticInfo;

enum ZNRequiredInfoType
{
	ZNREQUIRED_INFO_TYPE_NONE,///<Initialization.
	ZNREQUIRED_INFO_TYPE_Password, ///<The user needs to enter the password when joins the meeting. Via the InputMeetingPasswordAndScreenName() to specify the password information.
	ZNREQUIRED_INFO_TYPE_Password4WrongPassword,///<If the password is invalid, the user needs to re-enter it. Via the InputMeetingPasswordAndScreenName() to specify the password information. 
	ZNREQUIRED_INFO_TYPE_PasswordAndScreenName,///<The user needs to enter the screen name and the password,via the InputMeetingPasswordAndScreenName() to specify the necessary information.
	ZNREQUIRED_INFO_TYPE_ScreenName,///<The user needs to enter the screen name. Via the InputMeetingScreenName() to specify the screen name information.
	ZNREQUIRED_INFO_TYPE_MeetingIDAndScreenName,///<The user needs to enter the screen name and the meeting id,via the InputMeetingMeetingIDAndScreenName() to specify the necessary information.
};
/*! \enum WebinarNeedRegisterType
\brief Register type of webinar.
Here are more detailed structural descriptions.
*/
enum ZNWebinarNeedRegisterType
{
	ZNWebinarReg_NONE,///<Initialization.
	ZNWebinarReg_By_Register_Url,///<Register webinar account by URL.
	ZNWebinarReg_By_Email_and_DisplayName,///<Register webinar account by email and the screen name.
};

enum ZNAudioCallbackActionInfo
{
	ZNACTION_INFO_NONE = 0,
	ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED,
	ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR,
	ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_PHONECALLDEVICEERROR,
	ZNACTION_INFO_NEED_JOIN_VOIP,
	ZNACTION_INFO_MUTE_UNMUTE_AUDIO,
	ZNACTION_INFO_SHOW_AUDIO_SETTING_WINDOW,
};

typedef struct tagZNAudioBtnClickedCallbackInfo
{
	unsigned int userid_MuteUnmute;
	ZNAudioCallbackActionInfo audio_clicked_action;
	tagZNAudioBtnClickedCallbackInfo()
	{
		userid_MuteUnmute = 0;
		audio_clicked_action = ZNACTION_INFO_NONE;
	}

}ZNAudioBtnClickedCallbackInfo;



////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ZNList std::vector
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
#if (defined BUILD_WIN)
#define JS_WRAP
//#define UserInterfaceClass
#endif
