constexpr int fn (int n = 42)
{
    return n;
}

int main ()
{
    static_assert(fn() == 42);
    static_assert(fn(0) == 0);
    return 0;
}
