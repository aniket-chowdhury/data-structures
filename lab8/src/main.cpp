#include "print.hpp"
#include "list.hpp"



void driver(int n);


lib::list<int> l;
int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;

    driver(n);
    return 0;
}

void driver(int n)
{
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        switch (val)
        {
        case 1:
            l.print_cursive();
            break;
        case 2:
            int num;
            std::cin >> num;
            for (int k = 0; k < num; k++)
            {
                int m;
                std::cin >> m;
                l.append(m);
            }

            break;
        case 3:
            int del;
            std::cin >> del;
            l.remove(del);
            break;
        default:
            break;
        }
    }
}