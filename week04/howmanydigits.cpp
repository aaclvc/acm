/* Aida Colovic
 * 
 * Kattis Problem   : How Many Digits?
 * Problem ID       : howmanydigits
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.9
 * 
 */

#include <iostream>
#include <cmath>


int main(void)
{
    while (1)
    {
        int n = 0;
        std::cin >> n;

        if (std::cin.eof())
        {
            break;
        }
        else
        {
            if (n < 2)
            {
                std::cout << 1 << std::endl;
            }
            else
            {
                int ans = 0;
                ans = std::ceil(log10(2*M_PI*n) / 2+n*log10(n/M_E));
                std::cout << ans << std::endl;
            }
        }
    }
    return 0;
}