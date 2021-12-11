#include <iostream>
#include <iomanip>
#include <deque>
#include <vector>

static bool isOpening(char c)
{
    if (c == '(' || c == '{' || c == '[' || c == '<')
        return true;
}

int main(int argc, char **argv)
{
    std::vector<std::string> input;

    if (argc < 2)
	{
		std::cout << "Usage: SyntaxScoringPart1 <syntax_file>" << std::endl;
		return 1;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		std::cout << "Error: could not open file " << argv[1] << std::endl;
		return 1;
	}
    char line[256];
	while (fscanf(fp, "%s", line) != EOF)
        input.push_back(std::string(line));


    uint64_t score = 0;
    for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++)
    {
        std::string temp = *it;
        std::vector<char> stack;
        int i = 0;

        for (int i = 0 ; i < temp.size(); i++)
        {
            char endChar = ' ';
            if (isOpening(temp[i]) == true)
                stack.push_back(temp[i]);
            else
            {
                if (i > 0)
                   endChar = *(stack.end()-1);
                if (temp[i] == ')')
                {
                    if (endChar == '(')
                        stack.pop_back();
                    else
                    {
                        score += 3;
                        std::cout << "Error: " << temp << " is not a valid syntax" << std::endl;
                        break;
                    }
                }
                else if (temp[i] == '}')
                {
                    if (endChar == '{')
                        stack.pop_back();
                     else
                    {
                        score += 1197;
                        std::cout << "Error: " << temp << " is not a valid syntax" << std::endl;
                        break;
                    }
                }
                else if (temp[i] == ']')
                {
                    if (endChar == '[')
                        stack.pop_back();
                     else
                    {
                        score += 57;
                        std::cout << "Error: " << temp << " is not a valid syntax" << std::endl;
                        break;
                    }
                }
                else if (temp[i] == '>')
                {
                    if (endChar == '<')
                        stack.pop_back();
                     else
                    {
                        score += 25137;
                        std::cout << "Error: " << temp << " is not a valid syntax" << std::endl;
                        break;
                    }
                }
                else
                {
                    std::cout << temp;
                    std::cout << " Error: invalid syntax" << std::endl;
                }
            }
        }
    }
    std::cout << "result: " << score << std::endl;
	fclose(fp);
	return 0;
}