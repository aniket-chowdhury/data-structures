#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include "print.hpp"
using namespace std;

vector<int> merge(vector<int> left, vector<int> right)
{
    int leftCount = 0;
    int rightCount = 0;

    vector<int> results;

    bool useLeft;
    for (int i = 0; i < left.size() + right.size(); i++)
    {
        if (leftCount < left.size())
        {
            if (rightCount < right.size())
            {
                useLeft = (left[leftCount] < right[rightCount]);
            }
            else
            {
                useLeft = true;
            }
        }
        else
        {
            useLeft = false;
        }

        if (useLeft)
        {
            results.push_back(left[leftCount]);
            if (leftCount < left.size())
            {
                leftCount++;
            }
        }
        else
        {
            results.push_back(right[rightCount]);
            if (rightCount < right.size())
            {
                rightCount++;
            }
        }
    }
    return results;
}

vector<int> mergeSort(vector<int> arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }
    int len = floor(arr.size() / 2);
    vector<int> left(arr.begin(), arr.begin() + len);
    vector<int> right(arr.begin() + len, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

int main(int argc, char *argv[])
{
    std::vector<int> v = {1, 5, 13, 29,
                          11, 16, 25, 38,
                          45, 49, 52, 57,
                          51, 54, 59, 66};

    auto v1 = mergeSort(v);
    std::cout << "Enter element to find:";
    int x;
    cin >> x;
    for (auto &&i : v1)
    {
        if (i == x)
        {
            std::cout << "True";
            break;
        }
    }
}