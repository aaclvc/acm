/* Aida Colovic
 *
 * Kattis Problem   : Single source shortest path, non-negative weights
 * Problem ID       : shortestpath1
 * CPU Time limit   : 3 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.7
 *
 */

#include <iostream>
#include <vector>
#include <queue>

#define INF 20000000

struct edge
{
    int nodeTo, weight;
    edge() {}
    edge(int _nodeTo, int _weight)
    {
        nodeTo = _nodeTo;
        weight = _weight;
    }
    bool operator < (edge e) const
    {
        return weight > e.weight;
    }
};



int main()
{
    int numNodes, numEdges, numQueries, startNode, nodeFrom, nodeTo, weight;
    edge e, f;

    while (scanf("%d%d%d%d", &numNodes, &numEdges, &numQueries, &startNode) && numNodes)
    {
        std::vector<edge> adjlist[numNodes];
        for (int i = 0;i < numEdges;i++)
        {
            std::cin >> nodeFrom >> nodeTo >> weight;
            adjlist[nodeFrom].push_back(edge(nodeTo, weight));
        }

        // Dijkstra
        std::vector<int> dist = std::vector<int>(numNodes + 1, INF);

        std::priority_queue<edge> q;
        q.push(edge(startNode, 0));
        dist[startNode] = 0;

        while (!q.empty())
        {
            edge top = q.top(); q.pop();
            int u = top.nodeTo;
            for (int i = 0;i < adjlist[u].size();i++)
            {
                int v = adjlist[u][i].nodeTo;
                if (dist[u] + adjlist[u][i].weight < dist[v])
                {
                    dist[v] = dist[u] + adjlist[u][i].weight;
                    q.push(edge(v, dist[v]));
                }
            }
        }

        for (int i = 0;i < numQueries;i++)
        {
            std::cin >> nodeFrom;
            if (dist[nodeFrom] == INF)
            {
                std::cout << "Impossible" << std::endl;
            }
            else
            {
                std::cout << dist[nodeFrom] << std::endl;
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
