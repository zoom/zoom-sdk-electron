#ifndef _zoom_native_sdk_wrap_core_def_h_
#define _zoom_native_sdk_wrap_core_def_h_
#include <string>
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
	ZNSDKERR_SUCCESS = 0,
	ZNSDKERR_NO_IMPL,
	ZNSDKERR_WRONG_USEAGE,
	ZNSDKERR_INVALID_PARAMETER,
	ZNSDKERR_MODULE_LOAD_FAILED,
	ZNSDKERR_MEMORY_FAILED,
	ZNSDKERR_SERVICE_FAILED,
	ZNSDKERR_UNINITIALIZE,
	ZNSDKERR_UNAUTHENTICATION,
	ZNSDKERR_NORECORDINGINPROCESS,
	ZNSDKERR_TRANSCODER_NOFOUND,
	ZNSDKERR_VIDEO_NOTREADY,
	ZNSDKERR_NO_PERMISSION,
	ZNSDKERR_UNKNOWN,
	ZNSDKERR_OTHER_SDK_INSTANCE_RUNNING,
	ZNSDKERR_INTELNAL_ERROR,
	ZNSDKERR_NO_AUDIODEVICE_ISFOUND,
	ZNSDKERR_NO_VIDEODEVICE_ISFOUND,
	ZNSDKERR_TOO_FREQUENT_CALL,
	ZNSDKERR_FAIL_ASSIGN_USER_PRIVILEGE, 
	ZNSDKERR_MEETING_DONT_SUPPORT_FEATURE,
	ZNSDKERR_MEETING_NOT_SHARE_SENDER,
	ZNSDKERR_MEETING_YOU_HAVE_NO_SHARE,
	ZNSDKERR_MEETING_VIEWTYPE_PARAMETER_IS_WRONG, 
	ZNSDKERR_MEETING_ANNOTATION_IS_OFF, 
	ZNSDKERR_SETTING_OS_DONT_SUPPORT, 
};
enum ZNSDK_LANGUAGE_ID
{
	ZNLANGUAGE_Unknow = 0,
	ZNLANGUAGE_English,
	ZNLANGUAGE_Chinese_Simplified,
	ZNLANGUAGE_Chinese_Traditional,
	ZNLANGUAGE_Japanese,
	ZNLANGUAGE_Spanish,
	ZNLANGUAGE_German,
	ZNLANGUAGE_French,
	ZNLANGUAGE_Portuguese,
	ZNLANGUAGE_Russian,
};

enum ZNAuthResult
{
	ZNAUTHRET_SUCCESS = 0,
	ZNAUTHRET_KEYORSECRETEMPTY,
	ZNAUTHRET_KEYORSECRETWRONG,
	ZNAUTHRET_ACCOUNTNOTSUPPORT,
	ZNAUTHRET_ACCOUNTNOTENABLESDK,
	ZNAUTHRET_UNKNOWN,
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
	ZNCustomizedLanguageInfo customizedLang;///The custom resource information.
	int optionalFeatures;///<Additional functional configuration. The function currently supports only whether to use the custom UI mode. When the value of the optionalFeatures&ENABLE_CUSTOMIZED_UI_FLAG is TRUE, it means to the Use the custom UI mode. Otherwise use the traditional interface mode.
	_ZNConfigurableOptions()
	{
		optionalFeatures = 0;
	}

}ZNConfigurableOptions;
typedef struct _ZNInitParam
{
	ZoomSTRING path;
	ZoomSTRING domain;
	bool enable_log;
	ZNSDK_LANGUAGE_ID langid;
	ZoomSTRING strSupportUrl;
	ZoomSTRING strBrandingName;
	ZNConfigurableOptions obConfigOpts;///<The configuration options of the SDK.
	_ZNInitParam(){
		enable_log = true;
		langid = ZNLANGUAGE_English;
	}
}ZNInitParam;

typedef struct _ZNAuthParam
{
	ZoomSTRING sdk_key;
	ZoomSTRING sdk_secret;
}ZNAuthParam;

typedef struct _ZNLoginParam
{
	ZoomSTRING user_name;
	ZoomSTRING psw;
	ZoomSTRING ssotoken;
	bool remember_me;
	_ZNLoginParam() {
		remember_me = false;
	}
}ZNLoginParam;

enum ZNLOGINSTATUS
{
	ZNLOGIN_IDLE = 0,
	ZNLOGIN_PROCESSING,
	ZNLOGIN_SUCCESS,
	ZNLOGIN_FAILED,
};

enum ZNLoginType
{
	ZNLoginType_Unknown = 0,
	ZNLoginType_Email,
	ZNLoginType_SSO,
};

typedef struct _ZNAccountInfo {
	ZoomSTRING dispaly_name;
	ZNLoginType login_type;
}ZNAccountInfo;

enum ZNMeetingStatus
{
	ZNMEETING_STATUS_IDLE = 0,
	ZNMEETING_STATUS_CONNECTING,
	ZNMEETING_STATUS_WAITINGFORHOST,
	ZNMEETING_STATUS_INMEETING,
	ZNMEETING_STATUS_DISCONNECTING,
	ZNMEETING_STATUS_RECONNECTING,
	ZNMEETING_STATUS_FAILED,
	ZNMEETING_STATUS_ENDED,
	ZNMEETING_STATUS_UNKNOW,
	ZNMEETING_STATUS_LOCKED,
	ZNMEETING_STATUS_UNLOCKED,
	ZNMEETING_STATUS_IN_WAITING_ROOM,
	ZNMEETING_STATUS_WEBINAR_PROMOTE,
	ZNMEETING_STATUS_WEBINAR_DEPROMOTE,
	ZNMEETING_STATUS_JOIN_BREAKOUT_ROOM,
	ZNMEETING_STATUS_LEAVE_BREAKOUT_ROOM,
	ZNMEETING_STATUS_AUDIO_READY,
	ZNMEETING_STATUS_OTHER_MEETING_INPROGRESS,
	ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY,
};
enum ZNSDKUserType
{
	ZNSDK_UT_APIUSER = 99,
	ZNSDK_UT_NORMALUSER = 100,
	ZNSDK_UT_WITHOUT_LOGIN,
};
enum ZNZoomUserType
{
	ZNZoomUserType_APIUSER,
	ZNZoomUserType_EMAIL_LOGIN,
	ZNZoomUserType_FACEBOOK,
	ZNZoomUserType_GoogleOAuth,
	ZNZoomUserType_SSO,
	ZNZoomUserType_Unknown,
};
typedef struct _ZNStartParam
{
	ZNSDKUserType userType;
	ZoomSTRING meetingNumber;
	ZoomSTRING hDirectShareAppWnd;
	ZoomSTRING participantId;
	ZoomSTRING userId;
	ZoomSTRING userToken;
	ZoomSTRING username;
	ZoomSTRING sdkVanityID;
	ZoomSTRING userZAK;
	ZNZoomUserType zoomUserType;
	bool isVideoOff;
	bool isAudioOff;
	bool isDirectShareDesktop;
	_ZNStartParam() {
		userType = ZNSDK_UT_APIUSER;
	}
}ZNStartParam;
typedef struct _ZNJoinParam
{
	ZNSDKUserType userType;
	ZoomSTRING meetingNumber;
	ZoomSTRING hDirectShareAppWnd;
	ZoomSTRING participantId;
	ZoomSTRING userId;
	ZoomSTRING userToken;
	ZoomSTRING username;
	ZoomSTRING psw;
	ZoomSTRING vanityID;
	ZoomSTRING webinarToken;
	ZoomSTRING token4EnforceLogin;
	ZoomSTRING displayID;
	bool isVideoOff;
	bool isAudioOff;
	bool isDirectShareDesktop;
	_ZNJoinParam() {
		userType = ZNSDK_UT_APIUSER;
	}
}ZNJoinParam;
enum ZNLeaveMeetingCmd
{
	ZNLEAVE_MEETING,
	ZNEND_MEETING,
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
	ZoomSTRING hParent;
	ZoomSTRING rect_top;
	ZoomSTRING rect_bottom;
	ZoomSTRING rect_left;
	ZoomSTRING rect_right;
	ZoomSTRING hChatWnd;
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
	ZoomSTRING userId;///<The page in video wall mode for the moment.
	ZNAudioStatus audioStauts;///<The total number of pages in video wall mode.
}ZNUserAudioStatus;
enum ZNVideoStatus
{
	ZN_Video_ON, ///<Video is on.
	ZN_Video_OFF, ///<Video is off.
};
typedef struct _ZNCameraInfo
{
	ZoomSTRING deviceId;
	ZoomSTRING deviceName;
	bool isSelectedDevice;
}ZNCameraInfo;
typedef struct _ZNMicInfo
{
	ZoomSTRING deviceId;
	ZoomSTRING deviceName;
	bool isSelectedDevice;
}ZNMicInfo;
typedef struct _ZNSpeakerInfo
{
	ZoomSTRING deviceId;
	ZoomSTRING deviceName;
	bool isSelectedDevice;
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
	ZoomSTRING h323_deviceName;
	ZoomSTRING h323_deviceIP;
	ZoomSTRING h323_deviceE164Name;
	ZNH323DeviceType h323_DeviceType;
}ZNH323DeviecInfo;
typedef struct _ZNWndPosition
{
	ZoomSTRING z_left;
	ZoomSTRING z_top;
	ZoomSTRING z_hSelfWnd;
	ZoomSTRING z_hParent;
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
};


////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class ZNList
{
private:
	struct Budy
	{
		T data;
		Budy *next;
	};
	Budy *head;
	int length; 
	Budy *p;
	Budy *q;
public:
	ZNList()
	{
		head = NULL;
		length = 0;
		p = NULL;
	}
	~ZNList()
	{
		head = NULL;
		length = 0;
		p = NULL;
	}
	void add(T t)
	{
		if (head == NULL)
		{
			q = new Budy();
			q->data = t;
			q->next = NULL;
			length++;
			head = q;
			p = head;
		}
		else
		{
			q = new Budy();
			q->data = t;
			q->next = NULL;
			length++;
			p->next = q;
			p = q;
		}
	}

	void remove(int n)
	{
		if (n >= length)
		{
			return;
		}
		length--;

		if (n == 0)
		{
			q = head;
			head = head->next;
			delete(q);
		}
		else
		{
			q = head;
			for (int i = 0; i < n - 1; i++)
			{
				q = q->next;
			}
			Budy *t = q->next;
			q->next = q->next->next;
			delete(t);
		}
		p = head;
		if (p != NULL)
		{
			while (p->next != NULL)
			{
				p = p->next;
			}
		}
	}

	int getSize()
	{
		return length;
	}

	int getLength()
	{
		return getSize();
	}
	T get(int n)
	{
		q = head;
		for (int i = 0; i < n; i++)
		{
			q = q->next;
		}
		return q->data;
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
#if (defined BUILD_WIN)
#define JS_WRAP
#define UserInterfaceClass
#endif