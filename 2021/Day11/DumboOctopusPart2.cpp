#include <iostream>
#include <string.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define STEPS 1000

int map[MAP_HEIGHT][MAP_WIDTH];
int tempMap[MAP_HEIGHT][MAP_WIDTH];

static bool isEntireMapZero()
{
	for(uint8_t y = 0 ; y < MAP_HEIGHT; y++)
		for(uint8_t x= 0 ; x < MAP_WIDTH; x++)
			if (map[y][x] != 0)
				return (false);
	return (true);
}

static void setSurround(uint8_t x, uint8_t y)
{
	if (y > 0)
	{
		if (x < MAP_WIDTH - 1)
			map[y - 1][x + 1]++;
		if (x > 0)
			map[y - 1][x - 1]++;
		map[y - 1][x]++;
	}
	if (x < MAP_WIDTH - 1)
		map[y][x + 1]++;
	if (x > 0)
		map[y][x - 1]++;
	if (y < MAP_HEIGHT - 1)
	{
		if (x < MAP_WIDTH - 1)
			map[y + 1][x + 1]++;
		if (x > 0)
			map[y + 1][x - 1]++;
		map[y + 1][x]++;
	}
	tempMap[y][x] = 1;
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: DumboOctopusPart2 <octopus_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	char line[256];
	uint8_t height = 0;
	while (fscanf(fp, "%s", line) != EOF)
	{
		for(uint8_t i = 0; i < strlen(line); i++)
		{
			map[height][i] = line[i] - '0';
		}
		height++;
	}
	fclose(fp);
	uint64_t flashes = 0;
	for (int i = 0 ; i < STEPS; i++)
	{
		bool hasFlashed = true;
		for (uint8_t y = 0 ; y < MAP_HEIGHT; y++)
			for (uint8_t x = 0 ; x < MAP_WIDTH; x++)
			{
				map[y][x]++;
				tempMap[y][x] = 0;
			}

		while (hasFlashed == true)
		{
			hasFlashed = false;
			for (uint8_t y = 0 ; y < MAP_HEIGHT; y++)
				for (uint8_t x = 0 ; x < MAP_WIDTH; x++)
					if (map[y][x] > 9 && tempMap[y][x] == 0)
					{
						setSurround(x, y);
						hasFlashed = true;
					}
		}
		for (uint8_t y = 0 ; y < MAP_HEIGHT; y++)
			for (uint8_t x = 0 ; x < MAP_WIDTH; x++)
				if (map[y][x] > 9)
				{
					map[y][x] = 0;
					flashes++;
				}

		if (isEntireMapZero() == true)
		{
			std::cout << "step: " << i + 1 << std::endl;
			break;
		}
	}
	return 0;
}
