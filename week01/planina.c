/* Aida Colovic
 * 
 * Kattis Problem   : Planina
 * Problem ID       : planina
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.3
 * 
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, a = 0;
    
    scanf("%d", &n);
    
    a = pow(2, n) + 1;
    printf("%d\n", (int) pow(a, 2));
}