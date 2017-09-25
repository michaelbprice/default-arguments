// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

string fn (string s, int n = 42)
{
    return (n == 42) ? "foo" : s;
}

string fn (string s, bool b = false)
{
    return b ? s : "bar";
}

int main ()
{
    assert(fn("baz", 42)   == "foo");
    assert(fn("baz", true) == "baz");

    // Fails to compile
    //assert(fn("foobar")    == "???"); 
}

