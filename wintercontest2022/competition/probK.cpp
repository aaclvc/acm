/* Winter Contest 2022
 *
 * Team: FRAmework
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <string>
#include <climits>

#define ll long long
#define ull unsigned long long

int main (void)
{
    int n = 0, volume = 0;
    std::cin >> n >> volume;

    double minV = MAXFLOAT;
    int res  = 0;
    int tooSmall = 0;

    for (int i = 0; i < n; i++)
    {
        int h = 0, r = 0;
        std::cin >> h >> r;

        double tmpV = M_PI * r * r * h;

        if(tmpV < volume)
        {
            tooSmall++;
        }
        else
        {
            if(minV >= tmpV)
            {
                minV = tmpV;
                res = i+1;
            }
        }
    }

    if(tooSmall == n)
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << res << std::endl;
    }

    return 0;
}
