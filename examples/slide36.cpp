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

struct D_one : Base
{
    void fn (char);

    using Base::fn; // Bring Base names back into overload set!
};

struct D_two : Base
{
    using Base::fn;

    auto fn (string s = "foo")
    {
        return s + "!!!"; // Hides Base::fn!
    }
};

int main ()
{
    Base b;
    assert(b.fn() == "foo");

    D_one d_one;
    assert(d_one.fn() == "foo");

    D_two d_two;
    assert(d_two.fn() == "foo!!!");
    assert(d_two.Base::fn() == "foo");
}
