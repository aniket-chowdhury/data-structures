#include <iostream>
#include <vector>
#include <fstream>

#include "flight.hpp"
#include "file.hpp"

void place(std::vector<std::string> &v, std::string s)
{
    v.push_back(s);
}

int main(int argc, char *argv[])
{
    std::vector<flight> flights;
    flight a1("s1");

    flights.push_back(a1);

    flights[0].append({"Raja", "Mohan", "Phalguni", "Mahima"});
    flights[0].append({"Raja", "Mahima"});
    flights[0].append({"Raja"});

    flights[0].remove({"Raja", "Mahima"});
    lib::print(flights[0].getPassengers().size());
    lib::readFile("input.txt");
    // std::cout << k[0];
    // std::string str((std::istreambuf_iterator<char>(t)),
    //                 std::istreambuf_iterator<char>());

    // std::string delimiter = "\n";

    // size_t pos = 0;
    // std::string token;
    // int flag = 0;
    // std::vector<std::string> vec;
    // while ((pos = str.find(delimiter)) != std::string::npos)
    // {
    //     token = str.substr(0, pos);

    //     vec.push_back(std::string(token));
    //     // lib::print(vec[0]);
    //     // std::cout << token << std::endl;
    //     str.erase(0, pos + delimiter.length());
    //     if (!(pos = str.find(delimiter)) != std::string::npos)
    //     {
    //         for (size_t i = 0; i < vec.size(); i++)
    //         {
    //             lib::print(vec[i]);
    //         }
    //     }
    // }

    // std::cout << str << std::endl;
    // int count = 0;
    // std::string temp = "";
    // std::vector<std::string> vec;
    // vec.reserve(10);
    // for (size_t i = 0; i < str.size(); i++)
    // {
    //     if (str[i] == '\n')
    //     {
    //         vec[count]=temp;
    //         count++;
    //         temp="";
    //         continue;
    //     }
    //     temp += str[i];
    // }

    // for (size_t i = 0; i < vec.size(); i++)
    // {
    //     std::cout << vec[i];
    // }

    return 0;
}