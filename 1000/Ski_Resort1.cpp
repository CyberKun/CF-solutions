#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int t;
    cin >> t;

    while (t--)
    {
        long long int n, k, q;
        cin >> n >> k >> q;

        vector<long long int> vec(n);
        for (long long int i = 0; i < n; i++)
            cin >> vec[i];

        long long int ans = 0;
        long long int count = 0;

        for (long long int i = 0; i < n; i++)
        {
            if (vec[i] <= q)
                count++;
            else
            {
                if (count >= k)
                    ans += (count - k + 1) * (count - k + 2) / 2;
                
                count = 0;
            }
        }

        if (count >= k)
            ans += (count - k + 1) * (count - k + 2) / 2;

        cout << ans << endl;
    }

    return 0;
}
