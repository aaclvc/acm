/* Aida Colovic
 * 
 * Kattis Problem   : Jumbo Javelin
 * Problem ID       : jumbojavelin
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <iostream>
int main(void)
{
    int n = 0;
    int result = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        std::cin >> temp;
        result += temp;
    }

    std::cout << result - (n - 1) << std::endl;
    return 0;
}