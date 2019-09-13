#include <iostream>
#include <vector>

#include "print.hpp"
#include "file.hpp"

using lib::print;



int main(int argc, char *argv[])
{
    lib::end e("213");
    print(1,2,3,4,5,e);
    return 0;
}
