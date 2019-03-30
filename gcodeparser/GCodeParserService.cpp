#include "GCodeParserService.hpp"
#include "IGCodeParserClient.hpp"

namespace ICNC
{

sp<GCodeParserService> _g = NULL;

GCodeParser::GCodeParser(pid_t pid, const sp<IGCodeParserClient> client)
    : m_client_pid(pid), m_client(client)
{
}

uint32_t GCodeParser::current_line() const
{
    const sp<GCodeParserService> _servie = GCodeParserService::self();
    return _servie->current_line();
}

void GCodeParser::notify(const String16 &code)
{
    if (m_client != NULL)
    {
        m_client->notify(code);
    }
}

sp<GCodeParserService> GCodeParserService::self()
{
    if (_g == NULL)
    {
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

void GCodeParserService::notify(const String16 &code)
{
    for (sp<IGCodeParser> a : m_parsers) {
        a->notify(code);
    }
}

void GCodeParserService::start_parser()
{
    m_parser_thread.reset(new std::thread([]() {
        while (1)
        {
            std::this_thread::sleep_for(std::chrono::seconds(10));
            GCodeParserService::self()->notify(String16("G00 G01 G02"));
        }
    }));
}

} // namespace ICNC