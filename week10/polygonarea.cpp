/* Aida Colovic
 *
 * Kattis Problem   : Polygon Area
 * Problem ID       : polygonarea
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.1
 *
 */

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>

int main(void)
{
    int n = -1;
    while(1)
    {
        std::cin >> n;
        if(n == 0) break;

        std::vector<std::pair<int, int>> vertices(n, {0, 0});
        for(auto& i : vertices)
        {
            int x, y;
            std::cin >> x >> y;
            i = {x, y};
        }

        //kreuzprodukt
        int crossProduct = 0;
        for (int i = 0; i < n; i++)
        {
            std::pair<int, int> p1 = vertices[i];
            std::pair<int, int> p2 = vertices[i+1];

            if(i == n-1)  // connection between last and first point
            {
                p2 = vertices[0];
                crossProduct += p1.first * p2.second - p1.second * p2.first;
            }
            else
            {
                crossProduct += p1.first * p2.second - p1.second * p2.first;
            }
        }

        if( crossProduct < 1) std::cout << "CW ";
        else std::cout << "CCW ";

        double area = std::abs(crossProduct/2.0);
        printf("%.1lf\n", area);
    }
    return 0;
}
