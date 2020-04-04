#include "sdk_wrap.h"
#include "schedule_meeting_item_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE

IScheduleMeetingItemWrap::~IScheduleMeetingItemWrap()
{
	UnInit();
}

void IScheduleMeetingItemWrap::Init(IScheduleMeetingItem* pObj)
{
	if (pObj)
	{
		if (m_obj) 
		{
			UnInit();
		}

		m_obj = pObj;
		if (m_obj)
		{
			m_obj->SetEvent(this);
		}
	}
}

void IScheduleMeetingItemWrap::UnInit()
{
	if (m_obj)
	{
		m_obj->SetEvent(NULL);
		m_obj = NULL;
	}
}

time_t IScheduleMeetingItemWrap::GetCurrentStartTime()
{
	if (m_obj)
	{
		return m_obj->GetCurrentStartTime();
	}

	time_t result;
	ZeroMemory(&result, sizeof(time_t));
	return result;
}

IMPL_FUNC_1(IScheduleMeetingItem, SelectStartTime, SDKError, time_t, time, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SetDurationInMinutes, SDKError, int, duration, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SelectRecurringMeeting, SDKError, bool, select, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SelectHostVideoOnOrOff, SDKError, bool, bOn, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SelectAttendeeVideoOnOrOff, SDKError, bool, bOn, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, IsSupportAudioType, SDKError, SCHEDULEAUDIOTYPE, audio_type, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SelectAudioType, SDKError, SCHEDULEAUDIOTYPE, audio_type, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableWaitingRoom, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(IScheduleMeetingItem, EnableMeetingToPublic, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(IScheduleMeetingItem, EnableLanguageInterpretation, SDKError, bool, bEnable, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(IScheduleMeetingItem, SetInterpreterInfoList, SDKError, IList<IInterpreterInfo* >*, lst_interpreters, SDKERR_UNINITIALIZE)
IMPL_FUNC_1(IScheduleMeetingItem, SetAlternativeHostList, SDKError, IList<IAlternativeHostInfo* >*, lst_althosts, SDKERR_UNINITIALIZE)
IMPL_FUNC_0(IScheduleMeetingItem, GetScheduleTelAudioHelper, ISelectMeetingItemTelAudioHelper*, NULL);
IMPL_FUNC_1(IScheduleMeetingItem, SetMeetingTopic, SDKError, const wchar_t*, topic, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableMeetingPassword, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SetMeetingPassword, SDKError, const wchar_t*, meetingPsw, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableJoinBeforeHost, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableMuteUponEntry, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableScheduleWithPmi, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableOnlySignedInUserCanJoin, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SetSpecifiedDomainCanJoin, SDKError, const wchar_t*, specified_domain_can_join, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableHostInChina, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, EnableAutoRecord, SDKError, bool, bEnable, SDKERR_UNINITIALIZE);
IMPL_FUNC_1(IScheduleMeetingItem, SelectAutoRecordType, SDKError, SCHEDULERECTYPE, type, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(IScheduleMeetingItem, GetScheduleForHelper, ISelectMeetingItemScheduleForHelper*, NULL);
//IMPL_FUNC_0(IScheduleMeetingItem, GetCurrentStartTime, time_t, {});
IMPL_FUNC_0(IScheduleMeetingItem, GetDurationInMinutes, int, 0);
IMPL_FUNC_0(IScheduleMeetingItem, IsRecurringMeetingSelected, bool, false);
IMPL_FUNC_0(IScheduleMeetingItem, IsHostVideoOnOrOff, bool, false);
IMPL_FUNC_0(IScheduleMeetingItem, IsAttendeeVideoOnOrOff, bool, false);
IMPL_FUNC_1(IScheduleMeetingItem, GetSelectedAudioType, SDKError, SCHEDULEAUDIOTYPE&, type, SDKERR_UNINITIALIZE);
IMPL_FUNC_0(IScheduleMeetingItem, GetQueryTelAudioInfoHelper, IQueryMeetingItemTelAudioInfoHelper*, NULL);
IMPL_FUNC_0(IScheduleMeetingItem, GetMeetingTopic, const wchar_t*, NULL);
IMPL_FUNC_1(IScheduleMeetingItem, IsMeetingPasswordEnabled, bool, bool&, can_change, false);
IMPL_FUNC_0(IScheduleMeetingItem, GetMeetingPassword, const wchar_t*, NULL);
IMPL_FUNC_1(IScheduleMeetingItem, IsJoinBeforeHostEnabled, bool, bool&, can_change, false);
IMPL_FUNC_1(IScheduleMeetingItem, IsMuteUponEntryEnabled, bool, bool&, can_change, false);
IMPL_FUNC_1(IScheduleMeetingItem, IsScheduleWithPmiEnabled, bool, bool&, can_change, false);
IMPL_FUNC_1(IScheduleMeetingItem, IsOnlySignedInUserCanJoinEnabled, bool, bool&, can_change, false);
IMPL_FUNC_1(IScheduleMeetingItem, GetSpecifiedDomainCanJoin, const wchar_t*, bool&, can_change, NULL);
IMPL_FUNC_1(IScheduleMeetingItem, IsHostInChinaEnabled, bool, bool&, can_change, false);
IMPL_FUNC_2(IScheduleMeetingItem, IsAutoRecordEnabled, bool, bool&, can_change, int&, support_rec_type, false);
IMPL_FUNC_1(IScheduleMeetingItem, IsWaitingRoomEnabled, bool, bool&, can_change, false)
IMPL_FUNC_1(IScheduleMeetingItem, IsMeetingToPublicEnabled, bool, bool&, can_change, false)
IMPL_FUNC_0(IScheduleMeetingItem, GetPublicEventListUrl, const wchar_t*, NULL)
IMPL_FUNC_1(IScheduleMeetingItem, IsLanguageInterpretationEnabled, bool, bool&, can_change, false)
IMPL_FUNC_0(IScheduleMeetingItem, GetInterpreterInfoList, IList<IInterpreterInfo* >*, NULL)
IMPL_FUNC_0(IScheduleMeetingItem, GetAlternativeHostInfoList, IList<IAlternativeHostInfo* >*, NULL)
IMPL_FUNC_0(IScheduleMeetingItem, GetSelectedAutoRecordType, SCHEDULERECTYPE, SCHEDULERECTYPE::SCHEDULERecordType_none);
IMPL_FUNC_0(IScheduleMeetingItem, GetQueryScheduleForHelper, IQueryMeetingItemScheduleForHelper*, NULL);
IMPL_FUNC_0(IScheduleMeetingItem, GetUniqueMeetingID, UINT64, 0);
IMPL_FUNC_0(IScheduleMeetingItem, GetMeetingID, UINT64, 0);
IMPL_FUNC_0(IScheduleMeetingItem, IsPMI, bool, false);
IMPL_FUNC_0(IScheduleMeetingItem, IsWebinar, bool, false);
IMPL_FUNC_0(IScheduleMeetingItem, GetInviteEmailContent, const wchar_t*, NULL);
IMPL_FUNC_0(IScheduleMeetingItem, GetInviteEmailSubject, const wchar_t*, NULL);
IMPL_FUNC_0(IScheduleMeetingItem, GetJoinMeetingUrl, const wchar_t*, NULL);

END_ZOOM_SDK_NAMESPACE