#pragma once
#include "../common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IMeetingParticipantsController* InitIMeetingParticipantsControllerFunc(IMeetingParticipantsCtrlEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIMeetingParticipantsControllerFunc(IMeetingParticipantsController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IMeetingParticipantsController, IMeetingParticipantsCtrlEvent)
NORMAL_CLASS(IMeetingParticipantsController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IMeetingParticipantsController, IMeetingServiceWrap)
virtual SDKError SetEvent(IMeetingParticipantsCtrlEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual IList<unsigned int >* GetParticipantsList() = 0;
DEFINE_FUNC_0(GetParticipantsList, IList<unsigned int >*)
//virtual IUserInfo* GetUserByUserID(unsigned int userid) = 0;
DEFINE_FUNC_1(GetUserByUserID, IUserInfo*, unsigned int, userid)
//virtual SDKError LowerAllHands() = 0;
DEFINE_FUNC_0(LowerAllHands, SDKError)
//virtual SDKError ChangeUserName(const unsigned int userid, const wchar_t* userName, bool bSaveUserName) = 0;
DEFINE_FUNC_3(ChangeUserName, SDKError, const unsigned int, userid, const wchar_t*, userName, bool, bSaveUserName)

//virtual SDKError LowerHand(unsigned int userid) = 0;
DEFINE_FUNC_1(LowerHand, SDKError, unsigned int, userid)
//virtual SDKError RaiseHand() = 0;
DEFINE_FUNC_0(RaiseHand, SDKError)
//virtual SDKError MakeHost(unsigned int userid) = 0;
DEFINE_FUNC_1(MakeHost, SDKError, unsigned int, userid)
//virtual SDKError ExpelUser(unsigned int userid) = 0;
DEFINE_FUNC_1(ExpelUser, SDKError, unsigned int, userid)
//virtual SDKError ReclaimHost() = 0;
DEFINE_FUNC_0(ReclaimHost, SDKError)
//virtual SDKError CanReclaimHost(bool& bCanReclaimHost) = 0;
DEFINE_FUNC_1(CanReclaimHost, SDKError, bool&, bCanReclaimHost)
//virtual SDKError ReclaimHostByHostKey(const wchar_t* host_key) = 0;
DEFINE_FUNC_1(ReclaimHostByHostKey, SDKError, const wchar_t*, host_key)

//virtual SDKError CanbeCohost(unsigned int userid) = 0;
DEFINE_FUNC_1(CanbeCohost, SDKError, unsigned int, userid)
//virtual SDKError AssignCoHost(unsigned int userid) = 0;
DEFINE_FUNC_1(AssignCoHost, SDKError, unsigned int, userid)
//virtual SDKError RevokeCoHost(unsigned int userid) = 0;
DEFINE_FUNC_1(RevokeCoHost, SDKError, unsigned int, userid)

//virtual void onUserJoin(IList<unsigned int >* lstUserID, const wchar_t* strUserList = NULL) = 0;
CallBack_FUNC_2(onUserJoin, IList<unsigned int >*, lstUserID, const wchar_t*, strUserList)
//virtual void onUserLeft(IList<unsigned int >* lstUserID, const wchar_t* strUserList = NULL) = 0;
CallBack_FUNC_2(onUserLeft, IList<unsigned int >*, lstUserID, const wchar_t*, strUserList)
//virtual void onHostChangeNotification(unsigned int userId) = 0;
CallBack_FUNC_1(onHostChangeNotification, unsigned int, userId)
//virtual void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userid) = 0;
CallBack_FUNC_2(onLowOrRaiseHandStatusChanged, bool, bLow, unsigned int, userid)
//virtual void onUserNameChanged(unsigned int userId, const wchar_t* userName) = 0;
CallBack_FUNC_2(onUserNameChanged, unsigned int, userId, const wchar_t*, userName)
//virtual void onCoHostChangeNotification(unsigned int userId, bool isCoHost) = 0;
CallBack_FUNC_2(onCoHostChangeNotification, unsigned int, userId, bool, isCoHost)
END_CLASS_DEFINE(IMeetingParticipantsController)
END_ZOOM_SDK_NAMESPACE