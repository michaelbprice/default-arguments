#include <cassert>

int a = 9;

namespace N {

int get()
{
    return 42;
}

int fn_one (int x = get())
{
    return x;
}

//int fn_two (int a = 1, int b = a) // Does not compile!
int fn_two (int a = 1, int b = ::a)
{
    return b;
}

}

int get()
{
    return -42;
}

int main ()
{
    assert(N::fn_one() == 42);
    assert(N::fn_one(get()) == -42);

    assert(N::fn_two() == 9);
    assert(N::fn_two(2) == 9);

    return 0;
}
