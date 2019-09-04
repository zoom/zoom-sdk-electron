#include "run_task_to_main_thread.h"
#if (defined _WIN32)
#include <Windows.h>
UINT WM_THREAD_RUN_TASK = ::RegisterWindowMessageA("zoom_node_main_thread_task_id_sx1");
HHOOK g_hook = NULL;
int g_main_threadid = 0;
LRESULT CALLBACK MainThread_RunLoop(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);
void Init_MainThread_RunLoop(int threadid)
{
	if (NULL == g_hook)
	{
		g_main_threadid = threadid;
		g_hook = SetWindowsHookExW(WH_GETMESSAGE, MainThread_RunLoop, NULL, threadid);
	}
}

void Uninit_MainThread_RunLoop()
{
	if (g_hook)
	{
		g_main_threadid = 0;
		UnhookWindowsHookEx(g_hook);
		g_hook = NULL;
	}
}

LRESULT CALLBACK MainThread_RunLoop(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	do
	{
		if (HC_ACTION != code || PM_REMOVE != wParam)
			break;

		if (0 == lParam)
			break;
		LPMSG pMsg = (LPMSG)lParam;
		if (WM_THREAD_RUN_TASK == pMsg->message)
		{
			if (pMsg->wParam)
			{
				IMainThreadTask* task_ = (IMainThreadTask*)pMsg->wParam;
				if (task_)
					task_->Run();
			}
			return 0;
		}
	} while (false);

	return CallNextHookEx(NULL, code, wParam, lParam);
}


bool PostTaskToMainThread(IMainThreadTask* task_)
{
	if (0 == g_main_threadid || NULL == task_)
		return false;
	/*
	if (g_main_threadid == GetCurrentThreadId())
	{
		task_->Run();
		return true;
	}*/
	return ::PostThreadMessage(g_main_threadid, WM_THREAD_RUN_TASK, (WPARAM)task_, (LPARAM)0) ? true : false;
}
#else
void Init_MainThread_RunLoop(int threadid) {
    
}
bool PostTaskToMainThread(IMainThreadTask* task_){
	mainThread_wrap::PostTaskToMainThreadwarp(task_);
    return true;
}
void Uninit_MainThread_RunLoop() {}
#endif
