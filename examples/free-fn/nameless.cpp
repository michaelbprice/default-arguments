#include <cassert>

unsigned char fn (unsigned char = 'a', int =  42);

unsigned char fn (unsigned char c, int n)
{
    return (n == 42) ? c : '0';
}

int main ()
{
    assert(fn() == 'a');
    return 0;
}
