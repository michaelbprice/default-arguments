// GCC> g++ -std=c++14
#include <cassert>
#include <string>
#include <vector>
using std::string;
using std::vector;

size_t index = 0;
vector<string> v = { "foo", "bar" };

string next ()
{
    return v[index++];
}

auto defaults (string first = next(),
               string second = next())
{
    return first + second;
}

auto delegate (string first, string second)
{
    return first + second;
}

auto delegate (string first)
{
    return delegate(first, next());
}

auto delegate ()
{
    return delegate(next());
}

int main ()
{
    index = 0;
    assert(defaults() == "barfoo"); // WHAT!!!

    index = 0;
    assert(delegate() == "foobar");

    index = 0;
    assert(delegate(next(), next()) == "barfoo"); // OOPS!
}
