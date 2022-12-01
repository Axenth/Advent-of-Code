#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: CalorieCounting <input_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}

	std::vector<int> results;

	int num_lines = 0;
	int num_read = 0;
	while (fscanf(fp, "%d", &num_read) != EOF)
		num_lines++;
	fclose(fp);
	fp = fopen(argv[1], "r");
	int readValue = 0;
	int total = 0;
	char *line;
	size_t length;

	while (getline(&line, &length, fp) != -1)
	{
		readValue = 0;
		readValue = atoi(line);
		if (readValue == 0)
		{
			results.push_back(total);
			total = 0;
			readValue = 0;
		}
		else
		{
			total += readValue;
		}
	}

	std::sort(results.begin(), results.end());
	for (std::vector<int>::iterator it = results.begin(); it != results.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	fclose(fp);

	return 0;
}
