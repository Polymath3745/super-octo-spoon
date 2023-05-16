#include <iostream>
#include <typeinfo>

// derives return type from the return expression
template <typename lT, typename rT>
auto tf(const lT &lhs, const rT &rhs)
{
    return lhs + rhs;
}

int main()
{
    int i = 47;
    const char *cstr = "this is a c-string";
    const std::string sclass = std::string("this is a string class string");

    auto x = "this is a c-string";
    // declare type
    // derives type based on passed expression
    // declares that "y" will be the type derived from x
    decltype(x) y;

    std::cout << "type of is is " << typeid(i).name() << std::endl;
    std::cout << "type of cstr is " << typeid(cstr).name() << std::endl;
    std::cout << "type of sclass is " << typeid(sclass).name() << std::endl;
    std::cout << "type of x is " << typeid(x).name() << std::endl;
    std::cout << "type of y is " << typeid(y).name() << std::endl;

    for(auto it = sclass.begin(); it != sclass.end(); it++)
    {
        std::cout << *it << " ";
    }

    for(auto c : sclass)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // derives type from the return of template function
    auto z = tf<std::string, const char*>(sclass, cstr);
    std::cout << "z is " << z << std::endl;
    std::cout << "type of z is " << typeid(z).name() << std::endl;

    return 0;
}