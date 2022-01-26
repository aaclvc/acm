/* Aida Colovic
 *
 * Kattis Problem   : Torn to Pieces
 * Problem ID       : torn2pieces
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 3.1
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <queue>

int main (void)
{
    int n = 0;
    std::cin >> n;

    std::map<std::string, std::set<std::string>> graph;   // node => {neighbours}

    std::cin.ignore();
    for (int i = 0; i < n; i++)
    {
        std::string input;
        std::getline(std::cin, input);

        std::stringstream stream(input);                // node neighbour neighbour ....

        std::string node;
        stream >> node;

        std::string neighbour;
        while (stream >> neighbour)
        {
            graph[node].insert(neighbour);              //bidirectional
            graph[neighbour].insert(node);
        }
    }

    std::string start, end;
    std::cin >> start >> end;

//test if graph is correct
//    for (auto const& x : graph)
//    {
//        std::cout << x.first << ": ";  // string (key)
//        for(auto const& y: x.second)
//        {
//             std::cout << y << ", ";
//        }
//        std::cout << std::endl;
//    }

    std::queue<std::string> q;
    q.push(start);

    std::map<std::string, std::string> prev;
    prev[start] = "x";

    while (!q.empty())
    {
        std::string currentNode = q.front();
        q.pop();

        for (auto neighbour : graph[currentNode]) //check all neighbours of current node
        {
            if(prev.count(neighbour) == 0) // if not visited
            {
                prev[neighbour] = currentNode;
                q.push(neighbour);
            }
        }
    }

    if(prev.count(end) == 0)
    {
        std::cout << "no route found" << std::endl;
        return 0;
    }

    //get path
    std::vector<std::string> path;
    std::string node = end;
    while (node != "x")
    {
        path.push_back(node);
        node = prev[node];
    }

    //print answer backwards
    for (int i = path.size()-1; i > 0; i--)
    {
        std::cout << path[i] << " ";
    }
    std::cout << path[0] << std::endl;

    return 0;
}
