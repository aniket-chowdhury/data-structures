#include <iostream>
#include <vector>

#include "print.hpp"
#include "flight.hpp"

int main(int argc, char *argv[])
{
    std::vector<flight> flights;
    std::string s1 = "a1";
    std::string s2 = "a1";

    flight a1("s1");
    flight a2("s2");

    flights.push_back(a1);
    flights.push_back(a2);


    return 0;
}