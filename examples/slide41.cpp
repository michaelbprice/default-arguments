// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

struct Base
{
    auto fn (string s = "foo")
    {
        return do_fn(s);
    }

 private:
    virtual string do_fn (string s)
    {
        return s;
    }
};

struct Derived : Base
{
 private:
    virtual string do_fn (string s) override
    {
        return s + "!!!";
    }
};

int main ()
{
    Base b;
    assert(b.fn() == "foo");

    Derived d;
    assert(d.fn() == "foo!!!");
}
