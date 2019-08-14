#include <iostream>
#include "print.hpp"
#include "forward_list.hpp"

int main(int argc, char *argv[])
{

    lib::forward_list<int> l1;
    lib::forward_list<int> l2 = {23, 5, 76, 6};

    l1.append(34);
    l1.append(4);
    l1.append(24);
    l1.append(2);

    l1.print();
    l2.print();

    lib::print((l1.begin())->element);

    return 0;
}