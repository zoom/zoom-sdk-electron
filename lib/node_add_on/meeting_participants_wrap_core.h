#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"
#if (defined _WIN32)
#include "win/wrap/meeting_service_components_wrap/meeting_participants_ctrl_wrap.h"

class ZUserInfoWrap
{
public:
	ZUserInfoWrap();
	virtual ~ZUserInfoWrap();
	

	ZoomSTRING GetUserNamme();
	bool IsH323User();
	bool IsHost();
	unsigned int GetUserID();
	bool IsVideoOn();
	bool IsAudioMuted();
	ZNAudioType GetAudioJoinType();
	bool IsMySelf();
	bool IsInWaitingRoom();
	bool IsRaiseHand();
	ZNUserRole GetUserRole();
	bool IsPurePhoneUser();
	ZoomSTRING GetAudioVoiceLevel();
	bool IsClosedCaptionSender();
	bool GetWebinarAttendeeStauts();
	bool IsValidUserID(unsigned int userid);
	ZoomSTRING GetParticipantID();
private:
	ZOOM_SDK_NAMESPACE::IUserInfo* m_pUserInfo;
};
#endif

class ZMeetingParticipantsWrap
{
public:
	ZMeetingParticipantsWrap();
	virtual ~ZMeetingParticipantsWrap();
	void Init();
	void Uninit();
	void SetSink(ZNativeSDKMeetingParticipantsWrapSink* pSink);
	ZNList<unsigned int> GetParticipantsList();
	
	ZNUserInfomation GetUserInfomationByUserID(unsigned int userid);

	//callback

	void onUserJoin(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList);
	void onUserLeft(ZNList<unsigned int> lstUserID, ZoomSTRING strUserList);
	void onHostChangeNotification(unsigned int userId);
private:
	ZNativeSDKMeetingParticipantsWrapSink* m_pSink;
#if (defined _WIN32)
	ZUserInfoWrap m_user_info;
#endif
};

