#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, k, count = 0;
        vector<long long int> a;

        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int diff[n - 1], maxcount = 0;

        for (int i = 0; i < n - 1; i++)
        {
            diff[i] = a[i + 1] - a[i];

            if (diff[i] <= k)
            {
                count++;
            }
            else
            {
                if (count > maxcount)
                {
                    maxcount = count;
                }
                count = 0;
            }
        }

        if (count > maxcount)
        {
            maxcount = count;
        }

        // for (int i = 0; i < n - 1; i++)
        // {
        //     cout << diff[i] << ' ';
        // }
        // cout << endl;

        cout << n - maxcount - 1 << endl;
    }
    return 0;
}