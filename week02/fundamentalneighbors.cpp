/* Aida Colovic
 *
 * Kattis Problem   : Fundamental Neighbors
 * Problem ID       : fundamentalneighbors
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 4.5
 *
 */

#include <iostream>
#include <cmath>
#include <unordered_map>

std::unordered_map<int, int> primeFactorization(int n)
{
    std::unordered_map<int, int> factors;
    while (n%2 == 0)
    {
        factors[2]++;
        n /= 2;
    }

    for(int i = 3; i <= sqrt(n); i +=2)
    {
        while (n%i == 0)
        {
            factors[i]++;
            n /= i;
        }

    }
    if(n > 2)
    {
        factors[n]++;
    }
    return factors;
}

int main(void)
{
    while (1)
    {
        int number = 0;
        std::cin >> number;
        if(std::cin.eof())
        {
            break;
        }
        else
        {
            std::unordered_map<int, int> factors = primeFactorization(number);
            int neighbor = 1;
            for(const auto& e : factors)
            {
                neighbor *= pow(e.second, e.first);
            }
            std::cout << number << " " << neighbor << std::endl;
        }
    }
    return 0;
}
