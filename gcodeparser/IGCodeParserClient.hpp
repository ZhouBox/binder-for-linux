#ifndef IGCODEPARSERCLIENT_H
#define IGCODEPARSERCLIENT_H

#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

namespace ICNC
{

class IGCodeParserClient : public IInterface
{
  public:
    DECLARE_META_INTERFACE(GCodeParserClient);
    virtual void notify(const String16 &code) = 0;
};

class BnGCodeParserClient : public BnInterface<IGCodeParserClient>
{
    public:
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flag = 0);

};

} // namespace ICNC

#endif // IGCODEPARSERCLIENT_H