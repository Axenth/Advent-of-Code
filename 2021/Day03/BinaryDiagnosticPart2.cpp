#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

//stoi(str, index, base)
int main(int argc, char **argv)
{
	std::vector<std::string> input;
	if (argc < 2)
	{
		std::cout << "Usage: Binary <binary_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	char line[13];
	while (fscanf(fp, "%s", line) != EOF)
	{
		std::string command(line);
		input.push_back(command);
		input.push_back(command);
	}

	std::vector<std::string> o2Vector(input.begin(), input.end());
	for (int i = 0; i < 12; i++)
	{
		int counter = 0;
		int counter2 = 0;
		for(std::vector<std::string>::iterator it = o2Vector.begin(); it != o2Vector.end(); it++)
		{
			std::string temp = *it;
			if (temp[i] == '1')
				counter++;
			else if (temp[i] == '0')
				counter2++;
		}
		int majorbit = (counter >= counter2) ? 1 : 0;		
		std::vector<std::string> temp;
		for(std::vector<std::string>::iterator it = o2Vector.begin(); it != o2Vector.end(); it++)
		{
			std::string temp2 = *it;
			if (temp2[i] == majorbit + '0')
			{
				temp.push_back(temp2);
			}
		}
		o2Vector.clear();
		for(auto it = temp.begin(); it != temp.end(); it++)
			o2Vector.push_back(*it);
	}

	std::vector<std::string> co2Vector(input.begin(), input.end());
	for (int i = 0; i < 12; i++)
	{
		int counter = 0;
		int counter2 = 0;
		for(std::vector<std::string>::iterator it = co2Vector.begin(); it != co2Vector.end(); it++)
		{
			std::string temp = *it;
			if (temp[i] == '1')
				counter++;
			else if (temp[i] == '0')
				counter2++;
		}
		int minorbit = (counter2 <= counter) ? 0 : 1;		
		std::vector<std::string> temp;
		for(std::vector<std::string>::iterator it = co2Vector.begin(); it != co2Vector.end(); it++)
		{
			std::string temp2 = *it;
			if (temp2[i] == minorbit + '0')
			{
				temp.push_back(temp2);
			}
		}
		co2Vector.clear();
		for(auto it = temp.begin(); it != temp.end(); it++)
			co2Vector.push_back(*it);
	}

	std::cout << "The number of programs is " << o2Vector.size() << " " <<  co2Vector.size() << std::endl;
	std::cout << "Oxygen: " << o2Vector[0] << std::endl;
	std::cout << "Co2: " << co2Vector[0] << std::endl;
	
	int value1 = stoi(o2Vector[0], 0, 2);
	int value2 = stoi(co2Vector[0], 0, 2);

	std::cout << "The value is " << value1 << " " << value2 << std::endl;
	std::cout << "result " << value1 * value2 << std::endl;

	fclose(fp);
	return 0;
}
