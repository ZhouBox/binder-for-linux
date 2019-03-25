#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include "Itestservice.hpp"

int main(int argc, char* argv[])
{

    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("testservice"));
    if (binder.get() == NULL) {
        return -1;
    }
    sp<Itestservice> ts = interface_cast<Itestservice>(binder);
    if (ts.get() == 0) {
        return -2;
    }
    auto _str = ts->testfun(String16("binder"));
    ALOGI(_str);
    ALOGD(_str);
    return 0;
}