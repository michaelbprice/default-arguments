#include <cassert>

unsigned char fn (unsigned char c, int n = 42)
{
    return (n == 42) ? c : '0';
}

unsigned char fn (unsigned char c, bool b = false)
{
    return b ? c : c + 1;
}

int main ()
{
    //assert(fn('a') == 'a'); // Now ambiguous
    assert(fn('a', 42) == 'a');
    assert(fn('b', false) == 'c');
    return 0;
}
