// GCC> g++ -std=c++17
#include <cassert>
#include <string>
#include <unordered_map>
using namespace std;

static unordered_map<int, string> types;

template <typename T>
static int register_type ()
{
    types[T::_id] = T::name;
    return T::_id;
}

#define PASTE_IMPL(x,y) x ## y
#define PASTE(x,y) PASTE_IMPL(x,y)
#define REGISTER(name) auto PASTE(line,__LINE__) = register_type<name>();

struct Base
{
    using self_t = Base;
    constexpr static int _id = 1;
    constexpr static const char* name = "Base";
    
    virtual string fn (int id = self_t::_id) = 0;
};
REGISTER(Base);

struct Derived : Base
{
    using self_t = Derived;
    constexpr static int _id = 2;
    constexpr static const char* name = "Derived";
    
    virtual string fn (int id = self_t::_id) override
    {
        return types[id];
    }
};
REGISTER(Derived);

int main ()
{
    Derived d;
    assert(d.fn() == "Derived");

    Base & db = d;
    assert(db.fn() == "Base");
}
