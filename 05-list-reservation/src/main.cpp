#include <iostream>
#include <vector>

#include "print.hpp"
#include "flight.hpp"

int main(int argc, char *argv[])
{
    std::vector<flight> flights;
    flight a1("s1");
    flight a2("s2");

    flights.push_back(a1);
    flights.push_back(a2);

    flights[0].append({"Raja", "Mohan", "Phalguni", "Mahima"});
    flights[1].append({"Sunder", "Rashmi", "Srikant"});

    flights[0].print();
    flights[1].print();

    lib::print(flights[0].getPassengers().begin()->element);
    return 0;
}