#include <iostream>
#include <vector>
#include "print.hpp"
#include "file.hpp"

class C
{
    std::string name = "ihsdaf";
    friend std::ostream &operator<<(std::ostream &out, const C &c);
public:
};
std::ostream &operator<<(std::ostream &out, const C &c)
{
    out << c.name;

    return out;
}
int main(int argc, char *argv[])
{
    std::ifstream t("input.txt");

    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    // lib::print(str);
    std::string *s;
    s = new std::string;
    std::vector<std::string *> v(10);

    int k = 0;
    v[0]  = new std::string;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '\n')
        {
            k++;
            v[k] = new std::string;
            // v.push_back(s);
            // s = new std::string;
            continue;

        }
        *v[k] += str[i];
    }
    for (size_t i = 0; i < 9; i++)
    {
        lib::print(*v[i]);
    }
    
    
    // lib::print(v);
    // std::vector<C> obj(5);
    // std::vector<std::vector<C>> obj2D(5,obj);
    // lib::print(obj2D);
    return 0;
}