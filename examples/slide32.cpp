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

struct Derived : Base { };

int main ()
{
    Derived d;
    assert(d.fn() == "foo");
    assert(d.Base::fn() == "foo");
}
