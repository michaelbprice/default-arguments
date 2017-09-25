// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

auto fn (string s, bool b = true)
{
    return (b) ? s : "";
}

auto fn (string s = "foo", bool b);

int main ()
{
    assert(fn() == "foo");

    assert(fn("bar") == "bar");

    assert(fn("baz", false) == "");
}
