#include "IGCodeParserService.hpp"
#include "IGCodeParser.hpp"
#include "GCodeParserClient.hpp"


#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <utils/String8.h>
#include <utils/Looper.h>

#include <iostream>

#include <unistd.h>

using namespace ICNC;


int main(int agrc, char* argv[])
{


    class TestListener : public GCodeListenerImpl
    {
        public:
        void notify(const String16& code)
        {
            std::cout << String8(code).string() << std::endl;
        }

    };

    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("gcodeparser"));
    if (binder.get() == NULL) {
        return -1;
    }
    sp<IGCodeParserService> gcodes = interface_cast<IGCodeParserService>(binder);
    if (gcodes.get() == NULL) {
        return -2;
    }
    sp<GCodeParserClient> gcodec = new GCodeParserClient();

    sp<TestListener> tl = new TestListener();

    gcodec->add_gcode_listener(tl);

    sp<IGCodeParser> gcodep =  gcodes->create_client(getpid(), gcodec);
    std::cout << gcodep->current_line() << std::endl;

    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();


     

    return 0;
}