#include <iostream>
// #include<bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string str;
    int n;
    getline(cin, str);

    int l = str.length();

    for (int i = 0; i < l; i += 2)
    {
        n = str[i];
        for (int j = i + 2; j < l; j += 2)
        {
            if (str[j] < n)
            {
                int temp = n;
                n = str[j];
                str[j] = temp;
            }
        }
        str[i] = n;
    }

    cout << str;
    return 0;
}