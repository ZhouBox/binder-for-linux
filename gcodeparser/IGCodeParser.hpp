#ifndef IGCODEPARSER_H
#define IGCODEPARSER_H


#include "IGCodeModuleInterface.h"

#include <binder/IInterface.h>
#include <binder/Parcel.h>

using namespace android;

namespace ICNC
{

class IGCodeParser : public IInterface, public IGCodeModuleInterface
{
  public:
    DECLARE_META_INTERFACE(GCodeParser);
};

class BnGCodeParser : public BnInterface<IGCodeParser>
{
  public:
    virtual status_t onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flag = 0);
};

} // namespace ICNC

#endif // IGCODEPARSER_H