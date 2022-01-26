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
#include <string>

#define ll long long
#define ull unsigned long long


using namespace std;

int main(void)
{
    int time = 0;
    string p = "A";

    while (1)
    {
        cout << p << endl;
        cout.flush();

        string ans;
        getline(cin, ans);

        if(ans != "ACCESS GRANTED")
        {
            string tmp = ans.substr(15);
            time = stoi(tmp);
            if(time == 5)
            {
                p += 'A';
            }
            else
            {
                time -= 4;
                int rightChars = (time / 9) - 1;

                if(p[rightChars] == 'Z')
                {
                    p[rightChars] += 7;
                }
                else if(p[rightChars] == 'z')
                {
                    p[rightChars] = '0';
                }
                else
                {
                    p[rightChars] += 1;
                }
            }
        }
        else
        {
            break;
        }

    }
    return 0;
}
