#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE

BEGIN_CLASS_DEFINE_WITHCALLBACK(IScheduleMeetingItem, IScheduleMeetingItemStatusCallback)
NORMAL_CLASS(IScheduleMeetingItem)
~IScheduleMeetingItemWrap();
void Init(IScheduleMeetingItem* pObj);
void UnInit();

//virtual SDKError SelectStartTime(time_t time) = 0;
DEFINE_FUNC_1(SelectStartTime, SDKError, time_t, time)
//virtual SDKError SetDurationInMinutes(int duration) = 0;
DEFINE_FUNC_1(SetDurationInMinutes, SDKError, int, duration)
//virtual SDKError SelectRecurringMeeting(bool select_) = 0;
DEFINE_FUNC_1(SelectRecurringMeeting, SDKError, bool, select)
//virtual SDKError SelectHostVideoOnOrOff(bool bOn) = 0;
DEFINE_FUNC_1(SelectHostVideoOnOrOff, SDKError, bool, bOn)
//virtual SDKError SelectAttendeeVideoOnOrOff(bool bOn) = 0;
DEFINE_FUNC_1(SelectAttendeeVideoOnOrOff, SDKError, bool, bOn)
//virtual SDKError IsSupportAudioType(SCHEDULEAUDIOTYPE audio_type) = 0;
DEFINE_FUNC_1(IsSupportAudioType, SDKError, SCHEDULEAUDIOTYPE, audio_type)
//virtual SDKError SelectAudioType(SCHEDULEAUDIOTYPE audio_type) = 0;
DEFINE_FUNC_1(SelectAudioType, SDKError, SCHEDULEAUDIOTYPE, audio_type)
//virtual ISelectMeetingItemTelAudioHelper* GetScheduleTelAudioHelper() = 0;
DEFINE_FUNC_0(GetScheduleTelAudioHelper, ISelectMeetingItemTelAudioHelper*)
//virtual SDKError SetMeetingTopic(const wchar_t* topic) = 0;
DEFINE_FUNC_1(SetMeetingTopic, SDKError, const wchar_t*, topic)
//virtual SDKError EnableMeetingPassword(bool bEnable) = 0;
DEFINE_FUNC_1(EnableMeetingPassword, SDKError, bool, bEnable)
//virtual SDKError SetMeetingPassword(const wchar_t* meetingPsw) = 0;
DEFINE_FUNC_1(SetMeetingPassword, SDKError, const wchar_t*, meetingPsw)
//virtual SDKError EnableJoinBeforeHost(bool bEnable) = 0;
DEFINE_FUNC_1(EnableJoinBeforeHost, SDKError, bool, bEnable)
//virtual SDKError EnableMuteUponEntry(bool bEnable) = 0;
DEFINE_FUNC_1(EnableMuteUponEntry, SDKError, bool, bEnable)
//virtual SDKError EnableScheduleWithPmi(bool bEnable) = 0;
DEFINE_FUNC_1(EnableScheduleWithPmi, SDKError, bool, bEnable)
//virtual SDKError EnableOnlySignedInUserCanJoin(bool bEnable) = 0;
DEFINE_FUNC_1(EnableOnlySignedInUserCanJoin, SDKError, bool, bEnable)
//virtual SDKError SetSpecifiedDomainCanJoin(const wchar_t* specified_domain_can_join) = 0;
DEFINE_FUNC_1(SetSpecifiedDomainCanJoin, SDKError, const wchar_t*, specified_domain_can_join)
//virtual SDKError EnableHostInChina(bool bEnable) = 0;
DEFINE_FUNC_1(EnableHostInChina, SDKError, bool, bEnable)
//virtual SDKError EnableAutoRecord(bool bEnable) = 0;
DEFINE_FUNC_1(EnableAutoRecord, SDKError, bool, bEnable)
//virtual SDKError SelectAutoRecordType(SCHEDULERECTYPE type_) = 0;
DEFINE_FUNC_1(SelectAutoRecordType, SDKError, SCHEDULERECTYPE, type_)
//virtual SDKError EnableWaitingRoom(bool bEnable) = 0;
DEFINE_FUNC_1(EnableWaitingRoom, SDKError, bool, bEnable)
//virtual SDKError EnableMeetingToPublic(bool bEnable) = 0;
DEFINE_FUNC_1(EnableMeetingToPublic, SDKError, bool, bEnable)
//virtual SDKError EnableLanguageInterpretation(bool bEnable) = 0;
DEFINE_FUNC_1(EnableLanguageInterpretation, SDKError, bool, bEnable)
//virtual SDKError SetInterpreterInfoList(IList<IInterpreterInfo* >* lst_interpreters) = 0;
DEFINE_FUNC_1(SetInterpreterInfoList, SDKError, IList<IInterpreterInfo* >*, lst_interpreters)
//virtual SDKError SetAlternativeHostList(IList<IAlternativeHostInfo* >* lst_althosts) = 0;
DEFINE_FUNC_1(SetAlternativeHostList, SDKError, IList<IAlternativeHostInfo* >*, lst_althosts)

//virtual ISelectMeetingItemScheduleForHelper* GetScheduleForHelper() = 0;
DEFINE_FUNC_0(GetScheduleForHelper, ISelectMeetingItemScheduleForHelper*)
//virtual time_t GetCurrentStartTime() = 0;
DEFINE_FUNC_0(GetCurrentStartTime, time_t)
//virtual int GetDurationInMinutes() = 0;
DEFINE_FUNC_0(GetDurationInMinutes, int)
//virtual bool IsRecurringMeetingSelected() = 0;
DEFINE_FUNC_0(IsRecurringMeetingSelected, bool)
//virtual bool IsHostVideoOnOrOff() = 0;
DEFINE_FUNC_0(IsHostVideoOnOrOff, bool)
//virtual bool IsAttendeeVideoOnOrOff() = 0;
DEFINE_FUNC_0(IsAttendeeVideoOnOrOff, bool)
//virtual SDKError GetSelectedAudioType(SCHEDULEAUDIOTYPE& type_) = 0;
DEFINE_FUNC_1(GetSelectedAudioType, SDKError, SCHEDULEAUDIOTYPE&, type)
//virtual IQueryMeetingItemTelAudioInfoHelper* GetQueryTelAudioInfoHelper() = 0;
DEFINE_FUNC_0(GetQueryTelAudioInfoHelper, IQueryMeetingItemTelAudioInfoHelper*)
//virtual const wchar_t* GetMeetingTopic() = 0;
DEFINE_FUNC_0(GetMeetingTopic, const wchar_t*)
//virtual bool IsMeetingPasswordEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsMeetingPasswordEnabled, bool, bool&, can_change)
//virtual const wchar_t* GetMeetingPassword() = 0;
DEFINE_FUNC_0(GetMeetingPassword, const wchar_t*)
//virtual bool IsJoinBeforeHostEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsJoinBeforeHostEnabled, bool, bool&, can_change)
//virtual bool IsMuteUponEntryEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsMuteUponEntryEnabled, bool, bool&, can_change)
//virtual bool IsScheduleWithPmiEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsScheduleWithPmiEnabled, bool, bool&, can_change)
//virtual bool IsOnlySignedInUserCanJoinEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsOnlySignedInUserCanJoinEnabled, bool, bool&, can_change)
//virtual const wchar_t* GetSpecifiedDomainCanJoin(bool& can_change) = 0;
DEFINE_FUNC_1(GetSpecifiedDomainCanJoin, const wchar_t*, bool&, can_change)
//virtual bool IsHostInChinaEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsHostInChinaEnabled, bool, bool&, can_change)
//virtual bool IsAutoRecordEnabled(bool& can_change, int& support_rec_type) = 0;
DEFINE_FUNC_2(IsAutoRecordEnabled, bool, bool&, can_change, int&, support_rec_type)
//virtual SCHEDULERECTYPE GetSelectedAutoRecordType() = 0;
DEFINE_FUNC_0(GetSelectedAutoRecordType, SCHEDULERECTYPE)
//virtual bool IsWaitingRoomEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsWaitingRoomEnabled, bool, bool&, can_change)
//virtual bool IsMeetingToPublicEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsMeetingToPublicEnabled, bool, bool&, can_change)
//virtual const wchar_t* GetPublicEventListUrl() = 0;
DEFINE_FUNC_0(GetPublicEventListUrl, const wchar_t*)
//virtual bool IsLanguageInterpretationEnabled(bool& can_change) = 0;
DEFINE_FUNC_1(IsLanguageInterpretationEnabled, bool, bool&, can_change)
//virtual IList<IInterpreterInfo* >* GetInterpreterInfoList() = 0;
DEFINE_FUNC_0(GetInterpreterInfoList, IList<IInterpreterInfo* >*)
//virtual IList<IAlternativeHostInfo* >* GetAlternativeHostInfoList() = 0;
DEFINE_FUNC_0(GetAlternativeHostInfoList, IList<IAlternativeHostInfo* >*)
//virtual IQueryMeetingItemScheduleForHelper* GetQueryScheduleForHelper() = 0;
DEFINE_FUNC_0(GetQueryScheduleForHelper, IQueryMeetingItemScheduleForHelper*)
//virtual UINT64 GetUniqueMeetingID() = 0;
DEFINE_FUNC_0(GetUniqueMeetingID, UINT64)
//virtual UINT64 GetMeetingID() = 0;
DEFINE_FUNC_0(GetMeetingID, UINT64)
//virtual bool IsPMI() = 0;
DEFINE_FUNC_0(IsPMI, bool)
//virtual bool IsWebinar() = 0;
DEFINE_FUNC_0(IsWebinar, bool)
//virtual const wchar_t* GetInviteEmailContent() = 0;
DEFINE_FUNC_0(GetInviteEmailContent, const wchar_t*)
//virtual const wchar_t* GetInviteEmailSubject() = 0;
DEFINE_FUNC_0(GetInviteEmailSubject, const wchar_t*)
//virtual const wchar_t* GetJoinMeetingUrl() = 0;
DEFINE_FUNC_0(GetJoinMeetingUrl, const wchar_t*)

//virtual void onSupportSelectDateStatusNotification(bool can_use, ISelectMeetingItemDateHelper* date_select_helper) = 0;
CallBack_FUNC_2(onSupportSelectDateStatusNotification, bool, can_use, ISelectMeetingItemDateHelper*, date_select_helper)
//virtual void onSupportTelAudioNotification(bool can_use) = 0;
CallBack_FUNC_1(onSupportTelAudioNotification, bool, can_use)
//virtual void onMeetingPasswordEnabledStatusNotification(bool enable, const wchar_t* default_psw) = 0;
CallBack_FUNC_2(onMeetingPasswordEnabledStatusNotification, bool, enable, const wchar_t*, default_psw)
//virtual void onJoinBeforeHostEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onJoinBeforeHostEnabledStatusNotification, bool, enable)
//virtual void onMuteUponEntryEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onMuteUponEntryEnabledStatusNotification, bool, enable)
//virtual void onScheduleWithPmiEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onScheduleWithPmiEnabledStatusNotification, bool, enable)
//virtual void onOnlySignedInUserCanJoinEnabledStatusNotification(bool enable, const wchar_t* default_specified_domain_can_join) = 0;
CallBack_FUNC_2(onOnlySignedInUserCanJoinEnabledStatusNotification, bool, enable, const wchar_t*, default_specified_domain_can_join)
//virtual void onHostInChinaEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onHostInChinaEnabledStatusNotification, bool, enable)
//virtual void onAutoRecordEnabledStatusNotification(bool enable, SCHEDULERECTYPE& default_type) = 0;
CallBack_FUNC_2(onAutoRecordEnabledStatusNotification, bool, enable, SCHEDULERECTYPE&, default_type)
//virtual void onSupportScheduleForNotification(bool can_use) = 0;
CallBack_FUNC_1(onSupportScheduleForNotification, bool, can_use)
// virtual void onScheduleMeetingItemDestroyed() = 0;
CallBack_FUNC_0(onScheduleMeetingItemDestroyed)
//virtual void onWaitingRoomEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onWaitingRoomEnabledStatusNotification, bool, enable);
//virtual void onMeetingToPublicEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onMeetingToPublicEnabledStatusNotification, bool, enable);
//virtual void onLanguageInterpretationEnabledStatusNotification(bool enable) = 0;
CallBack_FUNC_1(onLanguageInterpretationEnabledStatusNotification, bool, enable);
END_CLASS_DEFINE(IScheduleMeetingItem)
END_ZOOM_SDK_NAMESPACE