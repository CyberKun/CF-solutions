#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<char> str(n);
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] < 91)
            str[i] += 32;
    }

    sort(str.begin(), str.end());

    for (int i = 0; i < str.size() - 1;)
    {
        if (str[i] == str[i + 1])
            str.erase(str.begin() + i);
        else
            i++;
    }

    if (str.size() == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
