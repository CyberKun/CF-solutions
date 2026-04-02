#include <iostream>
#include <string.h>
using namespace std;

string caps1(string str)
{
    int i = 1;
    str[0] = str[0] - 32;
    while (str[i] != '\0')
    {
        str[i] = str[i] + 32;
        i++;
    }
    return str;
}

string caps2(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = str[i] + 32;
        i++;
    }
    return str;
}

int main()
{
    string str;
    getline(cin, str);

    int i = 0;
    int flag = 1;
    while (str[i] != '\0')
    {
        if (str[i] <= 90) // First capital letter
        {
            i++;

            while (str[i] != '\0')
            {
                if (str[i] > 90) // If a letter is small
                {
                    flag = 0;
                    break;
                }
                i++;
            }
            if (flag == 0)
            {
                cout << str;
                return 0;
            }
            else
            {
                str = caps2(str);
                cout << str;
                return 0;
            }
        }
        else // First small letter
        {
            i++;
            while (str[i] != '\0')
            {
                if (str[i] > 90) // If a letter is small
                {
                    flag = 0;
                    break;
                }
                i++;
            }
            if (flag == 0)
            {
                cout << str;
                return 0;
            }
            else
            {
                str = caps1(str);
                cout << str;
                return 0;
            }
        }
    }

    return 0;
}