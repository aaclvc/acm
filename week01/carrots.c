/* Aida Colovic
 * 
 * Kattis Problem   : Tarifa
 * Problem ID       : tarifa
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <stdio.h>

int main(void)
{
    int n, problems;

    scanf("%d %d", &n, &problems);
    for (int i = 0; i < n; i++)
    {
        char description[1000];
        scanf("%s", description);
    }
    printf("%d\n", problems);
}