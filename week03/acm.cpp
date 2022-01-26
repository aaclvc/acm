/* Aida Colovic
 *
 * Kattis Problem   : ACM Contest Scoring
 * Problem ID       : acm
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 
 *
 */

#include <iostream>
#include <map>

int main(void)
{
    int right = 0;
    int totalTime = 0;
    std::map<char, int> wrongs;

    while (1)
    {
        int time = 0;
        char problem;
        std::string status;

        std::cin >> time;
        if (time == -1)
        {
            break;
        }
        std::cin >> problem >> status;

        if (status == "right")
        {
            totalTime += time;
            right++;
            if (wrongs[problem] > 0)
            {
                totalTime += 20 * wrongs[problem];
            }
        }
        else
        {
            wrongs[problem]++;
        }
    }
    std::cout << right << " " << totalTime << std::endl;

    return 0;
}