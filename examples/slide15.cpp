// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

auto defaults (string first = "foo", string second = "bar")
{
    return first + second;
}

auto delegate (string first, string second)
{
    return first + second;
}

auto delegate (string first)
{
    return delegate(first, "bar");
}

auto delegate ()
{
    return delegate("foo");
}

int main ()
{
    assert(defaults() == "foobar");
    assert(defaults("baz") == "bazbar");

    assert(delegate() == "foobar");
    assert(delegate("baz") == "bazbar");
}
