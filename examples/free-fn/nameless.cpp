#include <cassert>
#include <cctype>

unsigned char fn (unsigned char = 'a', int =  42);

unsigned char fn (unsigned char c, int n)
{
    return (n == 42) ? c : std::toupper(c);;
}

int main ()
{
    assert(fn() == 'a');
    return 0;
}
