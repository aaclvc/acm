/* Aida Colovic
 * 
 * Kattis Problem   : Fractional Lotion
 * Problem ID       : fractionallotion
 * CPU Time limit   : 2 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.0
 * 
 */

#include <iostream>

int main(void)
{
    char buffer[8];
    while (scanf("%s", buffer) == 1)
    {
        int n = atoi(buffer + 2);

        int counter = 0;
        int bound = (n << 1) + 1;

        for (int x = n + 1; x < bound; x++)
        {
            int y = x * n;
            if (y % (x - n) == 0)
            {
                counter++;
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}