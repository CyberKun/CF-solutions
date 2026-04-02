#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str;
    char ch;
    cin >> ch;
    getchar();
    getline(cin, str);

    string str2 = "qwertyuiopasdfghjkl;zxcvbnm,./";

    int n = str.length(), m = str2.length();
    char str3[n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (str[i] != str2[j])
        {
            j++;
        }
        if (ch == 'L')
        {
            str3[k] = str2[j + 1];
            k++;
        }
        else
        {
            str3[k] = str2[j - 1];
            k++;
        }
    }
    str3[k] = '\0';

    cout << str3;

    return 0;
}