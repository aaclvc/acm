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

#define ll long long
#define ull unsigned long long

int main (void)
{
    std::string input;
    std::cin >> input;

    int start = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if(input[i] == '1')
        {
            start = i;
            break;
        }
    }

    int end = 0;
    for (int i = input.size()-1; i >= 0; i--)
    {
        if(input[i] == '1')
        {
            end = i + 1;
            break;
        }
    }

    int diff = end - start;
    int factor = 32;
    int count = 1;

    while (1)
    {
        if(diff > factor)
        {
            factor *= 2;
            count++;
        }
        else if(diff <= factor) break;
    }
    for (int i = 1; i < count; i++)
    {
        std::cout << "long ";
    }
    std::cout << "long" << std::endl;
    return 0;
}
