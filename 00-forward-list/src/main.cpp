#include <iostream>
#include "print.hpp"
#include "forward_list.hpp"
#include "binarytree.hpp"

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

template <typename T>
void removeTail(lib::forward_list<T> &l)
{
    if (l.getHead() == nullptr)
        return;
    lib::node<T> *fence = l.getHead();

    while (fence->next->next != nullptr)
        fence = fence->next;
    delete (fence->next);
    fence->next = nullptr;
    return;
}

template <typename T>
void lastToFirst(lib::forward_list<T> &l)
{
    if (l.getHead() == nullptr || l.getTail() == nullptr)
        return;
    lib::node<T> *n = new lib::node<T>;
    n->next = l.getHead();
    l.setHead(n);
    l.getHead()->element = l.getTail()->element;
    auto fence = new lib::node<T>;
    removeTail(l);
    return;
}

template <typename T>
bool equal(lib::forward_list<T> l1, lib::forward_list<T> l2)
{
    auto f1 = l1.getHead();
    auto f2 = l2.getHead();

    while (f1 != nullptr && f2 != nullptr)
    {
        f1 = f1->next;
        f2 = f2->next;

        if (f1->element != f2->element)
            break;
    }

    return (f1 == nullptr && f2 == nullptr);
}

template <typename T>
lib::forward_list<T> intersection(lib::forward_list<T> &l1, lib::forward_list<T> &l2)
{
    lib::forward_list<int> l;

    return l;
}

template <typename T>
void greaterOnLeft(lib::forward_list<T> &l)
{
    l.reverse();

    lib::node<T> *fence = l.getHead();

    lib::node<T> *max = l.getHead();
    lib::node<T> *temp;

    while (fence != nullptr && fence->next != nullptr)
    {
        if (fence->next->element < max->element)
        {
            temp = fence->next;
            fence->next = temp->next;
            free(temp);
        }
        else
        {
            fence = fence->next;
            max = fence;
        }
    }

    l.reverse();
}

int main(int argc, char *argv[])
{

    lib::forward_list<int> l1 = {1, 2, 3, 10, 17, 22, 29, 42};
    lib::forward_list<int> l2 = {1, 3, 12, 42};
    lib::forward_list<int> l3 = {1, 3, 12, 42};
    lib::forward_list<int> l4 = {12, 15, 10, 11, 5, 6, 2, 3};
    lib::forward_list<int> l5 = {10, 20, 30, 40, 50, 60};
    lib::forward_list<int> l6 = {60, 50, 40, 30, 20, 10};
    lastToFirst(l1);

    l1.print();
    std::cout << std::endl;

    auto l = intersection(l1, l2);
    l.print();

    std::cout << (l2 == l3) << std::endl;

    l1.print();

    std::endl(std::cout);
    greaterOnLeft(l4);
    l4.print();

    std::endl(std::cout);
    greaterOnLeft(l5);
    l5.print();

    std::endl(std::cout);
    greaterOnLeft(l6);
    l6.print();

    return 0;
}