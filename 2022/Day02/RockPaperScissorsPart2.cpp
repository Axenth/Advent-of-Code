#include <iostream>

enum roundResult {WIN, LOSE, DRAW, ERROR};

int getScore(char opp, roundResult roundRes)
{
	switch (opp)
	{
		case 'A':
			switch (roundRes)
			{
				case WIN:
					return (2);
				case LOSE:
					return (3);
				case DRAW:
					return (1);
			}
		case 'B':
			switch (roundRes)
			{
				case WIN:
					return (3);
				case LOSE:
					return (1);
				case DRAW:
					return (2);
			}
		case 'C':
			switch (roundRes)
			{
				case WIN:
					return (1);
				case LOSE:
					return (2);
				case DRAW:
					return (3);
			}
	}
	return (0);
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
		roundResult roundRes =  ((yourPick == 'X') ? LOSE : (yourPick == 'Y') ? DRAW : WIN);
		int roundScore = getScore(opponentPick, roundRes);
		switch (roundRes)
		{
			case WIN:
				tempScore += 6;
				break;
			case DRAW:
				tempScore += 3;
				break;
		}
		tempScore += roundScore;
		totalScore += tempScore;
	}

	std::cout << "Totalscore: " << totalScore << std::endl;
	fclose(fp);

	return 0;
}
