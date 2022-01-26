/* Aida Colovic
 *
 * Kattis Problem   : Divisible Subsequences
 * Problem ID       : divisible
 * CPU Time limit   : 3 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 4.1
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

int main(void)
{
    int cases = 0;
    std::cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        int d = 0;
        int n = 0;

        std::cin >> d >> n;
        std::vector<int> arr = {0};
        std::vector<int> counts = {0};
        for(int j = 0; j < n; j++)
        {
            int tmp = 0;
            std::cin >> tmp;
            arr.push_back(tmp);
            counts.push_back((counts.back() + tmp) % d);
        }

        int result = 0;
        std::unordered_map<int, int> reminders;
        reminders[0] = 1;
        for (int x = 1; x <= n; x++)
        {
            result += reminders[counts[x]%d];
            reminders[counts[x]%d]++;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
