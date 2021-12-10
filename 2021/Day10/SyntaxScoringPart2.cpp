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
        bool erased = false;

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
                    else if (erased == false)
                    {
                        *it = "invalid";
                        erased = true;
                    }
                }
                else if (temp[i] == '}')
                {
                    if (endChar == '{')
                        stack.pop_back();
                    else if (erased == false)
                    {
                        *it = "invalid";
                        erased = true;
                    }
                }
                else if (temp[i] == ']')
                {
                    if (endChar == '[')
                        stack.pop_back();
                    else if (erased == false)
                    {
                        *it = "invalid";
                        erased = true;
                    }
                }
                else if (temp[i] == '>')
                {
                    if (endChar == '<')
                        stack.pop_back();
                    else if (erased == false)
                    {
                        *it = "invalid";
                        erased = true;
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

std::vector<uint64_t> scores;
 for (std::vector<std::string>::iterator it = input.begin(); it != input.end(); it++)
 {
    std::string temp = *it;
    std::vector<char> stack;
    int i = 0;
    if (temp == "invalid")
        continue;
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
                    break;
            }
            else if (temp[i] == '}')
            {
                if (endChar == '{')
                    stack.pop_back();
                else
                    break;
            }
            else if (temp[i] == ']')
            {
                if (endChar == '[')
                    stack.pop_back();
                else
                    break;
            }
            else if (temp[i] == '>')
            {
                if (endChar == '<')
                    stack.pop_back();
                else
                    break;
            }
            else
            {
                std::cout << temp;
                std::cout << " Error: invalid syntax" << std::endl;
            }
        }
    }
    score = 0;
    for (std::vector<char>::reverse_iterator rit = stack.rbegin(); rit != stack.rend(); rit++)
    {
        char c = *rit;
        score *= 5;
        if (c == '(')
            score += 1;
        else if (c == '{')
            score += 3;
        else if (c == '[')
            score += 2;
        else if (c == '<')
            score += 4;
    }
    scores.push_back(score);
 }
    std::sort(scores.begin(), scores.end());
    std::cout << "result: " <<   scores[scores.size()/2] << std::endl;
	fclose(fp);
	return 0;
}