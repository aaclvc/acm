/* Aida Colovic
 * 
 * Kattis Problem   : Santa Klas
 * Problem ID       : santaklas
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.5
 * 
 */

#include <iostream>
#include <cmath>

int main(void)
{
    int h = 0;
    int v = 0;
    std::cin >> h >> v;

    if (v <= 180)
    {
        std::cout << "safe";
    }
    else
    {
        std::cout << ((int)(h / cos(M_PI * v / 180.0 + M_PI_2)));
    }
    std::cout << std::endl;
}