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
	int counter[12];
	memset(counter, 0, sizeof(counter));
	while (fscanf(fp, "%s", line) != EOF)
	{
		std::string command(line);
		input.push_back(command);
		for (int i = 0 ; i < command.length() ; i++)
		{
			if (command[i] == '1')
				counter[i]++;
			else if (command[i] == '0')
				continue;
			else
				continue;
		}
	}
	std::stringstream gamma, epsilon;
	for (int i = 0 ; i < 12 ; i++)
	{
		if (input.size() / 2 < counter[i])
			gamma << "1";
		else
			gamma << "0";
	}

	for (int i = 0 ; i < 12 ; i++)
	{
		if (input.size() / 2 < counter[i])
			epsilon << "0";
		else
			epsilon << "1";
	}

	std::cout << "Gamma: " << gamma.str() << std::endl << "Epsilon: " << epsilon.str() << std::endl;
	int gammeConverted = stoi(gamma.str(), 0, 2);
	int epsilonConverted = stoi(epsilon.str(), 0, 2);
	std::cout << "Gamma: " << gammeConverted << std::endl << "Epsilon: " << epsilonConverted << std::endl;
	std::cout << "Answer: " << gammeConverted * epsilonConverted << std::endl;
	fclose(fp);
	return 0;
}
