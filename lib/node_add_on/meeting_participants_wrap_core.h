#pragma once
#include "zoom_native_sdk_wrap_core_def.h"
#include "zoom_sinks_wrap_class.h"

#if (defined _WIN32)
class ZUserInfoWrap
{
public:
	ZUserInfoWrap() {}
	virtual ~ZUserInfoWrap() {}
	

	ZoomSTRING GetUserNamme(unsigned int userid);
	ZoomSTRING GetEmail(unsigned int userid);
	bool IsHost(unsigned int userid);
	unsigned int GetUserID(unsigned int userid);
	bool IsVideoOn(unsigned int userid);
	bool IsAudioMuted(unsigned int userid);
	ZNAudioType GetAudioJoinType(unsigned int userid);
	bool IsMySelf(unsigned int userid);
	bool IsInWaitingRoom(unsigned int userid);
	bool IsRaiseHand(unsigned int userid);
	ZNUserRole GetUserRole(unsigned int userid);
	bool IsPurePhoneUser(unsigned int userid);
	ZoomSTRING GetAudioVoiceLevel(unsigned int userid);
	bool IsClosedCaptionSender(unsigned int userid);
	bool GetWebinarAttendeeStauts(unsigned int userid);
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

