#include <iostream>
#include <fstream>

int main(void)
{
    std::size_t size = 1000;
    std::size_t count = 0;

    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            std::size_t temp_count = count;
            std::getline(file, line);
            std::size_t pos_minus = line.find("-");
            std::size_t pos_column = line.find(":");
            std::string temp = line.substr(0, pos_minus);
            int min = std::stoi(temp, nullptr, 0);
            temp = line.substr(pos_minus + 1, pos_column);
            int max = std::stoi(temp, nullptr, 0);
            char letter = line.c_str()[pos_column - 1];
            std::string pass = line.substr(pos_column + 1, line.length());
            if (pass.c_str()[min] == letter || pass.c_str()[max] == letter)
            {
                if (pass.c_str()[min] == letter && pass.c_str()[max] == letter)
                    ;
                else
                    count++;
            }
            std::cout << min << " " << max << " " << letter << " " << "[" << pass << "]";
            if (temp_count == count)
                std::cout << " INVALID!";
            std::cout << std::endl;
        }
    }
    file.close();
    std::cout << count << " Valid Passwords!" << std::endl;
}


