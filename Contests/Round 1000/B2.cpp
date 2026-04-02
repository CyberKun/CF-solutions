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

        long long int sum = 0;
        for (int i = l - 1; i < r; i++)
        {
            sum += arr[i];
        }

        vector<int> seg1(arr.begin(), arr.begin() + (l - 1));
        vector<int> seg2(arr.begin() + (l - 1), arr.begin() + r);
        vector<int> seg3(arr.begin() + r, arr.end());

        sort(seg1.begin(), seg1.end());
        sort(seg2.begin(), seg2.end(), greater<int>());
        sort(seg3.begin(), seg3.end());

        long long int sum2 = sum;
        for (int i = 0; i < min(seg1.size(), seg2.size()); i++)
        {
            if (seg1[i] < seg2[i])
            {
                sum2 = sum2 - seg2[i] + seg1[i];
            }
            else
            {
                break;
            }
        }

        long long int sum3 = sum;
        for (int i = 0; i < min(seg3.size(), seg2.size()); i++)
        {
            if (seg3[i] < seg2[i])
            {
                sum3 = sum3 - seg2[i] + seg3[i];
            }
            else
            {
                break;
            }
        }

        cout << min(sum2, sum3) << endl;
    }

    return 0;
}
