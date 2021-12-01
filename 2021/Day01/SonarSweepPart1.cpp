#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: SonarSweepPart1 <sonar_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	int num_lines = 0;
	int num_read = 0;
	int *sonar_data = NULL;
	while (fscanf(fp, "%d", &num_read) != EOF)
		num_lines++;
	fclose(fp);
	sonar_data = new int[num_lines];
	fp = fopen(argv[1], "r");
	for (int i = 0; i < num_lines; i++)
		fscanf(fp, "%d", &sonar_data[i]);
	fclose(fp);
	int result = 0;
	for(int i = 0; i < num_lines - 1; i++)
	{
		int j = i + 1;
		if (sonar_data[j] > sonar_data[i])
			result++;
	}
	std::cout << "Number of times the sonar data went up: " << result << std::endl;
	delete[] sonar_data;
	return 0;
}
