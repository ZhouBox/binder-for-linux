#include "GCodeParserService.hpp"
#include "IGCodeParserClient.hpp"

namespace ICNC
{

sp<GCodeParserService> _g = NULL;



GCodeParser::GCodeParser(pid_t pid, const sp<IGCodeParserClient> client)
: m_client_pid(pid)
, m_client(client)
{

}


uint32_t GCodeParser::current_line() const
{
    const sp<GCodeParserService> _servie = GCodeParserService::self();
    return _servie->current_line();
}

sp<GCodeParserService> GCodeParserService::self()
{
    if (_g == NULL) {
        _g = new GCodeParserService();
    }
    return _g;
}


sp<IGCodeParser> GCodeParserService::create_client(pid_t pid, const sp<IGCodeParserClient> &client)
{
    sp<IGCodeParser> _parser = new GCodeParser(pid, client);
    m_parsers.push_back(_parser);
    return _parser;
}

uint32_t GCodeParserService::current_line() const
{
    return rand();
}

} // namespace ICNC