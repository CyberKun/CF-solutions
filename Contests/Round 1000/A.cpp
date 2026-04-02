#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int count = 0;

        if (l == 1 && r == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            for (int i = l; i < r; i++)
            {
                if (i == 1)
                {
                    count++;
                    if (r <= 2)
                    {
                        break;
                    }
                }
                else
                {
                    if (__gcd(i, i + 1) == 1)
                    {
                        count++;
                    }
                }
            }

            cout << count << endl;
        }
    }

    return 0;
}
