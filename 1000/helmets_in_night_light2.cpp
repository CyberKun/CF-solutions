#include <bits\stdc++.h>
using namespace std;

void costy(int *cost, int *count, int n, int p, int size, int index, int b[1000000], int a[1000000])
{
    if (index + size >= n)
    {
        *cost = *cost + n * b[index];
        return;
    }
    else
    {
        for (int i = index + 1; i < (index + size); i++)
        {
            if (b[i] < p)
            {
                if (*count + a[i] >= n)
                {
                    *cost = *cost + (n - *count) * b[i];
                    *count = n;
                    return;
                }
                else
                {
                    *cost = *cost + a[i] + b[i];
                    *count = *count + a[i];
                    costy(cost, count, n, p, a[i], i, b, a);
                }
            }
            else
            {
                return;
            }
        }
    }

    return;
}

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
        int count = 1;
        int flag = 0;

        for (int i = 0; i < n; i++)
        {
            cost = cost + p;
            if (b[i] < p)
            {
                if (count + a[i] < n)
                {
                    count = count + a[i];
                    cost = cost + a[i] * b[i];

                    costy(&cost, &count, n, p, a[i], i, b, a);
                }
            }
        }

        cout << cost << endl;
    }
    return 0;
}