#include "GCodeParserClient.hpp"


namespace ICNC
{

    bool GCodeParserClient::add_gcode_listener(const sp<GCodeListenerImpl> listener)
    {
        for (sp<GCodeListenerImpl> a : m_listeneres)
        {
            if (a == listener) {
                return false;
            }
        }
        m_listeneres.push_back(listener);
        return true;
    }

    void GCodeParserClient::notify(const String16& code)
    {
        for (sp<GCodeListenerImpl> a : m_listeneres)
        {
            a->notify(code);
        }
    }
}