#include "IGCodeParserClient.hpp"

#include <binder/IBinder.h>

namespace ICNC
{
    enum {
        ICNC_GCODEPARSERCLIENT_NOTIFY = IBinder::FIRST_CALL_TRANSACTION,
    };

    class BpGCodeParserClient : public BpInterface<IGCodeParserClient>
    {
        public:
        BpGCodeParserClient(const sp<IBinder>& impl)
        : BpInterface<IGCodeParserClient>(impl)
        {

        }

        virtual void notify(const String16& code)
        {
            Parcel data, reply;
            data.writeInterfaceToken(IGCodeParserClient::getInterfaceDescriptor());
            data.writeString16(code);
            remote()->transact(ICNC_GCODEPARSERCLIENT_NOTIFY, data, &reply);
        }

    };

    IMPLEMENT_META_INTERFACE(GCodeParserClient, "android.icnc.GCodeParserClient");

    status_t BnGCodeParserClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flag)
    {
        switch (code)
        {
            case ICNC_GCODEPARSERCLIENT_NOTIFY /* constant-expression */:
                /* code */
                {
                    CHECK_INTERFACE(IGCodeParserClient, data, reply);
                    String16 gcode = data.readString16();
                    this->notify(gcode);
                    return NO_ERROR;
                }
                break;
        
            default:
                return BnInterface::onTransact(code, data, reply, flag);
                break;
        }
    }

}