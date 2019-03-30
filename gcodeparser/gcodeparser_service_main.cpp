#include "GCodeParserService.hpp"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

int main(int argc, char* argv[])
{

    sp<IServiceManager> _sm = defaultServiceManager();
    _sm->addService(String16("gcodeparser"), ICNC::GCodeParserService::self());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}