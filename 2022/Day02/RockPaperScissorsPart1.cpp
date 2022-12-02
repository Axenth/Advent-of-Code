#include <iostream>

enum roundResult {WIN, LOSE, DRAW, ERROR};

roundResult isWin(char opp, char you)
{
	switch (opp)
	{
		case 'A':
			switch (you)
			{
				case 'X':
					return (DRAW);
				case 'Y':
					return (WIN);
				case 'Z':
					return (LOSE);
			}
		case 'B':
			switch (you)
			{
				case 'X':
					return (LOSE);
				case 'Y':
					return (DRAW);
				case 'Z':
					return (WIN);
			}
		case 'C':
			switch (you)
			{
				case 'X':
					return (WIN);
				case 'Y':
					return (LOSE);
				case 'Z':
					return (DRAW);
			}
	}
	return (ERROR);
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: RockPaperSciccors <input_file>" << std::endl;
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

	while (getline(&line, &length, fp) != -1)
	{
		int tempScore = 0;
		char opponentPick = line[0];
		char yourPick  = line[2];
		roundResult roundRes = isWin(opponentPick, yourPick);
		std::cout << ((roundRes == WIN) ? "win" : (roundRes == DRAW) ? "draw" : (roundRes == LOSE) ? "lose" : "ERROR") << std::endl;
		switch (roundRes)
		{
			case WIN:
				tempScore += 6;
				break;
			case DRAW:
				tempScore += 3;
				break;
		}

		switch(yourPick)
		{
			case 'X':
				tempScore += 1;
				break;
			case 'Y':
				tempScore += 2;
				break;
			case 'Z':
				tempScore += 3;
				break;
		}
		totalScore += tempScore;
	}

	std::cout << "Totalscore: " << totalScore << std::endl;
	fclose(fp);

	return 0;
}
