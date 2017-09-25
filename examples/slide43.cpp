// GCC> g++ -std=c++14
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
    virtual string fn (string s = "bar") override
    {
        return s + "!!!";
    }
};

int main ()
{
    Base b;
    assert(b.fn() == "foo");

    Derived d;
    assert(d.fn() == "bar!!!");

    Base & b_ref_to_d = d;
    assert(b_ref_to_d.fn() == "foo!!!");
}
