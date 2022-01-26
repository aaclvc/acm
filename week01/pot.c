/* Aida Colovic
 * 
 * Kattis Problem   : Pot
 * Problem ID       : pot
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   

int main(void)
{
    int n, next;
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &next);
        sum += pow(next/10, next%10);
    }
    
    printf("%d\n", sum);
    return 0;
}