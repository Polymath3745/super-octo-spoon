#include <iostream>
#include <string>


template <typename T>
T maxOf(const T &a, const T &b)
{
    return (a > b ? a:b);
}

int main()
{
    int a = 7;
    int b = 9;

    std::cout << "max is: "  << maxOf<int>(a,b) << std::endl;
    std::cout << "max is: "  << maxOf<short int>(a,b) << std::endl;
    std::cout << "max is: "  << maxOf<long int>(a,b) << std::endl;
    return 0;
}   
