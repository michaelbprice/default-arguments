// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

string b = "foo";

namespace N
{
    string fn (string s = b)
    {
        return s;
    }

    string b = "bar";
}

int main ()
{
    assert(N::fn() == "foo");

    assert(N::fn(b) == "foo");

    assert(N::fn(N::b) == "bar");

    b = "foobarbaz";
    assert(N::fn() == "foobarbaz");
}
