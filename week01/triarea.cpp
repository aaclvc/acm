/* Aida Colovic
 * 
 * Kattis Problem   : Triangle Area
 * Problem ID       : triarea
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <iostream>

int main(void)
{
    int h = 0;
    int b = 0;

    std::cin >> h >> b;
    std::cout << h * b / 2.0 << std::endl;
    return 0;
}