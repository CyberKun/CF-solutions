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
            if (l == 1)
            {
                count++;
                l++;
            }

            count += (r - l);

            cout << count << endl;
        }
    }

    return 0;
}
