/* Aida Colovic
 * 
 * Kattis Problem   : Prime Path
 * Problem ID       : primepath
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 2.3
 * 
 */

#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <queue>

bool isprime(int n) 
{
    if(n < 2) 
    {
        return false;
    }
    if(n == 2) 
    {
        return true;
    }
    for(int i = 2; i <= std::sqrt(n); i++) 
    {
        if(n % i == 0) 
        {
            return false;
        }
    }
    return true;
}

bool connect(int i, int j) 
{
    int diff = 0;
    while(i > 0 && j > 0) 
    {
        if(i%10 != j%10) 
        {
            diff++;
        }
        i /= 10;
        j /= 10;
    }
    return diff == 1;
}

int main() 
{

    std::set<int> all;
    for(int i = 1000; i <= 9999; i++) 
    {
        if(isprime(i)) 
        {
            all.insert(i);
        }
    }

    std::map<int, std::set<int>> adj;
    for(auto i : all) 
    {
        adj[i] = {};
        for(auto j : all) 
        {
            if(connect(i,j)) 
            {
                adj[i].insert(j);
            }
        }
    }

    int cases;
    std::cin >> cases;
    while(cases--) 
    {
        int n1, n2;
        std::cin >> n1 >> n2;

        std::map<int,int> vis;
        vis[n1] = 0;
        std::queue<int> q;
        q.push(n1);

        while(!q.empty()) 
        {
            int curr = q.front();
            q.pop();

            for(auto next : adj[curr]) 
            {
                if(vis.count(next) == 0) 
                {
                    vis[next] = vis[curr] + 1;
                    q.push(next);
                }
            }
        }

        std::cout << vis[n2] << std::endl;
    }

    return 0;
}