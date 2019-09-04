#ifndef _RUN_TASK_TO_MAIN_THREAD_H_
#define _RUN_TASK_TO_MAIN_THREAD_H_
#include <mutex>
#include <thread>
#include <map>
class IMainThreadTask
{
public:
	virtual ~IMainThreadTask() {}
	virtual void Run() = 0;
	virtual void UpdateData(void*, void*) {};
};

#if (defined _WIN32)
#else
class  mainThread_wrap{
public:
    static bool PostTaskToMainThreadwarp(IMainThreadTask* task_);
};
#endif

void Init_MainThread_RunLoop(int threadid);
bool PostTaskToMainThread(IMainThreadTask* task_);
void Uninit_MainThread_RunLoop();
#endif // !_RUN_TASK_TO_MAIN_THREAD_H_

