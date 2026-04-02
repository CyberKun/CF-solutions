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
        int n, x, sum = 0;
        cin >> n >> x;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        cout << sum %n << ' ' << sum /n << endl;

        if (sum % n == 0 && sum / n == x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
