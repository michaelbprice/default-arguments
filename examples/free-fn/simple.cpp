#include <cassert>

unsigned char fn (unsigned char c, int n = 42)
{
    return (n == 42) ? c : '0';
}

int main ()
{
    assert(fn('a') == 'a');
    return 0;
}
