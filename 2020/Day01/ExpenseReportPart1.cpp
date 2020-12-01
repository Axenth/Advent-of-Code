#include <iostream>
#include <fstream>

int main(void)
{
    int size = 200;
    int arr[200];
    int to_find = 2020;

    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            std::getline(file, line);
            int temp = std::stoi(line, nullptr, 0);
            arr[i] = temp;
        }
    }
    file.close();
    for(int i = 0; i < size; i++)
    {
       for (int j = 0; j < size; j++)
       {
           if (j == i) j++;
           if (arr[i] + arr[j] == to_find)
           {
               std::cout << arr[i] << " + " << arr[j] << " = " << to_find << std::endl;
               std::cout << arr[i] << " * " << arr[j] << " = " << arr[i] * arr[j] << std::endl;
           }
       }
    }
}