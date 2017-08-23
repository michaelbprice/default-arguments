#include <cassert>

enum class tag
{
    compiletime,
    runtime
};

tag runtime () { return tag::runtime; }

int identity (int n) { return n; }

constexpr int fn (int n, tag t = runtime())
{
    if (t == tag::runtime)
    {
        return identity(n);
    }
    else
    {
        return n + 1;
    }
}

int main ()
{
    //static_assert(fn(42) == 43); // No longer compiles
    assert(fn(42) == 42);  // Selects runtime path!
    static_assert(fn(42, tag::compiletime) == 43); // Selects compiletime path!
    return 0;
}
