// GCC> g++ -std=c++03
#include <cassert>

int fn (int =  42);

int fn (int n)
{
    return n;
}

int main ()
{
    assert(fn() == 42);
    return 0;
}
