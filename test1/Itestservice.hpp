#ifndef ITESTSERVICE_H
#define ITESTSERVICE_H


#include <binder/IInterface.h>
#include <binder/Parcel.h>


using namespace android;




class Itestservice : public IInterface {
    public:
    DECLARE_META_INTERFACE(testservice);
    virtual String16 testfun(const String16& name_) = 0;
    private:
};


class Bntestservice : public BnInterface<Itestservice> {
    public:
    virtual status_t onTransact(uint32_t code, const Parcel& data,
    Parcel* reply, uint32_t flags = 0);
    
};





#endif // ITESTSERVICE_H