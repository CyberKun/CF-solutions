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
        long long int n, k, b, s;
        cin >> n >> k >> b >> s;

        int a = k * b;

        if (b * k > s)
            cout << -1 << endl;
        else
        {

            vector<long long int> vec(n, 0);

            vec[0] = min(k * (b + 1) - 1, s);

            long long int total = s - vec[0];

            for (int i = 1; i < n; i++)
            {
                vec[i] = min(k - 1, total);
                total -= vec[i];

                if (total <= 0)
                {
                    break;
                }
            }

            if (!total)
            {
                for (int i = 0; i < n; i++)
                {
                    cout << vec[i] << ' ';
                }
                cout << endl;
            }
            else
                cout << -1 << endl;
        }
    }

    return 0;
}
