/* Aida Colovic
 *
 * Kattis Problem   : Pig Latin
 * Problem ID       : piglatin
 * CPU Time limit   : 3 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.2
 *
 *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
 *
 * Rules:
 * 1. word begins with Consonant
 *  -> take all letter befor first vowel
 *  -> move them to the end
 *  -> add ay to end
 *
 *
 * 2. word begins with vowel (a, e, i ,o ,u, y)
 *  -> add yay to the end
 *
 * Example with "cant"
 *  -> first rule because of c
 *  -> c-ant -> antc
 * -> antcay
 */

#include <iostream>
#include <sstream>
#include <map>

void checkWord(std::map<char, int> &isVowel, std::string &s)
{
    int locVowel = 0;
    if(isVowel[s[0]])
    {
       s += "yay";
    }
    else
    {
        for(int i = 1; i < s.length(); i++)
        {
            if(isVowel[s[i]])
            {
                locVowel = i;
                break;
            }
        }

        std::string front = s.substr(0, locVowel);
        std::string end = s.substr(locVowel, std::string::npos);
        s = end + front + "ay";
    }
}

int main(void)
{
    std::map<char, int> isVowel {
        {'a', 1},
        {'b', 0},
        {'c', 0},
        {'d', 0},
        {'e', 1},
        {'f', 0},
        {'g', 0},
        {'h', 0},
        {'i', 1},
        {'j', 0},
        {'k', 0},
        {'l', 0},
        {'m', 0},
        {'n', 0},
        {'o', 1},
        {'p', 0},
        {'q', 0},
        {'r', 0},
        {'s', 0},
        {'t', 0},
        {'u', 1},
        {'v', 0},
        {'w', 0},
        {'x', 0},
        {'y', 1},
        {'z', 0},
    };

    while (1)
    {
        std::string input;
        std::getline(std::cin, input);
        if(std::cin.eof())
        {
            break;
        }

        std::istringstream stream(input);
        std::string word;
        int count = 0;
        while (stream >> word)
        {
            if(count == 0)
            {
                checkWord(isVowel, word);
                std::cout << word;
                count++;
            }
            else
            {
                checkWord(isVowel, word);
                std::cout << " " << word;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
