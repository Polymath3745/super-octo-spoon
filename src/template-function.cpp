#include <iostream>
#include <string>


template <typename T>
T maxOf(const T &a, const T &b)
{
    return (a > b ? a:b);
}

int main()
{
    std::cout << "hello world" << std::endl;
}
