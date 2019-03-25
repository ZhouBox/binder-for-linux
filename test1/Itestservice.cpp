#include "Itestservice.hpp"

#include <utils/Log.h>



enum {
    TEST_FUN = IBinder::FIRST_CALL_TRANSACTION,
};


class Bptestservice : public BpInterface<Itestservice> {
public:
    Bptestservice(const sp<IBinder>& impl)
    : BpInterface<Itestservice>(impl)
    {

    }

    String16 testfun(const String16& name) {
        Parcel data;
        Parcel reply;
        data.writeInterfaceToken(Itestservice::getInterfaceDescriptor());
        data.writeString16(name);
        remote()->transact(TEST_FUN, data, &reply);
        String16 _str = reply.readString16();
        return _str;
        
    }

};

IMPLEMENT_META_INTERFACE(testservice, "android.test.Itestservice");

status_t Bntestservice::onTransact(uint32_t code, const Parcel &data,
                                   Parcel *reply, uint32_t flags)
{
    switch(code)
    {
        case TEST_FUN: {
            CHECK_INTERFACE(Itestservice, data, reply);
            String16 _name = data.readString16();
            String16 _str = testfun(_name);
            reply->writeString16(_str);
            return NO_ERROR;
        }
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}