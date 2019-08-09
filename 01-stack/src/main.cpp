#include <iostream>
#include "print.hpp"
#include "stack.hpp"

int fact(lib::stack<int> myStck);

int main()
{
    lib::stack<int> s1;

    lib::stack<int> s2 = {1, 3, 5, 7, 9};

    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.clear();

    // std::cout << s1.empty();

    s1 = {1, 2, 3, 4, 5, 6, 7};

    std::cout << fact(s1);
}

int fact(lib::stack<int> myStck)
{
    auto myStckC = myStck;
    int result = 1;
    while (!myStckC.empty())
    {
        //std::cout<<myStckC.top();
        result *= myStckC.top();
        myStckC.pop();
    }
    return result;
}