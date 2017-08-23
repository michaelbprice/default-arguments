constexpr unsigned char fn (unsigned char c, int n = 42)
{
    return (n == 42) ? c : '0';
}

int main ()
{
    static_assert(fn('a') == 'a');
    static_assert(fn('a', 0) == '0');
    return 0;
}
