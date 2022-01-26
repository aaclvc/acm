/* Aida Colovic
 *
 * Kattis Problem   : Quick Brown Fox
 * Problem ID       : quickbrownfox
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.2
 */

#include <iostream>
#include <set>

int main(void)
{
    int cases = 0;
    std::cin >> cases;
    std::cin.ignore();
    for (int i = 0; i < cases; i++)
    {
        std::set<char> letters {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        };
        std::string input;
        std::getline(std::cin, input);
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] >= 65 && input[i] <= 90)
            {
                input[i] += 32;
                letters.erase(input[i]);
            }
            else if(input[i] >= 97 && input[i] <= 122)
            {
                letters.erase(input[i]);
            }
        }

        if(letters.size())
        {
            std::cout << "missing ";
            for(auto letter : letters)
            {
                std::cout << letter;
            }
        }
        else
        {
            std::cout << "pangram";
        }
        std::cout << std::endl;
    }

    return 0;
}
