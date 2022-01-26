/* Aida Colovic
 *
 * Kattis Problem   : Hitting Targets
 * Problem ID       : hittingtargets
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.9
 *
 */

#include <iostream>
#include <vector>
#include <cmath>

struct circle
{
    int x;
    int y;
    int r;
};

struct rectangle
{
    int x1;
    int y1;
    int x2;
    int y2;
};


int main(void)
{
    int targets = 0;
    std::cin >> targets;

    std::vector<rectangle> targetR;
    std::vector<circle> targetC;

    for (int i = 0; i < targets; i++)
    {
        std::string keyWord;
        std::cin >> keyWord;
        if(keyWord == "rectangle")
        {
            rectangle rect;
            std::cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;
            targetR.push_back(rect);
        }
        else if (keyWord == "circle")
        {
            circle circ;
            std::cin >> circ.x >> circ.y >> circ.r;
            targetC.push_back(circ);
        }

    }

    int shots = 0;
    std::cin >> shots;

    for (int i = 0; i < shots; i++)
    {
        int hits = 0;
        int x = 0, y = 0;
        std::cin >> x >> y;

        for(auto rect : targetR)
        {
            if(x >= rect.x1 && x <= rect.x2 && y >= rect.y1 && y <= rect.y2) hits++; //check if shot is in rect
        }

        for(auto circ : targetC)
        {
            //check if dist between center of circle and shot is <= radius
            double dist = std::sqrt(std::pow(std::abs(x-circ.x), 2) + std::pow(std::abs(y-circ.y), 2));
            if(dist <= circ.r) {
                hits++;
            }
        }
        std::cout << hits << std::endl;
    }

}
