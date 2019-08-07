#ifndef PRINT__
#define PRINT__

#include <iostream>

namespace lib
{

template <typename T>
void print(T elem)
{
    std::cout << elem << " ";
}

template <typename T, typename... Args>
void print(T elem, Args... args)
{
    print(elem);
    print(args...);
}

}; // namespace lib
#endif