/* Aida Colovic
 *
 * Kattis Problem   : Marko
 * Problem ID       : marko
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.9
 *
 */

#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> letters = {
        2, 2, 2, 3, 3, 3,
        4, 4, 4, 5, 5, 5, 6, 6, 6,
        7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9
    };

    int n = 0;
    std::cin >> n;

    int counter = 0;
    std::vector<std::string> dct;
    for (int i = 0; i < n; i++)
    {
        std::string word;
        std::cin >> word;
        dct.push_back(word);
    }

    std::string pattern;
    std::cin >> pattern;

    for (int i = 0; i < n; i++)
    {
        if(dct[i].length() != pattern.length()) continue;

        std::string word = dct[i];
        int valid = 1;
        for (int j = 0; j < pattern.length(); j++)
        {
            if (letters[word[j] - 'a'] != pattern[j] - '0')
            {
                valid = 0;
                break;
            }
        }
        if (valid) counter++;
    }

    std::cout << counter << std::endl;

    return 0;
}
