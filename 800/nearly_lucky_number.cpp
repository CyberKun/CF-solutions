#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;

    int cnt = 0;

    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '4' || n[i] == '7')
            cnt++;
    }

    if(cnt==4 || cnt == 7)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;

    return 0;
}
