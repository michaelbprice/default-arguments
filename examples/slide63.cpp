// GCC> g++ -std=c++11
#include <cassert>

enum class tag
{
    compiletime,
    runtime
};

tag runtime ()
{
    return tag::runtime;
}

int identity (int n)
{
    return n;
}

constexpr int fn (int n, tag t = runtime())
{
    return (t == tag::runtime) ? identity(n) : n * n;
}

int main ()
{
#if (FAIL == 1)
    static_assert(fn(4) == 16, ""); // Does not compile!
#endif

    assert(fn(4) == 4);  // Selects runtime path!

    // Selects compile-time path!
    static_assert(fn(4, tag::compiletime) == 16, "");
}
