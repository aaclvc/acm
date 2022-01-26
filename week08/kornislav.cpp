/* Aida Colovic
 * 
 * Kattis Problem   : Kornislav
 * Problem ID       : kornislav
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.4
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> vec;
    for (int i = 0; i < 4; i++)
    {
        int tmp = 0;
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    std::sort(vec.begin(), vec.end());

    std::cout << vec[0]*vec[2] << std::endl;

    return 0;
}