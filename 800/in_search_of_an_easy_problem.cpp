#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, flag = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
            flag = 1;
    }

    if (flag == 1)
        cout << "HARD" << endl;
    else
        cout << "EASY" << endl;

    return 0;
}
