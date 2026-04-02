#include <bits\stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, p;
        cin >> n >> p;

        int a[n], b[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int count = 0;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            if (b[i] <= p)
            {
                count++;
                if (count == n)
                {
                    cout << count * p << endl;
                    // cout << 1;
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0)
        {
            int cost = count * p;
            // cout << cost << endl;

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (b[i] > b[j])
                    {
                        swap(b[i], b[j]);

                        swap(a[i], a[j]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                // count = count + a[i];

                if (count + a[i] >= n)
                {
                    cout << cost + (n - count) * b[i] << endl;
                    // cout << 2;
                    break;
                }
                else
                {
                    cost = cost + b[i] * a[i];
                    // cout << cost << ' ';
                    count = count + a[i];
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i] << ' ';
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << b[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}