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
#include <ctime>
#include <cstdlib>

#define ll long long
#define ull unsigned long long
using namespace std;

int main (void)
{
    map<int, bool> m;

    for (int i = 1; i <= 100; i++)
    {
        m.insert({i, true});
    }

    int y;
    y = 1;

    string ans;
    while (1)
    {
        cout << y << endl;
        m[y] = false;
        cout.flush();

        cin >> ans;

        if(ans == "equal") break;
        else if( ans == "factor")
        {
            for (int i = 2; i <= 100; i++)
            {
                if(m[i] == true)
                {
                    y *= i;
                    break;
                }
            }
        }
        else if(ans == "multiple")
        {
            for (int i = 2; i <= y; i++)
            {
                if((m[i] == true) && (y % i == 0))
                {
                    y /= i;
                    break;
                }
            }
        }
        else if(ans == "other")
        {
            while(1)
            {
                y = rand() % 100 + 1;
                if (m[y] == true) break;
            }
        }
    }

    return 0;
}
