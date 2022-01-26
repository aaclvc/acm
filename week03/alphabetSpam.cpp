/* Aida Colovic
 *
 * Kattis Problem   : Alphabet Spam
 * Problem ID       : alphabetspam
 * CPU Time limit   : 1 sec
 * Memory limit     : 1024 MB
 * Difficultiy      : 1.4
 *
 */

#include <iostream>

int main(void)
{
    int ans_whitespace = 0;
    int ans_lowercase  = 0;
    int ans_uppercase  = 0;
    int ans_symbols    = 0;

    std::string input;
    std::cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '_')
        {
            ans_whitespace++;
        }
        else if (input[i] >= 97 && input[i] <= 122)
        {
            ans_lowercase++;
        }
        else if (input[i] >= 65 && input[i] <= 90)
        {
            ans_uppercase++;
        }
        else
        {
            ans_symbols++;
        }
    }

    double whitespace = (double)ans_whitespace/input.size();
    double lowercase  = (double)ans_lowercase/input.size();
    double uppercase  = (double)ans_uppercase/input.size();
    double symbols    = (double)ans_symbols/input.size();

    printf("%.16lf\n", whitespace);
    printf("%.16lf\n", lowercase);
    printf("%.16lf\n", uppercase);
    printf("%.16lf\n", symbols);

    return 0;
}