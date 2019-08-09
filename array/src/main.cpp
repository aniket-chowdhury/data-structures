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
    void Name(){
        std::cout << name;
    }
    void insert()
    {
        int id_v;
        std::cout << "id ";
        std::cin >> id_v;
        int exp_v;
        std::cout << "exp ";
        std::cin >> exp_v;

        int salary_v;
        std::cout << "salary ";
        std::cin >> salary_v;

        int contact_v;
        std::cout << "contact ";
        std::cin >> contact_v;

        std::string name_v;
        std::cout << "name ";
        std::cin >> name_v;

        std::string department_v;
        std::cout << "department ";
        std::cin >> department_v;

        std::string address_v;
        std::cout << "address ";
        std::cin >> address_v;

        std::string email_v;
        std::cout << "email ";
        std::cin >> email_v;

        std::string position_v;
        std::cout << "position ";
        std::cin >> position_v;

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

    while (true)
    {

        std::cout << "1. Print:\n2. Delete\n3. Insert\n4. Search\nPick a choice: ";

        char ch;
        std::cin >> ch;

        int i;

        switch (ch)
        {
        case '1':
            std::cout << "Enter Row Number: ";
            std::cin >> i;
            if (i < 0 || i > 50)
            {
                std::cout << "Out of range";
                break;
            }
            emp[i].print();
            break;
        case '2':
            std::cout << "Enter Row Number: ";
            std::cin >> i;
            if (i < 0 || i > 50)
            {
                std::cout << "Out of range";
                break;
            }
            emp[i].clear();
            std::cout << "Row cleared";
            break;

        case '3':
            std::cout << "Enter Row Number: ";
            std::cin >> i;
            if (i < 0 || i > 50)
            {
                std::cout << "Out of range";
                break;
            }
            emp[i-1].insert();
            std::cout << "Row entered.";
            break;
        case '4':
            std::cout << "Enter Id: ";
            std::cin >> i;
            if (i < 0 || i > 50)
            {
                std::cout << "Out of range";
                break;
            }
            for (int k = 0; k < 50; k++)
            {
                if (i == k)
                {
                    emp[k].Name();
                }
            }
            std::cout << "\n";
            break;

        case 'q':
            exit(0);
        default:
            std::cout << "Wrong command";
            break;
        }
        std::cout << "\n\n\n";
    }
}
