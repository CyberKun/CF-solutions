#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int l = str.length(), s = l;

    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (str[i] == str[j])
            {
                s = s - 1;
                break;
            }
        }
    }

    if (s % 2 == 0)
        cout << "CHAT WITH HER!";
    else
        cout << "IGNORE HIM!";
    return 0;
}