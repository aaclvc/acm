#include <iostream>
#include <iomanip>
#include <cmath>

int main(void)
{
    long long a;
    std::cin >> a;
    double res = 6 * std::sqrt((a*2)/(3*std::sqrt(3)));
    std::cout << std::fixed << std::setprecision(8) << res << std::endl;
    return 0;
}
