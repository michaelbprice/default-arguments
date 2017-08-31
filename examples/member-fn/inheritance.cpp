#include <cassert>

struct Base
{
    static int fn (int x = 1)
    {
        return x;
    }
};

struct Derived : Base
{ };

int main ()
{
    assert(Base::fn() == 1);
    assert(Derived::fn() == 1);

    return 0;
}
