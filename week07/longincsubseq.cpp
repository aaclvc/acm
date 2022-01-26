/* Aida Colovic
 *
 * Kattis Problem   : Longest Increasing Subsequence
 * Problem ID       : longincsubseq
 * CPU Time limit   : 2 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 6.4
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 100100

std::vector<int> v(MAX, 0), tail(MAX, 0), pre(MAX, 0);

int ceilIndex(int l, int r, int key)
{
    while (r-l > 1)
    {
        int m = l + (r-l)/2;
        if(v[tail[m]] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

void lis(int n)
{
    if(n == 0)
    {
        return;
    }
    std::fill(pre.begin(), pre.begin()+n, -1);

    int length = 1;

    std::cin >> v[0];
    tail[0] = 0;
    for (int i = 1; i < n; i++)
    {
        std::cin >> v[i];                   // save remaining numbers
        if(v[i] <= v[tail[0]])
        {
            tail[0] = i;
        }
        else if(v[i] > v[tail[length-1]])
        {
            pre[i] = tail[length-1];
            tail[length++] = i;
        }
        else
        {
            int m = ceilIndex(-1, length-1, v[i]);
            pre[i] = tail[m-1];
            tail[m] = i;
        }
    }

    std::cout << length << std::endl;
    std::vector<int> out;
    for (int i = tail[length-1]; i >= 0; i=pre[i])
    {
        out.push_back(i);
    }
    for (int i = out.size()-1; i >= 0; --i)
    {
        if(i < out.size()-1)
            putchar(' ');
        std::cout << out[i];
    }
    std::cout << std::endl;

}

int main(void)
{
    int n = 0;
    while(1)
    {
        std::cin >> n;
        if(std::cin.eof())
        {
            break;
        }
        lis(n);
    }
    return 0;
}


// int main(void)
// {
//     while(1)
//     {
//         int n = 0;
//         std::cin >> n;
//         if(std::cin.eof())
//         {
//             break;
//         }

//         std::vector<int> v(n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             std::cin >> v[i];
//         }

//         //LIS
//         int a[n], mem[n+1];
//         int len = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int lo = 1;
//             int hi = len;
//             while (lo <= hi)
//             {
//                 int mid = std::ceil((lo+hi)/2.0);
//                 if (v[mem[mid]] < v[i])
//                     lo = mid+1;
//                 else
//                     hi = mid-1;
//             }

//             int newLen = lo;

//             a[i] = mem[newLen-1];
//             mem[newLen] = i;
//         }

//         int tmp = mem[len];
//         std::vector<int> v2(n, 0);

//         for (int i = len-1; i >= 0; i--)
//         {
//             v2[i] = tmp;
//             tmp = a[tmp];
//         }

//         std::cout << len << std::endl;

//         for (int i = 0; i < len-1; i++)
//         {
//             std::cout << v2[i] << " ";
//         }
//         std::cout << v2[len-1] << std::endl;
//     }

//     return 0;
// }
