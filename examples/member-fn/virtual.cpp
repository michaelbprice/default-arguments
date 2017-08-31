#include <cassert>

struct Base
{
    virtual int pure (int x = 1) = 0;

    virtual int pure_with_definition (int x = 1) = 0;

    virtual int pure_with_definition_2 (int x) = 0;

    virtual int fn (int x = 1)
    {
        return x;
    }
};

int Base::pure_with_definition (int x)
{
    return x;
}

int Base::pure_with_definition_2 (int x = 1)
{
    return x;
}

struct Derived : Base
{
    virtual int pure (int x = 42) override
    {
        return x;
    }

    virtual int pure_with_definition (int x = 42) override
    {
        return Base::pure_with_definition(x);
    }

    virtual int pure_with_definition_2 (int x) override;
  
    virtual int fn (int x = 42) override
    {
        return x;
    }
};

int Derived::pure_with_definition_2 (int x = 42)
{
    return Base::pure_with_definition_2(x);
}

int main ()
{
    Derived d; 
    assert(d.pure() == 42);
    assert(d.pure_with_definition() == 42);
    assert(d.pure_with_definition_2() == 42);
    assert(d.fn() == 42);

    Base & b = d;
    assert(b.pure() == 1);
    assert(b.pure_with_definition() == 1);
    assert(b.pure_with_definition_2() == 1);
    assert(b.fn() == 1);
    return 0;
}
