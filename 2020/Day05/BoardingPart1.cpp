#include <iostream>
#include <fstream>
#include <cmath>

static int rowValueLower(float lower, float upper)
{
    return((int)(floor((upper - lower)/ 2) + 1));
}

static int rowValueUpper(float lower, float upper)
{
    return((int)(ceil((upper - lower)/ 2)));
}

int main(void)
{
    std::size_t size = 867;
    int         ID[867];
    int         result = 0;
    std::ifstream file("input");
    if (file.is_open())
    {
        std::string line;
        for(int i = 0 ; i < size; i++)
        {
            std::getline(file, line);
            int upper = 127;
            int lower = 0;
            int rowRes = 0;
            int columnRes = 0;

            for (int j = 0; j < 6; j++)
            {
                if (line.c_str()[j] == 'F')
                    upper -= rowValueLower(lower, upper);
                if (line.c_str()[j] == 'B')
                    lower += rowValueUpper(lower, upper);
            }
            if (line.c_str()[6] == 'F')
                rowRes = lower;
            else if (line.c_str()[6] == 'B')
                rowRes = upper;
            
            lower = 0;
            upper = 7;
            for (int j = 7; j < 9; j++)
            {
                if (line.c_str()[j] == 'L')
                    upper -= rowValueLower(lower, upper);
                if (line.c_str()[j] == 'R')
                    lower += rowValueUpper(lower, upper);    
                
            }
            if (line.c_str()[9] == 'L')
                columnRes = lower;
            else if (line.c_str()[9] == 'R')
                columnRes = upper;
            
            int seatID = rowRes * 8 + columnRes;
            ID[i] = seatID;
        }
    }
    file.close();

    for(int i = 0 ; i < size; i++)
    {
      //  std::cout << ID[i] << std::endl;
        if (ID[i] > result)
            result = ID[i];
    }

     std::cout << "Found: " << result << std::endl;
}