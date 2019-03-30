#ifndef IGCODEPARSERSERVICE_H
#define IGCODEPARSERSERVICE_H

#include "IGCodeModuleInterface.h"

#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

namespace ICNC
{

class IGCodeParser;
class IGCodeParserClient;

class IGCodeParserService : public IInterface
{
  public:
    DECLARE_META_INTERFACE(GCodeParserService);
    virtual sp<IGCodeParser> create_client(pid_t pid, const sp<IGCodeParserClient> &client) = 0;
};

class BnGCodeParserService : public BnInterface<IGCodeParserService>, public IGCodeModuleInterface
{
  public:
    virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flag = 0);
};

} // namespace ICNC

#endif // IGCODEPARSERSERVICE_H