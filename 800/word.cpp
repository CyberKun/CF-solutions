#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    getline(cin, str);

    int i = 0, countl = 0, countu = 0;
    while (str[i] != '\0')
    {
        if (str[i] < 91)
        {
            countu++;
        }
        else
        {
            countl++;
        }
        i++;
    }

    if (countu > countl)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] > 91)
            {
                str[i] = str[i] - 32;
            }
            i++;
        }
    }
    else
    {
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] < 91)
            {
                str[i] = str[i] + 32;
            }
            i++;
        }
    }

    cout << str;

    return 0;
}