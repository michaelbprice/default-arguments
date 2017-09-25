// GCC> g++ -std=c++11
#include <cassert>
#include <string>
using std::string;

struct C
{
    C (string s) : label(s) { };

    friend string global_default (const C&);

    friend string friend_decl_default (const C& c = C{"friend declaration"})
    {
        return c.label;
    }

    friend string friend_later_default (const C& c)
    {
        return c.label;
    }

 private:
    string label;
};

C global_c{"global"};

// `friend_decl_default` requires a declaration before it is visible
string friend_decl_default (const C& c); // Does not work in Clang!

string friend_later_default (const C& c = C{"later"});

// `global_default` needs a definition if it is to be called
string global_default (const C& c = ::global_c)
{
    return c.label;
}

int main ()
{
    assert(global_default() == "global");

    assert(friend_decl_default() == "friend declaration");

    assert(friend_later_default() == "later");

    return 0;
}
