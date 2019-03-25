#include "Testservie.hpp"


sp<TestService> _g = NULL;

TestService::TestService()
{

}

TestService::~TestService()
{

}

sp<TestService> TestService::self()
{
    if (_g == NULL) {
         _g = new TestService();
    }
    return _g;
}

String16 TestService::testfun(const String16& name)
{
    return String16("Hello ") + name;
}



