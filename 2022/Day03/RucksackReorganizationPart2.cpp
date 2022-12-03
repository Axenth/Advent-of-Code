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

	for (std::vector<std::string>::iterator it = inputs.begin(); it != inputs.end(); )
	{
		std::string tempString1 = *it;
		std::string tempString2 = *(it+1);
		std::string tempString3 = *(it+2);
		

		for (int i = 0 ; i < tempString1.length(); i++)
		{
			bool setBreak = false;
			for (int j = 0 ; j < tempString2.length(); j++)
			{
				if (tempString1[i] == tempString2[j])
				{
					for (int k = 0 ; k < tempString3.length(); k++)
					{
						if (tempString3[k] == tempString2[j])
						{
							priorityItems.push_back(tempString1[i]);
							setBreak = true;
							break;
						}
					}
					if (setBreak == true)
						break;
				}
			}
			if (setBreak == true)
				break;
		}
		it += 3;
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
