#include <cassert>

int get ()
{
    return 42;
}

struct C
{
    static int fn (int x = get())
    {
        return x;
    }

    static int get ()
    {
        return 1;
    }
};

int main ()
{
    assert(C::fn() == 1);
    assert(C::fn(get()) == 42);

    return 0;
}
