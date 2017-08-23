#include <cassert>

unsigned char fn (unsigned char c = 'a', int n = 42)
{
    return n == 42 ? c : '0';
}

int main ()
{
    assert(fn() == 'a');
    assert(fn('a') == 'a');

  {
    assert(fn() == 'a');
    assert(fn('a') == 'a');

    unsigned char fn (unsigned char, int);
    //assert(fn() == 'a'); // No longer compiles!
    //assert(fn('a') == 'a'); // No longer compiles!
    assert(fn('a', 42) == 'a');
  }

  {
    unsigned char fn (unsigned char, int = 10);
    assert(fn('a') == '0');
  }

  {
    unsigned char fn (unsigned char, int = 10);
    unsigned char fn (unsigned char = 'z', int);
    assert(fn() == '0');
  }

    return 0;
}

