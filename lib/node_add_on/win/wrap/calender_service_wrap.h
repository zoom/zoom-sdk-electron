#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::ICalenderService* InitICalenderServiceFunc(ZOOM_SDK_NAMESPACE::ICalenderServiceEvent* pEvent);
void UninitICalenderServiceFunc(ZOOM_SDK_NAMESPACE::ICalenderService* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(ICalenderService, ICalenderServiceEvent)
STAITC_CLASS(ICalenderService)
INIT_UNINIT_WITHEVENT(ICalenderService)

#if (defined UserInterfaceClass)
virtual SDKError Init(ICalenderServiceEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
virtual SDKError Uninit()
{
	external_cb = NULL;
	return SDKERR_SUCCESS;
}
#endif 

//virtual SDKError StartOutlookExchangeCalender(OutlookExchageAuth& param) = 0;
DEFINE_FUNC_1(StartOutlookExchangeCalender, SDKError, OutlookExchageAuth&, param)
//virtual SDKError StopOutlookExchangeCalender() = 0;
DEFINE_FUNC_0(StopOutlookExchangeCalender, SDKError)
//virtual SDKError RetrieveCalEvents(CalenderAuthType type) = 0;
DEFINE_FUNC_1(RetrieveCalEvents, SDKError, CalenderAuthType, type)

//virtual void onCalenderEventsNotifcation(CalenderAuthType type, CalenderResult result, IList<ICalenderEvent* >* plstEvents) = 0;
CallBack_FUNC_3(onCalenderEventsNotifcation, CalenderAuthType, type, CalenderResult, result, IList<ICalenderEvent* >*, plstEvents)
END_CLASS_DEFINE(ICalenderService)
END_ZOOM_SDK_NAMESPACE