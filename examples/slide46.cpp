// GCC> g++ -std=c++14
#include <cassert>
#include <string>
using std::string;

struct Base
{
    auto fn ()
    {
        return do_fn(get_fn_default());
    }

    auto fn (string x)
    {
        return do_fn(x);
    }

 private:
    virtual string do_fn (string s)
    {
        return s;
    }

    virtual string get_fn_default ()
    {
        return "foo";
    }
};

struct Derived : Base
{
 private:
    virtual string do_fn (string s) override
    {
        return s + "!!!";
    }
 
    virtual string get_fn_default () override
    {
        return "bar";
    }
};

int main ()
{
    Base b;
    assert(b.fn() == "foo");

    Derived d;
    assert(d.fn() == "bar!!!");

    Base & b_ref_to_d = d;
    assert(b_ref_to_d.fn() == "bar!!!");
}
