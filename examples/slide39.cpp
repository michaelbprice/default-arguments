// GCC> g++ -std=c++11
#include <cassert>
#include <string>
using std::string;

struct Base
{
    virtual string fn (string s = "foo")
    {
        return s;
    }
};

struct Derived : Base
{
    virtual string fn (string s) override
    {
        return s + "!!!";
    }
};

int main ()
{
    Base b;
    assert(b.fn() == "foo");

    Derived d;

#if (FAIL == 1)
    assert(d.fn() == "foo!!!"); // Does not compile!
#endif
}
