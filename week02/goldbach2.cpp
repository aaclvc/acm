/* Aida Colovic
 * 
 * Kattis Problem   : Goldbach's Conjecture
 * Problem ID       : goldbach2
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.9
 * 
 */

#include <iostream>
#include <vector>

int main() 
{
    std::vector<bool> primes;
    primes.resize(32100, true);
    primes[0] = false;
    primes[1] = false;

    for(int i = 2; i < 32100; i++) 
    {
        if(!primes[i]) 
        {
            continue;
        }
        for(int j = i+1; j < 32100; j++) 
        {
            if(j % i == 0) 
            {
                primes[j] = false;
            }
        }
    }
    int cases;
    std::cin >> cases;
    for(int i = 0; i < cases; i++) 
    {
        int num;
        std::cin >> num;

        std::vector<std::pair<int, int>> reps;
        for(int i = 2; i <= num/2; i++) 
        {
            if(primes[i] && primes[num-i]) 
            {
                reps.push_back({i, num-i});
            }
        }

        std::cout << num << " has " << reps.size() << " representation(s)" << std::endl;
        for(auto i : reps) 
        {
            std::cout << i.first << "+" << i.second << std::endl;
        }
        std::cout << std::endl;
    }
}