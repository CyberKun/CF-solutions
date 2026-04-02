#include <iostream>
#include <string>
using namespace std;

int main()
{

    int n, count1 = 0, count2 = 0;
    cin >> n;
    getchar();
    string str;

    getline(cin, str);
    int i = 0;

    string str2 = "  ";
    string str3 = "  ";
    str3[2] = '\0';

    // while (str2[0] != str[n - 1])
    // {
    //     static int j=1;
    //     str2[0]=str[j-1];
    //     str[1]=str[j];

    //     for (int i = 1; i < n - 1; i++)
    //     {
    //         if (str[i] == str2[0] && str[i + 1] == str2[1])
    //         {
    //             count1++;
    //         }
    //     }
    //     if(count1>count2)
    //     {
    //           count2=count1;
    //         str3[0]=str2[0];
    //         str3[1]=str2[1];
    //         cout << str3;
    //     }
    //     count1=0;
    //     j++;
    // }

    for (int j = 1; j < n; j++)
    {
        str2[0] = str[j - 1];
        str2[1] = str[j];
        count1 = 0;
        for (int i = 1; i < n; i++)
        {
            if (str[i - 1] == str2[0] && str[i] == str2[1])
            {
                count1++;
            }
        }
        if (count1 > count2)
        {
            count2 = count1;
            str3[0] = str2[0];
            str3[1] = str2[1];
        }
    }

        cout << str3;

        return 0;
    }