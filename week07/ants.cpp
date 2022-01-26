/* Aida Colovic
 *
 * Kattis Problem   : Ants
 * Problem ID       : ants
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.4
 *
 */

#include <iostream>
#include <vector>
#include <climits>

int main (void)
{
    int cases = 0;
    std::cin >> cases;
    while (cases--)
    {
        int l = 0, n = 0;
        std::cin >> l >> n;

        std::vector<int> posAnts(n, 0);
        for (int i = 0; i < n; i++)
        {
            std::cin >> posAnts[i];
        }

        int earliest = INT_MAX;             // l - best case for latest
        int latest   = 0;                   // worst case for fastest

        int mid = l/2;
        for (int pos : posAnts)
        {
            if(pos <= mid)                  // go left
            {
                if(pos < earliest)
                {
                    earliest = pos;
                }

                if(pos > latest)
                {
                    latest = pos;
                }
            }
            else if(pos > mid)              // go right
            {
                int newPos = l - pos;

                if(newPos < earliest)
                {
                    earliest = newPos;
                }

                if(newPos > latest)
                {
                    latest = newPos;
                }
            }
        }

        std::cout << latest << " " << l-earliest << std::endl;

    }

    return 0;
}
