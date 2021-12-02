#include <iostream>

int main(int argc, char **argv)
{
	int horizontal  = 0;
	int depth = 0;
	if (argc < 2)
	{
		std::cout << "Usage: Dive <dive_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	char cmd[256];
	int amount;
	while (fscanf(fp, "%s %d", cmd, &amount) != EOF)
	{
		std::string command(cmd);
		if (command == "forward")
			horizontal += amount;
		else if (command == "up")
			depth -= amount;
		else if (command == "down")
			depth += amount;
	}
	fclose(fp);
	std::cout << "Final: " << horizontal * depth << std::endl;
	return 0;
}
