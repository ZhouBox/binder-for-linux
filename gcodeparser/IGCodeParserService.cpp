#include "IGCodeParserService.hpp"
#include "IGCodeParserClient.hpp"
#include "IGCodeParser.hpp"

namespace ICNC
{

enum
{
    ICNC_GCODEPARSER_CREATECLIENT = IBinder::FIRST_CALL_TRANSACTION,
};

class BpGCodeParserService : public BpInterface<IGCodeParserService>
{
  public:
    explicit BpGCodeParserService(const sp<IBinder> &impl)
        : BpInterface<IGCodeParserService>(impl)
    {
    }

    virtual sp<IGCodeParser> create_client(pid_t pid, const sp<IGCodeParserClient> &client)
    {
        Parcel data, reply;
        data.writeInterfaceToken(IGCodeParserService::getInterfaceDescriptor());
        data.writeInt32(pid);
        data.writeStrongBinder(IInterface::asBinder(client));
        remote()->transact(ICNC_GCODEPARSER_CREATECLIENT, data, &reply);
        return interface_cast<IGCodeParser>(reply.readStrongBinder());
    }
};

IMPLEMENT_META_INTERFACE(GCodeParserService, "android.icnc.IGCodeParserService");

status_t BnGCodeParserService::onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flag)
{
    switch (code)
    {
    case ICNC_GCODEPARSER_CREATECLIENT:
    {
        CHECK_INTERFACE(IGCodeParserService, data, reply);
        pid_t pid = data.readInt32();
        sp<IGCodeParserClient> client = interface_cast<IGCodeParserClient>(data.readStrongBinder());
        sp<IGCodeParser> parser = create_client(pid, client);
        reply->writeStrongBinder(IInterface::asBinder(parser));
        return NO_ERROR;
    }
    break;
    default:
        return BnInterface::onTransact(code, data, reply, flag);
        break;
    }
}

} // namespace ICNC