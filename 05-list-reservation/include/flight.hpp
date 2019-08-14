#include <string>
#include <utility>
#include "list.hpp"

class flight
{
    lib::list<std::string> passengers;
    std::string flightNumber;

public:
    flight(std::string flightNumberVal) : flightNumber(flightNumberVal) {}
    flight(std::pair<std::string, std::initializer_list<std::string>> p)
    {
        flightNumber = std::get<0>(p);
        passengers = std::get<1>(p);
    }
    flight(std::string flightNumberVal, std::initializer_list<std::string> passengersVal)
        : flightNumber(flightNumber),
          passengers(passengersVal)
    {
    }
};
