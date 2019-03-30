#include "IGCodeParser.hpp"

namespace ICNC
{

enum
{
    ICNC_GCODEPARSER_CURRENTLINE = IBinder::FIRST_CALL_TRANSACTION,
};

class BpGCodeParser : public BpInterface<IGCodeParser>
{
  public:
    BpGCodeParser(const sp<IBinder> &impl)
        : BpInterface<IGCodeParser>(impl)
    {
    }

    virtual uint32_t current_line() const
    {
        Parcel data, reply;
        data.writeInterfaceToken(IGCodeParser::getInterfaceDescriptor());
        remote()->transact(ICNC_GCODEPARSER_CURRENTLINE, data, &reply);
        return reply.readUint32();
    }
};

IMPLEMENT_META_INTERFACE(GCodeParser, "android.icnc.GCodeParser");

status_t BnGCodeParser::onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flag)
{
    switch (code)
    {
    case ICNC_GCODEPARSER_CURRENTLINE /* constant-expression */:
        /* code */
        {
            CHECK_INTERFACE(IGCodeParser, data, reply);
            reply->writeUint32(this->current_line());
            return NO_ERROR;
        }
        break;

    default:
        return BnInterface::onTransact(code, data, reply, flag);
        break;
    }
}

} // namespace ICNC