#include <cassert>

auto fn (unsigned char c, int n = 42)
{
    return n == 42 ? c : '0';
}

auto fn (unsigned char c = 'a', int n);

int main ()
{
    assert(fn() == 'a');
    assert(fn('b') == 'b');
    assert(fn('c', 0) == '0');
    return 0;
}

