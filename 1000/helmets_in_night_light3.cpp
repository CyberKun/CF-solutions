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

        int count = 1;
        int cost = p;

        for (int i = 0; i < n; i++)
        {
            if (b[i] < p)
            {
                if (a[i] <= (n - count))
                {
                    count = count + a[i];
                    cost = cost + a[i] * b[i];
                }
                else
                {
                    cost = cost + (n - count) * b[i];
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