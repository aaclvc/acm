/* Aida Colovic
 *
 * Kattis Problem   : Honeycomb Walk
 * Problem ID       : honey
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.6
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>

std::map<std::pair<int, std::pair<int, int>>, long long> step;
std::vector<long long> walks(15, 0);

long long walk(int x, int y, int n)
{
    if(n == 0)
    {
        if (x == 0 && y == 0) //if on start position and no steps left
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(step.count({n, {y, x}}) != 0)
    {
        return step[{n, {y, x}}];
    }

    long long out  =  walk(x, y+1, n-1) + walk(x, y-1, n-1) + walk(x+1, y+1, n-1)
                    + walk(x-1, y-1, n-1) + walk(x-1, y, n-1) + walk(x+1, y, n-1);

    step[{n, {y, x}}] = out;

    return out;
}

int main(void)
{

    for (int i = 0; i < 15; i++)
    {
        walks[i] = walk(0, 0, i);
    }


    int cases = 0;
    std::cin >> cases;

    while (cases--)
    {
        int n = 0;
        std::cin >> n;
        std::cout << walks[n] << std::endl;
    }

    return 0;
}
