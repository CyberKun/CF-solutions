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
        int n, x;
        cin >> n >> x;

        vector<int> vec(n);

        for (int i = 0; i < n; i++)
            cin >> vec[i];

        int minu, maxy, a, b, count = 0;

        minu = vec[0] - x;
        maxy = vec[0] + x;

        for (int i = 1; i < n; i++)
        {
            a = vec[i] - x;
            b = vec[i] + x;
            if (a > maxy || b < minu)
            {
                count++;
                minu = a;
                maxy = b;
            }

            if (a > minu)
                minu = a;

            if (b < maxy)
                maxy = b;
        }

        cout << count << endl;
    }

    return 0;
}
