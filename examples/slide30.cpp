// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

namespace N
{
    auto fn (string a, string b = "bar")
    {
        return a + b;
    }
}

using N::fn;

void in_the_middle ()
{
    assert(fn("foo") == "foobar");
}

struct C { };

namespace N
{
    // using-decl makes this next, new DFA visible outside N...
    auto fn (string = "foo", string);

    auto fn (C c) { return "C"; } // but not these overloads
    auto fn () { return  ""; }
}

int main ()
{
    in_the_middle();

    assert(fn() == "foobar"); // Not ambiguous!

#if (FAIL == 1)
    assert(fn(C()) == "C");   // Does not compile!
#endif

    assert(N::fn(C()) == "C");
}
