#ifndef IGCODEMODULEINTERFACE_H
#define IGCODEMODULEINTERFACE_H


#include <binder/IInterface.h>
#include <utils/String16.h>


using namespace android;


namespace ICNC 
{

class IGCodeModuleInterface
{
    public:
    virtual uint32_t current_line() const = 0;

    virtual void notify(const String16& code)
    {

    }


};

}




#endif // IGCODEMODULEINTERFACE_H