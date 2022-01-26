/* ICPC - NWERC 2021
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

#define ll long long
#define ull unsigned long long


using namespace std;

void allVisted(map<double, int> &m)
{
    bool yes = true;
    for(auto i : m)
    {
        if(i.second == 0)
        {
            cout << "no " << fixed << setprecision(1) << i.first << endl;
            yes = false;
            break;
        }
    }
    if(yes)
    {
        cout << "yes" << endl;
    }
}

void setVisited2(map<double, int> &map, int k, int g)
{
    double d = -180.0;
    while(d <= k)
    {
        map[d] = 1;
        d += 0.5;
    }

    d = 180.0;
    while(d >= g)
    {
        map[d] = 1;
        d -= 0.5;
    }
}

void setVisited(map<double, int> &map, int k, int g)
{
    double d = k;
    double end = g;
    while(d <= end)
    {
        map[d] = 1;
        d += 0.5;
    }
}

int main(void)
{
    int n = 0;
    cin >> n;
    vector<int> lg;
    map<double, int> map;

    for(int i = 0; i < n; i++)
    {
        int lat, lon;
        cin >> lat >> lon;
        lg.push_back(lon);
    }

    lg.push_back(lg[0]); // add last for round trip
    //inti map
    double d = -180.0;
    while (d < 180.0)
    {
        map[d] = 0;
        d += 0.5;
    }


    for (int i = 0; i < lg.size()-1; i++)
    {
        int x = lg[i];
        int y = lg[i+1];

        int k = 0;
        int g = 0;

        int diff = 0;

        if(x > y)
        {
            diff = x - y;
            g = x;
            k = y;
        }
        else
        {
            diff = y - x;
            g = y;
            k = x;
        }

        if(diff < 180)
        {
            setVisited(map, k, g);
        }
        else if(diff > 180)
        {
            setVisited2(map, k, g);
        }
        else if(diff == 180)
        {
            // if(map[k-1] == 0)
            // {
            //     setVisited2(map, k, g);
            // }
            // else
            // {
            //     setVisited(map, k, g);
            // }
            cout << "yes" << endl;
            return 0;
        }
    }

    // for(auto i : map)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    allVisted(map);

    return 0;
}
