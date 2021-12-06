#include <iostream>
#include <vector>
#include <numeric>
#include <array>

#define SIMULATION_TIME 256

int main(int argc, char **argv)
{
	std::array<unsigned long long int, 9> arr = {0};
	if (argc < 2)
	{
		std::cout << "Usage: LanternFish <lantern_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	int timer;
	while (fscanf(fp, "%d", &timer) != EOF)
		arr[timer]++;

	for (int i = 0; i < SIMULATION_TIME; i++) {
		std::array<unsigned long long int, 9> newGen;
		newGen[0] = arr[1];
		newGen[1] = arr[2];
		newGen[2] = arr[3];
		newGen[3] = arr[4];
		newGen[4] = arr[5];
		newGen[5] = arr[6];
		newGen[6] = arr[0] + arr[7];
		newGen[7] = arr[8];
		newGen[8] = arr[0];

		std::swap(arr, newGen);
	}
	std::cout << std::accumulate(arr.begin(), arr.end(), 0ULL) << std::endl;
}
