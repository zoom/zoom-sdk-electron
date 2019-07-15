#pragma once
#include "calender_service_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ICalenderService* InitICalenderServiceFunc(ZOOM_SDK_NAMESPACE::ICalenderServiceEvent* pEvent)
{
	ZOOM_SDK_NAMESPACE::ICalenderService* pObj(NULL);
	CSDKImpl::GetInst().CreateCalenderService(&pObj);
	if (pObj)
	{
		pObj->Init(pEvent);
	}
	return pObj;
}

void UninitICalenderServiceFunc(ZOOM_SDK_NAMESPACE::ICalenderService* obj)
{
	if (obj)
	{
		obj->Uninit();
		CSDKImpl::GetInst().DestroyCalenderService(obj);
	}
}

//virtual SDKError StartOutlookExchangeCalender(OutlookExchageAuth& param) = 0;
IMPL_FUNC_1(ICalenderService, StartOutlookExchangeCalender, SDKError, OutlookExchageAuth&, param, SDKERR_UNINITIALIZE)
//virtual SDKError StopOutlookExchangeCalender() = 0;
IMPL_FUNC_0(ICalenderService, StopOutlookExchangeCalender, SDKError, SDKERR_UNINITIALIZE)
//virtual SDKError RetrieveCalEvents(CalenderAuthType type) = 0;
IMPL_FUNC_1(ICalenderService, RetrieveCalEvents, SDKError, CalenderAuthType, type, SDKERR_UNINITIALIZE)

END_ZOOM_SDK_NAMESPACE