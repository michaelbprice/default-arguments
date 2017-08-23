#include <cassert>
#include <cctype>

unsigned char fn (unsigned char c, int n = 42)
{
    return (n == 42) ? c : std::toupper(c);
}

int main ()
{
    assert(fn('a') == 'a');
    return 0;
}
