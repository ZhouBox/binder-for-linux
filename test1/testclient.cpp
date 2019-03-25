#include <binder/IServiceManager.h>
#include <utils/Log.h>
#include <utils/String8.h>
#include "Itestservice.hpp"

#include <iostream>
#include <string>

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
    String16 _str = ts->testfun(String16("binder"));
    ALOGI(_str);
    ALOGD(_str);
    std::cout << String8(_str).string() << std::endl;


    std::string _in;
    while(std::cin >> _in){
        if (_in == "q") {
            break;
        }
        String16 _str = ts->testfun(String16(_in.c_str()));
        std::cout << String8(_str).string() << std::endl;
        _in = "";
        std::cout << "input `q` exit!" << std::endl;
    }
    
    return 0;
}