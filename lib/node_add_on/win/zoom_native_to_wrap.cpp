#include "zoom_native_to_wrap.h"
ZNSDKError Map2WrapDefine(ZOOM_SDK_NAMESPACE::SDKError err)
{
	ZNSDKError zn_err_(ZNSDKERR_UNKNOWN);
	switch (err)
	{
	case ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS:
		zn_err_ = ZNSDKERR_SUCCESS;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_NO_IMPL:
		zn_err_ = ZNSDKERR_NO_IMPL;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_WRONG_USEAGE:
		zn_err_ = ZNSDKERR_WRONG_USEAGE;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_INVALID_PARAMETER:
		zn_err_ = ZNSDKERR_INVALID_PARAMETER;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MODULE_LOAD_FAILED:
		zn_err_ = ZNSDKERR_MODULE_LOAD_FAILED;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MEMORY_FAILED:
		zn_err_ = ZNSDKERR_MEMORY_FAILED;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_SERVICE_FAILED:
		zn_err_ = ZNSDKERR_SERVICE_FAILED;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_UNINITIALIZE:
		zn_err_ = ZNSDKERR_UNINITIALIZE;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_UNAUTHENTICATION:
		zn_err_ = ZNSDKERR_UNAUTHENTICATION;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_NORECORDINGINPROCESS:
		zn_err_ = ZNSDKERR_NORECORDINGINPROCESS;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_TRANSCODER_NOFOUND:
		zn_err_ = ZNSDKERR_TRANSCODER_NOFOUND;
		break;	
	case ZOOM_SDK_NAMESPACE::SDKERR_VIDEO_NOTREADY:
		zn_err_ = ZNSDKERR_VIDEO_NOTREADY;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_NO_PERMISSION:
		zn_err_ = ZNSDKERR_NO_PERMISSION;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_UNKNOWN:
		zn_err_ = ZNSDKERR_UNKNOWN;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_OTHER_SDK_INSTANCE_RUNNING:
		zn_err_ = ZNSDKERR_OTHER_SDK_INSTANCE_RUNNING;
		break;
		
	case ZOOM_SDK_NAMESPACE::SDKERR_INTELNAL_ERROR:	
		zn_err_ = ZNSDKERR_INTELNAL_ERROR;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_NO_AUDIODEVICE_ISFOUND:
		zn_err_ = ZNSDKERR_NO_AUDIODEVICE_ISFOUND;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_NO_VIDEODEVICE_ISFOUND:
		zn_err_ = ZNSDKERR_NO_VIDEODEVICE_ISFOUND;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_TOO_FREQUENT_CALL:
		zn_err_ = ZNSDKERR_TOO_FREQUENT_CALL;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_FAIL_ASSIGN_USER_PRIVILEGE:
		zn_err_ = ZNSDKERR_FAIL_ASSIGN_USER_PRIVILEGE;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MEETING_DONT_SUPPORT_FEATURE:
		zn_err_ = ZNSDKERR_MEETING_DONT_SUPPORT_FEATURE;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MEETING_NOT_SHARE_SENDER:
		zn_err_ = ZNSDKERR_MEETING_NOT_SHARE_SENDER;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MEETING_YOU_HAVE_NO_SHARE:
		zn_err_ = ZNSDKERR_MEETING_YOU_HAVE_NO_SHARE;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MEETING_VIEWTYPE_PARAMETER_IS_WRONG:
		zn_err_ = ZNSDKERR_MEETING_VIEWTYPE_PARAMETER_IS_WRONG;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_MEETING_ANNOTATION_IS_OFF:	
		zn_err_ = ZNSDKERR_MEETING_ANNOTATION_IS_OFF;
		break;
	case ZOOM_SDK_NAMESPACE::SDKERR_SETTING_OS_DONT_SUPPORT:
		zn_err_ = ZNSDKERR_SETTING_OS_DONT_SUPPORT;
		break;
	default:
		
		break;
	}
	return zn_err_;
}

ZNAuthResult Map2WrapDefine(ZOOM_SDK_NAMESPACE::AuthResult result)
{
	ZNAuthResult zn_auth_result_ = ZNAUTHRET_UNKNOWN;
	switch (result)
	{
	case ZOOMSDK::AUTHRET_SUCCESS:
		zn_auth_result_ = ZNAUTHRET_SUCCESS;
		break;
	case ZOOMSDK::AUTHRET_KEYORSECRETEMPTY:
		zn_auth_result_ = ZNAUTHRET_KEYORSECRETEMPTY;
		break;
	case ZOOMSDK::AUTHRET_KEYORSECRETWRONG:
		zn_auth_result_ = ZNAUTHRET_KEYORSECRETWRONG;
		break;
	case ZOOMSDK::AUTHRET_ACCOUNTNOTSUPPORT:
		zn_auth_result_ = ZNAUTHRET_ACCOUNTNOTSUPPORT;
		break;
	case ZOOMSDK::AUTHRET_ACCOUNTNOTENABLESDK:
		zn_auth_result_ = ZNAUTHRET_ACCOUNTNOTENABLESDK;
		break;
	case ZOOMSDK::AUTHRET_UNKNOWN:
		zn_auth_result_ = ZNAUTHRET_UNKNOWN;
		break;
	case ZOOMSDK::AUTHRET_SERVICE_BUSY:
		zn_auth_result_ = ZNAUTHRET_SERVICE_BUSY;
		break;
	case ZOOMSDK::AUTHRET_NONE:
		zn_auth_result_ = ZNAUTHRET_NONE;
		break;
	case ZOOMSDK::AUTHRET_OVERTIME:
		zn_auth_result_ = ZNAUTHRET_OVERTIME;
		break;
	case ZOOMSDK::AUTHRET_NETWORKISSUE:
		zn_auth_result_ = ZNAUTHRET_NETWORKISSUE;
		break;
	default:
		break;
	}
	
	return zn_auth_result_;
}
ZNLOGINSTATUS Map2WrapDefine(ZOOM_SDK_NAMESPACE::LOGINSTATUS status)
{
	ZNLOGINSTATUS zn_login_status;
	switch (status)
	{
	case ZOOM_SDK_NAMESPACE::LOGIN_IDLE:
		zn_login_status = ZNLOGIN_IDLE;
		break;
	case ZOOM_SDK_NAMESPACE::LOGIN_PROCESSING:
		zn_login_status = ZNLOGIN_PROCESSING;
		break;
	case ZOOM_SDK_NAMESPACE::LOGIN_SUCCESS:
		zn_login_status = ZNLOGIN_SUCCESS;
		break;
	case ZOOM_SDK_NAMESPACE::LOGIN_FAILED:
		zn_login_status = ZNLOGIN_FAILED;
		break;
	default:
		break;
	}
	return zn_login_status;
}
ZNAccountInfo Map2WrapDefine(ZOOM_SDK_NAMESPACE::IAccountInfo* pAccountInfo)
{
	ZNAccountInfo zn_account_info;
	zn_account_info.dispaly_name = pAccountInfo->GetDisplayName();
	ZOOM_SDK_NAMESPACE::LoginType login_type = pAccountInfo->GetLoginType();
	switch (login_type)
	{
	case ZOOM_SDK_NAMESPACE::LoginType_Unknown:
		zn_account_info.login_type = ZNLoginType_Unknown;
		break;
	case ZOOM_SDK_NAMESPACE::LoginType_Email:
		zn_account_info.login_type = ZNLoginType_Email;
		break;
	case ZOOM_SDK_NAMESPACE::LoginType_SSO:
		zn_account_info.login_type = ZNLoginType_SSO;
		break;
	default:
		break;
	}
	return zn_account_info;
}
ZNMeetingStatus Map2WrapDefine(ZOOM_SDK_NAMESPACE::MeetingStatus status)
{
	ZNMeetingStatus zn_meeting_status;
	switch (status)
	{
	case ZOOMSDK::MEETING_STATUS_IDLE:
		zn_meeting_status = ZNMEETING_STATUS_IDLE;
		break;
	case ZOOMSDK::MEETING_STATUS_CONNECTING:
		zn_meeting_status = ZNMEETING_STATUS_CONNECTING;
		break;
	case ZOOMSDK::MEETING_STATUS_WAITINGFORHOST:
		zn_meeting_status = ZNMEETING_STATUS_WAITINGFORHOST;
		break;
	case ZOOMSDK::MEETING_STATUS_INMEETING:
		zn_meeting_status = ZNMEETING_STATUS_INMEETING;
		break;
	case ZOOMSDK::MEETING_STATUS_DISCONNECTING:
		zn_meeting_status = ZNMEETING_STATUS_DISCONNECTING;
		break;
	case ZOOMSDK::MEETING_STATUS_RECONNECTING:
		zn_meeting_status = ZNMEETING_STATUS_RECONNECTING;
		break;
	case ZOOMSDK::MEETING_STATUS_FAILED:
		zn_meeting_status = ZNMEETING_STATUS_FAILED;
		break;
	case ZOOMSDK::MEETING_STATUS_ENDED:
		zn_meeting_status = ZNMEETING_STATUS_ENDED;
		break;
	case ZOOMSDK::MEETING_STATUS_UNKNOW:
		zn_meeting_status = ZNMEETING_STATUS_UNKNOW;
		break;
	case ZOOMSDK::MEETING_STATUS_LOCKED:
		zn_meeting_status = ZNMEETING_STATUS_LOCKED;
		break;
	case ZOOMSDK::MEETING_STATUS_UNLOCKED:
		zn_meeting_status = ZNMEETING_STATUS_UNLOCKED;
		break;
	case ZOOMSDK::MEETING_STATUS_IN_WAITING_ROOM:
		zn_meeting_status = ZNMEETING_STATUS_IN_WAITING_ROOM;
		break;
	case ZOOMSDK::MEETING_STATUS_WEBINAR_PROMOTE:
		zn_meeting_status = ZNMEETING_STATUS_WEBINAR_PROMOTE;
		break;
	case ZOOMSDK::MEETING_STATUS_WEBINAR_DEPROMOTE:
		zn_meeting_status = ZNMEETING_STATUS_WEBINAR_DEPROMOTE;
		break;
	case ZOOMSDK::MEETING_STATUS_JOIN_BREAKOUT_ROOM:
		zn_meeting_status = ZNMEETING_STATUS_JOIN_BREAKOUT_ROOM;
		break;
	case ZOOMSDK::MEETING_STATUS_LEAVE_BREAKOUT_ROOM:
		zn_meeting_status = ZNMEETING_STATUS_LEAVE_BREAKOUT_ROOM;
		break;
	case ZOOMSDK::MEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY:
		zn_meeting_status = ZNMEETING_STATUS_WAITING_EXTERNAL_SESSION_KEY;
		break;
	default:
		break;
	}
	return zn_meeting_status;
}
ZNMeetingType Map2WrapDefine(ZOOM_SDK_NAMESPACE::MeetingType type)
{
	ZNMeetingType zn_meeting_type;
	switch (type)
	{
	case ZOOMSDK::MEETING_TYPE_NONE:
		zn_meeting_type = ZNMEETING_TYPE_NONE;
		break;
	case ZOOMSDK::MEETING_TYPE_NORMAL:
		zn_meeting_type = ZNMEETING_TYPE_NORMAL;
		break;
	case ZOOMSDK::MEETING_TYPE_WEBINAR:
		zn_meeting_type = ZNMEETING_TYPE_WEBINAR;
		break;
	case ZOOMSDK::MEETING_TYPE_BREAKOUTROOM:
		zn_meeting_type = ZNMEETING_TYPE_BREAKOUTROOM;
		break;
	default:
		break;
	}
	return zn_meeting_type;
}
ZNConnectionQuality Map2WrapDefine(ZOOM_SDK_NAMESPACE::ConnectionQuality quality)
{
	ZNConnectionQuality zn_connection_quality;
	switch (quality)
	{
	case ZOOMSDK::Conn_Quality_Unknow:
		zn_connection_quality = ZNConn_Quality_Unknow;
		break;
	case ZOOMSDK::Conn_Quality_Very_Bad:
		zn_connection_quality = ZNConn_Quality_Very_Bad;
		break;
	case ZOOMSDK::Conn_Quality_Bad:
		zn_connection_quality = ZNConn_Quality_Bad;
		break;
	case ZOOMSDK::Conn_Quality_Not_Good:
		zn_connection_quality = ZNConn_Quality_Not_Good;
		break;
	case ZOOMSDK::Conn_Quality_Normal:
		zn_connection_quality = ZNConn_Quality_Normal;
		break;
	case ZOOMSDK::Conn_Quality_Good:
		zn_connection_quality = ZNConn_Quality_Good;
		break;
	case ZOOMSDK::Conn_Quality_Excellent:
		zn_connection_quality = ZNConn_Quality_Excellent;
		break;
	default:
		break;
	}
	return zn_connection_quality;
}
ZNAudioStatus Map2WrapDefine(ZOOM_SDK_NAMESPACE::AudioStatus status)
{
	ZNAudioStatus zn_audio_status;
	switch (status)
	{
	case ZOOMSDK::Audio_None:
		zn_audio_status = ZN_Audio_None;
		break;
	case ZOOMSDK::Audio_Muted:
		zn_audio_status = ZN_Audio_Muted;
		break;
	case ZOOMSDK::Audio_UnMuted:
		zn_audio_status = ZN_Audio_UnMuted;
		break;
	case ZOOMSDK::Audio_Muted_ByHost:
		zn_audio_status = ZN_Audio_Muted_ByHost;
		break;
	case ZOOMSDK::Audio_UnMuted_ByHost:
		zn_audio_status = ZN_Audio_UnMuted_ByHost;
		break;
	case ZOOMSDK::Audio_MutedAll_ByHost:
		zn_audio_status = ZN_Audio_MutedAll_ByHost;
		break;
	case ZOOMSDK::Audio_UnMutedAll_ByHost:
		zn_audio_status = ZN_Audio_UnMutedAll_ByHost;
		break;
	default:
		break;
	}
	return zn_audio_status;
}
ZNVideoStatus Map2WrapDefine(ZOOM_SDK_NAMESPACE::VideoStatus status)
{
	ZNVideoStatus zn_video_status;
	switch (status)
	{
	case ZOOMSDK::Video_ON:
		zn_video_status = ZN_Video_ON;
		break;
	case ZOOMSDK::Video_OFF:
		zn_video_status = ZN_Video_OFF;
		break;
	default:
		break;
	}
	return zn_video_status;
}
ZNH323CalloutStatus Map2WrapDefine(ZOOM_SDK_NAMESPACE::H323CalloutStatus status)
{
	ZNH323CalloutStatus zn_h323_callout_status;
	switch (status)
	{
	case ZOOMSDK::H323Callout_Unknown:
		zn_h323_callout_status = ZN_H323Callout_Unknown;
		break;
	case ZOOMSDK::H323Callout_Success:
		zn_h323_callout_status = ZN_H323Callout_Success;
		break;
	case ZOOMSDK::H323Callout_Ring:
		zn_h323_callout_status = ZN_H323Callout_Ring;
		break;
	case ZOOMSDK::H323Callout_Timeout:
		zn_h323_callout_status = ZN_H323Callout_Timeout;
		break;
	case ZOOMSDK::H323Callout_Failed:
		zn_h323_callout_status = ZN_H323Callout_Failed;
		break;
	default:
		break;
	}
	return zn_h323_callout_status;
}
ZNH323DeviceType Map2WrapDefine(ZOOM_SDK_NAMESPACE::H323DeviceType type)
{
	ZNH323DeviceType zn_h323_device_type;
	switch (type)
	{
	case ZOOMSDK::H323DeviceType_Unknown:
		zn_h323_device_type = ZN_H323DeviceType_Unknown;
		break;
	case ZOOMSDK::H323DeviceType_H323:
		zn_h323_device_type = ZN_H323DeviceType_H323;
		break;
	case ZOOMSDK::H323DeviceType_SIP:
		zn_h323_device_type = ZN_H323DeviceType_SIP;
		break;
	case ZOOMSDK::H323DeviceType_BOTH:
		zn_h323_device_type = ZN_H323DeviceType_BOTH;
		break;
	default:
		break;
	}
	return zn_h323_device_type;
}
ZNFreeMeetingEndingReminderType Map2WrapDefine(ZOOM_SDK_NAMESPACE::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminderType type)
{
	ZNFreeMeetingEndingReminderType zn_free_meeting_ending_reminder_type;
	switch (type)
	{
	case ZOOMSDK::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_NONE:
		zn_free_meeting_ending_reminder_type = ZN_FreeMeetingEndingReminder_NONE;
		break;
	case ZOOMSDK::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_Can_UpgradeMeeting_ToPro_Once:
		zn_free_meeting_ending_reminder_type = ZN_FreeMeetingEndingReminder_Can_UpgradeMeeting_ToPro_Once;
		break;
	case ZOOMSDK::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_Can_UpgradeAccount:
		zn_free_meeting_ending_reminder_type = ZN_FreeMeetingEndingReminder_Can_UpgradeAccount;
		break;
	case ZOOMSDK::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_Reminder:
		zn_free_meeting_ending_reminder_type = ZN_FreeMeetingEndingReminder_Reminder;
		break;
	case ZOOMSDK::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Failed:
		zn_free_meeting_ending_reminder_type = ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Failed;
		break;
	case ZOOMSDK::IFreeMeetingEndingReminderHandler::FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Success:
		zn_free_meeting_ending_reminder_type = ZN_FreeMeetingEndingReminder_UpgradeMeeting_ToPro_Success;
		break;
	default:
		break;
	}
	return zn_free_meeting_ending_reminder_type;
}
ZNFreeMeetingNeedUpgradeType Map2WrapDefine(ZOOM_SDK_NAMESPACE::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType type)
{
	ZNFreeMeetingNeedUpgradeType zn_free_meeting_need_upgrade_type;
	switch (type)
	{
	case ZOOMSDK::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType_NONE:
		zn_free_meeting_need_upgrade_type = ZN_FreeMeetingNeedUpgradeType_NONE;
		break;
	case ZOOMSDK::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType_BY_ADMIN:
		zn_free_meeting_need_upgrade_type = ZN_FreeMeetingNeedUpgradeType_BY_ADMIN;
		break;
	case ZOOMSDK::IMeetingConfigurationFreeMeetingEvent::FreeMeetingNeedUpgradeType_BY_GIFTURL:
		zn_free_meeting_need_upgrade_type = ZN_FreeMeetingNeedUpgradeType_BY_GIFTURL;
		break;
	default:
		break;
	}
	return zn_free_meeting_need_upgrade_type;
}
ZNPremeetingAPIResult Map2WrapDefine(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result)
{
	ZNPremeetingAPIResult zn_premeeting_result;
	switch (result)
	{
	case ZOOMSDK::PREMETAPIRET_UNKNOW:
		zn_premeeting_result = ZN_PREMETAPIRET_UNKNOW;
		break;
	case ZOOMSDK::PREMETAPIRET_SUCCESS:
		zn_premeeting_result = ZN_PREMETAPIRET_SUCCESS;
		break;
	default:
		break;
	}
	return zn_premeeting_result;
}
ZNDirectShareStatus Map2WrapDefine(ZOOM_SDK_NAMESPACE::DirectShareStatus status)
{
	ZNDirectShareStatus zn_direct_share_status;
	switch (status)
	{
	case ZOOMSDK::DirectShare_Unknown:
		zn_direct_share_status = ZN_DirectShare_Unknown;
		break;
	case ZOOMSDK::DirectShare_Connecting:
		zn_direct_share_status = ZN_DirectShare_Connecting;
		break;
	case ZOOMSDK::DirectShare_In_Direct_Share_Mode:
		zn_direct_share_status = ZN_DirectShare_In_Direct_Share_Mode;
		break;
	case ZOOMSDK::DirectShare_Ended:
		zn_direct_share_status = ZN_DirectShare_Ended;
		break;
	case ZOOMSDK::DirectShare_Need_MeetingID_Or_PairingCode:
		zn_direct_share_status = ZN_DirectShare_Need_MeetingID_Or_PairingCode;
		break;
	case ZOOMSDK::DirectShare_NetWork_Error:
		zn_direct_share_status = ZN_DirectShare_NetWork_Error;
		break;
	case ZOOMSDK::DirectShare_Other_Error:
		zn_direct_share_status = ZN_DirectShare_Other_Error;
		break;
	case ZOOMSDK::DirectShare_WrongMeetingID_Or_SharingKey:
		zn_direct_share_status = ZN_DirectShare_WrongMeetingID_Or_SharingKey;
		break; 
	default:
		break;
	}
	return zn_direct_share_status;
}
ZNShareStatus Map2WrapDefine(ZOOM_SDK_NAMESPACE::SharingStatus status)
{
	ZNShareStatus zn_sharing_status;
	switch (status)
	{
	case ZOOMSDK::Sharing_Self_Send_Begin:
		zn_sharing_status = ZN_Sharing_Self_Send_Begin;
		break;
	case ZOOMSDK::Sharing_Self_Send_End:
		zn_sharing_status = ZN_Sharing_Self_Send_End;
		break;
	case ZOOMSDK::Sharing_Other_Share_Begin:
		zn_sharing_status = ZN_Sharing_Other_Share_Begin;
		break;
	case ZOOMSDK::Sharing_Other_Share_End:
		zn_sharing_status = ZN_Sharing_Other_Share_End;
		break;
	case ZOOMSDK::Sharing_View_Other_Sharing:
		zn_sharing_status = ZN_Sharing_View_Other_Sharing;
		break;
	case ZOOMSDK::Sharing_Pause:
		zn_sharing_status = ZN_Sharing_Pause;
		break;
	case ZOOMSDK::Sharing_Resume:
		zn_sharing_status = ZN_Sharing_Resume;
		break;
	default:
		break;
	}
	return zn_sharing_status;
}
ZNAudioType Map2WrapDefine(ZOOM_SDK_NAMESPACE::AudioType type)
{
	ZNAudioType zn_audio_type;
	switch (type)
	{
	case ZOOMSDK::AUDIOTYPE_NONE:
		zn_audio_type = ZN_AUDIOTYPE_NONE;
		break;
	case ZOOMSDK::AUDIOTYPE_VOIP:
		zn_audio_type = ZN_AUDIOTYPE_VOIP;
		break;
	case ZOOMSDK::AUDIOTYPE_PHONE:
		zn_audio_type = ZN_AUDIOTYPE_PHONE;
		break;
	case ZOOMSDK::AUDIOTYPE_UNKNOW:
		zn_audio_type = ZN_AUDIOTYPE_UNKNOW;
		break;
	default:
		break;
	}
	return zn_audio_type;
}
ZNUserRole Map2WrapDefine(ZOOM_SDK_NAMESPACE::UserRole role)
{
	ZNUserRole zn_user_role;
	switch (role)
	{
	case ZOOMSDK::USERROLE_NONE:
		zn_user_role = ZN_USERROLE_NONE;
		break;
	case ZOOMSDK::USERROLE_HOST:
		zn_user_role = ZN_USERROLE_HOST;
		break;
	case ZOOMSDK::USERROLE_COHOST:
		zn_user_role = ZN_USERROLE_COHOST;
		break;
	case ZOOMSDK::USERROLE_PANELIST:
		zn_user_role = ZN_USERROLE_PANELIST;
		break;
	case ZOOMSDK::USERROLE_BREAKOUTROOM_MODERATOR:
		zn_user_role = ZN_USERROLE_BREAKOUTROOM_MODERATOR;
		break;
	case ZOOMSDK::USERROLE_ATTENDEE:
		zn_user_role = ZN_USERROLE_ATTENDEE;
		break;
	default:
		break;
	}
	return zn_user_role;
}
ZNSMSVerificationCodeErr Map2WrapDefine(SMSVerificationCodeErr err)
{
	ZNSMSVerificationCodeErr zn_err = ZNSMSVerificationCodeErr_Unknown;
	switch (err)
	{
	case SMSVerificationCodeErr_Unknown:
		zn_err = ZNSMSVerificationCodeErr_Unknown;
		break;
	case SMSVerificationCodeErr_Success:
		zn_err = ZNSMSVerificationCodeErr_Success;
		break;
	case SMSVerificationCodeErr_Retrieve_SendSMSFailed:
		zn_err = ZNSMSVerificationCodeErr_Retrieve_SendSMSFailed;
		break;
	case SMSVerificationCodeErr_Retrieve_InvalidPhoneNum:
		zn_err = ZNSMSVerificationCodeErr_Retrieve_InvalidPhoneNum;
		break;
	case SMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound:
		zn_err = ZNSMSVerificationCodeErr_Retrieve_PhoneNumAlreadyBound;
		break;
	case SMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent:
		zn_err = ZNSMSVerificationCodeErr_Retrieve_PhoneNumSendTooFrequent;
		break;
	case SMSVerificationCodeErr_Verify_CodeIncorrect:
		zn_err = ZNSMSVerificationCodeErr_Verify_CodeIncorrect;
		break;
	case SMSVerificationCodeErr_Verify_CodeExpired:
		zn_err = ZNSMSVerificationCodeErr_Verify_CodeExpired;
		break;
	case SMSVerificationCodeErr_Verify_UnknownError:
		zn_err = ZNSMSVerificationCodeErr_Verify_UnknownError;
		break;
	default:
		break;
	}
	return zn_err;
}
ZNSettingsNetWorkType Map2WrapDefine(ZOOM_SDK_NAMESPACE::SettingsNetWorkType role)
{
	ZNSettingsNetWorkType zn_type = ZNSETTINGS_NETWORK_UNKNOWN;
	switch (role)
	{
	case ZOOMSDK::SETTINGS_NETWORK_WIRED:
		zn_type = ZNSETTINGS_NETWORK_WIRED;
		break;
	case ZOOMSDK::SETTINGS_NETWORK_WIFI:
		zn_type = ZNSETTINGS_NETWORK_WIFI;
		break;
	case ZOOMSDK::SETTINGS_NETWORK_PPP:
		zn_type = ZNSETTINGS_NETWORK_PPP;
		break;
	case ZOOMSDK::SETTINGS_NETWORK_3G:
		zn_type = ZNSETTINGS_NETWORK_3G;
		break;
	case ZOOMSDK::SETTINGS_NETWORK_OTHERS:
		zn_type = ZNSETTINGS_NETWORK_OTHERS;
		break;
	case ZOOMSDK::SETTINGS_NETWORK_UNKNOWN:
		zn_type = ZNSETTINGS_NETWORK_UNKNOWN;
		break;
	default:
		break;
	}
	return zn_type;
}
ZNSettingConnectionType Map2WrapDefine(ZOOM_SDK_NAMESPACE::SettingConnectionType role)
{
	ZNSettingConnectionType zn_type = ZNSETTINGS_CONNECTION_TYPE_UNKNOWN;
	switch (role)
	{
	case ZOOMSDK::SETTINGS_CONNECTION_TYPE_CLOUD:
		zn_type = ZNSETTINGS_CONNECTION_TYPE_CLOUD;
		break;
	case ZOOMSDK::SETTINGS_CONNECTION_TYPE_DIRECT:
		zn_type = ZNSETTINGS_CONNECTION_TYPE_DIRECT;
		break;
	case ZOOMSDK::SETTINGS_CONNECTION_TYPE_UNKNOWN:
		zn_type = ZNSETTINGS_CONNECTION_TYPE_UNKNOWN;
		break;
	default:
		break;
	}
	return zn_type;
}

ZNRequiredInfoType Map2WrapDefine(ZOOM_SDK_NAMESPACE::IMeetingPasswordAndScreenNameHandler::RequiredInfoType type)
{
	ZNRequiredInfoType zn_type = ZNREQUIRED_INFO_TYPE_NONE;
	switch (type)
	{
	case ZOOMSDK::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_NONE:
		zn_type = ZNREQUIRED_INFO_TYPE_NONE;
		break;
	case ZOOMSDK::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_Password:
		zn_type = ZNREQUIRED_INFO_TYPE_Password;
		break;
	case ZOOMSDK::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_Password4WrongPassword:
		zn_type = ZNREQUIRED_INFO_TYPE_Password4WrongPassword;
		break;
	case ZOOMSDK::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_PasswordAndScreenName:
		zn_type = ZNREQUIRED_INFO_TYPE_PasswordAndScreenName;
		break;
	case ZOOMSDK::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_ScreenName:
		zn_type = ZNREQUIRED_INFO_TYPE_ScreenName;
		break;
	case ZOOMSDK::IMeetingPasswordAndScreenNameHandler::REQUIRED_INFO_TYPE_MeetingIDAndScreenName:
		zn_type = ZNREQUIRED_INFO_TYPE_MeetingIDAndScreenName;
		break;
	default:
		break;
	}
	return zn_type;
}
ZNWebinarNeedRegisterType Map2WrapDefine(ZOOM_SDK_NAMESPACE::IWebinarNeedRegisterHandler::WebinarNeedRegisterType type)
{
	ZNWebinarNeedRegisterType zn_type = ZNWebinarReg_NONE;
	switch (type)
	{
	case ZOOMSDK::IWebinarNeedRegisterHandler::WebinarReg_NONE:
		zn_type = ZNWebinarReg_NONE;
		break;
	case ZOOMSDK::IWebinarNeedRegisterHandler::WebinarReg_By_Register_Url:
		zn_type = ZNWebinarReg_By_Register_Url;
		break;
	case ZOOMSDK::IWebinarNeedRegisterHandler::WebinarReg_By_Email_and_DisplayName:
		zn_type = ZNWebinarReg_By_Email_and_DisplayName;
		break;
	default:
		break;
	}
	return zn_type;
}
ZNAudioCallbackActionInfo Map2WrapDefine(ZOOM_SDK_NAMESPACE::AudioCallbackActionInfo info)
{
	ZNAudioCallbackActionInfo zn_info;
	switch (info)
	{
	case ZOOMSDK::ACTION_NONE:
		zn_info = ZNACTION_INFO_NONE;
		break;
	case ZOOMSDK::ACTION_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED:
		zn_info = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_NOAUDIODEVICECONNECTTED;
		break;
	case ZOOMSDK::ACTION_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR:
		zn_info = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_COMPUTERAUDIODEVICEERROR;
		break;
	case ZOOMSDK::ACTION_CHOOSE_AUDIO_DEVICE_PHONECALLDEVICEERROR:
		zn_info = ZNACTION_INFO_CHOOSE_AUDIO_DEVICE_PHONECALLDEVICEERROR;
		break;
	case ZOOMSDK::ACTION_NEED_JOIN_VOIP:
		zn_info = ZNACTION_INFO_NEED_JOIN_VOIP;
		break;
	case ZOOMSDK::ACTION_MUTE_UNMUTE_AUDIO:
		zn_info = ZNACTION_INFO_MUTE_UNMUTE_AUDIO;
		break;
	case ZOOMSDK::ACTION_SHOW_AUDIO_SETTING_WINDOW:
		zn_info = ZNACTION_INFO_SHOW_AUDIO_SETTING_WINDOW;
		break;
	default:
		break;
	}
	return zn_info;
}

/////Covert JS define to SDK
ZOOM_SDK_NAMESPACE::SDK_LANGUAGE_ID Map2SDKDefine(ZNSDK_LANGUAGE_ID id)
{
	ZOOM_SDK_NAMESPACE::SDK_LANGUAGE_ID sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Unknow;
	switch (id)
	{
	case ZNLANGUAGE_Unknow:
		break;
	case ZNLANGUAGE_English:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_English;
		break;
	case ZNLANGUAGE_Chinese_Simplified:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Chinese_Simplified;
		break;
	case ZNLANGUAGE_Chinese_Traditional:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Chinese_Traditional;
		break;
	case ZNLANGUAGE_Japanese:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Japanese;
		break;
	case ZNLANGUAGE_Spanish:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Spanish;
		break;
	case ZNLANGUAGE_German:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_German;
		break;
	case ZNLANGUAGE_French:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_French;
		break;
	case ZNLANGUAGE_Portuguese:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Portuguese;
		break;
	case ZNLANGUAGE_Russian:
		sdk_id = ZOOM_SDK_NAMESPACE::LANGUAGE_Russian;
		break;
	default:
		break;
	}

	return sdk_id;
}
ZOOM_SDK_NAMESPACE::SDKUserType Map2SDKDefine(ZNSDKUserType type)
{
	ZOOM_SDK_NAMESPACE::SDKUserType sdk_user_type= ZOOM_SDK_NAMESPACE::SDK_UT_APIUSER;
	switch (type)
	{
	case ZNSDK_UT_APIUSER:
		sdk_user_type = ZOOM_SDK_NAMESPACE::SDK_UT_APIUSER;
		break;
	case ZNSDK_UT_NORMALUSER:
		sdk_user_type = ZOOM_SDK_NAMESPACE::SDK_UT_NORMALUSER;
		break;
	case ZNSDK_UT_WITHOUT_LOGIN:
		sdk_user_type = ZOOM_SDK_NAMESPACE::SDK_UT_WITHOUT_LOGIN;
		break;
	default:
		break;
	}
	return sdk_user_type;
}
ZOOM_SDK_NAMESPACE::LeaveMeetingCmd Map2SDKDefine(ZNLeaveMeetingCmd cmd)
{
	ZOOM_SDK_NAMESPACE::LeaveMeetingCmd sdk_leave_meeting_cmd;
	switch (cmd)
	{
	case ZNLEAVE_MEETING:
		sdk_leave_meeting_cmd = ZOOM_SDK_NAMESPACE::LEAVE_MEETING;
		break;
	case ZNEND_MEETING:
		sdk_leave_meeting_cmd = ZOOM_SDK_NAMESPACE::END_MEETING;
		break;
	default:
		break;
	}
	return sdk_leave_meeting_cmd;
}
ZOOM_SDK_NAMESPACE::ZoomUserType Map2SDKDefine(ZNZoomUserType type)
{
	ZOOM_SDK_NAMESPACE::ZoomUserType sdk_zoom_user_type;
	switch (type)
	{
	case ZNZoomUserType_APIUSER:
		sdk_zoom_user_type = ZOOM_SDK_NAMESPACE::ZoomUserType_APIUSER;
		break;
	case ZNZoomUserType_EMAIL_LOGIN:
		sdk_zoom_user_type = ZOOM_SDK_NAMESPACE::ZoomUserType_EMAIL_LOGIN;
		break;
	case ZNZoomUserType_FACEBOOK:
		sdk_zoom_user_type = ZOOM_SDK_NAMESPACE::ZoomUserType_FACEBOOK;
		break;
	case ZNZoomUserType_GoogleOAuth:
		sdk_zoom_user_type = ZOOM_SDK_NAMESPACE::ZoomUserType_GoogleOAuth;
		break;
	case ZNZoomUserType_SSO:
		sdk_zoom_user_type = ZOOM_SDK_NAMESPACE::ZoomUserType_SSO;
		break;
	case ZNZoomUserType_Unknown:
		sdk_zoom_user_type = ZOOM_SDK_NAMESPACE::ZoomUserType_Unknown;
		break;
	default:
		break;
	}
	return sdk_zoom_user_type;
}
ZOOM_SDK_NAMESPACE::SDKFloatVideoType Map2SDKDefine(ZNSDKFloatVideoType type)
{
	ZOOM_SDK_NAMESPACE::SDKFloatVideoType sdk_float_video_type;
	switch (type)
	{
	case ZN_FLOATVIDEO_List:
		sdk_float_video_type = ZOOM_SDK_NAMESPACE::FLOATVIDEO_List;
		break;
	case ZN_FLOATVIDEO_Small:
		sdk_float_video_type = ZOOM_SDK_NAMESPACE::FLOATVIDEO_Small;
		break;
	case ZN_FLOATVIDEO_Large:
		sdk_float_video_type = ZOOM_SDK_NAMESPACE::FLOATVIDEO_Large;
		break;
	case ZN_FLOATVIDEO_Minimize:
		sdk_float_video_type = ZOOM_SDK_NAMESPACE::FLOATVIDEO_Minimize;
		break;
	default:
		break;
	}
	return sdk_float_video_type;
}
ZOOM_SDK_NAMESPACE::SDKViewType Map2SDKDefine(ZNSDKViewType type)
{
	ZOOM_SDK_NAMESPACE::SDKViewType sdk_view_type;
	switch (type)
	{
	case ZNSDK_FIRST_VIEW:
		sdk_view_type = ZOOM_SDK_NAMESPACE::SDK_FIRST_VIEW;
		break;
	case ZNSDK_SECOND_VIEW:
		sdk_view_type = ZOOM_SDK_NAMESPACE::SDK_SECOND_VIEW;
		break;
	default:
		break;
	}
	return sdk_view_type;
}
ZOOM_SDK_NAMESPACE::AnnotationToolType Map2SDKDefine(ZNAnnotationToolType type)
{
	ZOOM_SDK_NAMESPACE::AnnotationToolType sdk_annotation_tool_type;
	switch (type)
	{
	case ZN_ANNOTOOL_NONE_DRAWING:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_NONE_DRAWING;
		break;
	case ZN_ANNOTOOL_PEN:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_PEN;
		break;
	case ZN_ANNOTOOL_HIGHLIGHTER:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_HIGHLIGHTER;
		break;
	case ZN_ANNOTOOL_AUTO_LINE:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_LINE;
		break;
	case ZN_ANNOTOOL_AUTO_RECTANGLE:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_RECTANGLE;
		break;
	case ZN_ANNOTOOL_AUTO_ELLIPSE:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_ELLIPSE;
		break;
	case ZN_ANNOTOOL_AUTO_ARROW:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_ARROW;
		break;
	case ZN_ANNOTOOL_AUTO_RECTANGLE_FILL:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_RECTANGLE_FILL;
		break;
	case ZN_ANNOTOOL_AUTO_ELLIPSE_FILL:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_ELLIPSE_FILL;
		break;
	case ZN_ANNOTOOL_SPOTLIGHT:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_SPOTLIGHT;
		break;
	case ZN_ANNOTOOL_ARROW:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_ARROW;
		break;
	case ZN_ANNOTOOL_ERASER:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_ERASER;
		break;
	case ZN_ANNOTOOL_TEXTBOX:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_TEXTBOX;
		break;
	case ZN_ANNOTOOL_PICKER:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_PICKER;
		break;
	case ZN_ANNOTOOL_AUTO_RECTANGLE_SEMI_FILL:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_RECTANGLE_SEMI_FILL;
		break;
	case ZN_ANNOTOOL_AUTO_ELLIPSE_SEMI_FILL:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_ELLIPSE_SEMI_FILL;
		break;
	case ZN_ANNOTOOL_AUTO_DOUBLE_ARROW:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_DOUBLE_ARROW;
		break;
	case ZN_ANNOTOOL_AUTO_DIAMOND:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_DIAMOND;
		break;
	case ZN_ANNOTOOL_AUTO_STAMP_ARROW:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_STAMP_ARROW;
		break;
	case ZN_ANNOTOOL_AUTO_STAMP_CHECK:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_STAMP_CHECK;
		break;
	case ZN_ANNOTOOL_AUTO_STAMP_X:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_STAMP_X;
		break;
	case ZN_ANNOTOOL_AUTO_STAMP_STAR:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_STAMP_STAR;
		break;
	case ZN_ANNOTOOL_AUTO_STAMP_HEART:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_STAMP_HEART;
		break;
	case ZN_ANNOTOOL_AUTO_STAMP_QM:
		sdk_annotation_tool_type = ZOOM_SDK_NAMESPACE::ANNOTOOL_AUTO_STAMP_QM;
		break;
	default:
		break;
	}
	return sdk_annotation_tool_type;
}
ZOOM_SDK_NAMESPACE::AnnotationClearType Map2SDKDefine(ZNAnnotationClearType type)
{
	ZOOM_SDK_NAMESPACE::AnnotationClearType sdk_annotation_clear_type;
	switch (type)
	{
	case ZN_ANNOCLEAR_ALL:
		sdk_annotation_clear_type = ZOOM_SDK_NAMESPACE::ANNOCLEAR_ALL;
		break;
	case ZN_ANNOCLEAR_SELF:
		sdk_annotation_clear_type = ZOOM_SDK_NAMESPACE::ANNOCLEAR_SELF;
		break;
	case ZN_ANNOCLEAR_OTHER:
		sdk_annotation_clear_type = ZOOM_SDK_NAMESPACE::ANNOCLEAR_OTHER;
		break;
	default:
		break;
	}
	return sdk_annotation_clear_type;
}
ZOOM_SDK_NAMESPACE::SettingTabPage Map2SDKDefine(ZNSettingTabPage tabPage)
{
	ZOOM_SDK_NAMESPACE::SettingTabPage sdk_tabPage;
	switch (tabPage)
	{
	case ZN_SettingTabPage_General:
		sdk_tabPage = ZOOM_SDK_NAMESPACE::SettingTabPage_General;
		break;
	case ZN_SettingTabPage_Audio:
		sdk_tabPage = ZOOM_SDK_NAMESPACE::SettingTabPage_Audio;
		break;
	case ZN_SettingTabPage_Video:
		sdk_tabPage = ZOOM_SDK_NAMESPACE::SettingTabPage_Video;
		break;
	default:
		break;
	}
	return sdk_tabPage;
}
ZOOM_SDK_NAMESPACE::SDKCustomizedStringType Map2SDKDefine(ZNSDKCustomizedStringType type)
{
	ZOOM_SDK_NAMESPACE::SDKCustomizedStringType sdk_type;
	switch (type)
	{
	case ZN_SDK_Customized_LiveStream_MenuString_LiveOn_String:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_LiveStream_MenuString_LiveOn_String;
		break;
	case ZN_SDK_Customized_LiveStream_MenuString_LiveView_String:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_LiveStream_MenuString_LiveView_String;
		break;
	case ZN_SDK_Customized_LiveStream_MenuString_LiveStop_String:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_LiveStream_MenuString_LiveStop_String;
		break;
	case ZN_SDK_Customized_LiveStream_MenuString_CopyURL_String:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_LiveStream_MenuString_CopyURL_String;
		break;
	case ZN_SDK_Customized_Title_App:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_Title_App;
		break;
	case ZN_SDK_Customized_Title_ZoomVideo:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_Title_ZoomVideo;
		break;
	case ZN_SDK_Customized_Title_FreeZoomVideo:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_Title_FreeZoomVideo;
		break;
	case ZN_SDK_Customized_Title_ViewOnly_ZoomVideo:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_Title_ViewOnly_ZoomVideo;
		break;
	case ZN_SDK_Customized_Title_ViewOnly_FreeZoomVideo:
		sdk_type = ZOOM_SDK_NAMESPACE::SDK_Customized_Title_ViewOnly_FreeZoomVideo;
		break;
	default:
		break;
	}
	return sdk_type;
}
ZOOM_SDK_NAMESPACE::SDKCustomizedURLType Map2SDKDefine(ZNSDKCustomizedURLType type)
{
	ZOOM_SDK_NAMESPACE::SDKCustomizedURLType sdk_type;
	switch (type)
	{
	case ZN_SDKCustomizedURL_VITRULBG_HELP:
		sdk_type = ZOOM_SDK_NAMESPACE::SDKCustomizedURL_VITRULBG_HELP;
		break;
	case ZN_SDKCustomizedURL_VITRULBG_LEARN_MORE:
		sdk_type = ZOOM_SDK_NAMESPACE::SDKCustomizedURL_VITRULBG_LEARN_MORE;
		break;
	case ZN_SDKCustomizedURL_SUPPORTURL:
		sdk_type = ZOOM_SDK_NAMESPACE::SDKCustomizedURL_SUPPORTURL;
		break;
	default:
		break;
	}
	return sdk_type;
}
ZOOM_SDK_NAMESPACE::H323DeviceType Map2SDKDefine(ZNH323DeviceType type)
{
	ZOOM_SDK_NAMESPACE::H323DeviceType sdk_h323_type;
	switch (type)
	{
	case ZN_H323DeviceType_Unknown:
		sdk_h323_type = ZOOM_SDK_NAMESPACE::H323DeviceType_Unknown;
		break;
	case ZN_H323DeviceType_H323:
		sdk_h323_type = ZOOM_SDK_NAMESPACE::H323DeviceType_H323;
		break;
	case ZN_H323DeviceType_SIP:
		sdk_h323_type = ZOOM_SDK_NAMESPACE::H323DeviceType_SIP;
		break;
	case ZN_H323DeviceType_BOTH:
		sdk_h323_type = ZOOM_SDK_NAMESPACE::H323DeviceType_BOTH;
		break;
	default:
		break;
	}
	return sdk_h323_type;
}
ZOOM_SDK_NAMESPACE::SDKMinimizeUIMode Map2SDKDefine(ZNSDKMinimizeUIMode mode)
{
	ZOOM_SDK_NAMESPACE::SDKMinimizeUIMode sdk_mode;
	switch (mode)
	{
	case ZN_MinimizeUIMode_NONE:
		sdk_mode = ZOOM_SDK_NAMESPACE::MinimizeUIMode_NONE;
		break;
	case ZN_MinimizeUIMode_SHARE:
		sdk_mode = ZOOM_SDK_NAMESPACE::MinimizeUIMode_SHARE;
		break;
	case ZN_MinimizeUIMode_VIDEO:
		sdk_mode = ZOOM_SDK_NAMESPACE::MinimizeUIMode_VIDEO;
		break;
	case ZN_MinimizeUIMode_ACTIVESPEAKER:
		sdk_mode = ZOOM_SDK_NAMESPACE::MinimizeUIMode_ACTIVESPEAKER;
		break;
	default:
		break;
	}
	return sdk_mode;
}
ZOOM_SDK_NAMESPACE::SDK_APP_Locale Map2SDKDefine(ZNSDK_APP_Locale locale)
{
	ZOOM_SDK_NAMESPACE::SDK_APP_Locale sdk_locale;
	switch (locale)
	{
	case ZNSDK_APP_Locale_Default:
		sdk_locale = ZOOM_SDK_NAMESPACE::SDK_APP_Locale_Default;
		break;
	case ZNSDK_APP_Locale_CN:
		sdk_locale = ZOOM_SDK_NAMESPACE::SDK_APP_Locale_CN;
		break;
	default:
		break;
	}
	return sdk_locale;
}
std::string wStr2Str(const ZoomSTRING& s)
{

	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), slength, 0, 0, 0, 0);
	std::string r(len, '\0');
	WideCharToMultiByte(CP_UTF8, 0, s.c_str(), slength, &r[0], len, 0, 0);
	return r;
}
ZoomSTRING Str2WStr(const std::string& s)
{
	std::string strLocale = setlocale(LC_ALL, "");
	const char* chSrc = s.c_str();
	size_t nDestSize = mbstowcs(NULL, chSrc, 0) + 1;
	wchar_t* wchDest = new wchar_t[nDestSize];
	wmemset(wchDest, 0, nDestSize);
	mbstowcs(wchDest, chSrc, nDestSize);
	std::wstring wstrResult = wchDest;
	delete[]wchDest;
	setlocale(LC_ALL, strLocale.c_str());
	return wstrResult;
}
