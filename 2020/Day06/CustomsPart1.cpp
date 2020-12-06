#include <iostream>
#include <fstream>
#include <cmath>

class group
{
    public:

    int chars[255];
    int sum = 0;
    group()
    {
        for (int i = 0; i < 255; i++)
            chars[i] = 0;
    }

    void calc()
    {
        for (int i = 0; i < 255; i++)
        {
            if (chars[i] > 0)
                sum++;
        }
    }

};


int main(void)
{
    std::size_t size = 2087;
    int         group_amount = 460;
    group       groups[group_amount];
    int         group_count = 0;
    int         result = 0;
    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            std::getline(file, line);
            if(line.empty() == true)
                group_count++;
            for (int j = 0; j < line.size(); j++)
                groups[group_count].chars[line.c_str()[j]]++;
        }
    }
    file.close();
    for (int i = 0; i < group_amount; i++)
    {
        groups[i].calc();
        std::cout << groups[i].sum << std::endl;
        result += groups[i].sum;
    }
     std::cout << "Found: " << result << std::endl;
}