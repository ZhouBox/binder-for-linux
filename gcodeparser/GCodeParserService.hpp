#ifndef GCODEPARSERSERVICE_H
#define GCODEPARSERSERVICE_H

#include "IGCodeParserService.hpp"
#include "IGCodeParser.hpp"

#include <list>

using namespace android;

namespace ICNC
{


class GCodeParser : public BnGCodeParser
{
    public:
    GCodeParser(pid_t pid, const sp<IGCodeParserClient> client);
    virtual uint32_t current_line() const;

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


  private:
    GCodeParserService()
    {

    }

    ~GCodeParserService()
    {
        
    }

  private:
    std::list<sp<IGCodeParser>> m_parsers;
};

} // namespace ICNC

#endif // GCODEPARSERSERVICE_H