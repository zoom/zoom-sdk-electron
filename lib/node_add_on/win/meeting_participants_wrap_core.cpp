
#include "../meeting_participants_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZUserInfoWrap::ZUserInfoWrap()
{
	m_pUserInfo = NULL;
}
ZUserInfoWrap::~ZUserInfoWrap()
{
	m_pUserInfo = NULL;
}

ZMeetingParticipantsWrap::ZMeetingParticipantsWrap()
{
	SDKEventWrapMgr::GetInst().m_meetingParticipantsCtrlEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingParticipantsWrap::~ZMeetingParticipantsWrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingParticipantsCtrlEvent.SetOwner(NULL);
}
void ZMeetingParticipantsWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingParticipantsCtrlEvent);
}
void ZMeetingParticipantsWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().Uninit_Wrap();
}
void ZMeetingParticipantsWrap::SetSink(ZNativeSDKMeetingParticipantsWrapSink* pSink)
{
	m_pSink = pSink;
}

void ZMeetingParticipantsWrap::onUserJoin(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList)
{
	if (m_pSink)
		m_pSink->onUserJoin(lstUserID, strUserList);
}
void ZMeetingParticipantsWrap::onUserLeft(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList)
{
	if (m_pSink)
		m_pSink->onUserLeft(lstUserID, strUserList);
}
void ZMeetingParticipantsWrap::onHostChangeNotification(unsigned int userId)
{
	if (m_pSink)
		m_pSink->onHostChangeNotification(userId);
}
ZNList<unsigned int> ZMeetingParticipantsWrap::GetParticipantsList()
{
	ZNList<unsigned int> userId_list;
	ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().GetParticipantsList();
	if (NULL == lstUserID)
		return userId_list;
	for (int i = 0; i < lstUserID->GetCount(); ++i)
	{

		unsigned int zn_userid;
		
		zn_userid = lstUserID->GetItem(i);

		userId_list.push_back(zn_userid);
	}
	return userId_list;

}
ZNUserInfomation ZMeetingParticipantsWrap::GetUserInfomationByUserID(unsigned int userid)
{
	ZNUserInfomation zn_UserInfomation;

	if (!m_user_info.IsValidUserID(userid))
	{
		zn_UserInfomation.userInfoType = ZN_FAKE_USERINFO;
	}
	else
	{
		zn_UserInfomation.userName = m_user_info.GetUserNamme();
		zn_UserInfomation.isH323User = m_user_info.IsH323User();
		zn_UserInfomation.isHost = m_user_info.IsHost();
		zn_UserInfomation.userID = m_user_info.GetUserID();
		zn_UserInfomation.isVideoOn = m_user_info.IsVideoOn();
		zn_UserInfomation.isAudioMuted = m_user_info.IsAudioMuted();
		zn_UserInfomation.audioJoinType = m_user_info.GetAudioJoinType();
		zn_UserInfomation.isMySelf = m_user_info.IsMySelf();
		zn_UserInfomation.isInWaitingRoom = m_user_info.IsInWaitingRoom();
		zn_UserInfomation.isRaiseHand = m_user_info.IsRaiseHand();
		zn_UserInfomation.userRole = m_user_info.GetUserRole();
		zn_UserInfomation.isPurePhoneUser = m_user_info.IsPurePhoneUser();
		zn_UserInfomation.AudioVoiceLevel = m_user_info.GetAudioVoiceLevel();
		zn_UserInfomation.isClosedCaptionSender = m_user_info.IsClosedCaptionSender();
		zn_UserInfomation.webinarAttendeeStatus = m_user_info.GetWebinarAttendeeStauts();
		zn_UserInfomation.participantID = m_user_info.GetParticipantID();
		zn_UserInfomation.userInfoType = ZN_REAL_USERINFO;
	}

	return zn_UserInfomation;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool ZUserInfoWrap::IsValidUserID(unsigned int userid)
{

	bool bIsValid = false;
	ZOOM_SDK_NAMESPACE::IUserInfo* userinfo = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().GetUserByUserID(userid);
	if (userinfo)
	{
		m_pUserInfo = userinfo;
		bIsValid = true;
	}
	else
	{
		m_pUserInfo = NULL;
	}
	return bIsValid;
}

ZoomSTRING ZUserInfoWrap::GetUserNamme()
{
	
	ZoomSTRING zn_user_name;
	if (m_pUserInfo)
	{
		zn_user_name = m_pUserInfo->GetUserNameA();
	}
	return zn_user_name;
}
bool ZUserInfoWrap::IsH323User()
{
	
	bool zn_is_h323user = false;
	if (m_pUserInfo)
	{
		zn_is_h323user = m_pUserInfo->IsH323User();
	}
	return zn_is_h323user;
}
bool ZUserInfoWrap::IsHost()
{
	
	bool zn_is_host = false;
	if (m_pUserInfo)
	{
		zn_is_host = m_pUserInfo->IsHost();
	}
	return zn_is_host;
}
unsigned int ZUserInfoWrap::GetUserID()
{
	
	unsigned int user_id = 0;

	if (m_pUserInfo)
	{
		user_id = m_pUserInfo->GetUserID();
	}
	return user_id;
}
bool ZUserInfoWrap::IsVideoOn()
{
	
	bool zn_is_on = false;
	
	if (m_pUserInfo)
	{
		zn_is_on = m_pUserInfo->IsVideoOn();
	}
	return zn_is_on;
}
bool ZUserInfoWrap::IsAudioMuted()
{
	
	bool zn_is_muted = true;

	if (m_pUserInfo)
	{
		zn_is_muted = m_pUserInfo->IsAudioMuted();
	}
	return zn_is_muted;
}
ZNAudioType ZUserInfoWrap::GetAudioJoinType()
{
	return Map2WrapDefine(m_pUserInfo ? m_pUserInfo->GetAudioJoinType() : ZOOM_SDK_NAMESPACE::AUDIOTYPE_NONE);
}
bool ZUserInfoWrap::IsMySelf()
{
	
	bool zn_is_myself = false;
	if (m_pUserInfo)
	{
		zn_is_myself = m_pUserInfo->IsMySelf();
	}
	return zn_is_myself;
}
bool ZUserInfoWrap::IsInWaitingRoom()
{
	
	bool zn_is_in = false;
	
	if (m_pUserInfo)
	{
		zn_is_in = m_pUserInfo->IsInWaitingRoom();
	}
	return zn_is_in;
}
bool ZUserInfoWrap::IsRaiseHand()
{
	
	bool zn_is_raise = false;

	if (m_pUserInfo)
	{
		zn_is_raise = m_pUserInfo->IsRaiseHand();
	}
	return zn_is_raise;
}
ZNUserRole ZUserInfoWrap::GetUserRole()
{
	return Map2WrapDefine(m_pUserInfo ? m_pUserInfo->GetUserRole() : ZOOM_SDK_NAMESPACE::USERROLE_NONE);
}
bool ZUserInfoWrap::IsPurePhoneUser()
{
	
	bool zn_is_pure_phone = false;
	
	if (m_pUserInfo)
	{
		zn_is_pure_phone = m_pUserInfo->IsPurePhoneUser();
	}
	return zn_is_pure_phone;
}
bool ZUserInfoWrap::IsClosedCaptionSender()
{
	
	bool zn_is_ = false;
	
	if (m_pUserInfo)
	{
		zn_is_ = m_pUserInfo->IsClosedCaptionSender();
	}
	return zn_is_;
}
bool ZUserInfoWrap::GetWebinarAttendeeStauts()
{
	
	if (NULL == m_pUserInfo)
		return false;
	ZOOM_SDK_NAMESPACE::WebinarAttendeeStatus* p_webinarAttendeeStatus = m_pUserInfo->GetWebinarAttendeeStauts();
	if (p_webinarAttendeeStatus)
	{
		bool zn_is_allow_talk = p_webinarAttendeeStatus->allow_talk;
		return zn_is_allow_talk;
	}
	else
	{
		return false;
	}
}
ZoomSTRING ZUserInfoWrap::GetAudioVoiceLevel()
{
	int audio_voice_level = 0;

	if (m_pUserInfo)
		audio_voice_level = m_pUserInfo->GetAudioVoiceLevel();
	wchar_t temp[1024];
	int radix = 10;
	_itow(audio_voice_level, temp, radix);
	ZoomSTRING zn_audio_voice_level = temp;
	return zn_audio_voice_level;
}
ZoomSTRING ZUserInfoWrap::GetParticipantID()
{

	ZoomSTRING zn_participant_id;
	if (m_pUserInfo)
	{
		const wchar_t* temp_partiipant_id = m_pUserInfo->GetParticipantID();
		if (temp_partiipant_id)
			zn_participant_id = temp_partiipant_id;
	}
	return zn_participant_id;
}