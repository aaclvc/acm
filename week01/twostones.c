/* Aida Colovic
 * 
 * Kattis Problem   : Take Two Stones
 * Problem ID       : twostones
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.2
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%s\n", ((n % 2) == 0)?"Bob":"Alice");
}