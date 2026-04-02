#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long int sum1 = 0, sum2 = 0;

        vector<int> seg1(arr.begin(), arr.begin() + (r));
        vector<int> seg2(arr.begin() + (l - 1), arr.end());

        sort(seg1.begin(), seg1.end());
        sort(seg2.begin(), seg2.end());

        for (int i = 0; i < r - l + 1; i++)
        {
            sum1 += seg1[i];
        }

        for (int i = 0; i < r - l + 1; i++)
        {
            sum2 += seg2[i];
        }

        cout << min(sum2, sum1) << endl;
    }

    return 0;
}
