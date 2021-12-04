#include <iostream>
#include <sstream>
#define NUMBER_SIZE 100
#define BOARDS_SIZE 100

typedef struct s_board
{
	int board[5][5];
	int drawnBoard[5][5];
	bool done = false;
}	t_board;

static void printBoard(t_board *board, bool drawnBoard)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (drawnBoard)
				std::cout << board->drawnBoard[i][j] << " ";
			else
				std::cout << board->board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

static bool checkBingo(t_board *board)
{
	for (int i = 0; i < 5; i++)
	{
		int horizontal = 0;
		for (int j = 0; j < 5; j++)
		{
			if (board->drawnBoard[i][j] == 1)
				horizontal++;
		}
		if (horizontal == 5)
			return true;
	}

	for (int j = 0 ; j < 5; j++)
	{
		int vertical = 0;
		for (int i = 0; i < 5; i++)
		{
			if (board->drawnBoard[i][j] == 1)
				vertical++;
		}
		if (vertical == 5)
			return true;
	}
	return (false);
}

int main(int argc, char **argv)
{
	int drawnNumbers[NUMBER_SIZE];
	t_board boards[BOARDS_SIZE];
	if (argc < 2)
	{
		std::cout << "Usage: GiantSquidPart2 <squid_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	char buff[512];

	fscanf(fp, "%s", buff);
	std::string buffer(buff);
	std::stringstream numbers(buffer);
	std::string number;
	int i = 0;
	while(getline(numbers, number, ','))
	{
		drawnNumbers[i] = atoi(number.c_str());
		i++;
	}
	int ret = 0;
	int boardCount = 0;
	i = 0;
	while ((ret = fscanf(fp, "%d %d %d %d %d", &boards[boardCount].board[i][0], &boards[boardCount].board[i][1], &boards[boardCount].board[i][2], &boards[boardCount].board[i][3], &boards[boardCount].board[i][4])) != EOF)
	{
		if (ret == 0)
			continue;
		i++;
		if (i == 5)
		{
			boardCount++;
			i = 0;
		}		
	}
	fclose(fp);
	for (int i = 0; i < boardCount; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				boards[i].drawnBoard[j][k] = 0;

	t_board *finalBoard = NULL;

	int num;
	int lastnum;
	for (num = 0; num < NUMBER_SIZE; num++)
	{
		for (int board = 0; board < BOARDS_SIZE; board++)
		{
			if (boards[board].done)
				continue;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (boards[board].board[i][j] == drawnNumbers[num])
					{
						boards[board].drawnBoard[i][j] = 1;
					}
				}
			}
			if (checkBingo(&boards[board]) && boards[board].done == false)
			{
				boards[board].done = true;
				lastnum = drawnNumbers[num];
				finalBoard = &boards[board];
			}
		}
	}
	int sum = 0;
	for (int k = 0; k < 5; k++)
		for (int l = 0; l < 5; l++)
			if (finalBoard->drawnBoard[k][l] == 0)
				sum += finalBoard->board[k][l];

	std::cout << "lastnum: " << lastnum << std::endl;
	std::cout << "sum: " << sum <<  std::endl;
	std::cout << "result: " << sum * lastnum << std::endl;
	return 0;
}
