#include <bitset>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

template<typename T>
std::string typeToBin(const T& value)
{
    const std::bitset<std::numeric_limits<T>::digits + 1> bs(value);
    const std::string s(bs.to_string());
    const std::string::size_type pos(s.find_first_not_of('0'));
    return pos == std::string::npos ? "0" : s.substr(pos);
}

int main()
{

std::cout << '\n';

    int N = 1041;
    std::cout << typeToBin(N);

return 0;
}
