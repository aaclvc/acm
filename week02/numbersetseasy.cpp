/* Aida Colovic
 *
 * Kattis Problem   : Number Sets
 * Problem ID       : numbersetseasy
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 4.4
 *
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <set>

int find (std::vector<int> &d, int n)
{
    if(d[n] == -1)
    {
        return n;
    }
    return d[n] = find(d, d[n]);
}

void join (std::vector<int> &d, int a, int b)
{
    a = find(d, a);
    b = find(d, b);
    if(a==b)
        return;
    d[a] = b;
}

std::set<int> factorization(int n)
{
    std::set<int> primes;
    for(int i = 2; i <= sqrt(n); i++)
    {
        while(n%i == 0)
        {
            primes.insert(i);
            n /= i;
        }
    }

    if(n > 1)
    {
        primes.insert(n);
    }
    return primes;
}

bool share(int a, int b, int p)
{
    std::set<int> factorsA = factorization(a);
    std::set<int> factorsB = factorization(b);

    for (int i : factorsA)
    {
        if(i >= p && factorsB.count(i)>0)
        {
            return true;
        }
    }
    return false;
}

int solve()
{
    int a, b, p;
    std::cin >> a >> b >> p;

    std::vector<int> d(b+1, -1);
    for (int i = a; i <= b; i++)
    {
        for (int j = i+1; j <= b; j++)
        {
            if(share(i,j,p))
            {
                join(d, i, j);
            }
        }
    }

    int sets = 0;
    for (int i = a; i <= b; i++)
    {
        if(d[i] == -1)
        {
            sets++;
        }
    }
    return sets;
}

int main(void)
{
    int cases = 0;
    std::cin >> cases;
    for (int i = 1; i <= cases; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }

    return 0;
}
