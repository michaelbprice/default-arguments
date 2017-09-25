// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

string fn (string s = "foo", bool b = true)
{
    return (b) ? s : "";
}

int main ()
{
    assert(fn() == "foo");

    {
        string fn (string, bool); // Hides previous DFAs!!!

#if (FAIL == 1)
        assert(fn()      == "foo"); // No longer compiles!
        assert(fn("bar") == "bar"); // No longer compiles!
#endif
    }

    {
        string fn (string, bool = false);  // Hides previous DFAs!!!
        string fn (string = "baz", bool);

        // Both parameters now have DFAs.
        assert(fn() == "");
    }
}

