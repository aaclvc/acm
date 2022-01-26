/* Aida Colovic
 *
 * Kattis Problem   : Big Truck
 * Problem ID       : bigtruck
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.0
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int inf = 1 << 30;

struct node
{
    int dest;
    int dist;
    int items;
};

bool operator<(const node& n1, const node& n2)
{
    if(n1.dist == n2.dist)
    {
        return n1.items < n2.items;
    }

    return n1.dist > n2.dist;
}

int main(void)
{
    int n = 0;
    std::cin >> n;

    std::vector<int> items(n, 0);
    for(auto& i : items)
    {
        std::cin >> i;
    }

    int m = 0;
    std::cin >> m;

    std::vector<std::vector<std::pair<int,int>>> adj(n);            //adj matrix {destination, items(weight)}

    for(int i = 0; i < m; i++)
    {
        int n1, n2, w;
        std::cin >> n1 >> n2 >> w;
        n1--; n2--;

        adj[n1].push_back({n2,w});
        adj[n2].push_back({n1,w});
    }

    std::vector<int> bestDist(n,inf);
    std::vector<int> bestItem(n,0);
    std::vector<bool> visited(n,false);

    std::priority_queue<node> q;

    q.push({0,0,items[0]});
    bestDist[0] = 0;
    bestItem[0] = items[0];

    while(!q.empty())
    {
        int current = q.top().dest;
        q.pop();

        if(visited[current])
        {
            continue;                   // if allready visited go to next
        }
        visited[current] = true;

        for(auto i : adj[current])
        {
            int next = i.first;

            if(bestDist[next] > bestDist[current] + i.second)
            {
                bestDist[next] = bestDist[current] + i.second;
                bestItem[next] = bestItem[current] + items[next];
                q.push({next,bestDist[next],bestItem[next]});
            }

            else if(bestDist[next] == bestDist[current] + i.second)
            {
                bestItem[next] = std::max(bestItem[next], bestItem[current] + items[next]);
                q.push({next,bestDist[next],bestItem[next]});
            }
        }
    }

    if(bestDist[n-1] >= inf)
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << bestDist[n-1] << " " << bestItem[n-1] << std::endl;
    }

    return 0;
}
