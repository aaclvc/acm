/* Aida Colovic
 *
 * Kattis Problem   : Exact Change
 * Problem ID       : exactchange2
 * CPU Time limit   : 2 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 6.4
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000

int main(void)
{
    int cases = 0;
    std::cin >> cases;
    while (cases--)
    {
        int amount = 0, n = 0;
        std::cin >> amount >> n;

        std::vector<int> bills(n, 0);
        for (int i = 0; i < n; i++)
        {
            std::cin >> bills[i];
        }

        std::vector<int> dp(MAX+1, 10000);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = MAX; j >= 0; j--)
            {
                if((j - bills[i] >= 0) && (dp[j - bills[i]] + 1 < dp[j]))
                    dp[j] = dp[j - bills[i]] + 1;
            }
        }

        int i;
        for(i = amount; dp[i] == MAX; i++);

        std::cout << i << " " << dp[i] << std::endl;
    }

    return 0;
}
