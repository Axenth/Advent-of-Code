#include <iostream>
#include <vector>

#define SIMULATION_TIME 256

class lanternFish
{
	public:
		lanternFish() { timer = 8; isNew = true;}
		lanternFish(int timer) { this->timer = timer; }
		~lanternFish() { }
		int getTimer() { return (timer); }
		void decrementTimer(){ if (isNew == true) {isNew = false; return;} timer--; }
		void resetTimer() {timer = 6;}

	private:
		int timer;
		bool isNew = false;
};


int main(int argc, char **argv)
{
	std::vector<lanternFish*> vec;
	if (argc < 2)
	{
		std::cout << "Usage: Lanternfish <lantern_file>" << std::endl;
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
	{
		vec.push_back(new lanternFish(timer));
	}
	for (int i = 0 ; i < SIMULATION_TIME; i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			vec[j]->decrementTimer();
			if (vec[j]->getTimer() == -1)
			{
				vec[j]->resetTimer();
				vec.push_back(new lanternFish());
			}
		}
	}

	std::cout << "Size after " << SIMULATION_TIME << " days: " << vec.size() << std::endl;

	fclose(fp);
	return 0;
}
