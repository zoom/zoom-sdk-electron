#pragma once
#include "premeeting_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE

IScheduleForUserImpl::IScheduleForUserImpl()
{
	_pmiNumber = 0;
}

IScheduleForUserImpl::IScheduleForUserImpl(const wchar_t* email, const wchar_t* displayName, UINT64 pmiNumber)
{
	_email = email;
	_displayName = displayName;
	_pmiNumber = pmiNumber;
}

void IScheduleForUserImpl::SetEmail(const wchar_t* email)
{
	_email = email;
}

const wchar_t* IScheduleForUserImpl::GetEmail()
{
	return _email.c_str();
}

void IScheduleForUserImpl::SetDisplayName(const wchar_t* displayName)
{
	_displayName = displayName;
}

const wchar_t* IScheduleForUserImpl::GetDisplayName()
{
	return _displayName.c_str();
}

void IScheduleForUserImpl::SetPMINumber(UINT64 pmiNumber)
{
	_pmiNumber = pmiNumber;
}

UINT64 IScheduleForUserImpl::GetPMINumber()
{
	return _pmiNumber;
}


ZOOM_SDK_NAMESPACE::IPreMeetingService* InitIPreMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IPreMeetingServiceEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::IPreMeetingService* pObj(NULL);
	CSDKImpl::GetInst().CreatePreMeetingService(&pObj);
	if (pObj)
	{
		pObj->SetEvent(pEvent);
	}
	return pObj;
}

void UninitIPreMeetingServiceFunc(ZOOM_SDK_NAMESPACE::IPreMeetingService* obj)
{
	CSDKImpl::GetInst().DestroyPreMeetingService(obj);
}


//virtual IScheduleMeetingItem* CreateScheduleMeetingItem() = 0;
IMPL_FUNC_0(IPreMeetingService, CreateScheduleMeetingItem, IScheduleMeetingItem*, NULL)
//virtual void DestoryScheduleMeetingItem(IScheduleMeetingItem* pMeeting) = 0;
IMPL_FUNC_NORET_1(IPreMeetingService, DestoryScheduleMeetingItem, void, IScheduleMeetingItem*, pMeeting)
//virtual IScheduleMeetingItem* CreateEditMeetingItem(UINT64 meetingUniqueID) = 0;
IMPL_FUNC_1(IPreMeetingService, CreateEditMeetingItem, IScheduleMeetingItem*, UINT64, meetingUniqueId, NULL)
//virtual void DestoryEditMeetingItem(IScheduleMeetingItem* pMeeting) = 0;
IMPL_FUNC_NORET_1(IPreMeetingService, DestoryEditMeetingItem, void, IScheduleMeetingItem*, pMeeting)
//virtual SDKError ScheduleMeeting(IScheduleMeetingItem* pItem) = 0;
IMPL_FUNC_1(IPreMeetingService, ScheduleMeeting, SDKError, IScheduleMeetingItem*, pItem, SDKERR_UNINITIALIZE)
//virtual SDKError ScheduleMeeting(WndPosition& wndParam) = 0;
IMPL_FUNC_1(IPreMeetingService, ScheduleMeeting, SDKError, WndPosition&, wndParam, SDKERR_UNINITIALIZE)
//virtual SDKError EditMeeting(UINT64 meetingUniqueID, IScheduleMeetingItem* pItem) = 0;
IMPL_FUNC_1(IPreMeetingService, EditMeeting, SDKError, IScheduleMeetingItem*, pItem, SDKERR_UNINITIALIZE)
//virtual SDKError EditMeeting(WndPosition& wndParam, UINT64 meetingUniqueID) = 0;
IMPL_FUNC_2(IPreMeetingService, EditMeeting, SDKError, WndPosition&, wndParam, UINT64, meetingUniqueId, SDKERR_UNINITIALIZE)
//virtual SDKError DeleteMeeting(UINT64 meetingUniqueID) = 0;
IMPL_FUNC_1(IPreMeetingService, DeleteMeeting, SDKError, UINT64, meetingUniqueId, SDKERR_UNINITIALIZE)
//virtual SDKError ListMeeting() = 0;
IMPL_FUNC_0(IPreMeetingService, ListMeeting, SDKError, SDKERR_UNINITIALIZE)
//virtual IMyMeetingItem* GetMeeingItem(UINT64 meetingUniqueID) = 0;
IMPL_FUNC_1(IPreMeetingService, GetMeeingItem, IMeetingItemInfo*, UINT64, meetingUniqueId, NULL)

END_ZOOM_SDK_NAMESPACE
