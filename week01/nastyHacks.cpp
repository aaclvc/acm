/* Aida Colovic
 * 
 * Kattis Problem   : Nasty Hacks
 * Problem ID       : nastyhacks
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <iostream>

int main(void)
{
    int cases = 0;
    std::cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int r, e, c;
        std::cin >> r >> e >> c;

        if(r < e-c)
        {
            std::cout << "advertise" << std::endl;
        }
        else if (r > e-c)
        {
            std::cout << "do not advertise" << std::endl;
        }
        else if(r == e-c)
        {
            std::cout << "does not matter" << std::endl;
        }
    }
    return 0;
}