#include <iostream>
#include <vector>



int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: CampCleanup <input_file>" << std::endl;
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

	while (getline(&line, &length, fp) != -1)
	{
		inputs.push_back(std::string(line));
	}

	for (std::vector<std::string>::iterator it = inputs.begin(); it != inputs.end(); it++)
	{
		std::string tempString = *it;
		std::string string1 = tempString.substr(0, tempString.find(","));
		std::string string2 = tempString.substr(tempString.find(",") + 1);


		int range1Start = std::atoi(string1.c_str()); 
		int range1End = std::atoi(string1.substr(string1.find("-") + 1).c_str());

		int range2Start = std::atoi(string2.c_str()); 
		int range2End = std::atoi(string2.substr(string2.find("-") + 1).c_str());

		std::cout << range2Start << "-" << range2End << " " << range1Start << "-" << range1End << std::endl;
		if (((range2Start >= range1Start && range2Start <= range1End)  && (range2End >= range1Start && range2End <= range1End)) ||
		((range1Start >= range2Start && range1Start <= range2End)  && (range1End >= range2Start && range1End <= range2End)))
		{
		
			totalScore++;
		}
	}

	std::cout << "Totalscore: " << totalScore << std::endl;
	fclose(fp);

	return 0;
}
