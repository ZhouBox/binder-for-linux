#ifndef IGCODEMODULEINTERFACE_H
#define IGCODEMODULEINTERFACE_H


#include <binder/IInterface.h>


namespace ICNC 
{

class IGCodeModuleInterface
{
    public:
    virtual uint32_t current_line() const = 0;


};

}




#endif // IGCODEMODULEINTERFACE_H