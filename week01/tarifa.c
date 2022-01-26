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
    int credit, months, consumption = 0;

    scanf("%d", &credit);
    scanf("%d", &months);

    for (int i = 0; i < months; i++)
    {
        int temp;
        scanf("%d", &temp);
        consumption += temp;
    }
    
    printf("%d\n", ((credit*months) - consumption) + credit);
}