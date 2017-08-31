#include <cassert>

struct Base
{
    static int fn (int x = 1)
    {
        return x;
    }
};

struct D_one : Base
{
    static int fn (char);

    using Base::fn; // Bring base names back into overload set!
};

struct D_two : Base
{
    using Base::fn;

    static int fn (int x = 1) // Hides Base::fn!
    {
        return x + 1;
    }
};

int main ()
{
    assert(Base::fn() == 1);

    assert(D_one::fn() == 1);

    assert(D_two::fn() == 2);
    assert(D_two::Base::fn() == 1);
    
    return 0;
}
