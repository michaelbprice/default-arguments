#include <cassert>

struct C
{
    C (int x) : mx(x) { };

    friend int declaration (const C&);

    friend int definition (const C& c = C{-1})
    {
        return c.mx;
    }

    friend int definition_2 (const C& c)
    {
        return c.mx;
    }

 private:
    int mx;
};

C global_c{42};

// `definition` requires a declaration before it is visible
int definition (const C& c); // Does not work in Clang!

int definition_2 (const C& c = C{-9});

// `declaration` needs a definition if it is to be called
int declaration (const C& c = ::global_c)
{
    return c.mx;
}

int main ()
{
    assert(declaration() == 42);
    assert(definition() == -1);
    assert(definition_2() == -9);

    return 0;
}
