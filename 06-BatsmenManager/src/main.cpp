#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "print.hpp"

class batman
{
private:
    /* data */
public:
    int score = 0;
    std::string name;
    std::vector<int> runs;
    std::vector<int> weights = {1, 2, 4, 6, 8};
    void set(std::string n, std::initializer_list<int> r)
    {
        name = n;
        runs = r;
        for (size_t i = 0; i < 5; i++)
        {
            score += runs[i] * weights[i];
        }
    }
    void set(std::string n, std::vector<int> r)
    {
        name = n;
        runs = r;
        for (size_t i = 0; i < 5; i++)
        {
            score += runs[i] * weights[i];
        }
    };
    int get_score() { return score; }
};

struct less_than_key
{
    inline bool operator()(batman &bat1, batman &bat2)
    {
        return (bat1.get_score() < bat2.get_score());
    }
};

struct MatchString
{
    MatchString(const std::string &s) : s_(s) {}
    bool operator()(const batman &obj) const
    {
        return obj.name == s_;
    }

private:
    const std::string &s_;
};

class BatsmenManager
{
public:
    int lowestScore = 0;
    std::vector<batman> batsmen;
    void add(std::string s, std::initializer_list<int> v)
    {
        batman *b = new batman();
        b->set(s, v);
        if (batsmen.size() < 5 || b->get_score() > lowestScore)
        {
            batsmen.push_back(*b);
        };
        if (!batsmen.empty())
        {
            lowestScore = batsmen[0].get_score();
        }
        std::sort(batsmen.begin(), batsmen.end(), less_than_key());
        if (batsmen.size() > 10)
            batsmen.pop_back();
    }
    void remove(std::string s) {
        auto it = std::find_if(batsmen.begin(), batsmen.end(), MatchString(s));
        batsmen.erase(it);
    }
};

int main(int argc, char *argv[])
{
    BatsmenManager B;
    B.add("Aniket", {1, 2, 3, 4, 6});
    B.add("Aaryan", {1, 2, 3, 4, 5});
    B.add("Avinash", {1, 2, 3, 4, 5});
    B.add("Anshuman", {0, 0, 3, 4, 5});
    B.add("Anshul", {0, 2, 3, 4, 5});
    B.add("Anudit", {0, 2, 3, 4, 5});
    B.add("Abhinav", {0, 0, 0, 4, 5});
    B.add("Abhimanyu", {0, 2, 3, 4, 5});
    B.add("Anurup", {10, 2, 3, 4, 5});
    B.add("Jai", {1, 2, 3, 4, 2});
    B.add("J", {0, 0, 0, 0, 100});
    B.add("K", {1, 0, 0, 0, 100});
    int i = 0;
    for (auto it = B.batsmen.rbegin(); it != B.batsmen.rend(); it++)
    {
        i++;
        lib::print("\n", i, it->name, it->get_score());
    }
    i = 0;

    while (true)
    {
        std::cout << ("\n\n Press\n\
 1. Insert a score of a new player.\
(Name, number of 1s,2s,3s,4s,6s)\n \
2. Display scorecard. (display list of top 10 players.)\n \
3. Delete a player from scorecard.\n Enter your choice:");
        char ch;
        std::cin >> ch;
        char s[100];
        int one, two, three, four, six;
        switch (ch)
        {
        case 'q':
            exit(0);
            /* code */
            break;

        case '1':
            std::cout << " Enter Name:";
            std::cin >> s;
            std::cout << " 1s: ";
            std::cin >> one;
            std::cout << " 2s: ";
            std::cin >> two;
            std::cout << " 3s: ";
            std::cin >> three;
            std::cout << " 4s: ";
            std::cin >> four;
            std::cout << " 6s: ";
            std::cin >> six;
            B.add(s, {one, two, three, four, six});
            break;
        case '2':
            for (auto it = B.batsmen.rbegin(); it != B.batsmen.rend(); it++)
            {
                i++;
                lib::print("\n", i, it->name, it->get_score());
            }
            i = 0;
            break;
        case '3':
        std::cout << " Enter player name to be removed: ";
            std::cin >> s;
            B.remove(s);
            break;

        default:
            break;
        }
    }
}