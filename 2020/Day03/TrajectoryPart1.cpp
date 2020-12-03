#include <iostream>
#include <fstream>

int main(void)
{
    std::size_t size = 323;
    std::size_t count = 0;
    int         map[size][size * 10];

    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            int k = 0;
            std::getline(file, line);
            for (int j = 0; j < size * 10; j++)
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
        x += 3;
        if (map[j][x] == 1)
            count++;
        
    }
    
    /* *PRINT THE MAP*
    for (int i = 0; i < size; i++)
    {
        for (int k = 0 ; k < size * 10; k++)
            std::cout << map[i][k];
        std::cout << std::endl;
    }
    */
   
    std::cout << count << " Trees!" << std::endl;
}


