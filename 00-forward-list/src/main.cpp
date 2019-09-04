#include <iostream>
#include "print.hpp"
#include "forward_list.hpp"

template <typename T>
lib::forward_list<T> join(lib::forward_list<T> &l1, lib::forward_list<T> &l2)
{
    lib::forward_list<T> f;
    f.setHead(l1.getHead());
    f.setTail(l1.getTail());
    f.getTail()->next = l2.getHead();
    f.setTail(l2.getTail());
    f.print();
    return f;
}


int main(int argc, char *argv[])
{

    lib::forward_list<int> l2 = {1, 8, 3, 10, 17, 22, 29, 42, 1, 1, 1, 1};
    lib::forward_list<int> l1 = {1, 8, 3, 10, 17, 22, 29};

    l2.nthNode(2);
    std::cout << std::endl;
    l2.alternate();
    l2.print();
    std::cout << std::endl;

    l2.removeDuplicates();
    l2.print();
    std::cout << std::endl;

    auto s = join(l1, l2);
    s.reverse();
    std::cout << std::endl;
    

    s.print();
    s.swapnode(29,17);

    std::cout << std::endl;

    s.print();
    return 0;
}