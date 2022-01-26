/* Aida Colovic
 *
 * Kattis Problem   : Reseto
 * Problem ID       : reseto
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.9
 *
 */



#include <iostream>
#include <vector>

int main (void)
{
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<bool> primes;
    primes.resize(n+1, true);

    primes[0] = false;
    primes[1] = false;

    int crossed = 0;

    for(int i = 2; i <= n; i++) {
        if(!primes[i]) continue;

        for(int j = i; j <= n; j+=i) {
            if(!primes[j]) continue;                // If crossed, skip

            primes[j] = false;                      // Otherwise, cross
            crossed++;

            if(crossed == k) {                      // If crossed enough, quit
                std::cout << j << std::endl;
                return 0;
            }
        }
    }
    return 0;
}
