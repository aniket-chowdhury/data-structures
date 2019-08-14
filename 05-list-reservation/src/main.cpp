#include <iostream>
#include <vector>

#include "print.hpp"
#include "flight.hpp"

int main(int argc, char *argv[])
{
    std::vector<flight> flights;
    flight a1("s1");

    flights.push_back(a1);

    flights[0].append({"Raja", "Mohan", "Phalguni", "Mahima"});
    flights[0].append({"Raja",  "Mahima"});
    flights[0].append({"Raja"});

    flights[0].remove({"Raja",  "Mahima"});
    lib::print(flights[0].getPassengers().size());
    flights[0].print();
    return 0;
}