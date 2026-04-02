#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, p;
        cin >> n >> p;

        vector<long long int> a(n), b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<pair<long long int, long long int>> residents(n);
        for (int i = 0; i < n; i++)
        {
            residents[i] = {b[i], a[i]};
        }

        sort(residents.begin(), residents.end());

        long long int count = 1;
        long long int cost = p;

        for (int i = 0; i < n; i++)
        {
            if (residents[i].first < p)
            {
                if (residents[i].second <= (n - count))
                {
                    count += residents[i].second;
                    cost += residents[i].second * residents[i].first;
                }
                else
                {
                    cost += (n - count) * residents[i].first;
                    cout << cost << endl;
                    count = n;
                    break;
                }
            }
            else
            {
                cout << cost + (n - count) * p << endl;
                break;
            }
        }
    }
    return 0;
}
