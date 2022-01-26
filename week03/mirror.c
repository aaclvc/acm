/* Aida Colovic
 * 
 * Kattis Problem   : Mirror Images
 * Problem ID       : mirror
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.7
 * 
 */
#include <stdio.h>

void swap_char(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse_img(char* img, int low , int high)
{
    while (low < high)
    {
        swap_char(&img[low], &img[high]);
        high--;
        low++;
    }
    
}

void problem(int x)
{
    int rows, cols;
    char img[21][21];
    
    scanf("%d %d", &rows, &cols);
    
    /*read in image*/
    for (int i = 0; i < rows; i++)
    {
        scanf("%s", img[i]);
    }

    /*print new image*/
    printf("Test %d\n", x);
    for (int i = rows-1; i >= 0; i--)
    {
        reverse_img(img[i], 0, cols-1);
        printf("%s\n", img[i]);
    }
}

int main(void)
{
    int test_cases = 0;
    scanf("%d", &test_cases);
    for (int i = 1; i <= test_cases; i++)
    {
        problem(i);
    }

}