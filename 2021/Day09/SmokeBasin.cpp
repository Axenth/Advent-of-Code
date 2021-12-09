#include <iostream>
#include <iomanip>
#include <queue>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

#define MAP_WIDTH 100
#define MAP_HEIGHT 100

int map[MAP_HEIGHT][MAP_WIDTH];


typedef struct s_point
{
	s_point(int a, int b) {this->y = a; this->x = b;}
	int x;
	int y;
}	point;

void clear(std::stringstream &stream)
{
	if (stream.rdbuf()) stream.rdbuf()->pubseekpos(0);
}

static int FloodFill(int x, int y)
{
	if(map[y][x] == 9 || map[y][x] == 11)
		return (-1);
	std::queue<point> points;
	std::map<std::string, bool> ignore;
	points.push(point(y, x));
	uint64_t size = 0;
	while(points.size() > 0)
	{
		int i = points.front().y;
		int j = points.front().x;
		std::stringstream ss;
		clear(ss);
		ss << i << " " << j;
		if (ignore.count(ss.str()) == 1)
		{
			points.pop();
			continue;
		}
		ignore.insert(std::make_pair(ss.str(), true));
		
		if (i >= MAP_HEIGHT || i < 0 || j < 0 || j >= MAP_WIDTH)
		{
			points.pop();
			continue;
		}
		if (map[i][j] == 9 || map[i][j] == 11)
		{
			points.pop();
			continue;
		}
		map[i][j] = 11;
		size++;
		points.push(point(i - 1, j));
		points.push(point(i + 1, j));
		points.push(point(i, j - 1));
		points.push(point(i, j + 1));

		points.pop();
	}
	ignore.clear();
	return (size);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: SmokeBasin <basin_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
	char line[255];
	int i = 0;
	while (fscanf(fp, "%s", line) != EOF)
	{
		for (int j = 0 ; j < MAP_WIDTH; j++)
			map[i][j] = line[j] - '0';
		i++;
	}
	fclose(fp);

	int sum = 0;
	std::vector<int> basins;
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0 ; j < MAP_WIDTH; j++)
		{
			int ret = FloodFill(j, i);
			if (ret != -1)
				basins.push_back(ret);
		}
	}
	std::sort(basins.begin(), basins.end());
	std::vector<int>::reverse_iterator rit = basins.rbegin();
	int first = *rit;
	rit++;
	int second = *rit;
	rit++;
	int third = *rit;

	std::cout << "1. " << first << std::endl << "2. " << second << std::endl << "3. " << third << std::endl;
	std::cout << "result: " << (first * second * third) << std::endl;
	return 0;
}
