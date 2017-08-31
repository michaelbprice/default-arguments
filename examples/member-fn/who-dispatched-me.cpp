#include <cassert>

struct Base
{
    using self_t = Base;
    constexpr static int id = 1;
    virtual int fn (int id = self_t::id) = 0;
};

struct Derived : Base
{
    using self_t = Derived;
    constexpr static int id = 2;
    virtual int fn (int id = self_t::id) override
    {
        return id * 10;
    }
};

struct Another : Derived
{
    using self_t = Another;
    constexpr static int id = 3;
    virtual int fn (int id = self_t::id) override
    {
        return id * -1;
    }
};

int main ()
{
    Another a;
    assert(a.fn() == -3);

    Derived & ad = a;
    assert(ad.fn() == -2);

    Base & ab = a;
    assert(ab.fn() == -1);


    Derived d; 
    assert(d.fn() == 20);

    Base & db = d;
    assert(db.fn() == 10);

    return 0;
}
