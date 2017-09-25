// GCC> g++ -std=c++17
#include <experimental/source_location>
#include <cassert>
#include <iostream>

using namespace std;
using loc = experimental::source_location;
 
void my_assert(bool test, const char* reason,
               loc location = loc::current())
{
    if (!test)
    {
         cout << "Assertion failed: " << location.file_name << ":" 
              << location.line << ":" << location.column << ": "
              << "in function " << location.function_name << ": "
              << reason << std::endl;
    }
}
 
int main ()
{   
    // will print out with correct filename,
    // line and column numbers, and function name.
    my_assert(false, "On purpose");
}
