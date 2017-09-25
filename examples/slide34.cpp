// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

struct Base
{
    auto fn (string s = "foo")
    {
        return s;
    }
};

struct Derived : Base
{
    auto fn (bool)
    {
        return "char"; // Hides Base::fn!
    }
};

int main ()
{
    Base b;
    assert(b.fn() == "foo");

    Derived d;

#if (FAIL == 1)
    assert(d.fn()       == "foo"); // Does not compile!
#endif

    assert(d.Base::fn() == "foo");

    assert(d.fn("foo")  == "char"); // Slightly unnerving!
}
