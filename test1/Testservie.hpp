#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H

#include "Itestservice.hpp"

class TestService : public Bntestservice {
public:
    static sp<TestService> self();
    virtual String16 testfun(const String16& name);
private:
    TestService();
    virtual ~TestService();
};







#endif // TEST_SERVICE_H