#include <iostream>
#include <fstream>

int main(void)
{
    std::size_t size = 323;
    std::size_t count = 0;
    int         map[size][size * 15];
    int         answer[5];

    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            int k = 0;
            std::getline(file, line);
            for (int j = 0; j < size * 15; j++)
            {
                if (k == 31)
                    k = 0;
                if (line.c_str()[k] == '#')
                    map[i][j] = 1;
                else
                    map[i][j] = 0;
                k++;
            }
        }
    }
    file.close();

    int x = 0;
    for (int j = 1; j < 324; j++)
    {
        x += 1;
        if (map[j][x] == 1)
            count++;
    }
    answer[0] = count;
    std::cout << answer[0] << std::endl;
    count = 0;
    x = 0;    
    for (int j = 1; j < 324; j++)
    {
        x += 3;
        if (map[j][x] == 1)
            count++;
    }
    answer[1] = count;
    std::cout << answer[1] << std::endl;
    count = 0;
    x = 0;    
    for (int j = 1; j < 324; j++)
    {
        x += 5;
        if (map[j][x] == 1)
            count++;
    }
    answer[2] = count;
    std::cout << answer[2] << std::endl;
    count = 0;
    x = 0;    
    for (int j = 1; j < 324; j++)
    {
        x += 7;
        if (map[j][x] == 1)
            count++;
    }
    answer[3] = count;
    std::cout << answer[3] << std::endl;
    count = 0;
    x = 0;    
    for (int j = 2; j < 324; j += 2)
    {
        x += 1;
        if (map[j][x] == 1)
            count++;
    }
    answer[4] = count;
    std::cout << answer[4] << std::endl;

    /* *PRINT THE MAP*
    for (int i = 0; i < size; i++)
    {
        for (int k = 0 ; k < size * 10; k++)
            std::cout << map[i][k];
        std::cout << std::endl;
    }
    */
    unsigned long answers = 1;
    for (int i = 0; i < 5; i++)
        answers *= answer[i];
    std::cout << "FOUND: " << answer[0] << " * " << answer[1] << " * " << answer[2] << " * " << answer[3] << " * " << answer[4] << " = " << answers << " Trees!" << std::endl;
}


