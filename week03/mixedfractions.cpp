/* Aida Colovic
 *
 * Kattis Problem   : Mixed Fractions
 * Problem ID       : mixedfractions
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      :
 */

#include <iostream>

int main(void)
{
    while(1)
    {
        int numerator = -1;
        int denominator = -1;

        std::cin >> numerator >> denominator;

        if((numerator == 0) && (denominator == 0))
        {
            break;
        }

        int whole = numerator / denominator;
        int newNumerator = numerator % denominator;
        std::cout << whole << " " << newNumerator << " / " << denominator << std::endl;
    }
    return 0;
}
