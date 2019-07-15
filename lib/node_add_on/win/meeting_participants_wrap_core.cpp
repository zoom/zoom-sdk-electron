
#include "../meeting_participants_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_participants_ctrl_wrap.h"
#include "zoom_native_to_wrap.h"

extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;
class ZMeetingParticipantsCtrlEvent : public ZOOM_SDK_NAMESPACE::IMeetingParticipantsCtrlEvent
{
public:
	void SetOwner(ZMeetingParticipantsWrap* obj) { owner_ = obj; }
	virtual void onUserJoin(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
	{
		if (owner_) {
			ZNList<ZoomSTRING> userId_list;
			ZoomSTRING zn_strUserList = L"";
			if(strUserList)
				zn_strUserList = strUserList;
			for (int i = 0; i < lstUserID->GetCount(); ++i)
			{

				ZoomSTRING zn_userid;
				UINT64 userid = lstUserID->GetItem(i);
				wchar_t temp[1024];
				int radix = 10;
				_ui64tow(userid, temp, radix);
				zn_userid = temp;

				userId_list.add(zn_userid);
			}
			
			owner_->onUserJoin(userId_list, zn_strUserList);
			
		}
	}
	virtual void onUserLeft(ZOOM_SDK_NAMESPACE::IList<unsigned int >* lstUserID, const wchar_t* strUserList)
	{
		if (owner_) {
			ZNList<ZoomSTRING> userId_list;
			ZoomSTRING zn_strUserList = L"";
			if (strUserList)
				zn_strUserList = strUserList;
			for (int i = 0; i < lstUserID->GetCount(); ++i)
			{

				ZoomSTRING zn_userid;
				UINT64 userid = lstUserID->GetItem(i);
				wchar_t temp[1024];
				int radix = 10;
				_ui64tow(userid, temp, radix);
				zn_userid = temp;

				userId_list.add(zn_userid);
			}

			owner_->onUserLeft(userId_list, zn_strUserList);

		}
	}
	virtual void onHostChangeNotification(unsigned int userId)
	{
		if (owner_) {
			ZoomSTRING zn_userid;
			UINT64 userid = userId;
			wchar_t temp[1024];
			int radix = 10;
			_ui64tow(userid, temp, radix);
			zn_userid = temp;
			owner_->onHostChangeNotification(zn_userid);

		}
	}
	virtual void onLowOrRaiseHandStatusChanged(bool bLow, unsigned int userid)
	{

	}
	virtual void onUserNameChanged(unsigned int userId, const wchar_t* userName)
	{

	}
	virtual void onCoHostChangeNotification(unsigned int userId, bool isCoHost)
	{

	}
private:
	ZMeetingParticipantsWrap* owner_;
};

static ZMeetingParticipantsCtrlEvent g_meeting_participants_ctrl_event;


ZMeetingParticipantsWrap::ZMeetingParticipantsWrap()
{
	g_meeting_participants_ctrl_event.SetOwner(this);
	m_pSink = 0;
}
ZMeetingParticipantsWrap::~ZMeetingParticipantsWrap()
{
	Uninit();
	m_pSink = 0;
	g_meeting_participants_ctrl_event.SetOwner(NULL);
}
void ZMeetingParticipantsWrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().SetEvent(&g_meeting_participants_ctrl_event);
}
void ZMeetingParticipantsWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetMeetingParticipantsController().Uninit_Wrap();
}
void ZMeetingParticipantsWrap::SetSink(IZNativeSDKMeetingParticipantsWrapSink* pSink)
{
	m_pSink = pSink;
}

void ZMeetingParticipantsWrap::onUserJoin(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList)
{
	if (m_pSink)
		m_pSink->onUserJoin(lstUserID, strUserList);
}
void ZMeetingParticipantsWrap::onUserLeft(ZNList<ZoomSTRING> lstUserID, ZoomSTRING strUserList)
{
	if (m_pSink)
		m_pSink->onUserLeft(lstUserID, strUserList);
}
void ZMeetingParticipantsWrap::onHostChangeNotification(ZoomSTRING userId)
{
	if (m_pSink)
		m_pSink->onHostChangeNotification(userId);
}