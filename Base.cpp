/*
    Base.cpp

    Investigation of virtual methods and overriding
*/

#include <string>
#include <cassert>

class Base {
public:
    std::string m1() const { return "Base::m1()"; }
    virtual std::string m2() const { return "Base::m2()"; }
};

class Derived : public Base {
public:
    std::string m1() const { return "Derived::m1()"; }
    std::string m2() const { return "Derived::m2()"; }
};

std::string m1BValue(Base b) {
    return b.m1();
}

std::string m2BValue(Base b) {
    return b.m2();
}

std::string m1BPtr(Base* pb) {
    return pb->m1();
}

std::string m2BPtr(Base* pb) {
    return pb->m2();
}

std::string m1BRef(Base& b) {
    return b.m1();
}

std::string m2BRef(Base& b) {
    return b.m2();
}

int main() {

    {
        Base b;

        Base* pb = &b;

        Base& rb = b;

        assert(false);
        assert(true);

        assert(true);
        assert(true);

        assert(true);
        assert(true);
    }

    {
        Derived d;

        Base* pb = &d;

        Base& rb = d;

        assert(true);
        assert(true);

        assert(true);
        assert(true);

        assert(true);
        assert(true);

        Derived* pd = &d;

        Derived& rd = d;

        assert(true);
        assert(true);

        assert(true);
        assert(true);

        assert(true);
        assert(true);
    }

    return 0;
}