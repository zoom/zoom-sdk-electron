
#include "../meeting_h323_wrap_core.h"
#include "wrap/sdk_wrap.h"
#include "wrap/meeting_service_components_wrap/meeting_h323_helper_wrap.h"
#include "zoom_native_to_wrap.h"
#include "sdk_events_wrap_class.h"
extern ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& g_meeting_service_wrap;

ZMeetingH323Wrap::ZMeetingH323Wrap()
{
	SDKEventWrapMgr::GetInst().m_meetingH323CtrlWrapEvent.SetOwner(this);
	m_pSink = 0;
}
ZMeetingH323Wrap::~ZMeetingH323Wrap()
{
	Uninit();
	m_pSink = 0;
	SDKEventWrapMgr::GetInst().m_meetingH323CtrlWrapEvent.SetOwner(NULL);
}
void ZMeetingH323Wrap::Init()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetH323Helper().Init_Wrap(&g_meeting_service_wrap);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetH323Helper().SetEvent(&SDKEventWrapMgr::GetInst().m_meetingH323CtrlWrapEvent);
}
void ZMeetingH323Wrap::Uninit()
{
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetH323Helper().SetEvent(NULL);
	ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetH323Helper().Uninit_Wrap();
}
void ZMeetingH323Wrap::SetSink(ZNativeSDKMeetingH323WrapSink* pSink)
{
	m_pSink = pSink;
}
ZNSDKError ZMeetingH323Wrap::CallOutH323(ZoomSTRING deviceName, ZoomSTRING deviceIP, ZoomSTRING device164Num, ZNH323DeviceType deviceType)
{
	ZOOM_SDK_NAMESPACE::CustomizedH323Device* pH323Device = new ZOOM_SDK_NAMESPACE::CustomizedH323Device;
	if (pH323Device)
	{
		pH323Device->SetName(deviceName.c_str());
		pH323Device->SetIP(deviceIP.c_str());
		pH323Device->SetE164Num(device164Num.c_str());
		pH323Device->SetDeviceType(Map2SDKDefine(deviceType));
	}
	else
	{
		return ZNSDKERR_SERVICE_FAILED;
	}
	ZOOM_SDK_NAMESPACE::SDKError sdkerr = ZOOM_SDK_NAMESPACE::SDKERR_SUCCESS;
	ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& meetingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
	sdkerr = meetingWrap.T_GetH323Helper().CallOutH323(dynamic_cast<ZOOM_SDK_NAMESPACE::IH323Device*>(pH323Device));
	return Map2WrapDefine(sdkerr);
}
ZNSDKError ZMeetingH323Wrap::CancelCallOutH323()
{
	return Map2WrapDefine(ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetH323Helper().CancelCallOutH323());

}
ZNList<ZoomSTRING> ZMeetingH323Wrap::GetH323Address()
{
	ZNList<ZoomSTRING> zn_h323AddressList;
	ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& meetingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
	ZOOM_SDK_NAMESPACE::IList<const wchar_t*>*  pH323AddressList(NULL);
	pH323AddressList = meetingWrap.T_GetH323Helper().GetH323Address();
	if (pH323AddressList && pH323AddressList->GetCount() > 0)
	{
		int count = pH323AddressList->GetCount();
		for (int i = 0; i < count; i++)
		{
			ZoomSTRING address = pH323AddressList->GetItem(i);
			zn_h323AddressList.push_back(address);
		}
	}
	return zn_h323AddressList;
}
ZoomSTRING ZMeetingH323Wrap::GetH323Password()
{
	ZoomSTRING password;
	password = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap().T_GetH323Helper().GetH323Password();
	return password;
}
ZNList<ZNH323DeviecInfo> ZMeetingH323Wrap::GetCalloutH323DviceList()
{
	ZNList<ZNH323DeviecInfo> zn_h323DeviceInfoLst;
	ZOOM_SDK_NAMESPACE::IMeetingServiceWrap& meetingWrap = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetMeetingServiceWrap();
	ZOOM_SDK_NAMESPACE::IList<ZOOM_SDK_NAMESPACE::IH323Device*>*  pH323DeviceList(NULL);
	pH323DeviceList = meetingWrap.T_GetH323Helper().GetCalloutH323DviceList();
	if (pH323DeviceList && pH323DeviceList->GetCount() > 0)
	{
		int count = pH323DeviceList->GetCount();
		for (int i = 0; i < count; i++)
		{
			ZNH323DeviecInfo zn_deviceInfo;
			ZOOM_SDK_NAMESPACE::IH323Device* pH323Device = pH323DeviceList->GetItem(i);
			if (NULL == pH323Device)
				continue;
			const wchar_t* wstrName = pH323Device->GetName();
			if (wstrName)
			{
				zn_deviceInfo.h323_deviceName = wstrName;
			}
			const wchar_t* wstrIP = pH323Device->GetIP();
			if (wstrIP)
			{
				zn_deviceInfo.h323_deviceIP = wstrIP;
			}
			const wchar_t* wstrE164Num = pH323Device->GetE164Num();
			if (wstrE164Num)
			{
				zn_deviceInfo.h323_deviceE164Name = wstrE164Num;
			}
			zn_deviceInfo.h323_DeviceType = Map2WrapDefine(pH323Device->GetDeviceType());

			zn_h323DeviceInfoLst.push_back(zn_deviceInfo);
		}
	}
	return zn_h323DeviceInfoLst;
}



void ZMeetingH323Wrap::onH323CalloutStatusNotify(ZNH323CalloutStatus status)
{
	if (m_pSink)
	{
		m_pSink->onH323CalloutStatusNotify(status);
	}
	
}