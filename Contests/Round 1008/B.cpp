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
        int n, k;
        cin >> n >> k;

        if (k % 2 == 0)
        {
            for (int i = 0; i < n - 2; i++)
            {
                cout << n - 1 << ' ';
            }
            cout << n << ' ' << n - 1 << endl;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << n << ' ';
            }
            cout << n - 1 << endl;
        }
    }

    return 0;
}
