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
        int count = 1;
        int flag = 0;
        for (int i = 0; i < n; i++)
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

        int cost = 0;

        for (int i = 0; i < n; i++)
        {
            cost = cost + p;
            if (b[i] >= p)
            {
                cost = cost + (n - i - 1) * p;
                cout << cost << endl;
                break;
            }
            else
            {
                if (count + a[i] < n)
                {
                    // cout << 2 ;
                    cost = cost + a[i] * b[i];
                    count = count + a[i];
                    count++;
                }
                else if (count + a[i] == n)
                {
                    cost = cost + a[i] * b[i];
                    cout << cost << endl;
                    // cout << 1;
                    break;
                }
                else
                {
                    cost = cost + (n - count) * b[i];
                    cout << cost << endl;
                    break;
                }
                if (count == n)
                {
                    cout << cost << endl;
                    break;
                }
            }
        }
    }
    return 0;
}