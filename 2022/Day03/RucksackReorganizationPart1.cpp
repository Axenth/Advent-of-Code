#include <iostream>
#include <vector>



int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: RucksackReorganizaiton <input_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}

	char *line;
	size_t length;
	int totalScore = 0;
	std::vector<std::string> inputs;
	std::vector<char> priorityItems;

	while (getline(&line, &length, fp) != -1)
	{
		inputs.push_back(std::string(line));
	}

	for (std::vector<std::string>::iterator it = inputs.begin(); it != inputs.end(); it++)
	{
		std::string tempString = *it;
		if (tempString.empty())
			continue;
		std::string string1, string2;
		std::size_t compartmentSize = tempString.length() / 2;

		string1 = tempString.substr(0, compartmentSize);
		string2 = tempString.substr(compartmentSize);


		for (int i = 0 ; i < string1.length(); i++)
		{
			bool setBreak = false;
			for (int j = 0 ; j < string2.length(); j++)
			{
				if (string1[i] == string2[j])
				{
					priorityItems.push_back(string1[i]);
					setBreak = true;
					break;
				}
			}
			if (setBreak == true)
				break;
		}
	}

	for (std::vector<char>::iterator it = priorityItems.begin(); it != priorityItems.end(); it++)
	{
		int tempscore = 0;
		char value = *it;

		if (value >= 'a' && value <= 'z')
			tempscore = value - 96;
		
		if (value >= 'A' && value <= 'Z')
			tempscore = value - 38;
		totalScore += tempscore;
	}


	std::cout << "Totalscore: " << totalScore << std::endl;
	fclose(fp);

	return 0;
}
