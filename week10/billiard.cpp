/* Aida Colovic
 *
 * Kattis Problem   : Billiard
 * Problem ID       : billiard
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.9
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    double a, b, s, m, n;
    while(std::cin >> a >> b >> s >> m >> n)
    {
        if(a == 0 && b == 0 && s == 0 && m == 0 && n == 0) break;

        double xDist = a * m;
        double yDist = b * n;

        double angle = std::atan(yDist / xDist) * 180 / M_PI;
        double dist = std::sqrt(std::pow(xDist, 2) + std::pow(yDist, 2));

        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << angle << " " << dist / s << std::endl;
    }
    return 0;
}
