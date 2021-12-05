#include <iostream>

#define BOARD_SIZE 1000

int main(int argc, char **argv)
{
	int board[BOARD_SIZE][BOARD_SIZE];
	for (int i = 0 ; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			board[i][j] = 0;
	if (argc < 2)
	{
		std::cout << "Usage: HydrothermalVenture <input_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	char cmd[256];
	int x1, y1, x2, y2;
	while (fscanf(fp, "%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF)
	{
		std::string command(cmd);
		if (x1 == x2)
		{
			for (int y = 0; y <= BOARD_SIZE; y++)
			{
				if ((y >= y1 && y <= y2) || (y >= y2 && y <= y1))
					board[y][x1]++;
			}
		}
		else if (y1 == y2)
		{
			for (int x = 0; x <= BOARD_SIZE; x++)
			{
				if ((x >= x1 && x <= x2) || (x >= x2 && x <= x1))
					board[y1][x]++;
			}
		}
	}
	int overlaps = 0;
	for(int i = 0; i < BOARD_SIZE; i++)
		for(int j = 0; j < BOARD_SIZE; j++)
			if (board[i][j] > 1)
				overlaps++;

	std::cout << "Overlaps: " << overlaps << std::endl;

	fclose(fp);
	return 0;
}
