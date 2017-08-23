#include <cassert>

namespace using_defaults {

int sum_of_four (int a = 1, int b = 3, int c = 5, int d = 7)
{
    return a + b + c + d;
}

}

namespace using_delegation {

int sum_of_four (int a, int b, int c, int d)
{
    return a + b + c + d;
}

int sum_of_four (int a, int b, int c)
{
    return sum_of_four(a, b, c, 7);
}

int sum_of_four (int a, int b)
{
    return sum_of_four(a, b, 5);
}

int sum_of_four (int a)
{
    return sum_of_four(a, 3);
}

int sum_of_four ()
{
    return sum_of_four(1);
}

}

int main ()
{
    assert(using_defaults::sum_of_four() == 16);
    assert(using_defaults::sum_of_four(7) == 22);
    assert(using_defaults::sum_of_four(7, 5, 3, 1) == 16);

    assert(using_delegation::sum_of_four() == 16);
    assert(using_delegation::sum_of_four(7) == 22);
    assert(using_delegation::sum_of_four(7, 5, 3, 1) == 16);

    return 0;
}
