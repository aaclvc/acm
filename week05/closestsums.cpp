/* Aida Colovic
 *
 * Kattis Problem   : Closest Sums
 * Problem ID       : closestsums
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      :
 *
 */


#include <iostream>
#include <cmath>
#include <vector>

int main (void)
{
    int n = 0;
    int count = 1;

    while (std::cin >> n)
    {
        std::cout << "Case " << count << ":" << std::endl;
        count++;

        std::vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            std::cin >> tmp;
            v.push_back(tmp);
        }

        int m = 0;
        std::cin >> m;

        for (int i = 0; i < m; i++)
        {
            int aim = 0;
            std::cin >> aim;
            int closest = v[0] + v[1];

            for (int j = 0; j < n; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    int sum = v[j] + v[k];
                    if(std::abs(sum - aim) < std::abs(closest - aim))
                    {
                        closest = sum;
                    }
                }
            }
            std::cout << "Closest sum to " << aim << " is " << closest << "." << std::endl;
        }
    }

    return 0;
}
