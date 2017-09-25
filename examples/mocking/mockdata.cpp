// GCC> g++ -std=c++14
#include <experimental/array>
#include <cassert>
#include <fstream>
#include <stdexcept>

enum class mock
{
    MOCK,
    NOMOCK,
};

mock nomock () { return mock::NOMOCK; }

class file_data
{
 private:
    mock mock_state;

 public:
    constexpr file_data (mock mock_state = nomock())
      : mock_state(mock_state)
    { }

    constexpr std::array<int, 3> getNumbers () const
    {
        if (mock_state == mock::MOCK)
            return std::experimental::make_array(0, 1, 2);
        else
        {
            std::array<int, 3> a {0, 0, 0};
            delegateRead(a);
            return a; 
        }
    }

    void delegateRead (std::array<int, 3>& a) const
    {
        std::ifstream in { "numbers.dat" };
        in >> a[0] >> a[1] >> a[2];
    }
};

int main ()
{
  {
    file_data fd;
    auto numbers = fd.getNumbers();
    assert(numbers[0] == 32);
    assert(numbers[1] == 64);
    assert(numbers[2] == 128);
  }

  {
    constexpr file_data fd {mock::MOCK};
    constexpr auto numbers = fd.getNumbers();
    static_assert(numbers[0] == 0);
    static_assert(numbers[1] == 1);
    static_assert(numbers[2] == 2);
  }

    return 0;
}

