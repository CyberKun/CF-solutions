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
        long long int x, y;
        cin >> x >> y;

        int a = x % 10;
        int b = y % 10;

        if (y - x == 1 || x - y == 8)
        {
            cout << "YES" << endl;
        }
        else if (x % 9 == 0 && y == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
