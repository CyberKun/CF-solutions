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
        int n, count = 1, ans = 0;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> count1(2 * n, 0);
        vector<int> count2(2 * n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                count++;
            else
            {
                if (count > count1[a[i] - 1])
                    count1[a[i] - 1] = count;

                count = 1;
            }
        }

        if (count > count1[a[n - 1] - 1])
            count1[a[n - 1] - 1] = count;

        count = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (b[i] == b[i + 1])
                count++;
            else
            {
                if (count > count2[b[i] - 1])
                    count2[b[i] - 1] = count;

                count = 1;
            }
        }

        if (count > count2[b[n - 1] - 1])
            count2[b[n - 1] - 1] = count;

        count = 1;

        for (int i = 0; i < 2 * n; i++)
        {
            int sum = count1[i] + count2[i];
            ans = max(ans, sum);
        }

        cout << ans << endl;
        b.clear();
        a.clear();
        count1.clear();
        count2.clear();
    }

    return 0;
}
