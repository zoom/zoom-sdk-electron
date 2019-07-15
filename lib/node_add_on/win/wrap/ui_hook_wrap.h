#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
ZOOM_SDK_NAMESPACE::IUIHooker* InitIUIHookerFunc(ZOOM_SDK_NAMESPACE::IUIHookerEvent* pEvent);
void UninitIUIHookerFunc(ZOOM_SDK_NAMESPACE::IUIHooker* obj);

BEGIN_CLASS_DEFINE_WITHCALLBACK(IUIHooker, IUIHookerEvent)
STAITC_CLASS(IUIHooker)
INIT_UNINIT_WITHEVENT(IUIHooker)
virtual SDKError SetEvent(IUIHookerEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}
//virtual SDKError MonitorWndMessage(unsigned int wndmsgid, bool bAdd = true) = 0;
DEFINE_FUNC_2(MonitorWndMessage, SDKError, unsigned int, wndmsgid, bool, bAdd)
//virtual SDKError MonitorWnd(const wchar_t* classname, bool bAdd = true) = 0;
DEFINE_FUNC_2(MonitorWnd, SDKError, const wchar_t*, classname, bool, bAdd)
//virtual SDKError Start() = 0;
DEFINE_FUNC_0(Start, SDKError)
//virtual SDKError Stop() = 0;
DEFINE_FUNC_0(Stop, SDKError)

//virtual void onUIActionNotify(UIHOOKHWNDTYPE type, MSG msg) = 0;
CallBack_FUNC_2(onUIActionNotify, UIHOOKHWNDTYPE, type, MSG, msg)
END_CLASS_DEFINE(IUIHooker)
END_ZOOM_SDK_NAMESPACE