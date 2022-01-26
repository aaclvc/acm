/* Aida Colovic
 * 
 * Kattis Problem   : Planting Trees
 * Problem ID       : plantingtrees
 * CPU Time limit   : 3 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.0
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int seedlings = 0;
    std::vector<int> vec;

    std::cin >> seedlings;
    for (int i = 0; i < seedlings; i++)
    {
        int tmp = 0;
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int i = 0; i < seedlings; i++)
    {
        vec[i] += i + 2;
    }

    std::sort(vec.begin(), vec.end(), std::greater<int>());

    std::cout << vec.front() << std::endl;

    return 0;
}