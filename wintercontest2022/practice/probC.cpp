#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>

int findE(std::vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == 0)
            return i;
    }
}

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n+1, 0);
    arr[0] = -1;

    int i = 1;
    int j = n;
    while(1)
    {
        if(i == j)
        {
            std::cout << "! " << j<< std::endl;
            std::cout.flush();
            break;
        }
        std::cout << "?" << " " << i << " " <<  j << std::endl;
        std::cout.flush();

        std::string ans;
        std::cin >> ans;
        if(ans == "equal")
        {
            if(n == 3)
            {
                std::cout << "! 2" << std::endl;
                std::cout.flush();
                break;
            }
            // arr[i] = 0;
            // arr[j] = 0;

            i++;
            j--;
        }
        else if(ans == "lighter")
        {
            arr[i] = -1;
            arr[j] = -1;
            int equalCoin = findE(arr);

            std::cout << "?" << " " << equalCoin << " " <<  i << std::endl;
            std::cout.flush();

            std::cin >> ans;
            if(ans == "heavier")
            {
                std::cout << "! " << i << std::endl;
                std::cout.flush();
            }
            else
            {
                std::cout << "! " << j << std::endl;
                std::cout.flush();
            }
            break;
        }
        else if(ans == "heavier")
        {
            arr[i] = -1;
            arr[j] = -1;
            int equalCoin = findE(arr);
            std::cout << "?" << " " << equalCoin << " " <<  i<< std::endl;
            std::cout.flush();

            std::cin >> ans;
            if(ans == "lighter")
            {
                std::cout << "! " << i<< std::endl;
                std::cout.flush();
            }
            else
            {
                std::cout << "! " << j<< std::endl;
                std::cout.flush();
            }
            break;
        }
    }

    return 0;
}
