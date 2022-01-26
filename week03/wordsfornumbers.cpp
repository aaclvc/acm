/* Aida Colovic
 *
 * Kattis Problem   : Words for Numbers
 * Problem ID       : wordsfornumbers
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.0
 *
 */

#include <iostream>
#include <map>
#include <sstream>

std::string convertNumber(int n)
{
    std::map<int, std::string> unique = {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
    };

    std::map<int, std::string> tens{
        {2, "twenty"},
        {3, "thirty"},
        {4, "forty"},
        {5, "fifty"},
        {6, "sixty"},
        {7, "seventy"},
        {8, "eighty"},
        {9, "ninety"},
    };

    std::string converted;
    if (n < 20)
    {
        converted = unique[n];
    }
    else
    {
        int one = n % 10;
        int ten = n / 10;
        if (one != 0)
        {
            converted = tens[ten] + "-" + unique[one];
        }
        else
        {
            converted = tens[ten];
        }
    }
    return converted;
}
bool isNumber(std::string &str)
{
    for (char const &c : str)
    {
        if (std::isdigit(c) == 0)
            return false;
    }
    return true;
}

int main(void)
{
    while (1)
    {
        std::string input;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            break;
        }
        else
        {
            std::istringstream stream(input);
            std::string checkString;
            int word = 0;
            while (stream >> checkString)
            {
                if (isNumber(checkString))
                {
                    if (word == 0)
                    {
                        std::string begin = convertNumber(std::stoi(checkString));
                        begin[0] -= 32;
                        std::cout << begin << " ";
                    }
                    else
                    {
                        std::cout << convertNumber(std::stoi(checkString)) << " ";
                    }
                }
                else
                {
                    std::cout << checkString << " ";
                }
                word++;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}