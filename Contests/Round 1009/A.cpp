#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int l, r, d, u;
        cin >> l >> r >> d >> u;

        if (l == r && r == d && d == u)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
