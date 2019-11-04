
#include "../premeeting_service_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "zoom_native_to_wrap.h"

class ZPreMeetingServiceWrapEvent : public ZOOM_SDK_NAMESPACE::IPreMeetingServiceEvent
{
public:
	void SetOwner(ZPremeetingServiceWrap* obj) { owner_ = obj; }
	virtual void onScheduleOrEditMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, UINT64 meetingUniqueID)
	{
		if (owner_) {
			owner_->onScheduleOrEditMeeting(Map2WrapDefine(result), meetingUniqueID);
		}
	}
	virtual void onListMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result, ZOOM_SDK_NAMESPACE::IList<UINT64 >* lstMeetingList)
	{
		if (owner_)
		{
			ZNList<unsigned long long> zlst_meeting_list;
			if (lstMeetingList && lstMeetingList->GetCount() > 0)
			{
				for (int i = 0; i < lstMeetingList->GetCount(); ++i)
				{
					unsigned long long meetingID = lstMeetingList->GetItem(i);
					zlst_meeting_list.push_back(meetingID);
				}
			}
			ZNPremeetingAPIResult z_premeeting_api_result = Map2WrapDefine(result);
			owner_->onListMeeting(z_premeeting_api_result, zlst_meeting_list);
		}	
	}
	virtual void onDeleteMeeting(ZOOM_SDK_NAMESPACE::PremeetingAPIResult result)
	{
		if (owner_) {
			owner_->onDeleteMeeting(Map2WrapDefine(result));
		}
	}
private:
	ZPremeetingServiceWrap* owner_;
};

static ZPreMeetingServiceWrapEvent g_premeeting_event;


ZPremeetingServiceWrap::ZPremeetingServiceWrap()
{
	g_premeeting_event.SetOwner(this);
	m_pSink = 0;
}
ZPremeetingServiceWrap::~ZPremeetingServiceWrap()
{
	Uninit();
	m_pSink = 0;
	g_premeeting_event.SetOwner(NULL);
}
void ZPremeetingServiceWrap::Init()
{
	
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().SetEvent(&g_premeeting_event);
	
}
void ZPremeetingServiceWrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().Uninit_Wrap();
}
void ZPremeetingServiceWrap::SetSink(ZNativeSDKPreMeetingWrapSink* pSink)
{
	m_pSink = pSink;
}

ZNSDKError ZPremeetingServiceWrap::ScheduleMeeting(ZNWndPosition wndParam)
{
	ZOOM_SDK_NAMESPACE::WndPosition sdk_pos;
	swscanf_s(wndParam.z_hParent.c_str(), L"%x", (unsigned int*)&sdk_pos.hParent);
	
	swscanf_s(wndParam.z_hSelfWnd.c_str(), L"%x", (unsigned int*)&sdk_pos.hSelfWnd);
	
	sdk_pos.left = _wtoi(wndParam.z_left.c_str());
	sdk_pos.top = _wtoi(wndParam.z_top.c_str());
	
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().ScheduleMeeting(sdk_pos));
}
ZNSDKError ZPremeetingServiceWrap::ScheduleMeeting()
{
	ZOOM_SDK_NAMESPACE::IScheduleMeetingItem* pScheduleMeetingItem = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().CreateScheduleMeetingItem();
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().ScheduleMeeting(pScheduleMeetingItem));
}
ZNSDKError ZPremeetingServiceWrap::EditMeeting(unsigned long long meetingUniqueID)
{
	ZOOM_SDK_NAMESPACE::IScheduleMeetingItem* pEditMeetingItem = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().CreateEditMeetingItem(meetingUniqueID);
	if (pEditMeetingItem)
	{
		return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().EditMeeting(pEditMeetingItem));
	}
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::SDKERR_INTELNAL_ERROR);
}
ZNSDKError ZPremeetingServiceWrap::EditMeeting(ZNWndPosition wndParam, unsigned long long meetingUniqueID)
{
	ZOOM_SDK_NAMESPACE::WndPosition sdk_pos;
	swscanf_s(wndParam.z_hParent.c_str(), L"%x", (unsigned int*)&sdk_pos.hParent);
	swscanf_s(wndParam.z_hSelfWnd.c_str(), L"%x", (unsigned int*)&sdk_pos.hSelfWnd);
	sdk_pos.left = _wtoi(wndParam.z_left.c_str());
	sdk_pos.top = _wtoi(wndParam.z_top.c_str());
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().EditMeeting(sdk_pos, meetingUniqueID));
}

ZNSDKError ZPremeetingServiceWrap::ListMeeting()
{

	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().ListMeeting());
}
ZNSDKError ZPremeetingServiceWrap::DeleteMeeting(unsigned long long meetingUniqueID)
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetPreMeetingServiceWrap().DeleteMeeting(meetingUniqueID));
}
void ZPremeetingServiceWrap::onScheduleOrEditMeeting(ZNPremeetingAPIResult result, unsigned long long meetingUniqueID)
{
	if (m_pSink)
		m_pSink->onScheduleOrEditMeeting(result, meetingUniqueID);
}
void ZPremeetingServiceWrap::onListMeeting(ZNPremeetingAPIResult result, ZNList<unsigned long long> lst_meeting_list)
{
	if (m_pSink)
		m_pSink->onListMeeting(result, lst_meeting_list);
}
void ZPremeetingServiceWrap::onDeleteMeeting(ZNPremeetingAPIResult result)
{
	if (m_pSink)
		m_pSink->onDeleteMeeting(result);
}