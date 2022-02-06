/* Aida Colovic
 *
 * Kattis Problem   : Radio Commercials
 * Problem ID       : commercials
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      :
 *
 */

#include <iostream>

int main (void)
{
    int n = 0, p = 0;
    int max = 0, maxLocal = 0;

    std::cin >> n >> p;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;

        temp -= p;

        /*
        * Kadane's Algorithm
        * https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
        */
        if (temp > (temp + max))
        {
            max = temp;
        }
        else
        {
            max = temp + max;
        }

        if (max > maxLocal)
        {
            maxLocal = max;
        }
    }

    std::cout << maxLocal << std::endl;
    return 0;
}
