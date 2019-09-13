#include "print.hpp"
#include "queue.hpp"

int main(int argc, char *argv[])
{
    lib::queue<int> q;
    q.enqueue(1);
    q.print();
    return 0;
}