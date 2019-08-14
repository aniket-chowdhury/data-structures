#include <string>
#include <utility>
#include "list.hpp"
#include "print.hpp"

class flight
{
    lib::list<std::string> passengers;
    std::string flightNumber;

public:
    lib::list<std::string> getPassengers()
    {
        return passengers;
    }

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

    bool append(std::initializer_list<std::string> passengersVal)
    {
        try
        {
            passengers.append(passengersVal);
            return 1;
        }
        catch (const std::exception &e)
        {
            lib::print(e.what());
            return 0;
        }
    }

    bool remove(std::string s)
    {
        passengers.remove(s);
    }

    bool remove(std::initializer_list<std::string> passengersVal)
    {
        for (auto it = passengersVal.begin(); it < passengersVal.end(); it++)
        {
            // passengers.remove(*it);
        }
    }

    bool print()
    {
        passengers.print();
    }
};
