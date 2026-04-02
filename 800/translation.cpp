#include <bits/stdc++.h>
using namespace std;

int main()
{
    string string1, string2;

    getline(cin, string1);
    getline(cin, string2);

    reverse(string2.begin(), string2.end());

    bool flag = true;

    if (string1 == string2)
    {
    }
    else
    {
        flag = false;
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}