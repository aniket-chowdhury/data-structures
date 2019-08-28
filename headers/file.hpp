#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>

namespace lib
{

const std::string readFile(std::string filename)
{
    std::ifstream file;
    std::string line;
    // std::stringstream ss;
    char x;
    file.open(filename);
    std::string str = "";
    for (std::string line; getline(file, line);)
    {
        std::cout << line;
    }
    return str;
}

std::vector<std::string> split_string(std::string filename,
                                      const std::string &delimiter)
{
    const std::string &str = readFile(filename);

    std::vector<std::string> strings;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    strings.push_back(str.substr(prev));

    return strings;
}

} // namespace lib
