#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> s(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            continue;
        if (s[i] == 0)
        {
            s[i] = -1;
            s[i - 1] = -1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == -1)
            continue;
        sum += s[i];
    }
    std::cout << sum;
}
