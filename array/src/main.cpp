#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

std::string random_string(int n)
{
    std::vector<std::string> s({"A", "B", "C", "D", "E", "F", "G", "H",
                                "I", "J", "K", "L", "M", "N", "O", "P",
                                "Q", "R", "S", "T", "U", "V", "W", "X",
                                "Y", "Z", "a", "b", "c", "d", "e", "f",
                                "g", "h", "i", "j", "k", "l", "m", "n",
                                "o", "p", "q", "r", "s", "t", "u", "v",
                                "w", "x", "y", "z"});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, s.size() - 1);

    std::string str = "";
    for (int i = 0; i < n; i++)
    {
        str += s[dis(gen)];
    }
    return str;
}

class employee
{
public:
    employee() {}

    employee(int id_v,
             int exp_v,
             int salary_v,
             int contact_v,
             std::string name_v,
             std::string department_v,
             std::string address_v,
             std::string email_v,
             std::string position_v)
    {
        id = id_v;
        salary = salary_v;
        contact = contact_v;
        name = name_v;
        department = department_v;
        address = address_v;
        email = email_v;
        position = position_v;
        exp = exp_v;
    }

    void update(int id_v,
                int exp_v,
                int salary_v,
                int contact_v,
                std::string name_v,
                std::string department_v,
                std::string address_v,
                std::string email_v,
                std::string position_v)
    {
        id = id_v;
        salary = salary_v;
        contact = contact_v;
        name = name_v;
        department = department_v;
        address = address_v;
        email = email_v;
        position = position_v;
        exp = exp_v;
    }

    void print()
    {
        std::cout << " " << id
                  << " " << salary
                  << " " << contact
                  << " " << name
                  << " " << department
                  << " " << address
                  << " " << email
                  << " " << position
                  << " " << exp << std::endl;
    }
    void clear()
    {
        id = 0;
        salary = 0;
        contact = 0;
        name = "";
        department = "";
        address = "";
        email = "";
        position = "";
        exp = 0;
    }
    int id, salary, contact, exp;
    std::string name, department, address, email, position;
};

void enumerate(employee &e, int i)
{
    e.update(i, rand() % 20, rand() % 200000, rand() % 9999, random_string(12), random_string(12), random_string(12), random_string(12), random_string(12));
}

int main()
{
    srand(time(0));
    int i = 0;
    std::vector<employee> emp(50);

    for (auto &elem : emp)
    {
        enumerate(elem, ++i);
        elem.print();
        if (i == 30)
            break;
    }
    std::cout << std::endl;

    emp[0].print();
    emp[29].print();

    emp[0].clear();
    emp[2].clear();
    emp[29].clear();

    emp[29].update(30, rand() % 20, rand() % 200000, rand() % 9999, random_string(12), random_string(12), random_string(12), random_string(12), random_string(12));
    emp[0].update(1, rand() % 20, rand() % 200000, rand() % 9999, random_string(12), random_string(12), random_string(12), random_string(12), random_string(12));
    emp[1].update(2, rand() % 20, rand() % 200000, rand() % 9999, random_string(12), random_string(12), random_string(12), random_string(12), random_string(12));
}
