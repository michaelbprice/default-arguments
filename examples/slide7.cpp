// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

auto fn (string s = "foo")
{
    return s;
}

int main ()
{
    assert(fn("foobar") == "foobar");
    assert(fn() == "foo");
    return 0;
}
