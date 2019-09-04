
#include "../run_task_to_main_thread.h"
#import <Foundation/Foundation.h>
bool  mainThread_wrap::PostTaskToMainThreadwarp(IMainThreadTask *task_){

    dispatch_async(dispatch_get_main_queue(), ^{
        task_->Run();
    });
    
    return YES;
}
