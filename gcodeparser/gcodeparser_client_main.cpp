#include "IGCodeParserService.hpp"
#include "IGCodeParser.hpp"
#include "GCodeParserClient.hpp"


#include <binder/IServiceManager.h>
#include <iostream>


#include <unistd.h>

using namespace ICNC;


int main(int agrc, char* argv[])
{
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("gcodeservice"));
    if (binder.get() == NULL) {
        return -1;
    }
    sp<IGCodeParserService> gcodes = interface_cast<IGCodeParserService>(binder);
    if (gcodes.get() == NULL) {
        return -2;
    }
    sp<IGCodeParserClient> gcodec = new GCodeParserClient();

    sp<IGCodeParser> gcodep =  gcodes->create_client(getpid(), gcodec);
    std::cout << gcodep->current_line() << std::endl;

    return 0;
}