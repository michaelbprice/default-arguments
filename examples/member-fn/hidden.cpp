#include <cassert>

struct Base
{
    static int fn (int x = 1)
    {
        return x;
    }
};

struct Derived : Base
{
    static int fn (char)
    {
        return 4;
    }
};

int main ()
{
    assert(Base::fn() == 1);

    //assert(Derived::fn() == 1); // Does not compile!
    assert(Derived::Base::fn() == 1);
    assert(Derived::fn(1) == 4); // Slightly unnerving!

    return 0;
}
