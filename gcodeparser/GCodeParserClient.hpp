#ifndef GCODEPARSERCLINET_H
#define GCODEPARSERCLINET_H

#include "IGCodeParserClient.hpp"


#include <list>

namespace ICNC
{


class GCodeListenerImpl : public RefBase
{
    public:
    virtual void notify(const String16& code) = 0;

};



class GCodeParserClient : public BnGCodeParserClient
{
    public:
    virtual void notify(const String16& code);
    bool add_gcode_listener(const sp<GCodeListenerImpl> listener);

    private:
    std::list<sp<GCodeListenerImpl>> m_listeneres;


};

    
} // ICNC







#endif // GCODEPARSERCLINET_H