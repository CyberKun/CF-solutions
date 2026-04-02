#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, q;
        cin >> n >> q;

        int arr[n], ALLsum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            ALLsum += arr[i];
        }
        int l[q], r[q], k[q];
        string ans[q];

        for (int i = 0; i < q; i++)
        {
            cin >> l[i] >> r[i] >> k[i];
        }

        for (int i = 0; i < q; i++)
        {
            int sum = ALLsum;
            for (int j = l[i] + 1; j < r[i] + 1; j++)
            {
                sum -= arr[j];
            }
            sum += (r - l + 1) * k[i];

            if (sum % 2 == 0)
            {
                ans[i] = "NO";
            }
            else
            {
                ans[i] = "YES";
            }
        }

        for (int i = 0; i < q; i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}