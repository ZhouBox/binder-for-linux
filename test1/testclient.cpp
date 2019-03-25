#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include "Itestservice.hpp"

#include <iostream>

int main(int argc, char* argv[])
{

    std::cout << "testserviceclient" << std::endl;
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("testservice"));
    if (binder.get() == NULL) {
        std::cout << "testserviceclient -1" << std::endl;
        return -1;
    }
    sp<Itestservice> ts = interface_cast<Itestservice>(binder);
    if (ts.get() == NULL) {
        std::cout << "testserviceclient -2" << std::endl;
        return -2;
    }
    auto _str = ts->testfun(String16("binder"));
    ALOGI(_str);
    ALOGD(_str);
    std::cout << _str << std::endl;
    return 0;
}