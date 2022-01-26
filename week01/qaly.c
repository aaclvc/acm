/* Aida Colovic
 * 
 * Kattis Problem   : Quality-Adjusted Life-Year
 * Problem ID       : qaly
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <stdio.h>

int main(void)
{
    int period;
    double a, b;
    double result = 0;

    scanf("%d", &period);
    for (int i = 0; i < period; i++)
    {
        scanf("%lf %lf", &a, &b);
        result += a*b;
    }
    printf("%lf\n", result);

    return 0;
}