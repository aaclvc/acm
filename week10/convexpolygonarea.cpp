/* Aida Colovic
 *
 * Kattis Problem   : Convex Polygon Area
 * Problem ID       : convexpolygonarea
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.9
 *
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

int main(void)
{
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        std::cin >> m;

        std::vector<std::pair<int, int>> v(m, {0, 0});
        for(auto& i : v)
        {
            int x, y;
            std::cin >> x >> y;
            i = {x, y};
        }

        //kreuzprodukt
        int crossProduct = 0;
        for (int i = 0; i < m; i++)
        {
            std::pair<int, int> p1 = v[i];
            std::pair<int, int> p2 = v[i+1];

            if(i == m-1) //connection between last and first point
            {
                p2 = v[0];
                crossProduct += p1.first * p2.second - p1.second * p2.first;
            }
            else
            {
                crossProduct += p1.first * p2.second - p1.second * p2.first;
            }
        }
        double area = std::abs(crossProduct/2.0);
        std::cout << area << std::endl;
    }

    return 0;
}
