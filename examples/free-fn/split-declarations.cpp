#include <cassert>
#include <cctype>

auto fn (unsigned char c, int n = 42)
{
    return n == 42 ? c : std::toupper(c) ;
}

auto fn (unsigned char c = 'a', int n);

int main ()
{
    assert(fn() == 'a');
    assert(fn('b') == 'b');
    assert(fn('c', 0) == 'C');
    return 0;
}

