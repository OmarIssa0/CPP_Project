#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>    

void trim(std::string& str)
{
    while (!str.empty() && (str[0] == ' '  || str[0] == '\t'))
    {
        str.erase(str.begin());
    }
    while (!str.empty() && (str[str.size() - 1] == ' ' || str[str.size() - 1] == '\t'))
    {
        str.erase(str.end() - 1);
    }
}

// -1 & and 0-1000 & empty & 
int main ()
{
    std::ifstream file;
    file.open("test.csv");
    if (!file.is_open())
        std::cout << "Error for read the file" << std::endl;
    std::string line;
    std::map<std::string, float> mapValue;
    std::string key;
    std::string value;

    while (getline(file, line))
    {
        size_t foundSub = line.find("|");
        if (foundSub == std::string::npos)
        {
            std::cout << "Error :" + line << std::endl;
            continue;
        }
        key = line.substr(0, foundSub);
        trim(key);
        if (key.empty())
        {
            std::cout << "Error empty:" + key << std::endl;
            continue;
        }
        value = line.substr(foundSub + 1, line.size());
        trim(value);
        if (value.empty())
        {
            std::cout << "Error empty:" + value << std::endl;
            continue;
        }
        char *endptr = NULL; 
        double num = strtod(value.c_str(), &endptr);
        if (num < 0 || num > 1000)
        {
            std::cout << "Error num 0/1000 :" + value << std::endl;
            continue;    
        }
        std::cout << "key:" + key + "   " + "value: " + value << std::endl;
    }

}