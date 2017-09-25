// GCC> g++ -std=c++14
#include <cassert>

template <typename T>
auto fn (int n = get(T()))
{
    return n;
}

class A { };

auto get (A)
{
    return 42;
}

int main ()
{
    assert(fn<A>() == 42);
}
