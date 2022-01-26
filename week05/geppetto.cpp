/* Aida Colovic
 *
 * Kattis Problem   : Geppetto
 * Problem ID       : geppetto
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      :
 *
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <set>

int main (void)
{
    int n = 0;
    int m = 0;

    std::cin >> n >> m;
    std::set<int> pairs;

    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        std::cin >> a >> b;

        a--, b--;
        pairs.insert(((1 << a) + (1 << b)));
    }

    int total = 1 << n;
    for (int i = 0; i < (1 << n); i++)
    {
        for (auto pair : pairs)
        {
            if((i & pair) == pair)
            {
                total--;
                break;
            }
        }

    }
    std::cout << total << std::endl;

    return 0;
}
