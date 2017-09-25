// GCC> g++ -std=c++14
#include <cassert>

template <typename T>
auto fn (int n = T{42}) // MSVC = Sure!
{                       // Clang = Sure!
    return n;           // GCC = Sure!
}

int main ()
{
    assert(fn<bool>(1) == 1); // MSVC = Why not!
                              // Clang = Why not!
                              // GCC = Why not!

#if (FAIL == 1)
    assert(fn<bool>() == 42); // MSVC = Nope!
                              // Clang = Nope!
                              // GCC = Nope!
#endif
}
