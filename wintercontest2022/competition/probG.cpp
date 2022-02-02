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
#include <algorithm>

#define ll long long
#define ull unsigned long long

using namespace std;

int main (void)
{
    int n = 0;

    cin >> n;

    vector<int> scores(n, 1);
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        scores[tmp-1] *= i;
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        scores[tmp-1] *= i;
    }

    auto min = min_element(scores.begin(), scores.end());
    if(*min == scores[0])
    {
        for (int i = 1; i < n; i++)
        {
            cout << i << " ";
        }
            cout << n << endl;
    }
    else
    {
        if(*min * n < scores[0])
        {
            cout << "impossible" << endl;
        }
        else
        {

            vector<int> tmp = scores;
            tmp.erase(tmp.begin());
            sort(tmp.begin(), tmp.end(), greater<int>());

            cout << "scores tmp: ";
            for(auto i : tmp)
            {
                cout << i << " ";
            }
            cout << endl;

            cout << "1";
            for (int i = 0; i < tmp.size(); i++)
            {
                int index = distance(scores.begin(), find(scores.begin(), scores.end(), tmp[i]));
                cout << " "<< index+1;
                scores[index] = -1;
            }

            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
