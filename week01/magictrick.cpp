/* Aida Colovic
 *
 * Kattis Problem   : Magic Trick
 * Problem ID       : magictrick
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 *
 */

#include <iostream>
#include <unordered_set>

int main(void)
{
    std::unordered_set<char> letters;
    std::string input = "";
    std::cin >> input;
    int result = 1;

    for (char c : input)
    {
        letters.insert(c);
    }
    if (letters.size() != input.length())
    {
        result = 0;
    }
    std::cout << result << std::endl;
    return 0;
}
