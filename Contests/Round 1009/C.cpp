#include <bits/stdc++.h>
using namespace std;

int a[55], b[55];

void solve()
{
    int n;
    cin >> n;
    set<int> asd, asf;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i], asd.insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i], asf.insert(b[i]);
    }
    if (asd.size() + asf.size() < 4)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}