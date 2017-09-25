// GCC> g++ -std=c++14
#include <cassert>

template <typename T>
auto fn (int n = bool{42}) // MSVC = Nope!
{                          // Clang = Nope!
    return n;              // GCC = Why not!
}

int main ()
{
    assert(fn<int>(1) == 1); // GCC = Why not!

#if (FAIL == 1)
    assert(fn<int>() == 42); // GCC = Nope!
#endif
}
