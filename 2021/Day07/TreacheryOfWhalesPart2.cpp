#include <iostream>
#include <vector>
#include <cmath>

#define INPUTS 1000

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: TreacheryOfWhales <whales_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	int highestInput = INT32_MIN;
	int crabPositions[INPUTS];
	int i = 0;
	while (fscanf(fp, "%d", &crabPositions[i++]) != EOF)
		if (crabPositions[i - 1] > highestInput)
			highestInput = crabPositions[i - 1];

	uint64_t lowestFuel = UINT64_MAX;
	int lowestMoves = 0;
	for (int i = 0; i < 1500; i++)
	{
		int fuelSum = 0;
		for (int j = 0; j < INPUTS; j++)
		{
			int FuelCost = 0;
			int moveTo = abs(crabPositions[j] - i);

			for (int k = 0; k < moveTo; k++)
				FuelCost += 1 * (k + 1);
			fuelSum += FuelCost;
		}
		if (fuelSum < lowestFuel)
		{
			lowestFuel = fuelSum;
			lowestMoves = i;
		}
	}

	std::cout << "Lowest moves: " << lowestMoves << std::endl;
	std::cout << "Lowest fuel consumption: " << lowestFuel << std::endl;
}
