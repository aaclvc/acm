/* Aida Colovic
 * 
 * Kattis Problem   : N-Sum
 * Problem ID       : nsum
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <iostream>

int main(void)
{
    int a = 0;
    int res = 0;
    std::cin >> a;
    for (int i = 0; i < a; i++)
    {
        int temp = 0;
        std::cin >> temp;
        res += temp;
    }
    std::cout << res << std::endl;
    return 0;
}