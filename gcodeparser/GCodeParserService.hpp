#ifndef GCODEPARSERSERVICE_H
#define GCODEPARSERSERVICE_H

#include "IGCodeParserService.hpp"
#include "IGCodeParser.hpp"

#include <list>
#include <thread>

using namespace android;

namespace ICNC
{


class GCodeParser : public BnGCodeParser
{
    public:
    GCodeParser(pid_t pid, const sp<IGCodeParserClient> client);
    virtual uint32_t current_line() const;
    void notify(const String16& code);

    private:
    pid_t m_client_pid;
    sp<IGCodeParserClient> m_client;

};


class GCodeParserService : public BnGCodeParserService
{
  public:

    static sp<GCodeParserService> self();
    virtual sp<IGCodeParser> create_client(pid_t pid, const sp<IGCodeParserClient> &client);
    virtual uint32_t current_line() const;

    void start_parse();

    void notify(const String16& code);


  private:
    GCodeParserService()
    {

    }

    ~GCodeParserService()
    {

    }

  private:
    std::list<sp<IGCodeParser>> m_parsers;
    std::shared_ptr<std::thread> m_parser_thread;
};

} // namespace ICNC

#endif // GCODEPARSERSERVICE_H